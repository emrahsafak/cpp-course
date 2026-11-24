// ============================================================
//  C++ NOTLARI: Fonksiyon Tasarimi, Kopya vs Referans
//  Derle: g++ -std=c++17 -Wall -Wextra fonksiyon_tasarimi.cpp -o program
//
//  DUZEN: Her bolumde TANIM + CAGRI + ACIKLAMA yan yana.
//  Yukari-asagi gezmene gerek yok. main() en altta, sadece sirayi yonetir.
//
//  [0] Anatomi            [5] Fonksiyon zinciri
//  [1] Yanlis yaklasim    [6] main = orkestrator (en altta)
//  [2] Dogru yaklasim     [7] void vs int
//  [3] Kara kutu          [8] Kopya vs referans
//  [4] Yeniden kullanim   [9] Isim vs kutu (kafa karistiran nokta)
//
//  5 CUMLE OZET:
//   1) Fonksiyon girdi alir, return ile cikti verir.
//   2) & yok -> KOPYA, orijinal degismez.
//   3) & var -> ORIJINALIN KENDISI (ikinci isim), degisebilir.
//   4) Fonksiyonlar birbirini gormez; veriyi main() tasir.
//   5) Tur kelimesi (int/void) sadece TANIMLARKEN ve YENI DEGISKEN
//      acarken yazilir. CAGIRIRKEN yazilmaz.
// ============================================================

#include <iostream>
#include <cmath>

// "using namespace std;" yerine sadece ihtiyacimiz olanlar (isim cakismasi riski yok)
using std::cout; using std::cin; using std::endl;

constexpr double PI = 3.14159265358979323846;   // M_PI standart degil


// ------------------------------------------------------------
// [0] ANATOMI: fonksiyon = makine (girdi -> cikti)
//   int        : donus tipi (makineden int cikar)
//   ikiyleCarp : isim
//   (int sayi) : girdi (icerde adi "sayi")
//   return     : sonucu ver VE fonksiyonu bitir
// ------------------------------------------------------------
int ikiyleCarp(int sayi) { return sayi * 2; }

void demo0()
{
    int a = ikiyleCarp(5);          // CAGRI: tur yok. Bastaki int, 'a' degiskenine ait.
    cout << "[0] ikiyleCarp(5) = " << a << endl;
}


// ------------------------------------------------------------
// [1] YANLIS YAKLASIM (Anti-Pattern) - main'de BILEREK cagrilmiyor
//   Uc is tek fonksiyonda: giris + hesap + cikti.
//   Sorun: her cagrida kullanici girisi bekler, parametre alamaz
//   (YANLIS_alanHesaplama(5,10) yazamazsin), otomatik test edilemez.
// ------------------------------------------------------------
int YANLIS_alanHesaplama()
{
    int x, y;
    cout << "Kisa kenar: "; cin >> x;       // is 1: giris
    cout << "Uzun kenar: "; cin >> y;
    int alan = x * y;                       // is 2: hesap
    cout << "Alan: " << alan << endl;       // is 3: cikti
    return alan;
}


// ------------------------------------------------------------
// [2] DOGRU YAKLASIM: her fonksiyon TEK is yapar (SRP)
// ------------------------------------------------------------

// VERI TOPLAYICI: & VAR, cunku girilen degerleri main'deki
// kutulara GERI YAZMASI lazim. void, cunku sonuc x/y ile teslim edilir.
void kullanicidanAl(int& x, int& y)
{
    cout << "Kisa kenar giriniz: "; cin >> x;
    cout << "Uzun kenar giriniz: "; cin >> y;
}

// MATEMATIKCI: & YOK (kopya alir), cin/cout yok. "Saf fonksiyon":
// ayni girdi -> ayni cikti, dunyada baska hicbir sey degismez.
int alanHesaplama(int x, int y) { return x * y; }

// SUNUCU: sadece ekrana yazar.
void sonucuGoster(int alan) { cout << "Dikdortgenin alani: " << alan << endl; }

void demo2()
{
    cout << "\n[2] Dogru yaklasim (interaktif)" << endl;

    int kisa{}, uzun{};                      // 1) kutulari ac. {} => 0 (cop deger yok)
    kullanicidanAl(kisa, uzun);              // 2) & sayesinde kisa/uzun dolar
    int alan = alanHesaplama(kisa, uzun);    // 3) degerler KOPYALANIP gider, 50 doner
    sonucuGoster(alan);                      // 4) alan kopyalanip gider

    // Bellek akisi (5 ve 10 girildi):
    //   (1) [kisa:0 ] [uzun:0 ]
    //   (2) [kisa:5 ] [uzun:10]               <- referansla dolduruldu
    //   (3) [kisa:5 ] [uzun:10] [alan:50]     <- kopya gitti, 50 dondu
    //
    // Kazanc: girisi dosyadan almak -> sadece kullanicidanAl degisir.
    //         hesabi test etmek     -> alanHesaplama(5,10) == 50, tek satir.
    // (Modern alternatif: C++ Core Guidelines F.20 -> std::pair + structured binding.
    //  Referans mantigi oturunca isleriz.)
}


// ------------------------------------------------------------
// [3] KARA KUTU: [girdi] -> | fonksiyon | -> [cikti]
//   Icini bilmen gerekmez, iki soru yeter: "ne verirsem, ne alirim?"
//   (Unity'de Mathf.Sqrt'in icini dusunmemen gibi.)
//   double: bolme/karekok ondalikli sonuc uretir.
//   2.0 (2 degil): int/int kesiri atar -> 5/2 = 2, ama 5/2.0 = 2.5
// ------------------------------------------------------------
double ucgenAlani(double taban, double yukseklik) { return (taban * yukseklik) / 2.0; }
double daireAlani(double yaricap)                 { return PI * yaricap * yaricap; }
double hipotenus(double a, double b)              { return std::sqrt(a * a + b * b); }

void demo3()
{
    cout << "\n[3] Kara kutu" << endl;
    cout << "Ucgen (6,4)  : " << ucgenAlani(6.0, 4.0) << endl;   // 12
    cout << "Daire (r=3)  : " << daireAlani(3.0)       << endl;   // 28.2743
    cout << "Hipotenus    : " << hipotenus(3.0, 4.0)   << endl;   // 5
}


// ------------------------------------------------------------
// [4] YENIDEN KULLANIM: ayni fonksiyon, farkli girdi
//   [1]'deki yanlis fonksiyonla bu mumkun degildi.
// ------------------------------------------------------------
void demo4()
{
    cout << "\n[4] Yeniden kullanim" << endl;
    int en = 8, boy = 12;
    cout << "5x10   = " << alanHesaplama(5, 10)     << endl;   // 50
    cout << "3x7    = " << alanHesaplama(3, 7)      << endl;   // 21
    cout << "100x200= " << alanHesaplama(100, 200)  << endl;   // 20000
    cout << "8x12   = " << alanHesaplama(en, boy)   << endl;   // degiskenle de olur
}


// ------------------------------------------------------------
// [5] FONKSIYON ZINCIRI: bir fonksiyonun CIKTISI baskasinin GIRDISI olur
// ------------------------------------------------------------
void demo5()
{
    cout << "\n[5] Zincir" << endl;

    int alan = alanHesaplama(6, 9);        // Yontem A: ara degisken (okunakli, tercih)
    sonucuGoster(alan);

    sonucuGoster(alanHesaplama(6, 9));     // Yontem B: ic ice. Once ic calisir (54), sonra dis.

    double c = hipotenus(3.0, 4.0);        // 5.0
    cout << "Hipotenus: " << c << " | Karesi: " << c * c << endl;
}


// ------------------------------------------------------------
// [7] void vs int
//   int (veya baska tip): deger URETIR, baska yerde kullanabilirsin.
//   void                : is YAPAR, deger dondurmez.
//   Hesabi baska yerde kullanacaksan -> tip. Sadece yazdiracak/loglayacaksan -> void.
// ------------------------------------------------------------
int  kareAl(int sayi)             { return sayi * sayi; }
void selamVer(int isimUzunlugu)   { cout << "Merhaba! Isminiz " << isimUzunlugu << " harfli." << endl; }

void demo7()
{
    cout << "\n[7] void vs int" << endl;
    int ikiKat = kareAl(5) * 2;            // 50: dondurulen deger hesapta kullanildi
    cout << "5'in karesinin iki kati: " << ikiKat << endl;
    selamVer(5);                           // void: sadece cagrilir
    // int x = selamVer(5);                // HATA: void deger dondurmez
}


// ------------------------------------------------------------
// [8] KOPYA vs REFERANS (konunun cekirdegi)
//   & yok : fotokopi alir. Icerde ne yaparsan yap orijinal ayni kalir.
//   & var : orijinalin KENDISINI alir. Icerdeki degisiklik disarida gorulur.
//   C# karsiligi: ref int x  <->  C++: int& x
// ------------------------------------------------------------
void dortYap_Referans(int& sayi)                    { sayi = 4; }
void besYap_Kopya([[maybe_unused]] int sayi)        { sayi = 5; }   // bilerek kullanilmiyor
void artir(int& a)                                  { a = a + 1; }
void artirKopya([[maybe_unused]] int a)             { a = a + 1; }

void demo8()
{
    cout << "\n[8] Kopya vs Referans" << endl;

    int elma = 5;
    besYap_Kopya(elma);       cout << "besYap_Kopya sonrasi : " << elma << "  (degismedi)" << endl;   // 5
    dortYap_Referans(elma);   cout << "dortYap_Referans     : " << elma << "  (degisti)"   << endl;   // 4

    int sayi = 10;
    artir(sayi);              // 11
    artirKopya(sayi);         // kopya artar ama fonksiyon bitince yok olur -> sayi 11 kalir
    cout << "artir + artirKopya   : " << sayi << "  (sadece artir etkili)" << endl;
}


// ------------------------------------------------------------
// [9] KAFA KARISTIRAN NOKTA: ISIM vs KUTU
//   Soru: "x'ler kendi fonksiyonunun icinde omurlu degil mi?
//          alanHesaplama, kullanicidanAl'in x'ini nasil cekiyor?"
//   Cevap: CEKMIYOR. Iki ayri karisiklik var:
//
//   KARISIKLIK 1: "Ayni isim = ayni degisken" sanmak.
//     kullanicidanAl(int& x, ...) ile alanHesaplama(int x, ...) icindeki
//     x'ler SADECE AYNI HARF. Birine zeta desen program ayni calisir.
//     Veriyi tasiyan tek sey main()'dir.
//
//   KARISIKLIK 2: "Fonksiyon icinde yasar" kuralini KUTUya uygulamak.
//     Degisken iki sey: KUTU (bellekteki yer) + ISIM (etiket).
//     Kural ISIMLER icin gecerli. Bir kutunun birden fazla ismi olabilir:
//        int& x  => "Yeni kutu ACMA, verilen kutuya x ismini ver."
//        int  x  => "Yeni kutu AC, degerin fotokopisini koy."
//
//        kullanicidanAl(kisa, uzun)     alanHesaplama(kisa, uzun)
//        [ 5 ]  <- kisa VE x            main:  [kisa:5][uzun:10]
//        (tek kutu, iki isim)                     | kopya   | kopya
//                                       fonk:  [x:5]   [y:10]   (yeni kutular)
//
//   Omur kurali bozulmadi: fonksiyon bitince x/y ISIMLERI olur, ama
//   gosterdikleri kutular main'e ait ve yasar. & olmasaydi x yeni kutu
//   olurdu ve girilen deger kaybolurdu.
//   Hangi kutu hangi isme baglanir? ISIM degil, CAGRIDAKI SIRA:
//   1. arguman -> 1. parametre, 2. arguman -> 2. parametre.
//
//   KANIT: &degisken bellek adresini verir. Ayni adres = ayni kutu.
// ------------------------------------------------------------
void adresReferans(int& r) { cout << "  referans icindeki r : " << &r << endl; }
void adresKopya(int k)     { cout << "  kopya icindeki k    : " << &k << endl; }

void demo9()
{
    cout << "\n[9] Isim vs Kutu (adres kaniti)" << endl;
    int sayi = 10;
    cout << "  main'deki sayi      : " << &sayi << endl;
    adresReferans(sayi);   // AYNI adres  -> ayni kutu
    adresKopya(sayi);      // FARKLI adres -> yeni kutu
}


// ------------------------------------------------------------
// [6] main() = ORKESTRATOR: hesap yapmaz, sadece sirayi yonetir.
//   Ayni kalip her yerde: Girdi -> Islem -> Cikti
//   Oyun dongusu: ProcessInput -> Update -> Render
//   FPV drone   : gyro oku -> PID hesapla -> motorlara yaz
// ------------------------------------------------------------
int main()
{
    demo0();
    demo2();    // interaktif: iki sayi girmen gerekiyor
    demo3();
    demo4();
    demo5();
    demo7();
    demo8();
    demo9();

    return 0;   // 0 = isletim sistemine "her sey yolunda" (her zaman en sonda!)
}


// ------------------------------------------------------------
// ALISTIRMALAR (cevaplar parantezde)
//   A) void besYap(int s){ s = 5; }  int elma = 9; besYap(elma);  -> elma? (9)
//   B) kullanicidanAl'daki & isaretlerini sil -> kisa/uzun neden 0 kalir? (x,y fotokopi oldu)
//   C) alanHesaplama'yi kullanicidanAl'dan ONCE cagir -> alan? (0, once veri toplanmali)
//   D) alanHesaplama icine x = 999; yaz -> main'deki kisa degisir mi? (hayir, kopya)
//
// SIRADAKI: const referans (const int&), pointer, std::pair/structured
//           binding, fonksiyon overloading
// ------------------------------------------------------------
