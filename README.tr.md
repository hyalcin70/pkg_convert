# Paket Converter

[English](README.md) | [Deutsch](README.de.md) | [Türkçe](README.tr.md) | [Español](README.es.md) | [Français](README.fr.md)

> **Alfa Durumu:** Bu proje şu anda aktif test aşamasındadır (Alfa). Herhangi bir destek, yardım veya garanti sağlanmamaktadır.

**Lisans:** GPL-3.0, Commons Clause ile — ticari olmayan kullanım ücretsizdir; ticari kullanım yalnızca izinle mümkündür.

**Telif hakkı:** © 2026 Hakan Yalçın. Bu lisansın dışında herhangi bir kullanım — özellikle ticari kullanım, satış, telif hakkı veya lisans bildirimlerinin kaldırılması ya da yazılımı kendinize mal etme — kesinlikle yasaktır.

## pkg_convert nedir?

**pkg_convert**, **Package Converter** (Paket Dönüştürücü) anlamına gelir:
`.deb` ve `.rpm` paketlerini kurulabilir **Arch Linux** paketlerine
(`.pkg.tar.zst`) çeviren yerel bir C++/Qt6 aracıdır — gerçek bağımlılık
tespiti, kütüphanelerin depolarardan otomatik kurulumu ve kalıcı kurulum
geçmişi ile.

> ⚠️ **Yalnızca Arch tabanlı dağıtımlar.** Bu proje yalnızca **Arch
> Linux tabanlı** dağıtımlar (Arch, Manjaro, EndeavourOS, …) içindir.
> Diğer dağıtımlarla (Debian/Ubuntu, Fedora, openSUSE, …) ilgili
> istekler veya sorunlar **yanıtlanmaz** — araç yalnızca Arch tabanlı
> sistemlerde çalışan `.pkg.tar.zst` paketleri üretir.

## 🆕 Yenilikler (1.0.0-13)

- **Düzeltme**: yeni bir dosya yüklendiğinde önceki sonuç/bağımlılık listesi hemen temizlenir; eski kayıtlar gösterilmez.

- **Masaüstü entegrasyonu ve kararlılık**: sembolik bağlantılar paketlerde korunur, uygulama logoları doğrudan menüde görünür (ikon otomasyonu), kurulumdan sonra menü önbelleği yenilenir, sanal kök doğrulaması daha sağlam hale getirildi, Almanca tema etiketleri düzeltildi.

- **Türkçe çeviri düzenlemesi**: tüm metinler artık doğru Türkçe karakterleri kullanıyor (ğ ü ö ç ş ı İ).

- **Derlemeden sonra sanal kök doğrulaması**: bitmiş paket isteğe bağlı olarak geçici bir sanal köke kurulur (onay kutusu); kayıt ve dosya listesi otomatik olarak doğrulanır.

- Yabancı `Depends`/`Requires` üstverileri artık readelf NEEDED taramasına
  ek olarak değerlendiriliyor — dlopen ile yüklenen kütüphaneler (X11,
  Wayland, Vulkan) gerçek bağımlılıklara dönüşüyor.
- Sağlayıcı seçimi ad skoruyla (alt dize + jeton eşleşmesi, önce resmi
  depolar): `qt6-base` yerine `nsight-compute` gibi paketlerden gelen
  yanlış bağımlılıklar sona erdi.
- `.PKGINFO` yalnızca gerçek Arch paketleri içeriyor → `pacman -U`
  güvenilir şekilde çalışıyor.
- Gömülü kütüphane algılaması düzeltildi: kendi kendine yeten paketler
  kendi kütüphanelerini bağımlılık olarak listelemiyor.
- Kurulum/kaldırma artık `pkexec` kullanıyor (Polkit iletişim kutusu); yeni
  çalışma zamanı bağımlılıkları: `pkgfile`, `polkit`.

## 🌐 Dil

- 🇬🇧 İngilizce — [README.en.md](README.en.md)
- 🇩🇪 Almanca — [README.de.md](README.de.md)
- 🇫🇷 Fransızca — [README.fr.md](README.fr.md)
- 🇪🇸 İspanyolca — [README.es.md](README.es.md)
- 🇹🇷 Türkçe — [README.tr.md](README.tr.md)
- 🇵🇹 Portekizce — [README.pt.md](README.pt.md)

---

## Özellikler (kısaca)

- **deb/rpm → Arch**: paketi çıkarır, gereken kütüphaneleri `readelf` +
  `pkgfile` ile (tam soname) tespit eder ve yabancı
  `Depends`/`Requires` üstverilerini değerlendirir (dlopen ile yüklenen
  X11, Wayland veya Vulkan gibi kütüphaneler de bulunur)
- **Otomatik kurulum**: depo bağımlılıkları `pacman -S --asdeps` ile kurulur
- **En iyi sağlayıcı**: aynı kütüphaneyi birden fazla paket sağlıyorsa, ad
  skoru (alt dize + jeton eşleşmesi, önce resmi depolar) rastgele bir
  paket yerine doğru olanı seçer
- **İkili dosya yolu**: programlardan/oyunlardan gelen çalıştırılabilir
  dosyalar `/usr/bin/` altına taşınır, böylece Arch'ın `PATH` içinde yer alır.
- **Uyarı**: yalnızca veri paketlerinde (çalıştırılabilir program yoksa)
- **İpucu penceresi**: kurulum sırasında ek veri paketlerinin
  (`-data`, `-common`) eksik olabileceği belirtilir
- **Kopyalanabilir günlük**, kalıcı kurulum geçmişi
- **Açık/Koyu** değiştirici (varsayılan: açık), dil seçimi (DE/EN/FR/ES/TR/PT)

- **Sanal kök doğrulaması**: derlemeden sonra paket isteğe bağlı olarak geçici bir sanal köke kurularak kayıt ve dosya listesi doğrulanır (onay kutusu).

- **Sanal kök doğrulaması**: derlemeden sonra paket isteğe bağlı olarak geçici bir sanal köke kurularak kayıt ve dosya listesi doğrulanır (onay kutusu).

## Neden pkg_convert?

Bazı programlar yalnızca `.deb` veya `.rpm` olarak mevcuttur, Arch
depolarında bulunmaz. pkg_convert bunları AUR olmadan, yalnızca resmi
Arch kaynaklarını kullanarak doğrudan Arch üzerinde çevirir.

1. **İki yabancı biçim tek araçta.** `.deb` ve `.rpm`, tutarlı sonuçlarla
   aynı arayüzde ele alınır.
2. **Ekstra indirme adımı yok.** Yerel Arch senkronizasyon veritabanına
   karşı `pkgfile` kullanır — büyük bir yabancı paket önbelleği gerekmez.
3. **Gerçek soname aramalarıyla bağımlılıklar.** Gerekli kütüphaneler
   `readelf` + `pkgfile` ve yabancı `Depends`/`Requires` üstverileriyle
   tespit edilir; diğer dağıtımlara ait sabit ad tabloları kullanılmaz.
4. **Yerel C++/Qt6, çalışma zamanı yorumlayıcı bağımlılığı yok.** Tek bir
   yerel ikili dosya; çalışma zamanında Python/Bash gerekmez.
5. **Tümleşik Qt6 arayüzü**, 6 dil (DE/EN/FR/ES/TR/PT), açık/koyu tema,
   kurulum geçmişi, kopyalanabilir günlük.
6. **AUR yardımcı programı gerekmez.** Derleme ve test, düz kaynak üzerinden
   `makepkg -si` ile yapılır.

### Dürüst sınırlamalar

- `.INSTALL` betiği yok: ikon ve masaüstü önbellekleri otomatik
  yenilenmez; dönüştürülen bir uygulama ancak `gtk-update-icon-cache` +
  `update-desktop-database` ve/veya KDE menü yenilemesi
  (`kbuildsycoca6 --noincremental` veya yeniden oturum açma) sonrasında
  menüde görünebilir.
- Eşleme tablosunda kaydı olmayan yabancı paket adları, tahmin edilmek
  yerine eşlenmemiş olarak bildirilir.
- `makepkg` varsayılan olarak ikilileri sembollerinden arındırır; işlevsel
  olarak diğer araçların 1:1 kopyasıyla aynıdır, sadece daha küçüktür.
- `pkgname` sürüm son eki taşır, örn. `program-1.99.16`.
- `pkgfile`, güncel bir yerel senkronizasyon veritabanına dayanır;
  eşleşmeler eski görünüyorsa `pacman -Sy` komutunu çalıştırın.

## Derleme ve kurulum (kaynaktan, AUR'suz)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Ardından **Paket Converter** KDE menüsünde görünür
(kategori: Yardımcı Program / Paket Yönetimi).

Tam belgelendirme (Neden? / Kullanım / Notlar / Bağımlılıklar), yukarıda
bağlantısı verilen dile özgü README dosyasındadır.

![SattNEK Logo](created_by_sattnek.png)
