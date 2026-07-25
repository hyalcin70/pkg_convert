# Maintainer: Hakan Yalcin
pkgname=pkg_convert
pkgver=1.0.0
pkgrel=1
pkgdesc="Konvertiert .deb/.rpm-Pakete in installierbare Arch-Linux-Pakete (native Qt6-GUI)"
arch=('x86_64')
url="https://github.com/hyalcin70/pkg_convert"
license=('GPL3')
depends=('qt6-base' 'pacman' 'file' 'binutils' 'cpio' 'libarchive')
optdepends=(
  'rpmextract: für RPM-Quellen (oder rpmtools)'
)
makedepends=('qt6-base')
source=("pkg_convert_gui.cpp"
        "pkg_convert_gui.pro"
        "pkg_convert.desktop"
        "pkg_convert.svg")
sha256sums=('c5ed699d3a1a10c518479f781334c7dc6ce09f647953f1c27ddfad86d27cb675'
            '35246be3d5be89566d6ae4597975df9e243185031672e9ceb81f4debfc8fbcee'
            'bd8f98bdc2ee2748520d4df9099678898aabed9d800d691eba307479bc274b1c'
            '1c35318b13f7f32e5921bd4e0de0669202e8ec618075312e1eb60de41bcf294d')

build() {
  cd "$srcdir"
  qmake6 pkg_convert_gui.pro
  make
}

package() {
  cd "$srcdir"
  # Binary
  install -Dm755 pkg_convert_gui "$pkgdir/usr/bin/pkg_convert_gui"
  # .desktop für KDE-Menü
  install -Dm644 pkg_convert.desktop "$pkgdir/usr/share/applications/pkg_convert.desktop"
  # Icon (hicolor-Thema, wie KDE es erwartet)
  install -Dm644 pkg_convert.svg "$pkgdir/usr/share/icons/hicolor/scalable/apps/pkg_convert.svg"
}
