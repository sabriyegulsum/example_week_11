#include<stdio.h>
#include<string.h>
struct student{
    char name[10];
    char no[10];
};
int main()
{
    struct student std;
    char email[30];
    FILE *p,*q;
    p=fopen("student_list","r");
    if((q=fopen("ogrenci mail","w"))==NULL)
        printf("e mail dosyası açılmadı");
    else
    {
        fread(&std,sizeof(struct student),1,p);
        while(!feof(p))
        {
            strcpy(email,std.no);
            strcat(email,"@ogrenci.karabuk.edu.tr");
            fwrite(email,(30)*sizeof(char),1,q);
            fread(&std,sizeof(struct student),1,p);
        }
        fclose(q);
        fclose(p);
    }
    return 0;
}