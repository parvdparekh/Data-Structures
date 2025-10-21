#include <stdio.h>
#define SIZE 5
int q[SIZE];
int front=-1,rear=-1;
void enqueue(int e)
{
    if(front==0&&rear==SIZE-1||(rear+1)%SIZE==front)
    {
        printf("Queue is full\n");
        return;
    }
    if(front==-1)
        front=rear=0;
    else
        rear=(rear+1)%SIZE;
    q[rear]=e;
}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%SIZE;
}
void display()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    int i=0;
    for(i=front;i!=rear;i=(i+1)%SIZE)
        printf("%d\t",q[i]);
    printf("%d",q[i]);
    printf("\n");
}
void main()
{
    char c;
    int e;
    while(1)
    {
        printf("1)Enqueue\n2)Dequeue\n3)Display\n4)Quit\n");
        scanf("%d",&c);
        if(c==4)
            break;
        switch(c)
        {
            case 1:printf("Enter element to insert ");
            scanf("%d",&e);
            enqueue(e);
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            default:printf("Invalid input");
        }
    }
}
