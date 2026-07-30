// lang_de.cpp — Uebersetzungen fuer pkg_convert (Sprache: de)
#include <QString>
#include <QMap>

QMap<QString, QString> lang_de() {
    QMap<QString, QString> m;
    m.insert("title", "Paket Converter");
    m.insert("subtitle", "Wandelt Debian (.deb) / RedHat (.rpm) zu ArchLinux um");
    m.insert("dropHint", "Datei hierher ziehen (.deb / .rpm) oder 'Durchsuchen' klicken");
    m.insert("langLabel", "Sprache:");
    m.insert("browse", "Durchsuchen");
    m.insert("noFile", "Noch keine Datei ausgewählt.");
    m.insert("deps", "Abhängigkeiten");
    m.insert("build", "Paket bauen");
    m.insert("install", "Paket installieren");
    m.insert("installed", "Installierte Pakete (zum Deinstallieren wählen)");
    m.insert("uninstall", "Ausgewähltes Paket deinstallieren");
    m.insert("themeLight", "Dark");
    m.insert("themeDark", "Light");
    m.insert("choosePkg", "Paket wählen");
    m.insert("pkgsFilter", "Pakete (*.deb *.rpm)");
    m.insert("errNoDebRpm", "❌ Bitte eine .deb- oder .rpm-Datei wählen.");
    m.insert("errNoBuiltPkg", "❌ Noch kein Paket gebaut.");
    m.insert("fileLabel", "Datei: ");
    m.insert("chosen", "Gewählt: ");
    m.insert("working", "Verarbeite…");
    m.insert("targetDir", "Zielordner für ");
    m.insert("errNoTarget", "❌ Kein Zielordner gewählt.");
    m.insert("errPkgbuild", "❌ Konnte PKGBUILD nicht schreiben: ");
    m.insert("buildTitle", "Paket bauen für ");
    m.insert("buildAsk", "Wie soll das Paket erstellt werden?");
    m.insert("buildOnly", "Nur Paket");
    m.insert("buildSrc", "Paket + Quellen");
    m.insert("buildFor", "Konvertierung");
    m.insert("mapped", "Gemappte Libs");
    m.insert("unknown", "Nicht gemappt / manuell prüfen");
    m.insert("noMapped", "keine gemappt");
    m.insert("allOk", "✅ alle aufgelöst");
    m.insert("extraDeps", "📦 Zusatz-Pakete: ");
    m.insert("extraDepsNote", "   Diese werden zusätzlich benötigt.");
    m.insert("notSatisfiable", "⚠ Abhängigkeiten NICHT aus Arch-Repos auflösbar: ");
    m.insert("notSatisfiableNote", "   Bitte manuell prüfen.");
    m.insert("pkgbuildLabel", "PKGBUILD: ");
    m.insert("msgPkgBuilt", "✅ Paket gebaut:\n");
    m.insert("msgBuildFail", "❌ Build fehlgeschlagen.");
    m.insert("msgPkgbuildDone", "✅ PKGBUILD erstellt.");
    m.insert("cleanup", "🧹 Nur Paket: Arbeitsdateien entfernt.");
    m.insert("depsInstalled", "✅ Abhängigkeiten installiert: ");
    m.insert("depsFailed", "❌ Abhängigkeiten FEHLGESCHLAGEN: ");
    m.insert("warnIntroTitle", "Hinweis zum Umbau");
    m.insert("warnIntro", "Der automatische Umbau kann fehlschlagen – z.B. bei unvollständigen Abhängigkeiten, "
        "fehlenden Skripten oder nicht erkannten Systemunterschieden.");
    m.insert("warnContinue", "Trotzdem fortfahren?");
    m.insert("msgBuildAborted", "❌ Build abgebrochen.");
    m.insert("msgInstalled", "✅ installiert: ");
    m.insert("msgInstallFail", "❌ Installation fehlgeschlagen.");
    m.insert("msgInstallPartial", "⚠️ teilweise installiert: ");
    m.insert("msgInstAborted", "❌ Installation abgebrochen.");
    m.insert("msgInstAbortedPw", "❌ Installation abgebrochen (kein Passwort).");
    m.insert("hintInstallTitle", "Hinweis zur Installation");
    m.insert("hintInstallBody", "Manche Programme brauchen zusätzlich separat gelieferte "
        "Daten/Lokalisierung (z.B. ein *-data- oder *-common-Paket), die im "
        "ausgewählten Paket nicht enthalten sind.\n\n"
        "Falls das Programm beim Start über fehlende Dateien meckert, prüfe ob ein "
        "solches Zusatzpaket fehlt und konvertiere es ebenfalls.");
    m.insert("confirmInstallTitle", "Wirklich installieren?");
    m.insert("confirmInstallBody", "Möchten Sie wirklich installieren:\n\n");
    m.insert("sudoInstall", "Passwort für sudo");
    m.insert("sudoInstallBody", "Passwort für sudo (Installation von ");
    m.insert("msgRmAborted", "❌ Deinstallation abgebrochen.");
    m.insert("msgRmAbortedPw", "❌ Deinstallation abgebrochen (kein Passwort).");
    m.insert("confirmUninstallTitle", "Wirklich deinstallieren?");
    m.insert("confirmUninstallBody", "Möchten Sie wirklich deinstallieren:\n\n");
    m.insert("sudoUninstall", "Passwort für sudo");
    m.insert("sudoUninstallBody", "Passwort für sudo (Deinstallation von ");
    m.insert("msgUninstallDone", "✅ deinstalliert: ");
    m.insert("msgUninstallFail", "❌ Deinstallation fehlgeschlagen.");
    m.insert("msgUninstallPartial", "⚠️ teilweise deinstalliert: ");
    m.insert("msgNoPkgToRemove", "❌ Kein Paket zum Deinstallieren ausgewählt.");
    m.insert("msgChooseFirst", "❌ Bitte zuerst ein Paket in der Liste auswählen.");
    m.insert("linkCopyError", "Fehler beim Kopieren/Verknüpfen: ");
    m.insert("brandFallback", "created by SattNEK");
    m.insert("noRepoDeps", "(Keine Repo-Abhängigkeiten zu installieren – wurde das Paket mit "
        "der AKTUELLEN Programmversion gebaut?)");
    m.insert("warnNoBinary", "❌ Kein ausführbares Paket gefunden.");
    return m;
}
