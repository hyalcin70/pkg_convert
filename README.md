# Paket Converter

A native C++/Qt6 tool that converts `.deb` and `.rpm` packages into
installable **Arch-Linux** packages (`.pkg.tar.zst`) — with real
dependency detection, automatic installation of libraries from the
repos, and a persistent installation history.

## 🌐 Language

- 🇬🇧 English — [README.en.md](README.en.md)
- 🇩🇪 Deutsch — [README.de.md](README.de.md)
- 🇫🇷 Français — [README.fr.md](README.fr.md)
- 🇪🇸 Español — [README.es.md](README.es.md)
- 🇹🇷 Türkçe — [README.tr.md](README.tr.md)
- 🇵🇹 Português — [README.pt.md](README.pt.md)

---

## Features (short)

- **deb/rpm → Arch**: extracts, detects required libraries via
  `readelf` + `pkgfile` (exact soname)
- **Auto-install** of repo dependencies via `pacman -S --asdeps`
- **Binary path**: `/usr/games/` is relocated to `/usr/bin/`
- **Warning** for pure data packages (no executable program)
- **Hint popup** on install if additional data packages
  (`-data`, `-common`) might be missing
- **Copyable log**, persistent installation history
- **Light/Dark** toggle (default: light), language selection (DE/EN/FR/ES/TR/PT)

## Build & Install (from source, no AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Afterwards **Paket Converter** appears in the KDE menu
(category: Utility / Package Management).

Full documentation (Why? / Why pkg_convert vs debtap & rpmtoarch? /
Usage / Notes / Dependencies) is in the language-specific README
linked above.
