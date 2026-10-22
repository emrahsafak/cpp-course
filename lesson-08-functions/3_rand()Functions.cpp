```cpp
#include <iostream>
#include <cstdlib>   // rand() ve srand() fonksiyonlari icin gerekli
#include <ctime>     // time() fonksiyonu icin gerekli

using namespace std;

int main()
{
    // time(0) : 1970-01-01 00:00:00 UTC'den itibaren gecen saniye sayisini dondurur.
    srand(time(0));
    cout << " time(0) : " << time(0) << endl;

    int rastgeleSayi = rand();
    cout << " Uretilen rastgele sayi : " << rastgeleSayi << endl;

    // 2. ornek
    // 1-10 arasinda bir sayi uretmek.
    int rastgeleSayi2 = (rand() % 10) + 1;
    cout << " 1-10 arasinda uretilen rastgele sayi : " << rastgeleSayi2 << endl;

    // 3. ornek
    // 1-100 arasinda bir sayi uretmek.
    int rastgeleSayi3 = (rand() % 100) + 1;
    cout << " 1-100 arasinda uretilen rastgele sayi : " << rastgeleSayi3 << endl;

    return 0;
}


// -------------------------------------------------------
//  BOLUM 2 — HOCANIN KODUNUN SATIR SATIR ACIKLAMASI
// -------------------------------------------------------
//
//  SATIR: srand(time(0));
//  srand() : rand() icin baslangic noktasini (seed) belirler.
//  time(0) : her saniye farkli deger dondurur → farkli seed
//            → farkli sayi dizisi.
//  KURAL   : srand() programda YALNIZCA BIR KEZ, en basta cagirilir.
//
//  SATIR: cout << " time(0) : " << time(0) << endl;
//  time(0)'in Unix Timestamp degerini ekrana yazdirir.
//  Ornek cikti: 1748392847  (her saniye 1 artar)
//
//  SATIR: int rastgeleSayi = rand();
//  rand() : 0 ile RAND_MAX arasinda rastgele int uretir.
//  RAND_MAX: Windows(MSVC) = 32767 | Linux/macOS = 2147483647
//
//  SATIR: int rastgeleSayi2 = (rand() % 10) + 1;
//  rand() % 10 : her zaman [0, 9] araliginda sayi verir.
//    41 % 10 = 1  |  37 % 10 = 7  |  100 % 10 = 0
//  + 1 eklemek : [0, 9] → [1, 10] araligina tasir.
//
//  SATIR: int rastgeleSayi3 = (rand() % 100) + 1;
//  rand() % 100 : her zaman [0, 99] araliginda sayi verir.
//  + 1 eklemek  : [0, 99] → [1, 100] araligina tasir.


// -------------------------------------------------------
//  BOLUM 3 — GENEL KONU: rand() ve srand() MEKANIGI
// -------------------------------------------------------
//
//  rand() NEDEN HEP AYNI SAYIYI URETIR? (srand() OLMADAN)
//  rand() deterministik bir algoritmadir. LCG kullanir:
//      X(n+1) = (a * X(n) + c) mod m
//  srand() cagrilmazsa seed = 1 → ilk cikti cogu sistemde 41.
//
//  AKIS:
//  srand(time(0)) → Seed = X (her saniye farkli)
//      |
//      v
//  rand() → [a*X + c mod m] → Sayi_1
//      |
//      v
//  rand() → [a*Sayi_1 + c mod m] → Sayi_2
//
//  GENEL ARALIK FORMULU:
//  [MIN, MAX] araligi icin:
//      (rand() % (MAX - MIN + 1)) + MIN
//
//  Ornekler:
//    [1,   6] → (rand() % 6)  + 1   (zar atisi)
//    [50, 75] → (rand() % 26) + 50
//
//  0 vs nullptr:
//  time(0)       : C stili, calisir
//  time(nullptr) : C++11 stili, tip-guvenli, modern tercih
//
//  PROFESYONEL NOT:
//  rand() uretim kodunda onerilmez. Modern alternatif: <random>
//    - mt19937              : Mersenne Twister, yuksek kalite
//    - uniform_int_distribution : modulo sapmasini ortadan kaldirir
//    - random_device        : gercek donanim entropisi
```
