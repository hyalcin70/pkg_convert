# Maintainer: Hakan Yalçın
pkgname=pkg_convert
pkgver=1.0.0
pkgrel=1
pkgdesc="Converts .deb/.rpm packages into installable Arch-Linux packages (native Qt6 GUI)"
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
sha256sums=('55d9b55740ba261078669acf2715ee444706a86077560cf717ba7c309181e301'
            'f4eab89ccafa55fbf3a72bcaed4ce5b262200b92403c6a4595dee7bbb2873358'
            'bd8f98bdc2ee2748520d4df9099678898aabed9d800d691eba307479bc274b1c'
            '1c35318b13f7f32e5921bd4e0de0669202e8ec618075312e1eb60de41bcf294d'
            'f9f56f750c0da701623ea8a1f28b5c3e7f836ee5f178e4d7ec484f95cf0b4996'
            '94c093fb8ab53a9dda74cb5c3148fb236020dd7754bd6ceeb744fa54b6b3857b'
            '005f4b23378e850f212b43fea1dc28f51b20463f32e98bb3e4ceb3b70f092832'
            'be807b5a6a995750c0ff8fa67081339f1173de2d722031df0ffc39b3d6e67bf0'
            'd0fd39de32be6bb4bf34198f22a7f106b2ae952acde2e865d1aa5f3877dcc976'
            '36582cf7389a11578d41e8f7462b832b368cd356843e65414da9d1c4ee7e228a'
            'b0b2bdc5ab2e7b50b03644b06ac1536b05245b8673703ffee4b96d8fdfe3a98b')

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
