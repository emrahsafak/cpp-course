// ╔══════════════════════════════════════════════════════════════╗
// ║              FOR DÖNGÜSÜ — TAM ANLATIM DOSYASI              ║
// ╚══════════════════════════════════════════════════════════════╝

#include <iostream>
using namespace std;

int main()
{
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



    // ════════════════════════════════════════════════════════════
    // BÖLÜM 2: ADIM ADIM TAKİP — i <= 10 örneği
    // ════════════════════════════════════════════════════════════

    for (int i = 1; i <= 10; i++)
    {
        // ADIM 1 (sadece bir kez): int i = 1 → i hayata gelir
        // ADIM 2: i <= 10 mu? → EVET (1<=10) → bloğa gir
        // ADIM 3: Bloğu çalıştır
        // ADIM 4: i++ → i = 2
        // ADIM 2: i <= 10 mu? → EVET (2<=10) → bloğa gir
        // ...devam eder...
        // ADIM 2: i <= 10 mu? → HAYIR (11<=10 YANLIŞ) → DÖNGÜ BİTER

        if (i % 2 == 0)     // % = modulo (bölümden kalan)
                             // 4 % 2 = 0 → çift sayı ✓
                             // 5 % 2 = 1 → tek sayı  ✗
            cout << "Cift: " << i << endl;
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

    cout << endl << "Tek sayilar (1'den, 2'ser 2'ser):" << endl;

    for (int i = 1; i <= 15; i += 2)
    {
        // i=1  → 1 yazdır  → i=1+2=3
        // i=3  → 3 yazdır  → i=3+2=5
        // i=5  → 5 yazdır  → i=5+2=7
        // i=7  → 7 yazdır  → i=7+2=9
        // i=9  → 9 yazdır  → i=9+2=11
        // i=11 → 11 yazdır → i=11+2=13
        // i=13 → 13 yazdır → i=13+2=15
        // i=15 → 15 yazdır → i=15+2=17
        // i=17 → koşul (17<=15) YANLIŞ → DÖNGÜ BİTTİ
        cout << " " << i;
    }

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

    for (int i = 1; i <= 15; i++)   // i burada DOĞDU
    {                                // ← i'nin scope'u BAŞLADI
        cout << " " << i;
    }                                // ← i'nin scope'u BİTTİ → i ÖLDÜ

    // ❌ cout << i;   → DERLEME HATASI — i artık yok

    // KANITLA — dışarıda tanımlarsan:
    int j = 1;                       // j'nin scope'u = main'in tamamı

    for (; j <= 15; j++)             // BAŞLANGIÇ BOŞ → j zaten tanımlı
    {
        cout << " " << j;
    }                                // for bitti → ama j hâlâ canlı!

    cout << endl;
    cout << "j'nin son degeri: " << j << endl;   // ✓ ÇALIŞIR → j = 16

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
