#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "programlari";

	// C++ programi kodlamak cok zevkli!

	s.insert(0, "C++ ");
	s.erase(11, 3);
	s.append(" yazmak cok zevkli!");
	s.replace(12, 7, " kodlamak");

	cout << s << endl;   // C++ programi kodlamak cok zevkli!
	cout << s.substr(0, 10) << endl;   // C++ progra
	cout << "Uzunluk: " << s.length() << endl;   // 33
	cout << "bir karakter: " << s.at(s.length() - 1) << endl;   // bir karakter: !

	return 0;
}

// ============================================================
// KODUN ACIKLAMASI
// ============================================================
//
// Hedef metin yorumda yazili: "C++ programi kodlamak cok zevkli!".
// Dort islem ARDISIK uygulanir ve her biri s'nin KENDISINI degistirir.
// Bu yuzden her satirdaki indeksler, bir onceki satirdan cikan metne gore
// hesaplanir.
//
// SATIR: string s = "programlari";
// 11 karakter. Indeksler: p0 r1 o2 g3 r4 a5 m6 l7 a8 r9 i10.
//
// SATIR: s.insert(0, "C++ ");
// 0. indeksin onune "C++ " (4 karakter, sondaki bosluk dahil) sokar.
// Sonuc: "C++ programlari" (15 karakter). Butun harfler 4 saga kayar:
// p artik 4. indekste, l 11., a 12., r 13., i 14.
//
// SATIR: s.erase(11, 3);
// erase(pos, len): 11. indeksten 3 karakter siler. Yeni indekslere gore
// 11, 12, 13 = "lar". Sonuc: "C++ programi" (12 karakter).
// (Ayni satirda eski metne gore 7 yazsaydik yanlis yeri silerdik.)
//
// SATIR: s.append(" yazmak cok zevkli!");
// Sona ekler: "C++ programi yazmak cok zevkli!". Metnin basindaki bosluk,
// "programi" ile "yazmak" arasindaki bosluktur.
//
// SATIR: s.replace(12, 7, " kodlamak");
// replace(pos, len, metin): 12. indeksten 7 karakteri silip yerine metni
// koyar. 12. indeks "programi"dan sonraki bosluktur; 12'den 7 karakter
// " yazmak" olur (bosluk + 6 harf). Yerine 9 karakterlik " kodlamak" girer.
// Silinen ve eklenen uzunluk ayni olmak zorunda degil. Sonuc:
// "C++ programi kodlamak cok zevkli!".
//
// SATIR: cout << s.substr(0, 10) << endl;
// substr(pos, len): 0. indeksten 10 karakter, YENI bir string dondurur,
// s degismez. Karakterler: C + + bosluk p r o g r a = "C++ progra".
//
// SATIR: cout << "Uzunluk: " << s.length() << endl;
// 12 ("C++ programi") + 9 (" kodlamak") + 12 (" cok zevkli!") = 33.
//
// SATIR: cout << "bir karakter: " << s.at(s.length() - 1) << endl;
// Indeksler 0'dan basladigi icin son karakterin indeksi length() - 1'dir
// (32). Metnin uzunlugunu bilmeden son karakteri bu kaliple alirsin: '!'.
// at() sinir kontrolu yapar; length() 0 olsaydi -1 isaretsiz sayida buyuk
// bir degere donusurdu ve at() out_of_range firlatirdi.

// COMPILE: g++ -std=c++17 -Wall -Wextra lesson10_stringops.cpp -o program
