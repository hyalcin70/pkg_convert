# Paket Converter

Un outil natif C++/Qt6 qui convertit les paquets `.deb` et `.rpm` en
paquets **Arch Linux** installables (`.pkg.tar.zst`) — avec détection
réelle des dépendances, installation automatique des bibliothèques
depuis les dépôts et un historique d'installation persistant.

> ⚠️ **Uniquement pour les distributions basées sur Arch.** Ce projet est
> exclusivement destiné aux distributions **basées sur Arch Linux**
> (Arch, Manjaro, EndeavourOS, …). Les demandes ou problèmes concernant
> d'autres distributions (Debian/Ubuntu, Fedora, openSUSE, …) ne seront
> **pas** traités — l'outil produit des paquets `.pkg.tar.zst`, qui ne
> fonctionnent que sur les systèmes basés sur Arch.

## Pourquoi ?

Certains programmes (jeux, outils spécialisés) ne sont disponibles
qu'en `.deb` (Debian/Ubuntu) ou `.rpm` (Fedora/openSUSE), pas dans
les dépôts Arch. Cet outil les convertit sans AUR — uniquement avec
les sources officielles d'Arch.

## Fonctionnalités

- **deb/rpm → Arch** : extrait, détecte les bibliothèques requises via
  `readelf` + `pkgfile` (soname exact, pas de tables devinées)
- **Installation auto** des dépendances via `pacman -S --asdeps`
- **Chemin binaire** : Les fichiers exécutables des programmes/jeux sont déplacés vers `/usr/bin/` pour qu'ils soient dans le `PATH` d'Arch.
- **Avertissement** pour les paquets de données purs (sans exécutable)
- **Popup d'indice** à l'installation si des paquets de données
  supplémentaires (`-data`, `-common`) manquent
- **Journal copiable**, historique d'installation persistant
- **Basculateur Clair/Sombre** (par défaut : clair)

## Pourquoi pkg_convert ?

pkg_convert suit une approche propre aux formats de paquets externes,
destinée aux utilisateurs qui veulent convertir directement sous Arch
sans dépendre d’outils AUR pour l’étape de conversion.

1. **Un outil pour les deux formats étrangers.** Au lieu de combiner
   plusieurs outils mono-format, pkg_convert gère **`.deb` et
   `.rpm`** depuis la même interface avec une structure de paquet
   cohérente.
2. **Base de données Arch locale plutôt que gros caches externes.** Il
   utilise `pkgfile` sur votre sync DB locale existante — pas de
   téléchargement géant, pas de service de mise à jour séparé.
3. **Dépendances par lookup de soname réel.** Les bibliothèques sont
   identifiées avec `readelf` + `pkgfile`, pas par des tables de noms
   fixes venant d’autres distributions.
4. **C++/Qt6 natif, sans interpréteur au runtime.** Un seul binaire
   natif, pas de Python/Bash nécessaire à l’exécution.
5. **Interface Qt6 intégrée** avec multilingue, clair/sombre,
   historique d’installation et journal copiable.
6. **PAS besoin d’helper AUR.** Build et test depuis le source avec
   `makepkg -si`.

### Limites honnêtes

- Pas encore de script `.INSTALL` pour le rafraîchissement automatique
  du cache d’icônes ; les icônes du menu peuvent nécessiter un
  `gtk-update-icon-cache` + `update-desktop-database` manuel.
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
3. **Installer le paquet** → saisir le mot de passe, terminé

## Notes

- Certains projets séparent jeux/programmes en programme + paquet
  `-data`. Si graphismes/son manquent, convertir aussi le paquet de
  données.
- Les bibliothèques présentes uniquement dans l'**AUR** ne peuvent pas
  être installées automatiquement — l'outil vous avertit.

## Dépendances

`qt6-base` (fournit `qmake6`), `pacman`, `file`, `binutils`, `cpio`,
`libarchive`
