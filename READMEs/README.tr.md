# Paket Converter

![SattNEK Logo](../created_by_sattnek.png)

**Lisans:** GPL-3.0 + Commons Clause — ticari olmayan kullanım özgür; ticari kullanım yalnızca önceden izinle.

**Telif hakkı:** © 2026 Hakan Yalçın. Bu lisansın dışında herhangi bir kullanım — özellikle ticari kullanım, satış, telif veya lisans bildirimlerinin kaldırılması ya da yazılımı kendinize mal etme — kesinlikle yasaktır.

## pkg_convert nedir?

**pkg_convert**, **Package Converter** (paket dönüştürücü) anlamına gelir:
`.deb` ve `.rpm` paketlerini kurulabilir **Arch Linux** paketlerine
(`.pkg.tar.zst`) çeviren yerel bir C++/Qt6 aracıdır — gerçek bağımlılık
tespiti, kütüphanelerin repo'dan otomatik kurulumu ve kalıcı kurulum
geçmişi ile.

> ⚠️ **Yalnızca Arch tabanlı dağıtımlar.** Bu proje yalnızca **Arch
> Linux tabanlı** dağıtımlar (Arch, Manjaro, EndeavourOS, …) içindir.
> Diğer dağıtımlarla (Debian/Ubuntu, Fedora, openSUSE, …) ilgili
> istekler veya sorunlar **yanıtlanmaz** — araç yalnızca Arch tabanlı
> sistemlerde çalışan `.pkg.tar.zst` paketleri üretir.

## 🆕 Yenilikler (1.0.0-5)

- **Türkçe çevirinin düzeltilmesi**: tüm metinler artık doğru Türkçe karakterleri kullanıyor (ğ ü ö ç ş ı İ).

- **Derlemeden sonra sanal kök doğrulaması**: bitmiş paket isteğe bağlı olarak geçici bir sanal kökte kurulur (onay kutusu); kayıt ve dosya listesi otomatik doğrulanır.

- Yabancı `Depends`/`Requires` üstverileri artık readelf NEEDED taramasına
  ek olarak değerlendiriliyor — dlopen ile yüklenen kütüphaneler (X11,
  Wayland, Vulkan) gerçek bağımlılıklara dönüşüyor.
- Sağlayıcı seçimi ad skoruyla (alt dizge + jeton eşleşmesi, önce resmi
  depolar): `qt6-base` yerine `nsight-compute` gibi hatalı bağımlılıklar
  bitti.
- `.PKGINFO` yalnızca gerçek Arch paketleri içeriyor → `pacman -U`
  güvenilir çalışıyor.
- Gömülü kütüphane algılaması düzeltildi: kendi kendine yeten paketler
  kendi kütüphanelerini bağımlılık olarak listelemiyor.
- Kur/kaldır artık `pkexec` (Polkit iletişim kutusu) kullanıyor; yeni
  çalışma zamanı bağımlılıkları: `pkgfile`, `polkit`.

## Neden?

Bazı programlar (oyunlar, özel araçlar) yalnızca `.deb`
(Debian/Ubuntu) veya `.rpm` (Fedora/openSUSE) olarak mevcuttur, Arch
depolarında yoktur. Bu araç onları AUR'suz çevirir — yalnızca resmi
Arch kaynaklarını kullanarak.

## Özellikler

- **deb/rpm → Arch** : çıkarır, gereken kütüphaneleri `readelf` +
  `pkgfile` ile bulur (tam soname, tahmin edilen tablolar yok)
  ve yabancı `Depends`/`Requires` üstverilerini değerlendirir
  (dlopen ile yüklenen X11, Wayland veya Vulkan gibi kütüphaneler de
  bulunur)
- **Otomatik kurulum** : repo bağımlılıkları `pacman -S --asdeps` ile
- **En iyi sağlayıcı:** Aynı kütüphane birden fazla pakette varsa, ad
  skoru (alt dizge + jeton eşleşmesi, önce resmi depolar) keyfi bir
  takımın yerine doğru olanı seçer
- **Binary yolu** : Programların/oyunların çalıştırılabilir dosyaları `/usr/bin/` üzerine taşınır, böylece Arch'ın `PATH` içinde yer alır.
- **Uyarı** : yalnızca veri paketlerinde (çalıştırılabilir yok)
- **İpucu penceresi** : kurulumda eksik veri paketleri
  (`-data`, `-common`) varsa
- **Kopyalanabilir günlük**, kalıcı kurulum geçmişi
- **Açık/Koyu** değiştirici (varsayılan: açık)

- **Sanal kök doğrulaması**: derlemeden sonra paket isteğe bağlı olarak geçici bir sanal kökte kurularak kayıt ve dosya listesi doğrulanır (onay kutusu).

## Tasarım

- **İki farklı dış format:** `.deb` ve `.rpm` aynı arayüzde ele alınır.
- **Arch çözümleme:** Kütüphaneler `readelf` + `pkgfile` ile mevcut
  Arch sync DB üzerinden çözümlenir; yabancı `Depends`/`Requires`
  üstverileri de değerlendirilir.
- **Yerel ikili dosyalar:** Çalıştırılabilirler `/usr/bin/` altına
  alınır, veri/desktop dosyalarına dokunulmaz.
- **Depo etkileşimi:** Bağımlılıklar `pacman -S --asdeps` ile
  otomatik kurulabilir; kurulum/kaldırma arayüzden erişilebilir.
- **Runtime yorumlayıcı yok:** Tek yerel ELF; çalışma zamanında
  Python/Bash gerekmez.
- **Çok dilli:** Almanca, İngilizce, Fransızca, İspanyolca, Türkçe,
  Portekizce; açık/koyu; kurulum geçmişi; kopyalanabilir günlük.
- **AUR helper gerekmez:** `makepkg -si` ile kaynak üzerinden kurulum.

### Dürüst sınırlamalar

- Henüz `.INSTALL` betiği yok: ikon ve masaüstü önbellekleri otomatik
  yenilenmez; dönüştürülen bir uygulama `gtk-update-icon-cache` +
  `update-desktop-database` ve/veya KDE menü yenilemesi
  (`kbuildsycoca6 --noincremental` veya yeniden oturum açma) sonrasında
  menüde görünebilir.
- Eşleme tablosunda kaydı olmayan yabancı paket adları, tahmin etmek
  yerine eşlenmemiş olarak bildirilir.
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
3. **Paketi kur** → Polkit ile onayla, tamam

## Notlar

- Bazı projeler oyunları program + `-data` paketi olarak böler. Grafik/
  ses eksikse veri paketini de çevirin.
- Yalnızca **AUR**'da olan kütüphaneler otomatik kurulamaz — araç
  uyarır.

## Bağımlılıklar

`qt6-base` (`qmake6` sağlar), `pacman`, `file`, `binutils`, `cpio`,
`libarchive`, `pkgfile`, `polkit`
