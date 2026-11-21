#include <iostream>
#include <string>    // string turu icin gerekli
#include <cstddef>   // size_t icin gerekli
#include <iterator>  // size() fonksiyonu icin gerekli (C++17)
using namespace std;


int main()
{
	int arr[3][2];
	int arr2[3][2];
	
	cout << " Enter 6 integer for the first 2D array (3 rows, 2 columns): " << endl;
	for (auto& row : arr)
	{
		for (int& value : row)
		{
			cin >> value;
		}
	}
	cout << " Enter 6 integer for the second 2D array (3 rows, 2 columns): " << endl;
	for (auto& row : arr2)
	{
		for (int& value : row)
		{
			cin >> value;

		}

	}

	cout << endl;
	cout << endl;
	cout << endl;

int sum[3][2];

	for (int row = 0; row < 3; row++) 
	{
		for (int column = 0; column < 2; column++) 
		{
			sum[row][column] = arr[row][column] + arr2[row][column];
		}
	} 
	for (int row = 0; row < 3; row++) 
    {
	    for (int column = 0; column < 2; column++) 
		{
			cout << sum[row][column] << " ";
		}
	   cout << endl;
    }

}

// ============================================================
// SORU
// ============================================================
//
// 3 satir x 2 sutunluk iki int dizisi (arr ve arr2) klavyeden
// okunur. Iki dizinin ayni konumdaki elemanlari toplanip ucuncu
// bir diziye (sum) yazilir ve sonuc matris seklinde ekrana
// yazdirilir.
//
// Ornek:
//   girdi : 1 2 3 4 5 6   ve   10 20 30 40 50 60
//   cikti : 11 22
//           33 44
//           55 66
//
// ============================================================
// KODUN ACIKLAMASI
// ============================================================
//
// SATIR: int arr[3][2];
//   3 satir 2 sutunluk dizi: 6 tane int, 6 x 4 = 24 bayt.
//   Ilk deger verilmedi, icinde cop degerler var; okunmadan once
//   doldurulmali. Tipi "3 tane int[2]" demektir: sutun sayisi (2)
//   tipin icinde yazilidir. arr2 ayni tiptedir.
//
// SATIR: for (auto& row : arr)
//   Bu bir range-based for (range-for) dongusudur. 3 parcasi var:
//   1) ":" isareti bu yapinin sabit parcasidir, "icindeki her biri
//      icin" demektir. Solu: her turda elde edilen degisken.
//      Sagi: gezilecek dizi. C#'taki karsiligi:
//      foreach (var row in arr)
//   2) auto: tipi derleyici bulur. arr'nin elemanlari int[2]
//      oldugu icin row'un tipi int(&)[2] olur (2 elemanli satir).
//   3) &: kopya alma, gercek satira bagla demektir. Yeni bir kutu
//      acilmaz, mevcut satira ikinci bir isim verilir. row
//      uzerindeki her islem arr'nin kendisini etkiler.
//   Dongu arr'nin 3 satirini sirayla gezer.
//   & olmazsa dizi kopyalanmaz, pointer'a donusur ve ic dongu
//   boyutu bilemedigi icin derlenmez.
//
// SATIR: for (int& value : row)
//   Ayni range-for yapisi: ":" "icindeki her biri icin" demektir.
//   row bir int[2] oldugu icin ic dongu 2 eleman gezer; sutun
//   sayisi tipten bilinir. Eleman tipi int oldugu icin auto
//   yerine int yazildi.
//   & burada da kopya degil, ikinci isim demektir: value, satirdaki
//   elemanin kendisidir. int value yazilsaydi eleman kopyalanir,
//   okunan sayi kopyaya yazilir ve dizi dolmazdi.
//
// SATIR: cin >> value;
//   value, dizi elemaninin kendisi oldugu icin okunan sayi
//   dogrudan diziye yazilir.
//   Sira satir satirdir: arr[0][0], arr[0][1], arr[1][0] ...
//   Ornek: 1 2 3 4 5 6 girilirse arr = {1,2}, {3,4}, {5,6}.
//   Sayilari bosluk veya Enter ayirir.
//
// SATIR: for (auto& row : arr2)
//   arr ile ayni yapi (range-for, auto, &), sadece dizi farkli.
//
// SATIR: int sum[3][2];
//   Toplamlari tutacak dizi. Cop dolu baslar; asagidaki dongu
//   6 elemanin hepsine yazar. Degisken kullanilmadan hemen once
//   tanimlanabilir.
//
// SATIR: for (int row = 0; row < 3; row++)
//   Bu klasik for dongusudur (range-for degil): row bir index'tir
//   (sayi). Range-for'daki row ise bir satirin kendisiydi. Isim
//   ayni, anlam farkli; isim sadece bir etikettir.
//   Gecerli satir indexleri 0 ... 2 oldugu icin row < 3.
//
// SATIR: for (int column = 0; column < 2; column++)
//   Ic dongu sutunlari gezer: column 0 ve 1. Dis dongunun her
//   adiminda column yeniden 0'dan baslar.
//
// SATIR: sum[row][column] = arr[row][column] + arr2[row][column];
//   Matris toplami (C = A + B): ayni konumdaki elemanlar toplanir.
//   Burada klasik for kullanilir, cunku uc dizide ayni konuma
//   birden erisilmesi gerekir; range-for tek diziyi gezer.
//   MATLAB'da sum = arr + arr2 tek satirdir; C++'ta dizilerde +
//   operatoru yoktur, dongu gerekir.
//
// SATIR: cout << sum[row][column] << " ";
//   Bir satirin elemanlari ayni satira, aralarinda bosluk
//   birakilarak yazilir.
//
// SATIR: cout << endl;
//   Yazdirma dongusunde bu satir ic dongunun disinda, dis dongunun
//   icindedir: her satir bitince alt satira gecer.
//
// COMPILE: g++ -std=c++17 -Wall -Wextra lesson9_matrix.cpp -o program
