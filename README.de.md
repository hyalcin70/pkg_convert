# Paket Converter

Ein natives C++/Qt6-Werkzeug, das `.deb`- und `.rpm`-Pakete in
installierbare **Arch-Linux**-Pakete (`.pkg.tar.zst`) umwandelt —
mit echter Abhängigkeitserkennung, automatischer Repo-Installation
der Bibliotheken und persistentem Installationsverlauf.

## Warum?

Manche Programme (Spiele, Spezialtools) gibt es nur als `.deb` (Debian/Ubuntu)
oder `.rpm` (Fedora/openSUSE), nicht in den Arch-Repos. Dieses Tool
konvertiert sie ohne AUR — nur mit offiziellen Arch-Paketquellen.

## Funktionen

- **deb/rpm → Arch**: extrahiert, erkennt benötigte Bibliotheken über
  `readelf` + `pkgfile` (soname-exakt, keine geratenen Tabellen)
- **Auto-Install** der Repo-Abhängigkeiten via `pacman -S --asdeps`
- **Binary-Pfad**: `/usr/games/` wird nach `/usr/bin/` verschoben
- **Warnung** bei reinen Datenpaketen (ohne ausführbares Programm)
- **Hinweis-Popup** beim Installieren, falls zusätzliche Datenpakete
  (`-data`, `-common`) fehlen könnten
- **Kopierbarer Log**, persistente Installations-Historie
- **Hell/Dunkel**-Umschalter (Standard: hell)

## Bauen & Installieren (aus Quelle, ohne AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Danach erscheint **Paket Converter** im KDE-Menü (Kategorie: Utility / Paketverwaltung).

## Benutzung

1. **Durchsuchen** → wähle eine `.deb`- oder `.rpm`-Datei
2. **Paket bauen** (oder „Paket + Quellen")
3. **Paket installieren** → Passwort eingeben, fertig

## Hinweise

- Manche Upstreams splitten Spiele in Programm + `-data`-Paket.
  Sind nach dem Start Grafik/Sound fehlend, konvertiere auch das
  entsprechende Datenpaket.
- Bibliotheken, die nur in **AUR** existieren (z.B. `glc-lib`),
  können nicht automatisch installiert werden — das Tool warnt.

## Abhängigkeiten

`qt6-base`, `pacman`, `file`, `binutils`, `cpio`, `libarchive`
(sowie `qmake6` zum Bauen).
