// ============================================================
//  KONU: Visual Studio Debugger Mantığı
//  KOD : break örneği — çıktı: 0  1  2
// ============================================================

#include <iostream>
using namespace std;

int main()
{
    // ── BREAKPOINT NEDİR? ─────────────────────────────────────
    //
    //  Satırın soluna F9 basarsan kırmızı nokta çıkar → Breakpoint
    //  Program o satıra gelince DONAR ve seni bekler.
    //
    //  Neden lazım?
    //  Program normalde milisaniyede biter, hiçbir şey göremezsin.
    //  Breakpoint ile istediğin satırda durdurup inceleyebilirsin.
    //
    //  ● ← bu kırmızı nokta ekran görüntüsündeki breakpoint

    for (int i = 0; i <= 5; i++)   // ← buraya F9 bas, breakpoint koy
    {
        // ── SARI OK NEDİR? ───────────────────────────────────
        //
        //  Debugger çalışırken satırın solunda sarı ok görürsün →
        //  O ok = "CPU şu an bu satırı işlemek ÜZERE" demektir.
        //  Henüz çalışmadı. Bir sonraki F10'da çalışacak.

        if (i == 3)
            break;        // i=3'te döngü tamamen biter → çıktı: 0 1 2

        cout << i << "    ";
    }

    return 0;
}

// ============================================================
//  DEBUGGER TUŞLARI
//
//  F9          →  Breakpoint koy / kaldır
//  F5          →  Programı başlat veya breakpoint'ten devam et
//  F10         →  Bir sonraki satıra geç (Step Over)
//  F11         →  Fonksiyonun içine gir  (Step Into)
//  Shift+F5    →  Debugger'ı tamamen durdur
//
// ── NASIL KULLANIRSIN? ───────────────────────────────────────
//
//  1. for satırına F9 bas        →  breakpoint koy
//  2. F5 bas                     →  program o satırda DURUR
//  3. F10'a basmaya devam et     →  satır satır ilerle
//  4. Sol altta "Locals" bak     →  i değişkenini canlı izle
//
//  Locals Penceresi — En Güçlü Özellik:
//  Her F10'da 'i' nin değeri canlı değişir:
//  i = 0 → 1 → 2 → 3 (break!) 
//  Döngünün tam olarak nerede ne yaptığını gözlerinle görürsün.
//
//  Debugger = Programın X-ray'i.
//  Kod çalışırken içine bakmanı sağlar.
//  Her bug'ı bununla bulacaksın.
// ============================================================
