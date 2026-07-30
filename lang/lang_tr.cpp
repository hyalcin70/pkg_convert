// lang_tr.cpp — Uebersetzungen fuer pkg_convert (Sprache: tr)
#include <QMap>
#include <QString>

QMap<QString, QString> lang_tr() {
    return QMap<QString, QString> {
                {"title", "Paket Converter"},
                {"subtitle", "Debian (.deb) / RedHat (.rpm) paketlerini ArchLinux'e çevirir"},
                {"dropHint", "Dosyayı buraya sürükle (.deb / .rpm)  veya  'Gözat' tıkla"},
                {"browse", "Gözat"},
                {"choosePkg", "Paket seç"},
                {"pkgsFilter", "Paketler (*.deb *.rpm)"},
                {"noFile", "Henüz dosya seçilmedi."},
                {"deps", "Bağımlılıklar"},
                {"build", "Paket oluştur"},
                {"install", "Paketi kur"},
                {"installed", "Kurulu paketleri (kaldırmak için seç)"},
                {"uninstall", "Seçili paketi kaldır"},
                {"themeDark", "🌙 Koyu"},
                {"themeLight", "☀ Açık"},
                {"langLabel", "Dil :"},
                {"warnNoBinary", "⚠ Bu paket ÇALIŞTIRILABİLİR bir program içermiyor (sadece veri/"
                    "kütüphaneler). Çalıştırmak için gerçek program paketine de ihtiyacın var "
                    "(ör. circuslinux-data değil, circuslinux) !\n\n"},
                {"hintInstallTitle", "Kurulum notu"},
                {"hintInstallBody", "Bazı programlar seçilen pakette bulunmayan, ayrı sağlanan "
                    "veri/yerelleştirmeye (ör. bir *-data veya *-common paketi) ihtiyaç duyar.\n\n"
                    "Program başlarken eksik dosyalardan şikayet ederse, böyle bir ek paketin "
                    "eksik olup olmadığını kontrol et ve onu da dönüştür."},
                {"confirmInstallTitle", "Kurulumu onayla"},
                {"confirmInstallBody", "Gerçekten kurmak istiyor musun :\n\n"},
                {"confirmUninstallTitle", "Kaldırmayı onayla"},
                {"confirmUninstallBody", "Gerçekten kaldırmak istiyor musun :\n\n"},
                {"sudoInstall", "Root parolası"},
                {"sudoInstallBody", "sudo parolası (kuruluyor: "},
                {"sudoUninstall", "Root parolası"},
                {"sudoUninstallBody", "sudo parolası (kaldırılıyor: "},
                {"buildTitle", "Şu için oluştur: "},
                {"buildAsk", "Paket nasıl oluşturulsun ?"},
                {"buildOnly", "Sadece paket"},
                {"buildSrc", "Paket + Kaynaklar"},
                {"targetDir", "Hedef klasör: "},
                {"errNoBuiltPkg", "❌ Kurulacak oluşturulmuş paket yok."},
                {"errNoDebRpm", "❌ Sadece .deb veya .rpm desteklenir."},
                {"errNoTarget", "❌ İptal – hedef klasör seçilmedi."},
                {"errPkgbuild", "❌ PKGBUILD yazılamıyor: "},
                {"msgBuildFail", "❌ Oluşturma başarısız."},
                {"msgPkgbuildDone", "✅ PKGBUILD oluşturuldu."},
                {"msgPkgBuilt", "✅ Paket oluşturuldu."},
                {"msgInstalled", "✅ Paket kuruldu: "},
                {"msgInstallFail", "❌ Kurulum başarısız:"},
                {"msgInstallPartial", "⚠ Kurulum eksik – lütfen kontrol et (kurulu mu "},
                {"msgUninstallDone", "✅ Paket kaldırıldı: "},
                {"msgUninstallFail", "❌ Kaldırma başarısız:\n"},
                {"msgUninstallPartial", "⚠ Kaldırma belki iptal edildi – lütfen kontrol et (kurulu mu "},
                {"msgNoPkgToRemove", "❌ Kaldırılacak bilinen paket yok."},
                {"msgRmAborted", "❌ Kaldırma iptal edildi."},
                {"msgRmAbortedPw", "❌ Kaldırma iptal edildi (parola yok)."},
                {"msgInstAborted", "❌ Kurulum iptal edildi."},
                {"msgInstAbortedPw", "❌ Kurulum iptal edildi (parola yok)."},
                {"msgChooseFirst", "❌ Lütfen önce listeden bir paket seç."},
                {"mapped", "Eşlenen"},
                {"unknown", "Bilinmeyen"},
                {"allOk", "— (hepsi tamam !)"},
                {"noMapped", "— eşlenen yok"},
                {"extraDeps", "📦 Ayrıca dönüştür (Debian/RPM bağımlılıkları): "},
                {"extraDepsNote", "   Bu paketler program tarafından referans gösterilir (genelde veri/"
                    "yerelleştirme). Olmadan başlangıçta dosyalar eksik kalabilir.\n\n"},
                {"notSatisfiable", "⚠ Arch repo'larından KARŞILANAMAZ (tam kütüphane sürümü eksik): "},
                {"notSatisfiableNote", "   Bu program böyle ÇALIŞMAZ !\n\n"},
                {"noRepoDeps", "(Kurulacak repo bağımlılığı yok – paket programın GÜNCEL sürümüyle "
                    "oluşturuldu mu ?)"},
                {"chosen", "Seçildi: "},
                {"fileLabel", "Dosya: "},
                {"working", "İşleniyor…"},
                {"cleanup", "🧹 Sadece paket: çalışma dosyaları (pkg/, src/, PKGBUILD) silindi – "
                    "mevcut paketler korundu.\n"},
                {"pkgbuildLabel", "PKGBUILD: "},
                {"depsInstalled", "✅ Bağımlılıklar kuruldu: "},
                {"depsFailed", "❌ Bağımlılıklar BAŞARISIZ: "},
                {"warnIntroTitle", "Dönüştürme uyarısı"},
                {"warnIntro", "Otomatik dönüşüm başarısız olabilir: örneğin bağımlılıklar eksikse, "
                    "betikler yoksa veya sistem farkları tanınmıyorsa."},
                {"warnContinue", "Yine de devam edilsin mi?"},
                {"msgBuildAborted", "❌ Build iptal edildi."},
                {"linkCopyError", "Fehler beim Kopieren/Verknuepfen: "},
                {"brandFallback", "created by SattNEK"},
    };
}
