/*
================================================================================
  C++ IF BLOĞUNDA ATAMA HATASI - KOD AÇIKLAMASI
================================================================================
*/

#include <iostream>
using namespace std;

int main()
{
    // ============================================================
    // BAŞLANGIÇ DEĞERLERİ
    // ============================================================
    int x = 5;      // x değişkeni 5 olarak başlatıldı
    int y = 10;     // y değişkeni 10 olarak başlatıldı
    
    
    // ============================================================
    // HATA BURADA! (Satır 6)
    // ============================================================
    if (x = 20)     // ⚠️ SORUN: == yerine = kullanılmış!
    {
        /*
         * BU SATIRDA NELER OLUYOR?
         * 
         * 1. x = 20  →  Bu bir ATAMA işlemidir (karşılaştırma değil!)
         * 
         * 2. x'in değeri 5'ten 20'ye DEĞİŞTİRİLİR
         * 
         * 3. Atama işlemi 20 değerini döndürür
         * 
         * 4. C++'ta mantıksal değerlendirme:
         *    - 0        = FALSE (yanlış)
         *    - 0 dışı   = TRUE  (doğru)
         * 
         * 5. 20 sıfır olmadığı için → TRUE
         * 
         * 6. Sonuç: Bu if bloğu HER ZAMAN çalışır!
         *    (Çünkü 20 atandı ve 20 = TRUE)
         */
        
        
        // İkinci if kontrolü (Bu kısım DOĞRU yazılmış)
        if (y == 10)    // ✅ Burada == kullanılmış (karşılaştırma)
        {
            /*
             * y hala 10'a eşit mi kontrol ediliyor
             * y = 10 olduğu için bu da TRUE
             * Bu blok da çalışır
             */
            
            cout << "**" << endl;    // ÇIKTI: **
        }
    }
    else 
    {
        cout << "*****" << endl;
        
        /*
         * Bu else bloğu HİÇBİR ZAMAN ÇALIŞMAZ!
         * 
         * Neden?
         * Çünkü üstteki if (x = 20) her zaman TRUE döner
         * Else bloğu sadece if FALSE olduğunda çalışır
         */
    }
    
    /*
     * PROGRAM SONU:
     * - x artık 20'dir (başlangıçtaki 5 değil!)
     * - y hala 10'dur (değişmedi)
     * - Ekrana "**" yazdırıldı
     */
    
    return 0;
}


/*
================================================================================
ÖZET AÇIKLAMA
================================================================================

ORİJİNAL HATA:
--------------
if (x = 20)  ❌
  ↓
  Bu bir ATAMA'dır, KARŞILAŞTIRMA değil!
  x'e 20 değerini yazar
  Her zaman TRUE döner


DOĞRU KULLANIM:
----------------
if (x == 20) ✅
  ↓
  Bu bir KARŞILAŞTIRMA'dır
  x'in 20'ye eşit olup olmadığını kontrol eder
  x = 5 olduğu için FALSE döner
  Else bloğu çalışır


PROGRAM AKIŞI (Mevcut Hatalı Kodda):
-------------------------------------
1. x = 5, y = 10 ile başla
2. if (x = 20) → x'e 20 ata → TRUE → blok içine gir
3. x artık 20
4. if (y == 10) → 10 == 10 → TRUE → blok içine gir  
5. "**" yazdır
6. Else bloğu atlanır
7. Program biter


PROGRAM AKIŞI (Düzeltilmiş Versiyonda if (x == 20) olsaydı):
------------------------------------------------------------
1. x = 5, y = 10 ile başla
2. if (x == 20) → 5 == 20 → FALSE → blok atlanır
3. x hala 5
4. Else bloğuna git
5. "*****" yazdır
6. Program biter


TEMEL KURAL:
------------
=   → ATAMA (değer yazar)
==  → KARŞILAŞTIRMA (değer kontrol eder)

Bu C++'ın en yaygın hatalarından biridir!

================================================================================
*/
