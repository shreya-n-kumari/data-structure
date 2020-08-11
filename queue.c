#include<stdio.h>
#include<stdlib.h>
void addq(int* , int*, int* , int*);
void delq(int* ,int* ,int* , int *);
void display(int* , int* , int*);
int main()
{
    int size=4;
    int a[size];
    
    int front = -1;
    int rear = -1;
    while(1)
    {
        printf("\n1.Enter new element");
        printf("\n2.Delete Element");
        printf("\n3.Display all Elements");
        printf("\n4....EXIT.....\n");

        int choice;
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addq(a , &front , &rear ,&size);
                break;
            case 2:
                delq(&front, &rear, a, &size);
                break;
            case 3:
                display(&front , &rear ,a);
                break;
            case 4:
                exit(0);
                break;          
            default:
                printf("\nEntered invalid choice!");
        }
    }
}
void addq(int *a, int *front, int *rear , int *size)
{
    int id;
    *front = 0;
    if(*rear==*size)
    {
        printf("\nQueue is full");
    }
    else{
        (*rear)++;
        printf("\nEnter ID = ");
        scanf("%d",&id);
        a[(*rear)] = id;
    }
}
void delq(int *front, int *rear , int *a , int *size)
{
    if((*front == -1 && *rear == -1) || (*front == *size && *rear == *size))
    {
        printf("\nlist is empty\n");
    }
    else{
        printf("\npoped ID = %d\n",(a[*front]));
        
        (*front)++;
    }
}
void display(int *front, int *rear , int *a)
{
    int temp=*front;
    if(*front == -1)
    printf("\nList is Empty");
    else{
     while(temp!=*rear)
     {
         printf("%d\n",(a[temp]));
         temp++;
     }
 }
}
