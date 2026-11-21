# Paket Converter

[English](README.md) | [Deutsch](README.de.md) | [Türkçe](README.tr.md) | [Español](README.es.md) | [Français](README.fr.md)

> **Statut Alpha :** Ce projet est actuellement en phase de test active (Alpha). Aucun support, aucune assistance ni aucune garantie n'est fourni.

**Licence :** GPL-3.0 avec la clause Commons — gratuite pour un usage non commercial ; utilisation commerciale uniquement avec autorisation.

**Droit d'auteur :** © 2026 Hakan Yalçın. Toute utilisation en dehors de cette licence — en particulier un usage commercial, la vente, la suppression des mentions de droit d'auteur ou de licence, ou le fait de présenter ce logiciel comme le vôtre — est strictement interdite.

## Qu'est-ce que pkg_convert ?

**pkg_convert** signifie **Package Converter** : un outil natif en C++/Qt6
qui convertit les paquets `.deb` et `.rpm` en paquets installables pour
**Arch Linux** (`.pkg.tar.zst`) — avec une détection réelle des dépendances,
l'installation automatique des bibliothèques depuis les dépôts et un
historique d'installation persistant.

> ⚠️ **Uniquement pour les distributions basées sur Arch.** Ce projet est exclusivement destiné aux
> distributions **basées sur Arch Linux** (Arch, Manjaro, EndeavourOS, …).
> Les demandes ou les problèmes concernant d'autres distributions (Debian/Ubuntu,
> Fedora, openSUSE, …) ne **seront pas** traités — l'outil produit des
> paquets `.pkg.tar.zst`, qui ne fonctionnent que sur les systèmes basés sur Arch.

## 🆕 Nouveautés (1.0.0-13)

- **Correction** : le chargement d'un nouveau fichier efface désormais immédiatement le résultat et la liste de dépendances précédents au lieu d'afficher des entrées obsolètes.

- **Intégration bureau et stabilité** : les liens symboliques sont conservés dans les paquets, les logos des applications apparaissent directement dans le menu (automatisation des icônes), le cache du menu est actualisé après l'installation, la vérification du faux root est plus robuste, et les libellés des thèmes en allemand sont corrigés.

- **Refonte de la traduction turque** : tous les textes utilisent désormais les caractères turcs appropriés (ğ ü ö ç ş ı İ).

- **Vérification du faux root après la compilation** : le paquet terminé est éventuellement installé dans un faux root temporaire (case à cocher) ; l'enregistrement et la liste des fichiers sont vérifiés automatiquement.

- Les métadonnées étrangères `Depends`/`Requires` sont désormais évaluées en plus
  de l'analyse NEEDED de readelf — les bibliothèques chargées via dlopen (X11, Wayland,
  Vulkan) deviennent de vraies dépendances.
- Sélection du fournisseur par score de nom (correspondance de sous-chaîne + de jeton, dépôts officiels
  en priorité) : plus de fausses dépendances issues de bundles comme `nsight-compute`
  au lieu de `qt6-base`.
- `.PKGINFO` ne contient que de vrais paquets Arch → `pacman -U` fonctionne
  de manière fiable.
- Détection des bibliothèques embarquées corrigée : les paquets autonomes ne
  listent plus leurs propres bibliothèques comme dépendances.
- L'installation et la désinstallation utilisent désormais `pkexec` (boîte de dialogue Polkit) ; nouvelles
  dépendances d'exécution : `pkgfile`, `polkit`.

## 🌐 Langue

- 🇬🇧 English — [README.en.md](README.en.md)
- 🇩🇪 Deutsch — [README.de.md](README.de.md)
- 🇫🇷 Français — [README.fr.md](README.fr.md)
- 🇪🇸 Español — [README.es.md](README.es.md)
- 🇹🇷 Türkçe — [README.tr.md](README.tr.md)
- 🇵🇹 Português — [README.pt.md](README.pt.md)

---

## Fonctionnalités (en bref)

- **deb/rpm → Arch** : extrait, détecte les bibliothèques requises via
  `readelf` + `pkgfile` (soname exact) et évalue les métadonnées étrangères
  `Depends`/`Requires` (les bibliothèques chargées via dlopen comme X11, Wayland ou
  Vulkan sont également trouvées)
- **Installation automatique** des dépendances des dépôts via `pacman -S --asdeps`
- **Meilleur fournisseur** : si plusieurs paquets fournissent la même bibliothèque, un
  score de nom (correspondance de sous-chaîne + de jeton, dépôts officiels en priorité)
  l'emporte sur un bundle arbitraire
- **Chemin des binaires** : les exécutables des programmes et jeux sont déplacés vers `/usr/bin/` afin de figurer dans le `PATH` d'Arch.
- **Avertissement** pour les paquets de données purs (sans programme exécutable)
- **Fenêtre d'astuce** à l'installation si des paquets de données
  supplémentaires (`-data`, `-common`) pourraient manquer
- **Journal copiable**, historique d'installation persistant
- **Clair/Sombre** à bascule (par défaut : clair), sélection de la langue (DE/EN/FR/ES/TR/PT)

- **Vérification du faux root** : après la compilation, le paquet est éventuellement installé dans un faux root temporaire, ce qui vérifie l'enregistrement et la liste des fichiers (case à cocher).

- **Vérification du faux root** : après la compilation, le paquet est éventuellement installé dans un faux root temporaire, ce qui vérifie l'enregistrement et la liste des fichiers (case à cocher).

## Pourquoi pkg_convert ?

Certains programmes ne sont disponibles qu'aux formats `.deb` ou `.rpm`, et non
dans les dépôts Arch. pkg_convert les convertit directement sur Arch sans AUR,
en utilisant uniquement les sources officielles d'Arch.

1. **Les deux formats étrangers dans un seul outil.** `.deb` et `.rpm` sont gérés
   depuis la même interface graphique avec des résultats cohérents.
2. **Aucune étape de téléchargement supplémentaire.** Il utilise `pkgfile` sur votre
   base de synchronisation Arch locale — aucun gros cache de paquets étrangers n'est nécessaire.
3. **Des dépendances via de vraies recherches de soname.** Les bibliothèques requises sont
   identifiées avec `readelf` + `pkgfile` ainsi que les métadonnées étrangères `Depends`/`Requires`,
   et non à partir de tables de noms figées provenant d'autres distributions.
4. **C++/Qt6 natif, sans dépendance à un interpréteur à l'exécution.** Un seul
   binaire natif, aucun Python/Bash nécessaire à l'exécution.
5. **Interface graphique Qt6 intégrée** avec 6 langues (DE/EN/FR/ES/TR/PT),
   thème clair/sombre, historique d'installation, journal copiable.
6. **Aucun utilitaire AUR requis.** La compilation et les tests s'effectuent
   directement depuis les sources brutes via `makepkg -si`.

### Limites honnêtes

- Aucun script `.INSTALL` : les caches d'icônes et des fichiers .desktop ne sont pas
  actualisés automatiquement ; une application convertie peut n'apparaître dans le menu
  qu'après `gtk-update-icon-cache` + `update-desktop-database` et/ou une actualisation
  du menu KDE (`kbuildsycoca6 --noincremental` ou une nouvelle connexion).
- Les noms de paquets étrangers sans entrée dans la table de correspondance sont
  signalés comme non associés plutôt que devinés.
- `makepkg` réduit les binaires par défaut (strip) ; fonctionnellement identique à
  une copie 1:1 issue d'autres outils, simplement plus petit.
- Le `pkgname` comporte un suffixe de version, par exemple `program-1.99.16`.
- `pkgfile` dépend d'une base de synchronisation locale à jour ; exécutez `pacman -Sy`
  si les correspondances semblent obsolètes.

## Compilation et installation (depuis les sources, sans AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Ensuite, **Paket Converter** apparaît dans le menu KDE
(catégorie : Utilitaires / Gestion des paquets).

La documentation complète (Pourquoi ? / Utilisation / Remarques / Dépendances) se trouve dans le
README dans la langue correspondante, lié ci-dessus.

![Logo SattNEK](created_by_sattnek.png)
