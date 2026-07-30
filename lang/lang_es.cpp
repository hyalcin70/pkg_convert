// lang_es.cpp — Uebersetzungen fuer pkg_convert (Sprache: es)
#include <QString>
#include <QMap>

QMap<QString, QString> lang_es() {
    QMap<QString, QString> m;
    m.insert("title", "Convertidor de Paquetes");
    m.insert("subtitle", "Convierte paquetes Debian (.deb) / RedHat (.rpm) a ArchLinux");
    m.insert("dropHint", "Arrastra un archivo aqui (.deb/.rpm) o haz clic en 'Examinar'");
    m.insert("langLabel", "Idioma:");
    m.insert("browse", "Examinar");
    m.insert("noFile", "Ningun archivo seleccionado.");
    m.insert("deps", "Dependencias");
    m.insert("build", "Construir paquete");
    m.insert("install", "Instalar paquete");
    m.insert("installed", "Paquetes instalados (selecciona para desinstalar)");
    m.insert("uninstall", "Desinstalar paquete seleccionado");
    m.insert("themeLight", "Claro");
    m.insert("themeDark", "Oscuro");
    m.insert("choosePkg", "Elegir paquete");
    m.insert("pkgsFilter", "Paquetes (*.deb *.rpm)");
    m.insert("errNoDebRpm", "❌ Por favor selecciona un archivo .deb o .rpm.");
    m.insert("errNoBuiltPkg", "❌ Aun no se ha construido ningun paquete.");
    m.insert("fileLabel", "Archivo: ");
    m.insert("chosen", "Elegido: ");
    m.insert("working", "Procesando…");
    m.insert("targetDir", "Carpeta destino para ");
    m.insert("errNoTarget", "❌ No se selecciono carpeta destino.");
    m.insert("errPkgbuild", "❌ No se pudo escribir PKGBUILD: ");
    m.insert("buildTitle", "Construir paquete para ");
    m.insert("buildAsk", "Como deseas construir el paquete?");
    m.insert("buildOnly", "Solo paquete");
    m.insert("buildSrc", "Paquete + fuentes");
    m.insert("buildFor", "Conversion");
    m.insert("mapped", "Librerias mapeadas");
    m.insert("unknown", "No mapeadas / revisar manualmente");
    m.insert("noMapped", "ninguna mapeada");
    m.insert("allOk", "✅ todas resueltas");
    m.insert("extraDeps", "📦 Paquetes extra: ");
    m.insert("extraDepsNote", "   Se necesitan adicionalmente.");
    m.insert("notSatisfiable", "⚠ Dependencias NO SATISFACTORIAS desde los repos de Arch: ");
    m.insert("notSatisfiableNote", "   Por favor revisa manualmente.");
    m.insert("pkgbuildLabel", "PKGBUILD: ");
    m.insert("msgPkgBuilt", "✅ Paquete construido:\n");
    m.insert("msgBuildFail", "❌ Error en la construccion.");
    m.insert("msgPkgbuildDone", "✅ PKGBUILD creado.");
    m.insert("cleanup", "🧹 Solo paquete: archivos de trabajo eliminados.");
    m.insert("depsInstalled", "✅ Dependencias instaladas: ");
    m.insert("depsFailed", "❌ Dependencias FALLIDAS: ");
    m.insert("warnIntroTitle", "Aviso de conversion");
    m.insert("warnIntro", "La conversion automatica puede fallar: por ejemplo si faltan dependencias, "
        "faltan scripts o no se reconocen diferencias del sistema.");
    m.insert("warnContinue", "Continuar de todos modos?");
    m.insert("msgBuildAborted", "❌ Construccion cancelada.");
    m.insert("msgInstalled", "✅ instalado: ");
    m.insert("msgInstallFail", "❌ Error en la instalacion.");
    m.insert("msgInstallPartial", "⚠️ instalacion parcial: ");
    m.insert("msgInstAborted", "❌ Instalacion abortada.");
    m.insert("msgInstAbortedPw", "❌ Instalacion abortada (sin contrasena).");
    m.insert("hintInstallTitle", "Consejo de instalacion");
    m.insert("hintInstallBody", "Algunos programas necesitan datos/localizacion adicionales "
        "(por ejemplo, un paquete *-data o *-common) que no estan en el paquete seleccionado.\n\n"
        "Si el programa se queja de archivos faltantes al iniciar, comprueba si falta "
        "tal paquete adicional y conviertelo tambien.");
    m.insert("confirmInstallTitle", "Instalar realmente?");
    m.insert("confirmInstallBody", "Deseas realmente instalar:\n\n");
    m.insert("sudoInstall", "Contrasena para sudo");
    m.insert("sudoInstallBody", "Contrasena para sudo (instalar ");
    m.insert("msgRmAborted", "❌ Desinstalacion abortada.");
    m.insert("msgRmAbortedPw", "❌ Desinstalacion abortada (sin contrasena).");
    m.insert("confirmUninstallTitle", "Desinstalar realmente?");
    m.insert("confirmUninstallBody", "Deseas realmente desinstalar:\n\n");
    m.insert("sudoUninstall", "Contrasena para sudo");
    m.insert("sudoUninstallBody", "Contrasena para sudo (desinstalar ");
    m.insert("msgUninstallDone", "✅ desinstalado: ");
    m.insert("msgUninstallFail", "❌ Error al desinstalar.");
    m.insert("msgUninstallPartial", "⚠️ desinstalacion parcial: ");
    m.insert("msgNoPkgToRemove", "❌ No hay paquete seleccionado para eliminar.");
    m.insert("msgChooseFirst", "❌ Por favor selecciona un paquete de la lista primero.");
    m.insert("linkCopyError", "Error al copiar/enlazar: ");
    m.insert("brandFallback", "created by SattNEK");
    m.insert("noRepoDeps", "(Ninguna dependencia de repositorio que instalar – fue el paquete "
        "construido con la VERSION ACTUAL del programa?)");
    m.insert("warnIntroTitle", "Aviso de conversion");
    m.insert("warnIntro", "La conversion automatica puede fallar: por ejemplo si faltan dependencias, "
        "faltan scripts o no se reconocen diferencias del sistema.");
    m.insert("warnContinue", "Continuar de todos modos?");
    m.insert("msgBuildAborted", "❌ Construccion cancelada.");
    return m;
}
