# Maintainer: Hakan Yalçın
pkgname=pkg_convert
pkgver=1.0.0
pkgrel=9
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
    '6d5014742054fde390fa60d2793c8915a3f1135d2edb36b9cd2744c6843c92eb'
    'f4eab89ccafa55fbf3a72bcaed4ce5b262200b92403c6a4595dee7bbb2873358'
    'bd8f98bdc2ee2748520d4df9099678898aabed9d800d691eba307479bc274b1c'
    '1c35318b13f7f32e5921bd4e0de0669202e8ec618075312e1eb60de41bcf294d'
    'f9f56f750c0da701623ea8a1f28b5c3e7f836ee5f178e4d7ec484f95cf0b4996'
    '26ff27b678a92cd24c34a86f70cb356eb983c2664c24bd546d06eb1e43ca2a1c'
    '943a6050a4a487a0bbb605f73da73509f49d8089ff5f072da67bd14afe9eb909'
    '0ffc90e7f50cc5b361fa7f5d8e93539193f1f66ddb9f121e9b0e0e59b9abaf80'
    'd6a1a71b98fff75b11c11aebb29ab6d5a9f2d1069a1f73166767f51b22095190'
    'eccd02999d8e67016ef40c1920f1124df683621aceff0b22e644b7ac719691ab'
    'e0a23d534764a5342865533014aa70fe0ef5e7c6e02c2633db9ff051657f96d6'
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