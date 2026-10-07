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
    // ├──────────┼───