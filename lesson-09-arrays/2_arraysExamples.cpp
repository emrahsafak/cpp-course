#include <iostream>

using namespace std;

/*  PROGRAMLAMA SORUSU - DIZILER

    Asagidaki ozellikleri tasiyan bir C++ programi yaziniz :

    - Kullanicidan 4 adet sinav notu girmesini isteyiniz.
    - Bu 4 notu bir dizi(array) icerisinde tutunuz.
    - Dizideki notlarin ortalamasini hesaplayiniz.
    - Hesapladiginiz ortalamayi ekrana yazdiriniz.
*/

// ---------------- ADIM 1: HOCANIN ILK HALI (UZUN) ----------------
void adim1_uzunHal()
{
    double sinavNotlari[4];

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". sinav notunu girin: ";
        cin >> sinavNotlari[i];
    }

    double toplam = 0;
    for (int i = 0; i < 4; i++) {
        toplam = toplam + sinavNotlari[i];
    }

    double ortalama = toplam / 4;

    cout << "Sinav notlarinin ortalamasi: " << ortalama << endl;
}

// ---------------- ADIM 2: HOCANIN KISALTTIGI HAL (TEK DONGU) ----------------
void adim2_kisaHal()
{
    double sinavNotlari[4];
    double toplam = 0;

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". sinav notunu girin: ";
        cin >> sinavNotlari[i];
        toplam = toplam + sinavNotlari[i];
    }

    double ortalama = toplam / 4;

    cout << "Sinav notlarinin ortalamasi: " << ortalama << endl;
}

// ---------------- ADIM 3: SADELESTIRILMIS VE DUZELTILMIS HAL ----------------
void adim3_sonHal()
{
    const int NOT_SAYISI = 4;
    double sinavNotlari[NOT_SAYISI] = {};
    double toplam = 0;

    for (int i = 0; i < NOT_SAYISI; ++i) {
        cout << i + 1 << ". sinav notunu girin: ";
        cin >> sinavNotlari[i];
        toplam += sinavNotlari[i];
    }

    double ortalama = toplam / NOT_SAYISI;

    cout << "Sinav notlarinin ortalamasi: " << ortalama << endl;
}

int main()
{
    cout << "--- Adim 1: uzun hal ---\n";
    adim1_uzunHal();

    cout << "\n--- Adim 2: kisaltilmis hal ---\n";
    adim2_kisaHal();

    cout << "\n--- Adim 3: sadelestirilmis hal ---\n";
    adim3_sonHal();

    return 0;
}


// -------------------------------------------------------
//  BOLUM 2 — KODUN SATIR SATIR ACIKLAMASI
// -------------------------------------------------------
//
//  ---------- ADIM 1: UZUN HAL ----------
//
//  SATIR: double sinavNotlari[4];
//  RAM'de yan yana 4 tane double kutusu acar. Ilk deger verilmedigi icin
//  kutular simdilik cop deger tasir. Her double 8 bayt oldugu icin
//  toplam bellek: 4 x 8 = 32 bayt.
//  Not "double" secildi cunku notlar ondalikli olabilir (ornek: 72.5).
//
//  SATIR: for (int i = 0; i < 4; i++) { cout ...; cin >> sinavNotlari[i]; }
//  BIRINCI DONGU: sadece notlari alir ve diziye yazar.
//  i = 0, 1, 2, 3 icin dongu 4 kez doner (i < 4: gecerli indexler 0-3).
//  i + 1 : index 0'dan basladigi icin insan okumasi icin 1 eklenir.
//  cin >> sinavNotlari[i] : klavyeden okunan sayiyi i. kutuya yazar.
//
//  SATIR: double toplam = 0;
//  Notlari biriktirecegimiz degisken. 0 ile baslatilmasi ZORUNLUDUR.
//  Baslatilmazsa icinde cop deger olur ve toplam yanlis cikar.
//
//  SATIR: for (int i = 0; i < 4; i++) { toplam = toplam + sinavNotlari[i]; }
//  IKINCI DONGU: dizi artik dolu, kutulari tek tek gezip toplar.
//  Buradaki "int i" birincideki "i" ile ILGILI DEGILDIR. Her for'un i'si
//  sadece kendi dongusunun icinde yasar (kapsam / scope).
//
//  SATIR: double ortalama = toplam / 4;
//  Toplam, not sayisina bolunur. toplam double oldugu icin bolme
//  ondalikli yapilir. Ornek: 340 / 4 = 85.
//
//  ---------- ADIM 2: KISALTILMIS HAL ----------
//
//  FARK: Iki dongu TEK donguya birlestirildi.
//  "toplam = 0" dongunun ustune cekildi, toplama satiri ilk donguye girdi:
//    cin >> sinavNotlari[i];
//    toplam = toplam + sinavNotlari[i];
//  Her turda not hem diziye yazilir hem toplama eklenir:
//    Tur 1: toplam = 0    + not1
//    Tur 2: toplam = not1 + not2
//    Tur 3: toplam = not1 + not2 + not3
//    Tur 4: toplam = not1 + not2 + not3 + not4
//  Sonuc ayni, ama dizi tek seferde gezilir ve 5 satir kod azalir.
//
//  ---------- ADIM 3: SADELESTIRILMIS VE DUZELTILMIS HAL ----------
//
//  SATIR: const int NOT_SAYISI = 4;
//  const : degeri sonradan degistirilemeyen sabit. 4 sayisi artik TEK
//  yerde yazili. Kodda 4 yerine bu isim kullanilir.
//
//  SATIR: double sinavNotlari[NOT_SAYISI] = {};
//  Boyut olarak const degisken kullanilabilir (derleme zamaninda bilinir).
//  = {} tum kutulari 0 yapar, boylece cop deger riski kalkar.
//
//  SATIR: for (int i = 0; i < NOT_SAYISI; ++i)
//  Dongu siniri artik NOT_SAYISI. i++ yerine ++i kullanildi (tam sayida
//  sonuc ayni, ++i profesyonel kodda tercih edilen aliskanlik).
//
//  SATIR: toplam += sinavNotlari[i];
//  "toplam = toplam + ..." ifadesinin kisa yazimi. Anlami birebir aynidir.
//
//  SATIR: double ortalama = toplam / NOT_SAYISI;
//  Bolen artik sabit sayi degil, isimli sabit. Not sayisi degisirse
//  bu satira dokunmak gerekmez. NOT_SAYISI int'tir ama toplam double
//  oldugu icin bolme ondalikli yapilir.
//
//  ORNEK CIKTI (ornek girdilerle: 70, 80, 90, 100; uc adimda da ayni):
//    1. sinav notunu girin: 70
//    2. sinav notunu girin: 80
//    3. sinav notunu girin: 90
//    4. sinav notunu girin: 100
//    Sinav notlarinin ortalamasi: 85
//
//  BELLEKTE NE OLDU? (ornek girdilerle)
//    index            deger
//    sinavNotlari[0]  70
//    sinavNotlari[1]  80
//    sinavNotlari[2]  90
//    sinavNotlari[3]  100
//    toplam           340
//    ortalama         85


// -------------------------------------------------------
//  BOLUM 3 — GENEL KONU: REFACTORING (KODU GELISTIRME ADIMLARI)
// -------------------------------------------------------
//
//  REFACTORING NEDIR?
//  Programin ISLEVINI DEGISTIRMEDEN kodun yapisini iyilestirmektir.
//  Uc adimda da program ayni sonucu verir (ortalama 85).
//  Degisen sey: kodun okunabilirligi, uzunlugu ve bakimi.
//
//  ADIM 1 -> ADIM 2: IKI DONGUYU BIRLESTIRME
//  Once "veriyi al", sonra "topla" diye ayrildi. Mantikli bir ilk
//  taslak, cunku her is ayri dusunulur. Sonra fark edilir ki iki dongu
//  de ayni kutulari ayni sirayla geziyor. Tek dongu ayni isi yapar.
//  Kazanc: daha az kod, dizi tek kez gezilir.
//  Dikkat: iki isi tek donguya koymak HER ZAMAN dogru degildir.
//  Ornegin ortalama tum notlar girildikten SONRA hesaplanmalidir;
//  onu dongunun icine koyarsan sonuc yanlis olur.
//
//  ADIM 2 -> ADIM 3: SIHIRLI SAYIYI KALDIRMA
//  Adim 2'de 4 sayisi UC yerde elle yazili:
//    double sinavNotlari[4];
//    i < 4
//    toplam / 4
//  Not sayisini 5 yapmak istersen uc yeri de degistirmen gerekir.
//  Birini unutursan program SESSIZCE yanlis calisir (hata vermez).
//  Adim 3'te tek satir degisir: const int NOT_SAYISI = 5;
//  Elle yazilan, anlami belli olmayan sabit sayilara "sihirli sayi"
//  (magic number) denir ve profesyonel kodda kacinilir.
//
//  TOPLAM VE ORTALAMA TURU: double NEDEN ONEMLI?
//  Eger toplam "int" olsaydi:
//    int toplam = 342;
//    double ortalama = toplam / 4;   // 342 / 4 = 85 (ondalik KAYBOLUR)
//  Cunku iki tam sayinin bolumu tam sayi sonuc verir.
//  Ondalik istiyorsan en az bir tarafin double olmasi gerekir:
//    double ortalama = toplam / 4.0;   // 85.5
//
//  BU ORNEKTEKI KALIP (en cok kullanilan dizi kalibi):
//    1) Diziyi tanimla
//    2) Toplam icin 0 ile baslayan bir degisken ac
//    3) Dongu ile her kutuya git: oku, yaz, biriktir
//    4) Dongu bittikten sonra sonucu hesapla
//  Ayni kalip toplam, ortalama, en buyuk, en kucuk bulmada kullanilir.
//
//  TUZAKLAR:
//    - toplam = 0 yazmayi unutursan sonuc cop deger olur.
//    - Dongu sinirini i <= 4 yazarsan sinavNotlari[4]'e yazilir.
//      Bu gecersizdir (indexler 0-3), tanimsiz davranisa yol acar.
//    - cin >> ile harf girilirse okuma basarisiz olur ve sonraki
//      okumalar da bozulur. Girdi dogrulamasi ileride ele alinacak.
//    - const olmayan bir degisken dizi boyutu olarak kullanilamaz
//      (standart C++'ta boyut derleme zamaninda bilinmelidir).
//
//  PROFESYONEL NOT:
//  Adim 3 bile ileride daha da sadelesir. <numeric> icindeki
//  accumulate() toplama dongusunu tek satira indirir, std::array
//  ise boyutu kendisi bilir. Bunlari dizi konusu oturdugunda goreceksin.
//
//  C# ILE FARK:
//    C#'ta  double[] notlar = new double[4];  ve  notlar.Average()
//    gibi hazir fonksiyonlar vardir. C++'ta ham dizide bunlar yoktur,
//    toplami kendin biriktirirsin.