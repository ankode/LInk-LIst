#include<stdio.h>
#include<stdlib.h>

typedef struct node {
int data;
struct node * next;
}*NODE;

NODE Insert(NODE Head,int data)
{
    (Head->data)++;
    NODE temp= (struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=data;

    if(!Head->next)
    {
        Head->next=temp;
        return Head;
    }

    NODE cur=Head;
    while(cur->next)
        cur=cur->next;
    cur->next=temp;
    return Head;
}

display(NODE Head)
{
    NODE cur=Head->next;
    while(cur)
    {
        printf("%d --> ",cur->data);
        cur=cur->next;
    }
}

delete(NODE Head)
{
    if(!Head->next)
    {
        printf("Queue empty\n");
        return;
    }
    NODE cur = Head->next;
    printf("Element deleted is %d",cur->data);

    Head->next=cur->next;
}

void main()
{
    NODE Head=(struct node*)malloc(sizeof(struct node));
    Head->data=0;
    Head->next=NULL;
    int i=0,d;
    while(i!=4)
    {
        printf("Enter choice\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        scanf("%d",&i);
        switch(i)
        {
            case 1: printf("Enter data");
                    scanf("%d",&d);
                    Head=Insert(Head,d);
                    break;
            case 2: delete(Head);
                    break;
            case 3: display(Head);
            default:;

        }
    }

}
