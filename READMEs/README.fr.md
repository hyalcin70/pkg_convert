# Paket Converter

Un outil natif C++/Qt6 qui convertit les paquets `.deb`, `.rpm` et `.AppImage` en
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
qu'en `.deb` (Debian/Ubuntu), `.rpm` (Fedora/openSUSE) ou `.AppImage`, pas dans
les dépôts Arch. Cet outil les convertit sans AUR — uniquement avec
les sources officielles d'Arch.

## Fonctionnalités

- **deb/rpm/AppImage → Arch** : extrait, détecte les bibliothèques requises via
  `readelf` + `pkgfile` (soname exact, pas de tables devinées)
- **AppImage utilise les bibliothèques système** : les bibliothèques
  fournies intégrées que Arch livre déjà sont retirées du paquet, ainsi
  le programme utilise les **bibliothèques système à jour** (avec mises
  à jour automatiques) au lieu de bibliothèques intégrées obsolètes.
  Seules les bibliothèques sans paquet Arch restent en repli.
- **Installation auto** des dépendances via `pacman -S --asdeps`
- **Chemin binaire** : `/usr/games/` est déplacé vers `/usr/bin/`
- **Avertissement** pour les paquets de données purs (sans exécutable)
- **Popup d'indice** à l'installation si des paquets de données
  supplémentaires (`-data`, `-common`) manquent
- **Journal copiable**, historique d'installation persistant
- **Basculateur Clair/Sombre** (par défaut : clair)

## Pourquoi pkg_convert plutôt que debtap / rpmtoarch ?

Il existe d'autres convertisseurs (debtap, rpmtoarch). Voici pourquoi
pkg_convert convient mieux à la plupart des utilisateurs :

1. **Un outil pour les trois formats.** `debtap` ne gère que `.deb`
   (échec brutal sur `.rpm` : *"not a valid deb package"*), tandis que
   `rpmtoarch` ne gère que `.rpm`. pkg_convert gère **les trois**
   (`.deb`, `.rpm`, `.AppImage`) depuis la même interface avec des
   résultats identiques (vérifié : même empreinte binaire, même taille
   pour deb/rpm).
2. **Pas de base de données de 1,1 Go.** `debtap` télécharge une liste
   de paquets Debian/Ubuntu (≈1,1 Go de cache, avec root). pkg_convert
   utilise `pkgfile`, qui interroge votre base **locale** Arch — pas de
   gros téléchargement, pas d'étape de mise à jour séparée.
3. **Détection des dépendances plus complète.** Lors de tests avec
   différents programmes fournis à la fois en `.deb`, `.rpm` ou `.AppImage`,
   pkg_convert a résolu **11** bibliothèques
   (gtk3, webkit2gtk-4.1, cairo, pango, glib2, libsoup, zlib, glibc,
   gcc-libs, gdk-pixbuf2, libx11) contre **4** pour debtap.
4. **C++/Qt6 natif, sans exécution Python.** `debtap` est bash + Python
   (il appelle même `namcap` via Python). pkg_convert compile en un
   seul ELF de ~130 Ko — pas d'interpréteur, pas de dépendance Python.
5. **Interface Qt6 intégrée avec 6 langues** (DE/EN/FR/ES/TR/PT),
   clair/sombre, historique, journal copiable.
6. **Pas besoin d'AUR.** `debtap`/`rpmtoarch` viennent de l'AUR.
   pkg_convert se construit depuis vos sources via `makepkg -si`.

### Limites honnêtes

- Pas encore de script `.INSTALL` pour le cache d'icônes (debtap en
  génère un avec `gtk-update-icon-cache` + `update-desktop-database`).
- `makepkg` retire les symboles du binaire par défaut (≈12 % plus
  petit que la copie 1:1 de debtap) ; fonctionnellement identique.
- `pkgname` comporte un suffixe de version (ex. `program-1.99.16`).
- `pkgfile` s'appuie sur une base locale à jour ; lancez `pacman -Sy`
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

1. **Parcourir** → sélectionner un fichier `.deb`, `.rpm` ou `.AppImage`
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
