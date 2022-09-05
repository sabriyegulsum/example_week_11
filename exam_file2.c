#include<stdio.h>
struct student{
    int number;
    float mitderm;
    char name[40];
};
int main()
{   struct student std;
int i,j;
    FILE *p;
    if((p=fopen("ogrenci.kayit","w"))==NULL)
        printf("dosya açılamadı");
    else
    {
        printf("kaç öğrenci var:");
        scanf("%d",&i);
        for(j=0;j<i;j++)
        {
            printf("\nname number mit");
            scanf("%s%d%f",std.name,&std.number,&std.mitderm);
            fwrite(&std,sizeof(struct student),1,p);
        }
        fclose(p);
    }
    return 0;
}