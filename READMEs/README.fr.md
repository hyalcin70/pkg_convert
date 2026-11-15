# Paket Converter

**Licence :** GPL-3.0 avec la clause Commons — usage non commercial libre ; tout usage commercial nécessite une autorisation préalable.

**Droit d'auteur :** © 2026 Hakan Yalçın. Tout usage en dehors de cette licence — notamment un usage commercial, la vente, la suppression des mentions de droit d'auteur ou de licence, ou le fait de se l'approprier — est strictement interdit. 

## Qu'est-ce que pkg_convert ?

**pkg_convert** signifie **Package Converter** (convertisseur de paquets) :
un outil natif C++/Qt6 qui convertit les paquets `.deb` et `.rpm` en
paquets **Arch Linux** installables (`.pkg.tar.zst`) — avec détection
réelle des dépendances, installation automatique des bibliothèques depuis
les dépôts et un historique d'installation persistant.

> ⚠️ **Uniquement pour les distributions basées sur Arch.** Ce projet est
> exclusivement destiné aux distributions **basées sur Arch Linux**
> (Arch, Manjaro, EndeavourOS, …). Les demandes ou problèmes concernant
> d'autres distributions (Debian/Ubuntu, Fedora, openSUSE, …) ne seront
> **pas** traités — l'outil produit des paquets `.pkg.tar.zst`, qui ne
> fonctionnent que sur les systèmes basés sur Arch.

## 🆕 Nouveautés (1.0.0-13)

- **Correctif** : le chargement d'un nouveau fichier vide désormais immédiatement la liste de résultats/dépendances (au lieu d'afficher d'anciennes entrées).

- **Intégration bureau et stabilité** : les liens symboliques sont conservés dans les paquets, les logos apparaissent directement dans le menu (automatisme des icônes), le cache du menu est rafraîchi après l'installation, vérification en faux root plus robuste, libellés de thème allemands corrigés.

- **Révision de la traduction turque** : tous les textes utilisent désormais les caractères turcs corrects (ğ ü ö ç ş ı İ).

- **Vérification en faux root après la construction** : le paquet terminé est éventuellement installé dans un faux root temporaire (case à cocher) ; l'enregistrement et la liste des fichiers sont vérifiés automatiquement.

- Les métadonnées `Depends`/`Requires` étrangères sont désormais évaluées
  en plus du scan readelf NEEDED — les bibliothèques chargées par
  dlopen (X11, Wayland, Vulkan) deviennent de vraies dépendances.
- Sélection du fournisseur par score de nom (sous-chaîne +
  correspondance de jetons, dépôts officiels d'abord) : plus de
  dépendances erronées comme `nsight-compute` à la place de `qt6-base`.
- `.PKGINFO` ne contient que de vrais paquets Arch → `pacman -U`
  fonctionne de façon fiable.
- Détection des bibliothèques fournies corrigée : les paquets autonomes
  ne listent plus leurs propres libs comme dépendances.
- Installation/désinstallation via `pkexec` (boîte de dialogue Polkit) ;
  nouvelles dépendances runtime : `pkgfile`, `polkit`.

## Pourquoi ?

Certains programmes (jeux, outils spécialisés) ne sont disponibles
qu'en `.deb` (Debian/Ubuntu) ou `.rpm` (Fedora/openSUSE), pas dans
les dépôts Arch. Cet outil les convertit sans AUR — uniquement avec
les sources officielles d'Arch.

## Fonctionnalités

- **deb/rpm → Arch** : extrait, détecte les bibliothèques requises via
  `readelf` + `pkgfile` (soname exact, pas de tables devinées)
  et évalue les métadonnées `Depends`/`Requires` étrangères (les
  bibliothèques chargées par dlopen, comme X11, Wayland ou Vulkan,
  sont aussi détectées)
- **Installation auto** des dépendances via `pacman -S --asdeps`
- **Meilleur fournisseur :** Si plusieurs paquets fournissent la même
  bibliothèque, un score de nom (sous-chaîne + correspondance de jetons,
  dépôts officiels d'abord) évite de choisir un pack arbitraire
- **Chemin binaire** : Les fichiers exécutables des programmes/jeux sont déplacés vers `/usr/bin/` pour qu'ils soient dans le `PATH` d'Arch.
- **Avertissement** pour les paquets de données purs (sans exécutable)
- **Popup d'indice** à l'installation si des paquets de données
  supplémentaires (`-data`, `-common`) manquent
- **Journal copiable**, historique d'installation persistant
- **Basculateur Clair/Sombre** (par défaut : clair)

- **Vérification en faux root** : après la construction, le paquet est éventuellement installé dans un faux root temporaire pour vérifier l'enregistrement et la liste des fichiers (case à cocher).

- **Vérification en faux root** : après la construction, le paquet est éventuellement installé dans un faux root temporaire pour vérifier l'enregistrement et la liste des fichiers (case à cocher).

## Conception

- **Deux formats externes :** `.deb` et `.rpm` sont pris en charge
  dans la même interface.
- **Résolution Arch :** Les bibliothèques sont résolues via `readelf`
  + `pkgfile` contre votre sync DB locale, plus les métadonnées
  `Depends`/`Requires` étrangères.
- **Binaires natifs :** Les exécutables sont placés sous `/usr/bin/`
  pour le `PATH` d'Arch ; données et fichiers desktop restent
  inchangés.
- **Interaction avec les dépôts depuis l'interface :** Les dépendances
  peuvent être installées automatiquement via `pacman -S --asdeps` ;
  installation/désinstallation sont disponibles dans l'interface.
- **Pas d'interpréteur au runtime :** Un seul binaire natif, sans
  Python/Bash nécessaire à l'exécution.
- **Multilingue :** allemand, anglais, français, espagnol, turc,
  portugais ; clair/sombre ; historique d'installation ; journal
  copiable.
- **Pas d'helper AUR nécessaire :** Build et test depuis le source
  avec `makepkg -si`.

### Limites honnêtes

- Toujours pas de script `.INSTALL` : les caches d'icônes et de bureau
  ne sont pas rafraîchis automatiquement ; une application convertie peut
  n'apparaître dans le menu qu'après `gtk-update-icon-cache` +
  `update-desktop-database` et/ou un rafraîchissement du menu KDE
  (`kbuildsycoca6 --noincremental` ou reconnexion).
- Les noms de paquets étrangers sans entrée dans la table de
  correspondance sont signalés comme non mappés au lieu d'être devinés.
- `makepkg` strip les binaires par défaut ; fonctionnellement identique
  à une copie 1:1 d’autres outils, seulement plus petit.
- `pkgname` porte un suffixe de version, ex. `program-1.99.16`.
- `pkgfile` repose sur une sync DB locale à jour ; lancer `pacman -Sy`
  si les correspondances semblent obsolètes.

## Construction & installation (depuis les sources, sans AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Ensuite **Paket Converter** apparaît dans le menu KDE
(catégorie : Utilitaire / Gestion de paquets).

## Utilisation

1. **Parcourir** → sélectionner un fichier `.deb` ou `.rpm`
2. **Construire le paquet** (ou « Paquet + Sources »)
3. **Installer le paquet** → confirmer la boîte de dialogue Polkit, terminé

## Notes

- Certains projets séparent jeux/programmes en programme + paquet
  `-data`. Si graphismes/son manquent, convertir aussi le paquet de
  données.
- Les bibliothèques présentes uniquement dans l'**AUR** ne peuvent pas
  être installées automatiquement — l'outil vous avertit.

## Dépendances

`qt6-base` (fournit `qmake6`), `pacman`, `file`, `binutils`, `cpio`,
`libarchive`, `pkgfile`, `polkit`

![SattNEK Logo](../created_by_sattnek.png)
