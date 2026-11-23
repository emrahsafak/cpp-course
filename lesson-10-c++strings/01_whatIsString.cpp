#include <iostream>
#include <string>
using namespace std;

int main() {

	char mesaj[] = "Merhaba";
	cout << mesaj << endl;

	// Uzunluğunu hesaplayaım
	int uzunluk = 0;
	while (mesaj[uzunluk] != '\0') {
		uzunluk++;
	}

	cout << "Uzunluk: " << uzunluk << endl;

	// mesaj.append(" C++");
	string yeniMesaj = string(mesaj);
	yeniMesaj.append(" C++");
	cout << yeniMesaj << endl;

	string mystr = "Hello";
	mystr.append(" C++");
	cout << mystr << endl;

	return 0;
}

// ============================================================
// KODUN ACIKLAMASI
// ============================================================
//
// SATIR: char mesaj[] = "Merhaba";
// Bu bir C tipi string: sonu '\0' (null karakter) ile biten char dizisi.
// [] bos birakildi, boyutu derleyici hesaplar: 7 harf + 1 gizli '\0' = 8 bayt.
// Literal diziye KOPYALANIR, yani mesaj degistirilebilir bir dizidir.
//
//   indeks:  0    1    2    3    4    5    6    7
//   deger :  M    e    r    h    a    b    a   '\0'
//
// SATIR: cout << mesaj << endl;
// cout bir char dizisini gorunce '\0' gorene kadar karakterleri yazar.
// Dizi kendi uzunlugunu tutmaz; '\0' tek "burada bitti" isaretidir.
//
// SATIR: int uzunluk = 0;
// Hem sayac hem de o an baktigimiz indeks olarak kullanilir.
//
// SATIR: while (mesaj[uzunluk] != '\0') {
// '\0' gorene kadar ilerler. uzunluk 7 olunca mesaj[7] == '\0' olur ve
// dongu biter; sonuc 7. strlen() tam olarak bu isi yapar: her seferinde
// bastan sayar, yani O(n). (sizeof(mesaj) ise 8'dir, '\0' dahil.)
//
// SATIR: // mesaj.append(" C++");
// Yorumdan cikarilirsa derlenmez. char dizisi bir sinif degil, ham veridir;
// .append gibi uye fonksiyonu yoktur. Ayrica 8 baytlik sabit alan buyuyemez.
//
// SATIR: string yeniMesaj = string(mesaj);
// string(mesaj): char dizisinden bir std::string nesnesi kurar, '\0'a kadar
// olan karakterleri KOPYALAR. yeniMesaj bagimsiz bir kopyadir; mesaj sonradan
// degisse yeniMesaj etkilenmez. "string yeniMesaj = mesaj;" da ayni isi yapar.
//
// SATIR: yeniMesaj.append(" C++");
// std::string'in uye fonksiyonudur, sona " C++" ekler. Yer yetmezse string
// kendi icinde daha buyuk bellek ayirir, kopyalar, eskisini birakir; bunu
// sen yonetmezsin. yeniMesaj += " C++"; ile esdegerdir.
//
// SATIR: string mystr = "Hello";
// Literal dogrudan string'e verilir, aradaki char dizisine gerek kalmaz.
//
// SATIR: mystr.append(" C++");
// Ayni append mantigi. string kendi uzunlugunu sakladigi icin size() O(1),
// char dizisinde ise uzunluk her seferinde sayilarak bulunur.

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson10_cstring.cpp -o program
