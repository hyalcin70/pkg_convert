# Paket Converter

Yerel C++/Qt6 aracıdır; `.deb`, `.rpm` ve `.AppImage` paketlerini kurulabilir
**Arch Linux** paketlerine (`.pkg.tar.zst`) çevirir — gerçek
bağımlılık tespiti, kütüphanelerin repo'dan otomatik kurulumu ve
kalıcı kurulum geçmişi ile.

> ⚠️ **Yalnızca Arch tabanlı dağıtımlar.** Bu proje yalnızca **Arch
> Linux tabanlı** dağıtımlar (Arch, Manjaro, EndeavourOS, …) içindir.
> Diğer dağıtımlarla (Debian/Ubuntu, Fedora, openSUSE, …) ilgili
> istekler veya sorunlar **yanıtlanmaz** — araç yalnızca Arch tabanlı
> sistemlerde çalışan `.pkg.tar.zst` paketleri üretir.

## Neden?

Bazı programlar (oyunlar, özel araçlar) yalnızca `.deb`
(Debian/Ubuntu), `.rpm` (Fedora/openSUSE) veya `.AppImage` olarak mevcuttur, Arch
depolarında yoktur. Bu araç onları AUR'suz çevirir — yalnızca resmi
Arch kaynaklarını kullanarak.

## Özellikler

- **deb/rpm/AppImage → Arch** : çıkarır, gereken kütüphaneleri `readelf` +
  `pkgfile` ile bulur (tam soname, tahmin edilen tablolar yok)
- **AppImage sistem kütüphanelerini kullanır** : Arch'ın zaten sunduğu
  gömülü kütüphaneler paketten çıkarılır, böylece program **güncel
  sistem kütüphanelerini** (otomatik güncellemelerle) kullanır, eski
  gömülü kütüphaneleri değil. Yalnızca Arch paketi olmayan kütüphaneler
  yedek olarak kalır.
- **Otomatik kurulum** : repo bağımlılıkları `pacman -S --asdeps` ile
- **Binary yolu** : `/usr/games/` → `/usr/bin/` taşınır
- **Uyarı** : yalnızca veri paketlerinde (çalıştırılabilir yok)
- **İpucu penceresi** : kurulumda eksik veri paketleri
  (`-data`, `-common`) varsa
- **Kopyalanabilir günlük**, kalıcı kurulum geçmişi
- **Açık/Koyu** değiştirici (varsayılan: açık)

## debtap / rpmtoarch yerine neden pkg_convert?

Başka dönüştürücüler de var (debtap, rpmtoarch). İşte pkg_convert'in
çoğu kullanıcı için neden daha iyi olduğu:

1. **Üç biçim için tek araç.** `debtap` yalnızca `.deb` ile
   çalışır (`.rpm`'de sert şekilde *"not a valid deb package"* der),
   `rpmtoarch` yalnızca `.rpm`. pkg_convert **üçünü de** (`.deb`,
   `.rpm`, `.AppImage`) aynı arayüzden, aynı sonuçla yapar (doğrulandı:
   aynı binary hash, aynı paket boyutu deb/rpm için).
2. **1,1 GB veritabanı yok.** `debtap`, Debian/Ubuntu paket listesi
   indirir (≈1,1 GB önbellek, root ile). pkg_convert `pkgfile` kullanır
   ve **yerel** Arch repo veritabanını sorgular — büyük indirme yok,
   ayrı güncelleme adımı yok.
3. **Daha eksiksiz bağımlılık tespiti.** Hem `.deb`, `.rpm` hem de `.AppImage`
   olarak verilen farklı programlarla yapılan testlerde pkg_convert
   **11** kütüphane çözdü
   (gtk3, webkit2gtk-4.1, cairo, pango, glib2, libsoup, zlib, glibc,
   gcc-libs, gdk-pixbuf2, libx11) debtap'ın **4**'üne karşı.
   soname eşleşmesi = daha temiz paket.
4. **Yerel C++/Qt6, Python çalışma ortamı yok.** `debtap` bash + Python'dır
   (Python ile `namcap` çağırır bile). pkg_convert tek bir ~130 KB ELF'e
   derlenir — yorumlayıcı yok, Python bağımlılığı yok.
5. **6 dilde entegre Qt6 arayüzü** (DE/EN/FR/ES/TR/PT), açık/koyu,
   kurulum geçmişi, kopyalanabilir günlük.
6. **AUR gerekmez.** `debtap`/`rpmtoarch` AUR'dan gelir. pkg_convert
   kendi kaynağınızdan `makepkg -si` ile derlenir.
7. **AppImage doğru yapılır — eski gömülü kütüphaneler yok.** Çıplak
   bir AppImage kendi (genellikle eski) paylaşılan kütüphanelerini
   getirir ve sistem kütüphaneleri yerine bunları kullanır, böylece
   hiç güvenlik güncellemesi almaz. pkg_convert **Arch'ın zaten
   sunduğu her gömülü `.so`'yu çıkarır** ve gerçek Arch paketlerini
   `depends` olarak yazar. Program böylece güncel sistem
   kütüphanelerini (otomatik `pacman` güncellemeleriyle) kullanır.
   Yalnızca Arch paketi olmayan kütüphaneler yedek olarak gömülü
   kalır. Diğer dönüştürücüler AppImage'ı hiç işlemez.

### Dürüst sınırlamalar

- Henüz ikon önbelleği için `.INSTALL` betiği yok (debtap bunu
  `gtk-update-icon-cache` + `update-desktop-database` ile üretir).
- `makepkg` binary'den sembolleri varsayılan olarak çıkarır (debtap'ın
  1:1 kopyasından ≈12 % küçük) ; işlevsel olarak aynı.
- `pkgname` sürüm son eki taşır (ör. `program-1.99.16`).
- `pkgfile` güncel yerel sync db'ye dayanır ; eşleşmeler eskiyse
  `pacman -Sy` çalıştırın.

## Derleme & Kurulum (kaynaktan, AUR'suz)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Ardından **Paket Converter** KDE menüsünde görünür
(kategori: Yardımcı Program / Paket Yönetimi).

## Kullanım

1. **Gözat** → bir `.deb`, `.rpm` veya `.AppImage` dosyası seç
2. **Paket oluştur** (veya "Paket + Kaynaklar")
3. **Paketi kur** → parolayı gir, tamam

## Notlar

- Bazı projeler oyunları program + `-data` paketi olarak böler. Grafik/
  ses eksikse veri paketini de çevirin.
- Yalnızca **AUR**'da olan kütüphaneler otomatik kurulamaz — araç
  uyarır.

## Bağımlılıklar

`qt6-base` (`qmake6` sağlar), `pacman`, `file`, `binutils`, `cpio`,
`libarchive`
