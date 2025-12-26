#include <stdio.h>

int ucgenSayi(int n) {
    if (n == 1)//n 1 eşit ise 
        return 1;//1 döndürür
    else// bire eşit değise
        return n + ucgenSayi(n - 1);//n değerini kendisinden bir önceki sayıyla toplar (n-1) ile
}

int main() {
    int N;// integer değerinde (yani tam sayı olacak şekilde) N değeri tanımladık

    printf("N degerini girin: ");
    scanf("%d", &N);//n değerini girdik
     

    for (int i = 1; i <= N; i++) {//1 den N e kadar olan tüm sayıları ucgenSayi ya gönderip üçgen sayısını buluruz
        printf("%d ", ucgenSayi(i));
    }

    return 0;
}