// ============================================================
//  KONU : Visual Studio Debugger Mantigi
//  KOD  : break ornegi -> cikti: 0  1  2
// ============================================================

#include <iostream>
using namespace std;   // Ogrenme asamasinda sorun degil.
                       // Buyuk projelerde std::cout yazilir.

int main()
{
    // -- BREAKPOINT NEDIR? -----------------------------------
    //
    //  Imlec satirdayken F9'a bas (ya da satirin soluna tikla)
    //  -> kirmizi nokta cikar = Breakpoint.
    //  Program o satira gelince, satir CALISMADAN HEMEN ONCE durur.
    //
    //  Neden lazim?
    //  Program normalde milisaniyede biter, hicbir sey goremezsin.
    //  Breakpoint ile istedigin satirda durdurup inceleyebilirsin.

    for (int i = 0; i <= 5; i++)   // <- buraya F9 bas, breakpoint koy
    {
        // -- SARI OK NEDIR? ----------------------------------
        //
        //  Debugger calisirken satirin solunda sari ok gorursun.
        //  Ok = "CPU siradaki islemi bu satirda yapacak".
        //  Yani o satir HENUZ calismadi. Sonraki F10'da calisir.

        if (i == 3)
            break;   // i=3 oldugunda dongu tamamen biter.
                     // cout o tur calismaz -> 3 BASILMAZ.

        cout << i << "    ";
    }

    // Cikti: 0    1    2
    // break OLMASAYDI: 0    1    2    3    4    5

    return 0;   // main'in dondurdugu 0 = isletim sistemine "basarili" der
}

// ============================================================
//  DEBUGGER TUSLARI
// ============================================================
//
//  | Tus         | Ne yapar                                        |
//  |-------------|-------------------------------------------------|
//  | F9          | Breakpoint koy / kaldir                         |
//  | F5          | Debugger'i baslat / breakpoint'ten devam et     |
//  | Ctrl+F5     | Debugger'siz calistir (konsol acik kalir)       |
//  | F10         | Step Over: fonksiyon cagrisini tek adimda gec   |
//  | F11         | Step Into: fonksiyonun icine gir                |
//  | Shift+F11   | Step Out: icinde oldugun fonksiyondan cik       |
//  | Shift+F5    | Debugger'i tamamen durdur                       |
//
// ── NASIL KULLANIRSIN? ───────────────────────────────────────
//
//  1. for satirina F9 bas      -> breakpoint koy
//  2. F5 bas                   -> program o satirda DURUR
//  3. F10'a basmaya devam et   -> satir satir ilerle
//  4. Alttaki Locals/Autos'a bak -> i degiskenini canli izle
//
//  Her F10'da 'i' canli degisir:
//  i = 0 -> 1 -> 2 -> 3 (break! cout calismaz, dongu biter)
//
// ── LOCALS vs AUTOS ──────────────────────────────────────────
//
//  Locals : fonksiyondaki TUM yerel degiskenleri gosterir.
//  Autos  : sadece su anki ve onceki satirda gecen isimleri gosterir.
//
// ── BASLATILMAMIS DEGISKEN UYARISI ───────────────────────────
//
//  Bir degiskenin satiri henuz calismadiysa, debugger'da
//  gordugun deger BELIRSIZDIR (onceden bellekte kalan cop).
//  0 gormen, degiskenin 0 oldugu anlamina gelmez.
//  Cozum: degiskeni tanimladigin anda ilkle (int x = 0;).
//
// ── KUCUK NOT ────────────────────────────────────────────────
//
//  for'un 3. kisminda i++ ile ++i ayni sonucu verir, cunku
//  ifadenin degeri kullanilmiyor. Fark yalnizca sonucu bir
//  yerde kullandiginda ortaya cikar (b = a++ ile b = ++a gibi).
//
//  Debugger = Programin X-ray'i.
//  Kod calisirken icine bakmani saglar.
// ============================================================
