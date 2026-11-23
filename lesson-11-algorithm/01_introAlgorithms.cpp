// ============================================================
// ALGORITMAYA GIRIS
// ============================================================
//
// 1) ALGORITMA NEDIR?
// Algoritma, bir problemi cozmek icin izlenen sirali, net ve sonlu adimlar
// butunudur. Yemek tarifi gibi dusun: malzemeler girdi, tarifin adimlari
// algoritma, ortaya cikan yemek cikti. Ayni tarifi baska biri izlese ayni
// yemek cikar. Algoritma da herkes (ve her bilgisayar) icin ayni sonucu
// vermelidir.
// Gunluk hayattan ornek: ATM'den para cekme adimlari. Muhendislikten ornek:
// bir devreyi test ederken izledigin olcum sirasi.
//
// 2) BIR ALGORITMANIN OZELLIKLERI
//   Girdi     : sifir veya daha fazla girdi alir.
//   Cikti     : en az bir sonuc uretir.
//   Kesinlik  : her adim nettir, yoruma yer birakmaz.
//   Sonluluk  : sonsuza kadar calismaz, bir noktada biter.
//   Etkinlik  : her adim gercekten yapilabilir, basit bir islemdir.
//
// 3) ALGORITMA, PROGRAM VE KOD ARASINDAKI FARK
// Algoritma fikirdir (plan). Program, o fikrin bir dilde yazilmis halidir.
// Ayni algoritma C++'ta, C#'ta ya da MATLAB'de yazilabilir. Fikir degismez,
// sadece soz dizimi (syntax) degisir. Once dusunulur, sonra kod yazilir.
//
// 4) ALGORITMA NASIL TASARLANIR?
//   a) Problemi tanimla: girdi ne, cikti ne?
//   b) Adimlari kagitta yaz: sozde kod (pseudocode) veya akis diyagrami.
//   c) Kagit uzerinde kucuk bir ornekle elle dene.
//   d) C++'a cevir.
//   e) Sinir durumlarla test et (bos dizi, tek eleman, aranan yok ...).
// Ornek: dizideki en buyuk sayiyi bulma
//   Girdi: sayi dizisi. Cikti: en buyuk sayi.
//   Sozde kod:
//     1. Ilk elemani "en buyuk aday" yap.
//     2. Kalan her eleman icin: eleman adaydan buyukse aday o olsun.
//     3. Eleman kalmayinca aday sonuctur.
//   Bu 3 adim, asagidaki enBuyuk fonksiyonunun birebir karsiligidir.
//
// 5) C++'TA ALGORITMA NEYI IFADE EDER?
// C++'ta "algorithm", if veya for gibi ozel bir anahtar kelime degildir.
// Algoritma, yazdigin kodun gerceklestirdigi is akisinin adidir. Pratikte:
//   - Bir algoritma genelde bir FONKSIYON olarak yazilir. Parametreler girdi,
//     return degeri cikti olur.
//   - Her algoritma uc yapi tasindan kurulur:
//       Sira   : komutlar yukaridan asagi calisir.
//       Secim  : if / else / switch ile karar verilir.
//       Tekrar : for / while ile adimlar tekrarlanir.
//     Yani if/else, switch ve donguler algoritmanin yapi taslaridir.
//   - Algoritmalar veriyle birlikte calisir. Dizi gibi veri yapilari uzerinde
//     arama, siralama, toplama gibi isler yapar.
//   - C++ standart kutuphanesi (<algorithm>) hazir algoritmalar sunar:
//     std::max_element, std::find, std::sort, std::binary_search ...
//     Once ic mantigi ogrenmek, sonra hazir olani kullanmak dogru siradir.
//     (MATLAB'deki max() ve sort() gibi.)
//
// 6) ALGORITMA NASIL DEGERLENDIRILIR?
//   Dogruluk : her girdi icin dogru sonuc verir mi?
//   Zaman    : girdi buyudukce adim sayisi nasil artar? (Big-O)
//   Hafiza   : ekstra ne kadar yer kullanir?
// Big-O, adim sayisinin buyume sekline bakar, sabit carpanlara bakmaz:
//   O(1)      girdi ne kadar buyuk olursa olsun sabit adim (dizi[3] gibi)
//   O(log n)  girdi 2 kat olunca sadece 1 adim artar (ikili arama)
//   O(n)      adim sayisi girdiyle dogru orantili (dogrusal arama, en buyuk)
//   O(n^2)    girdi 2 kat olunca adim 4 kat olur (ic ice iki dongu)
// Ayni sonucu veren algoritmalarin hizi cok farkli olabilir. Asagidaki
// 1000 elemanli ornekte dogrusal arama 1000 adim, ikili arama 9 adim atar.
//
// 7) ASAGIDAKI ORNEKLER
// Dort temel algoritma: en buyuk elemani bulma, dogrusal arama, kabarcik
// siralama ve ikili arama. Aciklamalar kodun altindadir.
//
// ============================================================
// ORNEKLER
// ============================================================

#include <iostream>
#include <cstddef>
using namespace std;

// ===== 1. EN BUYUK ELEMANI BULMA =====

int enBuyuk(const int dizi[], size_t uzunluk)
{
	int enBuyukDeger = dizi[0];

	for (size_t i = 1; i < uzunluk; ++i)
	{
		if (dizi[i] > enBuyukDeger)
		{
			enBuyukDeger = dizi[i];
		}
	}

	return enBuyukDeger;
}

// ===== 2. DOGRUSAL ARAMA =====

int dogrusalArama(const int dizi[], size_t uzunluk, int aranan, int& adimSayisi)
{
	adimSayisi = 0;

	for (size_t i = 0; i < uzunluk; ++i)
	{
		++adimSayisi;

		if (dizi[i] == aranan)
		{
			return static_cast<int>(i);
		}
	}

	return -1;
}

// ===== 3. KABARCIK SIRALAMA =====

void kabarcikSiralama(int dizi[], size_t uzunluk)
{
	for (size_t tur = 0; tur + 1 < uzunluk; ++tur)
	{
		for (size_t i = 0; i + 1 < uzunluk - tur; ++i)
		{
			if (dizi[i] > dizi[i + 1])
			{
				int gecici = dizi[i];
				dizi[i] = dizi[i + 1];
				dizi[i + 1] = gecici;
			}
		}
	}
}

// ===== 4. IKILI ARAMA (dizi sirali olmali) =====

int ikiliArama(const int dizi[], size_t uzunluk, int aranan, int& adimSayisi)
{
	adimSayisi = 0;
	size_t sol = 0;
	size_t sag = uzunluk;

	while (sol < sag)
	{
		++adimSayisi;
		size_t orta = sol + (sag - sol) / 2;

		if (dizi[orta] == aranan)
		{
			return static_cast<int>(orta);
		}
		else if (dizi[orta] < aranan)
		{
			sol = orta + 1;
		}
		else
		{
			sag = orta;
		}
	}

	return -1;
}

int main()
{
	int notlar[] = { 64, 25, 12, 22, 11, 90, 37, 5 };
	size_t uzunluk = sizeof(notlar) / sizeof(notlar[0]);
	int adim = 0;

	cout << "En buyuk: " << enBuyuk(notlar, uzunluk) << endl;

	int yer = dogrusalArama(notlar, uzunluk, 90, adim);
	cout << "Dogrusal arama, 90: index " << yer << ", adim " << adim << endl;

	kabarcikSiralama(notlar, uzunluk);

	cout << "Sirali dizi: ";
	for (int deger : notlar)
	{
		cout << deger << " ";
	}
	cout << endl;

	yer = ikiliArama(notlar, uzunluk, 90, adim);
	cout << "Ikili arama, 90: index " << yer << ", adim " << adim << endl;

	int buyuk[1000];
	for (int i = 0; i < 1000; ++i)
	{
		buyuk[i] = i;
	}

	dogrusalArama(buyuk, 1000, 999, adim);
	cout << "1000 eleman, dogrusal arama adim: " << adim << endl;

	ikiliArama(buyuk, 1000, 999, adim);
	cout << "1000 eleman, ikili arama adim: " << adim << endl;
}

// KODUN ACIKLAMASI
//
// SATIR: int enBuyuk(const int dizi[], size_t uzunluk)
//   const: fonksiyon diziyi sadece okur, degistiremez. uzunluk ayri
//   parametredir cunku dizi fonksiyona adres olarak gelir ve sizeof ile
//   eleman sayisi fonksiyon icinde hesaplanamaz.
// SATIR: int enBuyukDeger = dizi[0];
//   Ilk aday ilk elemandir. 0 ile baslamak yanlis olurdu: butun sayilar
//   negatifse sonuc 0 cikardi. Bu yuzden dizi bos olmamalidir.
// SATIR: for (size_t i = 1; i < uzunluk; ++i)
//   0. eleman zaten aday oldugu icin 1'den baslar. Her eleman bir kez
//   gezilir: n-1 karsilastirma, yani O(n).
//
// SATIR: int dogrusalArama(const int dizi[], size_t uzunluk, int aranan, int& adimSayisi)
//   int& referanstir: fonksiyon main'deki adim degiskenini dogrudan
//   degistirir. Boylece fonksiyon hem index hem adim sayisi dondurmus olur.
//   Donus degeri bulunan index'tir, bulunamazsa -1.
// SATIR: return static_cast<int>(i);
//   i size_t (isaretsiz) tipindedir, donus tipi int. static_cast tur
//   donusumunu acikca yazar. -1 "yok" isareti oldugu icin donus tipi
//   isaretli int secildi (size_t negatif olamaz).
//   En kotu durumda (aranan sonda veya yok) n adim atar: O(n).
//
// SATIR: void kabarcikSiralama(int dizi[], size_t uzunluk)
//   Dizi adres olarak gelir, bu yuzden fonksiyon orijinal diziyi yerinde
//   siralar. Bir sey dondurmesine gerek yoktur (void). const yok, cunku
//   diziyi degistiriyor.
// SATIR: for (size_t tur = 0; tur + 1 < uzunluk; ++tur)
//   Her turda komsu elemanlar karsilastirilip gerekirse yer degistirir,
//   en buyuk eleman kabarcik gibi sona cikar. Kosul tur + 1 < uzunluk
//   olarak yazildi: tur < uzunluk - 1 yazilsa ve uzunluk 0 olsa, size_t
//   cikarmada geri sarar (0 - 1 devasa bir sayi olur).
// SATIR: for (size_t i = 0; i + 1 < uzunluk - tur; ++i)
//   Her turdan sonra sondaki elemanlar yerini bulmustur, o yuzden her tur
//   bir eleman daha az bakilir. i + 1 komsu eleman icindir (dizi[i + 1]).
// SATIR: int gecici = dizi[i];
//   Iki degiskenin yerini degistirmek (swap) icin ucuncu bir kutu gerekir.
//   Ic ice iki dongu oldugu icin yaklasik n*n adim: O(n^2).
//
// SATIR: int ikiliArama(const int dizi[], size_t uzunluk, int aranan, int& adimSayisi)
//   Dizi SIRALI olmalidir. Her adimda ortadaki elemana bakilir, aranan
//   buyukse sol yari, kucukse sag yari atilir. Aralik her adimda yariya
//   iner: O(log n).
// SATIR: size_t sag = uzunluk;
//   Arama araligi [sol, sag) seklindedir: sol dahil, sag dahil degil.
//   Boylece sag = orta - 1 yazmaya gerek kalmaz. size_t ile orta 0 iken
//   orta - 1 devasa bir sayiya doner, bu sekil o tuzagi onler.
// SATIR: size_t orta = sol + (sag - sol) / 2;
//   (sol + sag) / 2 ile ayni sonucu verir ama cok buyuk dizilerde sol + sag
//   toplaminin tasma riskini ortadan kaldirir.
//
// SATIR: size_t uzunluk = sizeof(notlar) / sizeof(notlar[0]);
//   Eleman sayisi dizinin tanimlandigi yerde hesaplanir (8 eleman). Bu
//   deger fonksiyonlara parametre olarak tasinir.
// SATIR: for (int deger : notlar)
//   Range-for: dizinin sinirlarini tipten bilir, index gerekmez.
// SATIR: int buyuk[1000];
//   0'dan 999'a kadar siralanmis dolduruldu, iki aramanin adim sayisini
//   ayni girdiyle karsilastirmak icin. Sonuc: dogrusal 1000, ikili 9 adim.

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson10_algorithms.cpp -o program
