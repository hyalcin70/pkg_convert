# Paket Converter

Un outil natif C++/Qt6 qui convertit les paquets `.deb` et `.rpm` en
paquets **Arch Linux** installables (`.pkg.tar.zst`) — avec détection
réelle des dépendances, installation automatique des bibliothèques
depuis les dépôts et un historique d'installation persistant.

## Pourquoi ?

Certains programmes (jeux, outils spécialisés) n'existent qu'en `.deb`
(Debian/Ubuntu) ou `.rpm` (Fedora/openSUSE), pas dans les dépôts Arch.
Cet outil les convertit sans AUR — uniquement avec les sources officielles d'Arch.

## Fonctionnalités

- **deb/rpm → Arch** : extrait, détecte les bibliothèques requises via
  `readelf` + `pkgfile` (soname exact, pas de tables devinées)
- **Installation auto** des dépendances de dépôt via `pacman -S --asdeps`
- **Chemin binaire** : `/usr/games/` est déplacé vers `/usr/bin/`
- **Avertissement** pour les paquets de données purs (sans programme exécutable)
- **Fenêtre d'info** à l'installation si des paquets de données
  supplémentaires (`-data`, `-common`) peuvent manquer
- **Journal copiable**, historique d'installation persistant
- **Bascule Clair/Sombre** (défaut : clair)

## Construction & installation (depuis les sources, sans AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Ensuite **Paket Converter** apparaît dans le menu KDE
(catégorie : Utilitaire / Gestion de paquets).

## Utilisation

1. **Parcourir** → choisissez un fichier `.deb` ou `.rpm`
2. **Construire le paquet** (ou « Paquet + Sources »)
3. **Installer le paquet** → saisissez le mot de passe, c'est fait

## Remarques

- Certains projets divisent les jeux en programme + paquet `-data`.
  Si graphismes/sons manquent après le lancement, convertissez aussi
  le paquet de données correspondant.
- Les bibliothèques qui n'existent que dans **AUR** (ex. `glc-lib`)
  ne peuvent pas être installées automatiquement — l'outil avertit.

## Dépendances

`qt6-base` (fournit `qmake6` pour construire), `pacman`, `file`, `binutils`, `cpio`, `libarchive`
