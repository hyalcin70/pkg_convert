// lang_en.cpp — Uebersetzungen fuer pkg_convert (Sprache: en)
#include <QString>
#include <QMap>

QMap<QString, QString> lang_en() {
    QMap<QString, QString> m;
    m.insert("title", "Package Converter");
    m.insert("subtitle", "Convert Debian (.deb) / RedHat (.rpm) packages to ArchLinux");
    m.insert("dropHint", "Drag and drop (.deb/.rpm) here or click 'Browse'");
    m.insert("langLabel", "Language:");
    m.insert("browse", "Browse");
    m.insert("noFile", "No file selected.");
    m.insert("deps", "Dependencies");
    m.insert("build", "Build package");
    m.insert("install", "Install package");
    m.insert("installed", "Installed packages (select to uninstall)");
    m.insert("uninstall", "Uninstall selected package");
    m.insert("themeLight", "Light");
    m.insert("themeDark", "Dark");
    m.insert("choosePkg", "Choose package");
    m.insert("pkgsFilter", "Packages (*.deb *.rpm)");
    m.insert("errNoDebRpm", "❌ Please select a .deb or .rpm file.");
    m.insert("errNoBuiltPkg", "❌ No package has been built yet.");
    m.insert("fileLabel", "File: ");
    m.insert("chosen", "Chosen: ");
    m.insert("working", "Processing…");
    m.insert("targetDir", "Target folder for ");
    m.insert("errNoTarget", "❌ No target folder selected.");
    m.insert("errPkgbuild", "❌ Could not write PKGBUILD: ");
    m.insert("buildTitle", "Build package for ");
    m.insert("buildAsk", "How should the package be built?");
    m.insert("buildOnly", "Package only");
    m.insert("buildSrc", "Package + sources");
    m.insert("buildFor", "Conversion");
    m.insert("mapped", "Mapped libs");
    m.insert("unknown", "Not mapped / check manually");
    m.insert("noMapped", "none mapped");
    m.insert("allOk", "✅ all resolved");
    m.insert("extraDeps", "📦 Extra packages: ");
    m.insert("extraDepsNote", "   These are additionally required.");
    m.insert("notSatisfiable", "⚠ Dependencies NOT satisfiable from Arch repos: ");
    m.insert("notSatisfiableNote", "   Please check manually.");
    m.insert("pkgbuildLabel", "PKGBUILD: ");
    m.insert("msgPkgBuilt", "✅ Package built:\n");
    m.insert("msgBuildFail", "❌ Build failed.");
    m.insert("msgPkgbuildDone", "✅ PKGBUILD created.");
    m.insert("cleanup", "🧹 Package only: work files removed.");
    m.insert("depsInstalled", "✅ Dependencies installed: ");
    m.insert("depsFailed", "❌ Dependencies FAILED: ");
    m.insert("warnIntroTitle", "Conversion notice");
    m.insert("warnIntro", "Automatic conversion may fail – for example if dependencies are incomplete, "
        "scripts are missing, or system differences are not recognized.");
    m.insert("warnContinue", "Continue anyway?");
    m.insert("msgBuildAborted", "❌ Build aborted.");
    m.insert("msgInstalled", "✅ installed: ");
    m.insert("msgInstallFail", "❌ Installation failed.");
    m.insert("msgInstallPartial", "⚠️ partially installed: ");
    m.insert("msgInstAborted", "❌ Installation aborted.");
    m.insert("msgInstAbortedPw", "❌ Installation aborted (no password).");
    m.insert("hintInstallTitle", "Installation hint");
    m.insert("hintInstallBody", "Some programs need additional separately provided "
        "data/localization (e.g. a *-data or *-common package) not included in "
        "the selected package.\n\n"
        "If the program complains about missing files at startup, check whether "
        "such an additional package is needed and convert it as well.");
    m.insert("confirmInstallTitle", "Really install?");
    m.insert("confirmInstallBody", "Do you really want to install:\n\n");
    m.insert("sudoInstall", "Password for sudo");
    m.insert("sudoInstallBody", "Password for sudo (install ");
    m.insert("msgRmAborted", "❌ Uninstall aborted.");
    m.insert("msgRmAbortedPw", "❌ Uninstall aborted (no password).");
    m.insert("confirmUninstallTitle", "Really uninstall?");
    m.insert("confirmUninstallBody", "Do you really want to uninstall:\n\n");
    m.insert("sudoUninstall", "Password for sudo");
    m.insert("sudoUninstallBody", "Password for sudo (uninstall ");
    m.insert("msgUninstallDone", "✅ uninstalled: ");
    m.insert("msgUninstallFail", "❌ Uninstall failed.");
    m.insert("msgUninstallPartial", "⚠️ partially uninstalled: ");
    m.insert("msgNoPkgToRemove", "❌ No package selected for removal.");
    m.insert("msgChooseFirst", "❌ Please select a package from the list first.");
    m.insert("linkCopyError", "Error copying/linking: ");
    m.insert("brandFallback", "created by SattNEK");
    m.insert("noRepoDeps", "(No repo dependencies to install – was the package built with "
        "the CURRENT program version?)");
    m.insert("warnIntroTitle", "Conversion notice");
    m.insert("warnIntro", "Automatic conversion may fail – for example if dependencies are incomplete, "
        "scripts are missing, or system differences are not recognized.");
    m.insert("warnContinue", "Continue anyway?");
    m.insert("msgBuildAborted", "❌ Build aborted.");
    return m;
}
