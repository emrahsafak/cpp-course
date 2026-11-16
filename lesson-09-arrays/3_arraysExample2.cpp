// =============================================================================
// SECTION 1: CLEAN CODE
// =============================================================================

#include <cstddef>   // std::size_t
#include <iostream>  // std::cin, std::cout

int main()
{
    // constexpr: an array size must be known at compile time
    constexpr std::size_t examCount = 4;

    // = {} zero-initializes every element, so no garbage values
    double examScores[examCount] = {};

    // const: weights must never change; they must sum to 1.0
    const double examWeights[examCount] = { 0.15, 0.15, 0.30, 0.40 };

    // accumulator: must start at 0.0, otherwise we add onto garbage
    double weightedAverage = 0.0;

    // std::size_t: same type as sizeof / size(), no signed/unsigned mismatch
    for (std::size_t i = 0; i < examCount; ++i)
    {
        std::cout << "Enter score " << i + 1 << ": ";
        std::cin >> examScores[i];

        // the same index i pairs each score with its own weight
        weightedAverage += examScores[i] * examWeights[i];
    }

    std::cout << "Weighted average: " << weightedAverage << '\n';

    return 0;
}


// =============================================================================
// SECTION 2: NEW CONCEPTS, LINE BY LINE
// =============================================================================
//
// SATIR: constexpr std::size_t examCount = 4;
//   NE?    : Degeri DERLEME ZAMANINDA bilinen sabit.
//   NEDEN? : Dizi boyutu derleyici tarafindan bilinmek zorunda, cunku derleyici
//            dizinin kac bayt yer kaplayacagini program calismadan hesaplar.
//            constexpr bunu garanti eder. const ise sadece "sonradan degistirme"
//            demektir; degeri calisma zamaninda da gelebilir.
//   TUZAK? :
//            int n = 0;
//            std::cin >> n;
//            double a[n];          // WRONG: standart C++ degil
//            // GCC bunu "VLA" uzantisi olarak sessizce kabul eder, MSVC reddeder.
//            // Dinamik boyut gerekiyorsa std::vector kullanilir (ileride).
//   (std::size_t turu asagida for satirinda aciklanir.)
//
// SATIR: const double examWeights[examCount] = { 0.15, 0.15, 0.30, 0.40 };
//   NE?    : Ilk degerden sonra degistirilemeyen dizi.
//   NEDEN? : Agirliklar bir "yapilandirma" verisidir, program boyunca sabittir.
//            const yazinca yanlislikla degistirme ihtimali derleme hatasina doner;
//            hata calisma zamaninda degil, yazarken yakalanir.
//   TUZAK? :
//            examWeights[0] = 0.5;   // derleme hatasi: read-only location
//
// SATIR: for (std::size_t i = 0; i < examCount; ++i)
//   NE?    : size_t, boyut ve indeks tutmak icin kullanilan ISARETSIZ tamsayi turu.
//   NEDEN? : sizeof ve .size() bu turu dondurur. Sayaci ayni tur yapinca derleyici
//            isaretli/isaretsiz karsilastirma uyarisi vermez. Isaretsiz oldugu icin
//            eksiye inemez; bunun yerine kilometre sayaci gibi BASA SARAR:
//            0 - 1 = 18446744073709551615 (64-bit'te).
//   TUZAK? :
//            // WRONG: i >= 0 her zaman dogru, dongu bitmez (undefined behavior)
//            for (std::size_t i = examCount - 1; i >= 0; --i) { }
//
//            // RIGHT: i > 0 ile say, icerde i - 1 kullan
//            for (std::size_t i = examCount; i > 0; --i) { examScores[i - 1]; }
//            // -Wextra ilk hatali satiri yakalar (-Wtype-limits), uyariyi ciddiye al.
//
// SATIR: std::cout << "Enter score " << i + 1 << ": ";
//   NE?    : std::, standart kutuphanenin isim alani (namespace) on ekidir.
//   NEDEN? : "using namespace std;" tum standart isimleri global alana doker.
//            Bugun bunu yasadik: "const int size = 4;" yazinca std::size
//            GIZLENDI (shadowing); ayni kapsamda artik size(dizi) cagrilamaz.
//            std:: her ismin nereden geldigini acikca gosterir, cakisma olmaz.
//   TUZAK? :
//            using namespace std;
//            const int size = 4;                       // WRONG: std::size'i gizler
//            constexpr std::size_t examCount = 4;      // RIGHT: anlamli isim + std::
//
// SATIR: weightedAverage += examScores[i] * examWeights[i];
//   NE?    : "a += b", "a = a + b" ile ayni; biriktirici (accumulator) kalibi.
//   NEDEN? : Her turda yeni carpim mevcut toplamin ustune eklenir; dongu bitince
//            toplam hazirdir. examScores[i] ile examWeights[i] AYNI index'te
//            durdugu icin ayni sinava aittir (paralel diziler).
//   TUZAK? :
//            double weightedAverage;        // WRONG: cop deger, uzerine ekler
//            double weightedAverage = 0.0;  // RIGHT
//
//
// =============================================================================
// SECTION 3: DEPTH
// =============================================================================
//
// 3.1 AGIRLIKLI ORTALAMA = KUTLE MERKEZI
//   Fizikteki kutle merkezi formulu: x_cm = Sum(m_i * x_i) / Sum(m_i)
//   Burada agirlik = kutle, not = konum. Agirliklarin toplami 1.0 ise payda 1
//   olur ve bolme kaybolur; kodumuz sadece carpip toplar. Bu bir VARSAYIM,
//   ve kod bunu kontrol etmez.
//
//   Ilk yazilan versiyonda agirliklar 0.15+0.15+0.30+0.45 = 1.05 idi. Dort
//   sinavdan 100 alan ogrenci 105 goruyordu. Hata hesapta degil, veride.
//
//     // WRONG: agirliklarin toplaminin 1.0 oldugunu kuru kuruya varsayar
//     weightedAverage += examScores[i] * examWeights[i];
//
//     // RIGHT: gercek agirlik toplamina bol, veri hatasina dayanikli olur
//     weightedAverage = weightedSum / weightSum;
//
// 3.2 BELLEKTE NE VAR?
//   Iki ayri blok: examScores = 4 x 8 = 32 bayt, examWeights = 32 bayt.
//   Adres formulu her ikisinde ayni: baslangic + i * sizeof(double) (8 bayt).
//   Iki dizi arasinda HICBIR baglanti yok; onlari ayni index'le eslestiren
//   tek sey senin disiplinin. Birinin boyutunu degistirip digerini unutursan
//   program hata vermez, yanlis hafiza okur (undefined behavior).
//   Cozum yonu: veriyi birlikte tutan yapi (struct). Ileride.
//
// 3.3 ONCEKI NOTLARDAKI DUZELTMELER
//   a) "size_t, bu sayi bir miktar, yon degil demenin turudur" eksik.
//      Asil sebep ADRES ALANI: size_t, makinedeki herhangi bir nesnenin
//      boyutunu veya dizi indeksini tasiyabilecek kadar genis tur olarak
//      tanimlanir. 32-bit'te 4 bayt (~4,29 milyar), 64-bit'te 8 bayt.
//      32-bit int ~2,1 milyar elemanda tikanir ve her platformda ayni
//      genislikte degildir. Isaretsiz olmasi bunun SONUCU. "Miktar vs yon"
//      sezgisi guzel ama sebep degil; ustelik C++ camiasinda isaretsiz
//      indeks tercihi tartismalidir (bkz. wraparound tuzagi, Section 2).
//   b) "Dizi her turden olabilir; hepsi ayni turden olmak zorundadir" ifadesi
//      celiskili. Dogrusu: bir dizi herhangi bir turde olabilir, ama TEK bir
//      dizinin tum elemanlari AYNI turden olmak zorundadir.
//
// 3.4 C# (UNITY) VE MATLAB PARALELLERI
//   | Konu                | C# (Unity)                          | C++                       |
//   |---------------------|-------------------------------------|---------------------------|
//   | Dizi nesnesi        | double[] heap'te, Length bilir      | ham dizi: sadece bayt     |
//   | Sinir kontrolu      | IndexOutOfRangeException            | yok (undefined behavior)  |
//   | Indeks turu         | int (isaretli)                      | std::size_t (isaretsiz)   |
//   | Salt-okunur dizi    | const dizi yok; readonly referansi  | const dizi gercekten      |
//   |                     | sabitler, ELEMANLAR yine degisir    | salt-okunur               |
//   C#'ta "for (int i = n - 1; i >= 0; i--)" guvenlidir; C++'ta size_t ile
//   ayni kalip sonsuz dongudur. Fark indeks turunden gelir.
//   MATLAB: avg = sum(scores .* weights)  veya  dot(scores, weights)
//   Mantik ayni (Sum(a_i * b_i)), MATLAB 1-tabanli indeks ve vektorlestirilmis,
//   C++ 0-tabanli ve donguyle elle yazilir.
//
//
// =============================================================================
// SECTION 4: QUICK RECAP
// =============================================================================
//
//   - constexpr = derleme zamani sabiti, dizi boyutu icin sart; const = sadece
//     ilk degerden sonra salt-okunur.
//   - std::size_t = boyut/indeks icin isaretsiz tur; 0 - 1 basa sarar, geri
//     sayarken "i > 0" ve "i - 1" kalibini kullan.
//   - Agirlikli ortalama = Sum(not * agirlik); agirliklar 1.0 etmiyorsa
//     gercek agirlik toplamina bol (kutle merkezi mantigi).
//   - using namespace std; yok, her zaman std:: yaz (shadowing tuzagi).
//   - Iki paralel dizi kirilgandir; index eslesmesini sadece disiplin korur.
//   - Biriktirici degisken (accumulator) mutlaka 0.0 ile baslatilir.
//
// SIRADAKI KONU: range-based for ("for (double s : examScores)") ve std::array.
//
// CHALLENGE: Section 3.1'deki saglam formulu kodla. Agirlik toplamini hesapla;
//   1.0'dan 1e-9'dan fazla saparsa uyari yazip programdan cik. "==" yerine
//   neden "fark < epsilon" kullandigini kendin acikla (ipucu: 0.1 + 0.2).
//
// COMPILE: g++ -std=c++17 -Wall -Wextra lesson3_arrays.cpp -o program
