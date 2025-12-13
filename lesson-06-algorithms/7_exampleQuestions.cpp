/*
================================================================================
  BOOLEAN İFADELERİN MATEMATİKSEL İŞLEMLERDE KULLANIMI
================================================================================
*/

#include <iostream>
using namespace std;

int main()
{
    // ========================================================================
    // SORU A) w değeri ne olur?
    // ========================================================================
    
    int x = 5, y = 9, z = 7.9, w;
    // Değişken tanımlamaları:
    // x = 5     → Tam sayı
    // y = 9     → Tam sayı
    // z = 7.9   → ⚠️ DİKKAT! int tipinde tanımlandı!
    //             → Ondalık kısım atılır → z = 7 olur
    // w = ?     → Henüz değer atanmadı (garbage value)
    
    
    w = (z > x) - (y <= 11);
    // Bu satır boolean ifadeleri matematiksel işlemde kullanıyor!
    
    // ADIM 1: (z > x) ifadesini hesapla
    // z > x  →  7 > 5  →  true
    // C++'ta: true = 1, false = 0
    // Sonuç: 1
    
    // ADIM 2: (y <= 11) ifadesini hesapla
    // y <= 11  →  9 <= 11  →  true
    // Sonuç: 1
    
    // ADIM 3: Çıkarma işlemi
    // w = 1 - 1
    // w = 0
    
    cout << w << endl;  // ÇIKTI: 0
    
    // ========================================================================
    // SONUÇ A: w = 0
    // ========================================================================
    
    return 0;
}


// ============================================================================
// ============================================================================


#include <iostream>
using namespace std;

int main()
{
    // ========================================================================
    // SORU B) w değeri ne olur?
    // ========================================================================
    
    int x = 5, y = 9, z = 7.4, w;
    // Değişken tanımlamaları:
    // x = 5     → Tam sayı
    // y = 9     → Tam sayı
    // z = 7.4   → ⚠️ int tipinde tanımlandı!
    //             → Ondalık kısım atılır → z = 7 olur
    // w = ?     → Henüz değer atanmadı
    
    
    w = 1;
    // Direkt atama yapıldı
    // w'ye 1 değeri atandı
    // Başka bir işlem yok
    
    cout << w;  // ÇIKTI: 1
    
    // ========================================================================
    // SONUÇ B: w = 1
    // ========================================================================
    
    return 0;
}


/*
================================================================================
ÖZET TABLO
================================================================================

SORU A:
-------
Başlangıç: x=5, y=9, z=7 (7.9'dan dönüştü), w=?
İşlem: w = (z > x) - (y <= 11)
       w = (7 > 5) - (9 <= 11)
       w = true - true
       w = 1 - 1
Sonuç: w = 0


SORU B:
-------
Başlangıç: x=5, y=9, z=7 (7.4'ten dönüştü), w=?
İşlem: w = 1
Sonuç: w = 1


================================================================================
ÖNEMLİ NOTLAR
================================================================================

1. INT TİPİNDE ONDALIK SAYI:
   ----------------------------
   int z = 7.9;  → z = 7 (ondalık kısım atılır, yuvarlanmaz!)
   int z = 7.4;  → z = 7
   int z = 7.1;  → z = 7


2. BOOLEAN → INTEGER DÖNÜŞÜMÜ:
   ----------------------------
   true   =  1
   false  =  0
   
   Örnek:
   (5 > 3)   →  true   →  1
   (5 < 3)   →  false  →  0
   (5 == 5)  →  true   →  1
   (5 != 5)  →  false  →  0


3. BOOLEAN ARİTMETİĞİ:
   ----------------------------
   1 - 1  =  0
   1 - 0  =  1
   0 - 1  = -1
   1 + 1  =  2
   
   Örnek:
   (true) - (true)   =  1 - 1  =  0
   (true) - (false)  =  1 - 0  =  1
   (false) - (true)  =  0 - 1  = -1


4. KARŞILAŞTIRMA OPERATÖRLERİ:
   ----------------------------
   >     Büyüktür
   <     Küçüktür
   >=    Büyük eşit
   <=    Küçük eşit
   ==    Eşittir
   !=    Eşit değildir


================================================================================
DETAYLI HESAPLAMA (SORU A)
================================================================================

Başlangıç Değerleri:
--------------------
x = 5
y = 9
z = 7.9 → int olduğu için → 7
w = tanımsız


İfade: w = (z > x) - (y <= 11)
--------------------------------------

Adım 1: İlk parantez (z > x)
   z > x
   7 > 5
   true
   1  ← Boolean'dan integer'a dönüştü

Adım 2: İkinci parantez (y <= 11)
   y <= 11
   9 <= 11
   true
   1  ← Boolean'dan integer'a dönüştü

Adım 3: Çıkarma işlemi
   w = 1 - 1
   w = 0

Final: w = 0


================================================================================
*/
