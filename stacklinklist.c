#include<stdio.h>
#include<stdlib.h>
struct node
{
    int id;
    struct node *link;
};
void push(struct node **, struct node **);
void pop(struct node **, struct node **);
void display(struct node **, struct node **);
int main()
{
    struct node *top = NULL;
    struct node *head = NULL;
    while(1)
    {
        printf("\n..............................");
        printf("\n1.Insert new data");
        printf("\n2.Delete node");
        printf("\n3.======>Display Stack.");
        printf("\n4.exit from the program");
        printf("\n..............................");

        int choice;
        printf("\nENTER CHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push(&head, &top);
                break;
            case 2:
                pop(&head,&top);
                break;
            case 3:
                display(&head,&top);
                break;
            case 4:
                exit(0);
                break;
        }
    }
}
void push(struct node **head, struct node **top)
{
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter ID : ");
    scanf("%d",&newNode->id);

    if(*head == NULL) 
    {
        (*head) = newNode;
    }
    else
    {
        (*top)->link=newNode;
        (*top)=newNode;
    }

    if(*top==NULL)
    {
        (*top)=newNode;
    }
    
}

void pop(struct node **head, struct node **top)
{
    struct node *temp=*head;
    if(*top==NULL)
    {
        printf("\nStack is empty");
    }
    else if(temp->link == NULL) {
        printf("\nID = %d",(*top)->id);
        *head = NULL;
        temp = NULL;
        *top = NULL;
    }
    else
    {
        while(temp->link!=*top)
        {
            temp=temp->link;
        }
        printf("\nID = %d",(*top)->id);
        temp->link = NULL;
        free(*top);
        *top=temp;
    }
}

void display(struct node **head,struct node **top)
{
    struct node *newHead = *head;
    struct node *next=*head;
    struct node *prev=NULL;

    while(next!=NULL)
    {
        next=next->link;
        newHead->link=prev;
        prev=newHead;
        newHead=next;
    }
    newHead=prev;
    printf("\nprev = %u ", prev);
    printf("\nnewHead = %u ", newHead);

    while(newHead != NULL) {
        printf("\n%d", newHead->id);
        newHead=newHead->link;
    }
    /*do{
        printf("newHead = %u ", newHead);
        printf("\n%d", newHead->id);
        newHead=newHead->link;
        
    }while(newHead!=NULL);*/
}
