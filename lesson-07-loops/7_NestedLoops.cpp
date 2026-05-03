// ============================================================
//  KONU : İç İçe Döngüler (Nested Loops)
//  GİRİŞ: sayi = 5
//  ÇIKTI:
//  1
//  2 2
//  3 3 3
//  4 4 4 4
//  5 5 5 5 5
// ============================================================


// ── KODUN KENDİSİ ────────────────────────────────────────────

#include <iostream>
using namespace std;

int main()
{
    int sayi;
    cout << "Lutfen bir sayi giriniz: ";
    cin >> sayi;

    for (int j = 1; j <= sayi; j++)
    {
        for (int i = 1; i <= j; i++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}


// ============================================================
//  AÇIKLAMA — ADIM ADIM
// ============================================================
//
//
//  ── DEĞİŞKENLER ─────────────────────────────────────────────
//
//  sayi  →  kullanıcıdan alınan sayı. Örnek: 5
//  j     →  dış döngü değişkeni. Hangi SATIRDA olduğumuzu tutar.
//  i     →  iç döngü değişkeni. O satırda kaç kere yazacağımızı SAYAR.
//
//
//  ── DIŞ DÖNGÜ ───────────────────────────────────────────────
//
//  for (int j = 1; j <= sayi; j++)
//
//  j = 1 den başlar, sayi'ye (5) kadar gider.
//  Her j değeri = bir satır demektir.
//  j=1 → 1. satır
//  j=2 → 2. satır
//  j=3 → 3. satır
//  j=4 → 4. satır
//  j=5 → 5. satır
//
//
//  ── İÇ DÖNGÜ ────────────────────────────────────────────────
//
//  for (int i = 1; i <= j; i++)
//
//  i = 1 den başlar, j'ye kadar gider.
//  Yani j kaç ise, iç döngü o kadar döner.
//  j=1 → i: 1           → 1 kere döner
//  j=2 → i: 1, 2        → 2 kere döner
//  j=3 → i: 1, 2, 3     → 3 kere döner
//
//  ÖNEMLİ: cout << j yazar, i değil!
//  i sadece SAYICI görevi görür, ekrana j yazılır.
//
//
//  ── ADIM ADIM TAM İZLEME ────────────────────────────────────
//
//  j=1:
//    i=1 → (1<=1) TRUE  → "1 " yazar
//    i=2 → (2<=1) FALSE → iç döngü biter
//    endl → alt satıra geç
//    EKRAN: 1
//
//  j=2:
//    i=1 → (1<=2) TRUE  → "2 " yazar
//    i=2 → (2<=2) TRUE  → "2 " yazar
//    i=3 → (3<=2) FALSE → iç döngü biter
//    endl → alt satıra geç
//    EKRAN: 2 2
//
//  j=3:
//    i=1 → (1<=3) TRUE  → "3 " yazar
//    i=2 → (2<=3) TRUE  → "3 " yazar
//    i=3 → (3<=3) TRUE  → "3 " yazar
//    i=4 → (4<=3) FALSE → iç döngü biter
//    endl → alt satıra geç
//    EKRAN: 3 3 3
//
//  j=4:
//    4 kere "4 " yazar → endl
//    EKRAN: 4 4 4 4
//
//  j=5:
//    5 kere "5 " yazar → endl
//    EKRAN: 5 5 5 5 5
//
//  j=6 → (6<=5) FALSE → dış döngü biter → program biter.
//
//
//  ── ALTIN KURAL ─────────────────────────────────────────────
//
//  Dış döngü (j)  →  hangi SATIRDA olduğunu belirler
//  İç döngü (i)   →  o satırda KAÇ KERE yazılacağını sayar
//  cout << j      →  i değil j yazılır, i sadece sayıcıdır
//
//  j her ilerlediğinde i SIFIRLANIR ve tekrar 1'den başlar.
//
//  Bunu şöyle düşün:
//  Dış döngü = dakika ibresi  (yavaş döner)
//  İç döngü = saniye ibresi  (hızlı döner, her dakika sıfırlanır)
//
// ============================================================
