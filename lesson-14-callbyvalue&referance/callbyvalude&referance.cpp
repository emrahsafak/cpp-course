// =====================================================================
// Call by Value  ve  Call by Reference
// =====================================================================
//
// ---------------------------------------------------------------------
// 0. HARITA
// ---------------------------------------------------------------------
// Bu konunun dayandigi kavram cifti:
//   kopya (copy) : ayni DEGERE sahip, ama BELLEKTE AYRI bir degisken
//   takma ad (alias / reference) : ayni BELLEGE verilmis IKINCI bir isim
// Fonksiyona arguman gecerken soru hep sudur: fonksiyon orijinali mi
// aliyor, yoksa onun bir fotokopisini mi?
//
//   1. Call by value: fonksiyon kopya alir
//   2. Reference degisken: bir degiskene ikinci isim
//   3. Call by reference: fonksiyon orijinali alir
//   4. const reference: kopyalamadan, degistirmeden okumak
//   5. Hangisini ne zaman kullanirim (karar tablosu)
//
// Notun tamami temel bilgi; sirayla oku.
//
// HER SEYI UNUTURSAN SUNLARI TUT:
//   - int deger   -> kopya. Fonksiyon ne yaparsa yapsin, orijinal degismez.
//   - int& deger  -> orijinalin kendisi. Fonksiyondaki degisiklik disari yansir.
//   - Degistirmeyecegin buyuk veri -> const T& (kopya yok, degisiklik yok).
//
// Takilirsan: okumayi birak, bir fonksiyon yaz, & koy, sil, ciktiyi karsilastir.
// ---------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

// ---------------------------------------------------------------------
// 1. CALL BY VALUE: FONKSIYON KOPYA ALIR
// ---------------------------------------------------------------------
// void degistir(int deger) cagrildiginda:
//   - fonksiyon icin stack'te YENI bir int (deger) olusur,
//   - sayi'nin DEGERI (5) bu yeni degiskene kopyalanir,
//   - fonksiyon deger'i 10 yapar -> sadece kopya degisir,
//   - fonksiyon bitince deger yok olur, sayi hala 5'tir.
//
// Kanit: iki degiskenin ADRESINE bakmak. &x, x'in bellekteki adresini
// verir (pointer bolumunde detayli gelecek). Adresler farkliysa, bunlar
// iki AYRI degiskendir.
//
// MATLAB paraleli: MATLAB fonksiyonlari zaten hep boyle calisir.
// Fonksiyona verdigin matrisi icerde degistirsen bile disaridaki matris
// degismez; degisikligi geri almak icin cikis degiskeni dondurursun.
// ---------------------------------------------------------------------
namespace bolum1
{
    void degistir(int deger)        // deger: sayi'nin KOPYASI
    {
        deger = deger * 2;
        cout << "   fonksiyon ici deger: " << deger << '\n';
        cout << "   deger'in adresi : " << &deger << '\n';
    }

    void demo()
    {
        cout << "1) call by value:\n";
        int sayi = 5;
        cout << "   sayi'nin adresi  : " << &sayi << '\n';
        degistir(sayi);
        cout << "   main'de sayi     : " << sayi << "  (degismedi)\n";
    }
}

// ---------------------------------------------------------------------
// 2. REFERENCE DEGISKEN: BIR DEGISKENE IKINCI ISIM
// ---------------------------------------------------------------------
//     int x = 5;
//     int& r = x;     // r, x'in takma adi
// Burada YENI bir int olusmaz. r ve x ayni bellek kutusuna bakan iki
// isimdir. r'ye yazmak, x'e yazmaktir.
//
// Dikkat: & isareti iki farkli yerde iki farkli anlam tasir:
//   int& r = x;     -> TIPIN yaninda: "r bir reference"
//   cout << &x;     -> DEGISKENIN onunde: "x'in adresi"
// Ayni sembol, baglama gore farkli is. Bunu karistirmamak onemli.
//
// Reference'in iki kurali:
//   KURAL 1: Tanimlandigi an bir degiskene baglanmak ZORUNDA.
//            Bos (hicbir seye bagli olmayan) reference yoktur.
//   KURAL 2: Bir kez baglandiktan sonra BASKA degiskene baglanamaz.
//            "r = y;" r'yi y'ye baglamaz; y'nin DEGERINI x'e yazar.
// ---------------------------------------------------------------------
namespace bolum2
{
    void demo()
    {
        cout << "2) reference degisken:\n";
        int x = 5;
        int& r = x;                 // r = x'in ikinci adi

        // int& bos;
        // HATA (g++): 'bos' declared as reference but not initialized

        r = 20;                     // aslinda x'e yaziyor
        cout << "   x = " << x << ", r = " << r << '\n';
        cout << "   ayni adres mi? " << (&x == &r ? "evet" : "hayir") << '\n';

        int y = 99;
        r = y;                      // KURAL 2: r y'ye BAGLANMADI, x = 99 oldu
        cout << "   r = y sonrasi x = " << x << " (r hala x'e bagli)\n";
    }
}

// ---------------------------------------------------------------------
// 3. CALL BY REFERENCE: FONKSIYON ORIJINALI ALIR
// ---------------------------------------------------------------------
// Parametre tipine & eklemek yeterli:
//     void degistir(int& deger)
// Artik deger, cagiranin degiskeninin (sayi'nin) takma adidir.
// Kopya OLUSMAZ. Fonksiyondaki her yazma dogrudan sayi'ya gider.
//
// Cagri satiri DEGISMEZ: degistir(sayi); Cagiran tarafta fark gorunmez,
// fark sadece fonksiyonun imzasinda. Bu yuzden bir fonksiyonu
// kullanirken imzasina bakmak gerekir: & varsa, arguman degisebilir.
//
// Sonucu: reference parametreye sabit sayi verilemez.
//     degistir(5);  -> 5'in bellekte degistirilebilir bir kutusu yok.
//
// Klasik kullanim: swap. Iki degiskenin yerini degistirmek. Call by
// value ile IMKANSIZ, cunku fonksiyon sadece kopyalari degistirirdi.
// Ayrica bir fonksiyondan birden fazla sonuc almanin bir yolu.
//
// C# paraleli: C#'taki 'ref' anahtar kelimesi. Farki: C#'ta cagiran da
// 'ref' yazmak zorunda (Degistir(ref sayi)), C++'ta yazmaz.
// ---------------------------------------------------------------------
namespace bolum3
{
    void degistir(int& deger)       // deger: sayi'nin KENDISI
    {
        deger = deger * 2;
        cout << "   fonksiyon ici deger: " << deger << '\n';
    }

    void takas(int& a, int& b)
    {
        int gecici = a;             // a'nin eski degerini sakla
        a = b;
        b = gecici;
    }

    void demo()
    {
        cout << "3) call by reference:\n";
        int sayi = 5;
        degistir(sayi);
        cout << "   main'de sayi     : " << sayi << "  (degisti)\n";

        // degistir(5);
        // HATA (g++): cannot bind non-const lvalue reference of type 'int&'
        //             to an rvalue of type 'int'

        int p = 1, q = 2;
        takas(p, q);
        cout << "   takas sonrasi p = " << p << ", q = " << q << '\n';
    }
}

// ---------------------------------------------------------------------
// 4. const REFERENCE: KOPYALAMADAN, DEGISTIRMEDEN OKUMAK
// ---------------------------------------------------------------------
// Call by value'nun bir maliyeti var: KOPYA. int icin onemsiz (4 bayt).
// Ama 10.000 karakterlik bir string ya da buyuk bir nesne her cagrida
// bastan sona kopyalanir. Bu hem zaman hem bellek demektir.
//
// Cozum: reference ile gec (kopya yok) + const ekle (degisiklik yok):
//     void yazdir(const string& metin)
//   - & : orijinali al, kopyalama
//   - const : fonksiyon icinde metin'e yazilamaz (const notuna bak)
// Boylece call by value'nun GUVENLIGI ile call by reference'in HIZI
// birlikte gelir.
//
// Bonus: const reference sabit degeri de kabul eder:
//     yazdir("merhaba");  -> gecerli (bolum 3'teki degistir(5) gecersizdi)
// Degistirilmeyecegi garanti oldugu icin derleyici gecici bir nesne
// olusturup onu baglar.
//
// try/catch notundaki catch (const exception& e) satiri tam olarak budur:
// exception nesnesini kopyalamadan ve degistirmeden yakalamak.
// ---------------------------------------------------------------------
namespace bolum4
{
    void yazdir(const string& metin)
    {
        // metin += "!";
        // HATA (g++): no match for 'operator+=' (operand types are
        //             'const std::string' and 'const char [2]')
        // Kisaca: const bir string'e ekleme yapan bir += yok.
        cout << "   " << metin << " (" << metin.size() << " karakter)\n";
    }

    void demo()
    {
        cout << "4) const reference:\n";
        string uzunMetin = "Bu metin fonksiyona kopyalanmadan gonderildi";
        yazdir(uzunMetin);          // degiskenle
        yazdir("sabit metin");      // sabitle de calisir
    }
}

// ---------------------------------------------------------------------
// 5. HANGISINI NE ZAMAN KULLANIRIM (KARAR TABLOSU)
// ---------------------------------------------------------------------
// Parametre yazarken iki soru sor:
//   1) Fonksiyon bu argumani DEGISTIRMELI mi?
//   2) Arguman BUYUK mu (string, dizi, nesne)?
//
//   +---------------------------+---------------+------------------+
//   | durum                     | yazim         | ornek            |
//   +---------------------------+---------------+------------------+
//   | kucuk tip, sadece oku     | T             | int, double, char|
//   | buyuk tip, sadece oku     | const T&      | const string&    |
//   | orijinali degistir        | T&            | int&, string&    |
//   +---------------------------+---------------+------------------+
//
// Neden kucuk tipte const& degil de kopya? int'i kopyalamak, bir
// adresi tasimak kadar ucuz (hatta daha hizli). Gereksiz & okunurlugu
// bozar.
//
// T& kullanirken: fonksiyonun adi degisikligi belli etmeli
// (takas, ikiyeKatla, sifirla). Okuyan kisi cagri satirindan
// argumanin degisecegini anlayamaz; isim bunu soylemeli.
// ---------------------------------------------------------------------
namespace bolum5
{
    double ortalama(int a, int b)           // kucuk, sadece oku -> kopya
    {
        return (a + b) / 2.0;
    }

    void selamla(const string& isim)        // buyuk, sadece oku -> const&
    {
        cout << "   merhaba " << isim << '\n';
    }

    void ikiyeKatla(double& x)              // degistir -> &
    {
        x *= 2;
    }

    void demo()
    {
        cout << "5) karar tablosu ornekleri:\n";
        cout << "   ortalama(3, 4) = " << ortalama(3, 4) << '\n';
        selamla("Emrah");
        double hiz = 12.5;
        ikiyeKatla(hiz);
        cout << "   ikiyeKatla sonrasi hiz = " << hiz << '\n';
    }
}

// ---------------------------------------------------------------------
int main()
{
    bolum1::demo();
    bolum2::demo();
    bolum3::demo();
    bolum4::demo();
    bolum5::demo();
    return 0;
}

// COMPILE: g++ -std=c++17 -Wall -Wextra parameters.cpp -o program
