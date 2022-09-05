#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct memleket{
    char city[20];
    char name[20];
    struct memleket *next;
};
typedef struct memleket mem;
mem *head;
int main()
{
    mem sehir,*q;
    FILE *p;
    p=fopen("memleket_","r");
    head=(mem *)malloc(sizeof(mem));
    q=head;
    fscanf(p,"%s%s",sehir.city,sehir.name);
    while(!feof(p))
    {
        q->next=(mem *)malloc(sizeof(mem));
        q=q->next;
        strcpy(q->city,sehir.city);
        strcpy(q->name,sehir.name);
        fscanf(p,"%s%s",sehir.city,sehir.name);
    }
    fclose(p);
    q->next=NULL;
    q=head->next;
    while(q->next!=NULL)
    {
        printf("\nisim: %s\tcity: %s",q->name,q->city);
        q=q->next;
    }
    return 0;
}