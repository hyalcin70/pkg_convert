# Changelog

## 1.0.0-2 (14. November 2026)

### Behoben
- `.PKGINFO` enthielt fremde Sonames (z. B. `libxkbcommon.so.0()(64bit)`),
  die pacman nicht auflösen konnte → jetzt stehen nur echte Arch-Pakete in
  `depend =`, `pacman -U` funktioniert zuverlässig.
- Mitgelieferte Bibliotheken wurden wegen eines Escaping-Bugs in
  `find -printf '%f\\n'` nicht erkannt → eigene Libs werden nicht mehr als
  Abhängigkeit gelistet.
- Bei mehreren pkgfile-Treffern wurde der erste Treffer genommen
  (z. B. `nsight-compute` statt `qt6-base`) → jetzt gewinnt der namensbeste
  Treffer (Token-Abgleich, offizielle Repos zuerst).

### Hinzugefügt
- Fremd-`Depends`/`Requires` aus den Paketmetadaten werden zusätzlich zum
  `readelf`-NEEDED-Scan ausgewertet — auch per `dlopen` geladene
  Bibliotheken (X11, Wayland, Vulkan) werden als echte Abhängigkeiten
  aufgelöst.
- Provider-Wahl über Namens-Score mit Token-Matching.
- Laufzeit-Abhängigkeiten `pkgfile` und `polkit`.

### Geändert
- Installation/Deinstallation läuft über `pkexec` (Polkit-Dialog) statt
  `sudo -S`.
- Alle READMEs in 7 Sprachen auf den aktuellen Stand gebracht.
