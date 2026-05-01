#include <iostream>
using namespace std;

int main()
{
	/* 
	  Soru: Kullanıcıdan başlangıç ve bitiş sayısını alarak, bu sayılar arasında bulunan ve 7'ye tam bölünebilen sayıları ekrana yazdıran bir program yazınız.  	
	*/ 
	
	int baslangicSayi, bitisSayi;
	cout << " Baslangic sayinizi giriniz :";
	cin >> baslangicSayi;
	cout << " Bitis sayinizi giriniz : ";
	cin >> bitisSayi;

	while (baslangicSayi <= bitisSayi)
	{
		cout << baslangicSayi << endl;

		if (baslangicSayi % 7 == 0)
		{
			cout << baslangicSayi << "sayisi 7'ye tam bolunur." << endl;
		}

		baslangicSayi++;

	}
    
}

<============================================================================================================================================================================>
#include <iostream>
using namespace std;

/*
=======================================================================
   SORU: Kullanicidan baslangic ve bitis sayisini alarak, bu sayilar
   arasinda bulunan ve 7'ye tam bolunebilen sayilari ekrana yazdirin.
=======================================================================

   -----------------------------------------------------------------------
   NEDEN 3. BIR DEGISKEN (index) KULLANDIK?
   The Core Question: Why a Third Variable?
   -----------------------------------------------------------------------

   YANLIS YAKLASIM — Ogrencinin ilk icgudusuel cozumu (Instinctive Attempt)
   Image'deki ilk kodda baslangicSayi dogrudan while icinde kullanildi:

       while (baslangicSayi <= bitisSayi)
       {
           baslangicSayi++;   // PROBLEM BURADA!
       }

   Bu yaklasimin kritik hatasi sudur:
   baslangicSayi++ her iterasyonda ORIJINAL degeri ezerek ustune yazar.
   Dongu bittiginde baslangicSayi artik ilk girilen deger DEGILDIR.
   Bu yuzden en sondaki cout satiri YANLIS deger yazdirir:

       cout << baslangicSayi << " ile " << bitisSayi ...
                  ↑
                  Artik bu, kullanicinin girdigi sayi degil!
                  Dongunun bozdugu bir sayi!

   -----------------------------------------------------------------------
   DOGRU YAKLASIM — index Degiskeni ile Cozum
   -----------------------------------------------------------------------

   Cozum: baslangicSayi'yi bir "kasa" gibi dusun.
   O kasayi HICBIR ZAMAN elleme.
   Dongu icinde sadece "index" adli bir KOPYA ile calis.

   Bellek gorunumu (Memory View) :

     Baslangicta kullanici 3 ve 20 girdi diyelim:

       [ baslangicSayi = 3  ]  ← Kilitli kasa. Hic degismez.
       [ bitisSayi     = 20 ]  ← Kilitli kasa. Hic degismez.
       [ index         = 3  ]  ← Serbest kopya. Dongu bunu kullanir.

     Dongu sonunda:
       [ baslangicSayi = 3  ]  ← HALA 3. Orijinal korundu. ✓
       [ bitisSayi     = 20 ]  ← HALA 20.                  ✓
       [ index         = 21 ]  ← Bozuldu ama umursamiyoruz. ✓

   Bu sayede en sondaki cout satiri guvenle sunu yazabilir:
       "3 ile 20 arasinda bulunan sayilar..."
        ↑        ↑
        Hala dogru degerler!

   -----------------------------------------------------------------------
   C# / UNITY ANALOGISI (Analogy for Unity Developers)
   -----------------------------------------------------------------------
   Bunu Unity'deki bir Transform dusun:

       Vector3 spawnPoint = player.position;  // Orijinal pozisyon
       Vector3 currentPos = spawnPoint;       // Kopyayla calis

       while (currentPos.x < targetX)
       {
           currentPos.x += speed;             // Kopyayi hareket ettir
       }

       // spawnPoint hala orijinal degerde! Respawn icin kullanabilirsin.

   Ayni mantik. baslangicSayi = spawnPoint (dokunma),
               index         = currentPos  (bunu kullan).

   -----------------------------------------------------------------------
   MODULO OPERATORU (%) — Bolunebilirlik Kontrolu
   -----------------------------------------------------------------------
   index % 7 == 0  ifadesi ne anlama gelir?

   % operatoru bolme isleminin KALANINI verir.
   Ornek:
       14 % 7 = 0   → 14, 7'ye tam bolunur    ✓
       15 % 7 = 1   → 15, 7'ye tam bolunmaz   ✗
       21 % 7 = 0   → 21, 7'ye tam bolunur    ✓

   MATLAB'daki mod(x, 7) == 0 ile BIREBIR AYNIDIR.
   C++'ta % operatoru tam sayilarda mod islevi gorur.

=======================================================================
*/

int main()
{
    // -----------------------------------------------------------------------
    // ADIM 1 — UC DEGISKEN BIRDEN TANIMLANDI
    // -----------------------------------------------------------------------
    // baslangicSayi : Kullanicinin girdigi ilk sayi. KORUNACAK.
    // bitisSayi     : Kullanicinin girdigi son sayi. KORUNACAK.
    // index         : Dongu icinde gezen "gezici kopya". HARCANAN.
    // -----------------------------------------------------------------------

    int baslangicSayi, bitisSayi, index;


    // -----------------------------------------------------------------------
    // ADIM 2 — KULLANICIDAN GIRDI AL (User Input)
    // -----------------------------------------------------------------------
    // cin >> degiskene klavyeden veri okur.
    // cout ile once kullaniciya ne girmesi gerektigini soyleriz.
    // -----------------------------------------------------------------------

    cout << " Baslangic sayinizi giriniz : ";
    cin  >> baslangicSayi;

    cout << " Bitis sayinizi giriniz : ";
    cin  >> bitisSayi;


    // -----------------------------------------------------------------------
    // ADIM 3 — INDEX'I BASLANGIC DEGERINE ESITLE (Initialize the Iterator)
    // -----------------------------------------------------------------------
    // Bu satirda index, baslangicSayi'nin bir KOPYASINI alir.
    // Artik index ve baslangicSayi ayni degere sahip ama FARKLI degiskenler.
    // Biri degisirse digeri etkilenmez. Tamamen bagimsiz bellek alanlari.
    // -----------------------------------------------------------------------

    index = baslangicSayi;   // index = baslangicSayi (kopya, NOT referans!)


    // -----------------------------------------------------------------------
    // ADIM 4 — WHILE DONGUSU
    // -----------------------------------------------------------------------
    // Kosul: index <= bitisSayi
    // Dikkat: baslangicSayi <= bitisSayi DEGIL!
    // Dongu baslangicSayi'yi hic GORMUYOR. Sadece index'i kullanir.
    // -----------------------------------------------------------------------

    while (index <= bitisSayi)
    {

        // -------------------------------------------------------------------
        // ADIM 5 — HER SAYIYI YAZDIR
        // -------------------------------------------------------------------
        // Once mevcut index degerini ekrana yaz.
        // Bu satir 7'ye bolunup bolunmediginden BAGIMSIZ her sayiyi yazar.
        // -------------------------------------------------------------------

        cout << index << endl;


        // -------------------------------------------------------------------
        // ADIM 6 — 7'YE BOLUNEBILIRLIK KONTROLU (Divisibility Check)
        // -------------------------------------------------------------------
        // index % 7 : index'i 7'ye boldugumuzde KALAN nedir?
        // Kalan 0 ise → tam bolunur → ek mesaj yazdir.
        // Kalan 0 degilse → if bloguna girilmez, sessizce devam edilir.
        // -------------------------------------------------------------------

        if (index % 7 == 0)
        {
            cout << index << " sayisi 7'ye tam bolunur." << endl;
        }


        // -------------------------------------------------------------------
        // ADIM 7 — INDEX'I ARTIR
        // -------------------------------------------------------------------
        // baslangicSayi DOKUNULMADI. Sadece index bir ilerledi.
        // Dongu tekrar kosulu kontrol etmek icin yukari cikar.
        // -------------------------------------------------------------------

        index++;

    }   // index > bitisSayi oldugunda dongu buradan cikti


    // -----------------------------------------------------------------------
    // ADIM 8 — DONGU SONU MESAJI
    // -----------------------------------------------------------------------
    // Bu satir NEDEN DOGRU calisir?
    // Cunku baslangicSayi ve bitisSayi hic degistirilmedi!
    // Dongu boyunca sadece index kostu. Orijinal degerler sapasaglam.
    //
    // Eger index kullanilmadan baslangicSayi++ yapilsaydi,
    // baslangicSayi burada yanlis degeri (bitisSayi + 1) gosterirdi.
    // -----------------------------------------------------------------------

    cout << baslangicSayi << " ile " << bitisSayi << " arasinda bulunan ve 7'ye tam bolunebilen sayilar yukarida listelenmistir." << endl;


    // -----------------------------------------------------------------------
    // ORNEK CIKTI — Kullanici 1 ve 30 girerse:
    //
    //   1
    //   2
    //   3
    //   4
    //   5
    //   6
    //   7
    //   7 sayisi 7'ye tam bolunur.
    //   8
    //   ...
    //   14
    //   14 sayisi 7'ye tam bolunur.
    //   ...
    //   21
    //   21 sayisi 7'ye tam bolunur.
    //   ...
    //   28
    //   28 sayisi 7'ye tam bolunur.
    //   29
    //   30
    //   1 ile 30 arasinda bulunan ve 7'ye tam bolunebilen sayilar yukarida listelenmistir.
    //         ↑                  ↑
    //         Hala dogru!        Hala dogru!   (index bozsa da bunlar saglamdi)
    // -----------------------------------------------------------------------

    return 0;
}

