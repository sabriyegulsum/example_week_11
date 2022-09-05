#include<stdio.h>
#include<string.h>
struct student{
    char name[10];
    int no;
};
int main()
{
    struct student std,boshesap={"",0};
    char isim[10];
    FILE *p;
    p=fopen("student_list","r+");
    printf("silmek istediğiniz isimi giriniz");
    scanf("%s",isim);
    printf("ok");
    fread(&std,sizeof(struct student),1,p);
    while(!feof(p))
    {
        if(strcmp(isim,std.name)==0)
        {
            fseek(p,(-1)*sizeof(struct student),SEEK_CUR);
            fwrite(&boshesap,sizeof(struct student),1,p);
            break;
            //ilk başta break koymadığım için 
        }
        else
            fread(&std,sizeof(struct student),1,p);
    }
    rewind(p);
    fread(&std,sizeof(struct student),1,p);
    while(!feof(p))
    {
        printf("\nisim:%s  no:%d",std.name,std.no);
        fread(&std,sizeof(struct student),1,p);
    }
    fclose(p);
    return 0;
}