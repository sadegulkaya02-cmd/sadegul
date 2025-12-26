#include <stdio.h>

int asalMi(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;//sayı asal değilse 0 gönderir
    }
    return 1;//sayı asalsa 1 dönderir
}

int unluMu(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');//seslerin ünlü yada ünsüz olup olmasığını kontrol eder
}

int main() {
    char s1,s2,s3;// s1,s2 ve s3 isimli değisken tanımladık(karakter şeklinde)
    int sayac = 0;

    printf("Gecerli Isimler:\n");

    for (s1 = 'a'; s1 <= 'z'; s1++) {
        for (s2 = 'a'; s2 <= 'z'; s2++) {//s1 ve s2 a'dan z'ye tüm harfleri denemiş

            s3 = s1;  // 1. ve 3. harf aynı olmak zorunda

        
            if (!unluMu(s1) && unluMu(s2) && !unluMu(s3)) {//s1 ve s3 aynı oldğundan ikiside ünsüz ,s2 ünlü olmalı
                int toplam = s1 + s2 + s3;
                if (asalMi(toplam)) {
                    sayac++;
                    printf("%2d. %c%c%c\n", sayac, s1, s2, s3);
                }
            }

            // ünlü-ünsüz-ünlü
            if (unluMu(s1) && !unluMu(s2) && unluMu(s3)) {
                int toplam = s1 + s2 + s3;//ascıı değerleri toplanıyor ve 
                if (asalMi(toplam)) //eğer toplam asalsa
                {
                    sayac++;//sayacı bir arttırıyor
                    printf("%2d. %c%c%c\n", sayac, s1, s2, s3);//ve printf ile ekrana yazdırıyor
                }
            }
        }
    }

    printf("\nToplam gecerli isim sayisi: %d\n", sayac);//sayaç sayesinde geçerli isim sayısını bulup yazdırıyoruz

    return 0;
}