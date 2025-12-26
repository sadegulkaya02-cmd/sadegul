#include <stdio.h>
#include <stdlib.h>     
#include <time.h>

int main() {
    int ciro[12];//12 değeri olmalı çünkü bir yıllık ciroda on iki ay vardır 
    int i, j;
    int max = 0;

        srand(time(NULL));//random sayının yazılmasını sağlar


    
    for (i = 0; i < 12; i++)//döngü 12 kez çalışır her dönüş 1 ayı temsil eder
     {
        ciro[i] = rand() % 10 + 1;//rand=random sayı için kullanılır %10+1 demesi 1 ile 10 arasında sayı ürettirir ve bu sayı o ayın cirosunu temsil eder
        if (ciro[i] > max)//eğer yeni ciro değeri daha büyükse yeni en büyük değer bu ayın cirosu olur
            max = ciro[i];
    }

     
    printf("Aylık Ciro Degerleri:\n");
    for (i = 0; i < 12; i++) {
        printf("%2d. ay: %d\n", i + 1, ciro[i]);//kaçıncı ay olduğunu ve o ayki cirosunu belirttik
    }

    

    printf("\n yatay bar grafiği\n");

    for (i = 0; i < 12; i++)//12 ay olduğu için 12 yazdık 
     {
        printf("%2d.: ", i + 1);
        for (j = 0; j < ciro[i]; j++) {
            printf("* ");//ciro değeri ne çıkarsa o kadar "*" yazdırıdık
        }
        printf("\n");//ve alt satıra geçtik düzenli ve anlaşılır olsun diye
    }

    
    printf("\ndikey bar grafiği\n");

    for (i = max; i > 0; i--) //en yüksek cirodan başlar ve teker teker azalır(i--)  
    {
        for (j = 0; j < 12; j++) 
        {
            if (ciro[j] >= i)//eğer o ayın cirosu ,o an bulunan satıra eşit veya daha büyükse
                printf(" * ");//"*" koyarız
            else
                printf("   ");//değilse boşluk koyarız
        }
        printf("\n");
    }

    for (i = 0; i < 12; i++) //hangi sütun hangi aya aitse onu belirtir
    {
        printf("%2d ", i + 1);
    }

    return 0;
}

