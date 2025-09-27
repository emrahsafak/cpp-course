/*  
    C++ TAMAMLAYICI KODLAMA EGZERSİZİ 

	Kullanıcıdan 3 adet sınav notu alınız (Sınav notları tam sayı şeklinde olmalı).
	Daha sonra bu notların ortalamasını bulup ekrana aş. gibi 2 şekilde yazdırsın:

       I) double olarak küsüratlı ( noktadan sonra 2 digit hassasiyet olsun )

	   II) Sonucu tamsayı olarak yazdırsın , yuvarlama yapsın, mesela not 84.5 => 85 
                                                                             84.49 => 84	                                                                            


*/


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
	int sinav1, sinav2, sinav3;

	cout << " Lutfen 3 adet sinav notu giriniz. " << endl;
	cin >>sinav1>>sinav2>>sinav3;

    double ortalama = (double)(sinav1 + sinav2 + sinav3) / 3.0; // ya 3.0 diye ya da double ort = (double) diye cast etmek gerekir. 

	// I) Ondalikli sekilde, 2 basamak hassasiyetle yazdır
	cout << "I) Ortalama (ondalikli): " << fixed << setprecision(5) << ortalama << endl;

	int sonuc = round(ortalama);
	// II) Yuvarlama yaparak tam sayı sonuc
	cout << " Ortalama (yuvarlamali, tamsayi):	" << sonuc  << endl;





    return 0;
}
