// SORU:
// Kullanicidan bir aralik degeri (n) alin ve 2'den n'e kadar olan asal
// sayilari ekrana yazdirin. Asal sayi, yalnizca 1'e ve kendisine tam bolunen
// (kalansiz bolen sayisi tam iki olan) 1'den buyuk dogal sayidir.
// Ayni algoritmayi iki yonde yazin: kucukten buyuge ve buyukten kucuge.
// Ornek: n = 20 -> 2 3 5 7 11 13 17 19 (ters yonde: 19 17 13 11 7 5 3 2)

#include <iostream>
using namespace std;

// asal sayilar yalnizca 1 e ve kendine tam bolunur.

void asalDuz()
{
	int aralikSayi = 0;

	cout << " Lutfnen asal sayilarin araligi icin bir deger giriniz :" << endl;
	cin >> aralikSayi;

	for (size_t i = 2; i <= aralikSayi; ++i)
	{
		size_t sayac = 0;

		for (size_t j = 1; j <= i; ++j)
		{
			if (i % j == 0)
			{
				++sayac;
			}
			
		}

		if (sayac == 2)
			cout << i << " ,";


	}
	cout << endl;
}



void asalTersten()
{
	int aralikSayi = 0;
	cout << " Please enter your number for the range of the prime number : ";
	cin >> aralikSayi;

	for (int i = aralikSayi; i >= 2; --i)
	{
		int bolnSayi = 0;

		for (int j = i; j >= 1; --j)
		{
			if (i % j == 0)
				++bolnSayi;

		}

		if (bolnSayi == 2)          // iç döngü bittiğtten SONRA
			cout << i << " ,";
	}
	cout << endl;
}






int main()
{
	asalDuz();
	asalTersten();
}

// KODUN ACIKLAMASI
// Algoritma: her aday sayi icin kalansiz bolenleri say. Bolen sayisi tam 2
// ise (1 ve kendisi) sayi asaldir. Iki fonksiyon ayni mantigi iki yonde
// uygular. Asagida kodun TUM satirlari ustten alta, sirayla aciklanmistir.
//
// SATIR: #include <iostream>
//   cout, cin ve endl'in tanimlari bu kutuphanede. Dosyaya kopyalanir.
// SATIR: using namespace std;
//   cout, cin, endl'i std:: onekini yazmadan kullanmamizi saglar.
// SATIR: // asal sayilar yalnizca 1 e ve kendine tam bolunur.
//   Yorum satiri, derleyici okumaz. Algoritmanin tanimini hatirlatir.
//
// ---------- asalDuz (kucukten buyuge) ----------
// SATIR: void asalDuz()
//   void: deger dondurmez, sonucu dogrudan ekrana yazar. main sadece cagirir.
// SATIR: int aralikSayi = 0;
//   Kullanicinin girecegi ust siniri (n) tutan kutu. 0 ile baslatilir,
//   baslatilmayan degisken rastgele cop deger tasir.
// SATIR: cout << " Lutfnen asal sayilarin araligi icin bir deger giriniz :" << endl;
//   Kullaniciya mesaj yazar. endl satir sonu koyar ve tamponu bosaltir.
// SATIR: cin >> aralikSayi;
//   Klavyeden bir tam sayi okuyup aralikSayi'ya yazar. Kullanici Enter'a
//   basana kadar program burada bekler.
// SATIR: for (size_t i = 2; i <= aralikSayi; ++i)
//   Dis dongu aday sayilari gezer: 2, 3, ... n. 2'den baslar, cunku 1 asal
//   degildir. size_t isaretsiz tam sayi tipidir, negatif deger tutamaz.
//   ++i: her turdan sonra i bir artar.
// SATIR: size_t sayac = 0;
//   Su anki adayin bolen sayisi. Dis dongunun icinde tanimli oldugu icin her
//   yeni adayda sifirdan baslar (disinda olsaydi sayilar birikirdi).
// SATIR: for (size_t j = 1; j <= i; ++j)
//   Ic dongu, i'yi bolebilecek tum sayilari dener: 1'den i'nin kendisine.
// SATIR: if (i % j == 0)
//   % kalani verir. Kalan 0 ise j, i'yi tam boler, yani j bir bolendir.
// SATIR: ++sayac;
//   Bolen bulundu, sayac bir artar (sayac = sayac + 1 ile ayni).
// SATIR: if (sayac == 2)
//   Bu if ic dongunun DISINDA: tum bolenler sayildiktan sonra karar verilir.
//   Tam iki bolen varsa (1 ve kendisi) asaldir. 7: bolenler 1, 7 -> sayac 2.
//   6: 1, 2, 3, 6 -> sayac 4, asal degil.
// SATIR: cout << i << " ,";
//   Asal sayiyi yazar, ardindan ayirici " ," basar. Suslu parantez yok, bu
//   yuzden if sadece bu tek satiri kontrol eder.
// SATIR: cout << endl;
//   Dis dongu bittikten sonra bir kez calisir, imleci alt satira gecirir.
//   Kapanan } isaretleri: ic dongu, dis dongu ve fonksiyon bloklarini bitirir.
//
// ---------- asalTersten (buyukten kucuge) ----------
// SATIR: void asalTersten()
//   Ayni asal testi, sadece aday sayilar buyukten kucuge gezilir.
// SATIR: int aralikSayi = 0;
//   Ust sinir icin kutu. Bu fonksiyonun kendi yerel degiskeni, asalDuz'dekinden
//   bagimsizdir (farkli scope, farkli kutu).
// SATIR: cout << " Please enter your number for the range of the prime number : ";
//   Mesaj yazar. endl olmadigi icin imlec ayni satirda kalir, kullanici
//   cevabi mesajin hemen yanina yazar.
// SATIR: cin >> aralikSayi;
//   Klavyeden n degerini okur.
// SATIR: for (int i = aralikSayi; i >= 2; --i)
//   Geriye sayma: baslangic n, kosul i >= 2, adim --i. Ilk tur n, son tur 2.
//   Cikti buyukten kucuge siralanir. int isaretli oldugu icin eksiye inebilir.
// SATIR: int bolnSayi = 0;
//   Bolen sayaci, dis dongu icinde: her aday icin sifirdan baslar.
// SATIR: for (int j = i; j >= 1; --j)
//   Bolen adaylari da i'den 1'e gezilir. j >= 1 sart: j 0 olursa i % 0
//   tanimsizdir (sifira bolme). Sayma yonu bolen sayisini degistirmez.
// SATIR: if (i % j == 0)
//   Kalan 0 ise j, i'nin bolenidir.
// SATIR: ++bolnSayi;
//   Bolen sayisini bir arttirir. Suslu parantez yok, if sadece bu satiri
//   kontrol eder.
// SATIR: if (bolnSayi == 2)          // iç döngü bittiğtten SONRA
//   Sagdaki yorum bu satirin ic dongunun disinda, sayim bittikten sonra
//   calistigini hatirlatir. Tam iki bolen -> asal.
// SATIR: cout << i << " ,";
//   Asal sayiyi yazar, ayirici ekler.
// SATIR: cout << endl;
//   Dongu bitince alt satira gecer. Kapanan } isaretleri iki dongu ve
//   fonksiyonu bitirir.
//
// ---------- main ----------
// SATIR: int main()
//   Programin giris noktasi. Calisma buradan baslar.
// SATIR: asalDuz();
//   Fonksiyonu cagirir. Cagirilmazsa icindeki kod hic calismaz. Once n'i
//   sorar, sonra asallari kucukten buyuge yazar.
// SATIR: asalTersten();
//   Ikinci fonksiyonu cagirir: n'i yeniden sorar, asallari buyukten kucuge
//   yazar. main'de return yok: main icin derleyici otomatik return 0 ekler.
//
// Ic ice iki dongu oldugu icin adim sayisi yaklasik n * n kadardir: O(n^2).

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson10_primes.cpp -o program
