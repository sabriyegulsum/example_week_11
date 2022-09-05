#include<stdio.h>
struct student{
    char name[20];
    int grade;
};
int main()
{
    struct student std;
    float sum,ort;
    int counter=0;
    FILE *p;
    p=fopen("not list","r");
    fread(&std,sizeof(struct student),1,p);
    while(!feof(p))
    {
        sum+=std.grade;
        counter++;
        fread(&std,sizeof(struct student),1,p);
    }
    fclose(p);
    ort=sum/(float)counter;
    printf("ort= %f",ort);
    return 0;
}