#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *ll;
    struct node *rl;
}*NODE;
NODE insert(NODE f,int d)
{
    NODE temp=(struct node*)malloc(sizeof(struct node));
    if(temp!=NULL)
    {
        temp->data=d;
        temp->ll=temp->rl=NULL;
    }
    if(f==NULL)
        return temp;
    NODE p=f;
    while(p->rl!=NULL)
        p=p->rl;
    p->rl=temp;
    temp->ll=p;
    return f;
}
NODE intersection(NODE a,NODE b)
{
    int f=0;
    NODE i=NULL,t1,b1;
    b1=b;
    while(b1!=NULL)
    {
        t1=a;
        while(t1!=NULL)
        {
            if(b1->data==t1->data)
        {
            f=1;
            break;
        }
        t1=t1->rl;
        }
        if(f==1)
            i=insert(i,b1->data);
        b1=b1->rl;
        f=0;
    }
        return i;
}
void print(NODE f)
{
    NODE p=f;
    if(f==NULL)
        printf("\nNo intersection");
    else
        while(p!=NULL)
        {
            printf("%d",p->data);
            printf("\n");
            p=p->rl;
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
    scanf("%d",&l2);
    printf("\nEnter elements for second list");
    for(i=0;i<l2;i++)
    {
        scanf("%d",&d);
        b=insert(b,d);
    }
    printf("The intersection of the lists is\n");
    if(l1<l2)
        c=intersection(b,a);
    else
       c=intersection(a,b);
    print(c);


}
