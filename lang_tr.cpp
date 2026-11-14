// lang_tr.cpp — Uebersetzungen fuer pkg_convert (Sprache: tr)
#include <QString>
#include <QMap>

QMap<QString, QString> lang_tr() {
    QMap<QString, QString> m;
    m.insert("title", "Paket Dönüştürücü");
    m.insert("subtitle", "Debian (.deb) / RedHat (.rpm) paketlerini ArchLinux'a dönüştürür");
    m.insert("dropHint", "Dosyayı buraya sürükleyin (.deb/.rpm) veya 'Görüntüle'ye tıklayın");
    m.insert("langLabel", "Dil:");
    m.insert("browse", "Görüntüle");
    m.insert("noFile", "Henüz dosya seçilmedi.");
    m.insert("deps", "Bağımlılıklar");
    m.insert("build", "Paket oluştur");
    m.insert("install", "Paketi kur");
    m.insert("installed", "Kurulu paketleri (kaldırmak için seçin)");
    m.insert("uninstall", "Seçili paketi kaldır");
    m.insert("themeLight", "Açık");
    m.insert("themeDark", "Koyu");
    m.insert("choosePkg", "Paket seç");
    m.insert("pkgsFilter", "Paketler (*.deb *.rpm)");
    m.insert("errNoDebRpm", "❌ Lütfen .deb veya .rpm dosyası seçin.");
    m.insert("errNoBuiltPkg", "❌ Henüz paket oluşturulmadı.");
    m.insert("fileLabel", "Dosya: ");
    m.insert("chosen", "Seçildi: ");
    m.insert("working", "İşleniyor…");
    m.insert("targetDir", "Hedef klasör: ");
    m.insert("errNoTarget", "❌ Hedef klasör seçilmedi.");
    m.insert("errPkgbuild", "❌ PKGBUILD yazılamadı: ");
    m.insert("buildTitle", "Paket oluştur: ");
    m.insert("buildAsk", "Paket nasıl oluşturulsun?");
    m.insert("buildOnly", "Sadece paket");
    m.insert("buildSrc", "Paket + kaynaklar");
    m.insert("buildFor", "Dönüştürme");
    m.insert("mapped", "Eşleşen kütüphaneler");
    m.insert("unknown", "Eşleşmemiş / elle kontrol edin");
    m.insert("noMapped", "hiç eşleşmemiş");
    m.insert("allOk", "✅ hepsi çözüldü");
    m.insert("extraDeps", "📦 Ek paketler: ");
    m.insert("extraDepsNote", "   Bunlar ek olarak gereklidir.");
    m.insert("notSatisfiable", "⚠ Bağımlılıklar Arch repolarından KARŞILANAMIYOR: ");
    m.insert("notSatisfiableNote", "   Lütfen elle kontrol edin.");
    m.insert("pkgbuildLabel", "PKGBUILD: ");
    m.insert("msgPkgBuilt", "✅ Paket oluşturuldu:\n");
    m.insert("msgBuildFail", "❌ Oluşturma başarısız.");
    m.insert("msgPkgbuildDone", "✅ PKGBUILD oluşturuldu.");
    m.insert("cleanup", "🧹 Sadece paket: çalışma dosyaları kaldırıldı.");
    m.insert("depsInstalled", "✅ Bağımlılıklar kuruldu: ");
    m.insert("depsFailed", "❌ Bağımlılıklar BAŞARISIZ: ");
    m.insert("warnIntroTitle", "Dönüştürme uyarısı");
    m.insert("warnIntro", "Otomatik dönüşüm başarısız olabilir: örneğin bağımlılıklar eksikse, "
        "betikler yoksa veya sistem farklılıkları tanınmıyorsa.");
    m.insert("warnContinue", "Yine de devam edilsin mi?");
    m.insert("msgBuildAborted", "❌ Oluşturma iptal edildi.");
    m.insert("msgInstalled", "✅ kuruldu: ");
    m.insert("msgInstallFail", "❌ Kurulum başarısız.");
    m.insert("msgInstallPartial", "⚠️ kısmen kuruldu: ");
    m.insert("msgInstAborted", "❌ Kurulum iptal edildi.");
    m.insert("msgInstAbortedPw", "❌ Kurulum iptal edildi (şifre yok).");
    m.insert("hintInstallTitle", "Kurulum ipucu");
    m.insert("hintInstallBody", "Bazı programlar ek olarak ayrı veriler/yerelleştirme gerektirir "
        "(örneğin bir *-data veya *-common paketi) ki bunlar seçili pakette yok.\n\n"
        "Eğer program başlatılırken eksik dosyalarla ilgili sorun çıkarsa, böyle bir ek paketin "
        "eksik olup olmadığını kontrol edin ve onu da dönüştürün.");
    m.insert("confirmInstallTitle", "Gerçekten kurulsun mu?");
    m.insert("confirmInstallBody", "Gerçekten kurmak istiyorsunuz:\n\n");
    m.insert("sudoInstall", "sudo şifresi");
    m.insert("sudoInstallBody", "sudo şifresi (kurulum: ");
    m.insert("msgRmAborted", "❌ Kaldırma işlemi iptal edildi.");
    m.insert("msgRmAbortedPw", "❌ Kaldırma işlemi iptal edildi (şifre yok).");
    m.insert("confirmUninstallTitle", "Gerçekten kaldırılsın mı?");
    m.insert("confirmUninstallBody", "Gerçekten kaldırmak istiyorsunuz:\n\n");
    m.insert("sudoUninstall", "sudo şifresi");
    m.insert("sudoUninstallBody", "sudo şifresi (kaldırma: ");
    m.insert("msgUninstallDone", "✅ kaldırıldı: ");
    m.insert("msgUninstallFail", "❌ Kaldırma başarısız.");
    m.insert("msgUninstallPartial", "⚠️ kısmen kaldırıldı: ");
    m.insert("msgNoPkgToRemove", "❌ Kaldırılacak paket seçilmedi.");
    m.insert("msgChooseFirst", "❌ Lütfen önce listeden bir paket seçin.");
    m.insert("linkCopyError", "Kopyalama/bağlama hatası: ");
    m.insert("brandFallback", "created by SattNEK");
    m.insert("noRepoDeps", "(Kurulacak repo bağımlılığı yok – paket programın GÜNCEL sürümüyle "
        "oluşturulmuş mu?)");
    m.insert("warnNoBinary", "❌ Çalıştırılabilir paket bulunamadı.");
    m.insert("missingToolsTitle", "Eksik Sistem Araçları");
    m.insert("missingToolsHint", "Bu araçlar dönüştürme için gereklidir.\nOnlar olmadan .deb/.rpm çıkarılamaz veya bağımlılıklar çözülmez.");
    m.insert("installMissing", "Eksikleri kur (sudo)");
    m.insert("skip", "Yine de devam et");
    m.insert("autoVerify", "Derlemeden sonra paketi sanal kökte doğrula");
    m.insert("verifyTitle", "Sanal kök doğrulaması");
    m.insert("verifyRunning", "Sanal kökte doğrulanıyor (paket ve bağımlılıkları kuruluyor)…");
    m.insert("verifyOk", "✅ Doğrulama başarılı: %1 ve %2 paket sanal kökte kuruldu, %3 dosya mevcut.");
    m.insert("verifyFail", "❌ Doğrulama başarısız:");
    m.insert("verifyNeedSync", "Pacman eşitleme veritabanı eksik (/var/lib/pacman/sync) — önce „sudo pacman -Sy“ çalıştırın.");
    m.insert("verifyTmpFail", "geçici dizin kullanılamıyor");
    m.insert("verifyNotRegistered", "Paket sanal kökte kaydedilmedi.");
    m.insert("verifyMissingFiles", "Beklenen %1 dosya sanal kökte eksik.");
    return m;
}
