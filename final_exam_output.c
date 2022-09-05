#include<stdio.h>
#include<stdlib.h>
struct node{
    int no;
    struct node *next;
};
typedef struct node node;
node *head;
void changing_list(void);
void write_list(void);
void create_list(void)
{
    int num[10]={0,0,0,1,1,1,2,2,3,5};
    node *p;
    int i;
    p=(node *)malloc(sizeof(node));
    for(i=0;i<10;i++)
    {
        if(i==0)
        {
            head=(node *)malloc(sizeof(node));
            p=head;
            p->no=num[i];
        }
        else
        {
            p->next=(node *)malloc(sizeof(node));
            p=p->next;
            p->no=num[i];
        }
    }
    p->next=NULL;
}
void changing_list(void)
{
    node *p,*k,*z;
    k=head;
    p=head;
    while(p->next!=NULL)
    {
        k=p;
        z=p;
        while(z->no==z->next->no)
        {
            k=z->next;
            z->next=z->next->next;
            free(k);
        }
        p=p->next;
    }
}
void write_list(void)
{
    node*p;
    p=head;
    while(p!=NULL)
    {
        printf("\n%d",p->no);
        p=p->next;
    }

}
int main()
{
    create_list();
    changing_list();
    write_list();
    return 0;
}