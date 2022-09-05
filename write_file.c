#include<stdio.h>
struct student{
    char name[10];
    char no[10];
};
int main()
{
    struct student std;
    FILE *p;
    p=fopen("student_list","r");
    fread(&std,sizeof(struct student),1,p);
    while(!feof(p))
    {
        printf("\nno:%s name:%s",std.no,std.name);
        fread(&std,sizeof(struct student),1,p);
    }
    fclose(p);
    return 0;
}