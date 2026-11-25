// SORU:
// 3 satir x 2 sutunluk iki int dizisi (arr ve arr2) klavyeden okunur
// (klasik index'li for dongulerle). Iki dizinin ayni konumdaki elemanlari
// toplanip ucuncu bir diziye (sum) yazilir ve sonuc matris seklinde ekrana
// yazdirilir.
//
// Ornek:
//   girdi : 1 2 3 4 5 6   ve   10 20 30 40 50 60
//   cikti : 11 22
//           33 44
//           55 66

#include <iostream>
using namespace std;

int main()
{
	int arr[3][2];
	int arr2[3][2];

	cout << " Enter 6 integer for the first 2D array (3 rows, 2 columns): " << endl;
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			cin >> arr[row][column];
		}
	}

	cout << " Enter 6 integer for the second 2D array (3 rows, 2 columns): " << endl;
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			cin >> arr2[row][column];
		}
	}

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

// KODUN ACIKLAMASI
// Fikir: iki matrisi toplamak (C = A + B) icin ayni konumdaki elemanlar
// toplanir. Dizi konumlari iki index ile adreslenir: satir (row) ve sutun
// (column). Bu yuzden her is (okuma, toplama, yazdirma) ic ice iki donguyle
// yapilir. Kodun TUM satirlari asagida ustten alta, sirayla aciklanmistir.
//
// SATIR: #include <iostream>
//   cout, cin ve endl'in tanimlari bu kutuphanede. Dosyaya kopyalanir.
// SATIR: using namespace std;
//   cout, cin, endl'i std:: onekini yazmadan kullanmamizi saglar.
// SATIR: int main()
//   Programin giris noktasi. Calisma buradan baslar.
//
// ---------- Dizilerin tanimi ----------
// SATIR: int arr[3][2];
//   3 satir 2 sutunluk dizi: 6 tane int, 6 x 4 = 24 bayt. Ilk deger
//   verilmedi, icinde cop degerler var; okunmadan once doldurulmali.
//   Tipi "3 tane int[2]" demektir. Koseli parantez burada BOYUTTUR (adet).
// SATIR: int arr2[3][2];
//   arr ile ayni tip ve boyutta ikinci dizi. Ayni konumdaki elemanlari
//   toplayabilmek icin boyutlari ayni olmali.
//
// ---------- Birinci diziyi okuma ----------
// SATIR: cout << " Enter 6 integer for the first 2D array (3 rows, 2 columns): " << endl;
//   Kullaniciya kac sayi girecegini soyler. endl satir sonu koyar.
// SATIR: for (int row = 0; row < 3; row++)
//   Dis dongu satirlari gezer. row bir INDEX'tir (sayi): 0, 1, 2.
//   Gecerli satir indexleri 0 ... 2 oldugu icin sart row < 3. row <= 3
//   yazilsaydi arr[3] diye olmayan bir satira erisilirdi (undefined
//   behavior: C++ sinir kontrolu yapmaz).
// SATIR: for (int column = 0; column < 2; column++)
//   Ic dongu o satirin sutunlarini gezer: column 0 ve 1. Dis dongunun
//   her adiminda column yeniden 0'dan baslar. Toplam tur: 3 x 2 = 6.
// SATIR: cin >> arr[row][column];
//   Klavyeden okunan sayiyi DOGRUDAN o konumdaki kutuya yazar. Ilk
//   koseli parantez satiri, ikincisi sutunu secer: arr[row] bir satirdir
//   (int[2]), [column] o satirdan bir eleman secer.
//   Sira satir satirdir: arr[0][0], arr[0][1], arr[1][0] ...
//   Ornek: 1 2 3 4 5 6 girilirse arr = {1,2}, {3,4}, {5,6}.
//   Sayilari bosluk veya Enter ayirir.
//
// ---------- Ikinci diziyi okuma ----------
// SATIR: cout << " Enter 6 integer for the second 2D array (3 rows, 2 columns): " << endl;
//   Ikinci dizi icin ayni mesaj.
// SATIR: for (int row = 0; row < 3; row++)
//   Ayni dis dongu. row burada yeni bir degiskendir: ilk dongu bitince
//   row yok oldu (scope), bu dongu yenisini acar.
// SATIR: for (int column = 0; column < 2; column++)
//   Ayni ic dongu, yine her satirda column 0'dan baslar.
// SATIR: cin >> arr2[row][column];
//   Okunan sayiyi arr2'nin ayni konumdaki kutusuna yazar. Ornek:
//   10 20 30 40 50 60 girilirse arr2 = {10,20}, {30,40}, {50,60}.
//
// SATIR: cout << endl;
//   Girdi ile sonuc arasinda bos bir satir birakir, cikti okunakli olur.
//
// ---------- Toplama ----------
// SATIR: int sum[3][2];
//   Toplamlari tutacak dizi. Cop dolu baslar; asagidaki dongu 6
//   elemanin hepsine yazar. Degisken kullanilmadan hemen once
//   tanimlanabilir.
// SATIR: for (int row = 0; row < 3; row++)
//   Satirlari gezer (0, 1, 2).
// SATIR: for (int column = 0; column < 2; column++)
//   Her satirda sutunlari gezer (0, 1).
// SATIR: sum[row][column] = arr[row][column] + arr2[row][column];
//   Matris toplami: ayni konumdaki iki eleman toplanip sum'in ayni
//   konumuna yazilir. Uc dizide AYNI (row, column) cifti kullanildigi
//   icin klasik index'li dongu burada dogal secimdir. MATLAB'da
//   sum = arr + arr2 tek satirdir; C++'ta dizilerde + operatoru yoktur,
//   dongu gerekir.
//
// ---------- Yazdirma ----------
// SATIR: for (int row = 0; row < 3; row++)
//   Her satir icin bir tur: sonuc matrisini satir satir yazar.
// SATIR: for (int column = 0; column < 2; column++)
//   O satirin elemanlarini sirayla gezer.
// SATIR: cout << sum[row][column] << " ";
//   Bir satirin elemanlarini ayni satira, aralarinda bosluk birakilarak
//   yazar. Bosluk olmazsa sayilar birbirine yapisir (1122 gibi).
// SATIR: cout << endl;
//   Bu satir ic dongunun disinda, dis dongunun icindedir: bir satirin
//   tum elemanlari yazildiktan sonra alt satira gecer.
// SATIR: }
//   main'in sonu. main'de return yazilmazsa derleyici otomatik return 0
//   ekler, program basariyla bitti demektir.
//
// Beklenen cikti (girdi: 1 2 3 4 5 6 ve 10 20 30 40 50 60):
//   11 22
//   33 44
//   55 66

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson9_matrixfor.cpp -o program
