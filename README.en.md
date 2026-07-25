# Paket Converter

A native C++/Qt6 tool that converts `.deb` and `.rpm` packages into
installable **Arch Linux** packages (`.pkg.tar.zst`) — with real
dependency detection, automatic repo installation of libraries, and a
persistent installation history.

## Why?

Some programs (games, specialty tools) are only available as `.deb`
(Debian/Ubuntu) or `.rpm` (Fedora/openSUSE), not in the Arch repos.
This tool converts them without AUR — using only official Arch sources.

## Features

- **deb/rpm → Arch**: extracts, detects required libraries via
  `readelf` + `pkgfile` (exact soname, no guessed tables)
- **Auto-install** of repo dependencies via `pacman -S --asdeps`
- **Binary path**: `/usr/games/` is moved to `/usr/bin/`
- **Warning** for pure data packages (no executable program)
- **Hint popup** at install time if extra data packages
  (`-data`, `-common`) might be missing
- **Copyable log**, persistent installation history
- **Light/Dark** toggle (default: light)

## Build & Install (from source, no AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Afterwards **Paket Converter** appears in the KDE menu
(category: Utility / Package Management).

## Usage

1. **Browse** → select a `.deb` or `.rpm` file
2. **Build package** (or "Package + Sources")
3. **Install package** → enter password, done

## Notes

- Some upstreams split games into program + `-data` package.
  If graphics/sound are missing after launch, also convert the
  corresponding data package.
- Libraries that exist only in **AUR** (e.g. `glc-lib`) cannot be
  installed automatically — the tool warns you.

## Dependencies

`qt6-base` (bietet `qmake6` zum Bauen), `pacman`, `file`, `binutils`, `cpio`, `libarchive`
