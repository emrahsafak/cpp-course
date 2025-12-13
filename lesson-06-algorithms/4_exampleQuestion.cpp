#include <iostream>

using namespace std;

int main()
{
	//Kullanicidan 3 tam sayi girisi alan ve bu girdilerden en buyugunu ekrana yazdiran program

		int sayi1, sayi2, sayi3,enbuyuk;
		cout << "Lutfen 3 adet sayi giriniz: ";
		cin >> sayi1 >> sayi2 >> sayi3;

		if (sayi1 >= sayi2 && sayi1 >= sayi3)
		{
			enbuyuk = sayi1;
		}
		else if (sayi2 >= sayi1 && sayi2 >= sayi3)
		{
			enbuyuk = sayi2;
		}
		else
		{
			enbuyuk = sayi3;
		}
		cout << "En buyuk sayi :" << enbuyuk << endl;

		return 0;

}
