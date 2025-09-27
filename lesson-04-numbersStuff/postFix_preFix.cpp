#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// POSTFIX
 /*
	
	//x = x + 1;
	x++;  // Artırma operatörü (Postfix)

	cout << x << endl;

	int y = 10;
	//y = y - 1;
	y--;  // Azaltma operatörü (Postfix)

	cout << y << endl;
 */


	//PREFIX

   /*
	int x = 7;
	++x;

	cout << x << endl;

	int y = 10;
	--y;
   */

   

	// Prefix ( ++x ve --x ) ile Potsfix ( x++ ve x-- ) Arasındaki Fark
	//1. Postfix ( x++ ) => ++ veya -- degiskenin sagindaysa buna postfix denir
	//
	//Degiskenin onceki degeri kullanılır, ardından degeri 1 artirilir. 

	int a = 7;
	int b = a++;
	cout << "a:" << a << endl;		
	cout << "b:" <<	b << endl;
	// ( a = 8 , b =7 )
	

	// Prefix (++x) => ++ veya -- degişkenin solundaysa buna prefix denir.
	//
	// Değişkenin değeri önce artırılır, ardından kullanılır.
	//Ör.
	
	 int x = 7;
	 int y = --x;
	 cout << "x:" << x << endl;
	 cout << "y:" << y << endl;
	 // ( x = 6 , y = 6 )
	

     return 0;
 
}
