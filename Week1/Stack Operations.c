#include <stdio.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push()
{
    if(top==SIZE-1)
    {
        printf("Overflow\n");
        return;
    }
    int a;
    printf("Enter element to insert\n");
    scanf("%d",&a);
    top+=1;
    stack[top]=a;
    printf("Pushed\n");
    printf("\n");
}
void pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
        return;
    }
    top-=1;
    printf("Popped\n");
    printf("\n");
}
void display()
{
    if(top==-1)
    {
        printf("Underflow\n");
        return;
    }
    for(int i=top;i>=0;i--)
        printf("%d\n",stack[i]);
    printf("\n");
}
void main()
{
    int c;
    while(1)
    {
        printf("\n");
        printf("1)Push\n2)Pop\n3)Display\n4)Quit\n");
        scanf("%d",&c);
        printf("\n");
        if(c==4)
            break;
        switch(c)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid Input");
        }
    }
}
