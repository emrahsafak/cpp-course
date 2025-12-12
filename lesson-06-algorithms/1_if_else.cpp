#include <iostream>

using namespace std;

int main() 
{
	int sifre = 1234;
  
	int girilenSifre;
	cout << "Lutfen sifrenizi giriniz: ";
	cin >> girilenSifre;
	
  if (girilenSifre == sifre) // eger girilen sifre sifreye esitse bunu yap.
	{
		cout << "Sifre dogru, hosgeldiniz!" << endl;
	}
	else // aksi takdirde bunu yap 
	{
		cout << "Yanlis sifre, lutfen tekrar deneyiniz." << endl;
	}
}
