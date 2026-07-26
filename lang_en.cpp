// lang_en.cpp — Uebersetzungen fuer pkg_convert (Sprache: en)
#include <QMap>
#include <QString>

QMap<QString, QString> lang_en() {
    return QMap<QString, QString> {
                {"title", "Paket Converter"},
                {"subtitle", "Converts Debian (.deb) / RedHat (.rpm) to ArchLinux"},
                {"dropHint", "Drag file here (.deb / .rpm)  or  click 'Browse'"},
                {"browse", "Browse"},
                {"choosePkg", "Choose package"},
                {"pkgsFilter", "Packages (*.deb *.rpm)"},
                {"noFile", "No file selected."},
                {"deps", "Dependencies"},
                {"build", "Build package"},
                {"install", "Install package"},
                {"installed", "Installed packages (select to uninstall)"},
                {"uninstall", "Uninstall selected package"},
                {"themeDark", "🌙 Dark"},
                {"themeLight", "☀ Light"},
                {"langLabel", "Language:"},
                {"warnNoBinary", "⚠ This package contains NO executable program (only data/"
                    "libraries). To run it you also need the actual program package "
                    "(e.g. circuslinux, not circuslinux-data)!\n\n"},
                {"hintInstallTitle", "Installation note"},
                {"hintInstallBody", "Some programs need separately provided data/localization "
                    "(e.g. a *-data or *-common package) not included in the selected package.\n\n"
                    "If the program complains about missing files at startup, check whether "
                    "such an add-on package is missing and convert it too."},
                {"confirmInstallTitle", "Confirm installation"},
                {"confirmInstallBody", "Do you really want to install:\n\n"},
                {"confirmUninstallTitle", "Confirm uninstallation"},
                {"confirmUninstallBody", "Do you really want to uninstall:\n\n"},
                {"sudoInstall", "Root password"},
                {"sudoInstallBody", "Password for sudo (installing "},
                {"sudoUninstall", "Root password"},
                {"sudoUninstallBody", "Password for sudo (uninstalling "},
                {"buildTitle", "Build for "},
                {"buildAsk", "How should the package be built?"},
                {"buildOnly", "Package only"},
                {"buildSrc", "Package + Sources"},
                {"targetDir", "Target folder for "},
                {"errNoBuiltPkg", "❌ No built package available to install."},
                {"errNoDebRpm", "❌ Only .deb or .rpm are supported."},
                {"errNoTarget", "❌ Aborted – no target folder chosen."},
                {"errPkgbuild", "❌ Cannot write PKGBUILD: "},
                {"msgBuildFail", "❌ Build failed."},
                {"msgPkgbuildDone", "✅ PKGBUILD created."},
                {"msgPkgBuilt", "✅ Package built."},
                {"msgInstalled", "✅ Package installed: "},
                {"msgInstallFail", "❌ Installation failed:"},
                {"msgInstallPartial", "⚠ Installation incomplete – please check (is "},
                {"msgUninstallDone", "✅ Package uninstalled: "},
                {"msgUninstallFail", "❌ Uninstallation failed:\n"},
                {"msgUninstallPartial", "⚠ Uninstallation possibly aborted – please check (is "},
                {"msgNoPkgToRemove", "❌ No package known to uninstall."},
                {"msgRmAborted", "❌ Uninstallation aborted."},
                {"msgRmAbortedPw", "❌ Uninstallation aborted (no password)."},
                {"msgInstAborted", "❌ Installation aborted."},
                {"msgInstAbortedPw", "❌ Installation aborted (no password)."},
                {"msgChooseFirst", "❌ Please select a package from the list first."},
                {"mapped", "Mapped"},
                {"unknown", "Unknown"},
                {"allOk", "— (all ok!)"},
                {"noMapped", "— none mapped"},
                {"extraDeps", "📦 Also convert (Debian/RPM depends): "},
                {"extraDepsNote", "   These packages are referenced by the program (usually data/"
                    "localization). Without them, files may be missing at startup.\n\n"},
                {"notSatisfiable", "⚠ NOT SATISFIABLE from Arch repos (exact library version missing): "},
                {"notSatisfiableNote", "   This program will NOT run like this!\n\n"},
                {"noRepoDeps", "(No repo dependencies to install – was the package built with the "
                    "CURRENT program version?)"},
                {"chosen", "Selected: "},
                {"fileLabel", "File: "},
                {"working", "Processing…"},
                {"cleanup", "🧹 Package only: work files (pkg/, src/, PKGBUILD) removed – "
                    "existing packages kept.\n"},
                {"pkgbuildLabel", "PKGBUILD: "},
                {"depsInstalled", "✅ Dependencies installed: "},
                {"depsFailed", "❌ Dependencies FAILED: "},
    };
}
