// ╔══════════════════════════════════════════════════════════════╗
// ║              FOR DÖNGÜSÜ — TAM ANLATIM DOSYASI              ║
// ╚══════════════════════════════════════════════════════════════╝


// ##########################################################################
//  1) SADE KOD (tamami, yorumsuz)
// ##########################################################################

#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
            cout << "Cift: " << i << endl;
    }

    cout << endl << "Tek sayilar (1'den, 2'ser 2'ser):" << endl;

    for (int i = 1; i <= 15; i += 2)
    {
        cout << " " << i;
    }

    cout << endl << endl;

    for (int i = 1; i <= 15; i++)
    {
        cout << " " << i;
    }

    int j = 1;

    for (; j <= 15; j++)
    {
        cout << " " << j;
    }

    cout << endl;
    cout << "j'nin son degeri: " << j << endl;

    return 0;
}


// ##########################################################################
//  2) ACIKLAMALI HALI (aciklama, anlattigi kodun ALTINDA)
// ##########################################################################

#include <iostream>
using namespace std;

int main()
{
    // ════════════════════════════════════════════════════════════
    // BÖLÜM 1 + BÖLÜM 2: FOR YAPISI VE ADIM ADIM TAKİP (i <= 10 örneği)
    // ════════════════════════════════════════════════════════════

    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
            cout << "Cift: " << i << endl;
        // % = modulo (bölümden kalan)
        // 4 % 2 = 0 → çift sayı ✓
        // 5 % 2 = 1 → tek sayı  ✗

        // ADIM 1 (sadece bir kez): int i = 1 → i hayata gelir
        // ADIM 2: i <= 10 mu? → EVET (1<=10) → bloğa gir
        // ADIM 3: Bloğu çalıştır
        // ADIM 4: i++ → i = 2
        // ADIM 2: i <= 10 mu? → EVET (2<=10) → bloğa gir
        // ...devam eder...
        // ADIM 2: i <= 10 mu? → HAYIR (11<=10 YANLIŞ) → DÖNGÜ BİTER
    }

    // ════════════════════════════════════════════════════════════
    // BÖLÜM 1: FOR DÖNGÜSÜNÜN YAPISI
    // ════════════════════════════════════════════════════════════
    //
    // for ( BAŞLANGIÇ ; KOŞUL ; GÜNCELLEME )
    //         ↓            ↓          ↓
    //    Sadece BİR    Her adımda   Blok her
    //    kez çalışır  kontrol       çalışınca
    //                 edilir        çalışır
    //
    // 3 GÖREVLİ TURNİKE MANTIĞI:
    // ┌─────────────┬──────────────────────────┬───────────────────────┐
    // │  Görevli    │         Görevi           │   Ne zaman çalışır?   │
    // ├─────────────┼──────────────────────────┼───────────────────────┤
    // │  int i = 1  │ Turniketi açar, bilet    │ Sadece bir kez,       │
    // │             │ verir                    │ en başta              │
    // ├─────────────┼──────────────────────────┼───────────────────────┤
    // │  i <= 10    │ Biletini her geçişte     │ Her iterasyondan ÖNCE │
    // │             │ kontrol eder             │                       │
    // ├─────────────┼──────────────────────────┼───────────────────────┤
    // │  i++        │ Biletini damgalar        │ Her blok bittikten    │
    // │             │ (sayıyı artırır)         │ SONRA                 │
    // └─────────────┴──────────────────────────┴───────────────────────┘
    //
    // Koşul FALSE olduğu an → turnike kapanır → i yok edilir



    cout << endl << "Tek sayilar (1'den, 2'ser 2'ser):" << endl;

    for (int i = 1; i <= 15; i += 2)
    {
        cout << " " << i;

        // i=1  → 1 yazdır  → i=1+2=3
        // i=3  → 3 yazdır  → i=3+2=5
        // i=5  → 5 yazdır  → i=5+2=7
        // i=7  → 7 yazdır  → i=7+2=9
        // i=9  → 9 yazdır  → i=9+2=11
        // i=11 → 11 yazdır → i=11+2=13
        // i=13 → 13 yazdır → i=13+2=15
        // i=15 → 15 yazdır → i=15+2=17
        // i=17 → koşul (17<=15) YANLIŞ → DÖNGÜ BİTTİ
    }

    // ════════════════════════════════════════════════════════════
    // BÖLÜM 3: ADIM BOYUTU DEĞİŞTİRME (i += 2)
    // ════════════════════════════════════════════════════════════
    //
    // i++   → her adımda 1 artır  (i = i + 1)
    // i+=2  → her adımda 2 artır  (i = i + 2)  ← KISALTMA
    //
    // GÜNCELLEME OPERATÖRLERİ (i=5 iken):
    // ┌──────────┬────────────┬──────────────┐
    // │  Yazım   │   Anlamı   │    Sonuç     │
    // ├──────────┼────────────┼──────────────┤
    // │  i++     │  i = i+1   │  i → 6       │
    // │  i += 2  │  i = i+2   │  i → 7       │
    // │  i += 5  │  i = i+5   │  i → 10      │
    // │  i -= 1  │  i = i-1   │  i → 4       │
    // │  i *= 2  │  i = i*2   │  i → 10      │
    // └──────────┴────────────┴──────────────┘



    cout << endl << endl;

    // ════════════════════════════════════════════════════════════
    // BÖLÜM 4: i'NİN SON DEĞERİ (neden 16 görünmez?)
    // ════════════════════════════════════════════════════════════
    //
    // i=15 → yazdır → i++ çalışır → i=16 → koşul kontrol edilir
    //                                  ↑
    //                           Bu değer OLUŞTU
    //                           ama blok çalışmadı
    //                           ve scope bitince yok edildi
    //
    // Fotoğraf analojisi:
    // Fotoğraf çekip sonra kamerayı kırmak gibi 📸💥
    // Kamera yok oldu — ama fotoğraf ekranda kaldı.
    // cout her değeri O AN ekrana işler, i'nin sonraki kaderi onu etkilemez.
    //
    // ZAMAN ÇİZELGESİ:
    // [1. an]  i=1  → cout çalışır → "1" ekranda  → i hâlâ canlı
    // [2. an]  i=3  → cout çalışır → "3" ekranda  → i hâlâ canlı
    // ...
    // [8. an]  i=15 → cout çalışır → "15" ekranda → i hâlâ canlı
    // [9. an]  i=17 → koşul YANLIŞ → döngü biter
    // [10. an] } kapanır → i YOK EDİLİR ← ama ekran çoktan yazdı!



    for (int i = 1; i <= 15; i++)   // i burada DOĞDU
    {                                // ← i'nin scope'u BAŞLADI
        cout << " " << i;
    }                                // ← i'nin scope'u BİTTİ → i ÖLDÜ

    // ❌ cout << i;   → DERLEME HATASI — i artık yok

    int j = 1;                       // j'nin scope'u = main'in tamamı
    // KANITLA — dışarıda tanımlarsan:

    for (; j <= 15; j++)             // BAŞLANGIÇ BOŞ → j zaten tanımlı
    {
        cout << " " << j;
    }                                // for bitti → ama j hâlâ canlı!

    cout << endl;
    cout << "j'nin son degeri: " << j << endl;   // ✓ ÇALIŞIR → j = 16

    // ════════════════════════════════════════════════════════════
    // BÖLÜM 5: SCOPE (KAPSAM) — ERİŞİM KURALI
    // ════════════════════════════════════════════════════════════
    //
    // SORU: Dışarıdan erişemememizin sebebi ne?
    //       → i'nin for içinde tanımlanmış olması mı?
    //       → i'nin yok olmuş olması mı?
    //
    // CEVAP: İkisi aynı şey — biri sebep, diğeri sonuç.
    //
    // SEBEP  → i'yi for'un içinde tanımladık
    // SONUÇ  → for bitince i otomatik yok edildi
    //
    // TANIMLAMA YERİ → YAŞAM SÜRESİ    → ERİŞİLEBİLİRLİK
    //      ↓                ↓                   ↓
    //  for içinde  →  for bitince ölür  →  dışarıdan ❌
    //  main içinde →  main bitince ölür →  for içinden ✓

    // ════════════════════════════════════════════════════════════
    // BÖLÜM 6: DEĞİŞKENİN BELLEKTEKİ GERÇEK DAVRANIŞI
    //          (i ve j NEDEN FARKLI YAŞIYOR? — TEKNİK DETAY)
    // ════════════════════════════════════════════════════════════
    //
    // ── 6.1) "YENİLENİYOR" DEĞİL, "YERİNDE GÜNCELLENİYOR" ─────────
    //
    // Sık yapılan zihinsel hata: "Her turda j yeniden mi oluşuyor?"
    // HAYIR. Yeni bir j DOĞMUYOR. Aynı j yerinde güncelleniyor.
    //
    // int j = 1;  satırı çalışınca :
    //   - Stack'te 4 byte'lık TEK BİR KUTU açılır.
    //   - Kutuya 1 yazılır.
    //   - Bu kutunun bellek adresi main bitene kadar SABİT kalır.
    //
    //   Kutu j :  [1] → j++ → [2] → j++ → [3] → ... → [15] → j++ → [16]
    //
    // Her j++ işlemi (j = j + 1) şu 3 adımdır :
    //   1) Aynı adresteki değeri OKU
    //   2) Değere 1 EKLE
    //   3) Sonucu AYNI ADRESE geri YAZ
    // Yeni kutu açılmaz, eski kutu silinmez. Sadece içindeki sayı değişir.
    //
    // ── 6.2) BOŞ BAŞLANGIÇ KISMI NEYİ GÖSTERİR? ───────────────────
    //
    //   for (; j <= 15; j++)
    //        ↑
    //     BOŞ başlangıç → döngü KENDİ kutusunu açmaz,
    //     hiçbir değeri sıfırlamaz, sadece dışarıdaki j'yi kullanır.
    //     Bu yüzden döngü bitince j kaybolmaz ve 16 değeriyle durur.
    //
    // ── 6.3) i vs j : KUTUNUN KADERİ ───────────────────────────────
    //
    // ┌───────────────┬──────────────────────────┬──────────────────────────┐
    // │               │ for (int i = 1; ...)     │ int j = 1; for (; ...)   │
    // ├───────────────┼──────────────────────────┼──────────────────────────┤
    // │ Kutu nerede   │ Döngüye ait scope'ta     │ main'in scope'unda       │
    // │ açılır?       │ açılır                   │ açılır                   │
    // ├───────────────┼──────────────────────────┼──────────────────────────┤
    // │ Her turda ne  │ Aynı kutu yerinde        │ Aynı kutu yerinde        │
    // │ olur?         │ artar                    │ artar                    │
    // ├───────────────┼──────────────────────────┼──────────────────────────┤
    // │ Döngü bitince │ } kapanınca KUTUNUN      │ Kutu yaşamaya devam      │
    // │               │ KENDİSİ serbest bırakılır│ eder (main bitene kadar) │
    // ├───────────────┼──────────────────────────┼──────────────────────────┤
    // │ Son değer     │ 16 (ama erişilemez)      │ 16 (cout ile okunabilir) │
    // └───────────────┴──────────────────────────┴──────────────────────────┘
    //
    // YANİ : İkisi de 16'ya ulaşır. Fark, 16'dan SONRA ne olduğundadır.
    // "j'nin son degeri: 16" satırı, i'nin de gizlice ulaştığı ama bize
    // gösteremediği değeri KANITLAR. j deneyinin asıl amacı budur.
    //
    // ── 6.4) "SON DEĞER 1 FAZLASI" HER ZAMAN DOĞRU DEĞİLDİR ───────
    //
    // GENEL KURAL : Sayaç, koşulu İLK KEZ BOZAN değerle sona erer.
    // Sıra her zaman : ARTIR → KONTROL ET → GİR YA DA ÇIK.
    //
    //   i++ ile (1→15)   : i=15 → yazdır → i++ → 16 → (16<=15) YANLIŞ
    //                      → son değer 16  (sınır + 1)
    //
    //   i += 2 ile (1→15): i=15 → yazdır → i+=2 → 17 → (17<=15) YANLIŞ
    //                      → son değer 17  (16 hiç oluşmaz!)
    //
    // Yani "1 artmış hali" değil, "BİR ADIM artmış hali" demek doğrudur.
    // Bu, ilk while örneğindeki "index 10 değil 11" bulgusunun birebir
    // aynısıdır: aynı CPU mantığı, farklı sözdizimi.
    //
    // ── 6.5) C# / UNITY PARALELİ ───────────────────────────────────
    //
    //   int j (main'de)         ≈ sınıfın alanı (field). Metottan bağımsız
    //                             yaşar, metot sadece değerini değiştirir.
    //   for (int i...) içindeki i ≈ foreach (var x in ...) değişkeni.
    //                             Sadece döngü süresince vardır.
    //
    // ── 6.6) PRATİK TUZAK VE MODERN C++ KURALI ─────────────────────
    //
    // j döngü bittikten sonra da erişilebilir olduğu için, ileride
    // yanlışlıkla eski değeriyle (16) kullanıp HATA yapabilirsin.
    //
    // MODERN C++ KURALI : Değişkeni mümkün olan EN DAR SCOPE'ta tanımla.
    //   → Varsayılan tercih : for (int i = 1; ...)
    //   → j tarzı (dışarıda tanımlama) yalnızca döngü sonrası değere
    //     GERÇEKTEN ihtiyaç duyduğunda kullanılır.

    return 0;
}

// ╔══════════════════════════════════════════════════════════════╗
// ║                     GENEL ÖZET                              ║
// ╠══════════════════════════════════════════════════════════════╣
// ║  1. for döngüsü 3 parçadan oluşur: BAŞLANGIÇ, KOŞUL,       ║
// ║     GÜNCELLEME                                              ║
// ║  2. Adım boyutunu i++ yerine i+=N yazarak değiştirebilirsin ║
// ║  3. Döngünün son turunda i bir sonraki değere ulaşır ama    ║
// ║     blok çalışmaz                                           ║
// ║  4. cout değeri O AN ekrana yazar — i'nin sonraki kaderi    ║
// ║     ekranı etkilemez                                        ║
// ║  5. Scope: nerede tanımlandıysa orada yaşar, orada ölür     ║
// ╚══════════════════════════════════════════════════════════════╝

===================================================================================================

// ╔══════════════════════════════════════════════════════════════╗
// ║   DEĞİŞKEN = SABİT ADRESLİ KUTU : TANIM, ATAMA, ÖMÜR, SCOPE  ║
// ╚══════════════════════════════════════════════════════════════╝


// ##########################################################################
//  1) SADE KOD (tamamı, yorumsuz)
// ##########################################################################

#include <iostream>
using namespace std;

int main()
{
    int j = 1;
    cout << "1) tanim sonrasi        : " << j << "  adres: " << &j << endl;

    j = 50;
    cout << "2) atama sonrasi        : " << j << endl;

    j++;
    cout << "3) j++ sonrasi          : " << j << endl;

    for (; j <= 60; j++)
    {
    }
    cout << "4) dongu sonrasi        : " << j << "  adres: " << &j << endl;

    {
        int j = 100;
        cout << "5) ic scope j (golge)   : " << j << "  adres: " << &j << endl;
    }

    cout << "6) dis j geri geldi     : " << j << "  adres: " << &j << endl;

    return 0;
}


// ##########################################################################
//  2) AÇIKLAMALI HALİ (açıklama, anlattığı kodun ALTINDA)
// ##########################################################################

#include <iostream>
using namespace std;

int main()
{
    int j = 1;
    cout << "1) tanim sonrasi        : " << j << "  adres: " << &j << endl;

    // ════════════════════════════════════════════════════════════
    // BÖLÜM A: DEĞİŞKEN NEDİR? (KUTU MODELİ)
    // ════════════════════════════════════════════════════════════
    //
    // int j = 1;  satırı çalışınca CPU/stack şunu yapar:
    //   1) Stack'te 4 byte'lık (int boyutu) boş bir alan AYIRIR.
    //   2) O alana 1 değerini YAZAR.
    //   3) Bu alanın bellek adresi main bitene kadar SABİT kalır.
    //
    //   Bellek görünümü (adres örnek amaçlıdır):
    //
    //   adres 0x1000 :  [ 1 ]      ← "j" dediğimiz şey aslında bu kutudur
    //
    // "j" ismi, programcı için bir etikettir. Derleyici bu ismi
    // adrese çevirir. Program çalışırken "j" diye bir isim kalmaz,
    // sadece adresler vardır.
    //
    // &j  → "j'nin adresi" operatörü (adres-of). Kutunun nerede
    //       durduğunu ekrana yazdırır. (Pointer konusunda detaylanacak.)
    //
    // C# paralelli: int j = 1; yerel değişkeni de stack'te yaşar.
    // Fark: C++'ta bu kutunun ömrünü scope belirler, GC yoktur.
    //
    // ════════════════════════════════════════════════════════════

    j = 50;
    cout << "2) atama sonrasi        : " << j << endl;

    // ════════════════════════════════════════════════════════════
    // BÖLÜM B: TANIM (DEFINITION) vs ATAMA (ASSIGNMENT)
    // ════════════════════════════════════════════════════════════
    //
    // En kritik ayrım: SATIRIN BAŞINDA TÜR (int) VAR MI?
    //
    //   int j = 1;   → TÜR VAR   → TANIM  → YENİ KUTU AÇILIR
    //   j = 50;      → TÜR YOK   → ATAMA  → MEVCUT KUTUNUN ÜSTÜNE YAZILIR
    //
    // j = 50; çalışınca :
    //   0x1000 :  [ 1 ]  →  [ 50 ]
    //   Eski değer (1) bir yerde SAKLANMAZ, ezilir ve kaybolur.
    //   Kutu aynı, adres aynı, sadece içindeki sayı değişti.
    //
    // ════════════════════════════════════════════════════════════

    j++;
    cout << "3) j++ sonrasi          : " << j << endl;

    // ════════════════════════════════════════════════════════════
    // BÖLÜM C: j++ İÇERİDE NE YAPAR?
    // ════════════════════════════════════════════════════════════
    //
    // j++  ≡  j = j + 1  ve 3 adımdır:
    //   1) 0x1000 adresindeki değeri OKU      (50)
    //   2) Değere 1 EKLE                      (51)
    //   3) Sonucu AYNI ADRESE geri YAZ        (0x1000 = 51)
    //
    // Yeni kutu açılmaz. Eski kutu silinmez. Sadece içerik değişir.
    //
    // ════════════════════════════════════════════════════════════

    for (; j <= 60; j++)
    {
    }
    cout << "4) dongu sonrasi        : " << j << "  adres: " << &j << endl;

    // ════════════════════════════════════════════════════════════
    // BÖLÜM D: DÖNGÜ j'Yİ SIFIRLAMAZ, KALDIĞI YERDEN DEVAM EDER
    // ════════════════════════════════════════════════════════════
    //
    // for (; j <= 60; j++)
    //      ↑
    //   BAŞLANGIÇ BOŞ → döngü kendi kutusunu AÇMAZ, değer ATAMAZ.
    //   Sadece main'deki mevcut j'yi kullanır.
    //
    // Döngü başladığında j = 51 olduğu için :
    //   51 → 52 → 53 → ... → 60 → 61
    //   (61 <= 60) YANLIŞ → döngü biter.
    //   Döngü 51'den 60'a kadar 10 tur döner (1'den değil!).
    //
    // Döngü bitince j = 61 ve ADRES HÂLÂ AYNI (satır 1 ile satır 4'ün
    // adresleri birebir aynı çıkar). Bu, "hep aynı kutu" iddiasının
    // çalışan kanıtıdır.
    //
    // ZAMAN ÇİZELGESİ (kutunun içeriği) :
    //   satır 1 :  [1]
    //   satır 2 :  [50]
    //   satır 3 :  [51]
    //   döngü   :  [51] → [52] → ... → [60] → [61]
    //   satır 4 :  cout [61] okur
    //
    // CPU bu satırları YUKARIDAN AŞAĞIYA SIRAYLA yürütür; her satır,
    // bir önceki satırın kutuda bıraktığı değerden devam eder.
    //
    // ════════════════════════════════════════════════════════════

    {
        int j = 100;
        cout << "5) ic scope j (golge)   : " << j << "  adres: " << &j << endl;
    }

    // ════════════════════════════════════════════════════════════
    // BÖLÜM E: GÖLGELEME (SHADOWING) — İÇ SCOPE'TA YENİDEN TANIM
    // ════════════════════════════════════════════════════════════
    //
    // Burada satırın başında TÜR (int) var → bu bir TANIM → YENİ KUTU.
    //
    //   Dış j :  adres 0x1000 :  [ 61 ]   (hâlâ yaşıyor, dokunulmadı)
    //   İç  j :  adres 0x1004 :  [ 100 ]  (yeni kutu, FARKLI adres)
    //
    // İsim aynı, kutular AYRI. Derleyici iç scope'ta "j" ismini EN
    // YAKIN tanıma bağlar; dış j bu sürede "gölgelenmiş" olur.
    // Çıktıda iki adresin FARKLI olduğunu göreceksin.
    //
    // İç scope'un } parantezi kapanınca iç j'nin kutusu serbest
    // bırakılır, dış j'nin kutusuna hiçbir şey olmaz.
    //
    // !! TUZAK !! Gölgeleme sessiz bir hata kaynağıdır. Dış j'yi
    // güncellediğini sanırken iç j'yi güncellersin. Derleyici varsayılan
    // olarak uyarmaz; -Wshadow bayrağı ile uyarır.
    // Pratik kural: iç scope'ta dış değişkenle AYNI ismi kullanma.
    //
    // ════════════════════════════════════════════════════════════

    cout << "6) dis j geri geldi     : " << j << "  adres: " << &j << endl;

    // ════════════════════════════════════════════════════════════
    // BÖLÜM F: ÖMÜR (LIFETIME) VE SCOPE — TEK KURAL
    // ════════════════════════════════════════════════════════════
    //
    // KURAL : Bir değişkenin kutusu, TANIMLANDIĞI SATIRDAN, o satırı
    //         içeren { } bloğunun KAPANIŞINA kadar yaşar.
    //
    //   Tanımlandığı yer   → Kutunun ömrü        → Erişim
    //   ─────────────────────────────────────────────────────────
    //   main içinde         → main bitince ölür   → main'in her yerinden ✓
    //   for (int i...) içi  → for bitince ölür    → dışarıdan ❌
    //   { } iç bloğu        → } kapanınca ölür    → dışarıdan ❌
    //
    // Satır 6'da dış j 61 olarak geri geldi çünkü hiç ölmemişti:
    // ömrü main'in sonuna kadardır.
    //
    // ════════════════════════════════════════════════════════════

    return 0;
}

// ╔══════════════════════════════════════════════════════════════╗
// ║              BÖLÜM G: DERLEYİCİ MÜ, CPU MU?                  ║
// ╠══════════════════════════════════════════════════════════════╣
// ║  Sık yapılan zihinsel hata: "Derleyici satır satır çalışıp,  ║
// ║  döngüden çıkıp main'e dönerek j'yi güncelliyor."            ║
// ║                                                              ║
// ║  GERÇEK:                                                     ║
// ║  • DERLEYİCİ (compile time): kodu BİR KEZ makine koduna      ║
// ║    çevirir ve biter. Program çalışırken ortada YOKTUR.       ║
// ║    Scope kuralları (i dışarıdan görünmez) SADECE derleyicinin║
// ║    isim kontrolüdür.                                         ║
// ║  • CPU (runtime): derlenmiş talimatları sırayla yürütür.     ║
// ║    "Yukarı çıkma" denen şey, CPU'nun bir jump (atlama)       ║
// ║    talimatıyla geri bir talimata gitmesidir.                 ║
// ║  • for döngüsü main'in DIŞINDA ayrı bir yer değildir; main'in║
// ║    gövdesinin parçasıdır. { } sadece scope sınırıdır, CPU'yu ║
// ║    başka yere taşımaz. Hepsi aynı stack çerçevesindedir.     ║
// ║  • j++ çalışırken CPU "main'e çık" demez; doğrudan j'nin     ║
// ║    ADRESİNE gider: oku → 1 ekle → aynı adrese yaz.           ║
// ╚══════════════════════════════════════════════════════════════╝

// ╔══════════════════════════════════════════════════════════════╗
// ║                     GENEL ÖZET                               ║
// ╠══════════════════════════════════════════════════════════════╣
// ║  1. Değişken = stack'te SABİT ADRESLİ bir kutu.              ║
// ║  2. int j = ...  (tür var)   → TANIM  → yeni kutu açar.      ║
// ║  3. j = ...      (tür yok)   → ATAMA  → mevcut kutuya yazar. ║
// ║  4. Her yazma eski değeri EZER; eski değer saklanmaz.        ║
// ║  5. Kutu, tanımlandığı { } kapanana kadar yaşar.             ║
// ║  6. Satırlar sırayla yürür; her satır önceki değerden devam. ║
// ║  7. Döngünün başlangıç kısmı boşsa j SIFIRLANMAZ.            ║
// ║  8. İç scope'ta aynı isimle tanım = gölgeleme (yeni kutu).   ║
// ║  9. Scope = derleyici kuralı, kutu/adres = çalışma zamanı.   ║
// ╚══════════════════════════════════════════════════════════════╝