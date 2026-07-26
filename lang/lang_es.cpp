// lang_es.cpp — Uebersetzungen fuer pkg_convert (Sprache: es)
#include <QMap>
#include <QString>

QMap<QString, QString> lang_es() {
    return QMap<QString, QString> {
                {"title", "Paket Converter"},
                {"subtitle", "Convierte Debian (.deb) / RedHat (.rpm) a ArchLinux"},
                {"dropHint", "Arrastra un archivo aquí (.deb / .rpm)  o  haz clic en 'Examinar'"},
                {"browse", "Examinar"},
                {"choosePkg", "Elegir paquete"},
                {"pkgsFilter", "Paquetes (*.deb *.rpm)"},
                {"noFile", "Ningún archivo seleccionado."},
                {"deps", "Dependencias"},
                {"build", "Construir paquete"},
                {"install", "Instalar paquete"},
                {"installed", "Paquetes instalados (selecciona para desinstalar)"},
                {"uninstall", "Desinstalar paquete seleccionado"},
                {"themeDark", "🌙 Oscuro"},
                {"themeLight", "☀ Claro"},
                {"langLabel", "Idioma :"},
                {"warnNoBinary", "⚠ Este paquete NO contiene programa ejecutable (solo datos/"
                    "bibliotecas). Para ejecutarlo también necesitas el paquete del programa real "
                    "(p.ej. circuslinux, no circuslinux-data) !\n\n"},
                {"hintInstallTitle", "Nota de instalación"},
                {"hintInstallBody", "Algunos programas necesitan datos/localización proporcionados "
                    "por separado (p.ej. un paquete *-data o *-common) no incluidos en el paquete "
                    "seleccionado.\n\n"
                    "Si el programa se queja de archivos faltantes al iniciar, comprueba si falta "
                    "tal paquete adicional y conviértelo también."},
                {"confirmInstallTitle", "Confirmar instalación"},
                {"confirmInstallBody", "¿Realmente quieres instalar :\n\n"},
                {"confirmUninstallTitle", "Confirmar desinstalación"},
                {"confirmUninstallBody", "¿Realmente quieres desinstalar :\n\n"},
                {"sudoInstall", "Contraseña de root"},
                {"sudoInstallBody", "Contraseña para sudo (instalando "},
                {"sudoUninstall", "Contraseña de root"},
                {"sudoUninstallBody", "Contraseña para sudo (desinstalando "},
                {"buildTitle", "Construcción para "},
                {"buildAsk", "¿Cómo construir el paquete ?"},
                {"buildOnly", "Solo paquete"},
                {"buildSrc", "Paquete + Fuentes"},
                {"targetDir", "Carpeta destino para "},
                {"errNoBuiltPkg", "❌ Ningún paquete construido para instalar."},
                {"errNoDebRpm", "❌ Solo se admiten .deb o .rpm."},
                {"errNoTarget", "❌ Cancelado – ninguna carpeta destino elegida."},
                {"errPkgbuild", "❌ No se puede escribir el PKGBUILD : "},
                {"msgBuildFail", "❌ Fallo al construir."},
                {"msgPkgbuildDone", "✅ PKGBUILD creado."},
                {"msgPkgBuilt", "✅ Paquete construido."},
                {"msgInstalled", "✅ Paquete instalado : "},
                {"msgInstallFail", "❌ Fallo de instalación :"},
                {"msgInstallPartial", "⚠ Instalación incompleta – comprueba (¿está "},
                {"msgUninstallDone", "✅ Paquete desinstalado : "},
                {"msgUninstallFail", "❌ Fallo al desinstalar :\n"},
                {"msgUninstallPartial", "⚠ Desinstalación quizá cancelada – comprueba (¿está "},
                {"msgNoPkgToRemove", "❌ Ningún paquete conocido para desinstalar."},
                {"msgRmAborted", "❌ Desinstalación cancelada."},
                {"msgRmAbortedPw", "❌ Desinstalación cancelada (sin contraseña)."},
                {"msgInstAborted", "❌ Instalación cancelada."},
                {"msgInstAbortedPw", "❌ Instalación cancelada (sin contraseña)."},
                {"msgChooseFirst", "❌ Por favor, selecciona primero un paquete de la lista."},
                {"mapped", "Mapeado"},
                {"unknown", "Desconocido"},
                {"allOk", "— (¡todo ok !)"},
                {"noMapped", "— ninguno mapeado"},
                {"extraDeps", "📦 Convertir también (dependencias Debian/RPM) : "},
                {"extraDepsNote", "   Estos paquetes son referenciados por el programa (datos/"
                    "localización). Sin ellos, faltarán archivos al iniciar.\n\n"},
                {"notSatisfiable", "⚠ NO SATISFACIBLE desde los repos de Arch (falta versión exacta de biblioteca) : "},
                {"notSatisfiableNote", "   ¡Este programa NO funcionará así !\n\n"},
                {"noRepoDeps", "(Ninguna dependencia de repositorio que instalar – ¿el paquete fue "
                    "construido con la VERSIÓN ACTUAL del programa ?)"},
                {"chosen", "Elegido : "},
                {"fileLabel", "Archivo : "},
                {"working", "Procesando…"},
                {"cleanup", "🧹 Solo paquete : archivos de trabajo (pkg/, src/, PKGBUILD) eliminados – "
                    "paquetes existentes conservados.\n"},
                {"pkgbuildLabel", "PKGBUILD : "},
                {"depsInstalled", "✅ Dependencias instaladas : "},
                {"depsFailed", "❌ Dependencias FALLIDAS : "},
    };
}
