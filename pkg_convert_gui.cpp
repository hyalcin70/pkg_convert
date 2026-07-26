// pkg_convert_gui - native Qt6 GUI (kein Python)
// Wandelt .deb/.rpm/.AppImage -> Arch PKGBUILD + makepkg, alles ueber QProcess.
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QProgressBar>

// Sprach-Tabellen (pro Sprache eine eigene Datei lang_XX.cpp)
QMap<QString, QString> lang_de();
QMap<QString, QString> lang_en();
QMap<QString, QString> lang_fr();
QMap<QString, QString> lang_es();
QMap<QString, QString> lang_tr();
QMap<QString, QString> lang_pt();
#include <QListWidget>
#include <QFileDialog>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QUrl>
#include <QProcess>
#include <QTemporaryDir>
#include <QStandardPaths>
#include <QDirIterator>
#include <QMessageBox>
#include <QInputDialog>
#include <QRegularExpression>
#include <QComboBox>
#include <QDir>
#include <QFile>
#include <QSettings>

#include <algorithm>

class DropLine : public QLineEdit {
    Q_OBJECT
public:
    explicit DropLine(QWidget *p = nullptr) : QLineEdit(p) {
        setAcceptDrops(true);
        setReadOnly(true);
        setPlaceholderText(QStringLiteral(
            "Datei hierher ziehen (.deb / .rpm / .AppImage)  oder  'Durchsuchen' klicken"));
    }
signals:
    void fileDropped(const QString &path);
protected:
    void dragEnterEvent(QDragEnterEvent *e) override {
        if (e->mimeData()->hasUrls()) e->acceptProposedAction();
    }
    void dropEvent(QDropEvent *e) override {
        const auto urls = e->mimeData()->urls();
        if (!urls.isEmpty()) {
            const QString p = urls.first().toLocalFile();
            setText(p);
            emit fileDropped(p);
        }
    }
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *p = nullptr) : QMainWindow(p) {
        setWindowTitle(QStringLiteral("Paket Converter – Debian/RedHat/AppImage zu ArchLinux"));
        resize(760, 580);
        m_dark = m_settings.value("theme", "light").toString() == "dark";
        applyTheme();
        buildUi();
        // Sprache aus Settings laden (Standard: Deutsch)
        m_lang = m_settings.value("lang", "de").toString();
        applyLang();
    }

    // --- i18n: Sprache -> Schluessel -> Text ---
    QString i18n(const QString &key) const {
        // Sprach-Tabellen kommen aus lang_XX.cpp (pro Sprache eine Datei).
        static const QMap<QString, QMap<QString, QString>> T = {
            {"de", lang_de()},
            {"en", lang_en()},
            {"fr", lang_fr()},
            {"es", lang_es()},
            {"tr", lang_tr()},
            {"pt", lang_pt()},
        };
        const QMap<QString, QString> &m = T.value(m_lang, T.value("de"));
        return m.value(key, T.value("de").value(key, key));
    }

    void applyTheme() {
        const QString dark = R"(
            QMainWindow { background: #1e1e2e; }
            QLabel#title { font-size: 22px; font-weight: 600; color: #cdd6f4; }
            QLabel#sub { font-size: 12px; color: #a6adc8; }
            QFrame#card { background: #313244; border-radius: 12px; padding: 16px; }
            QLineEdit, QTextEdit {
                background: #181825; border: 1px solid #45475a;
                border-radius: 8px; color: #cdd6f4; padding: 8px;
                font-family: 'JetBrains Mono', monospace; font-size: 13px;
            }
            QPushButton {
                background: #89b4fa; color: #11111b; border: none;
                border-radius: 8px; padding: 10px 18px;
                font-weight: 600; font-size: 14px;
            }
            QPushButton:hover { background: #74a0f0; }
            QPushButton:disabled { background: #45475a; color: #6c7086; }
            QPushButton#ghost { background: transparent; border: 1px solid #585b70; color: #cdd6f4; }
            QPushButton#ghost:hover { background: #45475a; }
            QLabel#h { font-size: 13px; font-weight: 600; color: #b4befe; }
            QLabel#ok { color: #a6e3a1; }
            QLabel#bad { color: #f38ba8; }
        )";
        const QString light = R"(
            QMainWindow { background: #f5f6fa; }
            QLabel#title { font-size: 22px; font-weight: 600; color: #2e2e3a; }
            QLabel#sub { font-size: 12px; color: #5a5a6e; }
            QFrame#card { background: #ffffff; border-radius: 12px; padding: 16px; border: 1px solid #e2e4ec; }
            QLineEdit, QTextEdit {
                background: #ffffff; border: 1px solid #c8ccd8;
                border-radius: 8px; color: #2e2e3a; padding: 8px;
                font-family: 'JetBrains Mono', monospace; font-size: 13px;
            }
            QPushButton {
                background: #3b82f6; color: #ffffff; border: none;
                border-radius: 8px; padding: 10px 18px;
                font-weight: 600; font-size: 14px;
            }
            QPushButton:hover { background: #2563eb; }
            QPushButton:disabled { background: #c8ccd8; color: #8a8a9a; }
            QPushButton#ghost { background: transparent; border: 1px solid #a8adbd; color: #2e2e3a; }
            QPushButton#ghost:hover { background: #eceef4; }
            QLabel#h { font-size: 13px; font-weight: 600; color: #5b5bd6; }
            QLabel#ok { color: #2e9e4f; }
            QLabel#bad { color: #d83a5a; }
        )";
        setStyleSheet(m_dark ? dark : light);
    }

private slots:
    void toggleTheme() {
        m_dark = !m_dark;
        m_settings.setValue("theme", m_dark ? "dark" : "light");
        applyTheme();
        if (themeBtn) themeBtn->setText(m_dark ? i18n("themeLight") : i18n("themeDark"));
    }
    void applyLang() {
        // Alle sichtbaren Texte neu setzen (UI wurde schon in buildUi() gebaut)
        if (titleLbl)  titleLbl->setText(i18n("title"));
        if (subLbl)    subLbl->setText(i18n("subtitle"));
        if (drop)      drop->setPlaceholderText(i18n("dropHint"));
        if (browseBtn) browseBtn->setText(i18n("browse"));
        if (metaLbl)   metaLbl->setText(metaLbl->text().isEmpty() ? i18n("noFile") : metaLbl->text());
        if (dep_h)     dep_h->setText(i18n("deps"));
        if (btnBuild)  btnBuild->setText(i18n("build"));
        if (btnInstall) btnInstall->setText(i18n("install"));
        if (inst_h)    inst_h->setText(i18n("installed"));
        if (uninstallBtn) uninstallBtn->setText(i18n("uninstall"));
        if (themeBtn)  themeBtn->setText(m_dark ? i18n("themeLight") : i18n("themeDark"));
        if (langCombo) {
            const int i = langCombo->findData(m_lang);
            if (i >= 0) langCombo->setCurrentIndex(i);
        }
    }

private slots:
    void browse() {
        // Startordner = zuletzt gewaehlter Quell-Ordner (sonst Home)
        const QString start = m_settings.value("lastSrcDir",
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation)).toString();
        const QString p = QFileDialog::getOpenFileName(
            this, i18n("choosePkg"), start,
            i18n("pkgsFilter"));
        if (!p.isEmpty()) { drop->setText(p); onFile(p); }
    }
    void installPkg() {
        if (m_lastPkg.isEmpty() || !QFile::exists(m_lastPkg)) {
            status->setText(i18n("errNoBuiltPkg"));
            return;
        }
        // Allgemeiner Rat-Hinweis als EIGENES POPUP-FENSTER, ganz am ANFANG
        // (noch vor der Bestaetigungsfrage) – so uebersieht man ihn nicht.
        QMessageBox::information(this, i18n("hintInstallTitle"),
            i18n("hintInstallBody"));
        // Sicherheitsabfrage: welches Paket wird installiert?
        if (QMessageBox::question(this, i18n("confirmInstallTitle"),
                i18n("confirmInstallBody") + m_lastName + "\n(" + m_lastPkg + ")",
                QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
            status->setText(i18n("msgInstAborted"));
            return;
        }
        // Passwort über eigenen Dialog abfragen (sudo -S liest es von stdin).
        // Kein Polkit-Agent nötig – funktioniert in jeder Session.
        bool ok = false;
        const QString pw = QInputDialog::getText(
            this, i18n("sudoInstall"), i18n("sudoInstallBody") + m_lastName + "):",
            QLineEdit::Password, "", &ok);
        if (!ok || pw.isEmpty()) {
            status->setText(i18n("msgInstAbortedPw"));
            return;
        }
        QProcess sudo;
        sudo.start("sudo", QStringList() << "-S" << "pacman" << "-U" << "--noconfirm" << m_lastPkg);
        sudo.write(pw.toUtf8() + "\n");   // Passwort als erste Zeile auf stdin
        sudo.closeWriteChannel();
        sudo.waitForFinished(-1);
        const int instExit = sudo.exitCode();
        const QByteArray err = sudo.readAllStandardError();
        QString instMsg;
        if (instExit != 0)
            instMsg = QString("\n❌ pacman -U fehlgeschlagen (Exit %1):\n%2")
                          .arg(instExit).arg(QString::fromUtf8(err).trimmed().right(400));
        // Repo-Abhaengigkeiten automatisch nachinstallieren (pacman -S --asdeps),
        // damit das Paket lauffaehig ist. Ergebnis wird VERIFIZIERT und gemeldet.
        QString depsMsg;
        if (!m_lastDeps.isEmpty()) {
            QProcess deps;
            deps.start("sudo", QStringList() << "-S" << "pacman" << "-S" << "--asdeps" << "--needed" << "--noconfirm" << m_lastDeps);
            deps.write(pw.toUtf8() + "\n");
            deps.closeWriteChannel();
            deps.waitForFinished(-1);
            // Verifizieren: sind alle Deps jetzt wirklich installiert?
            QStringList missing;
            for (const QString &d : m_lastDeps) {
                QProcess q; q.start("pacman", QStringList() << "-Q" << d);
                q.waitForFinished();
                if (q.exitCode() != 0) missing << d;
            }
            if (missing.isEmpty())
                depsMsg = QString("\n" + i18n("depsInstalled") + "%1").arg(m_lastDeps.join(", "));
            else
                depsMsg = QString("\n" + i18n("depsFailed") + "%1\nFehler: %2")
                              .arg(missing.join(", "),
                                   QString::fromUtf8(deps.readAllStandardError()).trimmed().right(300));
        } else {
            depsMsg = QString("\n" + i18n("noRepoDeps"));
        }
        // Ergebnis pruefen: pacman -Q <pkgname> (nach erfolgreichem pacman -U)
        QProcess chk; chk.start("pacman", QStringList() << "-Q" << m_lastName);
        chk.waitForFinished();
        if (instExit == 0 && chk.exitCode() == 0) {
            status->setText(i18n("msgInstalled") + m_lastName + depsMsg);
            addInstalled(m_lastName);  // zur persistenten Historie hinzufuegen
        }
        else if (instExit != 0)
            status->setText(i18n("msgInstallFail") + instMsg + depsMsg);
        else
            status->setText(i18n("msgInstallPartial") + m_lastName + " installiert?)" + depsMsg);
    }
    // Hilfsfunktion: Namen zur persistenten Installations-Historie hinzufuegen
    void addInstalled(const QString &name) {
        QStringList lst = m_settings.value("installed", QStringList()).toStringList();
        if (!lst.contains(name)) lst << name;
        m_settings.setValue("installed", lst);
        refreshInstList();
    }
    // Hilfsfunktion: Namen aus der Historie entfernen
    void forgetInstalled(const QString &name) {
        QStringList lst = m_settings.value("installed", QStringList()).toStringList();
        lst.removeAll(name);
        m_settings.setValue("installed", lst);
        refreshInstList();
    }
    // Liste der installierten Pakete aus Settings neu aufbauen
    void refreshInstList() {
        if (!instList) return;
        instList->clear();
        const QStringList lst = m_settings.value("installed", QStringList()).toStringList();
        for (const QString &n : lst)
            instList->addItem(n);
    }
    void removePkg(const QString &name) {
        if (name.isEmpty()) {
            status->setText(i18n("msgNoPkgToRemove"));
            return;
        }
        // Sicherheitsabfrage: welches Paket wird deinstalliert?
        if (QMessageBox::question(this, i18n("confirmUninstallTitle"),
                i18n("confirmUninstallBody") + name,
                QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
            status->setText(i18n("msgRmAborted"));
            return;
        }
        // Passwort über eigenen Dialog (sudo -S liest von stdin)
        bool ok = false;
        const QString pw = QInputDialog::getText(
            this, i18n("sudoUninstall"), i18n("sudoUninstallBody") + name + "):",
            QLineEdit::Password, "", &ok);
        if (!ok || pw.isEmpty()) {
            status->setText(i18n("msgRmAbortedPw"));
            return;
        }
        QProcess sudo;
        sudo.start("sudo", QStringList() << "-S" << "pacman" << "-R" << "--noconfirm" << name);
        sudo.write(pw.toUtf8() + "\n");
        sudo.closeWriteChannel();
        sudo.waitForFinished(-1);
        const QByteArray err = sudo.readAllStandardError();
        // Erfolg: nach Deinstallation darf pacman -Q den Namen NICHT mehr finden
        QProcess chk; chk.start("pacman", QStringList() << "-Q" << name);
        chk.waitForFinished();
        if (chk.exitCode() != 0) {
            status->setText(i18n("msgUninstallDone") + name);
            forgetInstalled(name);  // aus Historie entfernen
        }
        else if (sudo.exitCode() != 0)
            status->setText(i18n("msgUninstallFail") + QString::fromUtf8(err).trimmed());
        else
            status->setText(i18n("msgUninstallPartial") + name + " noch installiert?)");
    }
    void onFile(const QString &path) {
        m_path = path;
        // Ordner der Quelldatei merken, damit "Durchsuchen" dort startet
        m_settings.setValue("lastSrcDir", QFileInfo(path).absolutePath());
        const bool isAppImage = path.endsWith(".AppImage", Qt::CaseInsensitive);
        if (!(path.endsWith(".deb") || path.endsWith(".rpm") || isAppImage)) {
            status->setText(i18n("errNoDebRpm"));
            return;
        }
        // Gewaehlte Datei gross anzeigen, damit kein Zweifel besteht,
        // WELCHES Paket gerade geladen ist (z.B. Programm vs. -data-Paket).
        fileLbl->setText(i18n("chosen") + QFileInfo(path).fileName());
        btnBuild->setEnabled(true);
        m_lastName.clear();   // bei neuer Datei: alte Install/Remove-Ziele vergessen
        m_lastPkg.clear();
        m_lastDeps.clear();
        m_lastAurDeps.clear();
        status->setText(i18n("fileLabel") + QFileInfo(path).fileName());

        // Vorab-Metadaten lesen
        QTemporaryDir tmp;
        if (!tmp.isValid()) return;
        const QString staging = tmp.filePath("staging");
        QDir().mkpath(staging);
        const bool isDeb = path.endsWith(".deb");
        const bool isRpm = path.endsWith(".rpm");
        QMap<QString, QString> meta = parseMeta(path, staging, isDeb, isRpm, isAppImage);
        if (meta.value("ExtractError") == "1") {
            status->setText("❌ AppImage konnte nicht entpackt werden "
                            "(--appimage-extract fehlgeschlagen). Eventuell ein "
                            "inkompatibles/verschlüsseltes AppImage.");
            btnBuild->setEnabled(false);
            return;
        }
        metaLbl->setText(QString("Name: %1   Version: %2   Arch: %3   Format: %4")
            .arg(sanitizeName(meta.value("Package", "?")),
                 sanitizeVer(meta.value("Version", "?")),
                 meta.value("Architecture", "?"),
                 isAppImage ? "AppImage" : (isDeb ? "DEB" : "RPM")));
    }
    void runConvert(bool build) {
        if (m_path.isEmpty()) return;
        btnBuild->setEnabled(false);
        progress->setVisible(true);
        progress->setRange(0, 0);
        status->setText(i18n("working"));

        QTemporaryDir tmp;
        const QString staging = tmp.filePath("staging");
        QDir().mkpath(staging);
        const bool isDeb = m_path.endsWith(".deb");
        const bool isRpm = m_path.endsWith(".rpm");
        const bool isAppImage = m_path.endsWith(".AppImage", Qt::CaseInsensitive);
        QMap<QString, QString> meta = parseMeta(m_path, staging, isDeb, isRpm, isAppImage);
        const QString name = sanitizeName(meta.value("Package", "converted"));
        const QString ver = sanitizeVer(meta.value("Version", "1.0"));
        QString pkgrel = meta.value("Release", "1");
        if (!QRegularExpression("^\\d+$").match(pkgrel).hasMatch()) pkgrel = "1";

        // Ziel-Verzeichnis vom User waehlen (Startordner = zuletzt gewaehlt, sonst Downloads)
        const QString lastDir = m_settings.value("lastOutDir",
            QStandardPaths::writableLocation(QStandardPaths::DownloadLocation)).toString();
        QFileDialog dlg(this, i18n("targetDir") + name, lastDir);
        dlg.setFileMode(QFileDialog::Directory);
        dlg.setOption(QFileDialog::ShowDirsOnly, true);
        dlg.setOption(QFileDialog::DontUseNativeDialog, true);
        if (dlg.exec() != QDialog::Accepted) {
            progress->setVisible(false);
            btnBuild->setEnabled(true);
            status->setText(i18n("errNoTarget"));
            return;
        }
        const QString out = dlg.selectedFiles().value(0);
        if (out.isEmpty()) {
            progress->setVisible(false);
            btnBuild->setEnabled(true);
            status->setText(i18n("errNoTarget"));
            return;
        }
        // gewaehlten Ordner merken (QSettings -> naechstes Mal Startordner)
        m_settings.setValue("lastOutDir", out);

        // Abfrage: nur Paket oder mit Quellen? (vor Berechnung von buildOut)
        QMessageBox box(this);
        box.setWindowTitle(i18n("buildTitle") + name);
        box.setText(i18n("buildAsk"));
        QPushButton *onlyPkg = box.addButton(i18n("buildOnly"), QMessageBox::ActionRole);
        QPushButton *withSrc = box.addButton(i18n("buildSrc"), QMessageBox::ActionRole);
        box.setDefaultButton(onlyPkg);
        box.exec();
        const bool withSources = (box.clickedButton() == withSrc);

        // Bei "Paket + Quellen": eigenen Unterordner <name>-<ver> verwenden,
        // damit Artefakte nicht andere Pakete im Zielordner ueberlagern.
        const QString buildOut = withSources
            ? out + "/" + name + "-" + ver : out;
        QDir().mkpath(buildOut);
        const QString src = buildOut + "/src/staging";
        QDir().mkpath(src);
        copyDir(staging, src);

        // Viele .deb/.rpm legen Spiele/Binares in /usr/games/ ab - das ist
        // auf Arch oft NICHT in $PATH, daher nach /usr/bin/ verschieben,
        // damit das Programm startbar ist.
        QDir gamesDir(src + "/usr/games");
        if (gamesDir.exists()) {
            QDir().mkpath(src + "/usr/bin");
            for (const QFileInfo &fi : gamesDir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
                const QString dest = src + "/usr/bin/" + fi.fileName();
                if (fi.isDir())
                    copyDir(fi.filePath(), dest);
                else {
                    QFile::remove(dest);
                    QFile::rename(fi.filePath(), dest);
                }
            }
            // leeres /usr/games entfernen
            QDir(src + "/usr").rmdir("games");
            // ggf. auch /usr/games komplett weg, wenn nichts anderes drin
            QDir(src + "/usr").rmdir("games");
        }

        // Warnung, wenn dieses Paket KEIN ausfuehrbares Programm enthaelt
        // (z.B. ein reines Daten-Paket). Dann ist es allein nicht startbar.
        QString warnNoBinary;
        {
            bool foundBin = false;
            QDirIterator it(src, QDirIterator::Subdirectories);
            while (it.hasNext()) {
                it.next();
                const QFileInfo fi = it.fileInfo();
                if (!fi.isFile()) continue;
                const QString fp = it.filePath();
                // Binary-Kandidat:
                // - Datei in bin/ oder games/ (deb/rpm)
                // - AppImage: AppRun am Staging-Root (oder in /bin, /usr/bin)
                // - allgemein: ausfuehrbare ELF-Binares groesser 0
                bool isPathBin = fp.contains("/bin/") || fp.contains("/games/");
                bool isAppRun = (fi.fileName() == "AppRun");
                bool isElf = false;
                if (fi.size() > 0) {
                    QFile f(fp);
                    if (f.open(QIODevice::ReadOnly)) {
                        const QByteArray head = f.read(4);
                        isElf = (head == QByteArray("\x7f""ELF"));
                        f.close();
                    }
                }
                if ((isPathBin && fi.size() > 0) || isAppRun || (isElf && fi.size() > 0
                        && (fp.contains("/bin/") || fp.contains("/usr/bin/") || fp.contains("/opt/")))) {
                    foundBin = true;
                    break;
                }
            }
            if (!foundBin && build) {
                warnNoBinary = i18n("warnNoBinary");
            }
        }

        // PKGBUILD schreiben
        const QString arch = mapArch(meta.value("Architecture", "x86_64"));
        QStringList mapped, unknown, aurDeps;
        if (isAppImage) {
            // Option A: AppImage enthaelt eigene Libs. Wir scannen wie bei
            // deb/rpm, loesen sie via pkgfile zu echten Arch-Paketen auf und
            // LOESCHEN danach jede mitgelieferte .so, die Arch ohnehin
            // anbietet. Das Programm nutzt dann die frischen System-Libs
            // (automatische Updates, kleineres Paket). Nur Libs, die Arch
            // NICHT hat, bleiben als Fallback im Paket.
            depsFromBinaries(src, mapped, unknown, aurDeps);
            stripShippedLibs(src, mapped);
        } else {
            // debtap-Methode: echte Binaries scannen (readelf NEEDED) und jede
            // Library via pkgfile zum ECHTEN Arch-Repo-Paketnamen aufloesen.
            // Keine geratene Namenstabelle mehr.
            depsFromBinaries(src, mapped, unknown, aurDeps);
            // Fallback/Ergaenzung: Metadaten-Mapping (falls Binaries nichts liefern)
            if (mapped.isEmpty() && aurDeps.isEmpty())
                mapDeps(meta, isDeb, mapped, unknown, aurDeps);
        }
        // Deps fuer spaetere Installation merken
        m_lastDeps = mapped;
        m_lastAurDeps = aurDeps;
        const QString desc = meta.value("Summary", meta.value("Description", "konvertiertes Paket")).split('\n').first().left(200);
        QString pb;
        pb += QString("# Generiert von Paket Converter (%1 -> Arch)\n").arg(isAppImage ? "AppImage" : (isDeb ? "deb" : "rpm"));
        pb += QString("# Quelle: %1 (%2)\n").arg(meta.value("Package", name), isAppImage ? "AppImage" : (isDeb ? "deb" : "rpm"));
        pb += QString("pkgname=%1\n").arg(name);
        pb += QString("pkgver=%1\n").arg(ver);
        pb += QString("pkgrel=%1\n").arg(pkgrel);
        pb += QString("pkgdesc=\"%1\"\n").arg(desc);
        pb += QString("arch=('%1')\n").arg(arch);
        pb += QString("url=\"%1\"\n").arg(meta.value("URL", ""));
        pb += QString("license=('%1')\n").arg(meta.value("License", "custom"));
        pb += "depends=(\n";
        for (const auto &d : mapped) pb += "  '" + d + "'\n";
        if (mapped.isEmpty()) pb += "  # keine (AppImage ist self-contained)\n";
        pb += ")\n";
        if (isAppImage) {
            pb += "# AppImage: mitgelieferte Libs, die Arch ohnehin anbietet, wurden\n";
            pb += "# entfernt -> das Programm nutzt die frischen System-Libs (Updates).\n";
            pb += "# Nur exotische Libs (ohne Arch-Paket) bleiben als Fallback im Paket.\n";
        }
        pb += QString("# --- nicht gemappte Fremd-Abhaengigkeiten (manuell pruefen) ---\n");
        pb += QString("# TODO: %1\n").arg(unknown.isEmpty() ? "keine" : unknown.join(", "));
        if (!aurDeps.isEmpty()) {
            pb += QString("# --- ACHTUNG: nur im AUR verfuegbar (nicht automatisch installierbar) ---\n"
                         "# AUR: %1\n").arg(aurDeps.join(", "));
        }
        pb += "options=('!strip' '!emptydirs')\n";
        pb += "source=()\n";
        pb += "package() {\n";
        pb += "    cp -a \"$srcdir/staging/.\" \"$pkgdir/\"\n";
        pb += "}\n";

        QFile f(buildOut + "/PKGBUILD");
        if (!f.open(QIODevice::WriteOnly)) {
            status->setText(i18n("errPkgbuild") + out);
            progress->setVisible(false);
            btnBuild->setEnabled(true);
            return;
        }
        f.write(pb.toUtf8());
        f.close();

        QString result = QString("%1 (%2): %3\n").arg(i18n("mapped"), QString::number(mapped.size()),
            mapped.isEmpty() ? i18n("noMapped") : mapped.join(", "));
        result += QString("%1 (%2): %3\n\n").arg(i18n("unknown"), QString::number(unknown.size()),
            unknown.isEmpty() ? i18n("allOk") : unknown.join(", "));
        if (!warnNoBinary.isEmpty())
            result += warnNoBinary;
        if (!aurDeps.isEmpty())
            result += i18n("notSatisfiable") + aurDeps.join(", ")
                      + i18n("notSatisfiableNote");
        // --- Debian/RPM-Depends auswerten: welche ZUSATZPAKETE fehlen? ---
        // (Library-Deps werden bereits ueber readelf/pkgfile erkannt; hier geht
        // (z.B. reine Daten-Pakete, Fonts, -common ...)
        QStringList extraPkgs;
        {
            QString raw = meta.value(isDeb ? "Depends" : "Requires", "");
            // deb: komma-getrennt, kann Versionen haben ("pkg (>= 1.0) | alt")
            // rpm: eine Require pro Zeile
            QStringList items;
            if (isDeb) items = raw.split(',', Qt::SkipEmptyParts);
            else       items = raw.split('\n', Qt::SkipEmptyParts);
            const QRegularExpression verRe("\\s*[\\(|\\[].*"); // Version/Arch in Klammern weg
            const QStringList knownLibPrefix = {
                "libc", "libstdc", "libgcc", "libgl", "libglvnd", "libx", "libSDL",
                "libopenal", "libalut", "libncurses", "librecode", "glibc", "gcc-libs",
                "zlib", "libjpeg", "libpng", "freetype", "sdl", "libuuid", "libffi"
            };
            for (QString it : items) {
                it = it.split('|').first();          // Alternative (|) -> erste nehmen
                it = it.remove(verRe).trimmed();
                it = it.section(' ', 0, 0).trimmed(); // "pkg (>=..)" -> "pkg"
                if (it.isEmpty()) continue;
                // RPM-interne Pseudo-Deps (rpmlib, rtld(GNU_HASH), ...)
                // sind KEIN echtes Paket -> ignorieren
                if (it.startsWith("rpmlib") || it.startsWith("rtld(")
                    || it.startsWith("/") || (it.contains("(") && !it.contains(')'))) continue;
                // Library-artige Deps ueberspringen (die kommen ueber readelf)
                bool looksLib = false;
                for (const QString &p : knownLibPrefix)
                    if (it.startsWith(p) || it.contains(".so")) { looksLib = true; break; }
                if (looksLib) continue;
                // eigene Paketnamen (z.B. -data) nicht doppelt listen
                if (it == name) continue;
                if (!extraPkgs.contains(it)) extraPkgs << it;
            }
        }
        if (!extraPkgs.isEmpty()) {
            result += i18n("extraDeps") + extraPkgs.join(", ")
                      + i18n("extraDepsNote");
        }

        result += i18n("pkgbuildLabel") + buildOut + "/PKGBUILD\n";

        if (build) {
            QStringList args = {"-f", "--nodeps", "--noconfirm"};
            if (withSources) args.prepend("-s"); // sources mitbauen
            QProcess mp;
            mp.setWorkingDirectory(buildOut);
            mp.start("makepkg", args);
            mp.waitForFinished(-1);
            if (mp.exitCode() == 0) {
                // Paketname deterministisch aus name/ver/pkgrel ableiten
                // (nicht aus dem Verzeichnis suchen - dort koennen alte
                // Pakete liegen, die dann faelschlicherweise erwischt wuerden).
                const QString built = QString("%1-%2-%3-%4.pkg.tar.zst").arg(name, ver, pkgrel, arch);
                result += i18n("msgPkgBuilt") + "\n" + buildOut + "/" + built + "\n";
                status->setText(i18n("msgPkgBuilt"));
                m_lastPkg = buildOut + "/" + built;
                m_lastName = name;
                btnInstall->setEnabled(true);  // Installieren jetzt moeglich
            } else {
                result += i18n("msgBuildFail") + "\n" + mp.readAllStandardError();
                status->setText(i18n("msgBuildFail"));
            }
            // src-Paket Hinweis
            const QStringList srcs = QDir(buildOut).entryList(QStringList() << "*.src.tar.gz" << "*.src.tar.zst");
            if (!srcs.isEmpty())
                result += "✅ Sources: " + buildOut + "/" + srcs.first() + "\n";

            // Bei "Nur Paket": NUR die eigenen Arbeitsreste (pkg/, src/, PKGBUILD)
            // entfernen - niemals bereits vorhandene .pkg.tar.zst (fremde Pakete).
            if (!withSources) {
                QDir od(out);
                for (const QString &e : od.entryList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
                    if (e == "pkg" || e == "src" || e == "PKGBUILD")
                        ; // diese entfernen
                    else
                        continue; // alles andere (inkl. fremder .pkg.tar.zst) behalten
                    QFileInfo fi(od.filePath(e));
                    if (fi.isDir()) QDir(od.filePath(e)).removeRecursively();
                    else od.remove(e);
                }
                result += i18n("cleanup");
            }
        } else {
            status->setText(i18n("msgPkgbuildDone"));
        }

        depView->setPlainText(result);
        progress->setVisible(false);
        btnBuild->setEnabled(true);
    }

private:
    // ---- helpers ----
    QMap<QString, QString> parseMeta(const QString &path, const QString &staging, bool isDeb, bool isRpm, bool isAppImage) {
        QMap<QString, QString> meta;
        if (isAppImage) {
            // AppImage entpacken. Typ-2-AppImages haben einen ELF-Loader vor
            // dem squashfs, den unsquashfs nicht direkt liest -> daher das
            // eigene --appimage-extract nutzen (funktioniert fuer beide Typen).
            QProcess us;
            us.start("bash", QStringList() << "-c"
                << QString("cd '%1' && chmod u+x '%2' 2>/dev/null ; '%2' --appimage-extract >/dev/null 2>&1 && "
                           "mv squashfs-root/* . 2>/dev/null ; rmdir squashfs-root 2>/dev/null")
                       .arg(staging, path));
            us.waitForFinished(-1);
            if (!QFile::exists(staging + "/AppRun") && !QFile::exists(staging + "/usr")) {
                // Extraktion fehlgeschlagen -> Hinweis, damit es nicht still scheitert
                meta["ExtractError"] = "1";
            }
            // Name + Version aus Dateiname ableiten (Format: Name-x.y.z[-arch].AppImage)
            QString base = QFileInfo(path).completeBaseName(); // ohne .AppImage
            // Version zuerst aus dem VOLLEN Namen extrahieren (bevor Arch/Build-
            // Suffixe entfernt werden), damit z.B. LM-Studio-0.4.20-1-x64 die
            // Version 0.4.20 (nicht die Build-Nummer 1) liefert.
            QString ver;
            {
                QRegularExpression verRe("v?[0-9]+(?:\\.[0-9]+)+"); // min. eine Punkt-Version
                QRegularExpressionMatch vm = verRe.match(base);
                if (vm.hasMatch()) {
                    ver = vm.captured(0);
                } else {
                    // fallback: einzelne Zahl am Ende (z.B. -1)
                    QRegularExpression single("-(v?[0-9]+)$");
                    QRegularExpressionMatch sm = single.match(base);
                    if (sm.hasMatch()) ver = sm.captured(1);
                }
            }
            // Name = alles vor der Versionsgruppe bereinigen (Arch-Suffix etc.)
            if (!ver.isEmpty()) {
                // letztes '-' + Version + evtl. Arch-Suffix abschneiden
                base.replace(QRegularExpression("[-_]?" + QRegularExpression::escape(ver) + "[-_](x86_64|aarch64|arm64|x64|amd64|i386|i686)$"), "");
                base.replace(QRegularExpression("[-_]" + QRegularExpression::escape(ver) + "$"), "");
            }
            meta["Package"] = base;
            meta["Version"] = ver.isEmpty() ? "1.0" : ver;
            meta["Architecture"] = "x86_64";
            meta["Release"] = "1";
            // Versuche .desktop im entpackten Image zu finden (fuer Summary/Icon)
            QDirIterator it(staging, QStringList() << "*.desktop", QDir::Files, QDirIterator::Subdirectories);
            if (it.hasNext()) {
                const QString desk = it.next();
                QFile df(desk);
                if (df.open(QIODevice::ReadOnly)) {
                    const QString txt = df.readAll();
                    for (const QString &line : txt.split('\n')) {
                        QString k, v;
                        int idx = line.indexOf('=');
                        if (idx > 0) { k = line.left(idx).trimmed(); v = line.mid(idx + 1).trimmed(); }
                        if (k == "Name") meta["Summary"] = v;
                        else if (k == "Comment") { if (!meta.contains("Summary")) meta["Summary"] = v; }
                        else if (k == "Icon") meta["Icon"] = v;
                    }
                }
            }
            return meta;
        }
        if (isDeb) {
            QTemporaryDir work;
            QString ctrlDir = work.filePath("ctrl");
            QDir().mkpath(ctrlDir);
            // ar entpackt nach work (via bash cd, -C wird nicht von jedem ar unterstuetzt)
            QProcess arx; arx.start("bash", QStringList() << "-c"
                << QString("cd '%1' && ar x '%2'").arg(work.path(), path));
            arx.waitForFinished();
            // control
            QProcess ar; ar.start("bash", QStringList() << "-c"
                << QString("cd '%1' && ls control.tar* 2>/dev/null | head -1").arg(work.path()));
            ar.waitForFinished();
            QString ca = work.filePath(ar.readAllStandardOutput().trimmed());
            if (QFile::exists(ca)) {
                QProcess::execute("bsdtar", QStringList() << "-xf" << ca << "-C" << ctrlDir);
                QFile cf(ctrlDir + "/control");
                if (cf.open(QIODevice::ReadOnly)) {
                    const QString txt = cf.readAll();
                    for (const QString &line : txt.split('\n')) {
                        int idx = line.indexOf(':');
                        if (idx > 0) meta[line.left(idx).trimmed()] = line.mid(idx + 1).trimmed();
                    }
                }
            }
            // data
            QProcess ar2; ar2.start("bash", QStringList() << "-c"
                << QString("cd '%1' && ls data.tar* 2>/dev/null | head -1").arg(work.path()));
            ar2.waitForFinished();
            QString da = work.filePath(ar2.readAllStandardOutput().trimmed());
            if (QFile::exists(da))
                QProcess::execute("bsdtar", QStringList() << "-xf" << da << "-C" << staging);
        } else {
            // RPM: zuverlaessig via rpm2cpio | cpio entpacken (bsdtar kann
            // nicht alle RPM-Formate/Compressions lesen -> sonst leeres Paket)
            QProcess rp;
            rp.start("bash", QStringList() << "-c"
                << QString("rpm2cpio '%1' | (cd '%2' && cpio -idm 2>/dev/null)").arg(path, staging));
            rp.waitForFinished(-1);
            QProcess rpm;
            rpm.start("rpm", QStringList() << "-qp" << "--qf"
                << "%{NAME}\n%{VERSION}\n%{RELEASE}\n%{ARCH}\n%{SUMMARY}\n%{URL}\n%{LICENSE}\n"
                << path);
            rpm.waitForFinished();
            QStringList parts = QString(rpm.readAllStandardOutput()).split('\n');
            QStringList keys = {"Package", "Version", "Release", "Architecture", "Summary", "URL", "License"};
            for (int i = 0; i < keys.size() && i < parts.size(); ++i)
                meta[keys[i]] = parts[i].trimmed();
            QProcess req;
            req.start("rpm", QStringList() << "-qp" << "--requires" << path);
            req.waitForFinished();
            meta["Requires"] = req.readAllStandardOutput();
        }
        return meta;
    }
    QString sanitizeName(const QString &n) {
        QString s = n.toLower();
        s.replace(QRegularExpression("[^a-z0-9@._+-]"), "-");
        while (s.contains("--")) s.replace("--", "-");
        return s.replace(QRegularExpression("^-|-$"), "");
    }
    QString sanitizeVer(const QString &v) {
        QString s = v.trimmed();
        int c = s.indexOf(':'); if (c >= 0) s = s.mid(c + 1);
        s.replace(QRegularExpression("[-~^]"), "_");
        return s;
    }
    QString mapArch(const QString &a) {
        static const QMap<QString, QString> m = {
            {"amd64", "x86_64"}, {"x86_64", "x86_64"}, {"x86-64", "x86_64"},
            {"aarch64", "aarch64"}, {"arm64", "aarch64"},
            {"armhf", "armv7h"}, {"armv7hl", "armv7h"}, {"armel", "armv6h"},
            {"i386", "i686"}, {"i486", "i686"}, {"i586", "i686"},
            {"noarch", "any"}, {"all", "any"}, {"any", "any"}};
        return m.value(a, a);
    }
    // debtap-Methode: alle ELF-Binaries im Staging scannen, benoetigte
    // AppImage-Hilfe: jede mitgelieferte .so, die zu einem der genannten
    // Arch-Repo-Pakete gehoert, aus dem staging-Verzeichnis loeschen, damit
    // das Programm zur Laufzeit die frische System-Lib nutzt (keine
    // veralteten Mitliefer-Libs mehr). Nur Libs OHNE Arch-Paket bleiben.
    void stripShippedLibs(const QString &stagingDir, const QStringList &mapped) {
        Q_UNUSED(mapped);
        // Alle mitgelieferten .so* einsammeln
        QProcess own;
        own.start("bash", QStringList() << "-c" << QString(
            "cd %1 && find . -type f -name '*.so*' -printf '%p\\t%f\\n'").arg(stagingDir));
        own.waitForFinished(15000);
        const QString out = QString::fromUtf8(own.readAllStandardOutput());
        for (const QString &line : out.split('\n', Qt::SkipEmptyParts)) {
            const QString path = line.section('\t', 0, 0).trimmed();
            const QString base = line.section('\t', 1, 1).trimmed();
            if (path.isEmpty() || base.isEmpty()) continue;
            // gehoert diese Lib zu einem offiziellen Arch-Repo-Paket?
            QProcess pf;
            pf.start("pkgfile", QStringList() << base);
            pf.waitForFinished(20000);
            const QStringList hits = QString::fromUtf8(pf.readAllStandardOutput())
                                         .split('\n', Qt::SkipEmptyParts);
            bool repoHas = false;
            for (const QString &h : hits) {
                const QString cand = h.section('/', 1, 1).section('\t', 0, 0).trimmed();
                if (cand.startsWith("lib32-")) continue;
                if (!cand.isEmpty()) { repoHas = true; break; }
            }
            if (repoHas) {
                // Lib loeschen -> System-Lib wird genutzt
                QFile::remove(path);
                // ggf. leeres Verzeichnis aufraeumen (eine Ebene)
                QFileInfo fi(path);
                QDir(fi.absolutePath()).rmdir(".");
            }
        }
    }
    // Libraries (readelf NEEDED) sammeln und via pkgfile zum echten
    // Arch-Repo-Paket aufloesen. core/extra/multilib bevorzugt (kein AUR).
    void depsFromBinaries(const QString &stagingDir, QStringList &mapped, QStringList &unknown, QStringList &aurDeps) {
        // 1) Alle NEEDED-Libraries aller ELF-Dateien einsammeln
        // (sed statt grep -oP: keine Backslash-Escape-Fallen in C++-Strings)
        QProcess scan;
        scan.start("bash", QStringList() << "-c" << QString(
            "cd '%1' && find . -type f -print0 | xargs -0 file -N 2>/dev/null "
            "| grep 'ELF' | cut -d: -f1 "
            "| xargs -r -I{} readelf -d {} 2>/dev/null "
            "| grep NEEDED | sed 's/.*\\[//; s/\\].*//' | sort -u").arg(stagingDir));
        scan.waitForFinished(60000);
        const QStringList libs = QString::fromUtf8(scan.readAllStandardOutput())
                                     .split('\n', Qt::SkipEmptyParts);
        // Eigene mitgelieferte Libs nicht als Abhaengigkeit werten
        QSet<QString> shipped;
        {
            QProcess own;
            own.start("bash", QStringList() << "-c" << QString(
                "cd %1 && find . -type f -name '*.so*' -printf '%f\\n' | sort -u").arg(stagingDir));
            own.waitForFinished(15000);
            for (const QString &s : QString::fromUtf8(own.readAllStandardOutput())
                                        .split('\n', Qt::SkipEmptyParts))
                shipped.insert(s);
        }
        QSet<QString> seen;
        for (const QString &lib : libs) {
            if (shipped.contains(lib)) continue;                 // liefern wir selbst mit
            // 2) pkgfile: welches Repo-Paket enthaelt diese Library?
            QProcess pf;
            pf.start("pkgfile", QStringList() << lib);
            pf.waitForFinished(20000);
            QStringList hits = QString::fromUtf8(pf.readAllStandardOutput())
                                         .split('\n', Qt::SkipEmptyParts);
            if (hits.isEmpty()) {
                // Kein Repo-Paket enthaelt die EXAKTE Soname-Version
                // (z.B. librecode.so.0 vs. Arch librecode.so.3).
                // Ein Paket mit anderer Version wuerde das Binary NICHT
                // reparieren -> ehrlich als nicht erfuellbar melden.
                if (!aurDeps.contains(lib)) aurDeps << lib;
                continue;
            }
            QString pkg;
            // offizielle Repos bevorzugen: erst core/extra, dann multilib.
            // lib32-Pakete sind fuer 64-bit-Binaries falsch -> ueberspringen.
            for (const QString &h : hits) {
                const QString repo = h.section('/', 0, 0);
                const QString cand = h.section('/', 1, 1).section('\t', 0, 0).trimmed();
                if (cand.startsWith("lib32-")) continue;
                if (repo == "core" || repo == "extra") { pkg = cand; break; }
                if (pkg.isEmpty() && repo == "multilib") pkg = cand;
            }
            if (pkg.isEmpty()) {
                for (const QString &h : hits) {
                    const QString cand = h.section('/', 1, 1).section('\t', 0, 0).trimmed();
                    if (!cand.startsWith("lib32-")) { pkg = cand; break; }
                }
            }
            if (!pkg.isEmpty()) {
                // Basispakete nicht als depends auffuehren
                if (pkg == "glibc" || pkg == "gcc-libs") continue;
                if (!seen.contains(pkg)) { mapped << pkg; seen.insert(pkg); }
            } else {
                // kein Repo-Paket liefert diese Library -> nur via AUR/manuell
                if (!aurDeps.contains(lib)) aurDeps << lib;
            }
        }
        Q_UNUSED(unknown);
    }
    void mapDeps(const QMap<QString, QString> &meta, bool isDeb, QStringList &mapped, QStringList &unknown, QStringList &aurDeps) {
        const QMap<QString, QString> common = {
            {"glibc", "glibc"}, {"libc6", "glibc"}, {"libstdc++6", "libstdc++"},
            {"libstdc++", "libstdc++"}, {"zlib1g", "zlib"}, {"zlib", "zlib"},
            {"gcc-libs", "gcc-libs"}, {"libgcc-s1", "gcc-libs"},
            {"libssl3", "openssl"}, {"openssl-libs", "openssl"},
            {"ca-certificates", "ca-certificates"}};
        const QMap<QString, QString> deb = {
            {"libglib2.0-0", "glib2"}, {"libgtk-3-0", "gtk3"}, {"libgtk2.0-0", "gtk2"},
            {"libpango-1.0-0", "pango"}, {"libcairo2", "cairo"},
            {"libgdk-pixbuf2.0-0", "gdk-pixbuf2"}, {"libx11-6", "libx11"},
            {"libxext6", "libxext"}, {"libxtst6", "libxtst"}, {"libusb-1.0-0", "libusb"},
            {"libudev1", "systemd-libs"}, {"libsystemd0", "systemd-libs"},
            {"libdbus-1-3", "dbus"}, {"libexpat1", "expat"}, {"libffi8", "libffi"},
            {"libpcre3", "pcre"}, {"fontconfig", "fontconfig"}, {"libfreetype6", "freetype2"},
            {"libpng16-16", "libpng"}, {"libjpeg62-turbo", "libjpeg-turbo"},
            {"librecode0", "recode"}, {"librecode3", "recode"},
            {"librecode16-3", "recode"}, {"librecode32-3", "recode"},
            {"libcurl4", "curl"}, {"libsqlite3-0", "sqlite"}, {"libxml2", "libxml2"},
            {"libncurses6", "ncurses"}, {"libreadline8", "readline"},
            {"libuuid1", "util-linux-libs"}, {"libpopt0", "popt"}, {"libgomp1", "gcc-libs"},
            {"libacl1", "acl"}, {"libattr1", "attr"},
            // Bibliotheks-Abhaengigkeiten (Debian SO-Paketnamen -> Arch)
            {"libglc0", "glc-lib"}, {"libalut0", "freealut"}, {"libopenal1", "openal"},
            {"libsdl2-2.0-0", "sdl2"}, {"libsdl2-image-2.0-0", "sdl2_image"},
            {"libsdl2-mixer-2.0-0", "sdl2_mixer"}, {"libsdl2-ttf-2.0-0", "sdl2_ttf"},
            {"libsdl1.2debian", "sdl"}, {"libgl1", "libgl"}, {"libglu1-mesa", "glu"},
            {"libglu1", "glu"}, {"libglvnd0", "libglvnd"}, {"libvorbis0a", "libvorbis"},
            {"libvorbisfile3", "libvorbis"}, {"libogg0", "libogg"}, {"libjpeg62-turbo", "libjpeg-turbo"},
            {"libpng16-16", "libpng"}, {"libxrandr2", "libxrandr"}, {"libxinerama1", "libxinerama"},
            {"libxxf86vm1", "libxxf86vm"}, {"libxcursor1", "libxcursor"}, {"libxi6", "libxi"},
            {"libxrender1", "libxrender"}, {"libxfixes3", "libxfixes"}, {"libxdamage1", "libxdamage"}};
        const QMap<QString, QString> rpm = {
            {"glib2", "glib2"}, {"glib2-0", "glib2"}, {"gtk3", "gtk3"}, {"gtk2", "gtk2"},
            {"pango", "pango"}, {"cairo", "cairo"}, {"libX11", "libx11"}, {"libXext", "libxext"},
            {"libXtst", "libxtst"}, {"libusb-1", "libusb"}, {"systemd-libs", "systemd-libs"},
            {"dbus-libs", "dbus"}, {"expat", "expat"}, {"libffi", "libffi"}, {"pcre", "pcre"},
            {"fontconfig", "fontconfig"}, {"freetype", "freetype2"}, {"libpng", "libpng"},
            {"libjpeg-turbo", "libjpeg-turbo"}, {"curl", "curl"}, {"sqlite", "sqlite"},
            {"libxml2", "libxml2"}, {"ncurses", "ncurses"}, {"readline", "readline"},
            {"util-linux", "util-linux-libs"}, {"popt", "popt"}, {"openssl", "openssl"},
            {"zlib", "zlib"}, {"acl", "acl"}, {"attr", "attr"},
            // Bibliotheks-Abhaengigkeiten (RPM SO-Namen inkl. .so.N -> Arch-Pakete)
            {"libGLC.so.0", "glc-lib"}, {"libalut.so.0", "freealut"}, {"libopenal.so.1", "openal"},
            {"libSDL2-2.0.so.0", "sdl2"}, {"libSDL2_image-2.0.so.0", "sdl2_image"},
            {"libSDL2_mixer-2.0.so.0", "sdl2_mixer"}, {"libSDL2_ttf-2.0.so.0", "sdl2_ttf"},
            {"libSDL-1.2.so.0", "sdl"}, {"libGL.so.1", "libgl"}, {"libGLU.so.1", "glu"},
            {"libGLX.so.0", "libglvnd"}, {"libEGL.so.1", "libglvnd"},
            {"libXrandr.so.2", "libxrandr"}, {"libXinerama.so.1", "libxinerama"},
            {"libXxf86vm.so.1", "libxxf86vm"}, {"libXcursor.so.1", "libxcursor"},
            {"libXi.so.6", "libxi"}, {"libXrender.so.1", "libxrender"},
            {"libXfixes.so.3", "libxfixes"}, {"libXdamage.so.1", "libxdamage"}, {"libXft.so.2", "libxft"},
            {"libvorbis.so.0", "libvorbis"}, {"libvorbisfile.so.3", "libvorbis"},
            {"libogg.so.0", "libogg"}, {"libpng16.so.16", "libpng"},
            {"libjpeg.so.62", "libjpeg-turbo"}, {"libz.so.1", "zlib"},
            // Debian-spezifische Pakete, die auf Arch nicht existieren -> ignorieren
            // (Daten sind bereits im umgewandelten Paket enthalten, oder es gibt
            // kein Arch-Aequivalent, das als depends sinnvoll waere)
            {"libc6", ""}, {"libgcc1", ""}, {"libstdc++6", ""}, {"dpkg", ""},
            {"fonts-dejavu", ""}, {"ttf-dejavu", ""}};
        QStringList raw = isDeb
            ? meta.value("Depends", "").split(',', Qt::SkipEmptyParts)
            : meta.value("Requires", "").split('\n', Qt::SkipEmptyParts);
        QSet<QString> seen;
        for (QString part : raw) {
            part = part.trimmed();
            if (part.isEmpty()) continue;
            QString name;
            if (isDeb) name = part.split(QRegularExpression("[\\s(]")).first().trimmed();
            else {
                if (part.startsWith("rpmlib(") || part.startsWith("/"))
                    continue;
                name = part.split(QRegularExpression("[ <>=!\\[]")).first().trimmed();
                // GLIBC-interne Laufzeit-Libs nicht als Abhaengigkeit setzen
                // (libc, libm, libgcc_s, libstdc++, libdl, librt, libpthread ...)
                if (name == "libc" || name == "libm" || name == "libgcc_s" ||
                    name == "libstdc++" || name == "libdl" || name == "librt" ||
                    name == "libpthread" || name == "libresolv" || name == "libutil")
                    continue;
            }
            if (name.isEmpty() || name.contains('(')) continue;
            const QMap<QString, QString> &tbl = isDeb ? deb : rpm;
            QString m = tbl.value(name, common.value(name));
            // AUR-only Pakete (nicht in offiziellen Repos) duerfen NICHT in
            // depends=() landen, sonst scheitert pacman -S. Sie werden separat
            // als Warnung gemeldet (koennen ohne AUR nicht installiert werden).
            static const QSet<QString> aurOnly = {"glc-lib", "qt4", "libtxc_dxtn"};
            if (!m.isEmpty() && aurOnly.contains(m)) {
                if (!aurDeps.contains(m)) aurDeps << m;
                continue;
            }
            if (!m.isEmpty()) {
                // Nur in depends=() / Auto-Install aufnehmen, wenn das Paket
                // WIRKLICH in den konfigurierten Repos existiert. Sonst wuerde
                // 'pacman -S' still fehlschlagen und nichts installiert werden.
                QProcess ss;
                ss.start("bash", QStringList() << "-c"
                    << QString("pacman -Ss '^%1$' >/dev/null 2>&1").arg(m));
                ss.waitForFinished();
                const bool exists = (ss.exitCode() == 0);
                if (exists) {
                    if (!seen.contains(m)) { mapped << m; seen.insert(m); }
                } else {
                    if (!unknown.contains(m)) unknown << m;
                }
            } else { if (!unknown.contains(name)) unknown << name; }
        }
    }
    void copyDir(const QString &src, const QString &dst) {
        QDir d(src);
        for (const QFileInfo &fi : d.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
            const QString target = dst + "/" + fi.fileName();
            if (fi.isDir()) { QDir().mkpath(target); copyDir(fi.filePath(), target); }
            else QFile::copy(fi.filePath(), target);
        }
    }

    void buildUi() {
        auto *root = new QWidget(this);
        setCentralWidget(root);
        auto *v = new QVBoxLayout(root);
        v->setContentsMargins(24, 24, 24, 24);
        v->setSpacing(16);

        // Header mit Titel + Theme-Toggle + Sprachauswahl
        auto *header = new QHBoxLayout();
        titleLbl = new QLabel("Paket Converter"); titleLbl->setObjectName("title");
        auto *sub = new QLabel("Wandelt Debian (.deb) / RedHat (.rpm) / AppImage zu ArchLinux um");
        sub->setObjectName("sub");
        subLbl = sub;
        auto *leftHead = new QVBoxLayout();
        leftHead->addWidget(titleLbl); leftHead->addWidget(sub);
        header->addLayout(leftHead, 1);
        // Sprachauswahl
        auto *langRow = new QHBoxLayout();
        auto *langLbl = new QLabel("Sprache:"); langLbl->setObjectName("sub");
        langCombo = new QComboBox();
        langCombo->addItem("Deutsch", "de");
        langCombo->addItem("English", "en");
        langCombo->addItem("Français", "fr");
        langCombo->addItem("Español", "es");
        langCombo->addItem("Türkçe", "tr");
        langCombo->addItem("Português", "pt");
        langCombo->setFixedWidth(120);
        connect(langCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int i) {
            m_lang = langCombo->itemData(i).toString();
            m_settings.setValue("lang", m_lang);
            applyLang();
        });
        langRow->addWidget(langLbl);
        langRow->addWidget(langCombo);
        header->addLayout(langRow, 0);
        themeBtn = new QPushButton(m_dark ? "☀ Hell" : "🌙 Dunkel");
        themeBtn->setObjectName("ghost");
        themeBtn->setFixedWidth(110);
        connect(themeBtn, &QPushButton::clicked, this, &MainWindow::toggleTheme);
        header->addWidget(themeBtn, 0, Qt::AlignTop);
        v->addLayout(header);
        v->addSpacing(4);

        auto *card = new QFrame(); card->setObjectName("card");
        auto *cv = new QVBoxLayout(card); cv->setSpacing(12);
        auto *hl = new QHBoxLayout();
        drop = new DropLine(this);
        drop->setMinimumHeight(44);
        browseBtn = new QPushButton("Durchsuchen"); browseBtn->setObjectName("ghost");
        connect(browseBtn, &QPushButton::clicked, this, &MainWindow::browse);
        connect(drop, &DropLine::fileDropped, this, &MainWindow::onFile);
        hl->addWidget(drop, 3); hl->addWidget(browseBtn, 1);
        cv->addLayout(hl);
        metaLbl = new QLabel("Noch keine Datei ausgewählt."); metaLbl->setObjectName("h");
        cv->addWidget(metaLbl);
        fileLbl = new QLabel(""); fileLbl->setObjectName("sub");
        cv->addWidget(fileLbl);
        v->addWidget(card);

        dep_h = new QLabel("Abhängigkeiten"); dep_h->setObjectName("h");
        v->addWidget(dep_h);
        depView = new QTextEdit(); depView->setReadOnly(true); depView->setMinimumHeight(150);
        v->addWidget(depView);

        auto *bcard = new QFrame(); bcard->setObjectName("card");
        auto *bv = new QVBoxLayout(bcard);
        progress = new QProgressBar(); progress->setVisible(false);
        bv->addWidget(progress);
        auto *bl = new QHBoxLayout();
        btnBuild = new QPushButton("Paket bauen"); btnBuild->setEnabled(false);
        connect(btnBuild, &QPushButton::clicked, this, [this] { runConvert(true); });
        btnInstall = new QPushButton("Paket installieren"); btnInstall->setEnabled(false);
        connect(btnInstall, &QPushButton::clicked, this, &MainWindow::installPkg);
        bl->addWidget(btnBuild, 2);
        bl->addWidget(btnInstall, 1);
        bv->addLayout(bl);
        v->addWidget(bcard);

        // Liste der installierten Pakete (persistent ueber QSettings)
        auto *icard = new QFrame(); icard->setObjectName("card");
        auto *iv = new QVBoxLayout(icard);
        inst_h = new QLabel("Installierte Pakete (zum Deinstallieren wählen)"); inst_h->setObjectName("h");
        iv->addWidget(inst_h);
        instList = new QListWidget();
        instList->setMinimumHeight(90);
        iv->addWidget(instList);
        uninstallBtn = new QPushButton("Ausgewähltes Paket deinstallieren"); uninstallBtn->setObjectName("ghost");
        connect(uninstallBtn, &QPushButton::clicked, this, [this] {
            QListWidgetItem *it = instList->currentItem();
            if (it) removePkg(it->text());
            else status->setText("❌ Bitte zuerst ein Paket in der Liste auswählen.");
        });
        iv->addWidget(uninstallBtn);
        v->addWidget(icard);

        refreshInstList();  // Historie aus Settings laden
        v->addStretch(1);
        status = new QLabel(""); status->setObjectName("sub");
        // Text markier- und kopierbar machen (Maus + Tastatur)
        status->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
        status->setCursor(Qt::IBeamCursor);
        v->addWidget(status);

        // Branding: "created by SattNEK" (ganz unten, mittig)
        auto *brand = new QLabel();
        brand->setObjectName("brand");
        brand->setAlignment(Qt::AlignCenter);
        // Logo aus mehreren moeglichen Pfaden laden (Build-Ordner + installiert)
        QString brandPath;
        QStringList brandCandidates{
            QCoreApplication::applicationDirPath() + "/created_by_sattnek.png",
            "/usr/share/icons/hicolor/scalable/apps/created_by_sattnek.png",
            "/usr/share/pkg_convert/created_by_sattnek.png"
        };
        for (const QString &c : brandCandidates) {
            if (QFile::exists(c)) { brandPath = c; break; }
        }
        if (!brandPath.isEmpty()) {
            QPixmap bm(brandPath);
            // auf max 360px Breite skalieren
            if (bm.width() > 360) bm = bm.scaledToWidth(360, Qt::SmoothTransformation);
            brand->setPixmap(bm);
        } else {
            brand->setText("created by SattNEK");  // Fallback-Text
        }
        v->addWidget(brand);
    }

    DropLine *drop = nullptr;
    QLabel *metaLbl = nullptr, *status = nullptr, *fileLbl = nullptr;
    QLabel *titleLbl = nullptr, *subLbl = nullptr, *dep_h = nullptr, *inst_h = nullptr;
    QTextEdit *depView = nullptr;
    QProgressBar *progress = nullptr;
    QPushButton *btnBuild = nullptr, *themeBtn = nullptr, *btnInstall = nullptr;
    QPushButton *browseBtn = nullptr, *uninstallBtn = nullptr;
    QComboBox *langCombo = nullptr;
    QListWidget *instList = nullptr;  // Liste der installierten Pakete (persistent)
    QString m_path;
    QString m_lastPkg;  // Pfad zum zuletzt gebauten Paket (fuer Installieren)
    QString m_lastName; // pkgname des zuletzt gebauten Pakets
    QStringList m_lastDeps;     // gemappte Repo-Abhaengigkeiten (fuer pacman -S --asdeps)
    QStringList m_lastAurDeps;  // Abhaengigkeiten, die nur im AUR liegen (nicht automatisch installierbar)
    bool m_dark = false;
    QString m_lang = "de";
    QSettings m_settings{ "pkg_convert", "gui" };
};

int main(int argc, char **argv) {
    QApplication a(argc, argv);
    a.setFont(QFont("Noto Sans", 11));
    MainWindow w;
    w.show();
    return a.exec();
}

#include "pkg_convert_gui.moc"
