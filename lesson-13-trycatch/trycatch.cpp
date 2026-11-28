// =====================================================================
// try / catch / throw  (Exception Handling)
// =====================================================================
//
// ---------------------------------------------------------------------
// 0. HARITA
// ---------------------------------------------------------------------
// Bu konunun dayandigi kavram cifti:
//   hatayi FARK ETMEK : hatanin olustugu yer (cogu zaman derin bir fonksiyon)
//   hatayi ELE ALMAK  : ne yapilacagina karar verilen yer (cogu zaman yukarida)
// Bu iki yer genelde AYNI yer degildir. Exception, hatayi fark edilen
// yerden ele alinacak yere tasiyan mekanizmadir. Konunun ozu budur.
//
//   1. Uc anahtar kelime ve akis: try, throw, catch
//   2. Tip eslesmesi: hangi catch yakalar
//   3. Fonksiyondan throw: asil guc burada
//   4. Standart exception'lar: profesyonel yazim
//   5. C++ kendisi throw ETMEZ: C#'tan gelen en buyuk tuzak
//
// Notun tamami temel bilgi; ezberlenecek tablo yok. Sirayla oku.
//
// HER SEYI UNUTURSAN SUNLARI TUT:
//   - throw calistigi an, try blogunun KALANI atlanir, catch'e ziplanir.
//   - catch, throw edilen degerin TIPINE gore secilir.
//   - Sayiyi 0'a bolmek C++'ta exception DEGIL; kontrolu sen yaparsin.
//
// Takilirsan: okumayi birak, bir fonksiyondan throw et, main'de yakala.
// ---------------------------------------------------------------------

#include <iostream>
#include <stdexcept>    // std::runtime_error, std::invalid_argument (bolum 4)

using namespace std;

// ---------------------------------------------------------------------
// 1. UC ANAHTAR KELIME VE AKIS
// ---------------------------------------------------------------------
//   try   { ... }  : "bu blokta bir sey ters gidebilir, izle"
//   throw deger;   : "ters gitti" -> deger firlatilir (exception)
//   catch (Tip ad) : "bu tipte bir sey firlatildiysa buraya gel"
//
// AKIS (hocanin kodundaki mantik):
//   bolen != 0 -> throw calismaz -> try sonuna kadar calisir, catch ATLANIR
//   bolen == 0 -> throw 31 calisir -> try'in KALANI ATLANIR
//                 (sonuc hesaplanmaz, cout calismaz) -> catch(int) calisir
//   Her iki durumda da program catch'ten SONRAKI satirdan devam eder.
//
// throw bir "goto" degildir ama hissi oyle: o satirdan sonrasi
// try icinde hic calismaz. Fizik paraleli: bir devrede sigorta atinca
// akim devrenin geri kalanina gitmez, ama bina coken degil.
//
// Hocanin kodundaki "throw 31;": firlatilan deger 31, tipi int.
// catch (int hatakodu) bu yuzden onu yakalar; hatakodu = 31 olur.
// 31'in ozel bir anlami yok, herhangi bir int olabilirdi.
//
// Asagida hocanin kodu, cin yerine parametre alan bir fonksiyon
// halinde. Boylece program girdi beklemeden iki durumu da gosterir.
// ---------------------------------------------------------------------
namespace bolum1
{
    void bol(int bolunen, int bolen)
    {
        double sonuc;
        try
        {
            if (bolen == 0)
            {
                throw 31;                       // tip: int
            }
            sonuc = (double)bolunen / bolen;    // throw olursa BU SATIR CALISMAZ
            cout << "   sonuc: " << sonuc << '\n';
        }
        catch (int hatakodu)                    // int firlatildiysa buraya
        {
            cout << "   Bolen 0 olmamali! (hata kodu: " << hatakodu << ")\n";
        }
        cout << "   -> catch'ten sonra program devam ediyor\n";
    }

    void demo()
    {
        cout << "1) 10 / 4:\n";
        bol(10, 4);
        cout << "   10 / 0:\n";
        bol(10, 0);
    }
}

// ---------------------------------------------------------------------
// 2. TIP ESLESMESI: HANGI catch YAKALAR
// ---------------------------------------------------------------------
// Bir try'in arkasina birden fazla catch dizilebilir. throw edilen
// degerin TIPINE bakilir, YUKARIDAN ASAGIYA ilk uyan catch calisir,
// digerleri atlanir. (switch-case'e benzer, ama deger degil TIP eslesir.)
//
//   throw 31;      -> int        -> catch (int ...)
//   throw 2.5;     -> double     -> catch (double ...)
//   throw "metin"; -> const char*-> catch (const char* ...)
//   catch (...)    -> UC NOKTA: "ne olursa olsun" yakalar. HEP EN SONA yazilir.
//
// Dikkat: int ile double arasinda otomatik donusum YAPILMAZ.
// throw 2.5; bir catch(int)'e dusmez. Fonksiyon cagrisindaki
// promotion/conversion kurallari burada GECERLI DEGIL.
//
// Hicbir catch eslesmezse: exception yukari cikar (bolum 3), main'den
// de disari tasarsa program std::terminate ile aniden kapanir.
// ---------------------------------------------------------------------
namespace bolum2
{
    void dene(int secim)
    {
        try
        {
            if (secim == 1) throw 31;
            if (secim == 2) throw 2.5;
            if (secim == 3) throw "metin hatasi";
            if (secim == 4) throw 'x';          // char: asagida ozel catch'i yok
        }
        catch (int k)          { cout << "   int yakalandi: " << k << '\n'; }
        catch (double d)       { cout << "   double yakalandi: " << d << '\n'; }
        catch (const char* m)  { cout << "   metin yakalandi: " << m << '\n'; }
        catch (...)            { cout << "   bilinmeyen tip, catch(...) yakaladi\n"; }
    }

    void demo()
    {
        cout << "2) tip eslesmesi:\n";
        for (int i = 1; i <= 4; i++)
            dene(i);
    }
}

// ---------------------------------------------------------------------
// 3. FONKSIYONDAN throw: ASIL GUC BURADA
// ---------------------------------------------------------------------
// Hocanin ornegi try/catch'in sozdizimini ogretir ama gucunu gostermez:
// orada if-else ile ayni isi yapabilirdin. try/catch'in var olma sebebi
// sudur: throw ile catch FARKLI FONKSIYONLARDA olabilir.
//
// Bir fonksiyon throw ettiginde ve kendi icinde catch yoksa:
//   - fonksiyon ANINDA biter (return degeri bile olmadan),
//   - exception onu cagiran fonksiyona cikar,
//   - orada da catch yoksa bir ust seviyeye cikar...
//   - ilk uyan catch'te durur.
// Bu yukari cikisa "stack unwinding" denir: cikilan her fonksiyonun
// yerel degiskenleri bu sirada duzgunce yok edilir.
//
// Neden onemli: "hesapla" fonksiyonu hatayi FARK EDER ama ne yapilacagini
// BILEMEZ (ekrana mi yazsin, tekrar mi sorsun, oyunu mu durdursun?).
// Karari, durumu bilen ust seviye (main) verir. Bolum 0'daki kavram
// cifti tam olarak bu.
//
// Unity paraleli: bir alt sistem (ornegin kayit dosyasi okuyucu) hatayi
// bulur, ama kullaniciya mesaj gostermek UI'in isidir. Okuyucu throw
// eder, UI katmani catch eder.
// ---------------------------------------------------------------------
namespace bolum3
{
    double guvenliBol(int a, int b)
    {
        if (b == 0)
            throw 31;               // burada catch yok -> fonksiyon aninda biter
        return (double)a / b;
    }

    double ortalamaHizi(int yol, int sure)
    {
        double v = guvenliBol(yol, sure);   // throw olursa BU fonksiyon da biter
        cout << "   (bu satir sadece hata yoksa yazilir)\n";
        return v;
    }

    void demo()
    {
        cout << "3) fonksiyondan throw:\n";
        try
        {
            double v1 = ortalamaHizi(100, 4);
            cout << "   hiz: " << v1 << " m/s\n";
            double v2 = ortalamaHizi(100, 0);   // 2 seviye asagida throw
            cout << "   hiz: " << v2 << " m/s (bu satira hic gelinmez)\n";
        }
        catch (int kod)
        {
            cout << "   main seviyesinde yakalandi, kod " << kod << '\n';
        }
    }
}

// ---------------------------------------------------------------------
// 4. STANDART EXCEPTION'LAR: PROFESYONEL YAZIM
// ---------------------------------------------------------------------
// "throw 31;" ders icin uygundur ama gercek kodda kullanilmaz:
// 31 ne demek? Okuyan kisi bilmez, catch eden kisi de bilmez.
//
// Standart kutuphane hazir exception tipleri sunar (<stdexcept>):
//   std::runtime_error     : calisma sirasinda olusan genel hata
//   std::invalid_argument  : fonksiyona gecersiz arguman verildi
//   std::out_of_range      : sinir disi erisim
// Hepsi std::exception'dan turetilmistir ve hepsinde .what() vardir:
// throw ederken yazdigin aciklama metnini geri verir.
//
// Yakalama kalibi (bunu oldugu gibi kullan):
//     catch (const std::exception& e) { cout << e.what(); }
//   - const& : exception'i KOPYALAMADAN, DEGISTIRMEDEN yakala.
//     (& referans demek; kursta Call by Reference bolumunde gelecek.
//      Simdilik bu satiri bir kalip olarak kabul et.)
//   - std::exception : tum standart exception'larin atasi oldugu icin
//     hepsini tek catch ile yakalar.
// ---------------------------------------------------------------------
namespace bolum4
{
    double guvenliBol(int a, int b)
    {
        if (b == 0)
            throw invalid_argument("bolen sifir olamaz");
        return (double)a / b;
    }

    void demo()
    {
        cout << "4) standart exception:\n";
        try
        {
            double r1 = guvenliBol(7, 2);
            cout << "   7 / 2 = " << r1 << '\n';
            double r2 = guvenliBol(7, 0);       // throw -> alttaki satir atlanir
            cout << "   7 / 0 = " << r2 << '\n';
        }
        catch (const exception& e)
        {
            cout << "   hata: " << e.what() << '\n';
        }
    }
}

// ---------------------------------------------------------------------
// 5. C++ KENDISI throw ETMEZ: C#'TAN GELEN EN BUYUK TUZAK
// ---------------------------------------------------------------------
// C#'ta 10 / 0 yazarsan runtime sana DivideByZeroException firlatir.
// C++'ta BOYLE BIR SEY YOK.
//
//   int a = 10, b = 0;  a / b;   -> undefined behavior. Exception degil.
//                                   Program cokebilir ya da cop deger
//                                   uretebilir; try/catch bunu YAKALAMAZ.
//   double x = 10.0 / 0.0;       -> hata bile degil: sonuc "inf" olur.
//
// Ayni sekilde: dizi sinirinin disina tasmak, bos pointer'i kullanmak
// da C++'ta exception uretmez. Exception sadece birisi (sen ya da
// kutuphane) acikca "throw" yazdiginda olusur.
//
// Hocanin kodundaki "if (bolen == 0) throw 31;" satiri bu yuzden
// ZORUNLU. O kontrol olmasa catch hicbir zaman calismazdi.
//
// Kural: exception "beklenmedik ve burada cozulemeyen" durumlar icindir.
// Kullanicinin yanlis girdi vermesi gibi siradan, beklenen durumlari
// cogu zaman basit bir if ile cozmek daha sadedir.
// ---------------------------------------------------------------------
namespace bolum5
{
    void demo()
    {
        double x = 10.0 / 0.0;      // exception YOK, sonuc inf
        cout << "5) 10.0 / 0.0 = " << x << "  (exception firlatilmadi)\n";
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

// COMPILE: g++ -std=c++17 -Wall -Wextra trycatch.cpp -o program
