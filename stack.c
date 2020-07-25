#include<stdio.h>
#include<stdlib.h>

void push( int*, int*,int);
void pop(int*, int*);
void display(int* ,int*);
int main()
{
    int size=5; 
    int s[size];
    int top=-1;

    //int element;
     
    int choice;
    while(1)
    {
        printf("\n.......................");
        printf("\n1.Insert new element");
        printf("\n2.Delete element");
        printf("\n3.Display all Elements");
        printf("\n4.exit");
        printf("\n..........................");
           
        printf("\nENTER CHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push(s,&top,size);
            break;
        case 2:
            pop(s,&top);
            break;
        case 3:
            display(s,&top);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEntered invalid choice!");
        }
    }
}
void push( int *s,  int *top, int size)
{
    int element;
    if(*top==size)
    {
        printf("\noverflow");
        printf("\nDo you want to increase the size of array? (Y/N)");
    }
    else
    {
        printf("\nEnter element : ");
        scanf("%d",&element);
        s[++(*top)]=element;
    }
}
void pop(int *s, int *top)
{
    if(*top==-1)
    {
        printf("\nunderflow");
    }
    else
    {
        printf("\npoped element = %d",(s[*top]));
        (*top)--;

    }
}
void display(int *s, int *top)
{
    int temp=*top;

    for(;temp>=0;temp--)
    {
        printf("%d",(s[temp]));
    }
}
