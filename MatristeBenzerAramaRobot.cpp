#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>// programa T�rk�e dil deste�i eklemek i�in gereken k�t�phanenin dahil edilmesi

void rastgeleDegerlerAta(int** matrix,int N){//10x10'luk matrise rastgele de�erler atayan fonksiyon. 
    srand(time(NULL)); //random fonksiyonunun time ile beslenmesi
    int i,j;//d�ng� indexlerinin olu�turulmas�
    for(i=0;i<N;i++){//xlerin gezilmesi
        for(j=0;j<N;j++){//ylerin gezilmesi
            matrix[i][j] = rand() % 2; //0 veya 1 olmak �zere gezilen elemanlara tek ek rastgele de�er atanmas�
        }
    }
}
void matrixiYazdir(int** matrix,int N){// matrixi ekrana yazd�ran fonksiyon
	 int i,j;//d�ng� indexlerinin olu�turulmas�
    for(i=0;i<N;i++){//xlerin gezilmesi
        for(j=0;j<N;j++){//ylerin gezilmesi
           printf("%d ",matrix[i][j]);//gezilen her eleman�n yazd�r�lmas�
        }
        printf("\n");//her yeni sat�rda bir a�a�� ge�ilmesi
    }
}

int belirliKismiAra(int** matrix,int** arananMatrix,int arananMatrixboyu, int x1,int y1){//verilen matrisin; x1 ve y1 de�erleri ile s�n�rland��lm�� k�sm�nda
                                                                           //aranan matris ile ne kadar e�le�meye sahip oldu�unu bulan ve bunu d�nd�ren fonksiyon �rne�in
                                                                           //main k�sm�nda bu fonksiyon d�ng� i�erisinde �a�r�larak olas� t�m 3x3'l�k k�s�mlar�n denenmesi sa�lan�r
	int benzerlikSayaci = 0;//uyu�malar� sayacak olan saya�
	int i = 0,j = 0;//aranan matrisi gezecek olan index de�i�kenleri
	int a = 0,b = 0;//�zerinde aama yap�lacak matrisi gezmek i�in kullan�lacak d�ng� de�i�kenleri

	for(a = x1,i = 0;a<x1+arananMatrixboyu;a++,i++){//Arama i�lemini yapar. �rne�in 3x3l�k matrisi d�nmeye 0,0 dan ba�lamak istedi�imizden i ve j 0'dan ba�lat�l�r.10x10'luk matrisin istenilen 3x3l�k k�sm�n�
	                                  //gezmek itedi�imizden a=x1'e, b ise y1'e e�itlenir bu sayede d�nmeye istenilen yerden ba�lan�r. 3x3l�k bir alan d�nmek istedi-
	                                  //�imiz i�in a ve b 3 fazlas�na e�it oluncaya kadar devam eder.
	   for(b = y1,j = 0;b<y1+arananMatrixboyu;b++,j++){
	   	printf("matrix[%d][%d]: %d - arananMatrix[%d][%d]: %d\n",a,b,matrix[a][b],i,j,arananMatrix[i][j]);//arama i�leminin nas�l oldu�unun kullan�c� taraf�ndan da g�r�lebilmesi i�in
	   	                                                                                                  //her arama sonucu yazd�r�r
	   	if(*(matrix[a] + b) == *(arananMatrix[i] + j)){//matrix[a] matrix[a][index]'in ilk eleman�n� ifade eder, o halde *(matrix[a]+b) yap�larak matrix[a][b]'ye ula��labilir
	   	                                               //ayn�s� arananMatrix i�in de ge�erlidir
	   		benzerlikSayaci++; //e�er bir e�le�me varsa saya� 1 artt�r�l�yor
		   }
	   }
     printf("\n------------------------------\n");//��kt�n�n okunakl� olmas� i�in konulmu� kesme i�aretleri
	}
	printf("\nbulunan toplam benzerlik sayisi: %d\n\n\n",benzerlikSayaci);//bulunan toplam benzerlik say�s� yazd�r�l�yor
		 printf("\n==========================================================\n");//��kt�n�n okunakl� olmas� i�in konulmu� kesme i�aretleri
	return benzerlikSayaci;//saya� d�nd�r�l�yor
	
}

int main() {
	
	setlocale(LC_ALL, "Turkish");//T�rk�e dil deste�inin eklenmesi
	
	int goruntuBoyutuN;//�zerinde arama yap�laccak matrixin boyutunu tutan de�i�ken
	int arananMatrisBoyutu;//aranacak matrisin boyutunu tutan de�i�ken
	int x1=0,y1=0;//bulunan k�sm�n koordinatlar�n� tutacak de�i�kenler
    int enBenzerBenzemeSayisi = 0;//en �ok uyu�an�n ne kadar h�cresinin uyu�tu�unu tutacak de�i�ken
    int rastgeleDegerlerAtaBoolTercih1 = 0;//sorularda verilen cevaplar�n uygulanmas�n� sa�layacak de�i�kenler do�rudan tercih1 ve tercih2 de�i�kenleri de kullan�labilir ancak 
                                           //okunakl� olmas� i�in bu �ekilde yap�lm��t�r
    int rastgeleDegerlerAtaBoolTercih2 = 0;
        
    //Kullan�c�ya rastgele veya elle ayarlanm�� matriste arama yapma se�ene�i sunan soru:
    char tercih1;//tercihi tutacak de�i�ken
    char tercih2;
    char tekrar;//kullan�c�n�n program bitiminde dilerse program� tekrar denemesini sa�layan tercihi tutan de�i�ken
    while(1){
	    x1=0,y1=0;//program�n her ba�tan �al�����nda de�erlerin s�f�rlanmas�:
	    
	    enBenzerBenzemeSayisi = 0;
	    rastgeleDegerlerAtaBoolTercih1 = 0;
	    rastgeleDegerlerAtaBoolTercih2 = 0;
	    
    	while(1){
    	printf("\nRobottan gelen g�r�nt� matisinin N*N boyutunu se�in\n N:");
    	scanf("%d",&goruntuBoyutuN);//�zerinde arama yap�lacak matrisin boyut se�imi
    	
    	printf("\nAranacak matisin N*N boyutunu se�in\n N:");
    	scanf("%d",&arananMatrisBoyutu);//aranacak matrisin boyut se�imi

    	printf("\nKendi Belirledi�iniz matrisde mi arama yapmak istersiniz yoksa rastgele bir matris �zerinden mi arama yapmak istersiniz?\n");
		printf("\n�nemli not: Kendi belirleyece�iniz matrisi se�erseniz kod k�sm�ndan matrislerinizin boyutlar�n�n se�ti�iniz boyutlara uygun oldu�undan emin olmak zorundas�n�z\n");
		printf("\n(rastgel icin r, kendi belirledi�iniz icin k yaz�n�z):");//�zerinde arama yap�lacak matrisin rastgelelik se�imi
   	    getchar();//bir hatadan dolay� program�n direk ge�memesi i�in bekletme
	   	scanf("%c",&tercih1);//kullan�c�n�n iste�i do�rultusunda cevab� al�r ve tercih1 de�i�kenine atar
	   	
	   	printf("\nKendi Belirledi�iniz matrisi mi aramak istersiniz yoksa rastgele bir matrisi mi?\n");
	   	printf("\n(rastgel icin r, kendi belirledi�iniz i�in k yaz�n�z):");//aranacak matrisin rastgelelik se�imi
   	    getchar();//ayn� �ekilde bir hatadan dolay� program�n direk ge�memesi i�in bekletme
	   	scanf("%c",&tercih2);//kullan�c�n�n iste�i do�rultusunda cevab� al�r ve tercih2 de�i�kenine atar
    
        //tercihlere g�re bool de�i�kenlerinin belirlenmesi:
        //e�er ikisi de r se�ildiyse rastgele boollar�n� 1 yapar. E�er birisi se�ilmi�se yaln�zca se�ilenin bool'unu 1 yapar
    	if(tercih1=='r' && tercih2=='r'){
    		rastgeleDegerlerAtaBoolTercih1 = 1;
    	    rastgeleDegerlerAtaBoolTercih2 = 1;
    		break;//d�ng�y� bitirir ve aramay� ba�lat�r
		}else if(tercih1=='k' && tercih2=='r'){
    	    rastgeleDegerlerAtaBoolTercih2 = 1;  
		    break;
		}else if(tercih1=='r' && tercih2=='k'){
	        rastgeleDegerlerAtaBoolTercih1 = 1; 
		    break;
        }else{
        	break;//hi� biri de�ilse program default ba�lat�l�r
		}
   
}
    
	//==========================================================================================================================================
	int i,j;//main i�erisinde kullan�lacak olan d�ng�lerin d�ng� de�i�kenlerinin olu�turulmas�
	
	//�zerinde arama yap�lacak matrixin dinamik bellek ile olu�turulmas�:
	int **robotunGoruntusu = (int**)malloc(goruntuBoyutuN * sizeof(int*));//ana bellek ay�rma
	for(i=0; i < goruntuBoyutuN; i++) {
        robotunGoruntusu[i] = (int *)malloc(goruntuBoyutuN * sizeof(int));//yler i�in tek tek bellek ay�rma
    }
     
	int elleGirilenMatris[10][10] = { //bu matris de�erleri kullan�c� kendisi girmek istedi�inde de�i�tirmesi gereken k�s�m. N say�s�na yan� goruntuBoyutuN de�i�keninin tuttu�u say�ya
	                          //uygun olup olmad���na dikkat edilmelidir. Boyut N*N olmal�d�r
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
    };  //robottan gelen g�r�nt�n�n elle ayarlanmas�. Program �al��t���ndan bunun kullan�m� veya rastgele olu�turulmas�na dair bir soru soruluyor. 
        //Program�n do�ru �al��t���n� g�stermek i�in, �imdilik ortaya aranan k�sm� birebir koyup geri kalan yerleri s�f�r yapt�m. �ste�e g�re de�i�tirilip program ba�tan �al��t�r�labilir

    for (i = 0; i < goruntuBoyutuN; i++) {//elle girilen matrisi program boyunca kullan�lan robotun g�r�nt�s� matrisine e�itleyen d�ng�ler
       for (j = 0; j < goruntuBoyutuN; j++) {
        robotunGoruntusu[i][j] = elleGirilenMatris[i][j];//e�itleme i�lemi
        }
     }
     
  
  	//aranacak matrixin dinamik bellek ile olu�turulmas�:
    int **arananMatris = (int**)malloc(arananMatrisBoyutu*sizeof(int*));//ana bellek ay�rma
    for(i=0; i < arananMatrisBoyutu; i++) {
        arananMatris[i] = (int *)malloc(arananMatrisBoyutu * sizeof(int));//yler i�in tek tek bellek ay�rma
    }
    
    int arananMatrisElle[3][3] = {//bu matris de�erleri kullan�c� kendisi girmek istedi�inde de�i�tirmesi gereken k�s�m. N say�s�na yani arananMatrisBoyutu de�i�keninin tuttu�u say�ya
	                          //uygun olup olmad���na dikkat edilmelidir. Boyut N*N olmal�d�r
    {0, 1, 0},
    {0, 1, 0},
    {1, 1, 1}
    }; //buradaki aranan matris. Sorudakinin ayn�s�,elle de�i�tirlenilir
    
    for (i = 0; i < arananMatrisBoyutu; i++) {//elle girilen matrisi program boyunca kullan�lan aranan matrisine e�itleyen d�ng�ler
       for (j = 0; j < arananMatrisBoyutu; j++) {
        arananMatris[i][j] = arananMatrisElle[i][j];//e�itleme i�lemi
        }
     }

     if(rastgeleDegerlerAtaBoolTercih1 && rastgeleDegerlerAtaBoolTercih2){//tercihlere g�re matrislere rastgele de�erler atanmas�
     	rastgeleDegerlerAta(robotunGoruntusu,goruntuBoyutuN);
     	rastgeleDegerlerAta( arananMatris,arananMatrisBoyutu);
	 }else if(rastgeleDegerlerAtaBoolTercih1 ){//e�er ikisi de r se�ilmi�se iki matrise de rastgele de�erler atar. yaln�zca ilki r se�ilmi�se ona rastgele de�erler atar
	 	rastgeleDegerlerAta(robotunGoruntusu,goruntuBoyutuN);
	 }else{//e�er bu blo�a kadar inebildiyse yaln�zca aranan matris r se�ilmi�tir ona rastgele de�erler atar ve program devam eder
	 	rastgeleDegerlerAta( arananMatris,arananMatrisBoyutu);
	 }
	 
    //=================================================================================================================================================


    for(i=0;i<1+goruntuBoyutuN-arananMatrisBoyutu;i++){//b�y�k bir karenin i�erisinde daha k���k bir kareyi arad���m�z i�in 1+goruntuBoyutuN-arananMatrisBoyutu defa arama yapmamz
                                                       //yeterlidir. i ve j'yi s�f�rdan ba�latt���m�zda ise t�m olas� ihtimalleri arayabiliriz
      for(j=0;j<1+goruntuBoyutuN-arananMatrisBoyutu;j++){
      	 printf("\nburada aran�yor...\n");//��kt�n�n okunakl� olmas� i�in konulmu� kesme i�aretleri
      	 matrixiYazdir(robotunGoruntusu,goruntuBoyutuN);//��kt�n�n okunakl� olmas� ve kullan�c�n�n t�m ad�mlar� g�r�p isterse takip edebilmesi i�in aranan matris her seferinde ba�a yazd�r�l�r
        
    	 if(enBenzerBenzemeSayisi<belirliKismiAra(robotunGoruntusu,arananMatris,arananMatrisBoyutu,i,j)){//e�er �u anda denenen aranan matrisin benzeme miktar� eskisinden daha fazlaysa
    	                                                                              //yeni en �ok benzeyeni o ilan ediyor
    	 	enBenzerBenzemeSayisi=belirliKismiAra(robotunGoruntusu,arananMatris,arananMatrisBoyutu,i,j);//yeni en �ok benzeyenin benzeme miktar�n�n g�ncellenmesi
    	 	x1 = i;//yeni en �ok benzeyenin koordinatlar�n�n g�ncellenmesi
    	 	y1 = j;
		 }
	 }
	}
	printf("Not: Kendi elinizle arama se�ene�ini se�ip, matrise kod k�sm�ndan uygun boyut de�i�ikliklerini yapmad�ysan�z bozulmalar olu�abilir. Boyutlar� d�zenleyip tekrar deneyiniz");
	printf("\n====================================================================\n");//��kt�n�n okunakl� olmas� i�in konulmu� kesme i�aretleri
	printf("\nAranan K�s�m:\n");
	matrixiYazdir(arananMatris,arananMatrisBoyutu);//kullan�c� i�in arad���m�z matrisi yazd�r�yor
    printf("\nEn �ok benzeyen K�s�m:\n");
    for(i = x1; i < x1 + arananMatrisBoyutu; i++){//kullan�c� i�in x1 ve y1'i kullanarak en �ok benzeyen k�sm� yazd�r�yor
        for(j = y1; j < y1 + arananMatrisBoyutu; j++){
           printf("%d ", robotunGoruntusu[i][j]);//yazd�rma
        }
    printf("\n");//her yeni sat�rda a�a�� inme
   }
   	
	printf("\nBenzeme Say�s�/miktar�: %d\n",enBenzerBenzemeSayisi);//kullan�c� i�in benzeme miktar�n� yazd�r�yor
   printf("\n(x,y) Matematiksel Koordinatlar�(benzeyen 3x3'luk matrisin sol ust k��esini ifade eder): x: %d y: %d ",y1+1,goruntuBoyutuN-x1);//koordinatla� yazd�r�yor. Ancak kulllan�c�n�n daha ra-
   //hat g�rebilmesi i�in matematiksel olarak yazd�r�yor:
 
   //|(y ekseni)
   //|
   //|
   //|(1,10)(2,10)...(10,10)
   //|(1,9)..       ..(10,9)
   //|.                 .
   //|.                 .
   //|(1,1)(2,1)......(10,1)
   //-------------------------------(x ekseni)
   
   // Bunun sa�lanmas� x1,y1 de�il de y1+1,goruntuBoyutuN-x1 �eklinde printf'e yaz�l�yor

	printf("\nRobottan gelen g�r�nt�:\n");//kullan�c� i�in son defa 10x10'luk matrisin yaz�lmas�
	matrixiYazdir(robotunGoruntusu,goruntuBoyutuN);

    //belleklerin serberst b�rak�lmas�:
    for(i=0; i < goruntuBoyutuN; i++) {
        free(robotunGoruntusu[i]); // yleri serbest b�rak�r
    }
    free(robotunGoruntusu); // ana bellek blo�unu serbest b�rak�r
    
     for(i=0; i < arananMatrisBoyutu; i++) {
        free(arananMatris[i]); // yleri serbest b�rak�r
    }
    free(arananMatris); // ana bellek blo�unu serbest b�rak
   
   printf("\ntekrar denemek ister misiniz?(y/n)");
   getchar();//ayn� �ekilde bir hatadan dolay� program�n direk ge�memesi i�in bekletme
   scanf("%c",&tekrar);//kullan�c�n�n program� tekrar �al��t�rmak isteyip istemedi�inin tercihini alma
     if(tekrar=='y'){
     	continue;//e�er devam etmek isterse d�ng� ile program ba�tan ba�lar
	 }else{
	 	break;//e�er istemezse d�ng� k�r�l�r program biter
	 }
   }
    return 0;//program�n sonlanmas�
}

