#include <stdio.h>
#include <string.h>

int main() {
    char mesaj[300];//300 karaktere kadar saklayabilir
    int anahtar, secim;

    printf("1 - Sifrele\n");
    printf("2 - Sifre Coz\n");
    printf("Seciminizi girin: ");
    scanf("%d", &secim);
    getchar(); // boşlukları temizler bu sayede fgets düzgün çalışır

    printf("Mesaji girin: ");
    fgets(mesaj, sizeof(mesaj), stdin);//fgets boşluklar dahil her şeyi okur
    //sizeof(mesaj) ne kadar harf alabilecegini gösterdi
    //stdin ise girilen harfleri klavyeden okunacağını gösterir

    printf("Anahtar degeri girin: ");//anahtar değeri kaç birim kayacağını belirtir
    scanf("%d", &anahtar);

    for (int i = 0; mesaj[i] != '\0'; i++) {

        if (mesaj[i] >= 'a' && mesaj[i] <= 'z') //küçük harf  ve a-z aralığında ise
        {
            if (secim == 1)  // sifreleme seçeneği çıkar
                mesaj[i] = (mesaj[i] - 'a' + anahtar) % 26 + 'a';//küçük harf mi ve a-z aralığında mı
                //harfi 0-25 arası sayıya çevirir (a=0,b=1,....z=25)gibi
                //+anahtar ise anahtar kadar ileri kaydırır
                //%26 mod almadır alfabenin taşmasını önler(z den sonra a getirir)
            else if (secim == 2) // şifre çöz seçeneği çıkar
                mesaj[i] = (mesaj[i] - 'a' - anahtar + 26) % 26 + 'a';
                 //harfi 0-25 arası sayıya çevirir (a=0,b=1,....z=25)gibi
                //-anahtar ise anahtar kadar geri kaydırır
                 //%26 mod almadır alfabenin taşmasını önler(z den sonra a getirir)
        }
//üsttekinin aynısını büyük harf içinde yaptık
        else if (mesaj[i] >= 'A' && mesaj[i] <= 'Z')
//büyük harf mi ve a-z aralığında mı        {
            if (secim == 1)
                mesaj[i] = (mesaj[i] - 'A' + anahtar) % 26 + 'A';
                 //harfi 0-25 arası sayıya çevirir (A=0,B=1,......,Z=25)gibi
                //+anahtar ise anahtar kadar ileri kaydırır
                //%26 mod almadır alfabenin taşmasını önler(Z den sonra A getirir)
                
            else if (secim == 2)
                mesaj[i] = (mesaj[i] - 'A' - anahtar + 26) % 26 + 'A';
                 //harfi 0-25 arası sayıya çevirir (A=0,B=1,.....,Z=25)gibi
                //-anahtar ise anahtar kadar geri kaydırır
                 //%26 mod almadır alfabenin taşmasını önler(Z den sonra A getirir)
        }
    {

    if (secim == 1)//eğer 1 i seçtiğidimizde şifrelemeye geliriz
        printf("Sifrelenmis Mesaj: %s", mesaj);
    else if (secim == 2)//eğer 2 yi seçersek şifre çöze geliriz
        printf("Cozulmus Mesaj: %s", mesaj);
    else
        printf("Gecersiz secim!\n");//1 veya 2 den farklı bişey girersek geçersiz yazdırılır

    return 0;
}}