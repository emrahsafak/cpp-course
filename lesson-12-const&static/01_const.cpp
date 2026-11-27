// =====================================================================
// const
// =====================================================================
//
// ---------------------------------------------------------------------
// 0. HARITA
// ---------------------------------------------------------------------
// Bu konunun dayandigi kavram cifti:
//   compile-time  : derleyicinin, program CALISMADAN once bildigi deger
//   run-time      : ancak program calisirken ortaya cikan deger
// const bu ikisini AYIRMAZ. const sadece "degismez" der, "ne zaman
// bilindigi" sorusu constexpr'in isidir (bolum 4).
//
//   1. const degisken: tanim ve iki kural            [CEKIRDEK]
//   2. Neden const? Derleyiciyi bekci yapmak         [ANLA]
//   3. const fonksiyon parametresi                   [CEKIRDEK]
//   4. const vs constexpr vs #define                 [ANLA]
//
// OKUMA ROTASI
//   ilk tur   : 1 -> 3   (kod yazmak icin yeterli, burada durabilirsin)
//   ikinci tur: 2 -> 4   (nedenini anlamak icin, ezberlenmez)
//
// HER SEYI UNUTURSAN SUNLARI TUT:
//   - const degisken TANIMLANDIGI SATIRDA deger almak zorunda.
//   - Sonra ona atama yapmak COMPILE ERROR'dur, runtime hatasi degil.
//   - Degismeyecek her sey const olsun. Varsayilan const, istisna degisken.
//
// Takilirsan: okumayi birak, bir const yaz, ona atama yap, hatayi oku.
// ---------------------------------------------------------------------

#include <iostream>

using namespace std;

// ---------------------------------------------------------------------
// 1. const DEGISKEN: TANIM VE IKI KURAL                     [CEKIRDEK]
// ---------------------------------------------------------------------
// const, tipin onune gelen bir niteleyicidir (qualifier):
//     const double pi = 3.14;
// Anlami: "pi adiyla bu bellek bolgesine bu isim uzerinden YAZILAMAZ."
//
// KURAL 1: Ilk deger tanim aninda verilir.
//   Sonradan atama yasak oldugu icin, tanimda verilmezse degiskene
//   bir daha hic deger verilemez. Derleyici bunu bastan reddeder.
//
// KURAL 2: Tanimdan sonra atama yapilamaz.
//   Bu kontrol DERLEME aninda yapilir. Program hic olusmaz.
//   Yani hata kullanicinin elinde degil, senin masanda patlar.
//
// Kursta gordugun durum: once "double x; x = 3.15;" calisti, ama
// "const double pi = 3.14;" sonrasi "pi = 3.15;" hata verdi.
// Fark: x normal degisken, pi const.
// ---------------------------------------------------------------------
namespace bolum1
{
    void demo()
    {
        const double pi = 3.14;     // KURAL 1: tanimda deger verildi
        double x;                   // normal degisken: deger sonra verilebilir
        x = 3.15;                   // serbest

        // pi = 3.15;
        // HATA (g++): assignment of read-only variable 'pi'
        // (Visual Studio: "ifade degistirilebilir bir lvalue olmalidir")

        // const int bos;
        // HATA (g++): uninitialized 'const bos' [-fpermissive]

        cout << "1) pi = " << pi << ", x = " << x << '\n';

        // const okumayi engellemez, sadece yazmayi.
        // pi'yi istedigin kadar hesapta kullanabilirsin:
        const double r = 2.0;
        cout << "   daire alani = " << pi * r * r << '\n';
    }
}

// ---------------------------------------------------------------------
// 2. NEDEN const? DERLEYICIYI BEKCI YAPMAK                      [ANLA]
// ---------------------------------------------------------------------
// const performans icin degil, DOGRULUK icin vardir.
//
// Muhendislik paraleli: fizik sabitleri (g = 9.81, c = 3e8) bir
// hesabin ortasinda degismez. Bir formulde yanlislikla g'nin uzerine
// yazarsan, sonraki her hesap sessizce yanlis cikar. const bu
// "sessiz" hatayi "sesli" hale getirir: derleyici seni durdurur.
//
// C# paraleli: C#'taki 'const' ve 'readonly' ikilisinin karsiligi.
// C++ const, C#'taki readonly'ye daha yakindir: deger runtime'da da
// gelebilir (bolum 4'te gosteriliyor).
//
// Profesyonel aliskanlik:
//   - Bir degisken tanimlarken once "bu degisecek mi?" diye sor.
//   - Cevap hayirsa const yaz. Kodu okuyan kisi (6 ay sonraki sen)
//     o degiskenin asagida degismedigini aramadan bilir.
//   - "Magic number" yazma: 0.18 yerine const double kdvOrani = 0.18;
// ---------------------------------------------------------------------
namespace bolum2
{
    void demo()
    {
        const double g = 9.81;          // fizik sabiti, degismemeli
        const double t = 2.0;           // olcum: bir kez alindi, sabit

        const double yol = 0.5 * g * t * t;   // hesap sonucu da degismeyecek
        cout << "2) serbest dusme, 2 s: " << yol << " m\n";
    }
}

// ---------------------------------------------------------------------
// 3. const FONKSIYON PARAMETRESI                            [CEKIRDEK]
// ---------------------------------------------------------------------
// Parametre de bir yerel degiskendir. Onu da const yapabilirsin:
//     double kdvEkle(const double fiyat)
// Anlami: "fonksiyon govdesinde fiyat'in uzerine yazilmayacak."
//
// Burada dikkat: deger ile gecen (call by value) parametre zaten
// bir KOPYADIR. Fonksiyon onu degistirse bile cagiranin degiskeni
// etkilenmez. Yani buradaki const cagirani korumaz, sadece
// fonksiyonun KENDI ICINDE yanlislikla atama yapmasini engeller.
//
// const'in parametrede gercek gucu "const referans" ile gelir:
// buyuk bir nesneyi kopyalamadan, degistirmeden okumak. Bu kursta
// Call by Reference bolumunde gelecek; o zaman bu bolume geri don.
// ---------------------------------------------------------------------
namespace bolum3
{
    double kdvEkle(const double fiyat)
    {
        const double kdvOrani = 0.20;

        // fiyat = fiyat * 2;
        // HATA (g++): assignment of read-only parameter 'fiyat'

        return fiyat * (1.0 + kdvOrani);
    }

    void demo()
    {
        double urun = 100.0;            // cagiranin degiskeni const degil
        double sonuc = kdvEkle(urun);   // kopyasi fonksiyona gider
        cout << "3) " << urun << " TL + KDV = " << sonuc << " TL\n";
    }
}

// ---------------------------------------------------------------------
// 4. const vs constexpr vs #define                              [ANLA]
// ---------------------------------------------------------------------
// const   : "degismez". Deger runtime'da da gelebilir.
//           const int n = kullanicidanGelen;   // GECERLI
// constexpr: "degismez VE derleme aninda biliniyor". Derleyici degeri
//           hesaplayamiyorsa hata verir. Dizi boyutu gibi derleyicinin
//           ONCEDEN bilmesi gereken yerlerde kullanilir. (C++11)
// #define : C'den kalma. Derleyici degil, preprocessor metni duz
//           kopyala-yapistir yapar. Tipi yok, scope'u yok, debugger
//           gormez. Modern C++'ta sabit icin KULLANMA.
//
//   +-----------+--------------+--------------+-------+
//   |           | degistirilir | derleme aninda| tipi  |
//   +-----------+--------------+--------------+-------+
//   | const     | hayir        | sart degil   | var   |
//   | constexpr | hayir        | SART         | var   |
//   | #define   | (metin)      | (metin)      | yok   |
//   +-----------+--------------+--------------+-------+
//
// Pratik kural: derleme aninda bilinen sabit -> constexpr,
//               runtime'da bir kez belirlenen deger -> const.
// ---------------------------------------------------------------------
namespace bolum4
{
    int kareAl(int a) { return a * a; }

    void demo()
    {
        int girdi = 7;                  // runtime degeri gibi dusun
        const int n = kareAl(girdi);    // const: runtime'da belirlendi, sonra kilitlendi

        constexpr int boyut = 5;        // derleme aninda biliniyor
        int dizi[boyut] = {1, 2, 3, 4, 5};   // dizi boyutu icin uygun

        // constexpr int m = kareAl(girdi);
        // HATA (g++): call to non-'constexpr' function 'int kareAl(int)'
        // Derleyici kareAl'i derleme aninda calistiramaz, deger runtime'a kalir.

        cout << "4) n = " << n << ", dizi[boyut-1] = " << dizi[boyut - 1] << '\n';
    }
}

// ---------------------------------------------------------------------
int main()
{
    bolum1::demo();
    bolum2::demo();
    bolum3::demo();
    bolum4::demo();
    return 0;
}

// COMPILE: g++ -std=c++17 -Wall -Wextra const.cpp -o program
