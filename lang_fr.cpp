// lang_fr.cpp — Uebersetzungen fuer pkg_convert (Sprache: fr)
#include <QString>
#include <QMap>

QMap<QString, QString> lang_fr() {
    QMap<QString, QString> m;
    m.insert("title", "Convertisseur de Paquets");
    m.insert("subtitle", "Convertit les paquets Debian (.deb) / RedHat (.rpm) vers ArchLinux");
    m.insert("dropHint", "Glissez le fichier ici (.deb/.rpm) ou cliquez sur 'Parcourir'");
    m.insert("langLabel", "Langue:");
    m.insert("browse", "Parcourir");
    m.insert("noFile", "Aucun fichier selectionne.");
    m.insert("deps", "Dependances");
    m.insert("build", "Construire le paquet");
    m.insert("install", "Installer le paquet");
    m.insert("installed", "Paquets installes (selectionnez pour desinstaller)");
    m.insert("uninstall", "Desinstaller le paquet selectionne");
    m.insert("themeLight", "Clair");
    m.insert("themeDark", "Sombre");
    m.insert("choosePkg", "Choisir le paquet");
    m.insert("pkgsFilter", "Paquets (*.deb *.rpm)");
    m.insert("errNoDebRpm", "❌ Veuillez selectionner un fichier .deb ou .rpm.");
    m.insert("errNoBuiltPkg", "❌ Aucun paquet construit pour l'instant.");
    m.insert("fileLabel", "Fichier : ");
    m.insert("chosen", "Choisi : ");
    m.insert("working", "Traitement…");
    m.insert("targetDir", "Dossier cible pour ");
    m.insert("errNoTarget", "❌ Aucun dossier cible selectionne.");
    m.insert("errPkgbuild", "❌ Impossible d'ecrire le PKGBUILD : ");
    m.insert("buildTitle", "Construire le paquet pour ");
    m.insert("buildAsk", "Comment ce paquet doit-il etre construit ?");
    m.insert("buildOnly", "Paquet uniquement");
    m.insert("buildSrc", "Paquet + sources");
    m.insert("buildFor", "Conversion");
    m.insert("mapped", "Libs mappe es");
    m.insert("unknown", "Non mappees / verifier manuellement");
    m.insert("noMapped", "aucune mappee");
    m.insert("allOk", "✅ toutes resolues");
    m.insert("extraDeps", "📦 Paquets supplementaires : ");
    m.insert("extraDepsNote", "   Necessaires en supplement.");
    m.insert("notSatisfiable", "⚠ Dependances NON SATISFAISABLES depuis les depots Arch : ");
    m.insert("notSatisfiableNote", "   Veuillez verifier manuellement.");
    m.insert("pkgbuildLabel", "PKGBUILD : ");
    m.insert("msgPkgBuilt", "✅ Paquet construit :\n");
    m.insert("msgBuildFail", "❌ Echec de la construction.");
    m.insert("msgPkgbuildDone", "✅ PKGBUILD cree.");
    m.insert("cleanup", "🧹 Paquet uniquement : fichiers de travail supprimes.");
    m.insert("depsInstalled", "✅ Dependances installees : ");
    m.insert("depsFailed", "❌ Dependances EN ECHEC : ");
    m.insert("warnIntroTitle", "Avis de conversion");
    m.insert("warnIntro", "La conversion automatique peut echouer : par exemple si des dependances sont incompletes, "
        "des scripts manquent ou des differences systeme ne sont pas reconnues.");
    m.insert("warnContinue", "Continuer quand meme ?");
    m.insert("msgBuildAborted", "❌ Construction annulee.");
    m.insert("msgInstalled", "✅ installe : ");
    m.insert("msgInstallFail", "❌ Echec de l'installation.");
    m.insert("msgInstallPartial", "⚠️ partiellement installe : ");
    m.insert("msgInstAborted", "❌ Installation annulee.");
    m.insert("msgInstAbortedPw", "❌ Installation annulee (pas de mot de passe).");
    m.insert("hintInstallTitle", "Conseil d'installation");
    m.insert("hintInstallBody", "Certains programmes ont besoin de donnees/localisation supplémentaires "
        "(ex. un paquet *-data ou *-common) non inclus dans le paquet selectionne.\n\n"
        "Si le programme se plaint de fichiers manquants au démarrage, vérifiez si un "
        "tel paquet complementaire est necessaire et convertissez-le egalement.");
    m.insert("confirmInstallTitle", "Vraiment installer ?");
    m.insert("confirmInstallBody", "Voulez-vous vraiment installer :\n\n");
    m.insert("sudoInstall", "Mot de passe sudo");
    m.insert("sudoInstallBody", "Mot de passe sudo (installer ");
    m.insert("msgRmAborted", "❌ Desinstallation annulee.");
    m.insert("msgRmAbortedPw", "❌ Desinstallation annulee (pas de mot de passe).");
    m.insert("confirmUninstallTitle", "Vraiment desinstaller ?");
    m.insert("confirmUninstallBody", "Voulez-vous vraiment desinstaller :\n\n");
    m.insert("sudoUninstall", "Mot de passe sudo");
    m.insert("sudoUninstallBody", "Mot de passe sudo (desinstaller ");
    m.insert("msgUninstallDone", "✅ desinstalle : ");
    m.insert("msgUninstallFail", "❌ Echec de la desinstallation.");
    m.insert("msgUninstallPartial", "⚠️ partiellement desinstalle : ");
    m.insert("msgNoPkgToRemove", "❌ Aucun paquet selectionne pour la suppression.");
    m.insert("msgChooseFirst", "❌ Veuillez selectionner un paquet dans la liste d'abord.");
    m.insert("linkCopyError", "Erreur de copier/lier : ");
    m.insert("brandFallback", "created by SattNEK");
    m.insert("noRepoDeps", "(Aucune dependance de depot a installer – le paquet a-t-il ete construit "
        "avec la VERSION ACTUELLE du programme ?)");
    m.insert("warnIntroTitle", "Avis de conversion");
    m.insert("warnIntro", "La conversion automatique peut echouer : par exemple si des dependances sont incompletes, "
        "des scripts manquent ou des differences systeme ne sont pas reconnues.");
    m.insert("warnContinue", "Continuer quand meme ?");
    m.insert("msgBuildAborted", "❌ Construction annulee.");
    
    m.insert("warnNoBinary", "❌ Aucun paquet executable.");
return m;
}
