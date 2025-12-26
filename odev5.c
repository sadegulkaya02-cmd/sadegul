#include <stdio.h>
#define BOYUT 5

int labirent[BOYUT][BOYUT] = //çok boyutlu dizi şeklinde yazdık
{
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1}
};

int cozum[BOYUT][BOYUT] = {0};

int yolvarMı(int x, int y) //
{
    return (x >= 0 && x < BOYUT &&
            y >= 0 && y < BOYUT &&
            labirent[x][y] == 1 &&//1 ise yol var
            cozum[x][y] == 0);//bu yolu önceden kullandık mı
}

int yolBul(int x, int y) {
    // Çıkış noktası
    if (x == BOYUT - 1 && y == BOYUT - 1) {//labirentin son noktası ise
        cozum[x][y] = 1;
        return 1;//çıkış yolu bulundu
    }

    if (yolvarMı(x, y)) {
        cozum[x][y] = 1;

        
        if (yolBul(x + 1, y)) return 1;//bir alt satıra geç
        if (yolBul(x, y + 1)) return 1;//bir sağ sütuna geç
        if (yolBul(x - 1, y)) return 1;//bir üst satıra geç
        if (yolBul(x, y - 1)) return 1;//bir sol sütuna geç

        cozum[x][y] = 0;//o ise çıkışı daha bulamadık
        return 0;//geri dönderir
    }

    return 0;
}

void yazdir()//matris şeklinde labirentin çözümünü ekrana yazar 
{
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            printf("%d ", cozum[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (labirent[0][0] == 0 || labirent[BOYUT-1][BOYUT-1] == 0) 
    {
        printf("Baslangic veya cikis noktasi gecersiz!\n");
        return 0;
    }

    if (yolBul(0, 0))//(0,0) koordinatından başlayarak çıkışı arar
    {
        printf("Cikis yolu bulundu:\n");//çıkış bulunursa
        yazdir();//yazdır fonksiyonu çağırılarak labirentin çözüm yolunu ekrana yazdırır
    } else //çıkış bulunamazsa
    {
        printf("Cikis yolu bulunamadi!\n");//ekrana çıkış bulunamadı yazdırır
    }

    return 0;
}