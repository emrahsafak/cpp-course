#include <iostream>

/*  LESSON 3 - CONST VE CONSTEXPR (BEST PRACTICES)

    Hedef:
    - const ve constexpr farkini anlamak
    - Magic number'lari isimli sabitlere cevirmek
    - Fonksiyon parametresinde const ile "okuma-only" garanti vermek
    - Hesaplanan sonuc degiskenlerini const yapmak

    Not: Bu dosyada "using namespace std;" KULLANILMADI, std:: acik yazildi.
*/

// ---------------- BOLUM 1: KOD ----------------

// Derleme zamani sabitleri (global, tipli, isimli)
constexpr int    NOT_SAYISI = 4;
constexpr double GECME_NOTU = 50.0;

// Fonksiyon diziyi sadece OKUYABILIR, degistiremez.
double ortalamaHesapla(const double dizi[], int adet)
{
    double toplam = 0.0;

    for (int i = 0; i < adet; ++i) {
        toplam += dizi[i];
        // dizi[i] = 0;   // <-- Acilirsa DERLEME HATASI verir
    }

    return toplam / adet;
}

int main()
{
    double sinavNotlari[NOT_SAYISI] = {};

    for (int i = 0; i < NOT_SAYISI; ++i) {
        std::cout << i + 1 << ". sinav notunu girin: ";
        std::cin >> sinavNotlari[i];
    }

    const double ortalama = ortalamaHesapla(sinavNotlari, NOT_SAYISI);

    std::cout << "Sinav notlarinin ortalamasi: " << ortalama << '\n';

    if (ortalama >= GECME_NOTU) {
        std::cout << "Sonuc: GECTI\n";
    } else {
        std::cout << "Sonuc: KALDI\n";
    }

    return 0;
}


// -------------------------------------------------------
//  BOLUM 2 - KODUN SATIR SATIR ACIKLAMASI
// -------------------------------------------------------
//
//  SATIR: #include <iostream>
//  cout ve cin icin gerekli kutuphane. Derleyiciye "bu dosyayi koda
//  dahil et" der.
//
//  SATIR: constexpr int NOT_SAYISI = 4;
//  constexpr : "bu deger DERLEME ZAMANINDA kesin olarak bilinir" demektir.
//  Tip (int) acikca yazili; #define'in aksine tipi ve kapsami vardir.
//  Global yazildigi icin tum fonksiyonlar gorur. Isim BUYUK_HARF
//  yazilir: sabit oldugu bir bakista anlasilsin diye (yaygin gelenek).
//  Lesson 2'deki "const int NOT_SAYISI" ile calisir ama constexpr daha
//  guclu bir garantidir, bu yuzden dizi boyutu icin ilk tercihtir.
//
//  SATIR: constexpr double GECME_NOTU = 50.0;
//  Gecme siniri. Kodun icinde "50" yazmak yerine isim kullaniriz.
//  Siniri 45 yapmak istersen TEK satiri degistirirsin.
//
//  SATIR: double ortalamaHesapla(const double dizi[], int adet)
//  - double (donus tipi): fonksiyon bir ondalikli sayi geri verir.
//  - const double dizi[]: "bu diziyi sadece okuyacagim, yazmayacagim"
//    sozu. Fonksiyonu cagiran kisi govdeyi okumadan bu garantiyi gorur.
//  - int adet: dizi fonksiyona ADRES olarak gider (arka planda pointer'a
//    donusur, buna "decay" denir), boyut bilgisi KAYBOLUR. Bu yuzden
//    eleman sayisini ayrica parametre olarak veririz.
//
//  SATIR: double toplam = 0.0;
//  Burada const YOK, cunku toplam dongude surekli degisiyor.
//  Kural: sadece degismeyecek olani const yap.
//
//  SATIR: for (int i = 0; i < adet; ++i) { toplam += dizi[i]; }
//  Diziyi bastan sona gezer. Sinir artik sabit bir sayi degil, gelen
//  "adet" parametresidir; fonksiyon her boyuttaki diziyle calisir.
//  "// dizi[i] = 0;" satiri yorumdan cikarilirsa derleyici hata verir
//  (const koruma). Bug calisma zamaninda degil, DERLERKEN yakalanir.
//
//  SATIR: return toplam / adet;
//  toplam double oldugu icin bolme ondalikli yapilir. Sonuc cagirana
//  geri doner.
//
//  SATIR: double sinavNotlari[NOT_SAYISI] = {};
//  Boyut constexpr oldugu icin gecerlidir. "= {}" tum kutulari 0 yapar
//  (cop deger riski yok). Dizi burada const DEGIL, cunku notlari
//  asagida cin ile dolduruyoruz. Dolduktan sonra yazilmayacak ama
//  doldurma sirasinda yazilmasi gerekir.
//
//  SATIR: for (...) { cout ...; cin >> sinavNotlari[i]; }
//  Lesson 2'deki gibi 4 notu kullanicidan alip diziye yazar.
//
//  SATIR: const double ortalama = ortalamaHesapla(sinavNotlari, NOT_SAYISI);
//  Burada ikinci onemli nokta: const degisken, CALISMA ZAMANINDA
//  hesaplanan bir degerle de baslatilabilir. Ortalama bir kez
//  hesaplanir ve bir daha degismez; const olmasi dogru niyettir.
//  Diziyi fonksiyona verirken non-const dizi, const parametreye
//  otomatik ve guvenle donusur (kisitlama ekleyebilirsin, kaldiramazsin).
//
//  SATIR: std::cout << ... << '\n';
//  '\n' sadece satir sonu ekler. std::endl ayrica tamponu bosaltir
//  (flush) ve yavastir; cogu durumda '\n' yeterlidir.
//
//  SATIR: if (ortalama >= GECME_NOTU) { ... } else { ... }
//  Magic number yerine isimli sabit: kod kendini acikliyor.


// -------------------------------------------------------
//  BOLUM 3 - GENEL KONU: CONST ILE BEST PRACTICES
// -------------------------------------------------------
//
//  CONST NEDIR?
//  Derleyiciyle imzalanan bir sozlesme: "Bu deger degismeyecek.
//  Degistirmeye kalkarsam beni durdur." Unity'deki kilitli Inspector
//  alani gibi dusunulebilir, ama kilit DERLEME ZAMANINDA calisir.
//
//  "BEST PRACTICES" NE DEMEK?
//  const teknik olarak zorunlu degildir ama profesyoneller onu varsayilan
//  olarak her yerde kullanir. Kural: bir seyin degismesi icin sebep
//  yoksa const yap. Zihniyet: HER SEY const baslar, degismesi gerektigini
//  kanitlarsan const'u kaldirirsin.
//
//  NEDEN ONEMLI?
//  1) Hata yakalama : yanlislikla degisiklik derleme hatasi olur,
//                     sessiz bug olmaz.
//  2) Niyet iletimi : kodu okuyan "bu sabit" bilgisini aninda alir.
//  3) Magic number  : 4, 50 gibi anlami belirsiz sayilar isimli
//                     sabitlere donusur.
//  4) Optimizasyon  : derleyici sabit bildigi degerlerle daha agresif
//                     optimize edebilir.
//
//  UC SABIT TURU:
//    const     : baslatildiktan sonra degistirilemez. Degeri derleme
//                veya calisma zamaninda belirlenebilir.
//    constexpr : degeri DERLEME ZAMANINDA kesin hesaplanabilir olmak
//                zorundadir. const'tan guclu garanti.
//    #define   : eski C mirasi. Tipi yok, kapsami yok, hata mesajlari
//                anlasilmaz. Modern C++'ta KACIN.
//
//  LESSON 2'DEKI NOTUN DUZELTMESI:
//  "Boyut olarak const degisken kullanilabilir" cumlesi YARIM dogruydu.
//  Sadece degeri derleme zamaninda bilinen const kullanilabilir:
//
//      const int a = 4;            // OK, 4 sabit literal
//      int girilen; cin >> girilen;
//      const int n = girilen;      // const ama degeri calisma zamaninda
//      double dizi[n];             // standart C++'ta HATA
//
//  const sadece "degismez" der, "ne zaman bilindigini" garanti etmez.
//  Dizi boyutu icin dogru arac constexpr'dir.
//
//  TUZAKLAR:
//    - const degisken tanimlandigi anda deger almak zorundadir:
//        const double x;   // HATA
//    - Her seyi const yapma: toplam gibi degisen degiskenler const
//      olamaz. Mantik: "degismesi icin sebep var mi?"
//    - Dizi parametresinde boyut bilgisi kaybolur; sizeof(dizi) fonksiyon
//      icinde dizinin degil pointer'in boyutunu verir. Boyutu ayri gonder.
//
//  C# ILE KARSILASTIRMA:
//    C# const     ~ C++ constexpr (derleme zamani sabiti)
//    C# readonly  ~ C++ const (bir kez atanir, sonra degismez)
//    C#'ta "readonly" alanin icerigi degisebilir (referans tipinde),
//    C++ const dizi ise elemanlarini da kilitler.
//
//  SIRADAKI KONU:
//  const + pointer/referans: const int*, int* const, const&.
//  C++'in ilk "beyin yakan" noktasi, ama dogru modelle net oturur.
