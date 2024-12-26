#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Gerekli değişkenleri global olarak tanımlıyoruz
FILE *dosya;
char *ad[100],*soyad[100],*add,genel[200],*alan[200];
int x1,x2,x3,x4,m;
float aylik[100],enbuyuk;
//İstenilen Structure yapısını tanımlıyoruz
struct Personel {
    char *ad[30];
    char soyad[30];
    float aylik;
};
//Bütün personellerin verisini tutacak diziyi tanımlıyoruz
struct Personel person[12];
//Satis.txt dosyasındaki değerleri strtok kullanarak kelime kelime alan dizisine aktarıyoruz
void ekledegistir() {
    dosya=fopen("C:\\Users\\Can\\Desktop\\satis.txt", "r");
    x1=x2=x3=x4=m=0;
    for (int i=0;i<12;i++) {
        fgets(genel,100,dosya);
        add=strtok(genel," ");
        while( add != NULL ) {
            alan[x1]=strdup(add);
            x1++;
            add = strtok(NULL, " ");
        }
    }
    fclose(dosya);
    for (int i=0;i<12;i++) {
        soyad[x2]=alan[m];
        x2++;m++;
        ad[x3]=alan[m];
        x3++;m++;
        aylik[x4]=strtof(alan[m],NULL);
        x4++;m++;
    }
    //Satış değerlerinin en büyüğünü buluyoruz ve performans değerini satış değeri ile değiştiriyoruz
    for (int i=0;i<12;i++) {
        for (int j=0;j<12;j++) {
                    if (aylik[i]<aylik[j] && aylik[i]!=aylik[j]) {
                enbuyuk=aylik[j];
            }
        }
    }
    for (int i=0;i<12;i++) {
        aylik[i]=enbuyuk-aylik[i];
    }
    //Farklı türlerdeki dizileri strcpy ile daha önce oluşturduğumu Struct dizisine aktarıyoruz
    for (int i=0;i<12;i++) {
        strcpy(person[i].ad, ad[i]);
        strcpy(person[i].soyad, soyad[i]);
        person[i].aylik=aylik[i];
    }
}
//İsimlerin baş harfine göre sıralıyoruz
void siralayarakyazdir() {
    for (int i=0;i<12;i++) {
        for (int j=0;j<11;j++) {
            int k = j+1;
            if (strcmp(person[j].ad,person[k].ad)>0) {
                struct Personel temp=person[j];
                person[j] = person[k];
                person[k] = temp;
            }
        }
        FILE *fptr;
        //Prfrmns dosyasını yazma modunda açıyoruz
        fptr=fopen("C:\\Users\\Can\\Desktop\\prfrmns.txt","w");
        //Personel verilerini bu dosyaya yazıyoruz
        for (int i=0;i<12;i++) {
            fprintf(fptr,"%s %s %.2f\n",person[i].ad,person[i].soyad,person[i].aylik);
        }
        fclose(fptr);
    }
}
    int main() {
        ekledegistir();
        siralayarakyazdir();
    }
