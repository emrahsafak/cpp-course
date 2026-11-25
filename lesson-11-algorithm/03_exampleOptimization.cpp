// SORU:
// Kullanicidan bir aralik degeri (n) alin ve 2'den n'e kadar olan asal
// sayilari ekrana yazdirin. Asal testini tek bir fonksiyonda (isPrime)
// toplayin ve hizli calissin: n = 100000 ve ustunde bile bekletmesin.
// Bulunan asal sayi adedini de geri dondurun ve main icinde yazdirin.
//
// Ornek: n = 20 -> 2, 3, 5, 7, 11, 13, 17, 19,   Toplam: 8
// Kontrol: n = 100 -> 25 asal, n = 1000 -> 168, n = 10000 -> 1229,
//          n = 100000 -> 9592.

#include <iostream>
using namespace std;

// asal sayilar yalnizca 1 e ve kendine tam bolunur.


bool isPrime(int num)
{
	if (num < 2)
		return false;
	if (num == 2)
		return true;

	if (num % 2 == 0)
	{
		return false;
	}

	for (int i = 3; (long long)i * i <= num; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
		
	}
	
	return true;

}


int primeNum()
{
	int num = 0;
	int counterPrime = 0;

	cout << " Please enter the number for scope of the prime number :" << endl;
	cin >> num; 

	for (int i = 2; i <= num; ++i)
	{
		if (isPrime(i))
		{
			cout << i << ", ";
			++counterPrime;
		}

	}

	cout << endl;
	return counterPrime;
	
}





int main()
{
	int prime = primeNum();

	cout << " Total prime number :" << prime << endl;

}

// KODUN ACIKLAMASI
// Bu not iki bolumden olusur:
//   BOLUM 1: Kodun TUM satirlari ustten alta, sirayla.
//   BOLUM 2: isPrime icindeki for dongusunun mantigi: neden karekok
//            siniri, neden <=, neden 3'ten baslayip ikiser artiyor.
//
// =====================================================================
// BOLUM 1: SATIR SATIR ACIKLAMA
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
// ---------- isPrime: bir sayinin asal olup olmadigini soyler ----------
// SATIR: bool isPrime(int num)
//   bool: sadece true (evet) ya da false (hayir) tutar. Bu fonksiyon bir
//   evet/hayir sorusunun cevabini geri verir: "num asal mi?". num: sorulan
//   sayi. Cagiran taraf isPrime(7) derse num 7 olur.
// SATIR: if (num < 2)
//   0, 1 ve negatif sayilar asal degildir, en basta elenir.
// SATIR: return false;
//   (num < 2 icin) Cevap "hayir". return cevabi verir ve fonksiyondan
//   HEMEN cikar, asagidaki satirlar bu sayi icin hic calismaz.
// SATIR: if (num == 2)
//   2 tek cift asal sayidir. Asagidaki cift sayi kontrolunden ONCE ozel
//   olarak ele alinir; siralari ters olsaydi 2 de cift diye elenirdi.
// SATIR: return true;
//   (num == 2 icin) Cevap "evet", fonksiyon biter. Suslu parantez yok,
//   if sadece bu tek satiri kontrol eder.
// SATIR: if (num % 2 == 0)
//   % kalani verir. Kalan 0 ise num, 2'ye tam bolunur, yani cifttir.
// SATIR: return false;
//   (cift sayilar icin) 2 disindaki cift sayilar asal degildir. Bu satirdan
//   sonrasina gelen her sayi artik TEKTIR.
// SATIR: for (int i = 3; (long long)i * i <= num; i += 2)
//   i: aday bolen. 3'ten baslar (sayi tek, bolen cift olamaz). Sart: i'nin
//   karesi num'u gecene kadar dene (karekok siniri). (long long)i: carpma
//   tasmasin diye i'yi once buyuk kutuya cevirir. i += 2: her turda i'ye
//   2 ekler, yani 3, 5, 7, 9, ... Bu satirin mantigi BOLUM 2'de.
// SATIR: if (num % i == 0)
//   Kalan 0 ise i, num'u tam boler: 1 ve kendisi disinda bir bolen
//   bulundu demektir.
// SATIR: return false;
//   (bolen bulundugunda) Cevap "hayir", fonksiyon ve dongu hemen biter.
//   Geri kalan adaylari denemeye gerek yok.
// SATIR: return true;
//   Bu satira ancak dongu sonuna kadar doner ve hic return false
//   calismazsa gelinir: hicbir aday bolmedi, sayi asaldir. Dongunun
//   DISINDA durmasi onemli: icinde olsaydi ilk bolmeyen adayda "asal"
//   derdi (9 icin i = 2 bolmez, yanlis cevap verirdi).
//
// ---------- primeNum: aralikta asallari yazar ve sayar ----------
// SATIR: int primeNum()
//   int: ekrana yazmanin yani sira bulunan asal adedini geri verir.
// SATIR: int num = 0;
//   Kullanicinin girecegi ust sinir (n) icin kutu. 0 ile baslatilir.
//   Bu num, isPrime icindeki num'dan BAGIMSIZ ayri bir kutudur (farkli
//   scope).
// SATIR: int counterPrime = 0;
//   Bulunan asallari sayan kutu. Henuz hic asal bulunmadigi icin 0.
// SATIR: cout << " Please enter the number for scope of the prime number :" << endl;
//   Kullaniciya mesaj yazar. endl satir sonu koyar.
// SATIR: cin >> num;
//   Klavyeden bir tam sayi okuyup num'a yazar. Kullanici Enter'a basana
//   kadar program bekler.
// SATIR: for (int i = 2; i <= num; ++i)
//   Dis dongu ADAY SAYILARI gezer: 2, 3, ... num (num dahil, <=). Burada
//   i aday sayidir; isPrime icindeki i ise aday BOLENdir, ayri kutulardir.
// SATIR: if (isPrime(i))
//   isPrime'a "i asal mi?" diye sorar. Cagri, geri verdigi true ya da
//   false ile yer degistirir, if ona bakar. Her aday icin bir kez sorulur.
// SATIR: cout << i << ", ";
//   Asal sayiyi yazar, ardindan ayirici ", " basar. Bu satir ve alttaki
//   if'in suslu parantezi icinde, ikisi de sadece asal sayida calisir.
// SATIR: ++counterPrime;
//   Asal bulundu, sayac bir artar.
// SATIR: cout << endl;
//   Dongu bittikten sonra bir kez calisir, alt satira gecer.
// SATIR: return counterPrime;
//   Bulunan asal adedini fonksiyonu cagirana geri verir. counterPrime
//   fonksiyonun yerel kutusudur, dis dunya ancak return ile ulasir.
//   Ekrana yazilan liste (2, 3, 5, 7) ile return edilen adet (4) ayri
//   seylerdir: cout insana gosterir, return koda verir.
//
// ---------- main ----------
// SATIR: int main()
//   Programin giris noktasi. Calisma buradan baslar.
// SATIR: int prime = primeNum();
//   primeNum calisir (n sorar, asallari yazar) ve geri verdigi adet prime
//   kutusuna konur. Cagri, return degeriyle yer degistirir: n = 10 icin
//   satir int prime = 4; gibi okunur.
// SATIR: cout << " Total prime number :" << prime << endl;
//   Geri gelen adedi yazdirir. Bilinen degerle (100 icin 25) karsilastirip
//   programin dogrulugunu kontrol edebilirsin. main'de return yazilmazsa
//   derleyici otomatik return 0 ekler.
//
// =====================================================================
// BOLUM 2: FOR DONGUSUNUN MANTIGI (nasil kuruldu, neden dogru)
// =====================================================================
// Satir: for (int i = 3; (long long)i * i <= num; i += 2)
//
// --- Amac ---
// num asal mi? 1 ve kendisi disinda TEK BIR bolen bulmak yeter. Bulursak
// asal degil, hic bulamazsak asal.
//
// --- Ilk fikir ---
//   for (int i = 2; i < num; ++i)
// 2'den num - 1'e kadar hepsini dene. Dogru calisir ama yavas: num = 97
// icin 95 deneme yapar.
//
// --- Gozlem: bolenler cift cift gelir ---
// 48'in bolen ciftleri:
//   1 x 48
//   2 x 24
//   3 x 16
//   4 x 12
//   6 x 8
//   8 x 6    <- ayni ciftler ters sirada tekrar basliyor
//   12 x 4
//   ...
// 6 x 8'den sonrasi tekrar. Karekok 48 icin yaklasik 6,9: tekrarin basladigi
// yer tam karekok. Yani karekoktan sonrasini denemek ayni ciftleri tersten
// bulmaktir. 36 ve 91 ile yazarsan donus noktasini yine karekokte gorursun.
//
// --- Ispat: kucuk bolen karekoku gecemez (celiski ile) ---
// num = a x b olsun. Diyelim ikisi de karekokten BUYUK:
//   a > karekok(num)  ve  b > karekok(num)
// O zaman:
//   a x b  >  karekok(num) x karekok(num)  =  num
// Ama a x b zaten num'a esit olmali. num > num olamaz, celiski. Demek ki
// iki bolenin ikisi birden karekokten buyuk olamaz: en az biri, yani kucuk
// olan, karekoku gecmez. Bu yuzden denemeyi karekokte durdurmak yeter,
// kucuk boleni mutlaka yakalariz.
//
// Dikdortgen gozuyle: alani num olan dikdortgenin kenarlari a ve b. Kenarlar
// esitse kare olur ve kenar tam karekok kadardir. Bir kenari karekokten
// uzun yaparsan alanin sabit kalmasi icin digerini kisaltman gerekir; iki
// kenar ayni anda uzun olamaz.
//
// --- Kodda yazilisi: i * i <= num ---
// "i <= karekok(num)" demek, sqrt kullanmadan: i'nin karesi num'u gecmedi.
// Carpma hizli ve ondalik hata icermez. Ornek: num = 97 icin i = 3, 5, 7, 9
// denenir (9 x 9 = 81 <= 97), i = 11'de 121 > 97 olur ve dongu biter. Toplam
// 4 deneme (ilk fikirde 95).
//
// --- Neden < degil <= ? (tam kare durumu) ---
// Normal sayida bolen ciftinin iki yani farklidir (91 = 7 x 13), karekok
// bolen degildir. Tam karede iki yan AYNI sayidir (49 = 7 x 7): kucuk bolen
// karekokun tam kendisidir. num = 49 icin:
//   i = 3 : i x i = 9   , 49 % 3 = 1 -> bolmuyor, devam
//   i = 5 : i x i = 25  , 49 % 5 = 4 -> bolmuyor, devam
//   i = 7 : i x i = 49  , 49 % 7 = 0 -> boldu, return false
// <= ile 49 <= 49 dogru oldugu icin i = 7 denenir ve 49 asal degil cikar.
// < yazilsaydi 49 < 49 yanlis olur, dongu i = 7'ye gelmeden biter, hic
// bolen bulunamaz ve return true ile 49'a "asal" denirdi.
// Bu hata sadece ASAL SAYININ KARESI olan sayilarda cikar: 9, 25, 49, 121,
// 169, ... 81 gibi sayilarda cikmaz, cunku 81'in 3 gibi daha kucuk bir
// boleni de vardir ve dongu onu i = 3'te erken yakalar.
//
// --- Neden i = 3'ten basliyor ve i += 2 ? ---
// Bu satira gelen num TEKTIR (ciftler yukarida elendi). Tek sayiyi hicbir
// cift sayi bolemez, o yuzden 2, 4, 6, ... denemek bosa. 3'ten baslayip
// ikiser ilerlenir: 3, 5, 7, 9, ... Is yaklasik yariya iner.
//
// --- Neden (long long)i ? ---
// int en fazla 2147483647 tutar. i = 46341 oldugunda i * i = 2147488281
// olur, int'e sigmaz ve tasar; sonuc anlamsizlasir. (long long)i yazinca
// carpma buyuk kutuda yapilir, tasma olmaz. Bu yuzden isPrime(2147483647)
// de dogru cevap (true) verir. Donusumu carpmadan ONCE, i uzerinde
// yapmak onemli: (long long)(i * i) olsaydi tasma parantez icinde zaten
// olmus olurdu.
//
// --- Toplam hiz ---
// Bir sayiyi test etmek en fazla karekok(num) / 2 tur surer. Tum aralik
// icin adim sayisi yaklasik n x karekok(n) mertebesindedir ve erken cikis
// sayesinde pratikte bundan da azdir. Ilk fikirdeki yaklasik n x n / 2
// adimdan cok daha hizlidir. n = 100000 icin ic dongu yaklasik 1,3 milyon
// tur doner, ilk fikirde yaklasik 5 milyar.

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson10_primelogic.cpp -o program
