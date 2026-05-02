// =============================================================================
// KONU : do-while Döngüsü
// STANDART : C++17
// =============================================================================

#include <iostream>
// Konsol giriş/çıkış kütüphanesi. Olmadan cout ve cin çalışmaz.
// C# karşılığı: "using UnityEngine;"

using namespace std;
// std::cout yerine sadece cout yazmamızı sağlar.
// !! UYARI !! Büyük projelerde kullanımı önerilmez, isim çakışmalarına yol açar.

int main()
{
    int sifre = 1850;
    // Stack'te (yığın bellek) oluşturulan değişken.
    // main() bitince otomatik yok edilir, C#'taki gibi garbage collector YOK.

    int input;
    // !! DİKKAT !! Başlangıç değeri verilmedi.
    // C++'da yerel değişkenler otomatik sıfırlanmaz, içinde çöp değer olabilir.
    // İyi alışkanlık: int input = 0; şeklinde tanımla.

    do
    {
        cout << "Sifreyi giriniz: ";
        // cout: konsola veri gönderir.
        // << : stream insertion operatörü, veriyi sola iter.
        // endl YOK: imleç aynı satırda kalır, kullanıcı hemen yazar.

        cin >> input;
        // cin: klavyeden veri okur, Enter'a basılınca "input"a yazar.
        // !! RİSK !! Kullanıcı harf girerse cin hata moduna girer, döngü sonsuz döner.

    } while (input != sifre);
    // Koşul gövdeden SONRA kontrol edilir. Yani en az 1 kez çalışması garantidir.
    // != : eşit değilse true döner, döngü devam eder.
    //
    // !! YAYGIN HATA !! while(input = sifre) yazarsan — bu karşılaştırma DEĞİL,
    // atama olur. 1850 her zaman true sayılır ve döngü sonsuza döner.

    cout << " welcome home sir " << endl;
    // Döngü ancak doğru şifre girilince biter ve buraya ulaşılır.
    // endl: yeni satır ekler + tamponu (buffer) temizler.
    // Performans gerektiren durumlarda endl yerine '\n' tercih edilir.

} // main() bitti. "sifre" ve "input" stack'ten silinir.
