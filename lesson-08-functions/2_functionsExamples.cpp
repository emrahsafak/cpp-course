// ============================================================
//
//   C++ DERS NOTLARI  -  TEK DOSYA (kod + aciklama)
//   Konu : Fonksiyon Tasarimi, Kopya vs Referans, Sorumluluk Ayrimi
//
//   DOSYA DUZENI:
//     1) USTTE  : calisan tam kod (kopyala, derle, calistir)
//     2) ALTTA  : ayni kodun blok blok aciklamasi (yorum olarak)
//
//   DERLEME:
//     g++ -std=c++17 -Wall -Wextra fonksiyon_tasarimi.cpp -o program
//     ./program          (Windows: program.exe)
//
//   ICINDEKILER (kod ve aciklamada ayni numaralar):
//     [0] Fonksiyon anatomisi   - makine modeli
//     [1] Yanlis yaklasim       - Anti-Pattern
//     [2] Dogru yaklasim        - Separation of Concerns
//     [3] Kara kutu modeli
//     [4] Yeniden kullanim
//     [5] Fonksiyon zinciri
//     [6] main() = orkestrator
//     [7] void vs int
//     [8] Referans parametreler - kopya vs referans
//     [9] Kafa karistiran nokta - isim vs kutu (adres kaniti)
//
// ============================================================

#include <iostream>   // std::cout, std::cin, std::endl
#include <cmath>      // std::sqrt

// M_PI C++ standardinda yok (MSVC'de hata verir), kendi sabitimiz:
constexpr double PI = 3.14159265358979323846;


// ============================================================
//  [0] FONKSIYON ANATOMISI
// ============================================================

int ikiyleCarp(int sayi)
{
    return sayi * 2;
}


// ============================================================
//  [1] YANLIS YAKLASIM - Anti-Pattern
//  Uc is tek fonksiyonda: giris + hesap + cikti.
//  (main'de BILEREK cagirmiyoruz, "boyle yazma" ornegi)
// ============================================================

int YANLIS_alanHesaplama()
{
    int x, y;

    std::cout << "Kisa kenar: ";
    std::cin  >> x;                              // is 1: kullanici girisi

    std::cout << "Uzun kenar: ";
    std::cin  >> y;

    int alan = x * y;                            // is 2: hesaplama

    std::cout << "Alan: " << alan << std::endl;  // is 3: cikti

    return alan;
}


// ============================================================
//  [2] DOGRU YAKLASIM - Her fonksiyon TEK is yapar
// ============================================================

// INPUT: sadece veri toplar. & var, cunku girilen degerleri
// main'deki degiskenlere GERI YAZMASI gerekiyor.
void kullanicidanAl(int& x, int& y)
{
    std::cout << "Kisa kenar giriniz: ";
    std::cin  >> x;

    std::cout << "Uzun kenar giriniz: ";
    std::cin  >> y;
}

// HESAP: sadece matematik. & yok (kopya alir), cin/cout yok.
int alanHesaplama(int x, int y)
{
    return x * y;
}

// OUTPUT: sadece ekrana yazar.
void sonucuGoster(int alan)
{
    std::cout << "Dikdortgenin alani: " << alan << std::endl;
}


// ============================================================
//  [3] KARA KUTU MODELI
// ============================================================

// Ucgen alani: (taban * yukseklik) / 2
double ucgenAlani(double taban, double yukseklik)
{
    return (taban * yukseklik) / 2.0;
}

// Daire alani: PI * r^2
double daireAlani(double yaricap)
{
    return PI * yaricap * yaricap;
}

// Hipotenus: c = sqrt(a^2 + b^2)
double hipotenus(double a, double b)
{
    return std::sqrt(a * a + b * b);
}

void karaKutuOrnegi()
{
    std::cout << "\n--- [3] Kara Kutu ---" << std::endl;

    double ucgen = ucgenAlani(6.0, 4.0);
    double daire = daireAlani(3.0);
    double c     = hipotenus(3.0, 4.0);

    std::cout << "Ucgen alani (taban=6, yukseklik=4) : " << ucgen << std::endl;
    std::cout << "Daire alani (yaricap=3)            : " << daire << std::endl;
    std::cout << "Hipotenus   (a=3, b=4)             : " << c     << std::endl;
}


// ============================================================
//  [4] YENIDEN KULLANIM
// ============================================================

void yenidenKullanimOrnegi()
{
    std::cout << "\n--- [4] Yeniden Kullanim ---" << std::endl;

    int alan1 = alanHesaplama(5, 10);      // 50
    int alan2 = alanHesaplama(3, 7);       // 21
    int alan3 = alanHesaplama(100, 200);   // 20000

    std::cout << "5   x 10  = " << alan1 << std::endl;
    std::cout << "3   x 7   = " << alan2 << std::endl;
    std::cout << "100 x 200 = " << alan3 << std::endl;

    int en    = 8;
    int boy   = 12;
    int alan4 = alanHesaplama(en, boy);    // 96
    std::cout << "8   x 12  = " << alan4 << std::endl;
}


// ============================================================
//  [5] FONKSIYON ZINCIRI
// ============================================================

void fonksiyonZinciriOrnegi()
{
    std::cout << "\n--- [5] Fonksiyon Zinciri ---" << std::endl;

    // Yontem A: ara degisken ile (okunakli, tercih edilen)
    int alan = alanHesaplama(6, 9);
    sonucuGoster(alan);

    // Yontem B: ic ice zincir (kisa ama daha az okunakli)
    sonucuGoster(alanHesaplama(6, 9));

    // Bir fonksiyonun ciktisini baska hesapta kullanmak
    double c  = hipotenus(3.0, 4.0);   // 5.0
    double us = c * c;                 // 25.0
    std::cout << "Hipotenus: " << c << " | Karesi: " << us << std::endl;
}


// ============================================================
//  [7] void vs int
// ============================================================

int kareAl(int sayi)                   // deger URETIR
{
    return sayi * sayi;
}

void selamVer(int isimUzunlugu)        // is YAPAR, deger dondurmez
{
    std::cout << "Merhaba! Isminiz " << isimUzunlugu << " harfli." << std::endl;
}

void voidVsIntOrnegi()
{
    std::cout << "\n--- [7] void vs int ---" << std::endl;

    int sonuc  = kareAl(5);            // 25
    int ikiKat = kareAl(5) * 2;        // 50
    std::cout << "5'in karesi : " << sonuc  << std::endl;
    std::cout << "Iki kati    : " << ikiKat << std::endl;

    selamVer(5);
    // int x = selamVer(5);            // HATA: void deger dondurmez
}


// ============================================================
//  [8] REFERANS PARAMETRELER - KOPYA vs REFERANS
// ============================================================

void dortYap_Referans(int& sayi)       // & VAR  -> orijinalin kendisi
{
    sayi = 4;
}

void besYap_Kopya([[maybe_unused]] int sayi)   // & YOK -> fotokopi (uyari susturuldu: bilerek kullanilmiyor)
{
    sayi = 5;
}

void artir(int& a)       { a = a + 1; }   // orijinali artirir
void artirKopya(int a)   { a = a + 1; }   // kopyayi artirir, kopya ölür

void referansOrnegi()
{
    std::cout << "\n--- [8] Kopya vs Referans ---" << std::endl;

    int elma = 5;
    std::cout << "Basta elma            : " << elma << std::endl;

    besYap_Kopya(elma);
    std::cout << "besYap_Kopya sonrasi  : " << elma << "   (DEGISMEDI)" << std::endl;

    dortYap_Referans(elma);
    std::cout << "dortYap_Referans sonra: " << elma << "   (DEGISTI)" << std::endl;

    int sayi = 10;
    artir(sayi);                       // 11
    artirKopya(sayi);                  // hala 11
    std::cout << "artir + artirKopya    : " << sayi << "   (sadece artir etkili)" << std::endl;
}


// ============================================================
//  [9] KAFA KARISTIRAN NOKTA - ISIM vs KUTU (adres kaniti)
//  &degisken => o degiskenin bellek ADRESI (kutunun ev numarasi).
//  Adresler ayni ise KUTU aynidir. (Pointer konusunda detaylanacak.)
// ============================================================

void adresReferans(int& r)
{
    std::cout << "  adresReferans icindeki r : " << &r << std::endl;
}

void adresKopya(int k)
{
    std::cout << "  adresKopya icindeki k    : " << &k << std::endl;
}

void isimKutuOrnegi()
{
    std::cout << "\n--- [9] Isim vs Kutu (adres kaniti) ---" << std::endl;

    int sayi = 10;
    std::cout << "main'deki sayi             : " << &sayi << std::endl;

    adresReferans(sayi);   // AYNI adres  -> ayni kutu, ikinci isim
    adresKopya(sayi);      // FARKLI adres -> yeni kutu, fotokopi

    std::cout << "(Adresler her calistirmada degisebilir; onemli olan"
              << " hangilerinin birbirine ESIT oldugu.)" << std::endl;
}


// ============================================================
//  [6] main() = ORKESTRATOR
//  Hesap yapmaz, sadece fonksiyonlari dogru sirayla cagirir.
// ============================================================

int main()
{
    std::cout << "============================================" << std::endl;
    std::cout << "  C++ Fonksiyon Tasarimi - Tam Demo" << std::endl;
    std::cout << "============================================" << std::endl;

    // --- [0] Fonksiyon anatomisi ---
    std::cout << "\n--- [0] Fonksiyon = Makine ---" << std::endl;
    int a = ikiyleCarp(5);
    std::cout << "ikiyleCarp(5) = " << a << std::endl;

    // --- [2] Dogru yaklasim (interaktif) ---
    std::cout << "\n--- [2] Dogru Yaklasim ---" << std::endl;

    int kisa{}, uzun{};                      // {} => 0 ile baslat (cop deger yok)

    kullanicidanAl(kisa, uzun);              // 1. veriyi topla (referans: kutular dolar)
    int alan = alanHesaplama(kisa, uzun);    // 2. hesapla      (kopya gider, sonuc doner)
    sonucuGoster(alan);                      // 3. goster       (kopya gider)

    // --- digerleri ---
    karaKutuOrnegi();            // [3]
    yenidenKullanimOrnegi();     // [4]
    fonksiyonZinciriOrnegi();    // [5]
    voidVsIntOrnegi();           // [7]
    referansOrnegi();            // [8]
    isimKutuOrnegi();            // [9]

    std::cout << "\n============================================" << std::endl;
    std::cout << "  ZIHIN MODELI OZETI" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "  kullanicidanAl() => veri toplar" << std::endl;
    std::cout << "  alanHesaplama()  => hesap yapar" << std::endl;
    std::cout << "  sonucuGoster()   => ekrana yazar" << std::endl;
    std::cout << "  main()           => hepsini yonetir" << std::endl;
    std::cout << "============================================" << std::endl;

    return 0;   // 0 = isletim sistemine "her sey yolunda"
}


/* ============================================================
   ============================================================
   ACIKLAMALAR  (yukaridaki kodun blok blok anlatimi)
   ============================================================
   ============================================================


   ------------------------------------------------------------
   0) DOSYANIN BASI
   ------------------------------------------------------------
   #include <iostream>
       cout (ekrana yaz), cin (klavyeden oku), endl (satir sonu)
       buradan gelir.
   #include <cmath>
       Matematik fonksiyonlari (sqrt = karekok) buradan gelir.
   constexpr double PI = ...
       Derleme zamaninda sabit olan sayi. Eski notlarda M_PI vardi
       ama o C++ standardinda DEGIL; bazi derleyicilerde (MSVC) hata
       verir. Kendi sabitini tanimlamak her yerde calisir.
   std::cout, std::cin
       Eski notlarda "using namespace std;" vardi. Buyuk projelerde
       isim cakismasina yol actigi icin profesyonel kodda std::
       onekiyle yazilir. (Unity'de iki farkli kutuphanede ayni isimli
       sinif olmasi sorunu gibi dusun.)


   ------------------------------------------------------------
   [0] FONKSIYON ANATOMISI  -  "makine" modeli
   ------------------------------------------------------------
       int ikiyleCarp(int sayi)
       {
           return sayi * 2;
       }

     int          -> makineden int CIKACAK (donus tipi)
     ikiyleCarp   -> makinenin adi
     (int sayi)   -> makineye int KONACAK, makinenin icinde adi "sayi"
     return       -> sonucu disari ver VE fonksiyonu bitir

     Cagirma:  int a = ikiyleCarp(5);
       "makineye 5 koy" demek. Makine 10 uretir, a o degeri alir.
       MATLAB'daki  function out = f(a)  ile ayni mantik.


   ------------------------------------------------------------
   [1] YANLIS YAKLASIM  -  Anti-Pattern
   ------------------------------------------------------------
     YANLIS_alanHesaplama() icinde UC is var:
        1) kullanicidan veri alma (cin)
        2) hesaplama (x * y)
        3) ekrana yazma (cout)
     Buna "karmasik sorumluluk" hatasi denir.

     Neden kotu?
        int a1 = YANLIS_alanHesaplama();        // kullanici girisi bekler
        int a2 = YANLIS_alanHesaplama();        // TEKRAR giris bekler
        int a3 = YANLIS_alanHesaplama(5, 10);   // HATA: parametre almiyor
     - Her cagirista kullanici ile konusmak zorunda ("esir" fonksiyon).
     - Otomatik test edilemez (cin insan bekler).
     - Girisi dosyadan almak istesen butun fonksiyonu yeniden yazarsin.

     Kodda bilerek main'den cagrilmiyor; sadece "boyle yazma" ornegi.


   ------------------------------------------------------------
   [2] DOGRU YAKLASIM  -  Separation of Concerns / SRP
   ------------------------------------------------------------
     Kural: Her fonksiyon SADECE TEK is yapar.

     a) void kullanicidanAl(int& x, int& y)     -> VERI TOPLAYICI
          - Sadece cin kullanir. Hesap yok, ekrana sonuc yazma yok.
          - int& (referans) kullandik: girilen degerleri main'deki
            degiskenlere GERI YAZMASI gerekiyor. Fotokopiye yazsa
            degerler fonksiyon bitince kaybolurdu.
          - void: sonuc zaten x ve y uzerinden teslim ediliyor.

     b) int alanHesaplama(int x, int y)         -> MATEMATIKCI
          - Sadece x * y. cin yok, cout yok.
          - & yok: fotokopi alir, disariyi bozamaz.
          - Buna SAF FONKSIYON (pure function) denir: ayni girdiye
            hep ayni cikti, dunyada baska hicbir sey degismez.

     c) void sonucuGoster(int alan)             -> SUNUCU
          - Sadece cout. Hesap yok, giris yok.

     SRP kazanclari:
       Alani 2 kez hesapla      -> alanHesaplama(5,10), alanHesaplama(3,7)
       Girisi dosyadan al       -> sadece kullanicidanAl degisir
       Ciktiyi dosyaya yaz      -> sadece sonucuGoster degisir
       Hesabi test et           -> alanHesaplama(5,10) == 50 tek satir
     Unity benzetmesi: PlayerInput, PlayerMovement, PlayerUI ayri
     script'lerdir. Girisi klavyeden gamepade cevirirken hareket
     koduna dokunmazsin.

     Not (profesyonel): C++ Core Guidelines F.20 "cikti icin referans
     parametre yerine return kullan" der. Modern alternatif:
        std::pair<int,int> kullanicidanAl();
        auto [kisa, uzun] = kullanicidanAl();     // C++17
     Simdilik referans mantigini oturtuyoruz; bunu sonra isleriz.


   ------------------------------------------------------------
   [3] KARA KUTU MODELI
   ------------------------------------------------------------
        [girdi] --> | fonksiyon | --> [cikti]

     Iceriyi bilmek zorunda degilsin, iki soru yeter:
        "Ne verirsem?"  ve  "Ne alirim?"
     Unity'de Mathf.Sqrt(x) cagirirken icini dusunmemen gibi.

     ucgenAlani, daireAlani, hipotenus:
       - double kullandik cunku bolme ve karekok ondalikli sonuc
         uretir; int olsa kesir kaybolurdu.
       - 2.0 yazdik (2 degil): int / int islemi kesiri atar, 2.0
         ondalikli bolme yaptirir. Ornek: 5/2 = 2 ama 5/2.0 = 2.5
       - sqrt() <cmath>'tan gelir, PI bizim sabitimiz.


   ------------------------------------------------------------
   [4] YENIDEN KULLANIM
   ------------------------------------------------------------
     Dogru tasarlanmis fonksiyon, ayni kalip farkli degerlerle
     cagrilir:
        alanHesaplama(5, 10)      // 50
        alanHesaplama(3, 7)       // 21
        alanHesaplama(en, boy)    // degiskenle de olur
     Fonksiyon degismez, sadece girdi degisir. [1]'deki yanlis
     fonksiyonla bu mumkun degildi.


   ------------------------------------------------------------
   [5] FONKSIYON ZINCIRI
   ------------------------------------------------------------
     Bir fonksiyonun CIKTISI baska fonksiyonun GIRDISI olabilir.

        // Yontem A (tercih edilen, okunakli)
        int alan = alanHesaplama(6, 9);
        sonucuGoster(alan);

        // Yontem B (ic ice)
        sonucuGoster(alanHesaplama(6, 9));

     B'de once ic taraftaki alanHesaplama(6,9) calisir ve 54 doner,
     sonra sonucuGoster(54) cagrilir. Zincir uzadikca A okunabilirligi
     korur.


   ------------------------------------------------------------
   [6] main() = ORKESTRATOR
   ------------------------------------------------------------
     main hesap YAPMAZ, trafik polisi / proje yoneticisi gibi sadece
     sirayi yonetir:

        int kisa{}, uzun{};                    // satir 1
        kullanicidanAl(kisa, uzun);            // satir 2: topla
        int alan = alanHesaplama(kisa, uzun);  // satir 3: hesapla
        sonucuGoster(alan);                    // satir 4: goster

     Satir satir:
       1) int kisa{}, uzun{};
          main'in stack'inde iki int kutusu acilir. {} ile 0'a
          baslatilir. Baslatilmamis yerel int icinde COP deger tasir
          ve onu okumak Undefined Behavior'dir. Unity'deki gibi
          otomatik 0 korumasi C++'ta yerel degiskenlerde YOK.
       2) kullanicidanAl(kisa, uzun);
          Parametreler int& oldugu icin fonksiyon bu iki kutunun
          KENDISINI alir. cin >> x aslinda kisa'ya yazar.
          Donus degeri yok (void), cunku is kutulari doldurarak bitti.
       3) int alan = alanHesaplama(kisa, uzun);
          Sagdan sola oku: kisa ve uzun'un DEGERLERI kopyalanip
          fonksiyona gider, x*y hesaplanir, sonuc return ile doner
          ve main'deki yeni "alan" kutusuna yazilir.
       4) sonucuGoster(alan);
          alan'in degeri kopyalanir, fonksiyon sadece ekrana yazar.

     Bellek akisi (kullanici 5 ve 10 girdi):
       (1) main: [kisa: 0 ] [uzun: 0 ]
       (2) main: [kisa: 5 ] [uzun: 10]            <- referansla dolduruldu
       (3) main: [kisa: 5 ] [uzun: 10] [alan: 50] <- kopya gitti, 50 dondu
       (4) Ekran: Dikdortgenin alani: 50

     Girdi -> Islem -> Cikti kalibi profesyonel yazilimin iskeletidir:
       Oyun dongusu : ProcessInput -> Update -> Render
       FPV drone    : gyro oku -> PID hesapla -> motorlara yaz

     main() 'return 0' ile biter: isletim sistemine "her sey yolunda".


   ------------------------------------------------------------
   [7] void vs int
   ------------------------------------------------------------
     int (veya baska tip) -> fonksiyon bir deger URETIR ve geri verir,
                             baska yerde kullanabilirsin.
     void                 -> fonksiyon bir is YAPAR, deger dondurmez.

        int sonuc  = kareAl(5);       // 25, kullanilabilir
        int ikiKat = kareAl(5) * 2;   // 50, direkt hesapta kullanildi
        selamVer(5);                  // sadece cagrilir
        // int x = selamVer(5);       // HATA: void'den deger alinamaz

     Karar tablosu:
       Hesabi baska yerde kullanacaksan      -> int (uygun tip)
       Sadece ekrana yazdiracaksan           -> void
       Birden fazla yerde kullanacaksan      -> kesinlikle int
       Dosyaya yazma, log tutma vs.          -> void


   ------------------------------------------------------------
   [8] REFERANS PARAMETRELER  -  KOPYA vs REFERANS
   ------------------------------------------------------------
     Konunun cekirdegi:

       void besYap_Kopya(int sayi)        // & YOK -> FOTOKOPI
       void dortYap_Referans(int& sayi)   // & VAR -> ORIJINALIN KENDISI

     & yok : fonksiyon degerin kopyasini alir. Icerde ne yaparsan yap
             orijinal ayni kalir; fonksiyon bitince kopya yok olur.
     & var : fonksiyon orijinalin kendisini alir. Icerde yaptigin
             degisiklik disarida da gorulur.

     Demo cikti:
       Basta elma            : 5
       besYap_Kopya sonrasi  : 5   (DEGISMEDI)
       dortYap_Referans sonra: 4   (DEGISTI)
       artir + artirKopya    : 11  (sadece artir etkili)

     artir(sayi)      -> sayi 10'dan 11 olur (referans)
     artirKopya(sayi) -> kopya 12 olur ama fonksiyon bitince yok olur, sayi 11 kalir

     C# karsiligi:
        C#  : void DortYap(ref int x)   { x = 4; }
        C++ : void dortYap(int& x)      { x = 4; }
     (Nuans: kullanicidanAl sadece YAZDIGI icin C#'ta out'a daha
      yakin; C++'ta int& ikisini de karsilar.)


   ------------------------------------------------------------
   [9] KAFA KARISTIRAN NOKTA  -  ISIM vs KUTU
   ------------------------------------------------------------
   Soru: "x ve y degiskenleri kendi fonksiyonlarinin parantezi icinde
   omurlu degil mi? kullanicidanAl'in x'ini alanHesaplama nasil
   cekiyor?"

   CEVAP: CEKMIYOR. Iki sorun birbirine karisiyor. Ayri ayri:

   KARISIKLIK 1: "Ayni isim = ayni degisken" sanmak.
     void kullanicidanAl(int& x, int& y)
     int  alanHesaplama(int x, int y)
     Buradaki x'ler SADECE AYNI HARF. Birbirleriyle hicbir ilgileri
     yok. Birine a, digerine zeta desen program ayni calisir.
     alanHesaplama, kullanicidanAl'in varligindan bile habersiz.
     Veriyi tasiyan SADECE main'dir:
        kullanicidanAl(kisa, uzun);             // main kutulari doldurtur
        int alan = alanHesaplama(kisa, uzun);   // main dolu degerleri
                                                //  ELLE verir

   KARISIKLIK 2: "Degisken sadece kendi fonksiyonunda yasar" kuralini
   kutu sanmak. Bir degisken aslinda IKI seydir:
        KUTU : bellekte gercekten yer kaplayan, icinde deger olan sey
        ISIM : o kutuya erismek icin kullandigin etiket
     "Sadece fonksiyon icinde gecerli" kurali ISIMLER icindir.
     Bir kutunun birden fazla ismi olabilir.

     int& x  demek:  "Yeni kutu ACMA. Bana verilen kutuya x ismini ver."
     int  x  demek:  "Yeni kutu AC, verilen degerin fotokopisini koy."

     Yani:
        kullanicidanAl(kisa, uzun) cagrisinda
           x ismi  ->  main'deki kisa kutusunun IKINCI ISMI
           y ismi  ->  main'deki uzun kutusunun IKINCI ISMI
           (kutu tek, isim iki: kisa ve x)

           KUTU (adres 100)
           +------+
           |  5   |
           +------+
            ^    ^
          kisa   x      <- ayni kutu, iki etiket

        alanHesaplama(kisa, uzun) cagrisinda
           x, y -> tamamen YENI kutular, icine degerler kopyalandi

           main:  [kisa: 5][uzun: 10]  --kopya-->  [x: 5][y: 10]

   "Omur" kurali bozulmadi:
     - Fonksiyon bitince x ve y ISIMLERI olur.
     - Ama gosterdikleri KUTULAR main'e aittir ve main bitene kadar
       yasar. O yuzden kullanicinin girdigi degerler kaybolmaz.
     - & olmasaydi x gercekten yeni kutu olurdu, fonksiyon bitince
       girilen deger KAYBOLURDU ve kisa cop kalirdi.

   Hangi kutu hangi isme baglanir? ISIM degil, CAGRIDAKI SIRA belirler:
        kullanicidanAl(kisa, uzun);
        // 1. arguman (kisa) -> 1. parametre (x)
        // 2. arguman (uzun) -> 2. parametre (y)
     kullanicidanAl(uzun, kisa) yazsan x artik uzun'a baglanirdi.

   Kutunun ayni olup olmadigini belirleyen sey fonksiyonun ADI veya
   parametrenin ISMI degil, parametre tanimindaki & isaretidir.

   KANIT: Bolum [9]'daki demo adresleri yazdirir.
     main'deki sayi        : 0x...A
     adresReferans icinde r: 0x...A   <- AYNI adres = ayni kutu
     adresKopya icinde k   : 0x...B   <- FARKLI adres = yeni kutu
   (&degisken bellek adresini verir. Pointer konusunda detaylanacak.
    Adres degerleri her calistirmada degisebilir.)


   ------------------------------------------------------------
   OZET - EZBERLENECEK 5 CUMLE
   ------------------------------------------------------------
     1) Fonksiyon girdi alir, return ile cikti verir.
     2) & yok  -> KOPYA, orijinal degismez.
     3) & var  -> ORIJINALIN KENDISI (ikinci isim), degisebilir.
     4) Fonksiyonlar birbirini gormez; veriyi main tasir.
     5) Parametre isimleri yerel etikettir; ayni isim != ayni degisken.


   ------------------------------------------------------------
   ALISTIRMALAR (kendin dene)
   ------------------------------------------------------------
     A) void besYap(int sayi){ sayi = 5; }
        int elma = 9; besYap(elma); cout << elma;     // ekrana ne yazar?
        (Cevap: 9, cunku & yok, fotokopi degisti.)

     B) kullanicidanAl'daki & isaretlerini sil ve calistir.
        kisa/uzun neden 0 kaliyor? (Cevap: x ve y fotokopi oldu.)

     C) int alan = alanHesaplama(kisa, uzun);
        kullanicidanAl(kisa, uzun);
        Satirlari bu sirayla yazarsan hesap aninda kisa/uzun'da ne
        olur? (Cevap: ikisi de 0, alan 0 cikar; once veri toplanmali.)

     D) alanHesaplama icine x = 999; yazsan main'deki kisa degisir
        mi? (Cevap: hayir, x kopya.)


   ------------------------------------------------------------
   SIRADAKI KONULAR
   ------------------------------------------------------------
     - const referans (const int&, const std::string&): buyuk
       nesneleri kopyalamadan, degistirmeden gecirme
     - Pointer: &degisken adresinin gercek yuzu
     - std::pair / structured binding ile cok degerli donus
     - Fonksiyon asiri yukleme (overloading)
   ============================================================ */
