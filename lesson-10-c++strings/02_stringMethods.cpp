#include <iostream>
#include <string>
using namespace std;

int main() {

	string meyve = "elma";

	cout << "Uzunluk: " << meyve.length() << endl;
	cout << "Ilk harf: " << meyve.at(0) << endl;

	meyve.append(" suyu");
	cout << "Append ile: " << meyve << endl;

	string yeni = meyve + " guzeldir";
	cout << "Birlestirme: " << yeni << endl;

	// elma suyu guzeldir
	cout << "Parca1 (substr): " << yeni.substr(0, 4) << endl;
	string metin = yeni.substr(5, 4);
	cout << metin << endl;

	size_t pos = yeni.find("suzel");
	if (pos != string::npos)
		cout << "aranan metin bulundu. Pozisyon: " << pos << endl;
	else
		cout << "aranan metin bulunamadi!\n";

	yeni.erase(5, 5);
	cout << "Erase sonrasi: " << yeni << endl;

	// elma guzeldir
	yeni.insert(4, " TAZE");
	cout << "Insert sonrasi: " << yeni << endl;

	// elma TAZE guzeldir
	yeni.replace(0, 4, "portakal");
	cout << "Replace sonrasi: " << yeni << endl;

	return 0;
}

// ============================================================
// KODUN ACIKLAMASI
// ============================================================
//
// Hepsi std::string'in uye fonksiyonlaridir. Ortak kural: indeksler 0'dan
// baslar ve "pozisyon, adet" (pos, len) sirasiyla verilir.
//
// SATIR: cout << "Uzunluk: " << meyve.length() << endl;
// Karakter sayisini verir (4). size() ile ayni isi yapar. C tipi dizideki
// gibi '\0' sayilmaz, string uzunlugu kendi icinde saklar: O(1).
//
// SATIR: cout << "Ilk harf: " << meyve.at(0) << endl;
// 0. indeksteki karakteri verir ('e'). meyve[0] ile ayni sonucu verir ama
// at() sinir kontrolu yapar: gecersiz indekste std::out_of_range exception
// firlatir. [] ise kontrol etmez, sinir disi erisim undefined behavior olur.
//
// SATIR: meyve.append(" suyu");
// meyve'nin KENDISINI degistirir, sonuna " suyu" ekler: "elma suyu".
// meyve += " suyu"; ile esdegerdir.
//
// SATIR: string yeni = meyve + " guzeldir";
// + operatoru YENI bir string uretir. meyve degismez ("elma suyu" kalir),
// yeni = "elma suyu guzeldir" olur. append ile farki: append yerinde
// degistirir, + kopya uretir.
//
// SATIR: cout << "Parca1 (substr): " << yeni.substr(0, 4) << endl;
// substr(pos, len): pos'tan baslayip len karakter alir ve YENI bir string
// dondurur, yeni degismez. substr(0, 4) = "elma".
// Ikinci parametre bitis indeksi DEGIL, uzunluktur.
//
// SATIR: string metin = yeni.substr(5, 4);
// 5. indeksten 4 karakter: "elma suyu guzeldir" icinde index 5 = 's',
// sonuc "suyu". (Index 4 bosluktur.)
//
// SATIR: size_t pos = yeni.find("suzel");
// find, aranan metnin ILK bulundugu indeksi dondurur. Bulamazsa
// string::npos dondurur. size_t isaretsiz (unsigned) bir tamsayidir,
// bu yuzden donus degeri int'e degil size_t'ye yazilir.
//
// SATIR: if (pos != string::npos)
// string::npos, size_t'nin alabilecegi en buyuk degerdir ("bulunamadi"
// isareti). Burada "suzel" metni "elma suyu guzeldir" icinde gecmedigi
// icin kosul yanlis olur ve else kolu calisir.
//
// SATIR: yeni.erase(5, 5);
// erase(pos, len): 5. indeksten 5 karakteri siler: "suyu " gider.
// "elma suyu guzeldir" -> "elma guzeldir". yeni'nin kendisi degisir.
//
// SATIR: yeni.insert(4, " TAZE");
// insert(pos, metin): 4. indeksin ONUNE metni sokar, sagdaki karakterler
// kayar: "elma guzeldir" -> "elma TAZE guzeldir".
//
// SATIR: yeni.replace(0, 4, "portakal");
// replace(pos, len, metin): pos'tan len karakteri silip yerine metni koyar.
// Yeni metnin uzunlugu eski parcayla ayni olmak zorunda degil:
// 4 karakter ("elma") gider, 8 karakter ("portakal") girer.
// Sonuc: "portakal TAZE guzeldir".

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson10_stringmethods.cpp -o program
