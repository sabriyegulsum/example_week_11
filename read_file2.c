#include<stdio.h>
struct student{
    char name[20];
    int grade;
};
int main()
{
    struct student std;
    FILE *p;
    p=fopen("not list","r");
    fread(&std,sizeof(struct student),1,p);
    while(!feof(p))
    {
        printf("\nisim: %s\tnot:%d",std.name,std.grade);
        fread(&std,sizeof(struct student),1,p);
    }
    fclose(p);
    return 0;
}