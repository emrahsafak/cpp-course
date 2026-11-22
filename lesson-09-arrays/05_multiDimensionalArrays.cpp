#include <iostream>
#include <string>    // string turu icin gerekli
#include <cstddef>   // size_t icin gerekli
#include <iterator>  // size() fonksiyonu icin gerekli (C++17)
using namespace std;


int main()
{

	int arr[2][4] = { { 1,3,5,7 },{ 2,4,6,8 } };
	cout << "arr[0][0]: " << arr[0][0] << endl;
	cout << " arr[0][1]: " << arr[0][1] << endl;
	cout << endl;
	cout << endl;

	// Butun array elemanlarini yazdiralim

	for (int i = 0; i < 2; ++i)
	{
		cout << "{";
		for (int j = 0; j < 4; ++j)
		{
			cout << "(" << arr[i][j] << ")";
			
		}
		cout << "}" << endl;
		cout << endl;
	}



}

// ============================================================
// KODUN ACIKLAMASI
// ============================================================
//
// SATIR: int arr[2][4] = { { 1,3,5,7 },{ 2,4,6,8 } };
//   Koseli parantezler TANIMDA boyut (adet) belirtir: 2 satir, 4 sutun.
//   Toplam 2 x 4 = 8 eleman. int 4 bayt oldugu icin 8 x 4 = 32 bayt.
//   Ic suslu parantezler her satiri ayri gruplar:
//   ilk satir {1,3,5,7}, ikinci satir {2,4,6,8}.
//   Bellekte tablo yoktur: elemanlar satir satir arka arkaya dizilir
//   (1 3 5 7 2 4 6 8). Buna row-major duzen denir.
//   Matematikteki 2x4 matris ile birebir aynidir.
//
// SATIR: cout << "arr[0][0]: " << arr[0][0] << endl;
//   Koseli parantezler ERISIMDE index (konum) belirtir ve 0'dan baslar.
//   arr[0][0] = ilk satir, ilk sutun = 1.
//   Index aslinda offset'tir: baslangictan kac eleman ileride.
//   MATLAB'da A(1,1) ilk elemandir, C++'ta arr[0][0].
//
// SATIR: cout << " arr[0][1]: " << arr[0][1] << endl;
//   arr[0][1] = ilk satir, ikinci sutun = 3.
//   Metin " arr" diye bosluk ile basladigi icin cikti satiri bir
//   bosluk ile baslar.
//
// SATIR: for (int i = 0; i < 2; ++i)
//   Dis dongu satirlari gezer. i degerleri: 0 ve 1.
//   Gecerli satir indexleri 0 ... 1 oldugu icin kosul i < 2 (<= degil).
//   arr[2][...] yazmak undefined behavior olur: C++ sinir kontrolu yapmaz.
//
// SATIR: for (int j = 0; j < 4; ++j)
//   Ic dongu bir satirin sutunlarini gezer. j degerleri: 0, 1, 2, 3.
//   Dis dongunun HER adiminda j yeniden 0'dan baslar.
//   Toplam calisma sayisi: 2 x 4 = 8.
//
// SATIR: cout << "(" << arr[i][j] << ")";
//   arr[i][j] o anki satir i ve sutun j'deki elemani verir.
//   Derleyici adresi su sekilde hesaplar: baslangic + (i * 4 + j) * 4 bayt.
//   Bu satirda endl yok, bu yuzden bir satirin elemanlari yan yana yazilir.
//
// SATIR: cout << "}" << endl;
//   Bir satirin tum sutunlari bitince } kapatilir ve alt satira gecilir.
//   Hemen altindaki ikinci endl bos bir satir birakir.
//
// CIKTI:
//   arr[0][0]: 1
//    arr[0][1]: 3
//
//
//   {(1)(3)(5)(7)}
//
//   {(2)(4)(6)(8)}
//

