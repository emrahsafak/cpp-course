#include <iostream>

using namespace std;

int main()
{
/* Bu kod ekrana merhaba vb.bir metin yazar */
string isim; //  noun declaration
isim = "Emrah"; // noun initialization

int yas = 20; // integer declaration + initialization


/*
   Degisken verdigimiz zaman sayilarda ( int veri tipi ) tirnak isaretleri ile ugrasilmaz fakat isimlerde (string veri tipi) tirnak isareti ile cevreleyip belirtmemiz gerekir.
*/


cout << "Bir zamanlar " << isim << " isminde bir genc varmis" << endl << isim << " " << yas << " yasindaymis." << endl;
cout << isim << " ismini severmis fakat " <<  yas  << " yasini sevmezmis.\n";

/*
Degiskenimize yeni bir veri atarsak bu atadigimiz satirdan sonra yeni verimiz kullanilmaya baslar (!! Ancak yeni bir degisken atamak istedigimiz zamanlarda string (isimler icin) ve int (sayilar icin) kullanılarak yeni degisken atanır
*/

isim = "Melo";
yas  = 14;
cout << isim << " ismini sever ancak " << yas << " yasinda olmak istermis. \n ";



return 0;
