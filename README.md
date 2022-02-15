# Artificial Neural Networks
 
 Yapay sinir ağının perceptron ve delta learning tekniklerini kullanarak iki ve daha fazla örneği birbirinden ayırabiliriz. İlk kısımda tek katmanlı yapay sinir ağında iki örneği birbirinden nasıl ayrıştırabileceğimizi anlatacağım. İkinci kısımda ise çok katmanlı yapay sinir ağlarında ikiden fazla örnek geldiğinde bu örnekleri bire karşı hepsi kavramıyla bu örneklerin birbirinden nasıl ayrıldığını göstermiş olacağım.


# •Single Layer

 Öncellikle iki boyutlu düzlemde herhangi bir işlemi gerçekleştirebilmek için bir form oluşturdum. Daha sonra ana eksen doğrularını çizdirmek için pictureBox'ın event özelliğine gelip paint kısmına çift tıklayarak pictureBox1_Paint_1 fonksiyonunda gerekli işlemleri gerçekleştirdim. Form ekranı yükleniyorken; yani ilk çalıştırıldığında toplam örnek sayısı, class1 ve class2’deki örnek sayıları 0 olarak setlenmiş bir şekilde ayarladım. Sonrasında 2-boyutlu düzlem üzerinde örneklerimizi çizdirebilmek için pictureBox’ın event özelliğine gelip mouse click kısmına çift tıklayarak pictureBox1_MouseClick fonksiyonunda gerekli işlemleri gerçekleştirdim. Burada örneklerimizin çizdiğimiz ana eksen doğrularına göre düzgün koordinatları alabilmesi için noktalari ana eksenin merkezine taşıdım ve check_Class1 ve check_Class2 ile de çizilen örneklerin hangi sınıfa ait çizileceğini ayarladım. Resourche.h dosyasında ise Class1 için 0 Class2 için ise 1 tanımladım. Her örnek çizdirildiğinde ilgili sınıftaki sample sayısı ile toplam sample sayısı arttırılarak label2’de gösterilmesini sağladım.
Eğitim işlemini geçmeden önce ana eksen üzerinde iki sınıfı birbirinden ayırmak için kullanacağımız doğruyu randomlyToolStripMenuItem_Click fonksiyonuyla çizdirdim. Çizdirme işlemini doğrunun denklemiyle, yani;

 w0x1 + w1x2 + w2 = 0 
 
ile hesaplarız.
Y koordinatlarını Resource.h dosyasındaki YPoint fonksiyonuyla hesapladım.
Şimdi ise gelelim, form’da çizdirdiğimiz iki sınıfı ayırabileceğimiz tekniklere;

Bunlar;

1)Ayrık aktivasyon fonksiyonu

2)Sürekli aktivasyon fonksiyonu


# 1)Ayrık Aktivasyon Fonksiyon (Binary Discrete)


 Ayrık aktivasyon fonksiyonlu training işlemini binaryDiscToolStripMenuItem_Click fonksiyonu içerisinde gerçekleştirdim. En başta pictureBox’ı refresh ederek tüm örnekleri sildim ve tekrar ilgili rengiyle birlikte bulundukları konuma çizdirme işlemini yaptım. Daha sonrasında ise limit, is_all_done değişkenlerini tanımlayarak döngü içerisinde sample sayısı kadar değer içeren training_result adında bir pointer oluşturdum. Sample sayısı kadar çalışan döngüde her bir örnek geldiğinde perceptron fonksiyonunu çağırır ve training gerçekleştirilip training_result dizisine ilgili örnek için training tamamlandıysa 1 değeri atanır. Tamamlanmadıysa tekrardan döngü içerisinde 1 olana kadar devam eder. En sonda tüm örnekler için fonksiyon 1 değeri döndürdüyse döngüden çıkılır. Döngüden çıkıldığında, en baştaki döngüde tanımlanan j değişkeni kaça ulaşmışsa o değer limit değer olur. Yani toplam döngü değeri anlamına gelir.
 
 Perceptron.cpp’de yer alan perceptron fonksiyonunu biraz daha incelersek;
 
 ![image](https://user-images.githubusercontent.com/63511659/154136306-74afba49-9ddf-4c3a-ad08-e24518b8b3db.png)


 Perceptron fonksiyonu 3 tane parametre alır. Bunlar;

1) Tüm örneklerin özelliğini barındıran, x1, x2 ve id değişkenleri yer alan Samples structure’dur.
2) Ağırlık katsayıları (pointer w içersisinde örneklerin ağırlık katsayıları bulundurur.)
3) c öğrenme sabiti (c = 0.1)
Training işleminde ilk olarak örneklerin koordinatları ve bias katsayısı(1) ile randomlyToolStripMenu_Click fonksiyonunda elde ettiğimiz ağırlık değerlerini çarpılıp toplanarak net değeri elde edilir.

net = w[0] * x1 + w[1] * x2 + w[2] * bias

 Daha sonra elde edilen net değeri Process.cpp içinde olan sgn(net) fonksiyonu ile çıkış değeri bulunur. Eğer net değer 0’dan büyükse çıkış 1, değilse 0 değerini alır.

output = sgn(net)

 Burada desired yani beklenen çıktılar -> Resource.h’da yer alan Class1 için 0, Class2 için 1 değerleridir. Eğer beklenen çıktı ile output eşit değilse ağırlık katsayıları tekrar tekrar güncellenerek beklenen değer çıkış değerine eşit oluncaya kadar devam eder. Eşit olduğunda fonksiyon 1 değeri döndürür. Training işlemi bittikten sonra iki sınıfı birbirinden ayıran doğru pictureBox içinde çizilir.

w[t+1]= w[t] +c * (desired - output) * x

 Şimdi ise gelelim ikinci fonksiyonumuz olan sürekli aktivasyon fonksiyonuna:

# 2)Sürekli Aktivasyon Fonksiyonu
	
 Sürekli aktivasyon fonksiyonlu training işlemini ise continiousToolStripMenuItem_Click fonksiyonu içerisinde gerçekleştirdim. Örnekleri verip, random olarak doğruyu çizdirdikten sonra Normalize kutucuğunu işaretlenmesi gerekir, yoksa uyarı mesajı gelecektir. Normalize etmemizin amacı işaretlediğimiz verileri istediğimiz formata getirebilmek ve bu verilerin pictureBox içerisinde konumu değişmeyecek şekilde taşımayı sağlamaktır. Bunun için biz her bir verimizin x,y değerlerini pictureBox’ın genişliğine bölmemiz gerekir. Öncellikle pictureBox’ı refresh ederek tüm örnekleri , ilgili renk id değerleriyle bulundukları konuma yerleştirdim. Sonrasında burada da ayrık aktivasyonda olduğu gibi limit ve is_all_done değişkenlerini tanımlayarak döngü içerisine koydum. Ayrık aktivasyon algoritmasi ile aralarındaki tek fark döngü içerisindeki her bir örneği delta fonksiyonuna göre hesaplayıp geri döndürmektir. Mantık iki teknikte de aynı şekildedir. 

 Delta.cpp dosyası içindeki delta fonksiyonunu inceleyelim;
 
 ![image](https://user-images.githubusercontent.com/63511659/154136487-8ee2e4fb-ac3b-4949-bfa6-39e0b1d5a82f.png)

  
 Training işleminde burada da ilk olarak örneklerin koordinatları ve bias katsayısı, ağırlık katsayıları çarpılıp toplanarak net değeri elde edilir. Daha sonra elde edilen değer Process.cpp içinde yer alan sigmoid fonksiyonu yardımıyla çıkış değeri elde edilir.
Eğer beklenen değer ile çıkış değeri arasındaki fark deta.h dosyasında tanımlamış olduğum IS_EQUAL tanımlamasında olduğu gibi 0.4’ten az ise learning tamamlanmıştır ve fonksiyon 1 değeri verir. Eğer değilse ağırlık katsayıları tekrar tekrar güncellenerek adımlar bir kez daha uygulanır.

w[i+1]= w[i] +c * (desired - output) * sigmoid' * x

 Delta öğrenmede, perceptron’dan farklı olarak ağırlık katsayıları güncellenirken türevi 0’dan farklı olan bir aktivasyon fonksiyonu kullanılır. Delta fonksiyonu her bir örnek için beklenen değer ile çıkış arasındaki fark 0.4 hata payından az olana kadar devam eder. Training işlemi tamamlandıktan sonra YPoint fonksiyonuna 3.parametre olarak ekranın genişliğini girdim, böylece ekranın genişliğine bölünen x,y değerleri tekrar ekran genişliği ile çarpılarak eski değerlerine kavuşturdum. En sonda iki sınıfı birbirinden ayıran doğruyu ekranda gösterdim.


 Şimdi de çok katmanlı yapay sinir ağlarında ikiden fazla örnekleri birbirinden nasıl ayırabileceğimize bakalım.


# •Multi Layer

 Öncellikle iki boyutlu düzlemde herhangi bir işlemi gerçekleştirebilmek için bir form oluşturdum. Daha sonra ana eksen doğrularını çizdirmek için pictureBox'ın event özelliğine gelip paint kısmına çift tıklayarak pictureBox1_Paint_1 fonksiyonunda gerekli işlemleri gerçekleştirdim. Form ekranı yükleniyorken; yani ilk çalıştırıldığında toplam örnek sayısı, class1 ve class2’deki örnek sayıları 0 olarak setlenmiş bir şekilde ayarladım. Toplam kaç sınıf üzerinde işlem yapacağımızı classBox’tan seçip index değerini 1 arttırarak classCount değişkenine atayıp buton ile onaylama yaptım. Hangi sınıfın hangi etikete ait olacağını ise etiket’deki değerin 1 eksini alarak classLabel değişkeninde tuttum. Daha sonra 2 boyutlu düzlem üzerinde örneklerimizi çizdirebilmek için pictureBox’ın event özelliğine gelip mouse click kısmına çift tıklayarak pictureBox1_MouseClick fonksiyonunda gerekli işlemleri gerçekleştirdim. Burada örneklerimizin çizdiğimiz ana eksen doğrularına göre düzgün koordinatları alabilmesi için noktalari ana eksenin merkezine taşıdım. Bütün örnekler swich case ile etiketlerine göre belirlenen renklerde çizdirilmesini uyguladım. Her örnek çizdirildiğinde ilgili sınıftaki örnek sayısı ile toplam örnek sayısı artırılarak label4'de gösterilmesini sağladım.
Eğitim işlemini geçmeden önce ana eksen üzerinde iki sınıfı birbirinden ayırmak için kullanacağımız doğruyu randomlyToolStripMenuItem_Click fonksiyonuyla çizdirdim. Çizdirme işlemini doğrunun denklemiyle, yani;

w0x1 + w1x2 + w2 = 0 

ile hesaplarız.
Her sınıf için ağırlık değerlerini rastgele oluşturdum. Y koordinatlarını Resource.h dosyasındaki YPoint fonksiyonuyla hesapladım. Swich case ile ilgili sınıfa göre aynı renkte doğruları çizdirdim.

# 1)Ayrık Aktivasyon Fonksiyon (Binary Discrete)

 
 Ayrık aktivasyon fonksiyonlu training işlemini binaryDiscToolStripMenuItem_Click fonksiyonu içerisinde gerçekleştirdim. En başta pictureBox’ı refresh ederek tüm örnekleri sildim ve tekrar ilgili rengiyle birlikte bulundukları konuma çizdirme işlemini yaptım. Sonra sample sayısı kadar elemanı içinde bulunduran bir tane temp_sample adında pointer dizisi oluşturdum. Tüm örneklerin (x,y) değerleri  temp_sample dizisine ekledim. eğer döngüdeki category değişkenin değeri mevcut örneğin id'sine eşitse, yani aynı sınıftaysa temp_sample’daki mevcut örneğin etiketini 1, geri kalanını 0 yapar. Böylece eğitim yapılırken ilgili sınıfın, diğerlerinden ayrıştırılması sağlanır. Bire karşı hepsi mantığı uygulanır. Sample sayısı kadar çalışan döngüde her bir örnek geldiğinde perceptron fonksiyonunu çağırır ve training gerçekleştirilip training_result dizisine ilgili örnek için training tamamlandıysa 1 değeri atanır. Tamamlanmadıysa tekrardan döngü içerisinde 1 olana kadar devam eder. En sonda tüm örnekler için fonksiyon 1 değeri döndürdüyse döngüden çıkılır. Döngüden çıkıldığında, en baştaki döngüde tanımlanan j değişkeni kaça ulaşmışsa o değer limit değer olur. Yani toplam döngü değeri anlamına gelir.
    
 Perceptron.cpp’de yer alan perceptron fonksiyonunu biraz daha incelersek;
 
 ![image](https://user-images.githubusercontent.com/63511659/154136700-39fbe369-7076-4f2c-8943-bf00402de450.png)

 
 Perceptron fonksiyonu 3 tane parametre alır. Bunlar;
1) Tüm örneklerin özelliğini barındıran, x1, x2 ve id değişkenleri yer alan Samples structure’dur.
2) Ağırlık katsayıları (pointer w içersisinde örneklerin ağırlık katsayıları bulundurur.)
3) c öğrenme sabiti (c = 0.1)
Training işleminde ilk olarak örneklerin koordinatları ve bias katsayısı(1) ile randomlyToolStripMenu_Click fonksiyonunda elde ettiğimiz ağırlık değerlerini çarpılıp toplanarak net değeri elde edilir.

net = w[0] * x1 + w[1] * x2 + w[2] * bias

 Daha sonra elde edilen net değeri Process.cpp içinde olan sgn(net) fonksiyonu ile çıkış değeri bulunur. Eğer net değer 0’dan büyükse çıkış 1, değilse 0 değerini alır.
output = sgn(net)
Burada desire yani beklenen değerler, temp_sample pointer dizisinin id değerleridir. Eğer beklenen çıktı ile output eşit değilse ağırlık katsayıları tekrar tekrar güncellenerek beklenen değer çıkış değerine eşit oluncaya kadar devam eder. Eşit olduğunda fonksiyon 1 değeri döndürür.

# 2)Sürekli Aktivasyon Fonksiyonu
	
 Sürekli aktivasyon fonksiyonlu training işlemini ise continiousToolStripMenuItem_Click fonksiyonu içerisinde gerçekleştirdim. Örnekleri verip, random olarak doğruyu çizdirdikten sonra Normalize kutucuğunu işaretlenmesi gerekir, yoksa uyarı mesajı gelecektir. Normalize etmemizin amacı işaretlediğimiz verileri istediğimiz formata getirebilmek ve bu verilerin pictureBox içerisinde konumu değişmeyecek şekilde taşımayı sağlamaktır. Bunun için biz her bir verimizin x,y değerlerini pictureBox’ın genişliğine bölmemiz gerekir. Öncellikle pictureBox’ı refresh ederek tüm örnekleri , ilgili renk id değerleriyle bulundukları konuma yerleştirdim. Sonrasında burada da ayrık aktivasyonda olduğu gibi limit ve is_all_done değişkenlerini tanımlayarak döngü içerisine koydum. Ayrık aktivasyon algoritmasi ile aralarındaki tek fark döngü içerisindeki her bir örneği delta fonksiyonuna göre hesaplayıp geri döndürmektir. Mantık iki teknikte de aynı şekildedir. 

 Delta.cpp dosyası içindeki delta fonksiyonunu inceleyelim;
 
 ![image](https://user-images.githubusercontent.com/63511659/154136780-a57c8c0b-3c48-4e39-a0bb-94ffae53e9ac.png)

 
 Training işleminde burada da ilk olarak örneklerin koordinatları ve bias katsayısı, ağırlık katsayıları çarpılıp toplanarak net değeri elde edilir. Daha sonra elde edilen değer Process.cpp içinde yer alan sigmoid fonksiyonu yardımıyla çıkış değeri elde edilir.
Eğer beklenen değer ile çıkış değeri arasındaki fark delta.h dosyasında tanımlamış olduğum IS_EQUAL tanımlamasında olduğu gibi 0.4’ten az ise learning tamamlanmıştır ve fonksiyon 1 değeri verir. Eğer değilse ağırlık katsayıları tekrar tekrar güncellenerek adımlar bir kez daha uygulanır.
w[i+1]= w[i] +c * (desired - output) * sigmoid' * x

 Delta öğrenmede, perceptron’dan farklı olarak ağırlık katsayıları güncellenirken türevi 0’dan farklı olan bir aktivasyon fonksiyonu kullanılır. Delta fonksiyonu her bir örnek için beklenen değer ile çıkış arasındaki fark 0.4 hata payından az olana kadar devam eder. Training işlemi tamamlandıktan sonra YPoint fonksiyonuna 3.parametre olarak ekranın genişliğini girdim, böylece ekranın genişliğine bölünen x,y değerleri tekrar ekran genişliği ile çarpılarak eski değerlerine kavuşturdum. En sonda iki sınıfı birbirinden ayıran doğruyu ekranda gösterdim.
