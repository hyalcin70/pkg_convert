# Paket Converter

Una herramienta nativa C++/Qt6 que convierte paquetes `.deb` y `.rpm` en
paquetes **Arch Linux** instalables (`.pkg.tar.zst`) — con detección real
de dependencias, instalación automática de bibliotecas desde los repositorios
y un historial de instalación persistente.

## ¿Por qué?

Algunos programas (juegos, herramientas especializadas) solo existen como
`.deb` (Debian/Ubuntu) o `.rpm` (Fedora/openSUSE), no en los repos de Arch.
Esta herramienta los convierte sin AUR — solo con fuentes oficiales de Arch.

## Características

- **deb/rpm → Arch** : extrae, detecta las bibliotecas necesarias vía
  `readelf` + `pkgfile` (soname exacto, sin tablas adivinadas)
- **Instalación automática** de dependencias de repo vía `pacman -S --asdeps`
- **Ruta del binario** : `/usr/games/` se mueve a `/usr/bin/`
- **Aviso** para paquetes de datos puros (sin programa ejecutable)
- **Ventana de aviso** al instalar si podrían faltar paquetes de datos
  adicionales (`-data`, `-common`)
- **Registro copiable**, historial de instalación persistente
- **Conmutador Claro/Oscuro** (predeterminado: claro)

## Compilar e instalar (desde el código fuente, sin AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Después **Paket Converter** aparece en el menú de KDE
(categoría: Utilidad / Gestión de paquetes).

## Uso

1. **Examinar** → elige un archivo `.deb` o `.rpm`
2. **Construir paquete** (o « Paquete + Fuentes »)
3. **Instalar paquete** → introduce la contraseña, listo

## Notas

- Algunos proyectos dividen los juegos en programa + paquete `-data`.
  Si faltan gráficos/sonido tras iniciar, convierte también el
  paquete de datos correspondiente.
- Las bibliotecas que solo existen en **AUR** (p.ej. `glc-lib`) no
  pueden instalarse automáticamente — la herramienta avisa.

## Dependencias

`qt6-base` (incluye `qmake6` para compilar), `pacman`, `file`, `binutils`, `cpio`, `libarchive`
