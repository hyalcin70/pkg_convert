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
sha256sums=('11c9275defe9774472fdcfee7d82b72429aeae5e4768b3fe937ac249722c749c'
            'f4eab89ccafa55fbf3a72bcaed4ce5b262200b92403c6a4595dee7bbb2873358'
            'bd8f98bdc2ee2748520d4df9099678898aabed9d800d691eba307479bc274b1c'
            '1c35318b13f7f32e5921bd4e0de0669202e8ec618075312e1eb60de41bcf294d'
            'f9f56f750c0da701623ea8a1f28b5c3e7f836ee5f178e4d7ec484f95cf0b4996'
            'a23ca227b8db46abbdf878880e8a21c0c90d7ad9a69fb21f913fc19587b93939'
            'e882365c28f2b7533b01cb621b670189f95ded69384862c13bced8c6ce7d7b1f'
            'fc4efc55edc528a2543de509cd5c14ec187b471f34138c475747975e37600ef8'
            '634e48742dde378c4000f29c68a79f443b1ceedfe3a5fc6a54a11fbb3809e5e4'
            '5c9a632c76aa5569c4a24e2201f0128180e3e0d07bfa48ec0d0edf753ba35b5a'
            'af4125b4a755258249d86015896474a4663c960fcb94e881be2a0cd6c842cd1a')

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
