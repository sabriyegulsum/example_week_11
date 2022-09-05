#include<stdio.h>
struct student{
    int number;
    float mitderm;
    char name[40];
};
int main()
{
    struct student std;
    FILE *p;
    p=fopen("ogrenci.kayit","r");
    fread(&std,sizeof(struct student),1,p);
    while(!feof(p))
    {
        printf("\nnum:%d\tisim:%s\tnot:%f",std.number,std.name,std.mitderm);
        fread(&std,sizeof(struct student),1,p);
    }
    return 0;
}