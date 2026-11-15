# Paket Converter

**Lizenz:** GPL-3.0 mit Commons Clause — freie nicht-kommerzielle Nutzung; kommerzielle Nutzung nur mit Genehmigung.

**Urheberrecht:** © 2026 Hakan Yalçın. Jede Nutzung außerhalb dieser Lizenz — insbesondere kommerzielle Nutzung, Verkauf, das Entfernen von Urheberrechts- oder Lizenzhinweisen sowie eine Fremdbezeichnung — ist ausdrücklich untersagt.

## Was ist pkg_convert?

**pkg_convert** steht für **Package Converter** (deutsch: Paket-Umwandler):
ein nativer C++/Qt6-Konverter, der `.deb`- und `.rpm`-Pakete in
installierbare **Arch-Linux**-Pakete (`.pkg.tar.zst`) umwandelt — mit
echter Abhängigkeitserkennung, automatischer Repo-Installation der
Bibliotheken und persistenter Installationshistorie.

> ⚠️ **Ausschließlich für Arch-basierte Distributionen.** Dieses Projekt
> ist ausschließlich für **Arch-Linux-basierte** Distributionen
> (Arch, Manjaro, EndeavourOS, …) gedacht. Anfragen oder Probleme zu
> anderen Distributionen (Debian/Ubuntu, Fedora, openSUSE, …) werden
> **nicht** beantwortet — das Werkzeug erzeugt `.pkg.tar.zst`-Pakete,
> die nur auf Arch-basierten Systemen funktionieren.

## 🆕 Neu in 1.0.0-5

- **Türkisch-Überarbeitung**: Alle Texte verwenden jetzt die korrekten türkischen Sonderzeichen (ğ ü ö ç ş ı İ).

- **Fake-Root-Prüfung nach dem Bau**: Das fertige Paket wird (optional, per Checkbox) in einen temporären Fake-Root installiert; Registrierung und Dateiliste werden automatisch verifiziert.

- Fremde `Depends`/`Requires`-Metadaten werden zusätzlich zum
  `readelf`-NEEDED-Scan ausgewertet — auch per `dlopen` geladene
  Bibliotheken (X11, Wayland, Vulkan) werden als echte Abhängigkeiten
  aufgelöst.
- Anbieter-Auswahl über Namens-Score (Teilstring + Token-Abgleich,
  offizielle Repos zuerst): keine falschen Deps mehr durch Bundle wie
  `nsight-compute` statt `qt6-base`.
- `.PKGINFO` enthält nur echte Arch-Pakete → `pacman -U` funktioniert
  zuverlässig.
- Erkennung mitgelieferter Bibliotheken repariert: eigenständige Pakete
  listen ihre eigenen Libs nicht mehr als Abhängigkeiten.
- Installation/Deinstallation läuft über `pkexec` (Polkit-Dialog);
  neue Laufzeit-Abhängigkeiten: `pkgfile`, `polkit`.

## Warum?

Manche Programme (Spiele, Spezialwerkzeuge) gibt es nur als `.deb`
(Debian/Ubuntu) oder `.rpm` (Fedora/openSUSE), nicht in den
Arch-Repos. Dieses Werkzeug konvertiert sie ohne AUR — nur mit
offiziellen Arch-Quellen.

## Funktionen

- **deb/rpm → Arch**: extrahiert, erkennt benötigte Bibliotheken über
  `readelf` + `pkgfile` (exakte soname, keine geratenen Tabellen)
  und wertet fremde `Depends`/`Requires`-Metadaten aus (auch per
  `dlopen` geladene Bibliotheken wie X11, Wayland oder Vulkan)
- **Auto-Install** der Repo-Abhängigkeiten via `pacman -S --asdeps`
- **Bester Anbieter**: Liefern mehrere Pakete dieselbe Bibliothek,
  gewinnt der namensbeste Treffer (Teilstring- und Token-Abgleich,
  offizielle Repos zuerst) statt eines beliebigen Bündlers
- **Binary-Pfad**: Ausführbare Dateien aus den Programmen/Spielen werden nach `/usr/bin/` verschoben, damit sie unter Arch im `PATH` liegen.
- **Warnung** bei reinen Datenpaketen (ohne ausführbares Programm)
- **Hinweis-Popup** beim Installieren, falls zusätzliche Datenpakete
  (`-data`, `-common`) fehlen könnten
- **Kopierbarer Log**, persistente Installations-Historie
- **Hell/Dunkel**-Umschalter (Standard: hell)

- **Fake-Root-Prüfung**: Nach dem Bau wird das Paket optional in einen temporären Fake-Root installiert und Registrierung sowie Dateiliste verifiziert (Checkbox).

- **Fake-Root-Prüfung**: Nach dem Bau wird das Paket optional in einen temporären Fake-Root installiert und Registrierung sowie Dateiliste verifiziert (Checkbox).

## Gestaltung

- **Beide Fremdformate:** `.deb` und `.rpm` werden in derselben GUI
  verarbeitet.
- **Arch-Lookup:** Bibliotheken werden über `readelf` + `pkgfile`
  gegen die lokale Arch-Sync-DB aufgelöst; zusätzlich fließen fremde
  `Depends`/`Requires`-Metadaten ein.
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

- Kein `.INSTALL`-Skript: Icon- und Desktop-Caches werden nicht
  automatisch aktualisiert; eine konvertierte App erscheint ggf. erst im
  Menü, nachdem `gtk-update-icon-cache` + `update-desktop-database`
  ausgeführt wurden und/oder der KDE-Menücache neu gebaut wurde
  (`kbuildsycoca6 --noincremental` bzw. Neuanmeldung).
- Fremde Paketnamen ohne Tabelleneintrag werden als unmapped gemeldet,
  statt geraten zu werden.
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
3. **Paket installieren** → Polkit-Dialog bestätigen, fertig

## Hinweise

- Manche Upstreams splitten Programme/Spiele in Programm + `-data`-Paket.
  Fehlen nach dem Start Grafik/Ton, auch das passende Datenpaket
  konvertieren.
- Bibliotheken, die nur im **AUR** existieren (z.B. `glc-lib`), können
  nicht automatisch installiert werden — das Werkzeug warnt dich.

## Abhängigkeiten

`qt6-base` (bietet `qmake6` zum Bauen), `pacman`, `file`,
`binutils`, `cpio`, `libarchive`, `pkgfile`, `polkit`

![SattNEK Logo](../created_by_sattnek.png)
