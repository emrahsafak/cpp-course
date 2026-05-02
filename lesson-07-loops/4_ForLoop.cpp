#include <iostream>
using namespace std;

int main()
{
    // ═══════════════════════════════════════════════
    // FOR DÖNGÜSÜNÜN YAPISI:
    // for ( BAŞLANGIÇ ; KOŞUL ; GÜNCELLEME )
    //         ↓           ↓          ↓
    //    Sadece BİR    Her adımda   Blok her
    //    kez çalışır  kontrol       çalışınca
    //                 edilir        çalışır
    // ═══════════════════════════════════════════════

    for (int i = 1; i <= 10; i++)
    {
        // ── ADIM 1 (sadece bir kez): int i = 1
        //    → i değişkeni hayata gelir, değeri = 1
        //
        // ── ADIM 2: i <= 10 mı?  → EVET (1 <= 10) → bloğa gir
        // ── ADIM 3: Bloğu çalıştır (çift mi kontrol et, yazdır)
        // ── ADIM 4: i++  → i artık 2 oldu
        //
        // ── ADIM 2: i <= 10 mı?  → EVET (2 <= 10) → bloğa gir
        // ── ADIM 3: Bloğu çalıştır
        // ── ADIM 4: i++  → i artık 3 oldu
        //
        // ...bu döngü devam eder...
        //
        // ── ADIM 2: i <= 10 mı?  → HAYIR (11 <= 10 YANLIŞ) → DÖNGÜ BITER

        if (i % 2 == 0)     // % "modulo" operatörü = bölümden kalan
                             // 4 % 2 = 0 → çift sayı  ✓
                             // 5 % 2 = 1 → tek sayı   ✗
            cout << "Cift: " << i << endl;
    }

    cout << endl;

    // ═══════════════════════════════════════════
    // İKİNCİ DÖNGÜ — adım adım tam takip:
    // ═══════════════════════════════════════════

    for (int i = 1; i <= 15; i++)
    {
        // Adım 01: i=1  → koşul (1<=15)  DOĞRU  → 1 yazdır  → i=2 oldu
        // Adım 02: i=2  → koşul (2<=15)  DOĞRU  → 2 yazdır  → i=3 oldu
        // Adım 03: i=3  → koşul (3<=15)  DOĞRU  → 3 yazdır  → i=4 oldu
        // Adım 04: i=4  → koşul (4<=15)  DOĞRU  → 4 yazdır  → i=5 oldu
        // Adım 05: i=5  → koşul (5<=15)  DOĞRU  → 5 yazdır  → i=6 oldu
        // Adım 06: i=6  → koşul (6<=15)  DOĞRU  → 6 yazdır  → i=7 oldu
        // Adım 07: i=7  → koşul (7<=15)  DOĞRU  → 7 yazdır  → i=8 oldu
        // Adım 08: i=8  → koşul (8<=15)  DOĞRU  → 8 yazdır  → i=9 oldu
        // Adım 09: i=9  → koşul (9<=15)  DOĞRU  → 9 yazdır  → i=10 oldu
        // Adım 10: i=10 → koşul (10<=15) DOĞRU  → 10 yazdır → i=11 oldu
        // Adım 11: i=11 → koşul (11<=15) DOĞRU  → 11 yazdır → i=12 oldu
        // Adım 12: i=12 → koşul (12<=15) DOĞRU  → 12 yazdır → i=13 oldu
        // Adım 13: i=13 → koşul (13<=15) DOĞRU  → 13 yazdır → i=14 oldu
        // Adım 14: i=14 → koşul (14<=15) DOĞRU  → 14 yazdır → i=15 oldu
        // Adım 15: i=15 → koşul (15<=15) DOĞRU  → 15 yazdır → i=16 oldu
        // Adım 16: i=16 → koşul (16<=15) YANLIŞ → DÖNGÜ SONA ERDİ. i yok oldu.

        cout << " " << i;
    }

    return 0;
}
