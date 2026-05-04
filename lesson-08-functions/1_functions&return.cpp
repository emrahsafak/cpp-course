#include <iostream>
using namespace std;

int hesapla(int x) {
    int sonuc;
    sonuc = 3 * x + 2;
    return sonuc;
}

int alanHesapla(int x, int y) {
    int alan = x * y;
    return alan;
}

void kareAlanHesaplaGoster(int kenar) {
    cout << "Karenizin alani: " << (kenar * kenar) << endl;
}

int main()
{
    // C++ Fonksiyonlar - C++ Metodlar
    // f(x) = 3x + 2

    //cout << "sonuc: " << hesapla(3) << endl;
    //cout << alanHesapla(5, 10) << endl;
    kareAlanHesaplaGoster(5);
    kareAlanHesaplaGoster(7);
    kareAlanHesaplaGoster(10);

    cout << "Hoscakalin..\n";
    return 0;
}


// =============================================================================
//  PROGRAM ÇIKTISI:
//
//  Karenizin alani: 25
//  Karenizin alani: 49
//  Karenizin alani: 100
//  Hoscakalin..
// =============================================================================




// ─────────────────────────────────────────────────────────────────────────────
// [BÖLÜM 2] KODUN SATIR SATIR AÇIKLAMASI
// ─────────────────────────────────────────────────────────────────────────────


// ── #include <iostream> ──────────────────────────────────────────────────────
//
//  #include → "bu kütüphaneyi projeye ekle" komutudur.
//  <iostream> → "input output stream" yani giriş-çıkış akışı demektir.
//  cout ve cin gibi komutların tanımlandığı kütüphanedir.
//  Bu satır olmadan cout kullanmaya çalışırsan derleme hatası alırsın.


// ── using namespace std; ─────────────────────────────────────────────────────
//
//  "std" bir isim alanıdır (namespace). Kütüphanelerin klasörü gibi düşün.
//  Bu satır olmasaydı her seferinde std::cout yazmamız gerekirdi.
//  "using namespace std" yazarak bu klasörü varsayılan açık bırakıyoruz.


// ── int hesapla(int x) ───────────────────────────────────────────────────────
//
//  Fonksiyon imzası 3 parçadan oluşur:
//    [1] int      → Bu fonksiyon bize bir tamsayı GERİ DÖNDÜRECEK.
//    [2] hesapla  → Fonksiyonun adı.
//    [3] (int x)  → Dışarıdan bir tamsayı parametre alıyoruz, adı "x".
//
//  int sonuc;
//    → Fonksiyon içinde lokal bir değişken tanımladık.
//    → "Lokal" demek: bu değişken sadece bu fonksiyon içinde var olur.
//    → Fonksiyon sona erdiğinde RAM'den otomatik silinir.
//
//  sonuc = 3 * x + 2;
//    → Dışarıdan gelen x değerini formüle sokuyoruz.
//    → Örnek: x = 3 girilirse → 3*3 + 2 = 11 → sonuc = 11
//
//  return sonuc;
//    → Hesaplanan değeri fonksiyonu ÇAĞIRAN YERE gönder.
//    → main() içinde hesapla(3) yazarsak, o ifade 11 değerine dönüşür.
//    → return satırına ulaşılınca fonksiyon anında sona erer.


// ── int alanHesapla(int x, int y) ───────────────────────────────────────────
//
//  Bu sefer iki parametre alıyoruz: x ve y.
//  Parametreler virgülle ayrılır, her birinin tipi ayrı ayrı yazılır.
//
//  YANLIŞ → (int x, y)      : y'nin tipi belirsiz, derleme hatası!
//  DOĞRU  → (int x, int y)  : Her biri açıkça tanımlı.
//
//  int alan = x * y;
//    → Tanımlama ve atamayı tek satırda yaptık.
//    → Önceki fonksiyondaki iki ayrı satırla tamamen aynı sonucu verir.
//    → Daha temiz ve modern C++ yazım pratiğidir.
//
//  return alan;
//    → Örnek: alanHesapla(5, 10) → 5*10 = 50 → return 50


// ── void kareAlanHesaplaGoster(int kenar) ───────────────────────────────────
//
//  "void" → bu fonksiyon HİÇBİR ŞEY DÖNDÜRMEZ.
//  Hesapladığı sonucu çağıran yere göndermez, kendi içinde ekrana basar.
//  C# Unity'deki Start() ve Update() metodları da void'di — aynı mantık.
//
//  cout << "Karenizin alani: " << (kenar * kenar) << endl;
//    → cout              : konsola yaz (C#'taki Console.Write() karşılığı)
//    → <<                : akış operatörü, sağındaki veriyi konsola akıt
//    → "Karenizin alani" : ekrana sabit metin yaz
//    → (kenar * kenar)   : parantez içinde hesapla, sonucu akıt
//    → endl              : satır sonu + çıkış tamponunu temizle
//
//  Bu fonksiyonda return yok — void fonksiyonlarda return zorunlu değildir.
//  Gövde sona erince fonksiyon otomatik biter.


// ── int main() ───────────────────────────────────────────────────────────────
//
//  Her C++ programı main() fonksiyonundan başlar.
//  İşletim sistemi programı çalıştırdığında ilk buraya gelir.
//  Dönüş tipi int'tir: 0 = başarılı, 0 dışı = hata kodu.
//
//  //cout << "sonuc: " << hesapla(3) << endl;
//  //cout << alanHesapla(5, 10) << endl;
//    → Bu iki satır yorum satırı (kapalı), program onları atlar.
//    → Açık olsaydı: hesapla(3) → 11, alanHesapla(5,10) → 50 ekrana yazardı.
//    → Bu fonksiyonlar int döndürdüğü için cout içinde doğrudan kullanılabilir.
//
//  kareAlanHesaplaGoster(5);
//  kareAlanHesaplaGoster(7);
//  kareAlanHesaplaGoster(10);
//    → Aynı fonksiyon 3 farklı argümanla 3 kez çağrıldı.
//    → kenar=5  → 5*5   = 25  → ekrana: "Karenizin alani: 25"
//    → kenar=7  → 7*7   = 49  → ekrana: "Karenizin alani: 49"
//    → kenar=10 → 10*10 = 100 → ekrana: "Karenizin alani: 100"
//    → void döndürdüğü için sol tarafta değişken KULLANILMAZ.
//
//  cout << "Hoscakalin..\n";
//    → \n sadece satır sonu ekler.
//    → endl'den farkı: çıkış tamponunu temizlemez, bu yüzden daha hızlıdır.
//
//  return 0;
//    → main()'den 0 döndürmek = "program hatasız tamamlandı."
//    → İşletim sistemi bu değeri okur.




// ─────────────────────────────────────────────────────────────────────────────
// [BÖLÜM 3] FONKSİYONLAR — GENEL KAVRAM VE KULLANIM REHBERİ
// ─────────────────────────────────────────────────────────────────────────────


// ── FONKSİYON NEDİR? ─────────────────────────────────────────────────────────
//
//  Fonksiyon → belirli bir görevi yerine getiren, isim verilmiş kod bloğudur.
//  Bir kez yazılır, istenen her yerden istenen sayıda çağrılabilir.
//
//  Fizik Analojisi:
//    Tıpkı f(x) = 3x + 2 gibi → girdi ver, çıktı al.
//    Fonksiyonun içinde ne olduğu çağıran yeri ilgilendirmez.
//    Buna "soyutlama (abstraction)" denir.
//
//  C# / Unity Karşılaştırması:
//    C#'ta "metod (method)" denen şeyin C++'taki adı fonksiyondur.
//    C#'ta tüm metodlar bir sınıf içinde olmak zorundaydı.
//    C++'ta fonksiyonlar sınıf olmadan global olarak var olabilir.


// ── FONKSİYON YAPISI (SYNTAX) ────────────────────────────────────────────────
//
//  dönüş_tipi  fonksiyon_adı ( parametre_listesi )
//  {
//      // gövde
//      return değer;    ←  void ise bu satır olmayabilir
//  }


// ── 3 TEMEL FONKSİYON TÜRÜ ───────────────────────────────────────────────────
//
//  [1] Değer Döndüren
//      int hesapla(int x) { return 3 * x + 2; }
//      → Sonucu değişkene ata:   int s = hesapla(5);
//      → Ya da doğrudan kullan:  cout << hesapla(5);
//
//  [2] Çok Parametreli
//      int alanHesapla(int x, int y) { return x * y; }
//      → Her parametrenin tipi ayrı yazılır.
//      → Çağırırken sıra önemlidir: alanHesapla(5, 10) ≠ alanHesapla(10, 5)
//
//  [3] void — Değer Döndürmeyen
//      void yazdir(int n) { cout << n; }
//      → Sonuç gerekmez, fonksiyon kendi içinde işini bitirir.
//      → Hatalı kullanım: int x = yazdir(5);  ← DERLEME HATASI


// ── TEMEL KAVRAMLAR SÖZLÜĞÜ ──────────────────────────────────────────────────
//
//  Tanımlama  (Definition)  : Fonksiyonun gövdesini yazmak.
//  Çağırma    (Call/Invoke) : Fonksiyonu kullanmak.
//  Parametre  (Parameter)   : Tanımdaki değişken adları.      → (int x, int y)
//  Argüman    (Argument)    : Çağırırken verilen gerçek değer. → (5, 10)
//  Dönüş Tipi              : int, double, bool, void, string ...
//  Lokal Değişken          : Fonksiyon içinde yaşar, dışarıdan erişilemez.


// ── NEDEN FONKSİYON KULLANIRIZ? ──────────────────────────────────────────────
//
//  [1] DRY — Don't Repeat Yourself
//      Aynı kodu defalarca yazmak yerine bir kez tanımla, istediğin kadar çağır.
//
//  [2] Okunabilirlik
//      kareAlanHesaplaGoster(5) → ne yaptığını okuyunca anlıyorsun.
//      50 satır kodu main() içine gömmek yerine anlamlı fonksiyonlar kullan.
//
//  [3] Test Edilebilirlik
//      Her fonksiyon ayrı ayrı test edilebilir.
//      Hata varsa direkt o fonksiyona bakarsın, tüm kodu karıştırmazsın.
//
//  [4] Bakım Kolaylığı
//      Formül değişecekse sadece fonksiyon gövdesini güncelle.
//      Geri kalan her şey otomatik olarak doğrulanır.


// ── PRO İPUCU — FONKSİYON PROTOTYPE ─────────────────────────────────────────
//
//  Bu derste fonksiyonları main()'den ÖNCE yazdık.
//  Peki sonra yazmak istesek? Derleyici üstten aşağı okur —
//  tanımlamadan önce kullanırsan "identifier not found" hatası alırsın!
//
//  Çözüm → Prototype (öne bildirim):
//
//    int topla(int a, int b);       ← sadece imzayı bildir, gövde yok
//
//    int main() {
//        cout << topla(3, 5);       ← artık main() önce gelebilir
//    }
//
//    int topla(int a, int b) {      ← asıl tanımlama burada
//        return a + b;
//    }
//
//  Bunu ilerleyen derslerde göreceksin — şimdilik bilmen yeterli.

// ─────────────────────────────────────────────────────────────────────────────
