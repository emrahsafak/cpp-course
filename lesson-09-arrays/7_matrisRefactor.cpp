#include <iostream>
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
			cout << sum[row][column] << " ";
		}
		cout << endl;
	}
	
}

// SORU:
// 3x2 boyutunda iki dizi kullanicidan okunacak. Elemanlar ayni konumdan
// toplanip sum dizisine yazilacak ve sonuc matris seklinde ekrana basilacak.
// Ornek: 1 2 3 4 5 6 ve 10 20 30 40 50 60 -> 11 22 / 33 44 / 55 66

// KODUN ACIKLAMASI
// SATIR: for (auto& row : arr) { for (int& value : row) { cin >> value; } }
//   Range-for ile okuma. auto& row satirin kendisi, int& value elemanin
//   kendisi. & oldugu icin cin dogrudan dizinin icine yazar (kopya degil).
// SATIR: int sum[3][2];
//   Sonuc icin 3x2 dizi. Baslangic degeri yok, ilk yazilista dolar.
// SATIR: for (int row = 0; row < 3; row++)
//   Dis dongu satirlari gezer (0, 1, 2). Ic dongu sutunlari gezer (0, 1).
//   Klasik for kullaniyoruz cunku ayni index ile iki diziye birden erisiyoruz.
// SATIR: sum[row][column] = arr[row][column] + arr2[row][column];
//   Ayni konumdaki iki eleman toplanip sum'a yazilir.
// SATIR: cout << sum[row][column] << " ";
//   REFACTOR: Onceden toplama ve yazdirma iki ayri dongudeydi, simdi tek
//   dongude. Her hucre sadece kendi konumundaki hucrelere bagli oldugu icin
//   hesaplandigi anda yazdirilabilir.
// SATIR: cout << endl;
//   Her satirin sonunda alt satira gecer, cikti matris gibi gorunur.

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson9_matrix_refactor.cpp -o program
