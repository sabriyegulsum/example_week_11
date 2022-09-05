#include<stdio.h>
struct student{
    char name[20];
    int grade;
};
int main()
{
    struct student std;
    FILE *p;
    if((p=fopen("not list","w"))==NULL)
        printf("dosya açılmadı");
    else
    {
        printf("öğrencilerin isim ve notlarını giriniz(bitirmek için '-1')");
        scanf("%s%d",std.name,&std.grade);
        while(std.grade!=-1)
        {
            fwrite(&std,sizeof(struct student),1,p);
            printf("isim no");
            scanf("%s%d",std.name,&std.grade);
        }
        fclose(p);
    }
    return 0;
}