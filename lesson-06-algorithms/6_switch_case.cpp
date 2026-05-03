#include <iostream>
using namespace std;

int main()
{
    int gun;
    cout << "Bir gun sayisi giriniz: ";
    cin >> gun;
    
    switch (gun)
    {
        case 1:
            cout << "Pazartesi" << endl;
            break;
        case 2:
            cout << "Sali" << endl;
            break;
        case 3:
            cout << "Carsamba" << endl;
            break;
        case 4:
            cout << "Persembe" << endl;
            break;
        case 5:
            cout << "Cuma" << endl;
            break;
        case 6:
            cout << "Cumartesi" << endl;
            break;
        case 7:
            cout << "Pazar" << endl;
            break;
        default:
            cout << "Gecersiz sayi girdiniz!" << endl;
            return 1;  // Geçersiz değer için hata ile çık
    }
    
    return 0;  // Geçerli değerler için başarıyla çık
}



=============================================================================================================================================================================================================================================================================================================================



  #include <iostream>
using namespace std;

int main()
{
    int gun;
    cout << "Bir gun sayisi giriniz: ";
    cin >> gun;
    
    switch (gun)
    {
        case 1:
            cout << "Pazartesi" << endl;
            break;
            
        case 2:
            cout << "Sali" << endl;
            break;
            
        case 3:
            cout << "Carsamba" << endl;
            // ❌ BREAK SİLİNDİ! → Fall-through olur
            
        case 4:     // ⚠️ Break olmadığı için burası da çalışır!
            cout << "Persembe" << endl;
            break;  // Burada durur
            
        case 5:
            cout << "Cuma" << endl;
            break;
            
        case 6:
            cout << "Cumartesi" << endl;
            break;
            
        case 7:
            cout << "Pazar" << endl;
            break;
            
        default:
            cout << "Gecersiz sayi girdiniz!" << endl;
            return 1;
    }
    
    return 0;
}
```

## SENARYO: KULLANICI 3 GİRERSE

### BREAK VAR (Normal Durum):
```
Bir gun sayisi giriniz: 3
Carsamba
```
**Program 0 ile biter** ✅

---

### BREAK YOK (3. Break Silinmiş):
```
Bir gun sayisi giriniz: 3
Carsamba
Persembe
```
**Program 0 ile biter** ✅

---

## NE OLDU?

### Adım Adım Akış (Break Olmadan):

1. `switch (gun)` → gun = 3
2. case 1: atla (3 ≠ 1)
3. case 2: atla (3 ≠ 2)
4. **case 3: eşleşti!** (3 == 3)
   - `cout << "Carsamba"` → **Çarşamba yazdır**
   - ❌ **BREAK YOK!** → Aşağı doğru devam et
5. **case 4:** Koşul kontrolü **YAPILMAZ**, direkt çalışır! (FALL-THROUGH)
   - `cout << "Persembe"` → **Perşembe de yazdırıldı!**
   - ✅ `break;` → Switch'ten çık
6. return 0; → Program biter

---

## FALL-THROUGH NEDİR?

**Fall-Through** = Break olmadan bir case'den diğerine "düşmek"
```
case 3 ─┐
        │ Break yok!
        ↓
case 4 ←┘ Buraya "düştü", koşul kontrol edilmeden çalıştı!
```

---

## DİĞER DURUMLAR:

### Kullanıcı 1 Girerse:
```
Pazartesi          ← Sadece bu (break var)
```

### Kullanıcı 4 Girerse:
```
Persembe           ← Sadece bu (case 4'ün kendi break'i çalışır)
```

### Kullanıcı 99 Girerse:
```
Gecersiz sayi girdiniz!    ← return 1 ile çıkış
