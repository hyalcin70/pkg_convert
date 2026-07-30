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

## Gestaltung

- **Beide Fremdformate:** `.deb` und `.rpm` werden in derselben GUI
  verarbeitet.
- **Arch-Lookup:** Bibliotheken werden über `readelf` + `pkgfile`
  gegen die lokale Arch-Sync-DB aufgelöst.
- **Native Binaries:** Ausführbare Dateien landen über `/usr/bin/` im
  Arch-`PATH`; Daten/Desktops bleiben unberührt.
- **GUI-Repo-Interaktion:** Abhängigkeiten können automatisch über
  `pacman -S --asdeps` bezogen werden; Installation/Deinstallation
  sind direkt in der Oberfläche verfügbar.
- **Keine Laufzeit-Interpreter-Abhängigkeit:** Ein einzelnes natives
  Binary, ohne Python/Bash zur Laufzeit.
- **Mehrsprachig:** Deutsch, Englisch, Französisch, Spanisch,
  Türkisch, Portugiesisch; Hell/Dunkel; Installations-Historie;
  kopierbarer Log.
- **Ohne AUR-Hilfsmittel:** Build und Test laufen über normalen
  Quellcode + `makepkg -si`.

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
