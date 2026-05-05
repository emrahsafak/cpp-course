// ============================================================
//
//   C++ DERS NOTLARI
//   Konu : Fonksiyon Tasarimi & Sorumluluk Ayrimi
//
//   Icindekiler:
//     [1] Yanlis Yaklasim   — Anti-Pattern
//     [2] Dogru Yaklasim    — Separation of Concerns
//     [3] Kara Kutu Modeli  — Ne demek, neden onemli?
//     [4] Yeniden Kullanim  — Ayni fonksiyon, farkli degerler
//     [5] Fonksiyon Zinciri — Ciktiyi baska fonksiyona ver
//     [6] Orkestrator main  — main() ne is yapar?
//     [7] void vs int       — Ne zaman hangisini kullan?
//     [8] Gelecege Not      — Referans parametreler (int&)
//
// ============================================================

#include <iostream>
#include <cmath>        // sqrt(), M_PI icin
using namespace std;


// ============================================================
//  [1] YANLIS YAKLASIM — Anti-Pattern
//
//  Sorun: Fonksiyon hem kullaniciyla konusuyor
//         hem hesapliyor hem ekrana yazdiriyor.
//         Uc farkli is ayni fonksiyonda — "karmasik sorumluluk" hatasidir.
//
//  Sonuc: Bu fonksiyonu baska bir yerde KULLANAMAZSIN.
//         Her cagirdiginda cin devreye girer, kullanici girisi bekler.
//         Test etmek, tekrar kullanmak, degistirmek zordur.
// ============================================================

int YANLIS_alanHesaplama()
{
    int x, y;

    cout << "Kisa kenar: ";
    cin  >> x;                    // kullanici arayuzu

    cout << "Uzun kenar: ";
    cin  >> y;                    // kullanici arayuzu

    int alan = x * y;             // hesaplama

    cout << "Alan: " << alan;     // cikti — uc farkli is ayni yerde, KOTU

    return alan;
}

// Neden kotu? Simdi dusun:
//
//   int alan1 = YANLIS_alanHesaplama();      // kullanici girisi bekler
//   int alan2 = YANLIS_alanHesaplama();      // TEKRAR kullanici girisi bekler
//   int alan3 = YANLIS_alanHesaplama(5, 10); // HATA — parametre veremezsin
//
// Her cagirdiginda kullanici ile konusmak zorunda. Fonksiyon "esir".


// ============================================================
//  [2] DOGRU YAKLASIM — Separation of Concerns
//
//  Kural: Her fonksiyon SADECE tek bir is yapar.
//
//  Uc ayri sorumluluk = Uc ayri fonksiyon:
//    - kullanicidanAl()  => sadece veri toplar
//    - alanHesaplama()   => sadece hesap yapar
//    - sonucuGoster()    => sadece ekrana yazar
// ============================================================

// --------------------------------------------------
//  INPUT Fonksiyonu — Sadece kullanicidan veri alir.
//  Hesaplama YOK. Ekrana yazma YOK.
//
//  "int& x" => referans parametre.
//  Simdilik su sekilde dusun: fonksiyonun disaridaki
//  x ve y degiskenlerini DOGRUDAN doldurabilmesi icin.
//  (Detayli aciklama bolum [8]'de)
// --------------------------------------------------
void kullanicidanAl(int& x, int& y)
{
    cout << "Kisa kenar giriniz: ";
    cin  >> x;

    cout << "Uzun kenar giriniz: ";
    cin  >> y;
}

// --------------------------------------------------
//  HESAPLAMA Fonksiyonu — Sadece matematik yapar.
//  cin YOK. cout YOK. Saf hesaplama.
//
//  Input  : iki int (x, y)
//  Output : int (alan)
// --------------------------------------------------
int alanHesaplama(int x, int y)
{
    return x * y;
    // Bu kadar. Baska hicbir sey bu fonksiyonun isi degil.
}

// --------------------------------------------------
//  OUTPUT Fonksiyonu — Sadece sonucu ekrana yazar.
//  Hesaplama YOK. Input YOK.
//
//  Input  : int (alan)
//  Output : void — geri deger uretmez, sadece is yapar
// --------------------------------------------------
void sonucuGoster(int alan)
{
    cout << "Dikdortgenin alani: " << alan << endl;
}


// ============================================================
//  [3] KARA KUTU MODELI
//
//  Fonksiyonu bir kara kutu gibi dusun:
//
//    [x, y] ---> | alanHesaplama | ---> [alan]
//     input           kara kutu          output
//
//  Kutunun ICINI bilmek zorunda degilsin.
//  Sadece su iki soruyu sorarsın:
//    "Ne verirsem?"  =>  int x, int y
//    "Ne alirim?"    =>  int alan
//
//  Unity'de Mathf.Sqrt(x) kullandiginda icine bakmiyor,
//  hesabin nasil yapildigini dusunmuyorsun.
//  Sayi veriyorsun, sonuc aliyorsun. Ayni mantik.
//
//  Baska ornekler:
// ============================================================

// Ucgen alani: (taban * yukseklik) / 2
// double kullandik cunku bolme islemi ondalikli sonuc uretebilir.
double ucgenAlani(double taban, double yukseklik)
{
    return (taban * yukseklik) / 2.0;
    // Formulden baska hicbir sey yok. Temiz, saf fonksiyon.
}

// Daire alani: PI x r^2
// M_PI sabiti <cmath> kutuphanesinden gelir (PI = 3.14159...)
double daireAlani(double yaricap)
{
    return M_PI * yaricap * yaricap;
}

// Hipotenüs hesabi: c = sqrt(a^2 + b^2)
// sqrt() <cmath>'tan gelir.
double hipotenus(double a, double b)
{
    return sqrt(a * a + b * b);
}


// ============================================================
//  [4] YENIDEN KULLANIM
//
//  Dogru tasarlanmis fonksiyonu istedigin degerle cagirabilirsin.
//  Fonksiyon degismez — sadece farkli input verirsin.
// ============================================================

void yenidenKullanimOrnegi()
{
    cout << "\n--- [4] Yeniden Kullanim ---" << endl;

    // Ayni fonksiyon, tamamen farkli degerler:
    int alan1 = alanHesaplama(5, 10);     // sonuc: 50
    int alan2 = alanHesaplama(3, 7);      // sonuc: 21
    int alan3 = alanHesaplama(100, 200);  // sonuc: 20000

    cout << "5   x 10  = " << alan1 << endl;
    cout << "3   x 7   = " << alan2 << endl;
    cout << "100 x 200 = " << alan3 << endl;

    // Degiskenlerle de calisir:
    int en   = 8;
    int boy  = 12;
    int alan4 = alanHesaplama(en, boy);   // sonuc: 96
    cout << "8   x 12  = " << alan4      << endl;

    // Yanlis yaklasimda (YANLIS_alanHesaplama) bunu yapamazdin.
    // Her satir kullanici girisi beklerdi.
}


// ============================================================
//  [5] FONKSIYON ZINCIRI
//
//  Bir fonksiyonun CIKTISINI baska fonksiyona INPUT olarak verebilirsin.
//  Ara degisken kullanmak zorunda degilsin — ama okunabilirlik icin
//  genelde kullanmak daha iyidir.
// ============================================================

void fonksiyonZinciriOrnegi()
{
    cout << "\n--- [5] Fonksiyon Zinciri ---" << endl;

    // Yontem A — Ara degisken ile (okunakli, tercih edilen):
    int alan = alanHesaplama(6, 9);   // once hesapla, degiskene ata
    sonucuGoster(alan);               // sonra goster

    // Yontem B — Direkt zincir (kisaltilmis ama daha az okunakli):
    sonucuGoster(alanHesaplama(6, 9));
    // alanHesaplama(6, 9) => 54 dondurur
    // sonucuGoster(54)    => ekrana yazar
    // Iki satir, tek satirda — ayni sonuc.

    // Daha uzun bir zincir:
    // Hipotenus'u hesapla, sonucu baska bir hesapta kullan.
    double c   = hipotenus(3.0, 4.0);   // c = 5.0
    double us  = c * c;                 // 25.0
    cout << "Hipotenüs: " << c << " | Karesi: " << us << endl;
}


// ============================================================
//  [6] ORKESTRATOR OLARAK main()
//
//  main() buyuk projelerde su isi yapar:
//    - Dogru fonksiyonlari dogru sirada cagirir.
//    - Kendi basina hesaplama YAPMAZ.
//    - Trafik polisi gibi — yonlendirir, kendisi kosmaz.
//
//  Kucuk projelerde cin/cout main'de olabilir (kabul edilebilir).
//  Buyuk projelerde her sey ayri fonksiyona tasinir.
//
//  main()'in nasil gorunmesi gerektigini asagida goruyorsun.
// ============================================================


// ============================================================
//  [7] void vs int — Ne Zaman Hangisi?
//
//  int  => Fonksiyon bir deger URETIR ve geri verir.
//          O degeri baska yerde kullanabilirsin.
//
//  void => Fonksiyon bir is YAPAR ama deger dondurmez.
//          Sonucu baska yerde kullanamazsin.
// ============================================================

// int ornegi — deger uretir, baska yerde kullanilabilir:
int kareAl(int sayi)
{
    return sayi * sayi;
}

// void ornegi — is yapar, deger dondurmez:
void selamVer(int isim_uzunlugu)
{
    cout << "Merhaba! Isminiz " << isim_uzunlugu << " harfli." << endl;
    // return yok — ya da sadece "return;" (bos return) yazilir.
}

void voidVsIntOrnegi()
{
    cout << "\n--- [7] void vs int ---" << endl;

    // int fonksiyon — dondurulan degeri kullanabilirsin:
    int sonuc  = kareAl(5);         // sonuc = 25
    int ikiKat = kareAl(5) * 2;    // 50 — direkt kullanildi
    cout << "5'in karesi : " << sonuc  << endl;
    cout << "Iki kati    : " << ikiKat << endl;

    // void fonksiyon — sadece cagirirsin, deger alamazsin:
    selamVer(5);
    // int x = selamVer(5);  // HATA — void deger dondurmez, bunu yapamazsin

    // Karar tablosu:
    //
    //  Durum                                | Ne kullan?
    //  -------------------------------------|-------------------
    //  Hesabi baska yerde kullanacaksan     | int (veya uygun tip)
    //  Sadece ekrana yazdiracaksan          | void
    //  Birden fazla yerde kullanacaksan     | kesinlikle int
    //  Dosyaya yazma, log tutma vs.         | void
}


// ============================================================
//  [8] GELECEGE NOT — Referans Parametreler (int&)
//
//  Yukarida kullanicidanAl(int& x, int& y) gormus olmalisin.
//  "&" isareti "referans" anlamina gelir.
//
//  Normal parametre    => fonksiyon degerin KOPYASINI alir
//  Referans parametre  => fonksiyon orijinal degiskeni KENDISINI alir
//
//  C#'daki "ref" keyword ile BIREBIR ayni mantik:
//    C#  : void Doldur(ref int x)  { x = 10; }
//    C++ : void doldur(int& x)     { x = 10; }
//
//  Simdilik sadece var oldugunu bil.
//  Bir sonraki konuda tamamen parcalayacagiz.
// ============================================================

void referansOnizleme()
{
    cout << "\n--- [8] Referans Parametreler (Onizleme) ---" << endl;
    cout << "Bu konu bir sonraki derste detayli isleniyor." << endl;
    cout << "Simdilik: '&' isareti orijinal degiskeni verir." << endl;
    cout << "C#'daki 'ref' ile ayni mantik." << endl;
}


// ============================================================
//  MAIN — Orkestrator
//
//  Fark et: main() hicbir hesap YAPMIYOR.
//  Sadece fonksiyonlari dogru sirada cagiriyor.
// ============================================================

int main()
{
    cout << "============================================" << endl;
    cout << "  C++ Fonksiyon Tasarimi — Tam Demo        " << endl;
    cout << "============================================" << endl;


    // --- [2] Dogru Yaklasim Demo ---
    cout << "\n--- [2] Dogru Yaklasim ---" << endl;

    int kisa, uzun;

    kullanicidanAl(kisa, uzun);            // 1. veriyi topla
    int alan = alanHesaplama(kisa, uzun);  // 2. hesapla
    sonucuGoster(alan);                    // 3. goster

    // Her fonksiyon sadece kendi isini yapti.
    // main() sadece sirayi yonetti.


    // --- [3] Kara Kutu Demo ---
    cout << "\n--- [3] Kara Kutu ---" << endl;

    double ucgen = ucgenAlani(6.0, 4.0);
    double daire = daireAlani(3.0);
    double c     = hipotenus(3.0, 4.0);

    cout << "Ucgen alani (taban=6, yukseklik=4) : " << ucgen << endl;
    cout << "Daire alani (yaricap=3)             : " << daire << endl;
    cout << "Hipotenüs   (a=3, b=4)              : " << c     << endl;


    // --- Diger bolumler ---
    yenidenKullanimOrnegi();
    fonksiyonZinciriOrnegi();
    voidVsIntOrnegi();
    referansOnizleme();


    cout << "\n============================================" << endl;
    cout << "  ZIHIN MODELI OZETI                        " << endl;
    cout << "============================================" << endl;
    cout << "  kullanicidanAl() => veri toplar           " << endl;
    cout << "  alanHesaplama()  => hesap yapar            " << endl;
    cout << "  sonucuGoster()   => ekrana yazar           " << endl;
    cout << "  main()           => hepsini yonetir        " << endl;
    cout << "============================================" << endl;

    return 0;
    // 0 dondurmak isletim sistemine "her sey yolunda" demektir.
}
