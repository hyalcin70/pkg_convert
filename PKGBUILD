# Maintainer: Hakan Yalcin
pkgname=pkg_convert
pkgver=1.0.0
pkgrel=1
pkgdesc="Converts .deb/.rpm/.AppImage packages into installable Arch-Linux packages (native Qt6 GUI)"
arch=('x86_64')
url="https://github.com/hyalcin70/pkg_convert"
license=('GPL3')
depends=('qt6-base' 'pacman' 'file' 'binutils' 'cpio' 'libarchive')
optdepends=(
  'rpmextract: for RPM sources (or rpmtools)'
)
makedepends=('qt6-base')
source=("pkg_convert_gui.cpp"
        "pkg_convert_gui.pro"
        "pkg_convert.desktop"
        "pkg_convert.svg"
        "created_by_sattnek.png"
        "lang_de.cpp"
        "lang_en.cpp"
        "lang_fr.cpp"
        "lang_es.cpp"
        "lang_tr.cpp"
        "lang_pt.cpp")
sha256sums=('07162198be988650eb9c73834a0ca9820cc18f9d6fa6104dd66ef53ed25c3a20'
            'f4eab89ccafa55fbf3a72bcaed4ce5b262200b92403c6a4595dee7bbb2873358'
            'bd8f98bdc2ee2748520d4df9099678898aabed9d800d691eba307479bc274b1c'
            '1c35318b13f7f32e5921bd4e0de0669202e8ec618075312e1eb60de41bcf294d'
            'f9f56f750c0da701623ea8a1f28b5c3e7f836ee5f178e4d7ec484f95cf0b4996'
            '431f6969f81795bfe7234c16e73e0a606e6eaa68ce9ec1d30fe66da8fad36d40'
            '391b19d257dd1f80920854001b68afc3904d6f4b31f6423dbf2dd46d997270b9'
            '1076fc657e56f0545a5598ea5f304487b1f73f81b987b2656ee395b2988b57d4'
            '8aea02825d678076cc2f24d4df3b0ad4dee0ab7f9b76ca96f958f71fc783c70a'
            'f1e7a1bcef38ef06197497e226f76d0ce57694a68d4e92ec52e02392c1d53e09'
            'a9f69337ff86bf4ba0bfd2c3073e10939e645fd12f76300d984e0a1f85d95dc2')

build() {
  cd "$srcdir"
  qmake6 pkg_convert_gui.pro
  make
}

package() {
  cd "$srcdir"
  # Binary
  install -Dm755 pkg_convert_gui "$pkgdir/usr/bin/pkg_convert_gui"
  # Branding image (created by SattNEK)
  install -Dm644 created_by_sattnek.png "$pkgdir/usr/share/pkg_convert/created_by_sattnek.png"
  # .desktop for KDE menu
  install -Dm644 pkg_convert.desktop "$pkgdir/usr/share/applications/pkg_convert.desktop"
  # Icon (hicolor theme, as expected by KDE)
  install -Dm644 pkg_convert.svg "$pkgdir/usr/share/icons/hicolor/scalable/apps/pkg_convert.svg"
}
