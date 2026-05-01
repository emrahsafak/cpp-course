#include <iostream>
using namespace std;

int main()
{
	/* 
	  Soru: Kullanıcıdan başlangıç ve bitiş sayısını alarak, bu sayılar arasında bulunan ve 7'ye tam bölünebilen sayıları ekrana yazdıran bir program yazınız.  	
	*/ 
	
	int baslangicSayi, bitisSayi;
	cout << " Baslangic sayinizi giriniz :";
	cin >> baslangicSayi;
	cout << " Bitis sayinizi giriniz : ";
	cin >> bitisSayi;

	while (baslangicSayi <= bitisSayi)
	{
		cout << baslangicSayi << endl;

		if (baslangicSayi % 7 == 0)
		{
			cout << baslangicSayi << "sayisi 7'ye tam bolunur." << endl;
		}

		baslangicSayi++;

	}
    
}

