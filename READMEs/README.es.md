# Paket Converter

Una herramienta nativa de C++/Qt6 que convierte paquetes `.deb` y
`.rpm` en paquetes **Arch Linux** instalables (`.pkg.tar.zst`) — con
detección real de dependencias, instalación automática de bibliotecas
desde los repos y un historial de instalación persistente.

## ¿Por qué?

Algunos programas (juegos, herramientas especiales) solo están
disponibles como `.deb` (Debian/Ubuntu) o `.rpm` (Fedora/openSUSE), no
en los repos de Arch. Esta herramienta los convierte sin AUR — usando
solo fuentes oficiales de Arch.

## Características

- **deb/rpm → Arch** : extrae, detecta bibliotecas necesarias vía
  `readelf` + `pkgfile` (soname exacto, sin tablas adivinadas)
- **Instalación automática** de dependencias vía `pacman -S --asdeps`
- **Ruta del binario** : `/usr/games/` se mueve a `/usr/bin/`
- **Aviso** para paquetes de solo datos (sin ejecutable)
- **Ventana de pista** al instalar si faltan paquetes de datos
  adicionales (`-data`, `-common`)
- **Registro copiable**, historial de instalación persistente
- **Alternador Claro/Oscuro** (por defecto: claro)

## ¿Por qué pkg_convert en vez de debtap / rpmtoarch ?

Existen otros convertidores (debtap, rpmtoarch). Esto es por qué
pkg_convert es mejor para la mayoría:

1. **Una herramienta para ambos formatos.** `debtap` solo maneja
   `.deb` (falla en `.rpm` con *"not a valid deb package"*), mientras
   `rpmtoarch` solo `.rpm`. pkg_convert maneja **ambos** desde la
   misma GUI con resultados idénticos (verificado: mismo hash binario,
   mismo tamaño de paquete).
2. **Sin base de datos de 1,1 GB.** `debtap` descarga una lista de
   paquetes Debian/Ubuntu (≈1,1 GB de caché, con root). pkg_convert usa
   `pkgfile`, que consulta tu base **local** de Arch — sin gran
   descarga, sin paso de actualización separado.
3. **Detección de dependencias más completa.** En pruebas con
   diferentes programas disponibles tanto en `.deb` como en `.rpm`,
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
