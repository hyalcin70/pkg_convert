# Paket Converter

`.deb` ve `.rpm` paketlerini kurulabilir **Arch Linux** paketlerine
(`.pkg.tar.zst`) çeviren, tam C++/Qt6 tabanlı bir araç — gerçek
bağımlılık algılama, kitaplıkların depodan otomatik kurulumu ve kalıcı
bir kurulum geçmişi ile.

## Neden?

Bazı programlar (oyunlar, özel araçlar) yalnızca `.deb` (Debian/Ubuntu)
veya `.rpm` (Fedora/openSUSE) olarak mevcuttur, Arch depolarında yoktur.
Bu araç onları AUR'suz çevirir — yalnızca resmi Arch kaynaklarını kullanır.

## Özellikler

- **deb/rpm → Arch** : çıkartır, gerekli kitaplıkları `readelf` + `pkgfile`
  ile algılar (tam soname, tahmin edilmiş tablolar yok)
- **Otomatik kurulum** : repo bağımlılıkları `pacman -S --asdeps` ile kurulur
- **Binary yolu** : `/usr/games/` → `/usr/bin/` olarak taşınır
- **Uyarı** : saf veri paketleri için (çalıştırılabilir program yok)
- **İpucu penceresi** : kurulum sırasında ek veri paketleri
  (`-data`, `-common`) eksik olabilirse uyarır
- **Kopyalanabilir günlük**, kalıcı kurulum geçmişi
- **Açık/Koyu** düğmesi (varsayılan: açık)

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
2. **Paket oluştur** (veya « Paket + Kaynaklar »)
3. **Paketi kur** → parolayı gir, tamam

## Notlar

- Bazı projeler oyunları program + `-data` paketine böler.
  Başlattıktan sonra grafik/ses eksikse, ilgili veri paketini de çevir.
- Yalnızca **AUR**'da bulunan kitaplıklar (ör. `glc-lib`) otomatik
  kurulamaz — araç uyarır.

## Bağımlılıklar

`qt6-base`, `pacman`, `file`, `binutils`, `cpio`, `libarchive`
(derlemek için `qmake6` dahil).
