// Bir öğrenci yönetim sistemi programı üzerinde çalışıyorsunuz. Öğrencilerin aldığı notları bir dizi (array) içinde tutuyorsunuz 
// ve bu notların ortalamasını hesaplayıp ortalamanın üzerinde olan not sayısını bulup dönen fonksiyon yaziniz?
// Örneğin: Öğrenci notları şu şekilde olsun: int notlar[] = {85, 78, 90, 66, 88, 72, 95, 80, 84, 77};
// Bu dizi için ortalamanın üzerinde olan not sayısını 5 olarak bulmalıdır.


#include <iostream>
using namespace std;

int ortalamaUzeriNotlar(int notlar[], int uzunluk)
{
	int toplam = 0;
	for (int i = 0; i < uzunluk; ++i)
	{
		toplam += notlar[i];
	}

	double ortalama = (double)toplam / uzunluk;
	int sayac = 0;

	for (int i = 0; i < uzunluk; ++i)
	{
		if (notlar[i] > ortalama)
		{
			++sayac;
			cout << "Ortalama uzeri not sayisi : "<< sayac << ". Not: " << notlar[i] << endl;
		}
	}

	return sayac;
}

int main()
{

	int notlar[] = { 50, 60, 70, 80, 90, 100, 40, 30, 20, 10 };
	int uzunluk = sizeof(notlar) / sizeof(notlar[0]);

	
	ortalamaUzeriNotlar(notlar, uzunluk);

}

// SORU:
// Ogrenci notlari bir dizide tutuluyor. Notlarin ortalamasini hesaplayip
// ortalamanin uzerinde olan not sayisini bulan ve donduren bir fonksiyon yaz.
// Ornek: { 85, 78, 90, 66, 88, 72, 95, 80, 84, 77 } -> ortalama 81.5, sonuc 5

// KODUN ACIKLAMASI
// SATIR: int ortalamaUzeriNotlar(int notlar[], int uzunluk)
//   Fonksiyon main'den ONCE ve ayri yazilir (C++'ta fonksiyonun icinde
//   fonksiyon tanimlanamaz). int notlar[] parametresi aslinda int* demektir:
//   dizinin kopyasi degil ilk elemaninin adresi gelir. Adres eleman sayisini
//   tasimadigi icin uzunluk ayri parametre olarak verilir. Donus tipi int,
//   sayac degerini geri verir.
// SATIR: int toplam = 0;
//   Toplayici. Baslangic degeri 0 verilmezse icinde cop deger olur.
// SATIR: for (int i = 0; i < uzunluk; ++i)
//   Klasik for, index gerekli degil ama dizi uzunlugu parametreden geldigi
//   icin bu yazim da dogru. Sinir < uzunluk: gecerli indexler 0 ... uzunluk-1.
//   <= yazilsaydi notlar[uzunluk] okunur, dizi disina cikilirdi (UB).
// SATIR: toplam += notlar[i];
//   toplam = toplam + notlar[i] ile ayni. Her turda bir not toplama eklenir.
// SATIR: double ortalama = (double)toplam / uzunluk;
//   (double)toplam toplami ondalikli sayiya cevirir. Cevrilmeseydi iki int
//   bolunecek ve ondalik kisim atilacakti (ornegin 815 / 10 icin 81.5
//   yerine 81 cikardi). Ondalikli bolme niyeti acik olsun diye
//   double kullaniyoruz.
// SATIR: int sayac = 0;
//   Ortalama ustu not sayisini tutar.
// SATIR: if (notlar[i] > ortalama)
//   int ile double karsilastirilir, int otomatik double'a cevrilir. Esit
//   olan not ortalamanin ustu sayilmaz (> kullanildi, >= degil).
// SATIR: ++sayac;
//   Sartin saglandigi her notta sayaci 1 artirir.
// SATIR: cout << "Ortalama uzeri not sayisi : "<< sayac << ". Not: " << notlar[i] << endl;
//   Ortalama ustu notu, kacinci oldugunu belirterek ekrana yazar.
// SATIR: return sayac;
//   Sayaci cagirana geri verir. Fonksiyon burada biter.
// SATIR: int uzunluk = sizeof(notlar) / sizeof(notlar[0]);
//   Eleman sayisi main'de hesaplanir cunku orada notlar gercek dizidir.
//   sizeof(notlar) = 40 bayt, sizeof(notlar[0]) = 4 bayt, sonuc 10.
//   Fonksiyonun icinde bu hesap yanlis olurdu (pointer boyutu cikardi).
// SATIR: ortalamaUzeriNotlar(notlar, uzunluk);
//   Dizi fonksiyona adres olarak gider (kopyalanmaz). Donen deger burada
//   kullanilmiyor, cunku sonuc fonksiyonun icinde yazdiriliyor.
//   Bu dizi icin ortalama 55, ustundekiler: 60 70 80 90 100 (5 tane).

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson10_averageAbove.cpp -o program

