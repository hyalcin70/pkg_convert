// lang_de.cpp — Uebersetzungen fuer pkg_convert (Sprache: de)
#include <QMap>
#include <QString>

QMap<QString, QString> lang_de() {
    return QMap<QString, QString> {
                {"title", "Paket Converter"},
                {"subtitle", "Wandelt Debian (.deb) / RedHat (.rpm) zu ArchLinux um"},
                {"dropHint", "Datei hierher ziehen (.deb / .rpm)  oder  'Durchsuchen' klicken"},
                {"browse", "Durchsuchen"},
                {"choosePkg", "Paket wählen"},
                {"pkgsFilter", "Pakete (*.deb *.rpm)"},
                {"noFile", "Noch keine Datei ausgewählt."},
                {"deps", "Abhängigkeiten"},
                {"build", "Paket bauen"},
                {"install", "Paket installieren"},
                {"installed", "Installierte Pakete (zum Deinstallieren wählen)"},
                {"uninstall", "Ausgewähltes Paket deinstallieren"},
                {"themeDark", "🌙 Dunkel"},
                {"themeLight", "☀ Hell"},
                {"langLabel", "Sprache:"},
                {"warnNoBinary", "⚠ Dieses Paket enthält KEIN ausführbares Programm (nur Daten/"
                    "Bibliotheken). Zum Starten brauchst du zusätzlich das eigentliche "
                    "Programm-Paket (z.B. circuslinux, nicht circuslinux-data)!\n\n"},
                {"hintInstallTitle", "Hinweis zur Installation"},
                {"hintInstallBody", "Manche Programme brauchen zusätzlich separat gelieferte "
                    "Daten/Lokalisierung (z.B. ein *-data- oder *-common-Paket), die im "
                    "ausgewählten Paket nicht enthalten sind.\n\n"
                    "Falls das Programm beim Start über fehlende Dateien meckert, prüfe ob ein "
                    "solches Zusatzpaket fehlt und konvertiere es ebenfalls."},
                {"confirmInstallTitle", "Installation bestätigen"},
                {"confirmInstallBody", "Möchten Sie wirklich installieren:\n\n"},
                {"confirmUninstallTitle", "Deinstallation bestätigen"},
                {"confirmUninstallBody", "Möchten Sie wirklich deinstallieren:\n\n"},
                {"sudoInstall", "Root-Passwort"},
                {"sudoInstallBody", "Passwort für sudo (Installation von "},
                {"sudoUninstall", "Root-Passwort"},
                {"sudoUninstallBody", "Passwort für sudo (Deinstallation von "},
                {"buildTitle", "Build für "},
                {"buildAsk", "Wie soll das Paket gebaut werden?"},
                {"buildOnly", "Nur Paket"},
                {"buildSrc", "Paket + Quellen"},
                {"targetDir", "Zielordner für "},
                {"errNoBuiltPkg", "❌ Kein gebautes Paket zum Installieren vorhanden."},
                {"errNoDebRpm", "❌ Nur .deb oder .rpm werden unterstützt."},
                {"errNoTarget", "❌ Abbruch – kein Zielordner gewählt."},
                {"errPkgbuild", "❌ Kann PKGBUILD nicht schreiben: "},
                {"msgBuildFail", "❌ Build fehlgeschlagen."},
                {"msgPkgbuildDone", "✅ PKGBUILD erzeugt."},
                {"msgPkgBuilt", "✅ Paket gebaut."},
                {"msgInstalled", "✅ Paket installiert: "},
                {"msgInstallFail", "❌ Installation fehlgeschlagen:"},
                {"msgInstallPartial", "⚠ Installation unvollständig – bitte prüfen (ist "},
                {"msgUninstallDone", "✅ Paket deinstalliert: "},
                {"msgUninstallFail", "❌ Deinstallation fehlgeschlagen:\n"},
                {"msgUninstallPartial", "⚠ Deinstallation evtl. abgebrochen – bitte prüfen (ist "},
                {"msgNoPkgToRemove", "❌ Kein Paket zum Deinstallieren bekannt."},
                {"msgRmAborted", "❌ Deinstallation abgebrochen."},
                {"msgRmAbortedPw", "❌ Deinstallation abgebrochen (kein Passwort)."},
                {"msgInstAborted", "❌ Installation abgebrochen."},
                {"msgInstAbortedPw", "❌ Installation abgebrochen (kein Passwort)."},
                {"msgChooseFirst", "❌ Bitte zuerst ein Paket in der Liste auswählen."},
                {"mapped", "Gemappt"},
                {"unknown", "Unbekannt"},
                {"allOk", "— (alle ok!)"},
                {"noMapped", "— keine gemappt"},
                {"extraDeps", "📦 Zusätzlich konvertieren (Debian/RPM-Depends): "},
                {"extraDepsNote", "   Diese Pakete werden vom Programm referenziert (meist Daten/"
                    "Lokalisierung). Ohne sie fehlen ggf. Dateien beim Start.\n\n"},
                {"notSatisfiable", "⚠ NICHT ERFÜLLBAR aus Arch-Repos (exakte Library-Version fehlt): "},
                {"notSatisfiableNote", "   Dieses Programm wird so NICHT starten!\n\n"},
                {"noRepoDeps", "(Keine Repo-Abhängigkeiten zu installieren – wurde das Paket mit "
                    "der AKTUELLEN Programmversion gebaut?)"},
                {"chosen", "Gewählt: "},
                {"fileLabel", "Datei: "},
                {"working", "Verarbeite…"},
                {"cleanup", "🧹 Nur Paket: Arbeitsdateien (pkg/, src/, PKGBUILD) entfernt – "
                    "bestehende Pakete blieben erhalten.\n"},
                {"pkgbuildLabel", "PKGBUILD: "},
                {"depsInstalled", "✅ Abhängigkeiten installiert: "},
                {"depsFailed", "❌ Abhängigkeiten FEHLGESCHLAGEN: "},
    };
}
