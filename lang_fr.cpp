// lang_fr.cpp — Uebersetzungen fuer pkg_convert (Sprache: fr)
#include <QMap>
#include <QString>

QMap<QString, QString> lang_fr() {
    return QMap<QString, QString> {
                {"title", "Paket Converter"},
                {"subtitle", "Convertit Debian (.deb) / RedHat (.rpm) / AppImage en ArchLinux"},
                {"dropHint", "Glissez un fichier ici (.deb / .rpm / .AppImage)  ou  cliquez sur 'Parcourir'"},
                {"browse", "Parcourir"},
                {"choosePkg", "Choisir un paquet"},
                {"pkgsFilter", "Paquets (*.deb *.rpm *.AppImage)"},
                {"noFile", "Aucun fichier sélectionné."},
                {"deps", "Dépendances"},
                {"build", "Construire le paquet"},
                {"install", "Installer le paquet"},
                {"installed", "Paquets installés (sélectionnez pour désinstaller)"},
                {"uninstall", "Désinstaller le paquet sélectionné"},
                {"themeDark", "🌙 Sombre"},
                {"themeLight", "☀ Clair"},
                {"langLabel", "Langue :"},
                {"warnNoBinary", "⚠ Ce paquet ne contient AUCUN programme exécutable (uniquement des données/"
                    "bibliothèques). Pour le lancer, il vous faut aussi le paquet du programme réel "
                    "(ex. circuslinux, pas circuslinux-data) !\n\n"},
                {"hintInstallTitle", "Note d'installation"},
                {"hintInstallBody", "Certains programmes ont besoin de données/localisations fournies "
                    "séparément (ex. un paquet *-data ou *-common) non inclus dans le paquet sélectionné.\n\n"
                    "Si le programme se plaint de fichiers manquants au démarrage, vérifiez si un tel "
                    "paquet complémentaire manque et convertissez-le aussi."},
                {"confirmInstallTitle", "Confirmer l'installation"},
                {"confirmInstallBody", "Voulez-vous vraiment installer :\n\n"},
                {"confirmUninstallTitle", "Confirmer la désinstallation"},
                {"confirmUninstallBody", "Voulez-vous vraiment désinstaller :\n\n"},
                {"sudoInstall", "Mot de passe root"},
                {"sudoInstallBody", "Mot de passe pour sudo (installation de "},
                {"sudoUninstall", "Mot de passe root"},
                {"sudoUninstallBody", "Mot de passe pour sudo (désinstallation de "},
                {"buildTitle", "Construction pour "},
                {"buildAsk", "Comment construire le paquet ?"},
                {"buildOnly", "Paquet seul"},
                {"buildSrc", "Paquet + Sources"},
                {"targetDir", "Dossier cible pour "},
                {"errNoBuiltPkg", "❌ Aucun paquet construit à installer."},
                {"errNoDebRpm", "❌ Seuls .deb, .rpm ou .AppImage sont pris en charge."},
                {"errNoTarget", "❌ Annulé – aucun dossier cible choisi."},
                {"errPkgbuild", "❌ Impossible d'écrire le PKGBUILD : "},
                {"msgBuildFail", "❌ Échec de la construction."},
                {"msgPkgbuildDone", "✅ PKGBUILD créé."},
                {"msgPkgBuilt", "✅ Paquet construit."},
                {"msgInstalled", "✅ Paquet installé : "},
                {"msgInstallFail", "❌ Échec de l'installation :"},
                {"msgInstallPartial", "⚠ Installation incomplète – vérifiez (est-ce que "},
                {"msgUninstallDone", "✅ Paquet désinstallé : "},
                {"msgUninstallFail", "❌ Échec de la désinstallation :\n"},
                {"msgUninstallPartial", "⚠ Désinstallation peut-être annulée – vérifiez (est-ce que "},
                {"msgNoPkgToRemove", "❌ Aucun paquet à désinstaller."},
                {"msgRmAborted", "❌ Désinstallation annulée."},
                {"msgRmAbortedPw", "❌ Désinstallation annulée (aucun mot de passe)."},
                {"msgInstAborted", "❌ Installation annulée."},
                {"msgInstAbortedPw", "❌ Installation annulée (aucun mot de passe)."},
                {"msgChooseFirst", "❌ Veuillez d'abord sélectionner un paquet dans la liste."},
                {"mapped", "Associé"},
                {"unknown", "Inconnu"},
                {"allOk", "— (tout ok !)"},
                {"noMapped", "— aucun associé"},
                {"extraDeps", "📦 Convertir aussi (dépendances Debian/RPM/AppImage) : "},
                {"extraDepsNote", "   Ces paquets sont référencés par le programme (données/"
                    "localisation). Sans eux, des fichiers manqueront au démarrage.\n\n"},
                {"notSatisfiable", "⚠ NON SATISFAISABLE depuis les dépôts Arch (version exacte de bibliothèque manquante) : "},
                {"notSatisfiableNote", "   Ce programme NE fonctionnera PAS ainsi !\n\n"},
                {"noRepoDeps", "(Aucune dépendance de dépôt à installer – le paquet a-t-il été construit "
                    "avec la VERSION ACTUELLE du programme ?)"},
                {"chosen", "Choisi : "},
                {"fileLabel", "Fichier : "},
                {"working", "Traitement…"},
                {"cleanup", "🧹 Paquet seul : fichiers de travail (pkg/, src/, PKGBUILD) supprimés – "
                    "paquets existants conservés.\n"},
                {"pkgbuildLabel", "PKGBUILD : "},
                {"depsInstalled", "✅ Dépendances installées : "},
                {"depsFailed", "❌ Dépendances EN ÉCHEC : "},
    };
}
