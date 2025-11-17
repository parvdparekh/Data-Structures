#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start, *newnode, *ptr;

void insert(int e)
{
    if(start==NULL)
    {
        start=(struct node*)malloc(sizeof(struct node));
        start->data=e;
        start->next=NULL;
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=e;
    newnode->next=start;
    start=newnode;
}

void display()
{
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void reverse()
{
    struct node *prev = NULL;
    struct node *current = start;
    struct node *next_node = NULL;
    while (current != NULL)
    {
        next_node = current->next; 

        current->next = prev;     

        prev = current;
        current = next_node;
    }
    start=prev;
    display();
}

int main()
{
    int c,e;
    while(1)
    {
        printf("1)Insert\n2)Display\n3)Quit\n");
        scanf("%d",&c);
        if(c==3)
            break;
        switch(c)
        {
            case 1:
                printf("Enter ");
                scanf("%d",&e);
                insert(e);
                break;
            case 2:
                display();
                break;
            default:
                printf("Invalid");
        }
    }
    reverse();
}