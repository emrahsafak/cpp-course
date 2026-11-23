// SORU:
// Kullanicidan bir aralik degeri (n) alin ve 2'den n'e kadar olan asal
// sayilari iki yonde (kucukten buyuge ve buyukten kucuge) ekrana yazdirin.
// Asal testini tek bir fonksiyonda toplayin ve hizli calissin: n = 100000
// ve ustunde bile bekletmesin. Her yonde bulunan asal sayi adedini de
// geri dondurun ve main icinde yazdirin.
// Kontrol: n = 100 -> 25 asal, n = 1000 -> 168, n = 100000 -> 9592.

// =====================================================================
// ONCEKI KOD (eski surum, karsilastirma icin; adlarina Eski eklendi,
// main'den cagrilmaz. Eski main sadece asalDuzEski(); asalTerstenEski();
// cagiriyordu.)
// =====================================================================
#include <iostream>
using namespace std;

void asalDuzEski()
{
	int aralikSayi = 0;
	cout << " Lutfnen asal sayilarin araligi icin bir deger giriniz :" << endl;
	cin >> aralikSayi;
	for (size_t i = 2; i <= aralikSayi; ++i)
	{
		size_t sayac = 0;
		for (size_t j = 1; j <= i; ++j)
		{
			if (i % j == 0) { ++sayac; }
		}
		if (sayac == 2)
			cout << i << " ,";
	}
	cout << endl;
}

void asalTerstenEski()
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
		if (bolnSayi == 2)
			cout << i << " ,";
	}
	cout << endl;
}

// =====================================================================
// YENI KOD (asagida, senin yazdigin ve calisan hali)
// =====================================================================

#include <iostream>
using namespace std;

// asal sayilar yalnizca 1 e ve kendine tam bolunur.


bool asalMi(int sayi)
{
	if (sayi < 2)
	{
		return false;
	}

	if (sayi == 2)
		return true;

	if (sayi % 2 == 0)
		return false;

	for (int j = 3; (long long) j * j <= sayi; j +=2 )
	{
		if (sayi % j == 0)
		{
			return false;
		}
	}

	return true;
}



int asalDuz()
{
	int aralikSayi = 0;
	int asalAdeti = 0;

	cout << " Lutfnen asal sayilarin araligi icin bir deger giriniz :" << endl;
	cin >> aralikSayi;

	for (int i = 2; i <= aralikSayi; ++i)
	{
		if (asalMi(i))
		{
			cout << i << " ,";
			++asalAdeti;
		}

	}
	cout << endl;
	return asalAdeti;
}



int asalTersten()
{
	int aralikSayi = 0;
	int asalAdeti = 0;
	cout << " Please enter your number for the range of the prime number : ";
	cin >> aralikSayi;

	for (int i = aralikSayi; i >= 2; --i)
	{
		if (asalMi(i))
		{
			cout << i << " ,";
			++asalAdeti;
		}


	}
	cout << endl;
	return asalAdeti;
}



int main()
{
	int asal = asalDuz();
	cout << " Toplam asal sayi adedi :" << asal << endl;



	int asal2 = asalTersten();
	cout << " Toplam asal sayi adedi :" << asal2 << endl;
}

// KODUN ACIKLAMASI
//
// =====================================================================
// BOLUM 1: ONCEKI HAL (kisaca)
// =====================================================================
// Onceki kod dosyanin en ustunde, asalDuzEski ve asalTerstenEski adlariyla
// duruyor (satir satir aciklamasi onceki asal sayilari notunda). Asal testi
// asalDuz ve asalTersten icinde ayri ayri, ic ice bir dongu olarak
// yazilmisti: her aday icin bir sayac, 1'den i'ye kadar bir ic dongu ve
// dongu bittikten sonra "sayac == 2 mi?" karari.
//
// Mantik: i'nin 1'den i'ye kadar TUM bolenlerini say. Bolen sayisi tam 2
// ise (1 ve kendisi) asaldir. Dogru calisir ama her aday sayi icin i kadar
// tur doner ve ayni kod iki fonksiyonda kopya olarak durur.
//
// =====================================================================
// BOLUM 2: NELER GELISTI (yeni kod onceki koda gore)
// =====================================================================
// 1) Test tek fonksiyona tasindi: asalMi(int sayi).
//    ONCE: ayni ic dongu iki fonksiyonda kopyaydi.
//    SIMDI: asal testi tek yerde, iki fonksiyon da asalMi(i) cagirir.
//    Testi bir kez yazarsin, bir kez duzeltirsin.
//
// 2) Sayma yerine evet/hayir sorusu.
//    ONCE: tum bolenler sayilir, sonunda "sayac == 2 mi?" diye bakilir.
//    SIMDI: 1 ve kendisi disinda tek bir bolen bulunca hemen return false.
//    Gerisini saymaya gerek yok. Ornek: 1000 sayisinda 2 bolundugu icin
//    ilk kontrolde hemen false doner.
//
// 3) 1 ve sayinin kendisi denenmez.
//    ONCE: j 1'den i'ye kadar gidiyordu (2 bolen hep garanti).
//    SIMDI: bu ikisi her sayiyi boler, bilgi vermez, o yuzden hic
//    denenmez. Kalan bolen aranir, hic bulunmazsa sayi asaldir.
//
// 4) Karekok siniri: j * j <= sayi.
//    Bolenler cift cift gelir. 36 icin: 2x18, 3x12, 4x9, 6x6. Her cifte
//    kucuk olan hep 6'ya (karekoke) kadar. Karekoktan sonrasina bakmak
//    ayni ciftleri tersten tekrar bulmaktir. <= sart: 9 = 3x3 gibi tam
//    karelerde j * j sayiya esit olur, < yazilsaydi 9 asal sanilirdi.
//
// 5) Cift sayilar atlanir.
//    2 disindaki cift sayilar asal degildir. Cift sayi hemen elenir, tek
//    sayida da bolen cift olamaz: j 3'ten baslar ve j += 2 ile ilerler
//    (3, 5, 7, 9, ...). Islem yaklasik yariya iner.
//
// 6) int tasmasina karsi (long long).
//    int en fazla 2147483647 tutar. j * j, j = 46341 oldugunda bu siniri
//    asar ve sonuc anlamsiz olur. (long long) j * j ile carpma buyuk
//    kutuda yapilir. Boylece asalMi(2147483647) de dogru cevap verir.
//
// 7) Tip duzeni.
//    ONCE: asalDuz'da size_t i ile int aralikSayi karsilastiriliyordu,
//    derleyici isaretli/isaretsiz karsilastirma uyarisi veriyordu.
//    SIMDI: her yerde int, uyari yok.
//
// 8) Sonuc dogrulanabilir: fonksiyonlar asal adedini return eder.
//    Bilinen degerlerle karsilastirilir: n = 100 -> 25, 1000 -> 168,
//    10000 -> 1229, 100000 -> 9592. Iki yon da ayni n icin ayni adedi
//    vermelidir.
//
// HIZ FARKI (ic dongunun kac kez calistigi, hesaplanmis deger):
//   n = 1000    : onceki ~500 bin tur, yeni ~2 bin tur
//   n = 100000  : onceki ~5 milyar tur, yeni ~1,3 milyon tur
//   (yaklasik 3700 kat daha az is)
// Karmasiklik: onceki yaklasik n * n / 2 adim (O(n^2)). Yeni kod her asal
// sayida en fazla sqrt(sayi) / 2 tur doner; adim sayisi yaklasik
// n * sqrt(n) mertebesinde ve pratikte bundan da az.
//
// =====================================================================
// BOLUM 3: SATIR SATIR ACIKLAMA
// =====================================================================
//
// ---------- Baslangic ----------
// SATIR: #include <iostream>
//   cout, cin ve endl'in tanimlari bu kutuphanede. Dosyaya kopyalanir.
// SATIR: using namespace std;
//   cout, cin, endl'i std:: onekini yazmadan kullanmamizi saglar.
// SATIR: // asal sayilar yalnizca 1 e ve kendine tam bolunur.
//   Yorum satiri, derleyici okumaz. Asal sayinin tanimini hatirlatir.
//
// ---------- asalMi: tek bir sayinin asal olup olmadigini soyler ----------
// SATIR: bool asalMi(int sayi)
//   bool: sadece true (evet) ya da false (hayir) tutar. Bu fonksiyon bir
//   evet/hayir sorusunun cevabini geri verir. sayi: sorulan sayi.
// SATIR: if (sayi < 2)
//   0, 1 ve negatif sayilar asal degildir, en basta elenir.
// SATIR: return false;
//   (sayi < 2 icin) Cevabi "hayir" olarak verir ve fonksiyondan HEMEN
//   cikar. Asagidaki satirlar bu sayi icin hic calismaz.
// SATIR: if (sayi == 2)
//   2 tek cift asal sayidir, asagidaki cift sayi kontrolunden once ozel
//   olarak ele alinir. Sirasi onemli: bu satir altta olsaydi 2, bir
//   sonraki kontrolde elenirdi.
// SATIR: return true;
//   (sayi == 2 icin) Cevap "evet", fonksiyon biter. Suslu parantez yok,
//   if sadece bu tek satiri kontrol eder.
// SATIR: if (sayi % 2 == 0)
//   % kalani verir. Kalan 0 ise sayi 2'ye tam bolunur, yani cifttir.
// SATIR: return false;
//   (cift sayilar icin) 2 disindaki cift sayilar asal degildir. Cevap
//   "hayir", fonksiyon biter. Buraya gelen her sayi artik tektir.
// SATIR: for (int j = 3; (long long) j * j <= sayi; j +=2 )
//   j: aday bolen. 3'ten baslar, cunku sayi tek oldugu icin bolen cift
//   olamaz. Sart: j'nin karesi sayiyi gecene kadar dene (karekok siniri).
//   (long long) j: j'yi once buyuk kutuya cevirir, carpma tasmasin diye.
//   j +=2: her turda j'ye 2 ekler, yani 3, 5, 7, 9, ... diye ilerler.
// SATIR: if (sayi % j == 0)
//   Kalan 0 ise j, sayiyi tam boler. 1 ve kendisi disinda bir bolen
//   bulundu demektir.
// SATIR: return false;
//   (bolen bulundugunda) Cevap "hayir", fonksiyon ve dongu hemen biter.
//   Eski koddaki sayac ve break islerini tek satirda yapar.
// SATIR: return true;
//   Bu satira ancak dongu sonuna kadar doner ve hic return false
//   calismazsa gelinir: hicbir aday bolmedi, sayi asaldir. Dongunun
//   DISINDA durmasi onemli: icinde olsaydi ilk bolmeyen adayda "asal"
//   derdi (9 icin j = 2 bolmez, yanlis cevap verirdi).
//
// ---------- asalDuz: kucukten buyuge ----------
// SATIR: int asalDuz()
//   Artik int: ekrana yazmanin yani sira bulunan asal adedini geri verir.
// SATIR: int aralikSayi = 0;
//   Kullanicinin girecegi ust sinir (n) icin kutu. 0 ile baslatilir.
// SATIR: int asalAdeti = 0;
//   Bulunan asallari sayan kutu. Henuz hic asal bulunmadigi icin 0.
// SATIR: cout << " Lutfnen asal sayilarin araligi icin bir deger giriniz :" << endl;
//   Kullaniciya mesaj yazar. endl satir sonu koyar.
// SATIR: cin >> aralikSayi;
//   Klavyeden bir tam sayi okuyup aralikSayi'ya yazar. Kullanici Enter'a
//   basana kadar program bekler.
// SATIR: for (int i = 2; i <= aralikSayi; ++i)
//   Aday sayilari 2'den n'e kadar gezer. int, aralikSayi ile ayni tip
//   oldugu icin isaretli/isaretsiz uyarisi yoktur.
// SATIR: if (asalMi(i))
//   asalMi'ya "i asal mi?" diye sorar. Cagri, geri verdigi true ya da
//   false ile yer degistirir, if ona bakar. Eski ic dongunun yerini aldi.
// SATIR: cout << i << " ,";
//   Asal sayiyi yazar, ardindan ayirici " ," basar.
// SATIR: ++asalAdeti;
//   Asal bulundu, sayac bir artar. Bu ve ustteki satir if'in suslu
//   parantezi icinde, ikisi de sadece asal sayida calisir.
// SATIR: cout << endl;
//   Dongu bittikten sonra bir kez calisir, alt satira gecer.
// SATIR: return asalAdeti;
//   Bulunan asal adedini fonksiyonu cagirana geri verir. asalAdeti
//   fonksiyonun yerel kutusudur, dis dunya ancak return ile ulasir.
//
// ---------- asalTersten: buyukten kucuge ----------
// SATIR: int asalTersten()
//   Ayni islem, sayilar buyukten kucuge gezilir. Bu da adedi geri verir.
// SATIR: int aralikSayi = 0;
//   Bu fonksiyonun kendi yerel kutusu, asalDuz'dakinden bagimsizdir.
// SATIR: int asalAdeti = 0;
//   Bu fonksiyonun kendi sayaci, yine 0 ile baslar.
// SATIR: cout << " Please enter your number for the range of the prime number : ";
//   Mesaj yazar. endl yok, imlec ayni satirda kalir, cevap yanina yazilir.
// SATIR: cin >> aralikSayi;
//   Klavyeden n degerini okur.
// SATIR: for (int i = aralikSayi; i >= 2; --i)
//   Geriye sayma: baslangic n, sart i >= 2, adim --i. Ilk tur n, son tur 2.
// SATIR: if (asalMi(i))
//   Ayni asal testi, ayni fonksiyondan. Test kodu kopyalanmadi.
// SATIR: cout << i << " ,";
//   Asal sayiyi yazar.
// SATIR: ++asalAdeti;
//   Sayaci bir artirir. Suslu parantez sayesinde sadece asal sayida calisir.
// SATIR: cout << endl;
//   Dongu bitince alt satira gecer.
// SATIR: return asalAdeti;
//   Adedi main'e geri verir.
//
// ---------- main ----------
// SATIR: int main()
//   Programin giris noktasi. Calisma buradan baslar.
// SATIR: int asal = asalDuz();
//   asalDuz calisir (n sorar, asallari yazar) ve geri verdigi adet asal
//   kutusuna konur. Cagri, return degeriyle yer degistirir.
// SATIR: cout << " Toplam asal sayi adedi :" << asal << endl;
//   Geri gelen adedi yazdirir. Bilinen degerle (ornegin 100 icin 25)
//   karsilastirarak dogrulama yapilir.
// SATIR: int asal2 = asalTersten();
//   Ikinci fonksiyon calisir ve adedi asal2 kutusuna konur. Ayri bir kutu,
//   cunku asal zaten dolu. Ikisine ayni n girilirse asal == asal2 olmali.
// SATIR: cout << " Toplam asal sayi adedi :" << asal2 << endl;
//   Ikinci adedi yazdirir.

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson10_optimization.cpp -o program
