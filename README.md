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
- **Binary path**: `/usr/games/` is relocated to `/usr/bin/`
- **Warning** for pure data packages (no executable program)
- **Hint popup** on install if additional data packages
  (`-data`, `-common`) might be missing
- **Copyable log**, persistent installation history
- **Light/Dark** toggle (default: light), language selection (DE/EN/FR/ES/TR/PT)

## Why pkg_convert instead of debtap / rpmtoarch?

There are other converters (debtap, rpmtoarch). Here is why
pkg_convert is a better fit for most users:

1. **One tool for both formats.** `debtap` only handles `.deb`
   (it hard-fails on `.rpm` with *"not a valid deb package"*), while
   `rpmtoarch` only handles `.rpm`. pkg_convert handles **both**
   (`.deb`, `.rpm`) from the same GUI with identical
   results (verified: same binary hash, same package size for deb/rpm).
2. **No 1.1 GB database download.** `debtap` needs a Debian/Ubuntu
   package list (≈1.1 GB cache, fetched with root). pkg_convert uses
   `pkgfile`, which queries your **local** Arch repo database — no
   large download, no separate update step.
3. **More complete dependency detection.** In tests with
   different programs provided as both `.deb` and `.rpm`, pkg_convert
   resolved **11** libraries
   (gtk3, webkit2gtk-4.1, cairo, pango, glib2, libsoup, zlib, glibc,
   gcc-libs, gdk-pixbuf2, libx11) vs **4** from debtap. More
   soname-based matches mean a cleaner package.
4. **Native C++/Qt6, no Python runtime.** `debtap` is bash + Python
   (it even calls `namcap` via Python). pkg_convert compiles to a
   single ~130 KB ELF — no interpreter, no Python dependency at runtime.
5. **Integrated Qt6 GUI with 6 languages** (DE/EN/FR/ES/TR/PT),
   light/dark, install history, copyable log — not a separate GTK
   helper window next to a CLI.
6. **No AUR needed.** `debtap`/`rpmtoarch` come from the AUR.
   pkg_convert builds from your own source via `makepkg -si`.

### Honest limitations

- No `.INSTALL` script for icon-cache refresh yet (debtap generates
  one with `gtk-update-icon-cache` + `update-desktop-database`); menu
  icons may appear only after a manual cache refresh.
- `makepkg` strips the binary by default (≈12 % smaller than debtap's
  1:1 copy); functionally identical.
- `pkgname` carries a version suffix (e.g. `program-1.99.16`)
  rather than a clean name.
- `pkgfile` relies on an up-to-date local sync db; run `pacman -Sy`
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
