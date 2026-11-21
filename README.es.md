# Paket Converter

[English](README.md) | [Deutsch](README.de.md) | [Türkçe](README.tr.md) | [Español](README.es.md) | [Français](README.fr.md)

> **Estado Alfa:** Este proyecto se encuentra actualmente en fase de pruebas activas (Alfa). No se ofrece ningún tipo de soporte, ayuda ni garantía.

**Licencia:** GPL-3.0 con la Commons Clause — gratuito para uso no comercial; el uso comercial solo está permitido con autorización.

**Copyright:** © 2026 Hakan Yalçın. Cualquier uso al margen de esta licencia — especialmente el uso comercial, la venta, la eliminación de los avisos de copyright o de licencia, o presentar el software como propio — está estrictamente prohibido.

## ¿Qué es pkg_convert?

**pkg_convert** significa **Package Converter** (convertidor de paquetes): una herramienta nativa en C++/Qt6 que convierte paquetes `.deb` y `.rpm` en paquetes instalables de **Arch Linux** (`.pkg.tar.zst`) — con detección real de dependencias, instalación automática de bibliotecas desde los repositorios y un historial de instalación persistente.

> ⚠️ **Solo para distribuciones basadas en Arch.** Este proyecto está destinado exclusivamente a distribuciones **basadas en Arch Linux** (Arch, Manjaro, EndeavourOS, …). Las solicitudes o incidencias relativas a otras distribuciones (Debian/Ubuntu, Fedora, openSUSE, …) **no** serán atendidas: la herramienta genera paquetes `.pkg.tar.zst`, que solo funcionan en sistemas basados en Arch.

## 🆕 Novedades (1.0.0-13)

- **Corrección**: al cargar un archivo nuevo, ahora se limpia inmediatamente el resultado/lista de dependencias anterior en lugar de mostrar entradas obsoletas.

- **Integración de escritorio y estabilidad**: se conservan los enlaces simbólicos en los paquetes, los logos de las aplicaciones aparecen directamente en el menú (automatización de iconos), la caché del menú se actualiza tras la instalación, la verificación de la falsa raíz (fake root) es más robusta y se corrigieron las etiquetas del tema en alemán.

- **Revisión completa de la traducción al turco**: todos los textos usan ahora caracteres turcos correctos (ğ ü ö ç ş ı İ).

- **Verificación de falsa raíz tras la compilación**: el paquete terminado se instala opcionalmente en una falsa raíz temporal (casilla de verificación); el registro y la lista de archivos se verifican automáticamente.

- Los metadatos externos `Depends`/`Requires` ahora se evalúan además del análisis NEEDED de readelf — las bibliotecas cargadas mediante dlopen (X11, Wayland, Vulkan) pasan a ser dependencias reales.
- Selección del proveedor por puntuación de nombre (coincidencia de substring + token, repositorios oficiales primero): no más dependencias erróneas de conjuntos como `nsight-compute` en lugar de `qt6-base`.
- `.PKGINFO` contiene solo paquetes reales de Arch → `pacman -U` funciona de forma fiable.
- Corregida la detección de bibliotecas incluidas: los paquetes autónomos ya no enumeran sus propias bibliotecas como dependencias.
- Instalar/desinstalar usa ahora `pkexec` (diálogo de Polkit); nuevas dependencias de ejecución: `pkgfile`, `polkit`.

## 🌐 Idioma

- 🇬🇧 English — [README.en.md](README.en.md)
- 🇩🇪 Deutsch — [README.de.md](README.de.md)
- 🇫🇷 Français — [README.fr.md](README.fr.md)
- 🇪🇸 Español — [README.es.md](README.es.md)
- 🇹🇷 Türkçe — [README.tr.md](README.tr.md)
- 🇵🇹 Português — [README.pt.md](README.pt.md)

---

## Características (resumen)

- **deb/rpm → Arch**: extrae, detecta las bibliotecas requeridas mediante `readelf` + `pkgfile` (soname exacto) y evalúa los metadatos externos `Depends`/`Requires` (también se encuentran las bibliotecas cargadas con dlopen como X11, Wayland o Vulkan)
- **Instalación automática** de las dependencias de los repositorios mediante `pacman -S --asdeps`
- **Mejor proveedor**: si varios paquetes incluyen la misma biblioteca, gana el que tenga mejor puntuación de nombre (coincidencia de substring + token, repositorios oficiales primero) frente a un conjunto arbitrario
- **Ruta de binarios**: los ejecutables de programas/juegos se mueven a `/usr/bin/` para que estén en el `PATH` de Arch.
- **Aviso** para paquetes puramente de datos (sin programa ejecutable)
- **Ventana de sugerencia** al instalar si podrían faltar paquetes de datos adicionales (`-data`, `-common`)
- **Registro copiable**, historial de instalación persistente
- **Claro/Oscuro** conmutable (por defecto: claro), selección de idioma (DE/EN/FR/ES/TR/PT)

- **Verificación de falsa raíz**: tras la compilación, el paquete se instala opcionalmente en una falsa raíz temporal, verificando el registro y la lista de archivos (casilla de verificación).

- **Verificación de falsa raíz**: tras la compilación, el paquete se instala opcionalmente en una falsa raíz temporal, verificando el registro y la lista de archivos (casilla de verificación).

## ¿Por qué pkg_convert?

Algunos programas solo están disponibles como `.deb` o `.rpm`, no en los repositorios de Arch. pkg_convert los convierte directamente en Arch sin AUR, usando únicamente fuentes oficiales de Arch.

1. **Ambos formatos externos en una sola herramienta.** `.deb` y `.rpm` se gestionan desde la misma interfaz gráfica con resultados coherentes.
2. **Sin paso de descarga adicional.** Utiliza `pkgfile` con tu base de datos local de sincronización de Arch — no se necesita una gran caché de paquetes externos.
3. **Dependencias mediante búsquedas reales de soname.** Las bibliotecas requeridas se identifican con `readelf` + `pkgfile` más los metadatos externos `Depends`/`Requires`, no con tablas de nombres fijas de otras distribuciones.
4. **C++/Qt6 nativo, sin dependencia de intérprete en tiempo de ejecución.** Un único binario nativo, sin necesidad de Python/Bash en tiempo de ejecución.
5. **Interfaz gráfica Qt6 integrada** con 6 idiomas (DE/EN/FR/ES/TR/PT), claro/oscuro, historial de instalación y registro copiable.
6. **No se requiere gestor de AUR.** La compilación y las pruebas se ejecutan desde el código fuente plain mediante `makepkg -si`.

### Limitaciones honestas

- No hay script `.INSTALL`: las cachés de iconos y de archivos de escritorio no se actualizan automáticamente; una aplicación convertida puede aparecer en el menú solo después de `gtk-update-icon-cache` + `update-desktop-database` y/o una actualización del menú de KDE (`kbuildsycoca6 --noincremental` o volver a iniciar sesión).
- Los nombres de paquetes externos sin una entrada en la tabla de correspondencias se informan como no asignados en lugar de adivinarse.
- `makepkg` elimina los símbolos de los binarios por defecto; funcionalmente es igual que una copia 1:1 de otras herramientas, solo que más pequeño.
- `pkgname` incluye un sufijo de versión, p. ej. `program-1.99.16`.
- `pkgfile` depende de una base de datos de sincronización local actualizada; ejecuta `pacman -Sy` si las correspondencias parecen obsoletas.

## Compilación e instalación (desde el código fuente, sin AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Después, **Paket Converter** aparece en el menú de KDE (categoría: Utilidad / Gestión de paquetes).

La documentación completa (¿Por qué? / Uso / Notas / Dependencias) está en el README del idioma correspondiente enlazado arriba.

![SattNEK Logo](created_by_sattnek.png)
