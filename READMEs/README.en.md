# Paket Converter

A native C++/Qt6 tool that converts `.deb` and `.rpm`
packages into installable **Arch Linux** packages (`.pkg.tar.zst`) — with
real dependency detection, automatic repo installation of libraries, and
a persistent installation history.

> ⚠️ **Arch-based distributions only.** This project is exclusively for
> **Arch-Linux-based** distributions (Arch, Manjaro, EndeavourOS, …).
> Requests or issues concerning other distributions (Debian/Ubuntu,
> Fedora, openSUSE, …) will **not** be answered — the tool produces
> `.pkg.tar.zst` packages, which only work on Arch-based systems.

## Why?

Some programs (games, specialty tools) are only available as `.deb`
(Debian/Ubuntu) or `.rpm` (Fedora/openSUSE), not in the
Arch repos.
This tool converts them without AUR — using only official Arch sources.

## Features

- **deb/rpm → Arch**: extracts, detects required libraries via
  `readelf` + `pkgfile` (exact soname)
- **Auto-install** of repo dependencies via `pacman -S --asdeps`
- **Binary path**: Executables from programs/games are moved to `/usr/bin/` so they are in Arch's `PATH`.
- **Warning** for pure data packages (no executable program)
- **Hint popup** at install time if extra data packages
  (`-data`, `-common`) might be missing
- **Copyable log**, persistent installation history
- **Light/Dark** toggle (default: light)

## Design

- **Both foreign formats:** `.deb` and `.rpm` are handled in the same
  GUI.
- **Arch lookup:** Libraries are resolved via `readelf` + `pkgfile`
  against your local Arch sync DB.
- **Native binaries:** Executables are placed under `/usr/bin/` so
  they are in Arch's `PATH`; data/desktop files stay unchanged.
- **GUI repo interaction:** Dependencies can be fetched automatically
  via `pacman -S --asdeps`; install/uninstall are available from the
  interface.
- **No runtime interpreter dependency:** A single native binary,
  without Python/Bash at runtime.
- **Multilingual:** German, English, French, Spanish, Turkish,
  Portuguese; light/dark; installation history; copyable log.
- **No AUR helper required:** Build and test run from plain source via
  `makepkg -si`.

### Honest limitations

- No `.INSTALL` script for automatic icon-cache refresh; menu icons
  may only appear after manual `gtk-update-icon-cache` +
  `update-desktop-database`.
- `makepkg` strips binaries by default; functionally the same as a
  1:1 copy from other tools, just smaller.
- `pkgname` carries a version suffix, e.g. `program-1.99.16`.
- `pkgfile` relies on an up-to-date local sync DB; run `pacman -Sy`
  if mappings look stale.

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

- Some upstreams split programs/games into program + `-data` package.
  If graphics/sound are missing after launch, also convert the
  corresponding data package.
- Libraries that exist only in **AUR** (e.g. `glc-lib`) cannot be
  installed automatically — the tool warns you.

## Dependencies

`qt6-base` (provides `qmake6` to build), `pacman`, `file`,
`binutils`, `cpio`, `libarchive`
