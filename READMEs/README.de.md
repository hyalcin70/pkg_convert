# Paket Converter

Ein nativer C++/Qt6-Konverter, der `.deb`- und `.rpm`-Pakete in
installierbare **Arch-Linux**-Pakete (`.pkg.tar.zst`) umwandelt — mit
echter Abhängigkeitserkennung, automatischer Repo-Installation der
Bibliotheken und persistenter Installationshistorie.

## Warum?

Manche Programme (Spiele, Spezialwerkzeuge) gibt es nur als `.deb`
(Debian/Ubuntu) oder `.rpm` (Fedora/openSUSE), nicht in den
Arch-Repos. Dieses Werkzeug konvertiert sie ohne AUR — nur mit
offiziellen Arch-Quellen.

## Funktionen

- **deb/rpm → Arch**: extrahiert, erkennt benötigte Bibliotheken über
  `readelf` + `pkgfile` (exakte soname, keine geratenen Tabellen)
- **Auto-Install** der Repo-Abhängigkeiten via `pacman -S --asdeps`
- **Binary-Pfad**: `/usr/games/` wird nach `/usr/bin/` verschoben
- **Warnung** bei reinen Datenpaketen (ohne ausführbares Programm)
- **Hinweis-Popup** beim Installieren, falls zusätzliche Datenpakete
  (`-data`, `-common`) fehlen könnten
- **Kopierbarer Log**, persistente Installations-Historie
- **Hell/Dunkel**-Umschalter (Standard: hell)

## Warum pkg_convert statt debtap / rpmtoarch?

Es gibt andere Konverter (debtap, rpmtoarch). Hier ist, warum
pkg_convert für die meisten Anwender die bessere Wahl ist:

1. **Ein Tool für beide Formate.** `debtap` kann nur `.deb`
   (bricht bei `.rpm` hart ab mit *"not a valid deb package"*),
   `rpmtoarch` nur `.rpm`. pkg_convert beherrscht **beides** aus
   derselben GUI mit identischem Ergebnis (verifiziert: derselbe
   Binary-Hash, dieselbe Paketgröße).
2. **Keine 1,1-GB-Datenbank.** `debtap` lädt eine Debian/Ubuntu-
   Paketliste (≈1,1 GB Cache, mit Root-Rechten). pkg_convert nutzt
   `pkgfile`, das deine **lokale** Arch-Repo-Datenbank abfragt — kein
   großer Download, kein separater Update-Schritt.
3. **Vollständigere Abhängigkeitserkennung.** In einem echten Test
   (webos-dev-manager) löste pkg_convert **11** Bibliotheken auf
   (gtk3, webkit2gtk-4.1, cairo, pango, glib2, libsoup, zlib, glibc,
   gcc-libs, gdk-pixbuf2, libx11) statt **4** bei debtap. Mehr
   soname-Treffer bedeuten ein saubereres Paket.
4. **Nativ C++/Qt6, keine Python-Laufzeit.** `debtap` ist Bash + Python
   (es ruft sogar `namcap` via Python auf). pkg_convert kompiliert zu
   einem einzelnen ~130-KB-ELF — kein Interpreter, keine Python-
   Abhängigkeit zur Laufzeit.
5. **Integrierte Qt6-GUI mit 6 Sprachen** (DE/EN/FR/ES/TR/PT),
   Hell/Dunkel, Installations-Historie, kopierbarer Log — kein
   separates GTK-Hilfsfenster neben einer Konsole.
6. **Kein AUR nötig.** `debtap`/`rpmtoarch` kommen aus dem AUR.
   pkg_convert baut aus eigenem Quellcode via `makepkg -si`.

### Ehrliche Einschränkungen

- Noch kein `.INSTALL`-Skript für Icon-Cache-Aktualisierung (debtap
  erzeugt eines mit `gtk-update-icon-cache` + `update-desktop-database`);
  Menü-Icons erscheinen evtl. erst nach manuellem Cache-Update.
- `makepkg` strippt das Binary standardmäßig (≈12 % kleiner als debtaps
  1:1-Kopie); funktional identisch.
- `pkgname` trägt einen Versions-Suffix (z.B. `webos-dev-manager-1.99.16`)
  statt eines sauberen Namens.
- `pkgfile` verlässt sich auf eine aktuelle lokale Sync-DB; bei
  veralteten Mappings `pacman -Sy` ausführen.

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

- Manche Upstreams splitten Spiele in Programm + `-data`-Paket.
  Fehlen nach dem Start Grafik/Ton, auch das passende Datenpaket
  konvertieren.
- Bibliotheken, die nur im **AUR** existieren (z.B. `glc-lib`), können
  nicht automatisch installiert werden — das Werkzeug warnt dich.

## Abhängigkeiten

`qt6-base` (bietet `qmake6` zum Bauen), `pacman`, `file`,
`binutils`, `cpio`, `libarchive`
