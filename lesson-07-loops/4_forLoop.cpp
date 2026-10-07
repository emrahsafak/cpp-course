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

// ╔══════════════════════════════════════════════════════════════════════╗
// ║  DEĞİŞKEN, BELLEK KONUMU, TANIM, ATAMA, ÖMÜR (LIFETIME), SCOPE        ║
// ║  Standart: C++17                                                     ║
// ╚══════════════════════════════════════════════════════════════════════╝


// ##########################################################################
//  1) SADE KOD (tamamı, yorumsuz)
// ##########################################################################

#include <iostream>
using namespace std;

int main()
{
    int j = 1;
    cout << "1) tanim sonrasi          : " << j << "  adres: " << &j << endl;

    j = 50;
    cout << "2) atama sonrasi          : " << j << "  adres: " << &j << endl;

    j++;
    cout << "3) j++ sonrasi            : " << j << "  adres: " << &j << endl;

    for (; j <= 55; j++)
    {
        cout << "   dongu icinde           : " << j << "  adres: " << &j << endl;
    }
    cout << "4) dongu sonrasi          : " << j << "  adres: " << &j << endl;

    {
        int j = 100;
        cout << "5) ic blok, int j (golge) : " << j << "  adres: " << &j << endl;
    }

    cout << "6) dis j geri geldi       : " << j << "  adres: " << &j << endl;

    {
        j = 200;
        cout << "7) ic blok, j = 200       : " << j << "  adres: " << &j << endl;
    }

    cout << "8) blok sonrasi           : " << j << "  adres: " << &j << endl;

    for (int j = 0; j < 2; j++)
    {
        cout << "9) for(int j) golge       : " << j << "  adres: " << &j << endl;
    }

    cout << "10) for sonrasi dis j     : " << j << "  adres: " << &j << endl;

    j = 5;
    cout << "11) son atama             : " << j << "  adres: " << &j << endl;

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
    cout << "1) tanim sonrasi          : " << j << "  adres: " << &j << endl;

    // ════════════════════════════════════════════════════════════════
    // BÖLÜM A: DEĞİŞKEN NEDİR? (NESNE + BELLEK KONUMU + İSİM)
    // ════════════════════════════════════════════════════════════════
    //
    // int j = 1;  satırı bir TANIM'dır (definition) ve aynı anda
    // İLKLENDİRME'dir (initialization). Çalışma zamanında şunlar olur:
    //
    //   1) Stack'te (otomatik depolama, automatic storage duration)
    //      sizeof(int) = genelde 4 byte'lık bir BELLEK KONUMU ayrılır.
    //   2) Bu konumda bir int NESNESİ (object) oluşur.
    //   3) Nesneye ilk değer olarak 1 yazılır.
    //   4) Nesnenin BELLEK ADRESİ, ömrü boyunca SABİT kalır.
    //
    //   Üç kavramı ayır:
    //     İSİM (identifier) : "j"  → sadece kaynak koddadır, programcı içindir
    //     NESNE (object)    : bellekte yaşayan 4 byte'lık int
    //     ADRES (address)   : o nesnenin bellekteki konumu (örn. 0x7ffc...a4)
    //
    //   Derleyici, "j" ismini derleme zamanında bir adrese çevirir.
    //   Program çalışırken "j" diye bir isim yoktur, sadece adres vardır.
    //
    // &j  → adres-of operatörü. j nesnesinin bellek adresini döndürür.
    //       (Dönüş türü int*, yani pointer. Detayı pointer konusunda.)
    //
    // C# paraleli: Metot içi yerel değişken de stack'te yaşar. Fark: C++'ta
    // ömrü scope belirler, garbage collector yoktur.
    //
    // ════════════════════════════════════════════════════════════════

    j = 50;
    cout << "2) atama sonrasi          : " << j << "  adres: " << &j << endl;

    // ════════════════════════════════════════════════════════════════
    // BÖLÜM B: TANIM (DEFINITION) vs ATAMA (ASSIGNMENT)
    // ════════════════════════════════════════════════════════════════
    //
    // En kritik ayrım: satırın başında TÜR (int) VAR MI?
    //
    //   int j = 1;  → tür VAR → TANIM + İLKLENDİRME → yeni nesne oluşur
    //   j = 50;     → tür YOK → ATAMA              → mevcut nesne değişir
    //
    // j = 50; çalışınca ADRES DEĞİŞMEZ, sadece o adresteki değer değişir:
    //
    //   adres A :  1  →  50
    //
    // Eski değer (1) başka bir yere kaydedilmez, üzerine yazılır ve kaybolur.
    // Çıktıda satır 1 ve satır 2'nin adresleri BİREBİR AYNIDIR.
    //
    // ════════════════════════════════════════════════════════════════

    j++;
    cout << "3) j++ sonrasi            : " << j << "  adres: " << &j << endl;

    // ════════════════════════════════════════════════════════════════
    // BÖLÜM C: j++ BELLEKTE NE YAPAR?
    // ════════════════════════════════════════════════════════════════
    //
    // j++  ≡  j = j + 1  ve CPU düzeyinde 3 adımdır:
    //   1) A adresindeki değeri bir yazmaca (register) OKU     (50)
    //   2) Yazmaçtaki değere 1 EKLE                            (51)
    //   3) Sonucu AYNI A adresine geri YAZ                     (51)
    //
    // Yeni nesne oluşmaz, eski nesne yok edilmez; yalnızca değer değişir.
    // (Derleyici optimizasyonu j'yi tamamen yazmaçta tutabilir, ama
    // &j aldığımız için C++ semantiği "j'nin bir adresi var" der.)
    //
    // ════════════════════════════════════════════════════════════════

    for (; j <= 55; j++)
    {
        cout << "   dongu icinde           : " << j << "  adres: " << &j << endl;
    }
    cout << "4) dongu sonrasi          : " << j << "  adres: " << &j << endl;

    // ════════════════════════════════════════════════════════════════
    // BÖLÜM D: FOR DÖNGÜSÜ j'Yİ SIFIRLAMAZ, KALDIĞI YERDEN DEVAM EDER
    // ════════════════════════════════════════════════════════════════
    //
    // for (; j <= 55; j++)
    //      ↑
    //   BAŞLANGIÇ BOŞ → tanım YOK, atama YOK. Döngü yeni nesne
    //   oluşturmaz; main'deki mevcut j nesnesini kullanır.
    //
    // Döngü başlarken j = 51 olduğu için GÖVDE 5 KEZ çalışır (1'den değil,
    // 51'den başladı). Gövdenin gördüğü değerler: 51, 52, 53, 54, 55.
    //
    // TUR TUR İZLEME (kontrol → gövde → j++):
    //   j=51 → (51<=55) DOĞRU → gövde: cout 51 → j++ → j=52
    //   j=52 → (52<=55) DOĞRU → gövde: cout 52 → j++ → j=53
    //   j=53 → (53<=55) DOĞRU → gövde: cout 53 → j++ → j=54
    //   j=54 → (54<=55) DOĞRU → gövde: cout 54 → j++ → j=55
    //   j=55 → (55<=55) DOĞRU → gövde: cout 55 → j++ → j=56
    //   j=56 → (56<=55) YANLIŞ → GÖVDEYE GİRİLMEZ → döngü biter
    //
    // !! DİKKAT !! 56 değerinde gövde ÇALIŞMAZ. 56 sadece son j++ ile
    // nesneye yazılır ve koşul kontrolünde elenir. Bu yüzden döngü İÇİNDEKİ
    // cout hiçbir zaman 56 görmez.
    //
    // Döngü bitince j nesnesi ölmez (main'in scope'una aittir), içinde
    // 56 kalır. Döngü SONRASINDAKİ cout (satır 4) bu yüzden 56 yazar.
    //
    // Döngü içinde de, döngü sonrasında da ADRES AYNIDIR. "Hep aynı nesne"
    // iddiasının çalışan kanıtı budur.
    //
    // NESNENİN ZAMAN İÇİNDEKİ DEĞERİ VE KİMİN OKUDUĞU:
    //   satır 1          : nesne = 1
    //   satır 2          : nesne = 50
    //   satır 3          : nesne = 51
    //   gövde (5 tur)    : cout 51, 52, 53, 54, 55 okur
    //   son j++          : nesne = 56 (gövde bunu görmez)
    //   koşul kontrolü   : (56<=55) YANLIŞ → döngü biter
    //   satır 4          : cout 56 okur (döngü DIŞINDA)
    //
    // CPU satırları YUKARIDAN AŞAĞIYA sırayla yürütür; her satır, bir
    // önceki satırın bıraktığı değerden devam eder.
    //
    // SON DEĞER KURALI: Sayaç, koşulu İLK KEZ BOZAN değerle sona erer.
    // Sıra: ARTIR → KONTROL ET → GİR YA DA ÇIK.
    //
    // ════════════════════════════════════════════════════════════════

    {
        int j = 100;
        cout << "5) ic blok, int j (golge) : " << j << "  adres: " << &j << endl;
    }

    // ════════════════════════════════════════════════════════════════
    // BÖLÜM E: GÖLGELEME (SHADOWING / NAME HIDING)
    // ════════════════════════════════════════════════════════════════
    //
    // İç blokta satırın başında TÜR var → bu bir TANIM → YENİ NESNE.
    //
    //   Dış j : adres A  → değeri 56  (yaşıyor, dokunulmadı)
    //   İç  j : adres B  → değeri 100 (yeni nesne, FARKLI adres)
    //
    // İsim aynı, nesneler AYRI. Derleyici iç blokta "j" ismini EN YAKIN
    // tanıma bağlar; dış j'nin ismi bu blokta GİZLENİR (name hiding).
    // Dış nesne ise bellekte yaşamaya devam eder, sadece bu blokta o
    // isimle ona ulaşılamaz.
    //
    // İç blok } ile kapanınca iç j nesnesinin ömrü biter (yok edilir).
    // Dış j'ye hiçbir şey olmaz.
    //
    // !! TUZAK !! Dış j'yi güncellediğini sanırken iç j'yi güncellersin.
    // Derleyici varsayılan olarak uyarmaz; -Wshadow bayrağı ile uyarır.
    // Pratik kural: iç scope'ta dış değişkenle AYNI ismi kullanma.
    //
    // ════════════════════════════════════════════════════════════════

    cout << "6) dis j geri geldi       : " << j << "  adres: " << &j << endl;

    // ════════════════════════════════════════════════════════════════
    // BÖLÜM F: DIŞ j NEDEN "GERİ GELDİ"?
    // ════════════════════════════════════════════════════════════════
    //
    // Hiç gitmemişti. Dış j nesnesinin ömrü main'in sonuna kadardır.
    // İç blokta sadece İSMİ gizlenmişti. Blok bitince isim gizliliği
    // kalktı. Değer hâlâ 56, adres hâlâ A.
    //
    // ════════════════════════════════════════════════════════════════

    {
        j = 200;
        cout << "7) ic blok, j = 200       : " << j << "  adres: " << &j << endl;
    }

    // ════════════════════════════════════════════════════════════════
    // BÖLÜM G: İÇ BLOKTA TÜRSÜZ ATAMA → DIŞ NESNE DEĞİŞİR
    // ════════════════════════════════════════════════════════════════
    //
    // Süslü parantez YENİ NESNE OLUŞTURMAZ. Sadece yeni bir SCOPE
    // sınırı çizer. Yeni nesneyi oluşturan şey TANIM'dır (int j).
    //
    // Burada tür yok → atama → derleyici ismi çözümler (name lookup):
    //   1) Önce en içteki scope'a bakar: j tanımı var mı? YOK.
    //   2) Bir dış scope'a (main'in gövdesi) çıkar: j tanımı VAR → bağla.
    //
    // Bu çözümleme DERLEME ZAMANINDA yapılır. Çalışırken CPU "dışarı
    // çıkmaz"; doğrudan A adresine 200 yazar. Çıktıda adres, satır 1'deki
    // ile AYNIDIR.
    //
    // ÖZET KARŞILAŞTIRMA:
    //   { j = 200;     }  → dış nesne değişir, blok sonrası da 200 görürsün
    //   { int j = 200; }  → yeni nesne, blok sonunda yok olur, dış j etkilenmez
    //
    // ════════════════════════════════════════════════════════════════

    cout << "8) blok sonrasi           : " << j << "  adres: " << &j << endl;

    // 8. satır: 200 yazar. Kalıcı değişiklik, çünkü dış nesne güncellendi.

    for (int j = 0; j < 2; j++)
    {
        cout << "9) for(int j) golge       : " << j << "  adres: " << &j << endl;
    }

    // ════════════════════════════════════════════════════════════════
    // BÖLÜM H: for (int j ...) = İÇ BLOKTAKİ int j İLE AYNI ŞEY
    // ════════════════════════════════════════════════════════════════
    //
    // for'un başlangıç kısmına TÜR yazınca (int j = 0), bu bir TANIM olur.
    // O j, for'un kendi scope'una aittir ve dış j'yi GİZLER.
    //
    // Fark for ile süslü parantez arasında DEĞİL, TÜR yazıp yazmamadadır:
    //
    //   for (; j <= 55; j++)       → tür yok → dış nesne kullanılır
    //   for (int j = 0; ...)       → tür var → yeni nesne, farklı adres
    //   { int j = 100; }           → tür var → yeni nesne, farklı adres
    //   { j = 100; }               → tür yok → dış nesne kullanılır
    //
    // Çıktıda satır 9'un adresi, dış j'nin adresinden FARKLIDIR. Döngü
    // bitince bu j nesnesinin ömrü biter.
    //
    // ════════════════════════════════════════════════════════════════

    cout << "10) for sonrasi dis j     : " << j << "  adres: " << &j << endl;

    // Dış j hâlâ 200 ve adres A. for içindeki gölge j onu etkilemedi.

    j = 5;
    cout << "11) son atama             : " << j << "  adres: " << &j << endl;

    // ════════════════════════════════════════════════════════════════
    // BÖLÜM I: AYNI SCOPE'TA İKİNCİ TANIM → DERLEME HATASI
    // ════════════════════════════════════════════════════════════════
    //
    // Yukarıdaki j = 5; yerine şunu yazsaydık:
    //
    //   int j = 5;      // ❌ error: redefinition of 'int j'
    //
    // Sebep: Bu satır, ilk int j = 1; ile AYNI scope'tadır (main'in
    // gövdesi). Bir scope içinde aynı isim yalnızca BİR KEZ tanımlanabilir.
    // Derleyici programı hiç derlemez.
    //
    //   Farklı (iç) scope'ta aynı isim → ✓ izinli (gölgeleme)
    //   Aynı scope'ta aynı isim        → ❌ derleme hatası
    //
    // "Süslü parantezin dışı" yeni bir scope DEĞİLDİR; zaten j'nin
    // yaşadığı scope'tur. Yeni scope ancak yeni bir { } açınca oluşur.
    //
    // PRATİK TEST: j'yi tanımlayan satırla aynı { } seviyesinde misin?
    // Evet → ikinci tanım hata. Bir { } daha içeride misin? → serbest.
    //
    // ════════════════════════════════════════════════════════════════

    return 0;
}

// ╔══════════════════════════════════════════════════════════════════════╗
// ║  BÖLÜM J: ÖMÜR (LIFETIME) VE SCOPE — TEK KURAL                        ║
// ╠══════════════════════════════════════════════════════════════════════╣
// ║  Otomatik bir nesnenin ömrü, TANIMLANDIĞI satırdan, o satırı         ║
// ║  içeren { } bloğunun KAPANIŞINA kadardır.                            ║
// ║                                                                      ║
// ║  Tanımlandığı yer     → Ömrü             → Erişim                    ║
// ║  main içinde          → main bitince      → main'in her yerinden ✓   ║
// ║  for (int i...)       → for bitince       → dışarıdan ❌             ║
// ║  { } iç bloğu         → } kapanınca       → dışarıdan ❌             ║
// ║                                                                      ║
// ║  Kavram ayrımı:                                                      ║
// ║  • SCOPE   = bir ismin kaynak kodda GEÇERLİ olduğu bölge             ║
// ║              (derleme zamanı kavramı)                                ║
// ║  • LIFETIME= bir nesnenin bellekte YAŞADIĞI süre                     ║
// ║              (çalışma zamanı kavramı)                                ║
// ║  Gölgelemede ikisi ayrışır: dış j'nin scope'u iç blokta kesintiye    ║
// ║  uğrar (isim gizlenir) ama lifetime'ı kesilmez (nesne yaşar).        ║
// ╚══════════════════════════════════════════════════════════════════════╝

// ╔══════════════════════════════════════════════════════════════════════╗
// ║  BÖLÜM K: DERLEYİCİ Mİ, CPU MU?                                       ║
// ╠══════════════════════════════════════════════════════════════════════╣
// ║  Sık yapılan zihinsel hata: "Derleyici satır satır çalışıp döngüden  ║
// ║  çıkıp main'e dönerek j'yi güncelliyor."                             ║
// ║                                                                      ║
// ║  GERÇEK:                                                             ║
// ║  • DERLEYİCİ (compile time): kodu BİR KEZ makine koduna çevirir ve   ║
// ║    biter. Program çalışırken ortada YOKTUR. İsim çözümleme (name     ║
// ║    lookup), scope kontrolü, redefinition hatası hep derleme zamanı   ║
// ║    işleridir.                                                        ║
// ║  • CPU (runtime): derlenmiş talimatları sırayla yürütür. Döngüdeki   ║
// ║    "yukarı çıkma", CPU'nun bir JUMP talimatıyla program sayacını     ║
// ║    (instruction pointer) geri bir talimata ayarlamasıdır.            ║
// ║  • for döngüsü main'in DIŞINDA ayrı bir yer değildir; main'in        ║
// ║    gövdesinin parçasıdır. { } sadece scope sınırıdır, CPU'yu başka   ║
// ║    yere taşımaz. Hepsi aynı stack çerçevesindedir (stack frame).     ║
// ║  • j++ çalışırken CPU "main'e çık" demez; doğrudan nesnenin          ║
// ║    ADRESİNE gider: oku → 1 ekle → aynı adrese yaz.                   ║
// ╚══════════════════════════════════════════════════════════════════════╝

// ╔══════════════════════════════════════════════════════════════════════╗
// ║                           GENEL ÖZET                                 ║
// ╠══════════════════════════════════════════════════════════════════════╣
// ║  1. Değişken = isim + nesne + bellek adresi. İsim sadece derleme     ║
// ║     zamanında vardır, çalışırken sadece adres kalır.                 ║
// ║  2. int j = ...  (tür var) → TANIM + İLKLENDİRME → yeni nesne.       ║
// ║  3. j = ...      (tür yok) → ATAMA → mevcut nesnenin değeri değişir. ║
// ║  4. Her atama eski değerin ÜZERİNE yazar; eski değer saklanmaz.      ║
// ║  5. Nesnenin adresi, ömrü boyunca SABİTTİR; sadece değeri değişir.   ║
// ║  6. Nesne, tanımlandığı { } kapanana kadar yaşar (lifetime).         ║
// ║  7. Satırlar yukarıdan aşağıya sırayla yürür; her satır bir öncekinin║
// ║     bıraktığı değerden devam eder.                                   ║
// ║  8. for'un başlangıcı boşsa j SIFIRLANMAZ, kalınan değerden devam.   ║
// ║  9. Döngü gövdesi son değerde (56) ÇALIŞMAZ; 56'yı yalnızca döngü    ║
// ║     SONRASI cout görür.                                              ║
// ║ 10. { } yeni nesne oluşturmaz; yeni nesneyi TANIM (tür yazmak) yapar.║
// ║ 11. İç scope'ta aynı isimle tanım = gölgeleme (farklı adres).        ║
// ║ 12. İç scope'ta türsüz atama = isim dışarıda aranır, dış nesne       ║
// ║     değişir.                                                         ║
// ║ 13. Aynı scope'ta ikinci tanım = redefinition derleme hatası.        ║
// ║ 14. Scope = derleme zamanı, lifetime/adres = çalışma zamanı.         ║
// ║ 15. Modern C++: değişkeni mümkün olan EN DAR scope'ta tanımla ve     ║
// ║     gölgelemeden kaçın (-Wshadow ile derle).                         ║
// ╚══════════════════════════════════════════════════════════════════════╝

// ╔══════════════════════════════════════════════════════════════════════╗
// ║  BEKLENEN ÇIKTI (adresler makineye göre değişir; önemli olan         ║
// ║  hangilerinin EŞİT olduğudur)                                        ║
// ╠══════════════════════════════════════════════════════════════════════╣
// ║  1) tanim sonrasi          : 1    adres: 0x7ffc...a4   ← A           ║
// ║  2) atama sonrasi          : 50   adres: 0x7ffc...a4   ← A           ║
// ║  3) j++ sonrasi            : 51   adres: 0x7ffc...a4   ← A           ║
// ║     dongu icinde           : 51   adres: 0x7ffc...a4   ← A           ║
// ║     dongu icinde           : 52 / 53 / 54  (hepsi A)                 ║
// ║     dongu icinde           : 55   adres: 0x7ffc...a4   ← A           ║
// ║  4) dongu sonrasi          : 56   adres: 0x7ffc...a4   ← A           ║
// ║  5) ic blok, int j (golge) : 100  adres: 0x7ffc...a0   ← B (FARKLI)  ║
// ║  6) dis j geri geldi       : 56   adres: 0x7ffc...a4   ← A           ║
// ║  7) ic blok, j = 200       : 200  adres: 0x7ffc...a4   ← A           ║
// ║  8) blok sonrasi           : 200  adres: 0x7ffc...a4   ← A           ║
// ║  9) for(int j) golge       : 0    adres: 0x7ffc...a0   ← C (FARKLI)  ║
// ║  9) for(int j) golge       : 1    adres: 0x7ffc...a0   ← C           ║
// ║  10) for sonrasi dis j     : 200  adres: 0x7ffc...a4   ← A           ║
// ║  11) son atama             : 5    adres: 0x7ffc...a4   ← A           ║
// ║                                                                      ║
// ║  NOT: B ve C aynı adreste çıkabilir (biri ölünce stack alanı yeniden ║
// ║  kullanılır). Sorun değil: ömürleri çakışmıyor. KURAL: ömürleri      ║
// ║  çakışan iki nesne aynı adreste olamaz; A hiçbir zaman B veya C ile  ║
// ║  aynı olmaz.                                                         ║
// ║                                                                      ║
// ║  DERLEME: g++ -std=c++17 -Wshadow dosya.cpp                          ║
// ║  (5. ve 9. satırlar için gölgeleme uyarısı görürsün; örnekler        ║
// ║  bilerek öyle yazıldı, gerçek projede böyle yazma.)                  ║
// ╚══════════════════════════════════════════════════════════════════════╝