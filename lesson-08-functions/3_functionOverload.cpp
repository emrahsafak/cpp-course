// ============================================================================
//  function_overloading.cpp
//  Konu   : C++ Function Overloading (Fonksiyon Aşırı Yükleme) - Derinlemesine
//  Standart: C++17   |   Derleme: g++ -std=c++17 -Wall -Wextra function_overloading.cpp -o demo
// ============================================================================
//
//  BÜYÜK RESİM (önce harita, sonra detay):
//  ----------------------------------------
//  Overloading = AYNI SCOPE içinde, AYNI İSİMLİ ama FARKLI "imzalı" fonksiyonlar.
//
//  İMZA (signature) şunlardan oluşur:
//     - fonksiyon adı
//     - parametre tiplerinin sırası ve sayısı
//     - (üye fonksiyonlarda) const / volatile / ref-qualifier (&, &&)
//  İMZAYA DAHİL OLMAYANLAR:
//     - DÖNÜŞ TİPİ  (!!)  -> sadece dönüş tipi farklı olan iki fonksiyon tanımlanamaz.
//     - parametre isimleri
//
//  NASIL ÇALIŞIR? -> Overload resolution BELİRLİ ZAMANDA (compile-time) yapılır.
//  Runtime'da "hangisini çağırayım?" diye bir arama YOKTUR. Derleyici her fonksiyonu
//  "name mangling" ile benzersiz bir sembole çevirir; örn. GCC'de:
//        int add(int,int)       ->  _Z3addii
//        double add(double,double) -> _Z3adddd
//  Linker için bunlar tamamen farklı isimlerdir. (C'de overloading olmamasının sebebi
//  budur: C sembolleri mangle etmez.)
//
//  ANALOJİLER:
//   * C#/Unity : Debug.Log(object) / Debug.Log(object, Object context) overload'ları.
//                C# ile C++ mantığı aynı; fark: C++'ta implicit dönüşüm kuralları
//                çok daha geniş ve tuzaklı (aşağıda göreceğiz).
//   * MATLAB   : MATLAB'da overloading yok; tek fonksiyon içinde nargin / isa ile
//                elle dallanırsınız (runtime). C++ bu dallanmayı derleme zamanına taşır
//                -> SIFIR runtime maliyeti.
//
//  OVERLOAD RESOLUTION SIRALAMASI (iyiden kötüye):
//     1) Exact match        (tam eşleşme, const ekleme gibi önemsiz dönüşümler dahil)
//     2) Promotion          (char/short -> int, float -> double)
//     3) Standard conversion(int -> double, int -> long, pointer -> bool ...)
//     4) User-defined conv. (converting constructor / operator T)
//     5) Ellipsis (...)     (C tarzı variadic - en kötü)
//  Aynı seviyede iki aday eşit iyiyse -> AMBIGUOUS (belirsiz) -> DERLEME HATASI.
// ============================================================================

#include <cstddef>      // std::size_t
#include <iostream>     // std::cout
#include <string>       // std::string
#include <utility>      // std::move
#include <vector>       // std::vector

// ============================================================================
// BÖLÜM 1: Temel overloading - parametre sayısı ve tipi
// ============================================================================
namespace part1 {

// (1) İki int toplar. Her overload'ın içine kimliğini yazdırıyoruz ki
//     "hangisi seçildi?" sorusunu çıktıdan GÖREBİLELİM.
int add(int a, int b) {
    std::cout << "  add(int, int)           -> ";
    return a + b;               // int + int = int
}

// (2) Tip farklı -> imza farklı -> geçerli overload.
double add(double a, double b) {
    std::cout << "  add(double, double)     -> ";
    return a + b;
}

// (3) Parametre SAYISI farklı -> imza farklı.
int add(int a, int b, int c) {
    std::cout << "  add(int, int, int)      -> ";
    return a + b + c;
}

// (4) Sınıf tipi parametre. const& : kopyalamayı önler (performans) ve
//     geçici nesneleri (rvalue) de kabul eder.
std::string add(const std::string& a, const std::string& b) {
    std::cout << "  add(string, string)     -> ";
    return a + b;               // string birleştirme
}

// !!! DERLENMEZ: sadece dönüş tipi farklı !!!
// double add(int a, int b);   // HATA: "ambiguating new declaration"
// Neden? Çağrı noktasında add(1, 2) yazdığınızda dönüş tipi henüz "kullanılmamıştır";
// derleyici argümanlara bakarak karar verir, dönüş tipine bakarak değil.

void run() {
    std::cout << "\n=== BOLUM 1: Temel overloading ===\n";
    std::cout << add(2, 3) << '\n';                 // iki int       -> add(int,int)
    std::cout << add(2.5, 3.5) << '\n';             // iki double    -> add(double,double)
    std::cout << add(1, 2, 3) << '\n';              // üç argüman    -> add(int,int,int)
    std::cout << add(std::string("Game"), std::string("Dev")) << '\n';

    // Fonksiyon pointer'ı alırken overload set belirsizdir.
    // Hangisini istediğinizi tip ile söylemelisiniz:
    int (*fp)(int, int) = add;                       // hedef tipten seçim yapılır
    auto fp2 = static_cast<double (*)(double, double)>(add);  // cast ile seçim
    std::cout << fp(10, 20) << '\n';
    std::cout << fp2(0.5, 0.25) << '\n';
    // C# analojisi: method group -> delegate dönüşümünde de hedef delegate tipi seçimi belirler.
}

} // namespace part1

// ============================================================================
// BÖLÜM 2: Overload resolution sıralaması - Exact / Promotion / Conversion
// ============================================================================
namespace part2 {

void print(int v)                { std::cout << "  print(int)    : " << v << '\n'; }
void print(long v)               { std::cout << "  print(long)   : " << v << '\n'; }
void print(double v)             { std::cout << "  print(double) : " << v << '\n'; }
void print(const std::string& s) { std::cout << "  print(string) : " << s << '\n'; }

void run() {
    std::cout << "\n=== BOLUM 2: Resolution sirasi ===\n";

    print(42);                  // int literal: EXACT MATCH -> print(int)
    print(5L);                  // long literal: EXACT MATCH -> print(long)
    print(3.14);                // double literal: EXACT -> print(double)

    print('A');                 // char -> int bir PROMOTION'dır (integral promotion).
                                // print(int) seçilir ve 65 yazar (char'ın sayısal değeri).
                                // Çıktı "A" bekleyen biri için klasik sürpriz!

    print(3.14f);               // float -> double PROMOTION -> print(double)
                                // (float->int bir CONVERSION olurdu; promotion kazanır.)

    print(std::string("hi"));   // exact -> print(const string&)

    // !!! AMBIGUOUS (derlenmez) - kasıtlı olarak yorumda bırakıldı !!!
    // print(5u);               // unsigned int -> int, long, double: HEPSİ "conversion".
                                // Eşit seviyede 3 aday -> belirsiz -> hata.
                                // Çözüm: açık cast  print(static_cast<int>(5u));
                                //        veya print(unsigned) overload'ı eklemek.
}

} // namespace part2

// ============================================================================
// BÖLÜM 3: Klasik tuzak - string literal ve bool
// ============================================================================
namespace part3 {

namespace bad {
    void log(bool b)               { std::cout << "  log(bool)   : " << std::boolalpha << b << '\n'; }
    void log(const std::string& s) { std::cout << "  log(string) : " << s << '\n'; }
}

namespace good {
    void log(bool b)               { std::cout << "  log(bool)   : " << std::boolalpha << b << '\n'; }
    void log(const std::string& s) { std::cout << "  log(string) : " << s << '\n'; }
    // Çözüm: const char* için DOĞRUDAN overload. Exact match kazanır.
    void log(const char* s)        { log(std::string(s)); }   // string overload'a yönlendir
}

void run() {
    std::cout << "\n=== BOLUM 3: \"literal\" -> bool tuzagi ===\n";

    // "hello" tipi const char[6]'dır. Array-to-pointer ile const char* olur.
    //   const char* -> bool  : STANDARD conversion (boolean conversion)
    //   const char* -> string: USER-DEFINED conversion (string'in constructor'ı)
    // Sıralamada standard > user-defined olduğundan BOOL KAZANIR.
    std::cout << "bad:\n";
    bad::log("hello");           // log(bool) çalışır!  (pointer null değil -> true)

    std::cout << "good:\n";
    good::log("hello");          // const char* overload -> doğru davranış

    // Ders: "Aynı ismi farklı tiplerde aşırı yüklüyorsam, implicit dönüşümlerin
    // beklemediğim bir adayı kazandırıp kazandırmadığını" düşünmek zorundayım.
    // (std::string_view parametresi de çözüm olabilir, ama bool yine de kazanır
    //  çünkü string_view'e dönüşüm de user-defined'dır.)
}

} // namespace part3

// ============================================================================
// BÖLÜM 4: Referans kategorileri - const&, &&  (copy vs move overload)
// ============================================================================
namespace part4 {

// lvalue (isimli, adresi alınabilen) nesneler için: KOPYALA
void take(const std::string& s) {
    std::cout << "  take(const string&) : kopyalanir, orijinal korunur: \"" << s << "\"\n";
}

// rvalue (geçici / std::move edilmiş) nesneler için: ÇAL (move)
void take(std::string&& s) {
    // DİKKAT: isimli bir && parametresi, gövde içinde LVALUE gibi davranır.
    std::string stolen = std::move(s);      // kaynağı "boşalt" ve sahipliği al
    std::cout << "  take(string&&)      : tasindi (move): \"" << stolen << "\"\n";
}

void run() {
    std::cout << "\n=== BOLUM 4: const& vs && overload ===\n";
    std::string name = "Player_One";

    take(name);                          // lvalue -> const& overload
    take(std::string("Temp_Enemy"));     // geçici (rvalue) -> && overload
    take(std::move(name));               // std::move: lvalue'yu rvalue'ya CAST eder -> && overload
    // Bu noktadan sonra 'name' "geçerli ama belirsiz" durumdadır; kullanmayın.
    // Unity analojisi: Object pooling. Kopyalamak = Instantiate, move = havuzdan
    // nesneyi devretmek; kaynağı yeniden yaratmaya gerek kalmaz.
}

} // namespace part4

// ============================================================================
// BÖLÜM 5: Üye fonksiyonlarda const overloading
// ============================================================================
namespace part5 {

class Buffer {
public:
    explicit Buffer(std::size_t n) : data_(n, 0) {}     // n elemanlı, hepsi 0

    // const OLMAYAN nesne için: değiştirilebilir referans döner.
    int& at(std::size_t i) {
        std::cout << "  at() [non-const]\n";
        return data_[i];
    }

    // const nesne için: salt-okunur referans döner.
    // Sondaki 'const' -> gizli 'this' parametresini 'const Buffer*' yapar.
    // Yani 'this' tipi imzanın PARÇASIDIR -> geçerli overload.
    const int& at(std::size_t i) const {
        std::cout << "  at() [const]\n";
        return data_[i];
    }

private:
    std::vector<int> data_;
};

void readOnly(const Buffer& b) {        // const referans -> sadece const üyeler çağrılabilir
    std::cout << "  deger: " << b.at(0) << '\n';
}

void run() {
    std::cout << "\n=== BOLUM 5: const uye fonksiyon overload ===\n";
    Buffer buf(4);
    buf.at(0) = 99;                     // non-const nesne -> non-const at() -> YAZABİLİRİZ
    readOnly(buf);                      // const& içinden -> const at() -> sadece OKUR
    // Bu desen std::vector::operator[] ve std::map'in birçok API'sinde aynen vardır.
    // C#'ta "readonly/ReadOnlyCollection" ile tasarımla yaptığınız şeyi
    // C++ derleyiciye TİP SİSTEMİ ile garanti ettirir.
}

} // namespace part5

// ============================================================================
// BÖLÜM 6: Pointer overload ve nullptr
// ============================================================================
namespace part6 {

void g(int x)   { std::cout << "  g(int)   : " << x << '\n'; }
void g(char* p) { std::cout << "  g(char*) : " << (p ? "dolu" : "null") << '\n'; }

void run() {
    std::cout << "\n=== BOLUM 6: nullptr ===\n";
    g(0);                // 0 bir int literal -> g(int)  (null pointer sabiti de olabilir ama int exact)
    g(nullptr);          // nullptr_t -> pointer'a dönüşür -> g(char*)
    // Eski stil NULL makrosu 0 veya 0L olarak tanımlıdır; g(NULL) ya g(int)'i seçer
    // ya da belirsiz olur (derleyiciye bağlı). KURAL: modern C++'ta DAİMA nullptr.
}

} // namespace part6

// ============================================================================
// BÖLÜM 7: Template vs non-template overload
// ============================================================================
namespace part7 {

template <typename T>
void show(T v) { std::cout << "  show<T>(T)   [template] : " << v << '\n'; }

void show(int v) { std::cout << "  show(int)    [normal]   : " << v << '\n'; }

void run() {
    std::cout << "\n=== BOLUM 7: Template ile overload ===\n";
    show(5);        // İkisi de exact match -> eşitlikte NON-TEMPLATE kazanır.
    show(5.0);      // Normal show(int)'e dönüşüm gerekir (conversion); template exact -> TEMPLATE kazanır.
    show('a');      // Template T=char EXACT; normal show(int) için promotion gerekir.
                    // Exact > promotion -> TEMPLATE kazanır. (Sürpriz: 'a' yazdırır, 97 değil.)
    // Kural: önce dönüşüm seviyesi, eşitse non-template tercih edilir.
}

} // namespace part7

// ============================================================================
// BÖLÜM 8: = delete ile istenmeyen overload'ları yasaklamak
// ============================================================================
namespace part8 {

void setHealth(int hp) { std::cout << "  setHealth(int): " << hp << '\n'; }

// Yasaklanan overload: double argüman sessizce int'e kırpılmasın.
// Overload resolution, silinmiş fonksiyonu da ADAY olarak değerlendirir;
// seçilirse DERLEME HATASI verir. Bu sayede "sessiz veri kaybı" engellenir.
void setHealth(double) = delete;

void run() {
    std::cout << "\n=== BOLUM 8: = delete ===\n";
    setHealth(100);
    // setHealth(99.9);   // HATA: use of deleted function -> güvenlik ağı
    // MATLAB'da 99.9'un sessizce işlendiği yerde C++ sizi derleme anında durdurur.
}

} // namespace part8

// ============================================================================
// BÖLÜM 9: Default argument ile overload çakışması
// ============================================================================
namespace part9 {

void spawn(int id)               { std::cout << "  spawn(id)         : " << id << '\n'; }
void spawn(int id, float scale)  { std::cout << "  spawn(id, scale)  : " << id << ", " << scale << '\n'; }

// Aşağıdaki kombinasyon TUZAKTIR:
//    void spawn(int id, float scale = 1.0f);   // default arg
//    void spawn(int id);                       // spawn(5) -> İKİSİ DE uyar -> AMBIGUOUS
// Kural: Ya default argument kullanın ya overload; aynı çağrıyı çifte karşılamayın.

void run() {
    std::cout << "\n=== BOLUM 9: Overload vs default arg ===\n";
    spawn(7);
    spawn(7, 2.5f);
    // Genel tavsiye: Davranış AYNI ve sadece "opsiyonel parametre" varsa default arg;
    // davranış/algoritma FARKLIYSA overload kullanın.
}

} // namespace part9

// ============================================================================
// BÖLÜM 10: Pratik örnek - Vec2, constructor ve operator overloading
// ============================================================================
namespace part10 {

struct Vec2 {
    float x{0.0f};
    float y{0.0f};

    Vec2() = default;                                   // (a) Varsayılan: (0,0)
    explicit Vec2(float s) : x(s), y(s) {}              // (b) Tek değer: (s,s). explicit: Vec2 v = 3.0f; engellenir
    Vec2(float x_, float y_) : x(x_), y(y_) {}          // (c) İki değer

    // operator overloading = overloading'in özel bir hali; imza kuralları aynı.
    Vec2 operator+(const Vec2& rhs) const {             // Vec2 + Vec2
        return Vec2{x + rhs.x, y + rhs.y};
    }
    Vec2 operator*(float k) const {                     // Vec2 * float
        return Vec2{x * k, y * k};
    }
};

// Vec2 * float üye fonksiyonla çözüldü. float * Vec2 için ÜYE olamaz (sol operand float);
// bu yüzden global (free) overload yazılır.
inline Vec2 operator*(float k, const Vec2& v) { return v * k; }

// Çıktı operatörü: std::ostream& döndürmek zincirlemeyi (cout << a << b) mümkün kılar.
inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    return os << "(" << v.x << ", " << v.y << ")";
}

void run() {
    std::cout << "\n=== BOLUM 10: Vec2 (ctor + operator overload) ===\n";
    Vec2 a;                         // (0, 0)
    Vec2 b{3.0f};                   // explicit ctor (b): (3, 3)
    Vec2 c{1.0f, 2.0f};             // ctor (c): (1, 2)

    std::cout << "a = " << a << ", b = " << b << ", c = " << c << '\n';
    std::cout << "b + c   = " << (b + c) << '\n';
    std::cout << "c * 2   = " << (c * 2.0f) << '\n';
    std::cout << "2 * c   = " << (2.0f * c) << '\n';
    // Unity analojisi: Vector2'nin operator +, * overload'ları birebir aynı fikirdir.
    // Fark: C++'ta operatör bir üye ya da global fonksiyon olabilir; C#'ta static olmalıdır.
}

} // namespace part10

// ============================================================================
// main: tüm bölümleri sırayla çalıştırır
// ============================================================================
int main() {
    part1::run();
    part2::run();
    part3::run();
    part4::run();
    part5::run();
    part6::run();
    part7::run();
    part8::run();
    part9::run();
    part10::run();
    return 0;      // 0 = başarı kodu (işletim sistemine bildirilir)
}

// ============================================================================
// ÖZET - ALTIN KURALLAR
//  1) Overload = isim aynı, imza farklı; dönüş tipi imzaya dahil DEĞİLDİR.
//  2) Karar COMPILE-TIME'da verilir; runtime maliyeti sıfırdır (name mangling).
//  3) Sıralama: exact > promotion > standard conversion > user-defined > ellipsis.
//  4) Eşit seviyede iki aday -> ambiguous -> derleme hatası (sessiz yanlışlıktan iyidir).
//  5) "literal" -> bool tuzağı: const char* overload ekleyin veya tasarımı sadeleştirin.
//  6) Null pointer için nullptr kullanın, NULL/0 kullanmayın.
//  7) Ham dönüşüm istemiyorsanız = delete ile overload'ı yasaklayın.
//  8) Default argument ve overload'ı aynı çağrıyı karşılayacak şekilde karıştırmayın.
//  9) Non-template, eşit durumda template'e tercih edilir; ama exact template, promotion gerektiren normal fonksiyonu yener.
// ============================================================================
