#include<stdio.h>
#include<stdlib.h>
typedef struct node
{

    int data;
    struct node *next;
}*NODE;
NODE insert(NODE f,int d)
{

    NODE temp=(struct node*)malloc(sizeof(struct node));
    if(temp!=NULL)
    {

        temp->data=d;
        temp->next=temp;
    }
    if(f==NULL)
    {
        return temp;
    }
    NODE p=f->next;
    while(p->next!=f)
    {
        p=p->next;
    }
    p->next=temp;
    temp->next=f;
   30
}
NODE unio(NODE a,NODE b)
{


    int f=0;
    NODE u=NULL,b1,t1,t2;
    t2=a;
    do
    {
        u=insert(u,t2->data);
        t2=t2->next;
    }while(t2!=a);
    b1=b;
    do
    {
        t1=a;
        do
        {

            if(b1->data==t1->data)
                {
                    f=1;
                    break;
                }
            t1=t1->next;
        }while(t1!=a);
        if(f==0)
            u=insert(u,b1->data);
        b1=b1->next;
        f=0;
    }while(b1!=b);
    return u;
}
void print(NODE f)
{

    int i;
    NODE p=f->next;
    /*if(f==NULL)
        printf("\nEmpty");
    else
    {
     */printf("%d\n",f->data);
     while(p!=f)
        {
            printf("%d",p->data);
            p=p->next;
            printf("\n");
        }
    }

int main()
{
    int d,i,l1,l2;
    NODE a,b,c;
    a=b=NULL;
    printf("\nEnter size for first list");
    scanf("%d",&l1);
    printf("\nEnter elements for first list");
    for(i=0;i<l1;i++)
    {
        scanf("%d",&d);
        a=insert(a,d);
    }
    printf("\nEnter size for second list");
    //2
    printf("\nEnter elements for second list");
    for(i=0;i<l2;i++)
    {
        scanf("%d",&d);
        b=insert(b,d);
    }
    printf("The union of the lists is\n");
    if(l1<l2)
        c=unio(b,a);
    else
       c=unio(a,b);
    print(c);


}
//return f;
//2 //scanf("%d",&l2);