# Paket Converter

Yerel C++/Qt6 aracıdır; `.deb` ve `.rpm` paketlerini kurulabilir
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
(Debian/Ubuntu) veya `.rpm` (Fedora/openSUSE) olarak mevcuttur, Arch
depolarında yoktur. Bu araç onları AUR'suz çevirir — yalnızca resmi
Arch kaynaklarını kullanarak.

## Özellikler

- **deb/rpm → Arch** : çıkarır, gereken kütüphaneleri `readelf` +
  `pkgfile` ile bulur (tam soname, tahmin edilen tablolar yok)
- **Otomatik kurulum** : repo bağımlılıkları `pacman -S --asdeps` ile
- **Binary yolu** : Programların/oyunların çalıştırılabilir dosyaları `/usr/bin/` üzerine taşınır, böylece Arch'ın `PATH` içinde yer alır.
- **Uyarı** : yalnızca veri paketlerinde (çalıştırılabilir yok)
- **İpucu penceresi** : kurulumda eksik veri paketleri
  (`-data`, `-common`) varsa
- **Kopyalanabilir günlük**, kalıcı kurulum geçmişi
- **Açık/Koyu** değiştirici (varsayılan: açık)

## debtap / rpmtoarch yerine neden pkg_convert?

Başka dönüştürücüler de var (debtap, rpmtoarch). pkg_convert,
kendi çalışma prensibiyle şunları hedefler: Arch üzerinde doğrudan
çalışmak, dönüştürme adımında AUR yardımcılarına bağlı kalmamak.

1. **İki farklı format için tek araç.** Birden fazla tek-format
   çözümü birleşturmek yerine pkg_convert **`.deb` ve `.rpm`**'i tek
   arayüzde, tutarlı paket düzeniyle işler.
2. **Büyük harici cache yerine yerel Arch veritabanı.** `pkgfile`
   kullanır, mevcut Arch sync DB'ye sorgu yapar — büyük indirme yok,
   ayrı bir güncelleme hizmeti yok.
3. **Gerçek soname lookups ile bağımlılık tespiti.** Kütüphaneler
   `readelf` + `pkgfile` ile bulunur, başka dağıtımların sabit
   isim tablolarına bağlı değildir.
4. **C++/Qt6 yerel, runtime yorumlayıcı yok.** Tek bir yerel ELF,
   çalışma zamanında Python/Bash gerekmez.
5. **Entegre Qt6 arayüzü** çok dilli, açık/koyu, kurulum geçmişi ve
   kopyalanabilir günlük ile.
6. **AUR helper gerekmez.** `makepkg -si` ile kaynak üzerinden kurulum.

### Dürüst sınırlamalar

- Henüz ikon önbelleği için `.INSTALL` betiği yok; menü ikonları
  `gtk-update-icon-cache` + `update-desktop-database` ile el ile
  güncellenebilir.
- `makepkg` varsayılan olarak sembolleri çıkarır; işlevsel olarak
  diğer araçların 1:1 kopyasıyla aynıdır, daha küçüktür.
- `pkgname` sürüm son eki taşır, örn. `program-1.99.16`.
- `pkgfile` güncel yerel sync db gerektirir; eşleşmeler eskiyse
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

1. **Gözat** → bir `.deb` veya `.rpm` dosyası seç
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
