#include<stdio.h>
#include<stdlib.h>
void enQueue(int* , int* , int* , int*);
void deQueue(int* , int* , int* , int*);
void display(int* , int* , int* ,int* );
int main()
{
    int size = 5;
    int Queue[size];

    int front = -1;
    int rear = -1;

    int choice;

    while (1)
    {
        printf("\n1.Enter element ");
        printf("\n2.Delete element");
        printf("\n3.Display all elements");
        printf("\n4.......EXIT......");

        printf("\nEnter choice : ");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            enQueue(Queue , &front , &rear , &size);
            break;
        case 2:
            deQueue(Queue , &front , &rear , &size);
            break;
        case 3:
            display(Queue , &front , &rear , &size);
            break;
        case 4:
            exit(0);
            break;
        
        default:
            printf("\nEntered  invalid choice :)");
            break;
        }
    }
}

void enQueue(int *q , int *front , int *rear , int *size)
{
    int element;
    
    if((*rear+1)%(*size) == *front){
        printf("\nQueue is full\n");
    }
    else{
        printf("\nEnter element ");
        scanf("%d",&element);

        *rear = (*rear+1)%(*size);
        q[*rear] = element;

        if (*front == -1) {
            *front = *rear;
        }
    }
}

void deQueue(int *a , int *front , int *rear , int *size)
{
    if(*front == -1 && *rear == -1)
    {
        printf("\nQueue is Empty!\n");
    }
    else if(*front == *rear)
    {
        printf("\nDeleted element = %d\n",(a[*front]));
        *front = -1;
        *rear = -1;
    }
    else{
        printf("\nDeleted element = %d\n",(a[*front]));
        *front = (*front+1)%(*size);
    }
}

void display(int *a , int *front , int *rear ,int *size)
{
    //int temp = *front;
    if (*front == -1 && *rear == -1)
    {
        printf("\nQueue is Empty!\n");
    }else
    {
            /* if rear is behind front. (front> rear)*/
            for (int temp = *front; ; temp=(temp+1)%*size)
            {
                printf("%d\n",(a[temp]));
                if (temp == *rear)
                {
                    /* come out from loop, since all the elements are printed */
                    break;
                }
                
            }

    }    
   
}
