// lang_pt.cpp — Uebersetzungen fuer pkg_convert (Sprache: pt)
#include <QString>
#include <QMap>

QMap<QString, QString> lang_pt() {
    QMap<QString, QString> m;
    m.insert("title", "Conversor de Pacotes");
    m.insert("subtitle", "Converte pacotes Debian (.deb) / RedHat (.rpm) para ArchLinux");
    m.insert("dropHint", "Arraste o arquivo aqui (.deb/.rpm) ou clique em 'Procurar'");
    m.insert("langLabel", "Idioma:");
    m.insert("browse", "Procurar");
    m.insert("noFile", "Nenhum arquivo selecionado.");
    m.insert("deps", "Dependencias");
    m.insert("build", "Construir pacote");
    m.insert("install", "Instalar pacote");
    m.insert("installed", "Pacotes instalados (selecione para desinstalar)");
    m.insert("uninstall", "Desinstalar pacote selecionado");
    m.insert("themeLight", "☀ Claro");
    m.insert("themeDark", "🌙 Escuro");
    m.insert("choosePkg", "Escolher pacote");
    m.insert("pkgsFilter", "Pacotes (*.deb *.rpm)");
    m.insert("errNoDebRpm", "❌ Selecione um arquivo .deb ou .rpm.");
    m.insert("errNoBuiltPkg", "❌ Nenhum pacote construido ainda.");
    m.insert("fileLabel", "Arquivo: ");
    m.insert("chosen", "Escolhido: ");
    m.insert("working", "Processando…");
    m.insert("targetDir", "Pasta de destino para ");
    m.insert("errNoTarget", "❌ Nenhuma pasta de destino selecionada.");
    m.insert("errPkgbuild", "❌ Nao foi possivel escrever PKGBUILD: ");
    m.insert("buildTitle", "Construir pacote para ");
    m.insert("buildAsk", "Como o pacote deve ser construido?");
    m.insert("buildOnly", "Apenas pacote");
    m.insert("buildSrc", "Pacote + fontes");
    m.insert("buildFor", "Conversao");
    m.insert("mapped", "Libs mapeadas");
    m.insert("unknown", "Nao mapeadas / verificar manualmente");
    m.insert("noMapped", "nenhuma mapeada");
    m.insert("allOk", "✅ todas resolvidas");
    m.insert("extraDeps", "📦 Pacotes extras: ");
    m.insert("extraDepsNote", "   Estes sao necessarios adicionalmente.");
    m.insert("notSatisfiable", "⚠ Dependencias NAO SATISFEITAS pelos repositorios Arch: ");
    m.insert("notSatisfiableNote", "   Por favor verifique manualmente.");
    m.insert("pkgbuildLabel", "PKGBUILD: ");
    m.insert("msgPkgBuilt", "✅ Pacote construido:\n");
    m.insert("msgBuildFail", "❌ Construcao falhou.");
    m.insert("msgPkgbuildDone", "✅ PKGBUILD criado.");
    m.insert("cleanup", "🧹 Apenas pacote: arquivos de trabalho removidos.");
    m.insert("depsInstalled", "✅ Dependencias instaladas: ");
    m.insert("depsFailed", "❌ Dependencias FALHARAM: ");
    m.insert("warnIntroTitle", "Aviso de conversao");
    m.insert("warnIntro", "A conversao automatica pode falhar: por exemplo se dependencias estiverem incompletas, "
        "faltarem scripts ou diferencas do sistema nao forem reconhecidas.");
    m.insert("warnContinue", "Continuar mesmo assim?");
    m.insert("msgBuildAborted", "❌ Construcao cancelada.");
    m.insert("msgInstalled", "✅ instalado: ");
    m.insert("msgInstallFail", "❌ Instalacao falhou.");
    m.insert("msgInstallPartial", "⚠️ instalado parcialmente: ");
    m.insert("msgInstAborted", "❌ Instalacao abortada.");
    m.insert("msgInstAbortedPw", "❌ Instalacao abortada (sem senha).");
    m.insert("hintInstallTitle", "Conselho de instalacao");
    m.insert("hintInstallBody", "Alguns programas precisam de dados/localizacao adicionais "
        "(por exemplo, um pacote *-data ou *-common) que nao estao no pacote selecionado.\n\n"
        "Se o programa reclamar de arquivos faltantes ao iniciar, verifique se tal "
        "pacote adicional e necessario e converta-o tambem.");
    m.insert("confirmInstallTitle", "Realmente instalar?");
    m.insert("confirmInstallBody", "Deseja realmente instalar:\n\n");
    m.insert("sudoInstall", "Senha para sudo");
    m.insert("sudoInstallBody", "Senha para sudo (instalar ");
    m.insert("msgRmAborted", "❌ Desinstalacao abortada.");
    m.insert("msgRmAbortedPw", "❌ Desinstalacao abortada (sem senha).");
    m.insert("confirmUninstallTitle", "Realmente desinstalar?");
    m.insert("confirmUninstallBody", "Deseja realmente desinstalar:\n\n");
    m.insert("sudoUninstall", "Senha para sudo");
    m.insert("sudoUninstallBody", "Senha para sudo (desinstalar ");
    m.insert("msgUninstallDone", "✅ desinstalado: ");
    m.insert("msgUninstallFail", "❌ Desinstalacao falhou.");
    m.insert("msgUninstallPartial", "⚠️ desinstalado parcialmente: ");
    m.insert("msgNoPkgToRemove", "❌ Nenhum pacote selecionado para remocao.");
    m.insert("msgChooseFirst", "❌ Selecione um pacote da lista primeiro.");
    m.insert("linkCopyError", "Erro ao copiar/ligar: ");
    m.insert("brandFallback", "created by SattNEK");
    m.insert("noRepoDeps", "(Nenhuma dependencia de repositorio para instalar – o pacote foi "
        "construido com a VERSAO ATUAL do programa?)");
    m.insert("warnNoBinary", "❌ Nenhum executavel encontrado.");
    return m;
}
