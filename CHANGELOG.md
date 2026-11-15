# Changelog

## 1.0.0-9 (November 15, 2026)

### Fixed
- Desktop entries of installed packages now appear immediately in the KDE menu:
  after a successful install pkg_convert refreshes the menu cache (`kbuildsycoca6`).
- Fake-root verification uses its own minimal pacman.conf (signatures disabled,
  repositories via host mirrorlist) and reports low disk space clearly instead of
  failing silently with "package not registered".
- Foreign sonames without a repository counterpart are named concretely:
  `libcurl-nss.so.4` now shows up as AUR package `libcurl-nss` instead of a generic
  "check manually" note.

## 1.0.0-8 (November 15, 2026)

### Fixed
- Broken symlinks were skipped during conversion because Qt only lists them with the
  `System` filter: launcher links like `/usr/bin/google-chrome-stable ->
  /opt/google/chrome/google-chrome` vanished, so the command was missing after install.
  Both build stages now preserve and recreate all symlinks.

## 1.0.0-7 (November 15, 2026)

### Fixed
- Symlinks are now preserved during conversion: packages like Google Chrome ship their
  launcher as a symlink (`/usr/bin/google-chrome-stable -> /opt/google/chrome/google-chrome`)
  and previously lost it, so the command was not found after installation.

## 1.0.0-6 (November 15, 2026)

### Fixed
- German theme toggle showed swapped labels ("Light"/"Dark") — now "Hell"/"Dunkel".
- The installed-packages list now follows the app theme (previously pitch black in
  light mode on systems with a dark palette, e.g. a fresh CachyOS install).
- Combo boxes and checkboxes are themed consistently in light and dark mode.

## 1.0.0-5 (November 15, 2026)

### Fixed
- Turkish translation overhauled: proper Turkish characters throughout
  (ğ ü ö ç ş ı İ) instead of ASCII transliteration; a few phrasings improved.

## 1.0.0-4 (November 15, 2026)

### Added
- **Fake root verification after building**: the finished package is optionally
  installed into a temporary fake root (checkbox); registration and file list are
  verified automatically — see right away whether the package installs cleanly.

## 1.0.0-3 (November 14, 2026)

### Changed
- License: GPL-3.0 with an additional Commons Clause — selling or commercial use
  only with permission; explicit copyright and misuse notice.
- Runtime dependencies `pkgfile` and `polkit` declared in the PKGBUILD.
- All READMEs updated: license, copyright and misuse notes, name explanation
  (Package Converter), news block, SattNEK logo.
- Removed the outdated criminal-prosecution wording again.

## 1.0.0-2 (November 14, 2026)

### Fixed
- `.PKGINFO` contained foreign sonames (e.g. `libxkbcommon.so.0()(64bit)`) that
  pacman could not resolve → now only real Arch packages appear in `depend =`,
  making `pacman -U` reliable.
- Shipped libraries were not detected due to an escaping bug in
  `find -printf '%f\\n'` → a package's own libs are no longer listed as dependencies.
- When pkgfile returned multiple hits, the first one was taken
  (e.g. `nsight-compute` instead of `qt6-base`) → now the best name match wins
  (token matching, official repos first).

### Added
- Foreign `Depends`/`Requires` from package metadata is evaluated in addition to
  the `readelf` NEEDED scan — dlopen-loaded libraries (X11, Wayland, Vulkan)
  are resolved as real dependencies.
- Provider selection by name score with token matching.
- Runtime dependencies `pkgfile` and `polkit`.

### Changed
- Install/uninstall now uses `pkexec` (Polkit dialog) instead of `sudo -S`.
- Brought all READMEs (7 languages) up to date.
