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
disponibles como `.deb` (Debian/Ubuntu), `.rpm` (Fedora/openSUSE) o `.AppImage`, no
en los repos de Arch. Esta herramienta los convierte sin AUR — usando
solo fuentes oficiales de Arch.

## Características

- **deb/rpm/AppImage → Arch** : extrae, detecta bibliotecas necesarias vía
  `readelf` + `pkgfile` (soname exacto, sin tablas adivinadas)
- **AppImage usa bibliotecas del sistema** : las bibliotecas incluidas
  que Arch ya proporciona se eliminan del paquete, así el programa usa
  las **bibliotecas del sistema actualizadas** (con actualizaciones
  automáticas) en lugar de bibliotecas incluidas obsoletas. Solo las
  bibliotecas sin paquete Arch permanecen como respaldo.
- **Instalación auto** de dependencias vía `pacman -S --asdeps`
- **Ruta del binario** : `/usr/games/` se mueve a `/usr/bin/`
- **Aviso** para paquetes de solo datos (sin ejecutable)
- **Ventana de pista** al instalar si faltan paquetes de datos
  adicionales (`-data`, `-common`)
- **Registro copiable**, historial de instalación persistente
- **Alternador Claro/Oscuro** (por defecto: claro)

## ¿Por qué pkg_convert en vez de debtap / rpmtoarch ?

Existen otros convertidores (debtap, rpmtoarch). Esto es por qué
pkg_convert es mejor para la mayoría:

1. **Una herramienta para los tres formatos.** `debtap` solo maneja
   `.deb` (falla en `.rpm` con *"not a valid deb package"*), mientras
   `rpmtoarch` solo `.rpm`. pkg_convert maneja **los tres**
   (`.deb`, `.rpm`, `.AppImage`) desde la misma GUI con resultados
   idénticos (verificado: mismo hash binario, mismo tamaño para deb/rpm).
2. **Sin base de datos de 1,1 GB.** `debtap` descarga una lista de
   paquetes Debian/Ubuntu (≈1,1 GB de caché, con root). pkg_convert usa
   `pkgfile`, que consulta tu base **local** de Arch — sin gran
   descarga, sin paso de actualización separado.
3. **Detección de dependencias más completa.** En pruebas con
   diferentes programas disponibles tanto en `.deb`, `.rpm` como en `.AppImage`,
   pkg_convert resolvió **11** bibliotecas
   (gtk3, webkit2gtk-4.1, cairo, pango, glib2, libsoup, zlib, glibc,
   gcc-libs, gdk-pixbuf2, libx11) frente a **4** de debtap.
4. **C++/Qt6 nativo, sin runtime Python.** `debtap` es bash + Python
   (incluso llama a `namcap` vía Python). pkg_convert compila a un solo
   ELF de ~130 KB — sin intérprete, sin dependencia Python.
5. **GUI Qt6 integrada con 6 idiomas** (DE/EN/FR/ES/TR/PT), claro/
   oscuro, historial, registro copiable.
6. **Sin AUR.** `debtap`/`rpmtoarch` vienen de AUR. pkg_convert se
   construye desde tu código fuente vía `makepkg -si`.

### Limitaciones honestas

- Aún sin script `.INSTALL` para el caché de iconos (debtap genera uno
  con `gtk-update-icon-cache` + `update-desktop-database`).
- `makepkg` quita símbolos del binario por defecto (≈12 % más pequeño
  que la copia 1:1 de debtap) ; funcionalmente idéntico.
- `pkgname` lleva sufijo de versión (ej. `program-1.99.16`).
- `pkgfile` depende de una base local actualizada ; ejecuta
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

1. **Examinar** → seleccionar un archivo `.deb`, `.rpm` o `.AppImage`
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
