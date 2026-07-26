// lang_pt.cpp — Uebersetzungen fuer pkg_convert (Sprache: pt)
#include <QMap>
#include <QString>

QMap<QString, QString> lang_pt() {
    return QMap<QString, QString> {
                {"title", "Paket Converter"},
                {"subtitle", "Converte Debian (.deb) / RedHat (.rpm) / AppImage para ArchLinux"},
                {"dropHint", "Arraste um arquivo aqui (.deb / .rpm / .AppImage)  ou  clique em 'Procurar'"},
                {"browse", "Procurar"},
                {"choosePkg", "Escolher pacote"},
                {"pkgsFilter", "Pacotes (*.deb *.rpm *.AppImage)"},
                {"noFile", "Nenhum arquivo selecionado."},
                {"deps", "Dependências"},
                {"build", "Construir pacote"},
                {"install", "Instalar pacote"},
                {"installed", "Pacotes instalados (selecione para desinstalar)"},
                {"uninstall", "Desinstalar pacote selecionado"},
                {"themeDark", "🌙 Escuro"},
                {"themeLight", "☀ Claro"},
                {"langLabel", "Idioma :"},
                {"warnNoBinary", "⚠ Este pacote NÃO contém programa executável (apenas dados/"
                    "bibliotecas). Para executá-lo você também precisa do pacote do programa real "
                    "(ex. circuslinux, não circuslinux-data) !\n\n"},
                {"hintInstallTitle", "Nota de instalação"},
                {"hintInstallBody", "Alguns programas precisam de dados/localização fornecidos "
                    "separadamente (ex. um pacote *-data ou *-common) não incluídos no pacote "
                    "selecionado.\n\n"
                    "Se o programa reclamar de arquivos faltantes ao iniciar, verifique se falta "
                    "tal pacote adicional e converta-o também."},
                {"confirmInstallTitle", "Confirmar instalação"},
                {"confirmInstallBody", "Deseja realmente instalar :\n\n"},
                {"confirmUninstallTitle", "Confirmar desinstalação"},
                {"confirmUninstallBody", "Deseja realmente desinstalar :\n\n"},
                {"sudoInstall", "Senha de root"},
                {"sudoInstallBody", "Senha para sudo (instalando "},
                {"sudoUninstall", "Senha de root"},
                {"sudoUninstallBody", "Senha para sudo (desinstalando "},
                {"buildTitle", "Construir para "},
                {"buildAsk", "Como construir o pacote ?"},
                {"buildOnly", "Apenas pacote"},
                {"buildSrc", "Pacote + Fontes"},
                {"targetDir", "Pasta destino para "},
                {"errNoBuiltPkg", "❌ Nenhum pacote construído para instalar."},
                {"errNoDebRpm", "❌ Apenas .deb, .rpm ou .AppImage são suportados."},
                {"errNoTarget", "❌ Cancelado – nenhuma pasta destino escolhida."},
                {"errPkgbuild", "❌ Não é possível escrever o PKGBUILD : "},
                {"msgBuildFail", "❌ Falha ao construir."},
                {"msgPkgbuildDone", "✅ PKGBUILD criado."},
                {"msgPkgBuilt", "✅ Pacote construído."},
                {"msgInstalled", "✅ Pacote instalado : "},
                {"msgInstallFail", "❌ Falha na instalação :"},
                {"msgInstallPartial", "⚠ Instalação incompleta – verifique (está "},
                {"msgUninstallDone", "✅ Pacote desinstalado : "},
                {"msgUninstallFail", "❌ Falha ao desinstalar :\n"},
                {"msgUninstallPartial", "⚠ Desinstalação possivelmente cancelada – verifique (está "},
                {"msgNoPkgToRemove", "❌ Nenhum pacote conhecido para desinstalar."},
                {"msgRmAborted", "❌ Desinstalação cancelada."},
                {"msgRmAbortedPw", "❌ Desinstalação cancelada (sem senha)."},
                {"msgInstAborted", "❌ Instalação cancelada."},
                {"msgInstAbortedPw", "❌ Instalação cancelada (sem senha)."},
                {"msgChooseFirst", "❌ Por favor, selecione primeiro um pacote na lista."},
                {"mapped", "Mapeado"},
                {"unknown", "Desconhecido"},
                {"allOk", "— (tudo ok !)"},
                {"noMapped", "— nenhum mapeado"},
                {"extraDeps", "📦 Converter também (dependências Debian/RPM/AppImage) : "},
                {"extraDepsNote", "   Estes pacotes são referenciados pelo programa (geralmente dados/"
                    "localização). Sem eles, arquivos podem faltar ao iniciar.\n\n"},
                {"notSatisfiable", "⚠ NÃO SATISFATÍVEL dos repositórios Arch (versão exata de biblioteca ausente) : "},
                {"notSatisfiableNote", "   Este programa NÃO funcionará assim !\n\n"},
                {"noRepoDeps", "(Nenhuma dependência de repositório para instalar – o pacote foi "
                    "construído com a VERSÃO ATUAL do programa ?)"},
                {"chosen", "Escolhido : "},
                {"fileLabel", "Arquivo : "},
                {"working", "Processando…"},
                {"cleanup", "🧹 Apenas pacote : arquivos de trabalho (pkg/, src/, PKGBUILD) removidos – "
                    "pacotes existentes mantidos.\n"},
                {"pkgbuildLabel", "PKGBUILD : "},
                {"depsInstalled", "✅ Dependências instaladas : "},
                {"depsFailed", "❌ Dependências FALHARAM : "},
    };
}
