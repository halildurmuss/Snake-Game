# Snake-Game

## Bu projede C++ programlama dili ile “Yılan Oyunu” hazırlanmıştır.

Bu oyunda

- 12x12 boyutunda bir yılan oyunu tahtası hazırlanmıştır.
- Bu tahtanın kenarları aşağıdaki gibi duvar olacak şekilde tasarlandı. Yılanın 10x10’luk kalan alan içerisinde hareketi sağlandı.
- Tahtanın içerisini ise, “.” nokta şeklinde yılanının hareket noktaları temsil edilmiştir.
- Bu tahtada * işareti yılanın yem noktasını, X işareti ise yılanın başlangıç noktasını temsil etmektedir. Yılanın başlangıç noktası sabittir. Birinci satır ikinci sütundan başlayacaktır.

![ornek](https://user-images.githubusercontent.com/66306220/87162216-4bdc4600-c2ce-11ea-9649-904c2333c698.png)

- Yem * sürekli her oyunda rasgele bir yere konumlandırıldı. Rasgele sayı üreterek tahta içerisinde kalması sağlanmaıştır. Yemin yeri sabit değildir, her oyun başlangıcında tahta içerisinde değişken bir yerdedir. Kullanıcı oyunu bitirip ya da başarısız olup tekrar oynamak istediğinde yem başka rasgele bir yere konumlanacaktır.

- Bu oyunda yılan dört yönde hareket etmektedir, çapraz hareket etmemektedir.
- Yılan, büyümeyen cinstendir, yılanın büyüme durumunu yoktur.  Yeme ulaşması halinde oyunu tamamlamaktadır.
- Yılanın dört yönde hareketi wasd tuşları ile sağlanarak yapılmalıdır. Her tuş hareketi sadece 1 adım atmasını sağlar. (Her adımda kullanıcı wasd tuşlarından birine basıp enter tuşuna basabilir)
- Yeme 2 dakika içerisinde ulaşmamız halinde “Oyun başarılı bir şekilde tamamlandı” aksi takdirde “Oyun bitti, başarısız” mesajı ekrana verilecektir.
- Kullanıcı Q ya da q tuşuna basana kadar oyun tekrar tekrar oynayabilir.
- Kullanıcının oyun içerisinde 3 hakkı mevcuttur, duvara değmesi durumunda bu hakkından düşüyor.
- Oyuna her başlandığında oyuncunun 3 hakkı ve toplam 2 dk süresi olduğunu unutmayınız.

## Proje hazırlanmasına dair:

**1.**	Tahtayı iki boyutlu sayı dizisi olarak tutuldu. Bunu yapabildikten sonra, gerisi iki boyutlu bir sayı dizisini ekran yazdırmaktan başka bir şey değildir. 

**2.**  
   **a.**	Kullanıcıdan wasd tuşlarından birini girmesini bekleyerek yukarı, aşağı, sağa, sola hareket etmesi sağlandı.
    
   **b.**	Kullanıcı wasd tuşlarından birine basıp, daha sonra enter tuşuna basarak oyunu yönetebilir. Yılanın sürekli hareketliliği söz konusu değildir, biz tuşlara bastıkça hareket ediyor.
    
   **c.**	Bunun için kullanıcıdan scanf ile karakter alıp kontrol edilmiştir.
  
 **3.**	Kullanıcı q ya da Q tuşuna basmadığı sürece oyunu tekrar tekrar oynayabiliyor. Ekranı temizlemek için, system ( "CLS" ); komutundan yararlanıldı.
 
 **4.**	Oyundaki iki dakika (120sn) süreyi aşağıda saniye cinsinden geçen zamanı gösteren kod ile yazılmıştır. Bunun için  time.h kütüphanesini yararlanılmıştır.
 
 ```
#include <time.h> 
int main(void){

time_t start,end; 
time (&start);

//Kod buraya-- aradaki bütün işlemler yazıldı. 
//Bütün işlemler sonrası geçen zaman. 
time (&end); 
double dif = difftime (end,start); 
printf ("Geçen zaman %.2lf saniyedir.", dif );
}

```
 
 **5.** Yem için rasgele sayı üretme, iki tane 1 ile 10 arası sayı üretildi. Bu sayılardan biri x koordinatını, bir diğeri ise y koordinatını temsil etmektedir. Oyun başlangıcında yemi, bu üretilen rasgele x,y koordinatına koyulmuştur. Bu işlem için, stdlib.h kütüphanesindeki srand ve time fonksiyonlarını yararlanılmıştır. 
```
 srand(time(0));
int random_x = rand() % 10 + 1;
int random_y = rand() % 10 + 1;

```

 ## Örnek Ekran Çıktıları:
 
 - wasd tuşlarından birini girmesini bekleyerek yukarı, aşağı, sağa, sola hareket etmesi sağlandı.
 
 ![ekran_cikti_1](https://user-images.githubusercontent.com/66306220/87163567-39630c00-c2d0-11ea-9a6c-71a5c783e24a.png)
 
 - Yeme 2 dakika içerisinde ulaşmamız halinde “Tebikler Kazandınız!” aksi takdirde mesajı ekrana verilmiştir.
 
 ![ekran_cikti_2](https://user-images.githubusercontent.com/66306220/87163674-66172380-c2d0-11ea-844d-2d3c52251cbd.png)

 - Oyun içerisinde 3 hakkı mevcuttur, duvara değmesi durumunda bu hakkından düşüyor. 3 kere duvara vurduktan sonra ekrana “Başarısız üç hakkınızı tamamladınız!” mesajı verilmiştir.
 
 ![ekran_cikti_3](https://user-images.githubusercontent.com/66306220/87163776-8cd55a00-c2d0-11ea-9b86-9dd020f60e77.png)

 - Oyunun toplam 2 dk süresi olduğu için oyun süresi içinde yem noktasına ulaşamazsa ekrana “Size verilen sürede  oyunu tamamlayamadınız!” mesajı verilmiştir.
 
 ![ekran_cikti_4](https://user-images.githubusercontent.com/66306220/87163964-c908ba80-c2d0-11ea-9150-c6cc26b8c315.png)
