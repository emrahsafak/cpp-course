#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// 0. HARITA
// -----------------------------------------------------------------------
// Bu not su soruyu bastan sona cevaplar: ayni isimli birden fazla fonksiyon
// nasil tanimlanir, derleyici bunlardan hangisini neye gore secer, ve bu
// mekanizma hangi noktalarda beklenmedik sonuc uretir.
//
// Dosya asagidaki sirayla ilerler. Her bolumde once kavram anlatilir, hemen
// altinda o kavramin calisan kodu gelir. main() en sonda tum bolumleri
// sirayla cagirir, boylece dosya hem okunacak bir not hem calisan bir
// programdir.
//
//    1. On bilgi: karistirilmasi kolay uc kavram cifti
//    2. Overloading nedir, neden vardir
//    3. Tanim: birlikte aranan uc sart
//    4. Signature (imza) nedir
//    5. Signature'i farkli yapan seyler
//    6. Signature'i farkli YAPMAYAN seyler
//    7. Tanim anindaki hatalar
//    8. Cagri ani: overload resolution
//    9. Cagri anindaki hatalar ve klasik tuzaklar
//   10. Savunma araclari: nullptr ve = delete
//   11. Ileri basliklar: const uye fonksiyon, template, name hiding
//   12. Pratik kurallar
//
// Kod ve kimlikler Ingilizce, aciklamalar Turkce, teknik terimler Ingilizce
// birakilmistir (signature, exact match, promotion, conversion ...).


// 1. ON BILGI: KARISTIRILMASI KOLAY UC KAVRAM CIFTI
// -----------------------------------------------------------------------
// Overloading, bu uc ciftin ayrimi oturmadan ogrenilemez. Konunun tamami
// bunlarin uzerine kurulur.
//
// 1.1. PARAMETER ve ARGUMENT
//      parameter : fonksiyonu YAZARKEN tanimlanan yer tutucu (placeholder).
//                  "int number" ifadesindeki number.
//      argument  : fonksiyonu CAGIRIRKEN verilen gercek deger.
//                  "multiplyByTwo(5)" ifadesindeki 5.
//      Argument'lar parameter'lara SIRAYLA baglanir. Parameter'in ismi
//      yalnizca fonksiyonun govdesinde anlamlidir; cagiran taraf o ismi
//      hic gormez. Bu yuzden parameter ismini serbestce secebilirsiniz.
//
// 1.2. CALL (cagirma) ve RETURN (dondurme)
//      call   : bir fonksiyonu calistirmak. TUR KISITI YOKTUR. Herhangi bir
//               fonksiyonun icinden herhangi bir fonksiyonu cagirabilirsiniz.
//               void bir fonksiyon, int donduren bir fonksiyonu cagirabilir.
//      return : bulundugunuz fonksiyonun sonucunu cagirana teslim etmek.
//               TUR KISITI VARDIR: return ifadesinin turu, ICINDE
//               BULUNDUGUNUZ fonksiyonun return type'ina uymak zorundadir.
//      return yazarken sorulacak tek soru sudur:
//               "Hangi fonksiyonun icindeyim ve onun return type'i ne?"
//      Cagirdiginiz baska fonksiyonlarin return type'i bu soruyu etkilemez.
//
// 1.3. RETURN TYPE ve PARAMETER LISTESI
//      Bunlar fonksiyonun iki ayri ucudur:
//        parameter listesi -> fonksiyona NE GIRER   (giris ucu)
//        return type       -> fonksiyondan NE CIKAR (cikis ucu)
//      Overloading YALNIZCA giris ucuyla ilgilenir. Asagidaki her sey bu
//      cumlenin sonucudur.

namespace prelude {

int multiplyByTwo(int number)
{
    return number * 2;
}

// Bu fonksiyonun return type'i void. Icinde int donduren bir fonksiyonu
// cagirmasi tamamen gecerlidir; yasak olan, kendi icinden deger DONDURMEK.
void demo()
{
    int doubled = multiplyByTwo(5);   // call serbest: int fonksiyon cagrildi
    std::cout << "1. On bilgi\n";
    std::cout << "  multiplyByTwo(5) = " << doubled << '\n';
    // return doubled;   // HATA: demo() void oldugu icin deger teslim edemez.
                         // Sebep doubled'in turu DEGIL (o bir int);
                         // sebep return'un bulundugu fonksiyonun void olmasi.
}

} // namespace prelude


// 2. OVERLOADING NEDIR, NEDEN VARDIR
// -----------------------------------------------------------------------
// Overloading olmasaydi, ayni isi farkli turler icin yapan fonksiyonlara
// farkli isimler vermek zorunda kalirdiniz:
//
//     void printInt(int value);
//     void printDouble(double value);
//     void printString(const std::string& value);
//
// Overloading, hepsine ayni ismi vermeye izin verir:
//
//     void print(int value);
//     void print(double value);
//     void print(const std::string& value);
//
// Siz print(5) yazarsiniz; derleyici ARGUMENT'IN TURUNE bakarak hangisinin
// calisacagina karar verir.
//
// Kazanc estetik degil, mimaridir: cagiran kod, veri turu degistiginde
// fonksiyon ismini degistirmek zorunda kalmaz. std::cout << operatorunun ve
// Unity'deki Debug.Log'un tek bir isimle onlarca turu kabul etmesinin
// mekanizmasi tam olarak budur.
//
// Onemli: overloading bir CALISMA ZAMANI esnekligi degildir. Karar derleme
// aninda verilir (bkz. bolum 8), yani runtime maliyeti sifirdir. MATLAB'da
// nargin / isa ile her cagrida calisma aninda yaptiginiz dallanmayi, C++
// derleme anina tasir.


// 3. TANIM: BIRLIKTE ARANAN UC SART
// -----------------------------------------------------------------------
// Function overloading = AYNI SCOPE icinde, AYNI ISIMLI, fakat PARAMETER
// LISTESI FARKLI olan birden fazla fonksiyonun tanimlanmasi.
//
// Uc sart birlikte aranir:
//
//   (a) AYNI SCOPE
//       Farkli scope'taki ayni isimli fonksiyonlar overload OLMAZ; icteki
//       olan distakini gizler. Buna name hiding denir (bkz. bolum 11.3).
//
//   (b) AYNI ISIM
//       Isimler farkliysa ortada overloading yoktur. printInt ve printDouble
//       birbirinden bagimsiz iki fonksiyondur; aralarinda secim yapilacak bir
//       durum yoktur, cunku ismi siz zaten soylemissiniz.
//       Bu ayrim onemlidir: "signature'lari farkli olan fonksiyonlar
//       overload'dir" demek YANLIStir. Isim de signature'in parcasi oldugu
//       icin, isimleri farkli iki fonksiyonun signature'i da farklidir -- ama
//       onlar overload degildir. Dogru kosul: isim ayni, parameter listesi
//       farkli.
//
//   (c) FARKLI PARAMETER LISTESI
//       Liste de ayniysa bu AYNI fonksiyondur; ikinci tanim redefinition
//       hatasi verir.
//
// Tek cumlede: overloading, "ayni ismi yazdigimda derleyici dogrusunu
// secebiliyor mu?" sorusudur.


// 4. SIGNATURE (IMZA) NEDIR
// -----------------------------------------------------------------------
// Signature, derleyicinin iki fonksiyon bildirimini "ayni fonksiyon mu,
// farkli fonksiyon mu?" diye karsilastirdigi kimliktir.
//
// Siradan (template olmayan) bir fonksiyon icin:
//
//     signature = fonksiyon adi + parameter turlerinin SAYISI ve SIRASI
//
// Uye fonksiyonlarda ek olarak sondaki const / volatile nitelemesi de
// signature'a girer (bkz. bolum 11.1).
//
// Signature'a DAHIL DEGILDIR: return type ve parameter isimleri.
//
// Signature ile overloading kurali arasindaki iliski:
//
//     Isimler farkli mi?
//       |- Evet -> iki bagimsiz fonksiyon. Overloading meselesi yok.
//       |- Hayir (isim ayni, ayni scope)
//            |- parameter listesi farkli -> GECERLI OVERLOAD
//            |- parameter listesi ayni    -> AYNI FONKSIYON -> cakisma hatasi


// 5. SIGNATURE'I FARKLI YAPAN SEYLER
// -----------------------------------------------------------------------
// Asagidakilerden HERHANGI BIRININ farkli olmasi gecerli bir overload yaratir.
//
//   5.1. Parameter SAYISI       : print(int)        / print(int, int)
//   5.2. Parameter TURU         : print(int)        / print(double)
//   5.3. Turlerin SIRASI        : print(string,int) / print(int,string)
//   5.4. Referansin gosterdigi turdeki const : modify(int&) / modify(const int&)
//        Bunlar iki ayri turdur: "degistirilebilir int'e referans" ve
//        "salt-okunur int'e referans".
//   5.5. Pointer'in gosterdigi turdeki const : f(int*) / f(const int*)
//   5.6. Lvalue / rvalue referans : f(const T&) / f(T&&)
//        Kopyalama ve tasima (move) ayrimini mumkun kilar. Move semantigi
//        ayri bir konu oldugu icin burada yalnizca varligi not edilmistir.

namespace different_signature {

void print(int value)                          { std::cout << "  print(int): " << value << '\n'; }
void print(double value)                       { std::cout << "  print(double): " << value << '\n'; }
void print(int first, int second)              { std::cout << "  print(int, int): " << first << " " << second << '\n'; }
void print(const std::string& text, int count) { std::cout << "  print(string, int): " << text << " " << count << '\n'; }
void print(int count, const std::string& text) { std::cout << "  print(int, string): " << count << " " << text << '\n'; }

// const&, string'i kopyalamadan gecirir (performans) ve gecici (rvalue)
// nesneleri de kabul eder. Bu yuzden parameter olarak tercih edilir.

void modify(int& target)      { target = 42; }
void modify(const int& value) { std::cout << "  modify(const int&): " << value << " (salt okunur)\n"; }

void demo()
{
    std::cout << "5. Signature'i farkli yapan seyler\n";

    print(5);                            // print(int)
    print(2.5);                          // print(double)
    print(1, 2);                         // print(int, int)
    print(std::string("repeat"), 3);     // print(string, int)
    print(3, std::string("repeat"));     // print(int, string) -- ayni turler, ters sira

    int counter = 0;
    modify(counter);                     // counter const degil -> modify(int&)
    std::cout << "  modify(int&) sonrasi counter = " << counter << '\n';

    const int locked = 7;
    modify(locked);                      // locked const -> yalnizca const& versiyonu uygun
}

} // namespace different_signature


// 6. SIGNATURE'I FARKLI YAPMAYAN SEYLER
// -----------------------------------------------------------------------
// Konunun ayirt edici bolgesi burasidir. Asagidaki degisiklikler fonksiyonu
// ayirt etmeye YETMEZ; yani bunlarla overload uretemezsiniz.
//
// 6.1. PARAMETER ISMI
//      void f(int a);
//      void f(int b);   // HATA: redefinition of 'void f(int)'
//      Her ikisinin signature'i f(int). Parameter ismi govdenin icindeki bir
//      etikettir, derleyici icin ayirt edici bilgi degildir.
//
// 6.2. RETURN TYPE
//      int    add(int a, int b);
//      double add(int a, int b);   // HATA
//      GCC  : ambiguating new declaration of 'double add(int, int)'
//      Clang: functions that differ only in their return type cannot be overloaded
//
//      NEDEN? Cagri noktasina bakin:
//          add(2, 3);            // donen deger hicbir yere gitmiyor
//      Bu satirda sonuc kullanilmiyor. Derleyicinin elinde "hangi return type
//      isteniyor?" sorusuna verecek bir bilgi yoktur; yalnizca 2 ve 3 vardir.
//      Secim ZORUNLU OLARAK argument'lara bakilarak yapilir. Return type'i
//      ayirt edici yapmak, bu satirda cozumsuz bir durum yaratirdi.
//
//      Teknik kanit (name mangling): derleyici her fonksiyona arka planda
//      isim + parameter turlerinden bir sembol uretir.
//          add(int, int)       -> _Z3addii
//          add(double, double) -> _Z3adddd
//      Sembole return type HIC katilmaz. Dolayisiyla yalnizca return type'i
//      farkli iki fonksiyon ayni sembolu uretir, yani cakisir. C dilinde
//      overloading olmamasinin sebebi de budur: C sembolleri mangle etmez.
//
//      BURADA IKI SEYI KARISTIRMAMAK GEREKIR:
//        - Overload'lar ARASINDA return type'in farkli olmasi SERBESTtir.
//          int add(int,int) ile double add(double,double) birlikte yasar.
//        - Ama return type'in farkli olmasi bir fonksiyonu digerinden
//          AYIRMAYA YETMEZ. Ayiran sey her zaman parameter listesidir.
//
// 6.3. BY-VALUE PARAMETER'DAKI UST DUZEY (top-level) const
//      void f(int value);
//      void f(const int value);   // HATA: ayni signature -> redefinition
//      Sebep: int by-value alindiginda fonksiyon cagiranin degiskeninin bir
//      KOPYASINI alir. Fonksiyonun kendi kopyasini degistirip degistirmedigi
//      cagiran tarafi ilgilendirmez. Bu const tamamen fonksiyonun ic
//      meselesidir, arayuzun parcasi degildir.
//
//      const nerede duruyor diye bakma kurali:
//          f(const int)   -> const kopyanin kendisinde (top-level)  -> ETKISIZ
//          f(const int&)  -> const referansin gosterdigi turde      -> ETKILI
//          f(int* const)  -> const pointer'in kendisinde            -> ETKISIZ
//          f(const int*)  -> const pointer'in gosterdigi turde      -> ETKILI
//      Ozet: const, cagiranin gordugu bir seyi koruyorsa signature'a girer;
//      yalnizca fonksiyonun yerel kopyasini kilitliyorsa girmez.
//
// 6.4. DEFAULT ARGUMENT
//      Default argument signature'i DEGISTIRMEZ:
//          void f(int a, int b);
//          void f(int a, int b = 5);   // signature ikisinde de f(int, int)
//      Ikisinin de govdesi yazilirsa redefinition hatasi alinir. Yani default
//      argument ekleyerek bir fonksiyonu digerinden AYIRT EDEMEZSINIZ.
//
//      Buna ragmen default argument, GECERLI overload'larla birlikte
//      kullanildiginda cagri aninda belirsizlik yaratabilir:
//          void f(int a);                // signature: f(int)
//          void f(int a, int b = 5);     // signature: f(int, int) -> farkli
//                                        // tanimlar GECERLI
//          f(1, 2);   // yalnizca f(int, int) uygun -> NET
//          f(1);      // f(int) uygun; f(int, int) de uygun (b = 5 devreye
//                     // girer) -> iki aday esit iyi -> AMBIGUOUS -> HATA
//
//      Mekanizma: default argument, CAGRI NOKTASINDA uygulanan bir
//      kolayliktir. Derleyici f(1) ifadesini f(1, 5) olarak tamamlayabilir.
//      Bu tamamlama fonksiyonun KIMLIGINI (signature'ini) degistirmez, ama
//      onu DAHA FAZLA CAGRIYLA ESLESEBILIR hale getirir -- ve bu, komsu
//      overload'la cakisma yaratir.
//
//      Iki cumlede ayrim: signature fonksiyonun kimligidir; default argument
//      o fonksiyonun hangi cagrilarla eslesebilecegini genisletir. Kimlik
//      sabit kalir, eslesme alani buyur.
//
// 6.5. TYPE ALIAS (typedef / using)
//      using Metre = int;
//      void distance(Metre value);
//      void distance(int value);   // HATA: Metre int'in takma adi -> ayni
//                                  // signature -> redefinition
//      using yeni bir tur yaratmaz, yalnizca takma ad verir. Gercekten ayri
//      bir tur istiyorsaniz struct veya enum class kullanmaniz gerekir.
//
// 6.6. DIZI VE FONKSIYON PARAMETRELERI (adjustment)
//      void f(int data[]);   // derleyici bunu f(int*) olarak duzeltir
//      void f(int* data);    // HATA: ayni signature -> redefinition
//      void g(int data[5]);  // bu da g(int*)'tir; boyut bilgisi atilir
//      Parameter listesinde dizi turu otomatik olarak pointer'a cevrilir
//      (array-to-pointer adjustment). Ayni sey fonksiyon turleri icin de
//      gecerlidir: f(int()) ile f(int(*)()) aynidir.

namespace same_signature {

using Metre = int;

// Metre, int'in takma adi oldugu icin asagidaki fonksiyonun signature'i
// distance(int)'tir. Bu yuzden ayrica bir distance(int) tanimlanamaz.
void distance(Metre value) { std::cout << "  distance(Metre == int): " << value << '\n'; }
// void distance(int value) { }   // HATA: redefinition of 'void distance(int)'

void demo()
{
    std::cout << "6. Signature'i farkli yapmayan seyler\n";
    distance(100);   // Metre bir tur degil, isimdir: int argument sorunsuz gecer
}

} // namespace same_signature


// 7. TANIM ANINDAKI HATALAR
// -----------------------------------------------------------------------
// Overloading hatalari iki ayri zamanda ortaya cikar. Bu ayrimi gormek, hata
// mesajlarini okumayi kolaylastirir. Once fonksiyonlari YAZARKEN cikanlar:
//
//   Ayni signature, ikisinin de govdesi var
//       -> redefinition
//       -> ornek: void f(int a){}  void f(int b){}
//
//   Ayni signature, yalnizca return type farkli
//       -> cannot be overloaded / ambiguating new declaration
//       -> ornek: int f(int);  double f(int);
//
// Bu iki hata, siz hic cagri yazmadan, yalnizca tanimlara bakilarak verilir.
// Cok yayilmis bir yanlis anlama sudur: "return type farkliysa derleyici
// hangisini cagiracagini bilemez (ambiguity)". Mekanizma boyle degildir --
// hata CAGRIDA degil, TANIMDA verilir. Gercek ambiguous call hatasi,
// imzalarin gecerli olup cagrinin cozulemedigi durumdur (bkz. bolum 9.1).


// 8. CAGRI ANI: OVERLOAD RESOLUTION
// -----------------------------------------------------------------------
// Tanimlar gecerliyse, sira cagrida hangisinin secilecegine gelir. Surec uc
// adimlidir ve tamami DERLEME ZAMANINDA isler.
//
//   Adim 1 -- CANDIDATE FUNCTIONS (adaylar)
//     Derleyici o isimle gorunur olan tum fonksiyonlari toplar. Bu arama
//     (name lookup) overload resolution'dan ONCE calisir ve bir scope'ta
//     eslesme buldugu anda durur (bkz. name hiding, bolum 11.3).
//
//   Adim 2 -- VIABLE FUNCTIONS (uygun adaylar)
//     Adaylardan su iki kosulu saglayanlar kalir:
//       - argument sayisi parameter sayisina uyuyor (default argument'lar
//         hesaba katilarak),
//       - her argument, karsilik gelen parameter turune DONUSTURULEBILIYOR.
//
//   Adim 3 -- BEST VIABLE FUNCTION (en iyi aday)
//     Kalanlar arasinda en iyi eslesme secilir. Siralama (iyiden kotuye):
//
//       1) EXACT MATCH          : tur birebir ayni
//                                 int argument -> int parameter
//       2) PROMOTION            : bilgi kaybi olmayan guvenli genisletme
//                                 char / short / bool -> int ; float -> double
//       3) STANDARD CONVERSION  : diger yerlesik donusumler
//                                 int -> double ; long -> int ; pointer -> bool
//       4) USER-DEFINED CONV.   : sizin yazdiginiz constructor veya operator T
//                                 const char* -> std::string
//       5) ELLIPSIS (...)       : C tarzi degisken argument -- en kotu
//
//     Ustteki kategori kazanir. Ayni kategoride iki aday esit iyiyse kazanan
//     yoktur: ambiguous hatasi verilir.
//
// Bir cagrinin uc olasi sonucu vardir: BASARI, AMBIGUOUS, NO MATCHING
// FUNCTION. Ucuncusu, hicbir adayin viable olmadigi durumdur.

namespace resolution {

void rank(int value)    { std::cout << "  rank(int): " << value << '\n'; }
void rank(double value) { std::cout << "  rank(double): " << value << '\n'; }

void demo()
{
    std::cout << "8. Overload resolution\n";

    rank(5);        // int literal -> EXACT MATCH -> rank(int)
    rank(2.5);      // double literal -> EXACT MATCH -> rank(double)

    rank('A');      // char -> int  : PROMOTION  (2. seviye)
                    // char -> double: CONVERSION (3. seviye)
                    // Promotion ustte oldugu icin rank(int) kazanir ve ekrana
                    // 'A' degil, onun sayisal degeri olan 65 yazilir.

    rank(3.14f);    // float -> double: PROMOTION ; float -> int: CONVERSION
                    // Promotion kazanir -> rank(double)

    // rank(5L);    // AMBIGUOUS: bkz. bolum 9.1
}

} // namespace resolution


// 9. CAGRI ANINDAKI HATALAR VE KLASIK TUZAKLAR
// -----------------------------------------------------------------------
// 9.1. AMBIGUOUS CALL -- iki aday esit iyi
//      void rank(int);  void rank(double);
//      rank(5L);
//        5L bir long'dur.
//        long -> int    : standard conversion (3. seviye)
//        long -> double : standard conversion (3. seviye)
//        Ikisi ayni seviyede, esit iyi -> kazanan yok ->
//        "call of overloaded 'rank(long int)' is ambiguous"
//      Derleyici tahmin yurutmez. Bu bir tasarim tercihidir: sessizce yanlis
//      fonksiyonu secmek, derleme hatasindan cok daha pahaliya gelir.
//      Cozum, secimi acikca yapmaktir:  rank(static_cast<int>(5L));
//
//      Ayni durum uc adayla da olusur:
//      void rank(int); void rank(long); void rank(double);
//      rank(5u);   // unsigned int: uc donusum de 3. seviyede -> ambiguous
//
// 9.2. NO MATCHING FUNCTION -- hic uygun aday yok
//      void rank(int);  void rank(double);
//      rank(std::string("hello"));
//        std::string ne int'e ne double'a donusur; hicbir aday viable degil
//        -> "no matching function for call to 'rank(std::string)'"
//      Not: ayni yerde rank("hello") yazsaniz GCC baska bir tani mesaji verir:
//      const char* -> int yolunu deneyip "invalid conversion from 'const char*'
//      to 'int' [-fpermissive]" der. Mesaj farkli, sonuc ayni: cagri
//      karsilanamaz. Hata mesajinin lafzina degil, hangi asamada (tanim mi,
//      cagri mi) ciktigina bakmak gerekir.
//
// 9.3. TUZAK: PROMOTION, CONVERSION'I YENER
//      rank('A') cagrisinin 65 yazdirmasi bir hata degil, siralamanin
//      dogrudan sonucudur. 'A' karakterinin sayisal degeri 65'tir ve secilen
//      overload int aldigi icin sayi olarak yazdirilir. Beklenti 'A' gormekse,
//      bir rank(char) overload'i eklemek gerekir (exact match olur).
//
// 9.4. TUZAK: STRING LITERAL, bool'u KAZANDIRIR
//      Konunun en cok can yakan tuzagi:
//          void log(bool flag);
//          void log(const std::string& text);
//          log("literal");   // -> log(bool) calisir, ekrana "true" yazar!
//
//      NEDEN? "literal" ifadesinin turu const char[8]'dir ve const char*'a
//      donusur. Buradan iki yol vardir:
//          const char* -> bool        : STANDARD CONVERSION (3. seviye)
//          const char* -> std::string : USER-DEFINED CONVERSION (4. seviye)
//      3. seviye 4. seviyeyi yener, dolayisiyla bool kazanir.
//
//      COZUM: const char* icin dogrudan bir overload eklemek. Exact match
//      (1. seviye) her ikisini de yener:
//          void log(const char* text) { log(std::string(text)); }
//
//      GENEL DERS: ayni ismi farkli turlerle asiri yukledigimizde, implicit
//      donusumlerin beklemedigimiz bir adayi kazandirip kazandirmadigini
//      kontrol etmek zorundayiz. bool parameter'lari bu konuda en
//      tehlikelisidir, cunku neredeyse her pointer ve sayi ona donusebilir.
//
// 9.5. TUZAK: f(int) ile f(int&) birlikte
//      void f(int value);
//      void f(int& ref);     // tanim GECERLI: signature'lar farkli
//      int x = 1;
//      f(x);     // ikisi de exact match -> AMBIGUOUS -> HATA
//      f(5);     // int& bir rvalue'ya baglanamaz -> yalnizca f(int) uygun
//      Tanimlarin gecerli olmasi, her cagrinin cozulebilecegini garanti
//      etmez. Bu ikisini ayni arada kullanmaktan kacinin.

namespace literal_trap {

void log(bool flag)               { std::cout << "  log(bool): " << std::boolalpha << flag << '\n'; }
void log(const std::string& text) { std::cout << "  log(string): " << text << '\n'; }

void safeLog(bool flag)               { std::cout << "  safeLog(bool): " << std::boolalpha << flag << '\n'; }
void safeLog(const std::string& text) { std::cout << "  safeLog(string): " << text << '\n'; }
void safeLog(const char* text)        { safeLog(std::string(text)); }   // cozum satiri

void demo()
{
    std::cout << "9. Klasik tuzaklar\n";
    log("literal");       // beklenti: string ; gerceklesen: bool -> "true"
    safeLog("literal");   // const char* overload'i exact match -> string'e yonlenir
}

} // namespace literal_trap


// 10. SAVUNMA ARACLARI: nullptr VE = delete
// -----------------------------------------------------------------------
// 10.1. nullptr
//       void handle(int value);
//       void handle(char* text);
//         handle(0);         // 0 bir int literal -> handle(int) (exact match)
//         handle(nullptr);   // nullptr_t yalnizca pointer'a donusur -> handle(char*)
//         handle(NULL);      // NULL cogu derleyicide 0 veya 0L -> handle(int)'e
//                            // gider ya da belirsiz olur
//       Eski NULL makrosu bir tam sayi oldugu icin pointer overload'ini
//       kacirir. Modern C++'ta pointer icin DAIMA nullptr kullanilir.
//
// 10.2. = delete
//       void setHealth(int hp);
//       void setHealth(double) = delete;
//         setHealth(100);    // OK
//         setHealth(99.9);   // HATA: use of deleted function
//       Silinmis fonksiyon overload resolution'a ADAY OLARAK katilir;
//       secilirse derleme hatasi verir. Bu olmasaydi 99.9 sessizce 99'a
//       kirpilirdi. Yani = delete, sessiz veri kaybini derleme zamani
//       hatasina ceviren bir guvenlik agidir. MATLAB'in sessizce isledigi
//       yerde C++ sizi derleme aninda durdurur.

namespace guards {

void handle(int value)  { std::cout << "  handle(int): " << value << '\n'; }
void handle(char* text) { std::cout << "  handle(char*): " << (text ? "dolu" : "null") << '\n'; }

void setHealth(int hp)        { std::cout << "  setHealth(int): " << hp << '\n'; }
void setHealth(double) = delete;   // double argument'i kasitli olarak yasakla

void demo()
{
    std::cout << "10. Savunma araclari\n";
    handle(0);         // int literal kazanir
    handle(nullptr);   // pointer overload'i secilir
    setHealth(100);
    // setHealth(99.9);   // HATA: use of deleted function -> sessiz kirpma engellendi
}

} // namespace guards


// 11. ILERI BASLIKLAR
// -----------------------------------------------------------------------
// Bu uc baslik da ayni kurallara dayanir; yalnizca henuz islenmemis
// kavramlara deger. Simdilik mekanizmayi tanimak yeterlidir.
//
// 11.1. UYE FONKSIYONLARDA const OVERLOADING
//       class Buffer {
//           int&       at(std::size_t i);         // signature: at(size_t)
//           const int& at(std::size_t i) const;   // signature: at(size_t) const
//       };
//       Ikisinin de gorunur parameter listesi ayni (size_t), yine de bu
//       gecerli bir overload'dir. Sebep: her uye fonksiyonun gizli bir this
//       parameter'i vardir. Sondaki const, bu gizli parameter'in turunu
//       Buffer*'dan const Buffer*'a cevirir. Yani parameter listesi ASLINDA
//       farklidir -- bolum 3'un kurali burada da aynen gecerli, farklilik
//       sadece gizli parameter'da.
//       Sonuc: const olmayan nesnede yazilabilir versiyon, const nesnede
//       salt-okunur versiyon secilir. std::vector::operator[] tam olarak
//       boyle calisir. C#'ta tasarimla (ReadOnlyCollection) sagladiginiz seyi
//       C++ derleyiciye tip sistemi uzerinden garanti ettirir.
//
// 11.2. TEMPLATE ILE OVERLOAD
//       template <typename T> void show(T value);   // template
//                             void show(int value); // non-template
//         show(5);     // ikisi de exact match -> esitlikte NON-TEMPLATE kazanir
//         show(5.5);   // template exact; non-template icin conversion gerekir
//                      //   -> TEMPLATE kazanir
//         show('a');   // template exact (T = char); non-template icin promotion
//                      //   gerekir -> TEMPLATE kazanir ('a' yazar, 97 degil)
//       Kural sirasi: once donusum seviyesi (bolum 8'deki siralama), seviyeler
//       esitse non-template tercih edilir.
//
// 11.3. SCOPE VE NAME HIDING
//       Bolum 3'teki "ayni scope" sartinin sonucu: farkli scope'taki ayni
//       isimli fonksiyonlar overload OLMAZ, icteki distakini GIZLER.
//           struct Base    { void speak(int value);    };
//           struct Derived : Base { void speak(double value); };
//           Derived d;
//           d.speak(5);   // Derived::speak(double) cagrilir!
//                         // Base::speak(int) gizlendigi icin aday listesine
//                         // bile girmez
//       Mekanizma: name lookup, overload resolution'dan ONCE calisir. Isim
//       arama bir scope'ta eslesme buldugu anda durur ve disariya hic bakmaz.
//       Overload resolution yalnizca o scope'ta bulunanlar arasinda yapilir;
//       aday listesi olusmadan secim yapilamaz.
//       Cozum, base'in overload'larini scope'a tasimaktir: using Base::speak;
//
// 11.4. main OVERLOAD EDILEMEZ
//       Standart bunu acikca yasaklar. main, isletim sistemiyle sozlesmesi
//       olan ozel bir fonksiyondur.

namespace advanced {

class Buffer {
public:
    explicit Buffer(std::size_t size) : data_(size, 0) {}

    // const olmayan nesne icin: degistirilebilir referans doner
    int& at(std::size_t index)
    {
        std::cout << "  at() [non-const]\n";
        return data_[index];
    }

    // const nesne icin: salt-okunur referans doner.
    // Sondaki const, gizli this parameter'ini const Buffer* yapar -> ayri signature
    const int& at(std::size_t index) const
    {
        std::cout << "  at() [const]\n";
        return data_[index];
    }

private:
    std::vector<int> data_;
};

template <typename T>
void show(T value) { std::cout << "  show<T>(T) [template]: " << value << '\n'; }

void show(int value) { std::cout << "  show(int) [non-template]: " << value << '\n'; }

struct Base
{
    void speak(int value) { std::cout << "  Base::speak(int): " << value << '\n'; }
};

struct Derived : Base
{
    void speak(double value) { std::cout << "  Derived::speak(double): " << value << '\n'; }
};

void demo()
{
    std::cout << "11. Ileri basliklar\n";

    Buffer buffer(4);
    buffer.at(0) = 99;                    // non-const nesne -> yazilabilir versiyon

    const Buffer& readOnly = buffer;      // const referans
    const int& stored = readOnly.at(0);   // -> const versiyon secilir
    std::cout << "  deger: " << stored << '\n';

    show(5);      // esitlik -> non-template
    show(5.5);    // template exact -> template
    show('a');    // template exact -> template ('a' yazar)

    Derived derived;
    derived.speak(5);   // Derived::speak(double) -- Base::speak(int) gizlendi
}

} // namespace advanced


// 12. PRATIK KURALLAR
// -----------------------------------------------------------------------
//  1. Overloading = ayni scope + ayni isim + farkli parameter listesi.
//     Ucu birlikte aranir. Isimleri farkli iki fonksiyon overload DEGILDIR.
//
//  2. Ayni isimli fonksiyonlari ayiran TEK SEY parameter listesidir
//     (sayi, tur, sira). Return type ve parameter ismi ayirmaz.
//
//  3. Secim yalnizca ARGUMENT'lara bakilarak, DERLEME ZAMANINDA yapilir.
//     Runtime maliyeti sifirdir.
//
//  4. Siralama: exact match > promotion > standard conversion >
//     user-defined conversion > ellipsis. Esitlikte ambiguous, uygun aday
//     yoksa no matching function hatasi.
//
//  5. Overload setine bool parameter'i eklerken dikkat: string literal'ler ve
//     pointer'lar bool'a standard conversion ile gider. Gerekiyorsa
//     const char* overload'i ekleyin.
//
//  6. Pointer icin daima nullptr; NULL veya 0 kullanmayin.
//
//  7. Istenmeyen implicit donusumu = delete ile yasaklayin.
//
//  8. Ayni cagriyi hem overload hem default argument ile karsilamayin.
//     Davranis ayni ve yalnizca opsiyonel parametre varsa -> tek fonksiyon +
//     default argument. Davranis / algoritma farkliysa -> overload, default
//     argument olmadan.
//
//  9. Asiri yuklemeyi "ayni isi yapan farkli turler" icin kullanin. Isler
//     farkliysa farkli isim verin: overloading bir isim tasarrufu araci
//     degil, ayni kavramin farkli turlerdeki karsiligini sunma aracidir.

int main()
{
    prelude::demo();
    std::cout << '\n';

    different_signature::demo();
    std::cout << '\n';

    same_signature::demo();
    std::cout << '\n';

    resolution::demo();
    std::cout << '\n';

    literal_trap::demo();
    std::cout << '\n';

    guards::demo();
    std::cout << '\n';

    advanced::demo();

    return 0;
}

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson10_overloading.cpp -o program
