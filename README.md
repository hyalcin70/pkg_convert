# Paket Converter

> 🧪 **Beta status.** This project is still in **beta**. Features may change,
> break, or behave unexpectedly. Use at your own risk and report issues on
> the issue tracker.

A native C++/Qt6 tool that converts `.deb` and `.rpm`
packages into installable **Arch-Linux** packages (`.pkg.tar.zst`) — with
real dependency detection, automatic installation of libraries from the
repos, and a persistent installation history.

> ⚠️ **Arch-based distributions only.** This project is exclusively for
> **Arch-Linux-based** distributions (Arch, Manjaro, EndeavourOS, …).
> Requests or issues concerning other distributions (Debian/Ubuntu,
> Fedora, openSUSE, …) will **not** be answered — the tool produces
> `.pkg.tar.zst` packages, which only work on Arch-based systems.

## 🌐 Language

- 🇬🇧 English — [README.en.md](READMEs/README.en.md)
- 🇩🇪 Deutsch — [README.de.md](READMEs/README.de.md)
- 🇫🇷 Français — [README.fr.md](READMEs/README.fr.md)
- 🇪🇸 Español — [README.es.md](READMEs/README.es.md)
- 🇹🇷 Türkçe — [README.tr.md](READMEs/README.tr.md)
- 🇵🇹 Português — [README.pt.md](READMEs/README.pt.md)

---

## Features (short)

- **deb/rpm → Arch**: extracts, detects required libraries via
  `readelf` + `pkgfile` (exact soname)
- **Auto-install** of repo dependencies via `pacman -S --asdeps`
- **Binary path**: Executables from programs/games are moved to `/usr/bin/` so they are in Arch's `PATH`.
- **Warning** for pure data packages (no executable program)
- **Hint popup** on install if additional data packages
  (`-data`, `-common`) might be missing
- **Copyable log**, persistent installation history
- **Light/Dark** toggle (default: light), language selection (DE/EN/FR/ES/TR/PT)

## Why pkg_convert?

Some programs are only available as `.deb` or `.rpm`, not in the
Arch repos. pkg_convert converts them directly on Arch without AUR,
using only official Arch sources.

1. **Both foreign formats in one tool.** `.deb` and `.rpm` are handled
   from the same GUI with consistent results.
2. **No extra download step.** It uses `pkgfile` against your local
   Arch sync DB — no large foreign package cache needed.
3. **Dependencies via real soname lookups.** Required libraries are
   identified with `readelf` + `pkgfile`, not fixed name tables from
   other distributions.
4. **Native C++/Qt6, no runtime interpreter dependency.** A single
   native binary, no Python/Bash needed at runtime.
5. **Integrated Qt6 GUI** with 6 languages (DE/EN/FR/ES/TR/PT),
   light/dark, install history, copyable log.
6. **No AUR helper required.** Build and test run from plain source
   via `makepkg -si`.

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

Full documentation (Why? / Usage / Notes / Dependencies) is in the
language-specific README linked above.
