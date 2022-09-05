#include<stdio.h>
struct memleket{
    char city[20];
    char name[20];
};
int main()
{
    int i=1;
    struct memleket sehir;
    FILE *p;
    if((p=fopen("memleket","w+"))==NULL)
        printf("dosya açılamadı");
    else
    {
        printf("şehir ve isim bilgilerini giriniz (bitirmek için 0 dvam için 1 e basınız");
        while(i!=0)
        {
            printf("isim city");
            scanf("%s%s",sehir.city,sehir.name);
            fwrite(&sehir,sizeof(struct memleket),1,p);
            printf("\n?"); scanf("%d",&i);
        }
        fclose(p);
    }
    return 0;
}