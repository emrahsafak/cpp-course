#include <iostream>

using namespace std;

int main()
{
	int dogumYili = 1980; 
	string isim = "Kaan Kaya";
	float sayisalNotOrtalamasi = 3.47f;
	double pi = 3.14159265359;
	bool sinifiGectiMi = false;
	//char notOrtalamasiHarf = 'B'; // char da tek tırnak kullanılır, " ASCII " tablosundan faydalanarak rakamda verilebilir - "char notOrtalamasiHarf = 65;"  örnek 65-A 66-B 67-C 68-D tekabül eder.
	 char notOrtalamasiHarf = 68;
	



	cout << "Merhaba sayin" << isim << endl;
	cout << "Dogum Yili: " << dogumYili << endl;
	cout << "Sayisal Not Ortalamasi: " << sayisalNotOrtalamasi << endl;
	cout << "Pi nin sayisal degeri: " << pi << endl;
	cout << "Sinifi Gectiniz mi? " << sinifiGectiMi << endl;
	cout << "Not Ortalamasi " << notOrtalamasiHarf << endl;




     return 0;
 
}
