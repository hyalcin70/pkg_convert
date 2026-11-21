# Paket Converter

[English](README.md) | [Deutsch](README.de.md) | [Türkçe](README.tr.md) | [Español](README.es.md) | [Français](README.fr.md)

> **Alpha-Status:** Dieses Projekt befindet sich aktuell noch in der aktiven Testphase (Alpha). Jegliche Unterstützung, Hilfe oder Gewährleistung wird nicht gewährt.

**Lizenz:** GPL-3.0 mit der Commons Clause — kostenlos für nicht-kommerzielle Nutzung; kommerzielle Nutzung nur mit Genehmigung.

**Urheberrecht:** © 2026 Hakan Yalçın. Jede Nutzung außerhalb dieser Lizenz — insbesondere kommerzielle Nutzung, Verkauf, Entfernung von Urheberrechts- oder Lizenzhinweisen oder die Behauptung, die Software sei Ihr Eigentum — ist strengstens untersagt.

## Was ist pkg_convert?

**pkg_convert** steht für **Package Converter**: ein natives C++/Qt6-Werkzeug, das `.deb`- und `.rpm`-Pakete in installierbare **Arch-Linux**-Pakete (`.pkg.tar.zst`) umwandelt — mit echter Abhängigkeitserkennung, automatischer Installation von Bibliotheken aus den Repos und einer dauerhaften Installationshistorie.

> ⚠️ **Nur Arch-basierte Distributionen.** Dieses Projekt ist ausschließlich für **Arch-Linux-basierte** Distributionen (Arch, Manjaro, EndeavourOS, …). Anfragen oder Issues zu anderen Distributionen (Debian/Ubuntu, Fedora, openSUSE, …) werden **nicht** beantwortet — das Tool erzeugt `.pkg.tar.zst`-Pakete, die nur auf Arch-basierten Systemen funktionieren.

## 🆕 Neuigkeiten (1.0.0-13)

- **Fix**: Beim Laden einer neuen Datei wird die vorherige Ergebnis-/Abhängigkeitsliste jetzt sofort geleert, statt veraltete Einträge anzuzeigen.

- **Desktop-Integration & Stabilität**: Symlinks werden in Paketen beibehalten, App-Logos erscheinen direkt im Menü (Icon-Automatisierung), der Menü-Cache wird nach der Installation aktualisiert, robustere Fake-Root-Prüfung, korrigierte deutsche Theme-Beschriftungen.

- **Türkische Übersetzung überarbeitet**: Alle Texte verwenden jetzt korrekte türkische Zeichen (ğ ü ö ç ş ı İ).

- **Fake-Root-Prüfung nach dem Bauen**: Das fertige Paket wird optional in eine temporäre Fake-Root installiert (Checkbox); Registrierung und Dateiliste werden automatisch geprüft.

- Fremde `Depends`/`Requires`-Metadaten werden jetzt zusätzlich zum readelf-NEEDED-Scan ausgewertet — über dlopen geladene Bibliotheken (X11, Wayland, Vulkan) werden zu echten Abhängigkeiten.
- Anbieterauswahl nach Namenswertung (Substring- + Token-Match, offizielle Repos zuerst): keine falschen Abhängigkeiten mehr aus Bundles wie `nsight-compute` statt `qt6-base`.
- `.PKGINFO` enthält nur echte Arch-Pakete → `pacman -U` funktioniert zuverlässig.
- Erkennung mitgelieferter Bibliotheken korrigiert: Eigenständige Pakete listen ihre eigenen Bibliotheken nicht mehr als Abhängigkeiten.
- Installieren/Deinstallieren nutzt jetzt `pkexec` (Polkit-Dialog); neue Laufzeitabhängigkeiten: `pkgfile`, `polkit`.

## 🌐 Sprache

- 🇬🇧 English — [README.en.md](README.en.md)
- 🇩🇪 Deutsch — [README.de.md](README.de.md)
- 🇫🇷 Français — [README.fr.md](README.fr.md)
- 🇪🇸 Español — [README.es.md](README.es.md)
- 🇹🇷 Türkçe — [README.tr.md](README.tr.md)
- 🇵🇹 Português — [README.pt.md](README.pt.md)

---

## Funktionen (kurz)

- **deb/rpm → Arch**: extrahiert, erkennt benötigte Bibliotheken über `readelf` + `pkgfile` (exakter soname) und wertet fremde `Depends`/`Requires`-Metadaten aus (über dlopen geladene Bibliotheken wie X11, Wayland oder Vulkan werden ebenfalls gefunden)
- **Auto-Installation** von Repo-Abhängigkeiten über `pacman -S --asdeps`
- **Bester Anbieter**: Wenn mehrere Pakete dieselbe Bibliothek enthalten, gewinnt eine Namenswertung (Substring- + Token-Match, offizielle Repos zuerst) gegenüber einem beliebigen Bundle
- **Binary-Pfad**: Executables aus Programmen/Spielen werden nach `/usr/bin/` verschoben, damit sie in Archs `PATH` liegen.
- **Warnung** bei reinen Datenpaketen (ohne ausführbares Programm)
- **Hinweis-Popup** bei der Installation, wenn zusätzliche Datenpakete (`-data`, `-common`) fehlen könnten
- **Kopierbares Log**, dauerhafte Installationshistorie
- **Light/Dark**-Umschalter (Standard: light), Sprachauswahl (DE/EN/FR/ES/TR/PT)

- **Fake-Root-Prüfung**: Nach dem Bauen wird das Paket optional in eine temporäre Fake-Root installiert, wobei Registrierung und Dateiliste geprüft werden (Checkbox).

- **Fake-Root-Prüfung**: Nach dem Bauen wird das Paket optional in eine temporäre Fake-Root installiert, wobei Registrierung und Dateiliste geprüft werden (Checkbox).

## Warum pkg_convert?

Manche Programme sind nur als `.deb` oder `.rpm` verfügbar, nicht in den Arch-Repos. pkg_convert wandelt sie direkt auf Arch um, ohne AUR und ausschließlich mit offiziellen Arch-Quellen.

1. **Beide Fremdformate in einem Tool.** `.deb` und `.rpm` werden in derselben GUI mit konsistenten Ergebnissen verarbeitet.
2. **Kein zusätzlicher Download-Schritt.** Es nutzt `pkgfile` gegen die lokale Arch-Sync-DB — kein großer Fremdpaket-Cache nötig.
3. **Abhängigkeiten über echte soname-Lookups.** Benötigte Bibliotheken werden über `readelf` + `pkgfile` sowie fremde `Depends`/`Requires`-Metadaten ermittelt, nicht über feste Namenslisten anderer Distributionen.
4. **Natives C++/Qt6, keine Laufzeit-Interpreter-Abhängigkeit.** Eine einzelne native Binary, zur Laufzeit wird kein Python/Bash benötigt.
5. **Integrierte Qt6-GUI** mit 6 Sprachen (DE/EN/FR/ES/TR/PT), Light/Dark, Installationshistorie, kopierbares Log.
6. **Kein AUR-Helfer nötig.** Bauen und Testen laufen aus reinem Quellcode über `makepkg -si`.

### Ehrliche Einschränkungen

- Kein `.INSTALL`-Skript: Icon- und Desktop-Caches werden nicht automatisch aktualisiert; eine konvertierte App erscheint eventuell erst nach `gtk-update-icon-cache` + `update-desktop-database` und/oder einer KDE-Menü-Aktualisierung (`kbuildsycoca6 --noincremental` oder erneutem Anmelden) im Menü.
- Fremdpaketnamen ohne Eintrag in der Zuordnungstabelle werden als nicht zugeordnet gemeldet, statt geraten zu werden.
- `makepkg` entfernt standardmäßig Symbole aus Binaries; funktional identisch mit einer 1:1-Kopie anderer Tools, nur kleiner.
- `pkgname` trägt ein Versionssuffix, z. B. `program-1.99.16`.
- `pkgfile` ist auf eine aktuelle lokale Sync-DB angewiesen; führen Sie `pacman -Sy` aus, wenn die Zuordnungen veraltet wirken.

## Bauen & Installieren (aus Quellcode, ohne AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Danach erscheint **Paket Converter** im KDE-Menü (Kategorie: Dienstprogramme / Paketverwaltung).

Die vollständige Dokumentation (Warum? / Verwendung / Hinweise / Abhängigkeiten) befindet sich in der oben verlinkten sprachspezifischen README.

![SattNEK Logo](created_by_sattnek.png)
