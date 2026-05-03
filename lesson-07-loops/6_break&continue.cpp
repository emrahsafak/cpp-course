// ============================================================
//  KONU: continue vs break
//  ÖRNEK: 0'dan 5'e kadar say, 3'e gelince ne olur?
// ============================================================

#include <iostream>
using namespace std;

int main()
{
    // ── CONTINUE ─────────────────────────────────────────────
    // "Bu turu atla, döngüye devam et"
    // 3'ü atlar ama 4 ve 5'i yazmaya devam eder

    cout << "CONTINUE: ";

    for (int i = 0; i <= 5; i++)
    {
        if (i == 3)
            continue;    // i=3 ise cout'a gitme, i++'a dön

        cout << i << "  "; // Sadece 3 değilse buraya ulaşır
    }

    // Çıktı → 0  1  2  4  5
    //                    ↑
    //               3 burada yok, ama 4 ve 5 var

    cout << endl;


    // ── BREAK ────────────────────────────────────────────────
    // "Döngüyü tamamen bitir, çık"
    // 3'e gelince döngü ölür, 4 ve 5 hiç çalışmaz

    cout << "BREAK:    ";

    for (int i = 0; i <= 5; i++)
    {
        if (i == 3)
            break;       // i=3 ise döngüden tamamen çık

        cout << i << "  "; // i=3'ten sonra buraya hiç ulaşılmaz
    }

    // Çıktı → 0  1  2
    //                 ↑
    //            3, 4, 5 yok — döngü 3'te öldü

    cout << endl;


    // ── ÖZET ─────────────────────────────────────────────────
    //
    //  continue  →  "Bu adımı atla, koşmaya devam et"
    //  break     →  "Koşuyu tamamen bırak, eve dön"
    //
    //  ADIM ADIM (i=3 anı):
    //
    //  continue:                    break:
    //  i=3 → if true                i=3 → if true
    //    → continue                   → break
    //    → i++ çalışır (i=4)          → i++ ÇALIŞMAZ
    //    → döngü devam eder           → döngü tamamen biter
    //    → 4 ve 5 yazılır             → 4 ve 5 hiç çalışmaz

    return 0;
}
