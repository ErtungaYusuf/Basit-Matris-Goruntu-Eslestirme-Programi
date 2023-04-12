#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>// programa Türkçe dil desteği eklemek için gereken kütüphanenin dahil edilmesi

void rastgeleDegerlerAta(int** matrix,int N){//10x10'luk matrise rastgele değerler atayan fonksiyon. 
    srand(time(NULL)); //random fonksiyonunun time ile beslenmesi
    int i,j;//döngü indexlerinin oluşturulması
    for(i=0;i<N;i++){//xlerin gezilmesi
        for(j=0;j<N;j++){//ylerin gezilmesi
            matrix[i][j] = rand() % 2; //0 veya 1 olmak üzere gezilen elemanlara tek ek rastgele değer atanması
        }
    }
}
void matrixiYazdir(int** matrix,int N){// matrixi ekrana yazdıran fonksiyon
	 int i,j;//döngü indexlerinin oluşturulması
    for(i=0;i<N;i++){//xlerin gezilmesi
        for(j=0;j<N;j++){//ylerin gezilmesi
           printf("%d ",matrix[i][j]);//gezilen her elemanın yazdırılması
        }
        printf("\n");//her yeni satırda bir aşağı geçilmesi
    }
}

int belirliKismiAra(int** matrix,int** arananMatrix,int arananMatrixboyu, int x1,int y1){//verilen matrisin; x1 ve y1 değerleri ile sınırlandıılmış kısmında
                                                                           //aranan matris ile ne kadar eşleşmeye sahip olduğunu bulan ve bunu döndüren fonksiyon örneğin
                                                                           //main kısmında bu fonksiyon döngü içerisinde çağrılarak olası tüm 3x3'lük kısımların denenmesi sağlanır
	int benzerlikSayaci = 0;//uyuşmaları sayacak olan sayaç
	int i = 0,j = 0;//aranan matrisi gezecek olan index değişkenleri
	int a = 0,b = 0;//üzerinde aama yapılacak matrisi gezmek için kullanılacak döngü değişkenleri

	for(a = x1,i = 0;a<x1+arananMatrixboyu;a++,i++){//Arama işlemini yapar. örneğin 3x3lük matrisi dönmeye 0,0 dan başlamak istediğimizden i ve j 0'dan başlatılır.10x10'luk matrisin istenilen 3x3lük kısmını
	                                  //gezmek itediğimizden a=x1'e, b ise y1'e eşitlenir bu sayede dönmeye istenilen yerden başlanır. 3x3lük bir alan dönmek istedi-
	                                  //ğimiz için a ve b 3 fazlasına eşit oluncaya kadar devam eder.
	   for(b = y1,j = 0;b<y1+arananMatrixboyu;b++,j++){
	   	printf("matrix[%d][%d]: %d - arananMatrix[%d][%d]: %d\n",a,b,matrix[a][b],i,j,arananMatrix[i][j]);//arama işleminin nasıl olduğunun kullanıcı tarafından da görülebilmesi için
	   	                                                                                                  //her arama sonucu yazdırır
	   	if(*(matrix[a] + b) == *(arananMatrix[i] + j)){//matrix[a] matrix[a][index]'in ilk elemanını ifade eder, o halde *(matrix[a]+b) yapılarak matrix[a][b]'ye ulaşılabilir
	   	                                               //aynısı arananMatrix için de geçerlidir
	   		benzerlikSayaci++; //eğer bir eşleşme varsa sayaç 1 arttırılıyor
		   }
	   }
     printf("\n------------------------------\n");//çıktının okunaklı olması için konulmuş kesme işaretleri
	}
	printf("\nbulunan toplam benzerlik sayisi: %d\n\n\n",benzerlikSayaci);//bulunan toplam benzerlik sayısı yazdırılıyor
		 printf("\n==========================================================\n");//çıktının okunaklı olması için konulmuş kesme işaretleri
	return benzerlikSayaci;//sayaç döndürülüyor
	
}

int main() {
	
	setlocale(LC_ALL, "Turkish");//Türkçe dil desteğinin eklenmesi
	
	int goruntuBoyutuN;//üzerinde arama yapılaccak matrixin boyutunu tutan değişken
	int arananMatrisBoyutu;//aranacak matrisin boyutunu tutan değişken
	int x1=0,y1=0;//bulunan kısmın koordinatlarını tutacak değişkenler
    int enBenzerBenzemeSayisi = 0;//en çok uyuşanın ne kadar hücresinin uyuştuğunu tutacak değişken
    int rastgeleDegerlerAtaBoolTercih1 = 0;//sorularda verilen cevapların uygulanmasını sağlayacak değişkenler doğrudan tercih1 ve tercih2 değişkenleri de kullanılabilir ancak 
                                           //okunaklı olması için bu şekilde yapılmıştır
    int rastgeleDegerlerAtaBoolTercih2 = 0;
        
    //Kullanıcıya rastgele veya elle ayarlanmış matriste arama yapma seçeneği sunan soru:
    char tercih1;//tercihi tutacak değişken
    char tercih2;
    char tekrar;//kullanıcının program bitiminde dilerse programı tekrar denemesini sağlayan tercihi tutan değişken
    while(1){
	    x1=0,y1=0;//programın her baştan çalışışında değerlerin sıfırlanması:
	    
	    enBenzerBenzemeSayisi = 0;
	    rastgeleDegerlerAtaBoolTercih1 = 0;
	    rastgeleDegerlerAtaBoolTercih2 = 0;
	    
    	while(1){
    	printf("\nRobottan gelen görüntü matisinin N*N boyutunu seçin\n N:");
    	scanf("%d",&goruntuBoyutuN);//üzerinde arama yapılacak matrisin boyut seçimi
    	
    	printf("\nAranacak matisin N*N boyutunu seçin\n N:");
    	scanf("%d",&arananMatrisBoyutu);//aranacak matrisin boyut seçimi

    	printf("\nKendi Belirlediğiniz matrisde mi arama yapmak istersiniz yoksa rastgele bir matris üzerinden mi arama yapmak istersiniz?\n");
		printf("\nÖnemli not: Kendi belirleyeceğiniz matrisi seçerseniz kod kısmından matrislerinizin boyutlarının seçtiğiniz boyutlara uygun olduğundan emin olmak zorundasınız\n");
		printf("\n(rastgel icin r, kendi belirlediğiniz icin k yazınız):");//üzerinde arama yapılacak matrisin rastgelelik seçimi
   	    getchar();//bir hatadan dolayı programın direk geçmemesi için bekletme
	   	scanf("%c",&tercih1);//kullanıcının isteği doğrultusunda cevabı alır ve tercih1 değişkenine atar
	   	
	   	printf("\nKendi Belirlediğiniz matrisi mi aramak istersiniz yoksa rastgele bir matrisi mi?\n");
	   	printf("\n(rastgel icin r, kendi belirlediğiniz için k yazınız):");//aranacak matrisin rastgelelik seçimi
   	    getchar();//aynı şekilde bir hatadan dolayı programın direk geçmemesi için bekletme
	   	scanf("%c",&tercih2);//kullanıcının isteği doğrultusunda cevabı alır ve tercih2 değişkenine atar
    
        //tercihlere göre bool değişkenlerinin belirlenmesi:
        //eğer ikisi de r seçildiyse rastgele boollarını 1 yapar. Eğer birisi seçilmişse yalnızca seçilenin bool'unu 1 yapar
    	if(tercih1=='r' && tercih2=='r'){
    		rastgeleDegerlerAtaBoolTercih1 = 1;
    	    rastgeleDegerlerAtaBoolTercih2 = 1;
    		break;//döngüyü bitirir ve aramayı başlatır
		}else if(tercih1=='k' && tercih2=='r'){
    	    rastgeleDegerlerAtaBoolTercih2 = 1;  
		    break;
		}else if(tercih1=='r' && tercih2=='k'){
	        rastgeleDegerlerAtaBoolTercih1 = 1; 
		    break;
        }else{
        	break;//hiç biri değilse program default başlatılır
		}
   
}
    
	//==========================================================================================================================================
	int i,j;//main içerisinde kullanılacak olan döngülerin döngü değişkenlerinin oluşturulması
	
	//üzerinde arama yapılacak matrixin dinamik bellek ile oluşturulması:
	int **robotunGoruntusu = (int**)calloc(goruntuBoyutuN , sizeof(int*));tuN * sizeof(int*));       
	for(i=0; i < goruntuBoyutuN; i++) {	                        
        robotunGoruntusu[i] = (int *)calloc(goruntuBoyutuN , sizeof(int));//yler için tek tek bellek ayırma
    }
     
	int elleGirilenMatris[10][10] = { //bu matris değerleri kullanıcı kendisi girmek istediğinde değiştirmesi gereken kısım. N sayısına yanı goruntuBoyutuN değişkeninin tuttuğu sayıya
	                          //uygun olup olmadığına dikkat edilmelidir. Boyut N*N olmalıdır
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
    };  //robottan gelen görüntünün elle ayarlanması. Program çalıştığından bunun kullanımı veya rastgele oluşturulmasına dair bir soru soruluyor. 
        //Programın doğru çalıştığını göstermek için, şimdilik ortaya aranan kısmı birebir koyup geri kalan yerleri sıfır yaptım. İsteğe göre değiştirilip program baştan çalıştırılabilir

    for (i = 0; i < goruntuBoyutuN; i++) {//elle girilen matrisi program boyunca kullanılan robotun görüntüsü matrisine eşitleyen döngüler
       for (j = 0; j < goruntuBoyutuN; j++) {
        robotunGoruntusu[i][j] = elleGirilenMatris[i][j];//eşitleme işlemi
        }
     }
     
  
  	//aranacak matrixin dinamik bellek ile oluşturulması:
    int **arananMatris = (int**)calloc(arananMatrisBoyutu , sizeof(int*));//ana bellek ayırma
    for(i=0; i < arananMatrisBoyutu; i++) {
        arananMatris[i] = (int *)calloc(arananMatrisBoyutu , sizeof(int));//yler için tek tek bellek ayırma
    }
    
    int arananMatrisElle[3][3] = {//bu matris değerleri kullanıcı kendisi girmek istediğinde değiştirmesi gereken kısım. N sayısına yani arananMatrisBoyutu değişkeninin tuttuğu sayıya
	                          //uygun olup olmadığına dikkat edilmelidir. Boyut N*N olmalıdır
    {0, 1, 0},
    {0, 1, 0},
    {1, 1, 1}
    }; //buradaki aranan matris. Sorudakinin aynısı,elle değiştirlenilir
    
    for (i = 0; i < arananMatrisBoyutu; i++) {//elle girilen matrisi program boyunca kullanılan aranan matrisine eşitleyen döngüler
       for (j = 0; j < arananMatrisBoyutu; j++) {
        arananMatris[i][j] = arananMatrisElle[i][j];//eşitleme işlemi
        }
     }

     if(rastgeleDegerlerAtaBoolTercih1 && rastgeleDegerlerAtaBoolTercih2){//tercihlere göre matrislere rastgele değerler atanması
     	rastgeleDegerlerAta(robotunGoruntusu,goruntuBoyutuN);
     	rastgeleDegerlerAta( arananMatris,arananMatrisBoyutu);
	 }else if(rastgeleDegerlerAtaBoolTercih1 ){//eğer ikisi de r seçilmişse iki matrise de rastgele değerler atar. yalnızca ilki r seçilmişse ona rastgele değerler atar
	 	rastgeleDegerlerAta(robotunGoruntusu,goruntuBoyutuN);
	 }else{//eğer bu bloğa kadar inebildiyse yalnızca aranan matris r seçilmiştir ona rastgele değerler atar ve program devam eder
	 	rastgeleDegerlerAta( arananMatris,arananMatrisBoyutu);
	 }
	 
    //=================================================================================================================================================


    for(i=0;i<1+goruntuBoyutuN-arananMatrisBoyutu;i++){//büyük bir karenin içerisinde daha küçük bir kareyi aradığımız için 1+goruntuBoyutuN-arananMatrisBoyutu defa arama yapmamz
                                                       //yeterlidir. i ve j'yi sıfırdan başlattığımızda ise tüm olası ihtimalleri arayabiliriz
      for(j=0;j<1+goruntuBoyutuN-arananMatrisBoyutu;j++){
      	 printf("\nburada aranıyor...\n");//çıktının okunaklı olması için konulmuş kesme işaretleri
      	 matrixiYazdir(robotunGoruntusu,goruntuBoyutuN);//çıktının okunaklı olması ve kullanıcının tüm adımları görüp isterse takip edebilmesi için aranan matris her seferinde başa yazdırılır
        
    	 if(enBenzerBenzemeSayisi<belirliKismiAra(robotunGoruntusu,arananMatris,arananMatrisBoyutu,i,j)){//eğer şu anda denenen aranan matrisin benzeme miktarı eskisinden daha fazlaysa
    	                                                                              //yeni en çok benzeyeni o ilan ediyor
    	 	enBenzerBenzemeSayisi=belirliKismiAra(robotunGoruntusu,arananMatris,arananMatrisBoyutu,i,j);//yeni en çok benzeyenin benzeme miktarının güncellenmesi
    	 	x1 = i;//yeni en çok benzeyenin koordinatlarının güncellenmesi
    	 	y1 = j;
		 }
	 }
	}
	printf("Not: Kendi elinizle arama seçeneğini seçip, matrise kod kısmından uygun boyut değişikliklerini yapmadıysanız bozulmalar oluşabilir. Boyutları düzenleyip tekrar deneyiniz");
	printf("\n====================================================================\n");//çıktının okunaklı olması için konulmuş kesme işaretleri
	printf("\nAranan Kısım:\n");
	matrixiYazdir(arananMatris,arananMatrisBoyutu);//kullanıcı için aradığımız matrisi yazdırıyor
    printf("\nEn çok benzeyen Kısım:\n");
    for(i = x1; i < x1 + arananMatrisBoyutu; i++){//kullanıcı için x1 ve y1'i kullanarak en çok benzeyen kısmı yazdırıyor
        for(j = y1; j < y1 + arananMatrisBoyutu; j++){
           printf("%d ", robotunGoruntusu[i][j]);//yazdırma
        }
    printf("\n");//her yeni satırda aşağı inme
   }
   	
	printf("\nBenzeme Sayısı/miktarı: %d\n",enBenzerBenzemeSayisi);//kullanıcı için benzeme miktarını yazdırıyor
   printf("\n(x,y) Matematiksel Koordinatları(benzeyen 3x3'luk matrisin sol ust köşesini ifade eder): x: %d y: %d ",y1+1,goruntuBoyutuN-x1);//koordinatlaı yazdırıyor. Ancak kulllanıcının daha ra-
   //hat görebilmesi için matematiksel olarak yazdırıyor:
 
   //|(y ekseni)
   //|
   //|
   //|(1,10)(2,10)...(10,10)
   //|(1,9)..       ..(10,9)
   //|.                 .
   //|.                 .
   //|(1,1)(2,1)......(10,1)
   //-------------------------------(x ekseni)
   
   // Bunun sağlanması x1,y1 değil de y1+1,goruntuBoyutuN-x1 şeklinde printf'e yazılıyor

	printf("\nRobottan gelen görüntü:\n");//kullanıcı için son defa 10x10'luk matrisin yazılması
	matrixiYazdir(robotunGoruntusu,goruntuBoyutuN);

    //belleklerin serberst bırakılması:
    for(i=0; i < goruntuBoyutuN; i++) {
        free(robotunGoruntusu[i]); // yleri serbest bırakır
    }
    free(robotunGoruntusu); // ana bellek bloğunu serbest bırakır
    
     for(i=0; i < arananMatrisBoyutu; i++) {
        free(arananMatris[i]); // yleri serbest bırakır
    }
    free(arananMatris); // ana bellek bloğunu serbest bırak
   
   printf("\ntekrar denemek ister misiniz?(y/n)");
   getchar();//aynı şekilde bir hatadan dolayı programın direk geçmemesi için bekletme
   scanf("%c",&tekrar);//kullanıcının programı tekrar çalıştırmak isteyip istemediğinin tercihini alma
     if(tekrar=='y'){
     	continue;//eğer devam etmek isterse döngü ile program baştan başlar
	 }else{
	 	break;//eğer istemezse döngü kırılır program biter
	 }
   }
    return 0;//programın sonlanması
}

