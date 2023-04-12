1-10x10'luk rastgele matriste 3x3'lük soruda belirtilen matrisi aramak için sorulara sırasıyla:
    10,3,r,k cevaplarını vermeniz yeterlidir. Farklı aramalar yapmak da mümkündür.


2-Kendi elinizle belirlediğiniz matrisleri; kod kısmından aşağıdaki matrisleri değitirip,program başında sorulara uygun cevaplar vererek kullanabilirsiniz
========================================
 int arananMatrisElle[3][3] = {//aranacak olan matris, satır 148
    {0, 1, 0},
    {0, 1, 0},
    {1, 1, 1}
    }; 
========================================
	int elleGirilenMatris[10][10] = {//içerisinde arama yapılacak matris,  satır 120
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
    };
=======================================
  

Notlar:
1-Kendi elinizle arama seçeneğini seçip, matrise kod kısmından uygun boyut değişikliklerini yapmadıysanız bozulmalar oluşabilir. Boyutları düzenleyip tekrar deneyiniz.

2-Rastgele seçeneğini seçtiğiniz durumlarda aranan ve aratılan matrix boyutları birbirine yaklaştıkça rastgele oluşturulan sayılar anormal şekilde benzer olabilir. Bunun sorumlusu srand(time(NULL))'un tam olarak rastgele değerler oluşturmamasıdır. Kendi elinizle belirlediğiniz matrislerde bu sorun olmaz.

3-Aranacak matris boyutu, üzerinde arama yapılacak matrixten büyük olursa program doğru çalışmayacaktır. Hata alırsanız sebebi matrisin boyutlarının bu şekilde tanımlanmasından kaynaklanıyor olabilir.

4-(Bu sorunun sebebi, calloc yerine malloc kullanılması olduğundan kod düzenlenip bu not kaldırılmıştır)
