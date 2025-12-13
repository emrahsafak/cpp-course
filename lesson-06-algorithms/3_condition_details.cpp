#include <iostream>

using namespace std;

int main()
{
	int sayi1, sayi2, islem, sonuc = 0; // burada sadece sonuc degeri icin initialization yapiyoruz
	cout << "Lutfen iki sayi giriniz.";
	cin >> sayi1 >> sayi2;
	cout << "Yapmak istediginiz islemi seciniz: \n1-Toplama\n2-Cikarma\n3-Carpma\n4-Bolme\n";
	cin >> islem;

	if (islem == 1)   //eger islem 1 ise if in icindeki kod blogu calisir, else if lerin hicbiri calismaz ve dogrudan  cout << "Islem sonucu: " << sonuc << endl;  satirina gider
	{
		sonuc = sayi1 + sayi2;
	}
	else if (islem == 2)  //eger islem 1 degilse ve islem 2 ise bu kod blogu calisir, else if lerin geri kalani calismaz ve dogrudan cout << "Islem sonucu: " << sonuc << endl;  satirina gider
	{
		sonuc = sayi1 - sayi2;
	}
	else if (islem == 3)  //eger islem 1 ve islem 2 degilse ve islem 3 ise bu kod blogu calisir, else if lerin geri kalani calismaz ve dogrudan cout << "Islem sonucu: " << sonuc << endl;  satirina gider
	{
		sonuc = sayi1 * sayi2;
	}
	else if (islem == 4)  //eger islem 1, islem 2 ve islem 3 degilse ve islem 4 ise bu kod blogu calisir ve dogrudan cout << "Islem sonucu: " << sonuc << endl;  satirina gider
	{
		sonuc = sayi1 / sayi2;
	}
	else
	{
		cout << "Gecersiz islem secimi." << endl; //eger islem 1,2,3 veya 4 degilse bu kod blogu calisir cout << "gecersiz islem secimi." << endl;  satirina gider 
		return 1;
	}

	cout << "Islem sonucu: " << sonuc << endl;
	return 0;

}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// BUG NASIL ORTAYA CIKAR ??



#include <iostream>

using namespace std;

int main()
{
    // Değişken tanımlamaları - sadece sonuc initialize edildi
    int sayi1, sayi2, islem, sonuc = 0;
    
    cout << "Lutfen iki sayi giriniz.";
    cin >> sayi1 >> sayi2;
    
    cout << "Yapmak istediginiz islemi seciniz: \n1-Toplama\n2-Cikarma\n3-Carpma\n4-Bolme\n";
    cin >> islem;
    
    // ============================================================
    // BIRINCI IF-ELSE YAPISI (İşlem 1 ve 2)
    // ============================================================
    
    if (islem == 1)
    {
        // İşlem 1 seçildi: TOPLAMA
        sonuc = sayi1 + sayi2;
        // Bu bloktan çıkınca, else if (islem == 2) kontrol edilmez!
        // Çünkü if doğru oldu, else if'ler atlanır
    }
    else if (islem == 2)
    {
        // İşlem 2 seçildi: ÇIKARMA
        sonuc = sayi1 - sayi2;
        // Bu bloktan çıkınca alt satırlara devam eder
    }
    
    // ============================================================
    // İKİNCİ IF-ELSE YAPISI (İşlem 3 ve 4) - BAĞIMSIZ!
    // ============================================================
    // ⚠️ DİKKAT: Burada 'else if' yerine 'if' kullanıldığı için
    // bu BAĞIMSIZ bir kontrol! Üstteki if-else'den bağımsız çalışır!
    
    if (islem == 3)  // ← BUG BURADA! 'else if' olmalıydı!
    {
        // İşlem 3 seçildi: ÇARPMA
        sonuc = sayi1 * sayi2;
    }
    else if (islem == 4)
    {
        // İşlem 4 seçildi: BÖLME
        sonuc = sayi1 / sayi2;
    }
    else
    {
        // Bu else sadece üstteki if (islem == 3) ve else if (islem == 4)'e bağlı!
        // Eğer islem 1 veya 2 ise, burası yine çalışır!
        // Çünkü islem 1 != 3 ve islem 1 != 4
        
        cout << "Gecersiz islem secimi." << endl;
        
        // return 1: Programı HEMEN sonlandırır (hata kodu ile)
        // Bu satırdan sonra hiçbir kod çalışmaz!
        return 1;
    }
    
    // ============================================================
    // SONUÇ YAZDIRMA BÖLÜMÜ
    // ============================================================
    // Bu satıra sadece şu durumlarda ulaşılır:
    // - İşlem 3 veya 4 seçilirse (else bloğuna girmez)
    // - return 1; çalışmazsa
    
    cout << "Islem sonucu: " << sonuc << endl;
    return 0;  // Normal program çıkışı
}

// ============================================================
// SENARYO ANALİZLERİ:
// ============================================================

/*
SENARYO 1: islem = 1 (TOPLAMA)
-----------------------------
1. if (islem == 1) → ✅ DOĞRU → sonuc = sayi1 + sayi2
2. else if (islem == 2) → ATLANDI (önceki if doğruydu)
3. if (islem == 3) → ❌ YANLIŞ (1 != 3)
4. else if (islem == 4) → ❌ YANLIŞ (1 != 4)
5. else → ✅ ÇALIŞIR! "Gecersiz islem secimi." yazdırır
6. return 1; → Program ÇIKIŞ! (Satır 35'e asla ulaşılmaz)

ÇIKTI:
Gecersiz islem secimi.
Program exited with code 1 (0x1).

SONUÇ: İşlem yapıldı ama gösterilmedi! ❌
*/

/*
SENARYO 2: islem = 2 (ÇIKARMA)
-----------------------------
1. if (islem == 1) → ❌ YANLIŞ
2. else if (islem == 2) → ✅ DOĞRU → sonuc = sayi1 - sayi2
3. if (islem == 3) → ❌ YANLIŞ (2 != 3)
4. else if (islem == 4) → ❌ YANLIŞ (2 != 4)
5. else → ✅ ÇALIŞIR! "Gecersiz islem secimi."
6. return 1; → Program ÇIKIŞ!

ÇIKTI:
Gecersiz islem secimi.
Program exited with code 1 (0x1).

SONUÇ: İşlem yapıldı ama gösterilmedi! ❌
*/

/*
SENARYO 3: islem = 3 (ÇARPMA)
-----------------------------
1. if (islem == 1) → ❌ YANLIŞ
2. else if (islem == 2) → ❌ YANLIŞ
3. if (islem == 3) → ✅ DOĞRU → sonuc = sayi1 * sayi2
4. else if (islem == 4) → ATLANDI (önceki if doğruydu)
5. else → ATLANDI (if doğruydu, else çalışmaz)
6. cout << "Islem sonucu: " << sonuc << endl; → ÇALIŞIR! ✅
7. return 0; → Normal çıkış

ÇIKTI:
Islem sonucu: 288
Program exited with code 0 (0x0).

SONUÇ: Mükemmel çalışır! ✅
*/

/*
SENARYO 4: islem = 4 (BÖLME)
-----------------------------
1. if (islem == 1) → ❌ YANLIŞ
2. else if (islem == 2) → ❌ YANLIŞ
3. if (islem == 3) → ❌ YANLIŞ (4 != 3)
4. else if (islem == 4) → ✅ DOĞRU → sonuc = sayi1 / sayi2
5. else → ATLANDI (else if doğruydu)
6. cout << "Islem sonucu: " << sonuc << endl; → ÇALIŞIR! ✅
7. return 0; → Normal çıkış

ÇIKTI:
Islem sonucu: 2
Program exited with code 0 (0x0).

SONUÇ: Mükemmel çalışır! ✅
*/

/*
SENARYO 5: islem = 99 (GEÇERSİZ)
-----------------------------
1. if (islem == 1) → ❌ YANLIŞ
2. else if (islem == 2) → ❌ YANLIŞ
3. if (islem == 3) → ❌ YANLIŞ
4. else if (islem == 4) → ❌ YANLIŞ
5. else → ✅ ÇALIŞIR! "Gecersiz islem secimi."
6. return 1; → Program ÇIKIŞ!

ÇIKTI:
Gecersiz islem secimi.
Program exited with code 1 (0x1).

SONUÇ: Doğru çalışır! ✅ (Gerçekten geçersiz işlem)
*/

// ============================================================
// BUG ÇÖZÜMÜ:
// ============================================================

/*
ÇÖZÜM: Satır 21'deki 'if'i 'else if' yap!

DOĞRU KOD:
----------
if (islem == 1) {
    sonuc = sayi1 + sayi2;
}
else if (islem == 2) {
    sonuc = sayi1 - sayi2;
}
else if (islem == 3) {  // ← DÜZELTME BURADA!
    sonuc = sayi1 * sayi2;
}
else if (islem == 4) {
    sonuc = sayi1 / sayi2;
}
else {
    cout << "Gecersiz islem secimi." << endl;
    return 1;
}

cout << "Islem sonucu: " << sonuc << endl;
return 0;

Bu şekilde tüm if-else'ler tek bir zincir oluşturur ve
ilk doğru koşul bulununca diğerleri kontrol edilmez!
*/

// ============================================================
// RETURN KOMUTU HAKKİNDA:
// ============================================================

/*
return 0; → Normal program çıkışı (başarılı)
return 1; → Hata ile program çıkışı

return çalıştığında:
- Program HEMEN sona erer
- Altındaki hiçbir kod çalışmaz
- main() fonksiyonundan çıkılır
- İşletim sistemine kod gönderilir (0 = başarı, 1 = hata)

return olmadan:
- Program sonuna kadar devam eder
- Tüm satırlar sırayla çalışır
- main() bitince otomatik return 0; yapılır
*/

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//🔄 return 1; Çıkarılırsa (Satır 32)

else {
    cout << "Gecersiz islem secimi." << endl;
    // return 1;  ← Kaldırıldı!
}

cout << "Islem sonucu: " << sonuc << endl;  // Artık buraya gelinir!
return 0;
```

---

## 📊 **Senaryo Analizi:**

### **Senaryo 1: islem = 1 (Toplama)**
```
Girdi: 24, 12, islem = 1
```

**Adım adım:**
1. `if (islem == 1)` ✅ → `sonuc = 36`
2. `if (islem == 3)` ❌ → Atla
3. `else if (islem == 4)` ❌ → Atla
4. `else` ✅ → **"Gecersiz islem secimi."** yazdırılır 💀
5. ⚠️ **`return` yok, devam ediyor!**
6. `cout << "Islem sonucu: " << sonuc << endl;` ✅

**Konsol Çıktısı:**
```
Gecersiz islem secimi.
Islem sonucu: 36
```

**İki mesaj birden! 🤪**

---

### **Senaryo 2: islem = 2 (Çıkarma)**
```
Girdi: 24, 12, islem = 2
```

**Adım adım:**
1. `else if (islem == 2)` ✅ → `sonuc = 12`
2. `if (islem == 3)` ❌
3. `else if (islem == 4)` ❌
4. `else` ✅ → **"Gecersiz islem secimi."**
5. Devam → `cout << "Islem sonucu: " << sonuc << endl;`

**Konsol Çıktısı:**
```
Gecersiz islem secimi.
Islem sonucu: 12
```

**Yine ikisi birden! 🎭**

---

### **Senaryo 3: islem = 3 (Çarpma)**
```
Girdi: 24, 12, islem = 3
```

**Adım adım:**
1. `if (islem == 1)` ❌
2. `else if (islem == 2)` ❌
3. `if (islem == 3)` ✅ → `sonuc = 288` ✅
4. `else if (islem == 4)` **ATLANDI** (önceki if doğruydu!)
5. `else` **ATLANDI**
6. `cout << "Islem sonucu: " << sonuc << endl;` ✅

**Konsol Çıktısı:**
```
Islem sonucu: 288
```

**Bu senaryo DOĞRU çalışır! ✅** (Çünkü islem 3'te else'e girmez)

---

### **Senaryo 4: islem = 4 (Bölme)**
```
Girdi: 24, 12, islem = 4
```

**Adım adım:**
1. İlk iki if yanlış
2. `if (islem == 3)` ❌
3. `else if (islem == 4)` ✅ → `sonuc = 2` ✅
4. `else` **ATLANDI**
5. `cout << "Islem sonucu: " << sonuc << endl;`

**Konsol Çıktısı:**
```
Islem sonucu: 2
```

**Bu da DOĞRU çalışır! ✅**

---

### **Senaryo 5: islem = 5 (Geçersiz)**
```
Girdi: 24, 12, islem = 5
```

**Adım adım:**
1. Tüm if'ler yanlış
2. `else` ✅ → "Gecersiz islem secimi."
3. Devam → `cout << "Islem sonucu: " << sonuc << endl;`
4. ⚠️ `sonuc` hiç değiştirilmedi → **sonuc = 0** (initialize değeri)

**Konsol Çıktısı:**
```
Gecersiz islem secimi.
Islem sonucu: 0
```

**Mantıklı ama 0 sonucu kafa karıştırıcı! 🤔**

---

## 📋 **Özet Tablo:**

| İslem | Mesajlar | Sonuç | Doğru mu? |
|-------|----------|-------|-----------|
| 1 (Toplama) | "Gecersiz islem"<br>"Islem sonucu: 36" | 36 | ❌ Çift mesaj! |
| 2 (Çıkarma) | "Gecersiz islem"<br>"Islem sonucu: 12" | 12 | ❌ Çift mesaj! |
| 3 (Çarpma) | "Islem sonucu: 288" | 288 | ✅ Doğru! |
| 4 (Bölme) | "Islem sonucu: 2" | 2 | ✅ Doğru! |
| 5 (Geçersiz) | "Gecersiz islem"<br>"Islem sonucu: 0" | 0 | ⚠️ Yarı doğru |

---

## 🎯 **Sonuç:**

**`return 1;` olmadan:**

✅ **İyi tarafı:**
- Sonuçlar ekrana yazdırılır
- Program crash olmaz

❌ **Kötü tarafı:**
- İslem 1 ve 2'de **çift mesaj** (karışıklık!)
- "Gecersiz" mesajı yanlış alarm veriyor
- Kullanıcı kafası karışır: "Hem geçersiz hem sonuç gösteriyor?" 🤷

---

## 💡 **Görsel Karşılaştırma:**

### `return 1;` ile (Mevcut):
```
İslem 1 → Gecersiz islem secimi. (Program çıkar)
İslem 2 → Gecersiz islem secimi. (Program çıkar)
İslem 3 → Islem sonucu: 288 ✅
İslem 4 → Islem sonucu: 2 ✅
```

### `return 1;` olmadan:
```
İslem 1 → Gecersiz islem secimi.
          Islem sonucu: 36 🤪
İslem 2 → Gecersiz islem secimi.
          Islem sonucu: 12 🤪
İslem 3 → Islem sonucu: 288 ✅
İslem 4 → Islem sonucu: 2 ✅



	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   // return = 0; NE DEMEK ????

	int main()  // ← Bu bir fonksiyon (main fonksiyonu)
{
    // kodlar...
    return 0;  // ← "main fonksiyonundan çık ve 0 değeri gönder"
}






