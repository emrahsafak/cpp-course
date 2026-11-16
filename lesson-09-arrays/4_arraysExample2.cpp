#include <iostream>
#include <string>    // string turu icin gerekli
#include <cstddef>   // size_t icin gerekli
#include <iterator>  // size() fonksiyonu icin gerekli (C++17)
using namespace std;


int main()
{
	const int size = 4;
	double sinavNotlari[size]; // sinav notlarini tutacak dizi.
	double sinavAgirlik[size] = {0.15, 0.15,0.30, 0.40}; // sinav agirliklarini tutacak dizi.
	double agirlikToplam = 0;


	for (int i = 0; i < size; ++i)
	{
		cout << i +1 << " sianv notunu giriniz: ";
		cin >> sinavNotlari[i];
		agirlikToplam += sinavNotlari[i] * sinavAgirlik[i];
	}
	
	cout << "Sinav notlari ortalamasi: " << agirlikToplam << endl;

}


// =============================================================================
//  KODUN ACIKLAMASI
// =============================================================================
//
// SATIR: const int size = 4;
//   Degeri degistirilemeyen int. Dizi boyutu derleme zamaninda bilinmek zorunda
//   oldugu icin 4 sabit olarak yazilir. Hem iki dizinin boyutunu hem de
//   dongunun sinirini belirler.
//
// SATIR: double sinavNotlari[size];
//   4 tane double kutusu (4 x 8 = 32 bayt), ardisik. Ilk deger verilmedi, yani
//   icleri belirsiz. Sorun yok, cunku dongu her kutuyu okumadan once yaziyor.
//
// SATIR: double sinavAgirlik[size] = {0.15, 0.15,0.30, 0.40};
//   Degerler sirayla 0., 1., 2., 3. kutuya yazilir. Notlar ve agirliklar iki
//   ayri dizidir, ayni index ile eslesir: sinavNotlari[2] ile sinavAgirlik[2]
//   ayni sinava aittir. Agirliklarin toplami 1.00.
//
// SATIR: double agirlikToplam = 0;
//   Toplamin biriktigi degisken. Icinde agirliklarin toplami degil, not x
//   agirlik carpimlarinin toplami birikir. 0, double'a otomatik cevrilir (0.0).
//
// SATIR: agirlikToplam += sinavNotlari[i] * sinavAgirlik[i];
//   Ayni index'teki not ile agirligi carpip toplama ekler. Dongu bitince
//   sonuc = Sum(not * agirlik). Agirliklar toplami 1.00 oldugu icin bu deger
//   dogrudan agirlikli ortalamadir, ayrica bolme gerekmez.
//   (Fizikte kutle merkezi: Sum(m * x) / Sum(m). Agirlik = kutle, not = konum.)
//
// SATIR: cout << "Sinav notlari ortalamasi: " << agirlikToplam << endl;
//   cout double'i varsayilan olarak 6 anlamli basamakla ve sondaki sifirlari
//   atarak yazar: 70.5 -> 70.5, 100.0 -> 100, 73.456789 -> 73.4568.
//
// SATIR: }
//   main'in sonunda return yok. main'e ozel olarak sonuna gelinince otomatik
//   "return 0;" uygulanir.
//
// COMPILE: g++ -std=c++17 -Wall -Wextra lesson3_arrays.cpp -o program
