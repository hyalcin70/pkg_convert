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
sha256sums=('2cda6276748ad4c820c2662705f743e6443a3f472458b767f074fb5809e6d64e'
            'f4eab89ccafa55fbf3a72bcaed4ce5b262200b92403c6a4595dee7bbb2873358'
            'bd8f98bdc2ee2748520d4df9099678898aabed9d800d691eba307479bc274b1c'
            '1c35318b13f7f32e5921bd4e0de0669202e8ec618075312e1eb60de41bcf294d'
            'f9f56f750c0da701623ea8a1f28b5c3e7f836ee5f178e4d7ec484f95cf0b4996'
            'ec1afeae449c29d254bca5c43edeb3a927259f3da5a6c3ac1c8f3f11106c0ef7'
            '79637c11836e43d08d745efd19f0ba000d99eecec5f4b4b82b8a8cd61672747d'
            '3bde98fe70d7da53ba18622a8bfec925fc5ba259ae613c94f37fa68f99634305'
            'e4433a87a314abe1be1ab8b442b251461cea6a11edb88b192bee9836bd4fc3b2'
            '351b0e10b0c948cb7483dc800dfbc7dc79418ea5f1ea6d1a1b8a07c2190ce2e0'
            'ced4a474140e13da1197a818c68f66cf168129cda3606cd0bed015449c3e7315')

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