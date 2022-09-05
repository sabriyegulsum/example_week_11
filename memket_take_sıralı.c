#include<stdio.h>
struct memleket{
    char city[20];
    char name[20];
};
int main()
{
    struct memleket sehir;
    FILE *p,*q;
    p=fopen("memleket","r");
    q=fopen("memleket_","w+");
    while(!feof(p))
    {
        fread(&sehir,sizeof(struct memleket),1,p);
        fprintf(q,"\n%s\t%s",sehir.city,sehir.name);
    }
    fclose(p);
    rewind(q);
    fscanf(q,"%s%s",sehir.city,sehir.name);
    while(!feof(q))
    {
        printf("\nşehir: %s   isim: %s",sehir.city,sehir.name);
        fscanf(q,"%s%s",sehir.city,sehir.name);
    }
    fclose(q);
    return 0;
}