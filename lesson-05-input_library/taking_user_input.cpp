#include <iostream>

using namespace std;

int main() 
{
	string isim;
	int en, boy, alan;

	cout << " Lutfen adinizi yaziniz ";
	cin >> isim;

	cout << " Merhaba " << isim << " Geometrik hesaplama programina hosgeldin\n";
	cout << " Lutfen dikdörtgenin enini giriniz ";
	cin >> en;

	cout << " Lutfen dikdörtgenin boyunu giriniz ";
	cin >> boy;

	// Hesaplama İşlemi
	
	alan = boy * en;

	cout << "Islem sonucunuz " << alan << " Sayin " << isim << endl;

    return 0;
}
