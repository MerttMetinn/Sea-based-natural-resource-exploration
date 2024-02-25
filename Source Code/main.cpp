#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>

void sekilleriCiz(int *points,int index)
{
    int gd = DETECT, gm;
    int pencereGenislik = 1450;
    int pencereYukseklik = 700;
    initwindow(pencereGenislik, pencereYukseklik, "Birinci Kisim - Sekilleri Cizme");

    int buyutmeFaktoru = 12;
    int birimKareBoyutu = buyutmeFaktoru;

    for (int x = 0; x < pencereGenislik; x += birimKareBoyutu)
    {
        for (int y = 0; y < pencereYukseklik; y += birimKareBoyutu)
        {
            setcolor(2);
            setlinestyle(0, 0, 1);
            rectangle(x, y, x + birimKareBoyutu, y + birimKareBoyutu);
        }
    }

    int baslangic_x1 = -1;
    int baslangic_y1 = -1;
    int son_x = -1;
    int son_y = -1;

    setcolor(15);
    setlinestyle(0, 0, 3);

    for (int i = 0; i < index; i += 2)
    {
        int x1 = points[i];
        int y1 = points[i + 1];

        if (baslangic_x1 == -1 && baslangic_y1 == -1)
        {
            baslangic_x1 = x1;
            baslangic_y1 = y1;
            son_x = x1;
            son_y = y1;
        }
        else
        {
            if (x1 == baslangic_x1 && y1 == baslangic_y1)
            {
                if (son_x != baslangic_x1 || son_y != baslangic_y1)
                {
                    line(son_x * buyutmeFaktoru, son_y * buyutmeFaktoru, baslangic_x1 * buyutmeFaktoru, baslangic_y1 * buyutmeFaktoru);
                }
                baslangic_x1 = -1;
                baslangic_y1 = -1;
            }
            else
            {
                line(son_x * buyutmeFaktoru, son_y * buyutmeFaktoru, x1 * buyutmeFaktoru, y1 * buyutmeFaktoru);
                son_x = x1;
                son_y = y1;
            }
        }
    }
    getch();
}

int sekilleriBoya(int *points, int index)
{
    int gd = DETECT, gm;
    int pencereGenislik = 1450;
    int pencereYukseklik = 700;
    initwindow(pencereGenislik, pencereYukseklik, "Ikinici Kisim - Alan Parcalama");
    int buyutmeFaktoru = 12;
    int birimKareBoyutu = buyutmeFaktoru;

    int baslangic_x1 = -1;
    int baslangic_y1 = -1;
    int son_x = -1;
    int son_y = -1;
    int *polyPoints = (int *)malloc(index * sizeof(int));
    int polyIndex = 0;

    setcolor(15);
    setlinestyle(0, 0, 2);

    for (int i = 0; i < index; i += 2)
    {
        int x1 = points[i];
        int y1 = points[i + 1];

        if (baslangic_x1 == -1 && baslangic_y1 == -1)
        {
            baslangic_x1 = x1;
            baslangic_y1 = y1;
            son_x = x1;
            son_y = y1;
        }
        else
        {
            if (x1 == baslangic_x1 && y1 == baslangic_y1)
            {
                if (son_x != baslangic_x1 || son_y != baslangic_y1)
                {
                    line(son_x * buyutmeFaktoru, son_y * buyutmeFaktoru, baslangic_x1 * buyutmeFaktoru, baslangic_y1 * buyutmeFaktoru);
                    polyPoints[polyIndex] = son_x * buyutmeFaktoru;
                    polyPoints[polyIndex + 1] = son_y * buyutmeFaktoru;
                    polyIndex += 2;
                }
                setfillstyle(SOLID_FILL, CYAN);
                fillpoly(polyIndex / 2, polyPoints);
                polyIndex = 0;
                baslangic_x1 = -1;
                baslangic_y1 = -1;
                son_x = -1;
                son_y = -1;
            }
            else
            {
                line(son_x * buyutmeFaktoru, son_y * buyutmeFaktoru, x1 * buyutmeFaktoru, y1 * buyutmeFaktoru);
                polyPoints[polyIndex] = son_x * buyutmeFaktoru;
                polyPoints[polyIndex + 1] = son_y * buyutmeFaktoru;
                polyIndex += 2;
                son_x = x1;
                son_y = y1;
            }
        }
    }

    int sariKareSayisi = 0;

    for (int x = 0; x < pencereGenislik; x += birimKareBoyutu)
    {
        for (int y = 0; y < pencereYukseklik; y += birimKareBoyutu)
        {
            setcolor(RED);
            setlinestyle(0, 0, 1);
            rectangle(x, y, x + birimKareBoyutu, y + birimKareBoyutu);
            setfillstyle(SOLID_FILL, YELLOW);

            bool isCyan = false;
            for (int i = x + 1; i < x + birimKareBoyutu; i++)
            {
                for (int j = y + 1; j < y + birimKareBoyutu; j++)
                {
                    if (getpixel(i, j) == CYAN)
                    {
                        isCyan = true;
                        break;
                    }
                }
                if (isCyan)
                {
                    break;
                }
            }

            if (isCyan)
            {
                floodfill(x + 1, y + 1, RED);
                sariKareSayisi++;
            }
        }
    }


    printf("\nToplam platform (Sari kare) adedi : %d\n", sariKareSayisi);

    free(polyPoints);
    getch();
    closegraph();

    return sariKareSayisi;
}

void alanhesabi(int *points, int index, float birimSondajMaliyet,float birimPlatformMaliyet,int platform_adedi)
{
    printf("\n|-----------------------------------------------------------------------------|\n");
    int i = 0;
    int poligon = 0;
    float toplam_alan = 0.0;

    while (i < index - 2)
    {
        float alan = 0.0;
        int baslangic = i;
        do
        {
            int x1 = points[i];
            int y1 = points[i + 1];
            int x2 = points[(i + 2) % index];
            int y2 = points[(i + 3) % index];
            alan += (x1 * y2 - x2 * y1);
            i += 2;
        }
        while (points[i] != points[baslangic] || points[i + 1] != points[baslangic + 1]);
        alan = abs(alan) / 2.0;
        printf("\n%d. Poligonun Matematiksel Alan Degeri: %.2f", ++poligon, alan);
        i += 2;
        toplam_alan += alan;
    }
    printf("\n\nHesaplanan Toplam Matematiksel Alan Degeri: %.2f\n",toplam_alan);

    float rezervDegeri = toplam_alan * 10;
    printf("\nToplam Matematiksel Alan * 10 = Kaynak Rezerv Degeri\t\tKaynak Rezerv Degeri : %.2f\n",rezervDegeri);

    float toplamSondajMaliyet = toplam_alan * birimSondajMaliyet;
    printf("\nToplam Matematiksel Alan * BirimSondajMaliyeti = Toplam Sondaj Maliyeti\t\tToplam Sondaj Maliyeti : %.2f\n",toplamSondajMaliyet);

    float toplam_platform_maliyet = birimPlatformMaliyet * platform_adedi;
    printf("\nBirim Platform Maliyeti * Platform Adedi = Toplam Platform Maliyeti\t\tToplam Platform Maliyeti : %.2f\n",toplam_platform_maliyet);

    float maliyet = toplam_platform_maliyet + toplamSondajMaliyet;
    printf("\nMaliyet : %.2f\n",maliyet);

    float kar_miktari = rezervDegeri - maliyet;
    printf("\nKar Miktari : %.2f\n",kar_miktari);
}

int main()
{
    printf("\n|-----------------------------------------------------------------------------|\n");
    system("curl http://zplusorg.com/prolab.txt > veri.txt");
    printf("|-----------------------------------------------------------------------------|\n\n");

    printf("~~~ En uygun alan bolumleme islemini yapan programa Hosgeldiniz! ~~~\n\n");
    float birimSondajMaliyet = 0.0;
    do
    {
        printf("Lutfen birim Sondaj Maliyetini giriniz (1 ile 10 arasi) :");
        scanf("%f", &birimSondajMaliyet);
    }
    while(birimSondajMaliyet < 1.0 || birimSondajMaliyet > 10.0);

    float birimPlatformMaliyet = 0.0;
    printf("Lutfen birim Platform Maliyetini giriniz :");
    scanf("%f",&birimPlatformMaliyet);

    FILE *dosya;
    char satir[100];
    int hedefSatir;

    dosya = fopen("veri.txt", "r");

    if (dosya == NULL)
    {
        printf("Dosya acilamadi.");
        return 1;
    }

    printf("\nHangi satiri yazdirmak ve analiz etmek istersiniz?\n");
    scanf("%d", &hedefSatir);

    int satirSayaci = 1;
    char *hedefSatirIcerik = NULL;

    while (fgets(satir, sizeof(satir), dosya) != NULL)
    {
        if (satirSayaci == hedefSatir)
        {
            char *baslangic = strchr(satir, 'B');
            char *bitis = strchr(satir, 'F');

            if (baslangic != NULL && bitis != NULL && baslangic < bitis)
            {
                baslangic++;
                *bitis = '\0';
                hedefSatirIcerik = baslangic;
            }
            else
            {
                printf("Gecersiz veri.\n");
            }
            break;
        }
        satirSayaci++;
    }
    printf("\nHedef Satir icerik: %s\n", hedefSatirIcerik);

    int points[100];
    char *koordinat = strtok(hedefSatirIcerik, ",()");
    int index = 0;

    while (koordinat != NULL && index < 100)
    {
        points[index] = atoi(koordinat);
        index++;
        koordinat = strtok(NULL, ",()");
    }

    if (index >= 4 && index % 2 == 0)
    {
        printf("Koordinatlar points dizisine atanmistir.\n");

        printf("Points Dizisi: ");
        for (int i = 0; i < index; i++)
        {
            printf("%d %d ", points[i], points[i + 1]);
            i++;
        }
        printf("\n");

    }
    else
    {
        printf("Gecersiz koordinat sayisi.\n");
    }

    sekilleriCiz(points,index);
    int platform_adedi = sekilleriBoya(points,index);
    alanhesabi(points,index,birimSondajMaliyet,birimPlatformMaliyet,platform_adedi);
    closegraph();
    fclose(dosya);
    return 0;
}

