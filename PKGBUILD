# Maintainer: Hakan Yalcin
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
        "lang/lang_de.cpp"
        "lang/lang_en.cpp"
        "lang/lang_fr.cpp"
        "lang/lang_es.cpp"
        "lang/lang_tr.cpp"
        "lang/lang_pt.cpp")
sha256sums=('50e2292d0c7f9a6d5df0e7a8ab0eea147685f99a43ce13a7e2b8f98cf18a94a6'
            '0eeb19ddb3e008110951eca6bd11224386d6b1920fb30e82d9404774d8662bdb'
            'bd8f98bdc2ee2748520d4df9099678898aabed9d800d691eba307479bc274b1c'
            '1c35318b13f7f32e5921bd4e0de0669202e8ec618075312e1eb60de41bcf294d'
            'e2f6daf8a484ff887fb0cdf0e7f373ddf41df89f75e0e16f638c9e3141b41882'
            '69e4a02359c6c49b1cbf5eaa710171f3cb35de07823103bb28d37c5e9a952757'
            '3024c3cc35e2c6232734858293d463fbb9cc03e334a4bbfc931d5d78afaa46be'
            'db11facbcf8a0a3a14423bf5bbe9a24e852a023425c9cc8d1f2bae2aa46f7155'
            '9690192d8189ab4eeb3e18c31a7223da2e5b0cbc7fb20c79533044e1cde9b8a4'
            '57912fc00d74ab275550927bfe7b50c6fab574ba359786c6d8a4de6f4ad459f0')

build() {
  cd "$srcdir"
  qmake6 pkg_convert_gui.pro
  make
}

package() {
  cd "$srcdir"
  # Binary
  install -Dm755 pkg_convert_gui "$pkgdir/usr/bin/pkg_convert_gui"
  # .desktop for KDE menu
  install -Dm644 pkg_convert.desktop "$pkgdir/usr/share/applications/pkg_convert.desktop"
  # Icon (hicolor theme, as expected by KDE)
  install -Dm644 pkg_convert.svg "$pkgdir/usr/share/icons/hicolor/scalable/apps/pkg_convert.svg"
}
