#include <iostream>
#include <string>    // string turu icin gerekli
#include <cstddef>   // size_t icin gerekli
#include <iterator>  // size() fonksiyonu icin gerekli (C++17)

using namespace std;

int main()
{
    // ---------------- DERS 1 ----------------
    int dizi[5] = { 12, 20, 8, 45, 18 };

    for (size_t i = 0; i < size(dizi); ++i)
    {
        cout << i + 1 << ". eleman : " << dizi[i] << '\n';
    }

    cout << "dizi[1] icin yeni degeri giriniz: ";
    cin >> dizi[1];

    for (size_t i = 0; i < size(dizi); ++i)
    {
        cout << i + 1 << ". eleman : " << dizi[i] << '\n';
    }

    // ---------------- DERS 2 ----------------
    cout << "\n--- Ders 2: bos koseli parantez ve farkli turler ---\n";

    double arr[] = { 21.2, 25.75, 27.01 };
    string mevsimler[] = { "ilkbahar", "yaz", "sonbahar", "kis" };
    int kismi[5] = { 1, 2 };

    for (size_t i = 0; i < size(arr); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < size(mevsimler); ++i)
    {
        cout << mevsimler[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < size(kismi); ++i)
    {
        cout << kismi[i] << " ";
    }
    cout << endl;

    cout << "arr eleman sayisi : " << size(arr) << '\n';
    cout << "arr toplam bayt   : " << sizeof(arr) << '\n';

    return 0;
}


// -------------------------------------------------------
//  BOLUM 2 — KODUN SATIR SATIR ACIKLAMASI
// -------------------------------------------------------
//
//  ---------- DERS 1 ----------
//
//  SATIR: int dizi[5] = { 12, 20, 8, 45, 18 };
//  RAM'de yan yana 5 tane int kutusu acar ve degerleri ayni anda yazar.
//  Her int 4 bayt oldugu icin toplam bellek: 5 x 4 = 20 bayt.
//  Boyut [5] derleme zamaninda sabit olmak zorundadir.
//
//  SATIR: for (size_t i = 0; i < size(dizi); ++i)
//  i       : index sayaci, 0'dan baslar (ilk kutu baslangictan 0 kutu ileride).
//  size(dizi) : dizinin eleman sayisini verir (5). Dizi buyurse
//            kodu degistirmek gerekmez; elle yazilan "5" boyle degildir.
//  size_t  : size()'in dondurdugu isaretsiz tur. Ayni turu kullanmak
//            isaretli/isaretsiz karsilastirma uyarisini onler.
//  ++i     : i'yi 1 artirir. Her turdan sonra calisir.
//  Tur sayisi: i = 0, 1, 2, 3, 4 (i = 5 oldugunda sart bozulur, dongu biter).
//
//  SATIR: cout << i + 1 << ". eleman : " << dizi[i] << '\n';
//  dizi[i] : i. kutunun icindeki degeri okur.
//  i + 1   : sadece okunabilirlik icin. Index 0'dan baslar, insan 1'den sayar.
//  '\n'    : alt satira gecer.
//
//  SATIR: cin >> dizi[1];
//  Klavyeden okunan sayiyi DOGRUDAN 1 numarali kutuya yazar.
//  Eski deger (20) silinir. Kutunun adresi degismez, sadece icerigi degisir.
//
//  SATIR: ikinci for dongusu
//  Ayni dongu tekrar calisir. Bu sefer dizinin guncel halini yazar.
//
//  ---------- DERS 2 ----------
//
//  SATIR: double arr[] = { 21.2, 25.75, 27.01 };
//  Kose parantezin ICI BOS birakilmistir. Derleyici suslu parantezin
//  icindeki deger sayisini sayar ve boyutu kendisi belirler: 3.
//  Yani bu satir "double arr[3] = {...}" ile birebir aynidir.
//  double 8 bayt oldugu icin toplam bellek: 3 x 8 = 24 bayt.
//  Bos [] YALNIZCA ilk deger verilen tanimlamada kullanilabilir.
//
//  SATIR: string mevsimler[] = { "ilkbahar", "yaz", "sonbahar", "kis" };
//  Dizi her turden olabilir; hepsi ayni turden olmak zorundadir.
//  Burada 4 tane string kutusu var, boyut yine otomatik (4).
//  string icin <string> kutuphanesi eklenmelidir.
//
//  SATIR: int kismi[5] = { 1, 2 };
//  Boyut 5 ama sadece 2 deger verilmis. Verilmeyen kutular
//  otomatik olarak 0 ile doldurulur: 1 2 0 0 0.
//
//  SATIR: cout << arr[i] << " ";
//  Her elemandan sonra bosluk yazar, boylece hepsi ayni satirda kalir.
//
//  SATIR: cout << endl;
//  Satir sonuna gecer ve tamponu bosaltir. Sonraki cikti yeni satirda baslar.
//
//  SATIR: cout << "arr toplam bayt   : " << sizeof(arr) << '\n';
//  sizeof(arr) TUM dizinin bayt sayisini verir (24), eleman sayisini degil.
//  Eleman sayisi = sizeof(arr) / sizeof(arr[0]) = 24 / 8 = 3.
//
//  GERCEK CALISMA CIKTISI (kullanici 98 girdi):
//    1. eleman : 12
//    2. eleman : 20
//    3. eleman : 8
//    4. eleman : 45
//    5. eleman : 18
//    dizi[1] icin yeni degeri giriniz: 98
//    1. eleman : 12
//    2. eleman : 98      <-- degisen kutu
//    3. eleman : 8
//    4. eleman : 45
//    5. eleman : 18
//
//    --- Ders 2: bos koseli parantez ve farkli turler ---
//    21.2 25.75 27.01
//    ilkbahar yaz sonbahar kis
//    1 2 0 0 0
//    arr eleman sayisi : 3
//    arr toplam bayt   : 24
//
//  BELLEKTE NE DEGISTI? (Ders 1)
//    index     ONCE     SONRA
//    dizi[0]   12       12
//    dizi[1]   20  -->  98
//    dizi[2]   8        8
//    dizi[3]   45       45
//    dizi[4]   18       18


// -------------------------------------------------------
//  BOLUM 3 — GENEL KONU: DIZI (ARRAY) MANTIGI
// -------------------------------------------------------
//
//  DIZI NEDIR?
//  RAM'de yan yana duran, ayni turden kutulardan olusan bloktur.
//
//  BELLEK YERLESIMI (kurs anlatimi, adresler ORNEKTIR):
//    index     deger    adres
//    dizi[0]   12       100
//    dizi[1]   20       104   (+4 bayt)
//    dizi[2]   8        108   (+4 bayt)
//    dizi[3]   45       112   (+4 bayt)
//    dizi[4]   18       116   (+4 bayt)
//
//  ERISIM FORMULU:
//    dizi[i] adresi = baslangic adresi + i * sizeof(tur)
//    Ornek: dizi[3] -> 100 + 3 * 4 = 112
//  Bilgisayar elemani aramaz, adresi hesaplar. Bu yuzden erisim
//  dizi ne kadar buyuk olursa olsun ayni surede gerceklesir.
//
//  INDEX NEDEN 0'DAN BASLAR?
//  Index "baslangictan kac kutu ileride" demektir.
//  Ilk kutu baslangicta durdugu icin indexi 0'dir.
//
//  DIZI TANIMLAMANIN UC YOLU:
//    1) Once tanimla, sonra tek tek doldur (kursun ilk gosterdigi yontem):
//         int dizi[5];
//         dizi[0] = 12;
//         dizi[1] = 20;   ... seklinde devam eder.
//       Uzun ve hataya acik. Doldurmadan okunan kutu cop deger tasir.
//    2) Boyut ve degerleri birlikte ver:
//         int dizi[5] = { 12, 20, 8, 45, 18 };
//    3) Boyutu bos birak, derleyici saysin:
//         double arr[] = { 21.2, 25.75, 27.01 };
//       Eleman eklersen ya da cikarirsan boyutu elle guncellemene gerek kalmaz.
//
//  KISMI BASLATMA:
//    int a[5] = { 1, 2 };   -> 1 2 0 0 0   (kalanlar 0 olur)
//    int b[5] = {};         -> 0 0 0 0 0   (hepsi 0)
//    int c[5];              -> cop deger   (ilk deger verilmemis)
//  Dizi boyutundan FAZLA deger verilirse derleme hatasi olur:
//    int d[2] = { 1, 2, 3 };   // HATA
//
//  FARKLI TURDE DIZILER:
//    int       tam sayilar        (4 bayt)
//    double    ondalikli sayilar  (8 bayt)
//    string    metinler           (boyutu derleyiciye gore degisir)
//  Bir dizinin TUM elemanlari AYNI turden olmak zorundadir.
//  Ayni dizide hem int hem string tutulamaz.
//
//  DONGU SINIRI: SABIT SAYI YERINE size()
//  Kurs ornegi:
//    for (int i = 0; i < 5; i++)   // 5 elle yazilmis
//  Sorun: diziye eleman ekler ve donguyu guncellemeyi unutursan
//  ya son eleman yazilmaz ya da dizinin disina taşilir.
//  Cozum: i < size(dizi). Dizi buyuse kucukse dongu kendini uyarlar.
//  Eski yontem (C++17 oncesi): sizeof(dizi) / sizeof(dizi[0])
//
//  i++ ILE ++i:
//  Kurs i++ kullaniyor, biz ++i kullandik. Tamsayilarda sonuc ayni.
//  ++i ileride iterator ve sinif turlerinde gereksiz kopya yapmaz,
//  bu yuzden profesyonel kodda tercih edilir.
//
//  cout << dizi NEDEN ADRES YAZAR?
//  Ifadede "dizi" yazildiginda derleyici onu ilk elemanin adresini
//  tutan bir isaretciye (int*) cevirir. Buna array decay denir.
//  cout int* gorunce degeri degil adresi yazar.
//  Elemanlari gormek icin dongu ile tek tek yazdirmak gerekir.
//
//  C# ILE FARK:
//  C#'ta int[] heap'te duran, uzunlugunu bilen ve sinir kontrolu
//  yapan bir nesnedir (IndexOutOfRangeException).
//  C#'ta var arr = new double[] { 21.2, 25.75, 27.01 } benzer mantiktir.
//  C++'ta ham dizi sadece ardisik byte'lardir: uzunluk saklanmaz,
//  sinir kontrolu yoktur.
//
//  TUZAKLAR:
//    - dizi[5] gecersizdir (gecerli indexler 0-4). C++ hata vermez,
//      davranis tanimsizdir (undefined behavior).
//    - Ilk deger verilmemis dizi (int dizi[5];) cop deger tasir.
//    - int x[]; seklinde boyutsuz VE degersiz tanimlama derleme hatasidir.
//      Derleyici boyutu neye gore sayacagini bilemez.
//    - size() C++17 ile geldi. Eski standartta "size was not declared"
//      hatasi verir. Derleyici ayarindan -std=c++17 secilmelidir.
//    - cin >> dizi[1] yanlis tur girilirse (ornek: harf) basarisiz olur
//      ve sonraki okumalar da bozulur. Bu durum ileride ele alinacak.
//
//  PROFESYONEL NOT:
//  Ham dizi temeli anlamak icin onemlidir, ama modern C++ tercihi
//  std::array<int, 5> dir (<array>):
//    - ayni bellek yerlesimi, ek maliyet yok
//    - .size() ile eleman sayisini kendisi bilir
//    - .at(i) ile sinir kontrolu yapar (disina cikilirsa hata firlatir)
//  Boyutu calisma zamaninda degisen veri icin std::vector kullanilir.