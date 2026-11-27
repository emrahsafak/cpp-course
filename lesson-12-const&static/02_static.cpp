// =====================================================================
// static
// =====================================================================
//
// ---------------------------------------------------------------------
// 0. HARITA
// ---------------------------------------------------------------------
// Bu konunun dayandigi kavram cifti (ONCE BUNU OTURT):
//   scope    (kapsam) : degiskenin ISMINE kodun neresinden erisilir
//   lifetime (omur)   : degiskenin BELLEGI ne zaman olusur, ne zaman silinir
// Normal yerel degiskende ikisi ayni: { ile dogar, } ile olur.
// static bu ikisini birbirinden AYIRIR. Butun konu bundan ibaret.
//
//   1. static yerel degisken                          [CEKIRDEK]
//   2. Neden calisiyor? Bellekte nerede yasiyor        [ANLA]
//   3. Tuzaklar: ne zaman static KULLANMAMALI          [ANLA]
//   4. Dosya seviyesinde static (internal linkage)     [REFERANS]
//
// OKUMA ROTASI
//   ilk tur   : 1                (kod yazmak icin yeterli)
//   ikinci tur: 2 -> 3           (nedenini anlamak icin)
//   ezberlenmez: 4               (cok dosyali projede karsina cikinca ac)
//
// HER SEYI UNUTURSAN SUNLARI TUT:
//   - static yerel degisken fonksiyon bitince SILINMEZ, degerini korur.
//   - Ilk deger atamasi SADECE BIR KEZ, ilk cagrida yapilir.
//   - Ismi yine sadece o fonksiyonun icinden gorulur.
//
// Takilirsan: okumayi birak, bir sayac fonksiyonu yaz, static'i sil, farki gor.
// ---------------------------------------------------------------------

#include <iostream>

using namespace std;

// ---------------------------------------------------------------------
// 1. static YEREL DEGISKEN                                  [CEKIRDEK]
// ---------------------------------------------------------------------
// Normal yerel degisken: fonksiyon her cagrildiginda sifirdan olusur,
// fonksiyon bitince yok olur. Bir onceki cagridan hicbir sey hatirlamaz.
//
// static yerel degisken:
//   - scope   : DEGISMEDI. Hala sadece bu fonksiyonun icinden gorulur.
//   - lifetime: DEGISTI. Programin sonuna kadar yasar.
//   - "static int sayac = 0;" satiri SADECE ilk cagrida calisir.
//     Sonraki cagrilarda bu satir atlanir, sayac eski degeriyle devam eder.
//
// Unity paraleli: MonoBehaviour'daki bir field gibi dusun, Update()
// her cagrildiginda sifirlanmaz. Ama static yerel degisken bir field'dan
// farkli olarak disaridan GORUNMEZ, sadece o fonksiyona aittir.
// ---------------------------------------------------------------------
namespace bolum1
{
    void normalSayac()
    {
        int sayac = 0;          // her cagrida yeniden olusur, 0 olur
        sayac++;
        cout << sayac << ' ';
    }

    void staticSayac()
    {
        static int sayac = 0;   // sadece ilk cagrida 0 yapilir
        sayac++;                // her cagrida bir oncekinin uzerine ekler
        cout << sayac << ' ';
    }

    void demo()
    {
        cout << "1) normal: ";
        for (int i = 0; i < 3; i++)
            normalSayac();
        cout << '\n';

        cout << "   static: ";
        for (int i = 0; i < 3; i++)
            staticSayac();
        cout << '\n';

        // cout << sayac;
        // HATA (g++): 'sayac' was not declared in this scope
        // static omru uzatir, kapsami GENISLETMEZ.
    }
}

// ---------------------------------------------------------------------
// 2. NEDEN CALISIYOR? BELLEKTE NEREDE YASIYOR                   [ANLA]
// ---------------------------------------------------------------------
// Normal yerel degiskenler STACK'te yasar. Fonksiyon cagrildiginda
// stack'te onun icin yer acilir, fonksiyon donunce o yer geri verilir.
// Bu yuzden degerleri kaybolur.
//
// static yerel degiskenler stack'te DEGIL, programin "statik bellek"
// bolgesinde yasar (global degiskenlerle ayni yer). Bu bolge program
// baslarken ayrilir, program bitince birakilir. Fonksiyonun donmesi
// onlara dokunmaz.
//
// Ek kural: ilk deger yazilmazsa static degisken SIFIR ile baslar.
// Normal yerel degisken ise ilk degersiz rastgele (belirsiz) degerle baslar (okumak
// undefined behavior). Yine de her zaman ilk degeri acikca yaz.
//
// Stack/heap ayrintisi kursta "Stack ve Heap Kavrami" bolumunde gelecek.
// ---------------------------------------------------------------------
namespace bolum2
{
    int kacinciCagri()
    {
        static int n;           // ilk deger yazilmadi -> 0 ile baslar
        return ++n;
    }

    void demo()
    {
        kacinciCagri();
        kacinciCagri();
        const int son = kacinciCagri();
        cout << "2) kacinciCagri 3 kez cagrildi, son deger: " << son << '\n';
    }
}

// ---------------------------------------------------------------------
// 3. TUZAKLAR: NE ZAMAN static KULLANMAMALI                     [ANLA]
// ---------------------------------------------------------------------
// static yerel degisken "gizli global"dir. Fonksiyon artik ayni
// girdiyle cagrildiginda hep ayni sonucu VERMEZ, cunku bir hafizasi var.
//
//   - Test etmesi zorlasir: sonuc, daha once kac kez cagrildigina baglidir.
//   - Sifirlanamaz: disaridan erisilemedigi icin "bastan baslat" diyemezsin.
//   - Coklu thread'de (ileride) ortak durum = dikkat gerektirir.
//
// Asagidaki demo tuzagi gosteriyor: toplam fonksiyonu ikinci
// listede eski toplamdan devam ediyor.
//
// Kural: static yerel degiskeni SADECE gercekten "programin omru
// boyunca bir kez olusturulup saklanacak" sey icin kullan
// (cagri sayaci, bir kez hazirlanan tablo vb.). Hesap sonucu tasimak
// icin kullanma; onu parametre ve return ile tasi.
// ---------------------------------------------------------------------
namespace bolum3
{
    int yanlisToplam(int deger)
    {
        static int toplam = 0;  // tuzak: liste degisse de sifirlanmaz
        toplam += deger;
        return toplam;
    }

    void demo()
    {
        int sonuc = 0;
        sonuc = yanlisToplam(1);
        sonuc = yanlisToplam(2);
        cout << "3) ilk liste (1,2) toplami: " << sonuc << '\n';

        sonuc = yanlisToplam(10);
        sonuc = yanlisToplam(20);
        cout << "   ikinci liste (10,20) toplami: " << sonuc
             << "  <- 30 beklenirdi, 33 cikti\n";
    }
}

// ---------------------------------------------------------------------
// 4. DOSYA SEVIYESINDE static (INTERNAL LINKAGE)            [REFERANS]
// ---------------------------------------------------------------------
// !! Bu bolum tek dosyalik programlarda hicbir sey degistirmez. Birden
// !! fazla .cpp dosyasi olan bir projede "multiple definition" linker
// !! hatasi aldiginda acilir. Tutulacak tek kural: bir global degisken
// !! veya yardimci fonksiyon sadece bu dosyada kullaniliyorsa, onu
// !! static yap (ya da isimsiz namespace icine koy).
//
// Fonksiyon DISINDA kullanilan static'in anlami tamamen farklidir:
// burada omur zaten program boyudur, static omru degistirmez.
// Degistirdigi sey linkage'dir: "bu isim baska .cpp dosyalarindan
// GORULMESIN." Yani ayni kelime, bu sefer scope/gorunurluk ekseninde.
//
// Modern C++'ta ayni isi isimsiz namespace de yapar:
//     namespace { int gizli = 5; }
//
// Sinif icindeki static uye (static member) ayri bir konudur;
// kursta OOP bolumunde gelecek.
// ---------------------------------------------------------------------
namespace bolum4
{
    static int dosyayaOzel = 42;    // sadece bu .cpp dosyasindan gorulur

    void demo()
    {
        cout << "4) dosyayaOzel = " << dosyayaOzel << '\n';
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

// COMPILE: g++ -std=c++17 -Wall -Wextra static.cpp -o program
