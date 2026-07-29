# Paket Converter

Ein nativer C++/Qt6-Konverter, der `.deb`- und `.rpm`-Pakete
in installierbare **Arch-Linux**-Pakete (`.pkg.tar.zst`) umwandelt — mit
echter Abhängigkeitserkennung, automatischer Repo-Installation der
Bibliotheken und persistenter Installationshistorie.

> ⚠️ **Ausschließlich für Arch-basierte Distributionen.** Dieses Projekt
> ist ausschließlich für **Arch-Linux-basierte** Distributionen
> (Arch, Manjaro, EndeavourOS, …) gedacht. Anfragen oder Probleme zu
> anderen Distributionen (Debian/Ubuntu, Fedora, openSUSE, …) werden
> **nicht** beantwortet — das Werkzeug erzeugt `.pkg.tar.zst`-Pakete,
> die nur auf Arch-basierten Systemen funktionieren.

## Warum?

Manche Programme (Spiele, Spezialwerkzeuge) gibt es nur als `.deb`
(Debian/Ubuntu) oder `.rpm` (Fedora/openSUSE), nicht in den
Arch-Repos. Dieses Werkzeug konvertiert sie ohne AUR — nur mit
offiziellen Arch-Quellen.

## Funktionen

- **deb/rpm → Arch**: extrahiert, erkennt benötigte Bibliotheken über
  `readelf` + `pkgfile` (exakte soname, keine geratenen Tabellen)
- **Auto-Install** der Repo-Abhängigkeiten via `pacman -S --asdeps`
- **Binary-Pfad**: Ausführbare Dateien aus den Programmen/Spielen werden nach `/usr/bin/` verschoben, damit sie unter Arch im `PATH` liegen.
- **Warnung** bei reinen Datenpaketen (ohne ausführbares Programm)
- **Hinweis-Popup** beim Installieren, falls zusätzliche Datenpakete
  (`-data`, `-common`) fehlen könnten
- **Kopierbarer Log**, persistente Installations-Historie
- **Hell/Dunkel**-Umschalter (Standard: hell)

## Gestaltungsziele

pkg_convert verfolgt einen eigenen Ansatz für fremde Paketformate
und richtet sich an Anwender, die direkt unter Arch arbeiten wollen,
ohne AUR-Hilfsmittel für den Konvertierungsschritt selbst.

1. **Ein Tool für beide Fremdformate.** Statt verschiedene
   Ein-Format-Lösungen zu kombinieren, beherrscht pkg_convert
   **`.deb` und `.rpm`** in derselben GUI mit konsistentem
   Paketlayout.
2. **Lokale Arch-Datenbank statt großer Fremd-Caches.** Es wird
   `pkgfile` genutzt, das deine vorhandene Arch-Sync-DB abfragt —
   kein Mega-Cache, kein separater Aktualisierungsdienst.
3. **Abhängigkeiten über echte Soname-Lookups.** Required Libraries
   werden per `readelf` + `pkgfile` ermittelt, nicht über feste
   Namens-Tabellen fremder Distributionen.
4. **Kompiliertes C++/Qt6 ohne Laufzeit-Interpreter-Abhängigkeit.**
   Ein einzelnes natives Binary, kein Python/Bash zur Laufzeit.
5. **Integrierte Qt6-GUI** mit Mehrsprachigkeit, Hell/Dunkel,
   Installations-Historie und kopierbarem Log.
6. **Installation ohne AUR-Hilfsmittel.** Build und Test laufen über
   normalen Quellcode + `makepkg -si`.

### Ehrliche Einschränkungen

- Kein `.INSTALL`-Skript für automatische Icon-Cache-Aktualisierung;
  Menü-Icons erscheinen ggf. erst nach manuellem `gtk-update-icon-cache`
  + `update-desktop-database`.
- `makepkg` strippt Binaries standardmäßig; funktional identisch zur
  1:1-Kopie anderer Werkzeuge, nur kleiner.
- `pkgname` trägt einen Versions-Suffix, z.B. `program-1.99.16`.
- `pkgfile` erfordert eine aktuelle lokale Sync-DB; bei veralteten
  Mappings `pacman -Sy` ausführen.

## Bauen & Installieren (aus Quelle, ohne AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Danach erscheint **Paket Converter** im KDE-Menü
(Kategorie: Utility / Paketverwaltung).

## Benutzung

1. **Durchsuchen** → eine `.deb`- oder `.rpm`-Datei auswählen
2. **Paket bauen** (oder „Paket + Quellen")
3. **Paket installieren** → Passwort eingeben, fertig

## Hinweise

- Manche Upstreams splitten Programme/Spiele in Programm + `-data`-Paket.
  Fehlen nach dem Start Grafik/Ton, auch das passende Datenpaket
  konvertieren.
- Bibliotheken, die nur im **AUR** existieren (z.B. `glc-lib`), können
  nicht automatisch installiert werden — das Werkzeug warnt dich.

## Abhängigkeiten

`qt6-base` (bietet `qmake6` zum Bauen), `pacman`, `file`,
`binutils`, `cpio`, `libarchive`
