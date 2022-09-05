#include<stdio.h>
struct student{
    int number;
    float mitderm;
    char name[40];
};
int main()
{
    struct student std1,std2;
    FILE *p;
    p=fopen("ogrenci.kayit","r+");
    int i[10]={2,0,1,0,2,1,3,0,5,1};
    int j=0,k=0;
    for(int a=0;a<5;a++)
        j+=i[a];
    for(int a=5;a<10;a++)
        k+=i[a];
    fseek(p,(j-1)*sizeof(struct student),SEEK_SET);
    fread(&std1,sizeof(struct student),1,p);
    rewind(p);
    fseek(p,(k-1)*sizeof(struct student),SEEK_SET);
    fread(&std2,sizeof(struct student),1,p);
    rewind(p);
    fseek(p,(j-1)*sizeof(struct student),SEEK_SET);
    fwrite(&std2,sizeof(struct student),1,p);
    rewind(p);
    fseek(p,(k-1)*sizeof(struct student),SEEK_SET);
    fwrite(&std1,sizeof(struct student),1,p);
    fclose(p);
    return 0;
    //eğer ilk baştan istediğin adıma gitmek istiyorsan onun bir eksiği
    //ile sizof u çarparız
}