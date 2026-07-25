# Paket Converter

Ein natives C++/Qt6-Werkzeug, das `.deb`- und `.rpm`-Pakete in
installierbare **Arch-Linux**-Pakete (`.pkg.tar.zst`) umwandelt —
mit echter Abhängigkeitserkennung, automatischer Repo-Installation
der Bibliotheken und persistentem Installationsverlauf.

## 🌐 Sprache / Language / Langue / Idioma / Dil / Dil

- 🇩🇪 Deutsch — [README.de.md](README.de.md)
- 🇬🇧 English — [README.en.md](README.en.md)
- 🇫🇷 Français — [README.fr.md](README.fr.md)
- 🇪🇸 Español — [README.es.md](README.es.md)
- 🇹🇷 Türkçe — [README.tr.md](README.tr.md)
- 🇵🇹 Português — [README.pt.md](README.pt.md)

---

## Funktionen (Kurzfassung)

- **deb/rpm → Arch**: extrahiert, erkennt benötigte Bibliotheken über
  `readelf` + `pkgfile` (soname-exakt)
- **Auto-Install** der Repo-Abhängigkeiten via `pacman -S --asdeps`
- **Binary-Pfad**: `/usr/games/` wird nach `/usr/bin/` verschoben
- **Warnung** bei reinen Datenpaketen (ohne ausführbares Programm)
- **Hinweis-Popup** beim Installieren, falls zusätzliche Datenpakete
  (`-data`, `-common`) fehlen könnten
- **Kopierbarer Log**, persistente Installations-Historie
- **Hell/Dunkel**-Umschalter (Standard: hell), Sprachauswahl (DE/EN/FR/ES/TR/PT)

## Bauen & Installieren (aus Quelle, ohne AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Danach erscheint **Paket Converter** im KDE-Menü (Kategorie: Utility / Paketverwaltung).

Die vollständige Dokumentation (Warum? / Benutzung / Hinweise / Abhängigkeiten)
findest du in der für dich passenden Sprach-README oben.
# pkg_convert
