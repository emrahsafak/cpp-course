#include <iostream>
#include <cstddef>   // size_t icin gerekli
#include <iterator>  // size() fonksiyonu icin gerekli (C++17)

using namespace std;

int main()
{
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

    return 0;
}


// -------------------------------------------------------
//  BOLUM 2 — KODUN SATIR SATIR ACIKLAMASI
// -------------------------------------------------------
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
//  BELLEKTE NE DEGISTI?
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
//  cout << dizi NEDEN ADRES YAZAR?
//  Ifadede "dizi" yazildiginda derleyici onu ilk elemanin adresini
//  tutan bir isaretciye (int*) cevirir. Buna array decay denir.
//  cout int* gorunce degeri degil adresi yazar.
//  Elemanlari gormek icin dongu ile tek tek yazdirmak gerekir.
//
//  C# ILE FARK:
//  C#'ta int[] heap'te duran, uzunlugunu bilen ve sinir kontrolu
//  yapan bir nesnedir (IndexOutOfRangeException).
//  C++'ta ham dizi sadece ardisik byte'lardir: uzunluk saklanmaz,
//  sinir kontrolu yoktur.
//
//  TUZAKLAR:
//    - dizi[5] gecersizdir (gecerli indexler 0-4). C++ hata vermez,
//      davranis tanimsizdir (undefined behavior).
//    - Ilk deger verilmemis dizi (int dizi[5];) cop deger tasir.
//      int dizi[5] = {}; yazilirsa hepsi 0 olur.
//    - Dongu sinirinda sabit sayi yerine size(dizi) kullan.
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
