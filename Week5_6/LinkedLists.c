#include <stdio.h>
struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;
void create(int x)
{
    struct node *newnode,*temp;
    int i,val;
    for(int i=0;i<x;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&val);
        newnode->data=val;
        newnode->next=NULL;
        if(start==NULL)
            start=newnode;
        else{
            temp=start;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }
}

void insert_begin(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=start;
    start=newnode;
}

void insert_end(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else
    {
        struct node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}

void insert_pos(int val, int pos)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(pos==1)
    {
        newnode->next=start;
        start=newnode;
        return;
    }
    struct node *temp=start;
    for(int i=1;i<pos-1&&temp!=NULL;i++)
        temp=temp->next;
    if(temp==NULL)
        return;
    newnode->next=temp->next;
    temp->next=newnode;
}

void display()
{
    struct node *temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void delete_end()
{

    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->

    next=NULL;
    free(ptr);
}

void delete_beg()
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
}

void delete_node()
{

    struct node *ptr,*preptr;
    int val;
    printf("Enter value ");
    scanf("%d",&val);
    ptr=start;
    if(ptr->data==val)
    {
        delete_beg;
        return;
    }
    else
    {
        while(ptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
}

void main()
{
    int n;
    printf("Enter initial no of nodes ");
    scanf("%d",&n);
    create(n);
    int c, val,pos;
    while(1)
    {
        printf("1)Insert_begin\n2)Insert_end\n3)Insert_pos\n4)Display\n5)Delete_beg\n6)Delete_end\n7)Delete_node\n10)Quit\n");
        scanf("%d",&c);
        if(c==10)
            break;
        switch(c)
        {
            case 1:scanf("%d",&val);
            insert_begin(val);
            break;

            case 2:scanf("%d",&val);
            insert_end(val);
            break;

            case 3:scanf("%d%d",&val,&pos);
            insert_pos(val,pos);
            break;

            case 4:display();
            break;

            case 5:delete_beg();
            break;

            case 6:delete_end();
            break;

            case 7:delete_node();
            break;

            default:printf("Invalid");
        }
    }
}
