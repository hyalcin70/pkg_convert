# Paket Converter

![SattNEK Logo](created_by_sattnek.png)

> 🧪 **Beta status.** This project is still in **beta**. Features may change,
> break, or behave unexpectedly. Use at your own risk and report issues on
> the issue tracker.

**License:** GPL-3.0 with the Commons Clause — free for non-commercial use; commercial use only with permission.

**Copyright:** © 2026 Hakan Yalçın. Any use outside this license — especially commercial use, selling, removing copyright or license notices, or claiming the software as your own — is strictly prohibited.

## What is pkg_convert?

**pkg_convert** stands for **Package Converter**: a native C++/Qt6 tool
that converts `.deb` and `.rpm` packages into installable **Arch Linux**
packages (`.pkg.tar.zst`) — with real dependency detection, automatic
installation of libraries from the repos, and a persistent installation
history.

> ⚠️ **Arch-based distributions only.** This project is exclusively for
> **Arch-Linux-based** distributions (Arch, Manjaro, EndeavourOS, …).
> Requests or issues concerning other distributions (Debian/Ubuntu,
> Fedora, openSUSE, …) will **not** be answered — the tool produces
> `.pkg.tar.zst` packages, which only work on Arch-based systems.

## 🆕 What's new (1.0.0-2)

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
  `readelf` + `pkgfile` (exact soname) and evaluates foreign
  `Depends`/`Requires` metadata (dlopen-loaded libs like X11, Wayland or
  Vulkan are found too)
- **Auto-install** of repo dependencies via `pacman -S --asdeps`
- **Best provider**: if several packages ship the same library, a name
  score (substring + token match, official repos first) wins over an
  arbitrary bundle
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
   identified with `readelf` + `pkgfile` plus foreign `Depends`/`Requires`
   metadata, not fixed name tables from other distributions.
4. **Native C++/Qt6, no runtime interpreter dependency.** A single
   native binary, no Python/Bash needed at runtime.
5. **Integrated Qt6 GUI** with 6 languages (DE/EN/FR/ES/TR/PT),
   light/dark, install history, copyable log.
6. **No AUR helper required.** Build and test run from plain source
   via `makepkg -si`.

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

Full documentation (Why? / Usage / Notes / Dependencies) is in the
language-specific README linked above.
