# Maintainer: Hakan Yalçın
pkgname=pkg_convert
pkgver=1.0.0
pkgrel=4
pkgdesc="Converts .deb/.rpm packages into installable Arch-Linux packages (native Qt6 GUI)"
arch=('x86_64')
url="https://github.com/hyalcin70/pkg_convert"
license=('custom:GPL-3.0-with-Commons-Clause')
depends=('qt6-base' 'pacman' 'file' 'binutils' 'cpio' 'libarchive' 'pkgfile' 'polkit')
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
sha256sums=(
    'fa860aaa157dd1fdc60e87a32a62064b2b3a3df1e54374cba15ae5c980d20031'
    'f4eab89ccafa55fbf3a72bcaed4ce5b262200b92403c6a4595dee7bbb2873358'
    'bd8f98bdc2ee2748520d4df9099678898aabed9d800d691eba307479bc274b1c'
    '1c35318b13f7f32e5921bd4e0de0669202e8ec618075312e1eb60de41bcf294d'
    'f9f56f750c0da701623ea8a1f28b5c3e7f836ee5f178e4d7ec484f95cf0b4996'
    '7f826dab5d66c039bde6cc1bb98b25edfd89d905001ef1bfa48073a0188ece3c'
    'a962d4a8b287d1b5737ef0481ef21aabd348bea4a04413543ff03ea28c9d280c'
    '7ee4d0bfb606a54fe47cf9ab74842ff539e2bd1c12373b7d8a76a88174c9bba8'
    '29931b4d9c871f6bcf75966dedadafb5f9f2e809f9880718ea35f08b5a16573f'
    '3e5c99451be08e669a21d5def854591d3a75c27d54c3cf6fac8929655ed687d2'
    'dfa0b289b2ea13a1aae179116e03b62a40dd46ed7a16727a80e8f30098153cfa'
)

build() {
  cd "$srcdir"
  qmake6 pkg_convert_gui.pro
  make
}

package() {
  cd "$srcdir"
  install -Dm755 pkg_convert_gui "$pkgdir/usr/bin/pkg_convert_gui"
  install -Dm644 created_by_sattnek.png "$pkgdir/usr/share/pkg_convert/created_by_sattnek.png"
  install -Dm644 pkg_convert.desktop "$pkgdir/usr/share/applications/pkg_convert.desktop"
  install -Dm644 pkg_convert.svg "$pkgdir/usr/share/icons/hicolor/scalable/apps/pkg_convert.svg"
}