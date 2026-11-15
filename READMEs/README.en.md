# Paket Converter

**License:** GPL-3.0 with the Commons Clause — free for non-commercial use; commercial use only with permission.

**Copyright:** © 2026 Hakan Yalçın. Any use outside this license — especially commercial use, selling, removing copyright or license notices, or claiming the software as your own — is strictly prohibited.

## What is pkg_convert?

**pkg_convert** stands for **Package Converter**: a native C++/Qt6 tool
that converts `.deb` and `.rpm` packages into installable **Arch Linux**
packages (`.pkg.tar.zst`) — with real dependency detection, automatic repo
installation of libraries, and a persistent installation history.

> ⚠️ **Arch-based distributions only.** This project is exclusively for
> **Arch-Linux-based** distributions (Arch, Manjaro, EndeavourOS, …).
> Requests or issues concerning other distributions (Debian/Ubuntu,
> Fedora, openSUSE, …) will **not** be answered — the tool produces
> `.pkg.tar.zst` packages, which only work on Arch-based systems.

## 🆕 What's new (1.0.0-5)

- **Turkish translation overhaul**: all texts now use proper Turkish characters (ğ ü ö ç ş ı İ).

- **Fake root verification after building**: the finished package is optionally installed into a temporary fake root (checkbox); registration and file list are verified automatically.

- Foreign `Depends`/`Requires` metadata is now evaluated in addition to
  the readelf NEEDED scan — dlopen-loaded libraries (X11, Wayland,
  Vulkan) become real dependencies.
- Provider selection by name score (substring + token match, official
  repos first): no more wrong deps from bundles like `nsight-compute`
  instead of `qt6-base`.
- `.PKGINFO` carries only real Arch packages → `pacman -U` works
  reliably.
- Shipped-library detection fixed: self-contained packages no longer
  list their own libraries as dependencies.
- Install/uninstall now uses `pkexec` (Polkit dialog); new runtime
  dependencies: `pkgfile`, `polkit`.

## Why?

Some programs (games, specialty tools) are only available as `.deb`
(Debian/Ubuntu) or `.rpm` (Fedora/openSUSE), not in the
Arch repos.
This tool converts them without AUR — using only official Arch sources.

## Features

- **deb/rpm → Arch**: extracts, detects required libraries via
  `readelf` + `pkgfile` (exact soname) and evaluates foreign
  `Depends`/`Requires` metadata (dlopen-loaded libs like X11, Wayland or
  Vulkan are found too)
- **Auto-install** of repo dependencies via `pacman -S --asdeps`
- **Best provider**: if several packages ship the same library, a name
  score (substring + token match, official repos first) wins over an
  arbitrary bundle
- **Binary path**: Executables from programs/games are moved to `/usr/bin/` so they are in Arch's `PATH`.
- **Warning** for pure data packages (no executable program)
- **Hint popup** at install time if extra data packages
  (`-data`, `-common`) might be missing
- **Copyable log**, persistent installation history
- **Light/Dark** toggle (default: light)

- **Fake root verification**: after building, the package is optionally installed into a temporary fake root, verifying registration and file list (checkbox).

- **Fake root verification**: after building, the package is optionally installed into a temporary fake root, verifying registration and file list (checkbox).

## Design

- **Both foreign formats:** `.deb` and `.rpm` are handled in the same
  GUI.
- **Arch lookup:** Libraries are resolved via `readelf` + `pkgfile`
  against your local Arch sync DB, plus foreign `Depends`/`Requires`
  metadata from the source package.
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

- No `.INSTALL` script: icon and desktop caches are not refreshed
  automatically; a converted app may only appear in the menu after
  `gtk-update-icon-cache` + `update-desktop-database` and/or a KDE menu
  refresh (`kbuildsycoca6 --noincremental` or re-login).
- Foreign package names without a mapping-table entry are reported as
  unmapped instead of being guessed.
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
3. **Install package** → confirm the Polkit dialog, done

## Notes

- Some upstreams split programs/games into program + `-data` package.
  If graphics/sound are missing after launch, also convert the
  corresponding data package.
- Libraries that exist only in **AUR** (e.g. `glc-lib`) cannot be
  installed automatically — the tool warns you.

## Dependencies

`qt6-base` (provides `qmake6` to build), `pacman`, `file`,
`binutils`, `cpio`, `libarchive`, `pkgfile`, `polkit`

![SattNEK Logo](../created_by_sattnek.png)
