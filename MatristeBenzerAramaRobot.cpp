#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>// programa Türkçe dil desteði eklemek için gereken kütüphanenin dahil edilmesi

void rastgeleDegerlerAta(int** matrix,int N){//10x10'luk matrise rastgele deðerler atayan fonksiyon. 
    srand(time(NULL)); //random fonksiyonunun time ile beslenmesi
    int i,j;//döngü indexlerinin oluþturulmasý
    for(i=0;i<N;i++){//xlerin gezilmesi
        for(j=0;j<N;j++){//ylerin gezilmesi
            matrix[i][j] = rand() % 2; //0 veya 1 olmak üzere gezilen elemanlara tek ek rastgele deðer atanmasý
        }
    }
}
void matrixiYazdir(int** matrix,int N){// matrixi ekrana yazdýran fonksiyon
	 int i,j;//döngü indexlerinin oluþturulmasý
    for(i=0;i<N;i++){//xlerin gezilmesi
        for(j=0;j<N;j++){//ylerin gezilmesi
           printf("%d ",matrix[i][j]);//gezilen her elemanýn yazdýrýlmasý
        }
        printf("\n");//her yeni satýrda bir aþaðý geçilmesi
    }
}

int belirliKismiAra(int** matrix,int** arananMatrix,int arananMatrixboyu, int x1,int y1){//verilen matrisin; x1 ve y1 deðerleri ile sýnýrlandýýlmýþ kýsmýnda
                                                                           //aranan matris ile ne kadar eþleþmeye sahip olduðunu bulan ve bunu döndüren fonksiyon örneðin
                                                                           //main kýsmýnda bu fonksiyon döngü içerisinde çaðrýlarak olasý tüm 3x3'lük kýsýmlarýn denenmesi saðlanýr
	int benzerlikSayaci = 0;//uyuþmalarý sayacak olan sayaç
	int i = 0,j = 0;//aranan matrisi gezecek olan index deðiþkenleri
	int a = 0,b = 0;//üzerinde aama yapýlacak matrisi gezmek için kullanýlacak döngü deðiþkenleri

	for(a = x1,i = 0;a<x1+arananMatrixboyu;a++,i++){//Arama iþlemini yapar. örneðin 3x3lük matrisi dönmeye 0,0 dan baþlamak istediðimizden i ve j 0'dan baþlatýlýr.10x10'luk matrisin istenilen 3x3lük kýsmýný
	                                  //gezmek itediðimizden a=x1'e, b ise y1'e eþitlenir bu sayede dönmeye istenilen yerden baþlanýr. 3x3lük bir alan dönmek istedi-
	                                  //ðimiz için a ve b 3 fazlasýna eþit oluncaya kadar devam eder.
	   for(b = y1,j = 0;b<y1+arananMatrixboyu;b++,j++){
	   	printf("matrix[%d][%d]: %d - arananMatrix[%d][%d]: %d\n",a,b,matrix[a][b],i,j,arananMatrix[i][j]);//arama iþleminin nasýl olduðunun kullanýcý tarafýndan da görülebilmesi için
	   	                                                                                                  //her arama sonucu yazdýrýr
	   	if(*(matrix[a] + b) == *(arananMatrix[i] + j)){//matrix[a] matrix[a][index]'in ilk elemanýný ifade eder, o halde *(matrix[a]+b) yapýlarak matrix[a][b]'ye ulaþýlabilir
	   	                                               //aynýsý arananMatrix için de geçerlidir
	   		benzerlikSayaci++; //eðer bir eþleþme varsa sayaç 1 arttýrýlýyor
		   }
	   }
     printf("\n------------------------------\n");//çýktýnýn okunaklý olmasý için konulmuþ kesme iþaretleri
	}
	printf("\nbulunan toplam benzerlik sayisi: %d\n\n\n",benzerlikSayaci);//bulunan toplam benzerlik sayýsý yazdýrýlýyor
		 printf("\n==========================================================\n");//çýktýnýn okunaklý olmasý için konulmuþ kesme iþaretleri
	return benzerlikSayaci;//sayaç döndürülüyor
	
}

int main() {
	
	setlocale(LC_ALL, "Turkish");//Türkçe dil desteðinin eklenmesi
	
	int goruntuBoyutuN;//üzerinde arama yapýlaccak matrixin boyutunu tutan deðiþken
	int arananMatrisBoyutu;//aranacak matrisin boyutunu tutan deðiþken
	int x1=0,y1=0;//bulunan kýsmýn koordinatlarýný tutacak deðiþkenler
    int enBenzerBenzemeSayisi = 0;//en çok uyuþanýn ne kadar hücresinin uyuþtuðunu tutacak deðiþken
    int rastgeleDegerlerAtaBoolTercih1 = 0;//sorularda verilen cevaplarýn uygulanmasýný saðlayacak deðiþkenler doðrudan tercih1 ve tercih2 deðiþkenleri de kullanýlabilir ancak 
                                           //okunaklý olmasý için bu þekilde yapýlmýþtýr
    int rastgeleDegerlerAtaBoolTercih2 = 0;
        
    //Kullanýcýya rastgele veya elle ayarlanmýþ matriste arama yapma seçeneði sunan soru:
    char tercih1;//tercihi tutacak deðiþken
    char tercih2;
    char tekrar;//kullanýcýnýn program bitiminde dilerse programý tekrar denemesini saðlayan tercihi tutan deðiþken
    while(1){
	    x1=0,y1=0;//programýn her baþtan çalýþýþýnda deðerlerin sýfýrlanmasý:
	    
	    enBenzerBenzemeSayisi = 0;
	    rastgeleDegerlerAtaBoolTercih1 = 0;
	    rastgeleDegerlerAtaBoolTercih2 = 0;
	    
    	while(1){
    	printf("\nRobottan gelen görüntü matisinin N*N boyutunu seçin\n N:");
    	scanf("%d",&goruntuBoyutuN);//üzerinde arama yapýlacak matrisin boyut seçimi
    	
    	printf("\nAranacak matisin N*N boyutunu seçin\n N:");
    	scanf("%d",&arananMatrisBoyutu);//aranacak matrisin boyut seçimi

    	printf("\nKendi Belirlediðiniz matrisde mi arama yapmak istersiniz yoksa rastgele bir matris üzerinden mi arama yapmak istersiniz?\n");
		printf("\nÖnemli not: Kendi belirleyeceðiniz matrisi seçerseniz kod kýsmýndan matrislerinizin boyutlarýnýn seçtiðiniz boyutlara uygun olduðundan emin olmak zorundasýnýz\n");
		printf("\n(rastgel icin r, kendi belirlediðiniz icin k yazýnýz):");//üzerinde arama yapýlacak matrisin rastgelelik seçimi
   	    getchar();//bir hatadan dolayý programýn direk geçmemesi için bekletme
	   	scanf("%c",&tercih1);//kullanýcýnýn isteði doðrultusunda cevabý alýr ve tercih1 deðiþkenine atar
	   	
	   	printf("\nKendi Belirlediðiniz matrisi mi aramak istersiniz yoksa rastgele bir matrisi mi?\n");
	   	printf("\n(rastgel icin r, kendi belirlediðiniz için k yazýnýz):");//aranacak matrisin rastgelelik seçimi
   	    getchar();//ayný þekilde bir hatadan dolayý programýn direk geçmemesi için bekletme
	   	scanf("%c",&tercih2);//kullanýcýnýn isteði doðrultusunda cevabý alýr ve tercih2 deðiþkenine atar
    
        //tercihlere göre bool deðiþkenlerinin belirlenmesi:
        //eðer ikisi de r seçildiyse rastgele boollarýný 1 yapar. Eðer birisi seçilmiþse yalnýzca seçilenin bool'unu 1 yapar
    	if(tercih1=='r' && tercih2=='r'){
    		rastgeleDegerlerAtaBoolTercih1 = 1;
    	    rastgeleDegerlerAtaBoolTercih2 = 1;
    		break;//döngüyü bitirir ve aramayý baþlatýr
		}else if(tercih1=='k' && tercih2=='r'){
    	    rastgeleDegerlerAtaBoolTercih2 = 1;  
		    break;
		}else if(tercih1=='r' && tercih2=='k'){
	        rastgeleDegerlerAtaBoolTercih1 = 1; 
		    break;
        }else{
        	break;//hiç biri deðilse program default baþlatýlýr
		}
   
}
    
	//==========================================================================================================================================
	int i,j;//main içerisinde kullanýlacak olan döngülerin döngü deðiþkenlerinin oluþturulmasý
	
	//üzerinde arama yapýlacak matrixin dinamik bellek ile oluþturulmasý:
	int **robotunGoruntusu = (int**)malloc(goruntuBoyutuN * sizeof(int*));//ana bellek ayýrma
	for(i=0; i < goruntuBoyutuN; i++) {
        robotunGoruntusu[i] = (int *)malloc(goruntuBoyutuN * sizeof(int));//yler için tek tek bellek ayýrma
    }
     
	int elleGirilenMatris[10][10] = { //bu matris deðerleri kullanýcý kendisi girmek istediðinde deðiþtirmesi gereken kýsým. N sayýsýna yaný goruntuBoyutuN deðiþkeninin tuttuðu sayýya
	                          //uygun olup olmadýðýna dikkat edilmelidir. Boyut N*N olmalýdýr
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
    };  //robottan gelen görüntünün elle ayarlanmasý. Program çalýþtýðýndan bunun kullanýmý veya rastgele oluþturulmasýna dair bir soru soruluyor. 
        //Programýn doðru çalýþtýðýný göstermek için, þimdilik ortaya aranan kýsmý birebir koyup geri kalan yerleri sýfýr yaptým. Ýsteðe göre deðiþtirilip program baþtan çalýþtýrýlabilir

    for (i = 0; i < goruntuBoyutuN; i++) {//elle girilen matrisi program boyunca kullanýlan robotun görüntüsü matrisine eþitleyen döngüler
       for (j = 0; j < goruntuBoyutuN; j++) {
        robotunGoruntusu[i][j] = elleGirilenMatris[i][j];//eþitleme iþlemi
        }
     }
     
  
  	//aranacak matrixin dinamik bellek ile oluþturulmasý:
    int **arananMatris = (int**)malloc(arananMatrisBoyutu*sizeof(int*));//ana bellek ayýrma
    for(i=0; i < arananMatrisBoyutu; i++) {
        arananMatris[i] = (int *)malloc(arananMatrisBoyutu * sizeof(int));//yler için tek tek bellek ayýrma
    }
    
    int arananMatrisElle[3][3] = {//bu matris deðerleri kullanýcý kendisi girmek istediðinde deðiþtirmesi gereken kýsým. N sayýsýna yani arananMatrisBoyutu deðiþkeninin tuttuðu sayýya
	                          //uygun olup olmadýðýna dikkat edilmelidir. Boyut N*N olmalýdýr
    {0, 1, 0},
    {0, 1, 0},
    {1, 1, 1}
    }; //buradaki aranan matris. Sorudakinin aynýsý,elle deðiþtirlenilir
    
    for (i = 0; i < arananMatrisBoyutu; i++) {//elle girilen matrisi program boyunca kullanýlan aranan matrisine eþitleyen döngüler
       for (j = 0; j < arananMatrisBoyutu; j++) {
        arananMatris[i][j] = arananMatrisElle[i][j];//eþitleme iþlemi
        }
     }

     if(rastgeleDegerlerAtaBoolTercih1 && rastgeleDegerlerAtaBoolTercih2){//tercihlere göre matrislere rastgele deðerler atanmasý
     	rastgeleDegerlerAta(robotunGoruntusu,goruntuBoyutuN);
     	rastgeleDegerlerAta( arananMatris,arananMatrisBoyutu);
	 }else if(rastgeleDegerlerAtaBoolTercih1 ){//eðer ikisi de r seçilmiþse iki matrise de rastgele deðerler atar. yalnýzca ilki r seçilmiþse ona rastgele deðerler atar
	 	rastgeleDegerlerAta(robotunGoruntusu,goruntuBoyutuN);
	 }else{//eðer bu bloða kadar inebildiyse yalnýzca aranan matris r seçilmiþtir ona rastgele deðerler atar ve program devam eder
	 	rastgeleDegerlerAta( arananMatris,arananMatrisBoyutu);
	 }
	 
    //=================================================================================================================================================


    for(i=0;i<1+goruntuBoyutuN-arananMatrisBoyutu;i++){//büyük bir karenin içerisinde daha küçük bir kareyi aradýðýmýz için 1+goruntuBoyutuN-arananMatrisBoyutu defa arama yapmamz
                                                       //yeterlidir. i ve j'yi sýfýrdan baþlattýðýmýzda ise tüm olasý ihtimalleri arayabiliriz
      for(j=0;j<1+goruntuBoyutuN-arananMatrisBoyutu;j++){
      	 printf("\nburada aranýyor...\n");//çýktýnýn okunaklý olmasý için konulmuþ kesme iþaretleri
      	 matrixiYazdir(robotunGoruntusu,goruntuBoyutuN);//çýktýnýn okunaklý olmasý ve kullanýcýnýn tüm adýmlarý görüp isterse takip edebilmesi için aranan matris her seferinde baþa yazdýrýlýr
        
    	 if(enBenzerBenzemeSayisi<belirliKismiAra(robotunGoruntusu,arananMatris,arananMatrisBoyutu,i,j)){//eðer þu anda denenen aranan matrisin benzeme miktarý eskisinden daha fazlaysa
    	                                                                              //yeni en çok benzeyeni o ilan ediyor
    	 	enBenzerBenzemeSayisi=belirliKismiAra(robotunGoruntusu,arananMatris,arananMatrisBoyutu,i,j);//yeni en çok benzeyenin benzeme miktarýnýn güncellenmesi
    	 	x1 = i;//yeni en çok benzeyenin koordinatlarýnýn güncellenmesi
    	 	y1 = j;
		 }
	 }
	}
	printf("Not: Kendi elinizle arama seçeneðini seçip, matrise kod kýsmýndan uygun boyut deðiþikliklerini yapmadýysanýz bozulmalar oluþabilir. Boyutlarý düzenleyip tekrar deneyiniz");
	printf("\n====================================================================\n");//çýktýnýn okunaklý olmasý için konulmuþ kesme iþaretleri
	printf("\nAranan Kýsým:\n");
	matrixiYazdir(arananMatris,arananMatrisBoyutu);//kullanýcý için aradýðýmýz matrisi yazdýrýyor
    printf("\nEn çok benzeyen Kýsým:\n");
    for(i = x1; i < x1 + arananMatrisBoyutu; i++){//kullanýcý için x1 ve y1'i kullanarak en çok benzeyen kýsmý yazdýrýyor
        for(j = y1; j < y1 + arananMatrisBoyutu; j++){
           printf("%d ", robotunGoruntusu[i][j]);//yazdýrma
        }
    printf("\n");//her yeni satýrda aþaðý inme
   }
   	
	printf("\nBenzeme Sayýsý/miktarý: %d\n",enBenzerBenzemeSayisi);//kullanýcý için benzeme miktarýný yazdýrýyor
   printf("\n(x,y) Matematiksel Koordinatlarý(benzeyen 3x3'luk matrisin sol ust köþesini ifade eder): x: %d y: %d ",y1+1,goruntuBoyutuN-x1);//koordinatlaý yazdýrýyor. Ancak kulllanýcýnýn daha ra-
   //hat görebilmesi için matematiksel olarak yazdýrýyor:
 
   //|(y ekseni)
   //|
   //|
   //|(1,10)(2,10)...(10,10)
   //|(1,9)..       ..(10,9)
   //|.                 .
   //|.                 .
   //|(1,1)(2,1)......(10,1)
   //-------------------------------(x ekseni)
   
   // Bunun saðlanmasý x1,y1 deðil de y1+1,goruntuBoyutuN-x1 þeklinde printf'e yazýlýyor

	printf("\nRobottan gelen görüntü:\n");//kullanýcý için son defa 10x10'luk matrisin yazýlmasý
	matrixiYazdir(robotunGoruntusu,goruntuBoyutuN);

    //belleklerin serberst býrakýlmasý:
    for(i=0; i < goruntuBoyutuN; i++) {
        free(robotunGoruntusu[i]); // yleri serbest býrakýr
    }
    free(robotunGoruntusu); // ana bellek bloðunu serbest býrakýr
    
     for(i=0; i < arananMatrisBoyutu; i++) {
        free(arananMatris[i]); // yleri serbest býrakýr
    }
    free(arananMatris); // ana bellek bloðunu serbest býrak
   
   printf("\ntekrar denemek ister misiniz?(y/n)");
   getchar();//ayný þekilde bir hatadan dolayý programýn direk geçmemesi için bekletme
   scanf("%c",&tekrar);//kullanýcýnýn programý tekrar çalýþtýrmak isteyip istemediðinin tercihini alma
     if(tekrar=='y'){
     	continue;//eðer devam etmek isterse döngü ile program baþtan baþlar
	 }else{
	 	break;//eðer istemezse döngü kýrýlýr program biter
	 }
   }
    return 0;//programýn sonlanmasý
}

