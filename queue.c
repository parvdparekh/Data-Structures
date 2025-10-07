#include <stdio.h>
#define SIZE 5
int q[SIZE];
int front=-1,rear=-1;
void enqueue(int e)
{
    if(rear==SIZE-1)
    {
        printf("Queue is full\n");
        return;
    }
    if(rear==-1)
        front=0;
    rear++;
    q[rear]=e;
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty\n");
        return;
    }
    front++;
}
void display()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty\n");
        return;
    }
    for(int i=front;i<rear+1;i++)
        printf("%d\t",q[i]);
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
