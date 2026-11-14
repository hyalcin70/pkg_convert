# Paket Converter

![SattNEK Logo](../created_by_sattnek.png)

**Licencia:** GPL-3.0 con la cláusula Commons — uso no comercial libre; el uso comercial solo con autorización previa.

**Derechos de autor:** © 2026 Hakan Yalçın. Cualquier uso fuera de esta licencia — especialmente el uso comercial, la venta, la eliminación de avisos de derechos de autor o de licencia, o apropiarse del software — está estrictamente prohibido.

## ¿Qué es pkg_convert?

**pkg_convert** significa **Package Converter** (convertidor de paquetes):
una herramienta nativa de C++/Qt6 que convierte paquetes `.deb` y `.rpm`
en paquetes **Arch Linux** instalables (`.pkg.tar.zst`) — con detección
real de dependencias, instalación automática de bibliotecas desde los
repos y un historial de instalación persistente.

> ⚠️ **Solo para distribuciones basadas en Arch.** Este proyecto es
> exclusivamente para distribuciones **basadas en Arch Linux**
> (Arch, Manjaro, EndeavourOS, …). Las solicitudes o problemas sobre
> otras distribuciones (Debian/Ubuntu, Fedora, openSUSE, …) **no**
> serán respondidos — la herramienta genera paquetes `.pkg.tar.zst`,
> que solo funcionan en sistemas basados en Arch.

## 🆕 Novedades (1.0.0-2)

- Los metadatos `Depends`/`Requires` extranjeros se evalúan además del
  escaneo readelf NEEDED: las bibliotecas cargadas con dlopen (X11,
  Wayland, Vulkan) pasan a ser dependencias reales.
- Selección de proveedor por puntuación de nombre (subcadena +
  coincidencia de tokens, repos oficiales primero): se acabaron las
  dependencias erróneas como `nsight-compute` en vez de `qt6-base`.
- `.PKGINFO` solo contiene paquetes Arch reales → `pacman -U` funciona
  de forma fiable.
- Detección de bibliotecas incluidas corregida: los paquetes autónomos
  ya no listan sus propias libs como dependencias.
- Instalar/desinstalar usa `pkexec` (diálogo de Polkit); nuevas
  dependencias de runtime: `pkgfile`, `polkit`.

## ¿Por qué?

Algunos programas (juegos, herramientas especiales) solo están
disponibles como `.deb` (Debian/Ubuntu) o `.rpm` (Fedora/openSUSE), no
en los repos de Arch. Esta herramienta los convierte sin AUR — usando
solo fuentes oficiales de Arch.

## Características

- **deb/rpm → Arch** : extrae, detecta bibliotecas necesarias vía
  `readelf` + `pkgfile` (soname exacto, sin tablas adivinadas)
  y evalúa los metadatos `Depends`/`Requires` extranjeros (también
  bibliotecas cargadas con dlopen, como X11, Wayland o Vulkan)
- **Instalación auto** de dependencias vía `pacman -S --asdeps`
- **Mejor proveedor:** Si varios paquetes incluyen la misma biblioteca,
  una puntuación por nombre (subcadena + coincidencia de tokens, repos
  oficiales primero) evita elegir un paquete arbitrario
- **Ruta del binario** : Los ejecutables de los programas/juegos se mueven a `/usr/bin/` para que estén en el `PATH` de Arch.
- **Aviso** para paquetes de solo datos (sin ejecutable)
- **Ventana de pista** al instalar si faltan paquetes de datos
  adicionales (`-data`, `-common`)
- **Registro copiable**, historial de instalación persistente
- **Alternador Claro/Oscuro** (por defecto: claro)

- **Verificación en fake root**: tras compilar, el paquete se instala opcionalmente en un fake root temporal para verificar el registro y la lista de archivos (casilla).

- **Verificación en fake root**: tras compilar, el paquete se instala opcionalmente en un fake root temporal para verificar el registro y la lista de archivos (casilla).

## Diseño

- **Ambos formatos externos:** `.deb` y `.rpm` se gestionan en la
  misma GUI.
- **Búsqueda en Arch:** Las bibliotecas se resuelven con `readelf` +
  `pkgfile` contra tu sync DB local de Arch, más los metadatos
  `Depends`/`Requires` extranjeros.
- **Binarios nativos:** Los ejecutables se colocan en `/usr/bin/` para
  que estén en el `PATH` de Arch; los datos/desktops permanecen
  intactos.
- **Interacción con repos desde la GUI:** Las dependencias pueden
  obtenerse automáticamente con `pacman -S --asdeps`; la instalación y
  desinstalación están disponibles desde la interfaz.
- **Sin dependencia de intérprete en runtime:** Un solo binario
  nativo, sin Python/Bash durante la ejecución.
- **Multilenguaje:** Alemán, inglés, francés, español, turco,
  portugués; claro/oscuro; historial de instalaciones; registro
  copiable.
- **Sin helper del AUR:** Build y test desde fuente con
  `makepkg -si`.

### Limitaciones honestas

- Aún sin script `.INSTALL`: las cachés de iconos y escritorio no se
  refrescan automáticamente; una app convertida puede aparecer en el menú
  solo tras `gtk-update-icon-cache` + `update-desktop-database` y/o un
  refresco del menú KDE (`kbuildsycoca6 --noincremental` o reiniciar
  sesión).
- Los nombres de paquetes extranjeros sin entrada en la tabla se
  reportan como no mapeados en lugar de adivinarse.
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
3. **Instalar paquete** → confirmar el diálogo de Polkit, listo

## Notas

- Algunos proyectos dividen programas/juegos en programa + paquete `-data`. Si
  faltan gráficos/sonido, convierte también el paquete de datos.
- Bibliotecas solo en **AUR** no se instalan automáticamente — la
  herramienta avisa.

## Dependencias

`qt6-base` (proporciona `qmake6`), `pacman`, `file`, `binutils`,
`cpio`, `libarchive`, `pkgfile`, `polkit`
