# Paket Converter

Una herramienta nativa de C++/Qt6 que convierte paquetes `.deb` y
`.rpm` en paquetes **Arch Linux** instalables (`.pkg.tar.zst`) — con
detección real de dependencias, instalación automática de bibliotecas
desde los repos y un historial de instalación persistente.

> ⚠️ **Solo para distribuciones basadas en Arch.** Este proyecto es
> exclusivamente para distribuciones **basadas en Arch Linux**
> (Arch, Manjaro, EndeavourOS, …). Las solicitudes o problemas sobre
> otras distribuciones (Debian/Ubuntu, Fedora, openSUSE, …) **no**
> serán respondidos — la herramienta genera paquetes `.pkg.tar.zst`,
> que solo funcionan en sistemas basados en Arch.

## ¿Por qué?

Algunos programas (juegos, herramientas especiales) solo están
disponibles como `.deb` (Debian/Ubuntu) o `.rpm` (Fedora/openSUSE), no
en los repos de Arch. Esta herramienta los convierte sin AUR — usando
solo fuentes oficiales de Arch.

## Características

- **deb/rpm → Arch** : extrae, detecta bibliotecas necesarias vía
  `readelf` + `pkgfile` (soname exacto, sin tablas adivinadas)
- **Instalación auto** de dependencias vía `pacman -S --asdeps`
- **Ruta del binario** : Los ejecutables de los programas/juegos se mueven a `/usr/bin/` para que estén en el `PATH` de Arch.
- **Aviso** para paquetes de solo datos (sin ejecutable)
- **Ventana de pista** al instalar si faltan paquetes de datos
  adicionales (`-data`, `-common`)
- **Registro copiable**, historial de instalación persistente
- **Alternador Claro/Oscuro** (por defecto: claro)

## ¿Por qué pkg_convert?

pkg_convert sigue un enfoque propio para formatos de paquetes
externos, pensado para quienes quieren convertir directamente en Arch
sin depender de ayuda del AUR en ese paso.

1. **Una herramienta para ambos formatos.** En vez de combinar
   opciones de un solo formato, pkg_convert trabaja con **`.deb` y
   `.rpm`** desde la misma GUI y con estructura de paquete coherente.
2. **Base de datos local de Arch en vez de cachés externas grandes.**
   Usa `pkgfile` contra tu sync DB local — sin descargas masivas ni
   servicios de actualización aparte.
3. **Dependencias por soname real.** Se detectan con `readelf` +
   `pkgfile`, no por tablas de nombres fijas de otras distribuciones.
4. **C++/Qt6 nativo, sin intérprete en runtime.** Un solo binario,
   sin Python/Bash durante la ejecución.
5. **GUI Qt6 integrada** con multilenguaje, claro/oscuro, historial
   de instalaciones y registro copiable.
6. **Sin helper del AUR para instalar.** Build y test desde fuente
   con `makepkg -si`.

### Limitaciones honestas

- Aún sin script `.INSTALL` para refresco automático de caché de
  iconos; los iconos del menú pueden requerir `gtk-update-icon-cache`
  + `update-desktop-database` manual.
- `makepkg` quita símbolos por defecto; funcionalmente igual a una
  copia 1:1, solo más pequeño.
- `pkgname` lleva sufijo de versión, ej. `program-1.99.16`.
- `pkgfile` necesita una sync DB local actualizada; ejecuta
  `pacman -Sy` si las correspondencias parecen obsoletas.

## Construir e instalar (desde fuentes, sin AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Después **Paket Converter** aparece en el menú KDE
(categoría: Utilidad / Gestión de paquetes).

## Uso

1. **Examinar** → seleccionar un archivo `.deb` o `.rpm`
2. **Construir paquete** (o «Paquete + Fuentes»)
3. **Instalar paquete** → introducir contraseña, listo

## Notas

- Algunos proyectos dividen programas/juegos en programa + paquete `-data`. Si
  faltan gráficos/sonido, convierte también el paquete de datos.
- Bibliotecas solo en **AUR** no se instalan automáticamente — la
  herramienta avisa.

## Dependencias

`qt6-base` (proporciona `qmake6`), `pacman`, `file`, `binutils`,
`cpio`, `libarchive`
