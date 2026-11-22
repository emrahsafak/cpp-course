#include <iostream>
using namespace std;

int main()
{
	int a[4] = { 10, 20, 30, 40 };
	int m[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

	// ===== BOLUM 1: KLASIK FOR =====

	cout << "1.1 sayac: ";
	for (int i = 0; i < 3; i++)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "1.2 index ile dizi:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "  a[" << i << "] = " << a[i] << endl;
	}

	cout << "1.3 ikiser atlayarak: ";
	for (int i = 0; i < 4; i += 2)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "1.4 tersten: ";
	for (int i = 3; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "1.5 2 boyutlu dizi:" << endl;
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			cout << m[row][column] << " ";
		}
		cout << endl;
	}

	// ===== BOLUM 2: RANGE-FOR =====

	cout << "2.1 okuma: ";
	for (int value : a)
	{
		cout << value << " ";
	}
	cout << endl;

	int b[3] = { 1, 2, 3 };

	cout << "2.2 kopya (int value): ";
	for (int value : b)
	{
		value = value * 10;
		cout << value << " ";
	}
	cout << endl;
	cout << "    b hala: ";
	for (int value : b)
	{
		cout << value << " ";
	}
	cout << endl;

	cout << "2.3 ikinci isim (int& value): ";
	for (int& value : b)
	{
		value = value * 10;
		cout << value << " ";
	}
	cout << endl;
	cout << "    b artik: ";
	for (int value : b)
	{
		cout << value << " ";
	}
	cout << endl;

	cout << "2.4 const auto&: ";
	for (const auto& value : b)
	{
		cout << value << " ";
	}
	cout << endl;

	cout << "2.5 2 boyutlu range-for:" << endl;
	for (const auto& row : m)
	{
		for (int value : row)
		{
			cout << value << " ";
		}
		cout << endl;
	}

	cout << "2.6 sadece dis dongu: ";
	for (const auto& row : m)
	{
		cout << "satirda " << sizeof(row) / sizeof(row[0]) << " eleman, ";
	}
	cout << endl;

	for (auto& row : m)
	{
		for (int& value : row)
		{
			value = value * 2;
		}
	}
	cout << "2.7 m iki ile carpildi: ";
	for (const auto& row : m)
	{
		for (int value : row)
		{
			cout << value << " ";
		}
	}
	cout << endl;

	// ===== BOLUM 3: KARSILASTIRMA =====

	int x[3] = { 1, 2, 3 };
	int y[3] = { 10, 20, 30 };
	int z[3];

	for (int i = 0; i < 3; i++)
	{
		z[i] = x[i] + y[i];
	}

	cout << "3.1 x + y: ";
	for (int value : z)
	{
		cout << value << " ";
	}
	cout << endl;

	cout << "3.2 sira numarali:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "  " << (i + 1) << ". eleman: " << z[i] << endl;
	}

	int total1 = 0;
	for (int i = 0; i < 4; i++)
	{
		total1 += a[i];
	}
	int total2 = 0;
	for (int value : a)
	{
		total2 += value;
	}
	cout << "3.3 toplam (klasik, range): " << total1 << " " << total2 << endl;

	return 0;
}

// ============================================================
// KODUN ACIKLAMASI
// ============================================================
//
// ------------------------------------------------------------
// A) BUYUK RESIM
// ------------------------------------------------------------
// Dongu (loop) = bir is blogunu (govdeyi) tekrar tekrar calistirmak.
// C++'ta for'un iki yazimi var:
//   Klasik for : for (baslangic; kosul; adim)
//                Sayaci SEN yonetirsin, elinde bir SAYI (index) olur.
//   Range-for  : for (degisken : dizi)
//                Gezmeyi DERLEYICI yonetir, elinde ELEMANIN KENDISI olur.
// Ikisi de ayni isi yapabilir. Fark, tekrari kimin yonettigi ve sana
// ne verdigidir. Hangisini sececegini tek soru belirler:
// "Elemanin kacinci sirada oldugunu (index) bilmem gerekiyor mu?"
//
// ------------------------------------------------------------
// B) BOLUM 1: KLASIK FOR
// ------------------------------------------------------------
//
// SATIR: for (int i = 0; i < 3; i++)
//   Uc parcasi var, noktali virgulle ayrilir:
//   1) int i = 0 : baslangic. Dongu basinda SADECE BIR KEZ calisir.
//   2) i < 3     : kosul. Her turdan ONCE kontrol edilir; yanlissa
//                  dongu biter.
//   3) { govde } : kosul dogruysa calisir.
//   4) i++       : adim. Govdeden SONRA calisir, sayaci bir artirir.
//   Sira: 1, 2, 3, 4, 2, 3, 4, ... kosul yanlis olunca cikilir.
//   Izleme: i=0 (0<3 dogru, govde) -> i=1 (govde) -> i=2 (govde)
//           -> i=3 (3<3 yanlis, cik). Govde 3 kez calisti: 0 1 2.
//   i degiskeni sadece bu for'un icinde yasar.
//   i++ ve ++i: int icin sonuc ayni. Adim bolumunde fark yaratmaz.
//
// SATIR: cout << "  a[" << i << "] = " << a[i] << endl;
//   a[i]: i, dizideki elemanin index'idir (sira numarasi, 0'dan baslar).
//   Index aslinda offset'tir: baslangictan kac eleman ileride.
//   Adres = baslangic + i * 4 bayt (int 4 bayt oldugu icin).
//   a 4 elemanli oldugu icin gecerli index'ler 0, 1, 2, 3'tur.
//
// SATIR: for (int i = 0; i < 4; i++)
//   Dizi gezerken kosul < kullanilir, <= degil: N elemanli dizide
//   gecerli index'ler 0 ... N-1'dir. i <= 4 yazilsaydi dizinin disina
//   tasilirdi (undefined behavior). C++ sinir kontrolu yapmaz.
//   Buradaki 4 sayisini SEN yazarsin; derleyici bunu dizinin
//   boyutuyla karsilastirmaz. Uyumsuz yazilirsa (i < 5 gibi) derleyici
//   kendiliginden fark etmez.
//
// SATIR: for (int i = 0; i < 4; i += 2)
//   Adim i += 2 oldugu icin ikiser atlar: i = 0 ve 2 (10 ve 30).
//   Baslangic, kosul ve adim serbesttir; istedigin yerden istedigin
//   adimla gidebilirsin. Range-for'da bu serbestlik yoktur.
//
// SATIR: for (int i = 3; i >= 0; i--)
//   Tersten gezme: sondan baslar, i-- ile azalir, i >= 0 oldugu surece
//   doner (40 30 20 10).
//
// SATIR: for (int row = 0; row < 3; row++)
//   2 boyutlu dizi icin ic ice iki for kullanilir.
//   Dis dongu satirlari (row: 0, 1, 2), ic dongu sutunlari
//   (column: 0, 1) gezer. Ic dongu, dis dongunun HER adiminda
//   0'dan yeniden baslar. Toplam tur: 3 x 2 = 6.
//   Gezme sirasi bellek sirasidir (satir satir, row-major).
//
// SATIR: cout << endl;
//   (1.5 icindeki) Bu satir ic dongunun disinda, dis dongunun
//   icindedir: bir satirin sutunlari bitince alt satira gecer.
//
//   Not: i, j, row, column gibi isimler serbesttir; derleyici icin
//   sadece etikettir, anlami sen verirsin. Ic ice dongude iki donguye
//   ayni ismi verme: ic olan dis olani gizler.
//
// ------------------------------------------------------------
// C) BOLUM 2: RANGE-FOR
// ------------------------------------------------------------
//
// SATIR: for (int value : a)
//   Yapi: for (degisken : dizi)
//   ":" bu yapinin sabit parcasidir, "icindeki her biri icin"
//   demektir. Sol: her turda elde edilen degisken. Sag: gezilecek
//   dizi. C# karsiligi: foreach (var value in a).
//   Baslangic, kosul ve adim YAZILMAZ. Derleyici dizinin basindan
//   sonuna eleman eleman ilerler. Sana index vermez, eleman verir.
//   Sag taraf, boyutu bilinen bir dizi olmalidir. Boyut tipin
//   icindedir (int[4] gibi), derleyici basi ve sonu tipten bilir.
//   Burada & yok: value her turda elemanin KOPYASIDIR. Sadece okumak
//   icin yeterli; int kopyalamak ucuzdur. Tipi int yazildi cunku
//   eleman tipi int.
//
//   Soldaki degisken icin 3 karar vardir:
//   1) Tip: auto (derleyici bulsun) veya elle (int).
//   2) &: kopya mi, ikinci isim mi?
//   3) const: degistirmek yasak mi?
//
// SATIR: for (int value : b)
//   (2.2) value kopya oldugu icin govdede value'yu degistirmek diziyi
//   ETKILEMEZ: ekrana 10 20 30 yazilir ama b hala 1 2 3'tur.
//
// SATIR: for (int& value : b)
//   (2.3) & = kopya alma, gercek elemana bagla. Yeni bir kutu acilmaz,
//   mevcut elemana ikinci bir isim verilir: value, dizi elemaninin
//   KENDISIDIR. value'yu degistirmek diziyi degistirir (b = 10 20 30).
//   Klavyeden diziye okumak (cin >> value) icin de bu gerekir.
//   Tanimda tipten sonra yazilan & "referans" demektir. Ifadede
//   yazilan &x ise adres alma operatorudur; farkli bir anlami vardir.
//
// SATIR: for (const auto& value : b)
//   auto : tipi (int) derleyici bulur.
//   &    : kopya yok.
//   const: bu degisken uzerinden degistirme yasak. Yanlislikla
//          degistirmeyi derleyici yakalar.
//   Sadece OKUYAN dongulerde iyi bir aliskanliktir.
//   Karar kurali:
//     Elemani degistirecek misin?             -> auto& (veya int&)
//     Sadece okuyacak, tip buyuk veya dizi    -> const auto&
//     Sadece okuyacak, tip kucuk (int, double)-> int veya auto
//
// SATIR: for (const auto& row : m)
//   m, int[3][2] tipindedir: elemanlari 3 tane int[2] (satir).
//   row her turda bir satirin ikinci adidir, tipi const int(&)[2].
//   Burada & ZORUNLUDUR. auto row (& yok) yazilsaydi dizi
//   kopyalanamaz, pointer'a donusurdu (array-to-pointer decay).
//   Pointer dizinin boyutunu bilmez, bu yuzden ic dongu derlenmezdi.
//   Satirlari gezerken daima & kullan (okuyorsan const auto&).
//
// SATIR: for (int value : row)
//   Ic seviye: row bir int[2] oldugu icin 2 eleman gezer. Sutun
//   sayisi tipten bilinir. Range-for sadece verilen TEK seviyeyi
//   gezer; ic seviyeye inen dongunun kendisini sen yazarsin.
//
// SATIR: cout << "satirda " << sizeof(row) / sizeof(row[0]) << " eleman, ";
//   sizeof(row) = 8 bayt (2 x 4), sizeof(row[0]) = 4 bayt, sonuc 2.
//   Bu, row'un pointer degil 2 elemanli bir dizi oldugunu gosterir.
//   Dis dongu 3 tur dondu: ic dongu olmadan sadece satirlar gezilir.
//
// SATIR: for (auto& row : m)
//   (2.7) Hem satir (auto& row) hem eleman (int& value) referans
//   oldugu icin m'nin kendisi degisir: 2 4 6 8 10 12.
//
//   Derleyici nasil ilerler: dizinin basindan baslar, her adimda bir
//   sonraki elemana gecer, sona gelince durur. Dis dongude bir adim
//   bir satirdir (2 x 4 = 8 bayt), ic dongude bir adim bir int'tir
//   (4 bayt). Konum hesabi yapmaz, index tutmaz.
//   Yaklasik karsiligi (derleyici arka planda pointer/iterator kullanir):
//     for (auto& row : arr) { govde }
//     for (int i = 0; i < 3; i++) { auto& row = arr[i]; govde }
//
// ------------------------------------------------------------
// D) BOLUM 3: KARSILASTIRMA
// ------------------------------------------------------------
//
//   Ortak : ikisi de govdeyi tekrarlar, ikisi de diziyi gezebilir.
//
//   Baslangic, kosul, adim:
//     Klasik for : sen yazarsin.
//     Range-for  : derleyici belirler.
//   Elindeki sey:
//     Klasik for : index (sayi), elemana a[i] ile ulasirsin.
//     Range-for  : elemanin kendisi (kopya veya referans).
//   Sinir hatasi riski:
//     Klasik for : var (i < 5 gibi yanlis yazilabilir).
//     Range-for  : yok, sinirlari tipten alir.
//   Esneklik:
//     Klasik for : atlama, tersten, kismi gezme, her sey.
//     Range-for  : sadece bastan sona hepsi.
//
//   Hangisi? "Index'e ihtiyacim var mi?"
//     Index LAZIM -> klasik for:
//       - ayni anda birden fazla dizide ayni konuma erismek,
//       - sira numarasi yazdirmak,
//       - ikiser atlamak, tersten gitmek, dizinin bir kismini gezmek,
//       - konumu bir formulde kullanmak.
//     Index lazim DEGIL, hepsini bir kez gezeceksin -> range-for.
//
// SATIR: z[i] = x[i] + y[i];
//   Uc dizide ayni konuma erisilir. Range-for tek diziyi gezer ve
//   konumu bilmez, bu yuzden burada klasik for gerekir.
//
// SATIR: cout << "  " << (i + 1) << ". eleman: " << z[i] << endl;
//   Index 0'dan baslar, insanlar 1'den sayar; sira numarasi icin
//   i + 1 yazilir. Index'e ihtiyac duyulan ikinci ornek.
//
// SATIR: total1 += a[i];
//   total2 += value;
//   Ayni is iki yazimla: sonuc ikisinde de 100. Index gerekmeyen bu
//   is icin range-for daha kisa ve sinir hatasi riski yoktur.
//   Ikisi ayni programda birlikte kullanilabilir.
//
// ------------------------------------------------------------
// E) SIK YAPILAN HATALAR
// ------------------------------------------------------------
//   1) for (...) satirinin sonuna ; koymak: govde bos kalir, sonraki
//      { } blogu dongunun disinda yalnizca bir kez calisir.
//   2) < yerine <= yazmak: bir fazla tur, dizinin disina tasma.
//   3) Sinir sayisini dizi boyutuyla uyumsuz yazmak.
//   4) Range-for'da & unutmak: kopya uzerinde calisirsin. cin ile
//      okurken dizi dolmaz. Satirlarda unutulursa derleme hatasi olur.
//   5) Range-for'un sadece bir seviye gezdigini unutmak: 2 boyutlu
//      dizide ic dongu ayrica yazilmalidir.
//   6) ":" (range-for), "::" (std::cout) ve "? :" (kosul operatoru)
//      birbirinden farkli seylerdir.
//
// ------------------------------------------------------------
// CIKTI
// ------------------------------------------------------------
//   1.1 sayac: 0 1 2
//   1.2 index ile dizi:
//     a[0] = 10
//     a[1] = 20
//     a[2] = 30
//     a[3] = 40
//   1.3 ikiser atlayarak: 10 30
//   1.4 tersten: 40 30 20 10
//   1.5 2 boyutlu dizi:
//   1 2
//   3 4
//   5 6
//   2.1 okuma: 10 20 30 40
//   2.2 kopya (int value): 10 20 30
//       b hala: 1 2 3
//   2.3 ikinci isim (int& value): 10 20 30
//       b artik: 10 20 30
//   2.4 const auto&: 10 20 30
//   2.5 2 boyutlu range-for:
//   1 2
//   3 4
//   5 6
//   2.6 sadece dis dongu: satirda 2 eleman, satirda 2 eleman, satirda 2 eleman,
//   2.7 m iki ile carpildi: 2 4 6 8 10 12
//   3.1 x + y: 11 22 33
//   3.2 sira numarali:
//     1. eleman: 11
//     2. eleman: 22
//     3. eleman: 33
//   3.3 toplam (klasik, range): 100 100
//
// COMPILE: g++ -std=c++17 -Wall -Wextra lesson9_forloops.cpp -o program
