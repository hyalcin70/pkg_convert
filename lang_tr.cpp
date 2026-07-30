// lang_tr.cpp — Uebersetzungen fuer pkg_convert (Sprache: tr)
#include <QString>
#include <QMap>

QMap<QString, QString> lang_tr() {
    QMap<QString, QString> m;
    m.insert("title", "Paket Donusturucu");
    m.insert("subtitle", "Debian (.deb) / RedHat (.rpm) paketlerini ArchLinux'a donusturur");
    m.insert("dropHint", "Dosyayi buraya surukleyin (.deb/.rpm) veya 'Goruntule' tiklayin");
    m.insert("langLabel", "Dil:");
    m.insert("browse", "Goruntule");
    m.insert("noFile", "Henuz dosya secilmedi.");
    m.insert("deps", "Bagimliliklar");
    m.insert("build", "Paket olustur");
    m.insert("install", "Paketi kur");
    m.insert("installed", "Kurulu paketleri (kaldirmak icin sec)");
    m.insert("uninstall", "Secili paketi kaldir");
    m.insert("themeLight", "Acik");
    m.insert("themeDark", "Koyu");
    m.insert("choosePkg", "Paket sec");
    m.insert("pkgsFilter", "Paketler (*.deb *.rpm)");
    m.insert("errNoDebRpm", "❌ Lutfen .deb veya .rpm dosyasi secin.");
    m.insert("errNoBuiltPkg", "❌ Henuz paket olusturulmadi.");
    m.insert("fileLabel", "Dosya: ");
    m.insert("chosen", "Secildi: ");
    m.insert("working", "Isleniyor…");
    m.insert("targetDir", "Hedef klasor: ");
    m.insert("errNoTarget", "❌ Hedef klasor secilmedi.");
    m.insert("errPkgbuild", "❌ PKGBUILD yazilamadi: ");
    m.insert("buildTitle", "Paket olustur: ");
    m.insert("buildAsk", "Paket nasil olusturulsun?");
    m.insert("buildOnly", "Sadece paket");
    m.insert("buildSrc", "Paket + kaynaklar");
    m.insert("buildFor", "Donusturme");
    m.insert("mapped", "Eslenen kutuphaneler");
    m.insert("unknown", "Eslenmemiis / elle kontrol edin");
    m.insert("noMapped", "hic eslenmemiis");
    m.insert("allOk", "✅ hepsi cozuldu");
    m.insert("extraDeps", "📦 Ek paketler: ");
    m.insert("extraDepsNote", "   Bunlar ek olarak gereklidir.");
    m.insert("notSatisfiable", "⚠ Bagimliliklar Arch repolardan KARSILANAMIYOR: ");
    m.insert("notSatisfiableNote", "   Lutfen elle kontrol edin.");
    m.insert("pkgbuildLabel", "PKGBUILD: ");
    m.insert("msgPkgBuilt", "✅ Paket olusturuldu:\n");
    m.insert("msgBuildFail", "❌ Olusturma basarisiz.");
    m.insert("msgPkgbuildDone", "✅ PKGBUILD olusturuldu.");
    m.insert("cleanup", "🧹 Sadece paket: calisma dosyalari kaldirildi.");
    m.insert("depsInstalled", "✅ Bagimliliklar kuruldu: ");
    m.insert("depsFailed", "❌ Bagimliliklar BASARISIZ: ");
    m.insert("warnIntroTitle", "Donusturme uyarisi");
    m.insert("warnIntro", "Otomatik donusum basarisiz olabilir: ornegin bagimliliklar eksikse, "
        "betikler yoksa veya sistem farkliliklari taninmiyorsa.");
    m.insert("warnContinue", "Yine de devam edilsin mi?");
    m.insert("msgBuildAborted", "❌ Olusturma iptal edildi.");
    m.insert("msgInstalled", "✅ kuruldu: ");
    m.insert("msgInstallFail", "❌ Kurulum basarisiz.");
    m.insert("msgInstallPartial", "⚠️ kismen kuruldu: ");
    m.insert("msgInstAborted", "❌ Kurulum iptal edildi.");
    m.insert("msgInstAbortedPw", "❌ Kurulum iptal edildi (sifre yok).");
    m.insert("hintInstallTitle", "Kurulum ipucu");
    m.insert("hintInstallBody", "Bazi programler ek olarak ayri veriler/localizasyon gerektirir "
        "(ornegin bir *-data veya *-common paketi) ki bunlar secili pakette yok.\n\n"
        "Eger program baslatirken eksik dosyalar icin sasiyorsa, Boyle bir ek paketin "
        "eksik olup olmadigini kontrol edin ve onu da donusturun.");
    m.insert("confirmInstallTitle", "Gercekten kurulsun mu?");
    m.insert("confirmInstallBody", "Gercekten kurmak istiyorsunuz:\n\n");
    m.insert("sudoInstall", "sudo sifresi");
    m.insert("sudoInstallBody", "sudo sifresi (kurulum: ");
    m.insert("msgRmAborted", "❌ Kaldirma islemi iptal edildi.");
    m.insert("msgRmAbortedPw", "❌ Kaldirma islemi iptal edildi (sifre yok).");
    m.insert("confirmUninstallTitle", "Gercekten kaldirilsin mi?");
    m.insert("confirmUninstallBody", "Gercekten kaldirmak istiyorsunuz:\n\n");
    m.insert("sudoUninstall", "sudo sifresi");
    m.insert("sudoUninstallBody", "sudo sifresi (kaldirma: ");
    m.insert("msgUninstallDone", "✅ kaldirildi: ");
    m.insert("msgUninstallFail", "❌ Kaldirma basarisiz.");
    m.insert("msgUninstallPartial", "⚠️ kismen kaldirildi: ");
    m.insert("msgNoPkgToRemove", "❌ Kaldirilacak paket secilmedi.");
    m.insert("msgChooseFirst", "❌ Lutfen once listeden bir paket secin.");
    m.insert("linkCopyError", "Kopyalama/baglama hatasi: ");
    m.insert("brandFallback", "created by SattNEK");
    m.insert("noRepoDeps", "(Kurulacak repo bagimliligi yok – paket programin GUNCEL surumuyle "
        "olusturuldu mu?)");
    m.insert("warnNoBinary", "❌ Calistirilabilir paket bulunamadi.");
    return m;
}
