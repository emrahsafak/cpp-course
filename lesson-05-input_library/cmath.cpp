#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	
	int sonuc,x, y;
	cout << " Lutfen ussu alinacak sayiyi giriniz x: " << endl;
	cin >> x;
	cout << " Lutfen ussun degerini giriniz y: " << endl;
	cin >> y;
	sonuc = pow(x, y);
	cout << " sonuc: " << sonuc << endl;
	
	

	int sonuc1;
	sonuc1 = floor(2.7);
	cout << " sonuc1 " << sonuc1 << endl;
	// floor kendinden küçük en yakın tam sayıya yuvarlar.

	int sonuc2;
	sonuc2 = ceil(2.1);
	cout << " sonuc2 " << sonuc2 << endl;
	// ceil kendinden büyük en yakın tam sayıya yuvarlar.

	int sonuc3, sonuc4;
	sonuc3 = round(2.5);
	sonuc4 = round(2.4);
	cout << " sonuc3 " << sonuc3 << endl;
	cout << " sonuc4 " << sonuc4 << endl;
	// round kendine yakın büyük ya da küçük tam sayıya yuvarlar.

    return 0;
}
