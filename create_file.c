#include<stdio.h>
#include<string.h>
struct student{
    char name[10];
    char no[10];
};
int main()
{
    struct student std;
    FILE *p;
    if((p=fopen("student_list","w"))==NULL)
        printf("dosya açılamadı");
    else
    {
        printf("no ve isim giriniz(bitirmek için (bitir)");
        scanf("%s%s",std.no,std.name);
        while(strcmp(std.no,"bitir")!=0)
        {
            fwrite(&std,sizeof(struct student),1,p);
            printf("no isim?");
            scanf("%s%s",std.no,std.name);
        }
        fclose(p);
    }
    return 0;
}