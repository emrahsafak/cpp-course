#include <iostream>
using namespace std;

int main()
{

     int sicaklik = 31;

     if (sicaklik < 0)                         
     {
	     cout << "Hava cok soguk!" << endl;    // eger  hava 0 dan kucukse cok soguk yazdirir, diger satirlara ugramadan cout
     }
     else if (sicaklik >= 0 && sicaklik < 15) 
     {
	     cout << "Hava soguk!" << endl;        // ya da  0 - 15 arasindaysa soguk yazdir
     }
      else if (sicaklik >= 15 && sicaklik < 25) 
     {
	     cout << "Hava normal!" << endl;       // ya da 15 - 25 arasindaysa normal yazdir
     }
     else if (sicaklik >= 25 && sicaklik < 35) 
     {
	     cout << "Hava sicak!" << endl;        // ya da 25 - 35 arasindaysa sicak yazdir
     }
     else 
     {
	     cout << "Hava cok sicak!" << endl;    // degilse ( 35 den buyukse ) cok sicak yazdir
     }

    return 0;
}

