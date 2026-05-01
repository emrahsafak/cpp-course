#include <iostream>
using namespace std;

int main()
{
	/* 
	   while dongusu(Loop) :

	   * Onceden belirlenmis kosullara kadar devam eder.
	   * Kosulun her kontrolunden sonra dongu icerisindeki islemler bir kez yapilir/
	   * Kosul bozulduktan sonra ilk kontrolde dongu terk edilir.
	   
	   while ( kosu ) 
	   {
	     // yapilacak islem 1
	     // yapilacak islem 2
	     // yapilacak islem 3
	   }
       	
	*/ 
	
	int index = 3;

	while (index <= 10)
	{
		cout << " Index degeri :" << index << endl;
		index++;
	}
	 
	cout << endl << " dongu bitti ";
	cout << " Index degeri :" << index << endl;
    
}

<=================================================================================================> 

#include <iostream>
using namespace std;

/*
=======================================================================
   WHILE DONGUSU — DERLEYICI VE CALISMA ZAMANI DAVRANISI
   While Loop  — Compiler & Runtime Behavior (Step by Step)
=======================================================================

   -----------------------------------------------------------------------
   PHASE 1 : COMPILE TIME (Derleme Asamasi)
   -----------------------------------------------------------------------
   - Kaynak kod (source code) CPU'nun anlayacagi makine diline cevirilir.
   - Hicbir satir henuz CALISTIRILMAZ. Derleyici sadece talimatlari yazar.

   Derleyici su isleri yapar:
     1) #include <iostream>   → iostream kutuphanesini koda dahil eder.
     2) using namespace std   → std:: on ekini zorunlu olmaktan cikarir.
     3) int main()            → Programin giris noktasini tanimlar.
     4) int index             → Stack bellekte 4 byte (int boyutu) ayirir.
     5) while kosulu          → Bir "conditional jump" (kosullu atlama)
                                 assembly komutu olusturur.
     6) index++               → Bir "increment" (artirma) komutu olusturur.

   -----------------------------------------------------------------------
   PHASE 2 : RUNTIME (Calisma Zamani)
   -----------------------------------------------------------------------
   Derleyicinin olusturdugu talimatlar CPU tarafindan SIRAYLA calistirilir.
*/

int main()
{
    // -----------------------------------------------------------------------
    // ADIM 1 — DEGISKEN BASLATMA (Variable Initialization)
    // -----------------------------------------------------------------------
    // Stack bellekte 4 byte'lik bir alan acilir.
    // O alana 3 degeri yazilir.
    //
    // Bellek gorunumu :
    //   [ index = 3 ]  ← stack uzerinde
    // -----------------------------------------------------------------------

    int index = 3;


    // -----------------------------------------------------------------------
    // ADIM 2 — WHILE KOSULUNUN ILK KONTROLU (First Condition Check)
    // -----------------------------------------------------------------------
    // CPU su soruyu sorar : "index <= 10 dogru mu?"
    // 3 <= 10 → TRUE (dogru)
    // Dogru oldugu icin CPU dongu govdesinin ICINE girer.
    // Yanlis olsaydi, CPU donguyu ATLAR ve asagiya devam ederdi.
    //
    // Assembly duzeyinde zihinsel model (Mental Model at Assembly Level) :
    //
    //   LABEL: kosul_kontrol
    //       EGER (index <= 10) YANLIS ise → dongu_sonu'na ATLA
    //       [dongu govdesini calistir]
    //       index = index + 1
    //       kosul_kontrol'e ATLA      ← CPU geri yukari "zipler"
    //   LABEL: dongu_sonu
    //       [program devam eder]
    //
    // Dongu, aslinda CPU'nun iki bellek adresi arasinda ileri-geri
    // "ziplamasi"ndan (jump) baska bir sey degildir.
    // -----------------------------------------------------------------------

    while (index <= 10)
    {
        // -------------------------------------------------------------------
        // ADIM 3 — DONGU GOVDESI (Loop Body) — Her iterasyonda calisir
        // -------------------------------------------------------------------
        // cout mevcut index degerini ekrana yazar.
        // endl satiri sonlandirir ve tamponu (buffer) bosaltir.
        // -------------------------------------------------------------------

        cout << " Index degeri : " << index << endl;


        // -------------------------------------------------------------------
        // ADIM 4 — INDEX ARTIRILIR (Increment)
        // -------------------------------------------------------------------
        // index++ ifadesi index = index + 1 ile TAMAMEN AYNIDIR.
        // Bu satir her iterasyonun SONUNDA calisir.
        // Artirmadan SONRA CPU tekrar yukari donup kosulu kontrol eder.
        // -------------------------------------------------------------------

        index++;


        // -------------------------------------------------------------------
        // ITERASYON TABLOSU (Iteration Table) :
        //
        //  Iterasyon | Kontroldeki index | Kosul          | Islem
        //  ----------|-------------------|----------------|------------------
        //      1     |        3          | 3  <= 10  TRUE | Yazdir, index→ 4
        //      2     |        4          | 4  <= 10  TRUE | Yazdir, index→ 5
        //      3     |        5          | 5  <= 10  TRUE | Yazdir, index→ 6
        //      4     |        6          | 6  <= 10  TRUE | Yazdir, index→ 7
        //      5     |        7          | 7  <= 10  TRUE | Yazdir, index→ 8
        //      6     |        8          | 8  <= 10  TRUE | Yazdir, index→ 9
        //      7     |        9          | 9  <= 10  TRUE | Yazdir, index→10
        //      8     |       10          | 10 <= 10  TRUE | Yazdir, index→11
        //      9     |       11          | 11 <= 10 FALSE | DONGUDAN CIK ✗
        //
        // -------------------------------------------------------------------
    }


    // -----------------------------------------------------------------------
    // ADIM 5 — KOSUL BOZULUR, DONGU CIKISI (Condition Fails — Loop Exits)
    // -----------------------------------------------------------------------
    // index 11 oldigunda :
    //   11 <= 10 → FALSE
    // CPU dongu blogunun TAMAMEN DISINA atlar.
    // Bir sonraki satirdan devam eder.
    // -----------------------------------------------------------------------


    // -----------------------------------------------------------------------
    // ADIM 6 — DONGU SONRASI CALISMA (Post-Loop Execution)
    // -----------------------------------------------------------------------
    // KRITIK ZIHINSEL MODEL (Critical Mental Model) :
    //
    // index degeri burada 10 DEGIL, 11'dir.
    //
    // Neden?
    //   - Son basarili iterasyonda index = 10 yazdirildi.
    //   - Ardindan index++ calisip index'i 11 yapti.
    //   - SONRA kosul kontrol edildi : 11 <= 10 → FALSE → cikis.
    //   - Yani dongu, index 11 olduktan SONRA terk edildi.
    //
    // Bu, while dongulerinde cok sik yapilan bir yanlis anlamadir.
    // Cikis degeri her zaman sinirin bir adim OTESINDEDIR.
    // -----------------------------------------------------------------------

    cout << endl << " Dongu bitti!" << endl;
    cout << " Dongu sonrasi index degeri : " << index << endl;
    // Cikti → 11  (10 degil!)


    // -----------------------------------------------------------------------
    // EKSTRA : SIFIR ITERASYON DURUMU (Zero Iteration Case)
    // -----------------------------------------------------------------------
    // Eger index baslangicta 11 olsaydi :
    //   while (11 <= 10) → hemen FALSE
    //   Dongu govdesi HIC CALISMAZ, sifir iterasyon gerceklesirdi.
    //
    // Bu, while ile do-while arasindaki temel farktir :
    //   while    → kosulu ONCE kontrol eder (0 iterasyon mumkun)
    //   do-while → govdeyi ONCE calistirir, sonra kontrol eder
    //              (en az 1 iterasyon garantilidir)
    // -----------------------------------------------------------------------


    // -----------------------------------------------------------------------
    // NIHAI CIKTI (Final Output) :
    //
    //   Index degeri : 3
    //   Index degeri : 4
    //   Index degeri : 5
    //   Index degeri : 6
    //   Index degeri : 7
    //   Index degeri : 8
    //   Index degeri : 9
    //   Index degeri : 10
    //
    //   Dongu bitti!
    //   Dongu sonrasi index degeri : 11
    // -----------------------------------------------------------------------

    return 0;
}
