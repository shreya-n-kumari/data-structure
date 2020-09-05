#include<stdio.h>
#include<stdlib.h>
void Enqueue(struct details **front, struct details **rear);
void dequeue(struct details **front);
void display(struct details **front);

struct details
{
    int id;
    char name[10];
    struct details *link;
};

int main()
{
    struct details *front = NULL;
    struct details *rear = NULL;
    int choice;
    while(1)
    {
        printf("\n1.Enter details in queue.");
        printf("\n2.Delete details.");
        printf("\n3.Display details.");
        printf("\n4.....EXIT FROM QUEUE....");

        printf("\nEnter choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            Enqueue(&front, &rear);   
            break;
        case 2:
            dequeue(&front);
            break;
        case 3:
            display(&front);
            break;
        case 4:
            exit(0);
            break;
        
        default:
            break;
        }
    }
    

}
void Enqueue(struct details **front, struct details **rear)
{
    struct details *newNode = (struct details *)malloc(sizeof(struct details));

    printf("\nEnter ID : ");
    scanf("%d", &newNode->id);
    printf("\nEnter Name : ");
    scanf("%s", newNode->name);
    newNode->link = NULL;
   
    if(*front == NULL && *rear == NULL)
    {
         (*front) = newNode;
         (*rear) = newNode;
    }
    else
    {
        (*rear)->link = newNode;
        *rear = newNode;
    }    
}

void dequeue(struct details **front )
{
    struct details *r = *front;
    if(*front == NULL)
    {
        printf("\nLis is Empty!");
    }
    else
    {
            printf("\nDeleted ID = %d and Deleted Name = %s\n", (*front)->id, (*front)->name);
            *front = (*front)->link;
            r->link = NULL;
            r = NULL;
            free(r);
        
    }    
}

void display(struct details **front)
{
    struct details *temp = *front;
    if(*front == NULL)
    {
        printf("\nLis is Empty!");
    }   
    else
    {
        while(temp != NULL)
        {
            printf("\nID = %d",temp->id);
            printf("\nNAME = %s\n",temp->name);
            temp = temp->link;
              
        } 
    }
}
