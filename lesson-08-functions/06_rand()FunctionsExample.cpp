#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rastgeleSayiUret(int min, int max)
{
    int rastgeleSayi = min + (rand() % (max - min + 1));
    return rastgeleSayi;
}

int main()
{
    cout << "time(0) : " << time(0) << endl;

    srand(time(0));

    int rastgeleSayi1 = rastgeleSayiUret(1, 10);
    cout << "1-10  arasinda rastgele sayi : " << rastgeleSayi1 << endl;

    int rastgeleSayi2 = rastgeleSayiUret(1, 100);
    cout << "1-100 arasinda rastgele sayi : " << rastgeleSayi2 << endl;

    int rastgeleSayi3 = rastgeleSayiUret(50, 75);
    cout << "50-75 arasinda rastgele sayi : " << rastgeleSayi3 << endl;

    return 0;
}


// -------------------------------------------------------
// ACIKLAMA
// -------------------------------------------------------
//
// NEDEN FONKSIYON?
//   Ayni formulu her aralik icin tekrar yazmak yerine
//   bir kez tanimlayip farkli parametrelerle cagiriyoruz.
//   Buna DRY (Don't Repeat Yourself) prensibi denir.
//
// FONKSIYON IMZASI: int rastgeleSayiUret(int min, int max)
//   int min : aralik baslangici (dahil)
//   int max : aralik sonu       (dahil)
//   return  : [min, max] araliginda rastgele bir int
//
// FORMUL: min + (rand() % (max - min + 1))
//
//   ADIM 1 — (max - min + 1)
//     Araliktaki toplam eleman sayisini verir.
//     Ornek: min=5, max=10 → 10 - 5 + 1 = 6
//     Cunku: 5,6,7,8,9,10 → 6 farkli sayi
//
//   ADIM 2 — rand() % 6
//     Modulo her zaman [0, N-1] araliginda sayi uretir.
//     41 % 6 = 5  |  37 % 6 = 1  |  100 % 6 = 4
//     Sonuc: [0, 5]
//
//   ADIM 3 — min + sonuc
//     [0, 5] araligini [5, 10] araligina kaydiririr.
//     0+5=5 | 1+5=6 | 2+5=7 | 3+5=8 | 4+5=9 | 5+5=10
//
// srand(time(0)):
//   Her calistirmada farkli seed → farkli sayi dizisi.
//   Programda YALNIZCA BIR KEZ, en basta cagirilir.
