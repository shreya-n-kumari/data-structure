#include<stdio.h>
#include<stdlib.h>
struct dll
{
    int id;
    struct dll *rlink;
    struct dll *llink;
};
void InsertBegin(struct dll **);
void InsertEnd(struct dll **);
void display(struct dll **);
void InsertMiddle(struct dll **, int);
int countNode(struct dll **);
void InsertPosition(struct dll **);
void deleteFirst(struct dll **);
void deleteLast(struct dll **);
void deleteMiddle(struct dll **, int);
void deletePosition(struct dll **);
int main()
{
    struct dll *head=NULL;
    int choice;
    int count;
    int nodeCount;
    //int resultCount;

    while(1)
    {
        printf("\n..............................");
        printf("\n1.Enter  node at begin:");
        printf("\n2.Enter node at last:");
        printf("\n3.display all nodes");
        printf("\n4.Enter node at the middle of list:");
        printf("\n5.count the node:");
        printf("\n6.exit from the list");
        printf("\n7.Enter node at any position:");
        printf("\n8.Delete First Node of The List");
        printf("\n9.Delete last node");
        printf("\n10.Delete middle node");
        printf("\n11.Delete node at any position");
        printf("\n................................");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                InsertBegin(&head);
                break;
            case 2:
                InsertEnd(&head);
                break;
            case 3:
                display(&head);
                break;
            case 4:
                nodeCount = countNode(&head);
                InsertMiddle(&head, nodeCount);
                break;        
            case 5:
                count = countNode(&head);
                printf("Count = %d ", count);
                break;
            case 6:
                exit(0);
                break;
            case 7:
                InsertPosition(&head);
                break;
            case 8:
                deleteFirst(&head);
                break;
            case 9:
                deleteLast(&head);
                break;
            case 10:
                nodeCount = countNode(&head);
                deleteMiddle(&head, nodeCount);
                break;
            case 11:
                deletePosition(&head);
                break;  
            default:
            printf("\nyou have entered invalid choice");
    }
 }
}

//................INSERT NODE AT BEGIN OF THE LIST.................
void InsertBegin(struct dll **head)
{
    struct dll *newNode=(struct dll *)malloc(sizeof(struct dll));
    printf("enter ID:");
    scanf("%d",&newNode->id);
    newNode->rlink=NULL;
    newNode->llink=NULL;
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        newNode->rlink=*head;
        (*head)->llink = newNode;
        *head=newNode;
    }
}
//.....................INSERT NODE AT LAST...................
void InsertEnd(struct dll **head)
{
  struct dll *newNode=(struct dll *)malloc(sizeof(struct dll));
    printf("enter ID:");
    scanf("%d",&newNode->id);
    newNode->rlink=NULL;
    newNode->llink=NULL;

    struct dll *t=*head;
    
    if(*head==NULL)
    {
        *head=newNode;
    }
    else{

        while(t->rlink!=NULL)
        {
            t=t->rlink;
        }
        t->rlink=newNode;
        newNode->llink=t;
    }

}
//....................DISPLAY ALL NODES OF LIST.................
void display(struct dll **head)
{
    struct dll *temp=*head;
    if(*head==NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("\ninserted nodes are: ");
            printf("%d",temp->id);
            temp=temp->rlink;
        }
    }
}
//.......................COUNT THE LIST............................
int countNode(struct dll **head)
{
    struct dll *t=*head;
    int cnt=0;
    while(t!=NULL)
    {
        cnt=cnt+1;
        t=t->rlink;
    }
    return cnt;
}
//.......................INSERT NODE IN MIDDLE......................
void InsertMiddle(struct dll **head,int n)
{
    struct dll *newNode=(struct dll *)malloc(sizeof(struct dll));
    printf("enter ID:");
    scanf("%d",&newNode->id);
    newNode->rlink=NULL;
    newNode->llink=NULL; 
    struct dll *t=*head;
    int mid = n/2;

    mid=mid-1;
    while(mid!=0)
    {
       t=t->rlink;
       mid--;
    }
    newNode->rlink=t->rlink;
    t->rlink=newNode;
    newNode->llink=t;
    newNode->rlink->llink=newNode;
}
//............................INSERT NODE AT ANY POSITION..............
void InsertPosition(struct dll **head)
{
    struct dll *newNode=(struct dll *)malloc(sizeof(struct dll));
    int n;
    printf("\nenter number of position");
    scanf("%d",&n);
    n=n-1;
    printf("enter ID:");
    scanf("%d",&newNode->id);
    newNode->rlink=NULL;
    newNode->llink=NULL;
    struct dll *t=*head;
    while(n!=0)
    {
        t=t->rlink;
        n--;
    }
    newNode->llink=t;
    newNode->rlink=t->rlink;
    t->rlink=newNode;
    t->rlink->llink=newNode;
}   
//.......................DELETE FIRST NODE......................
void deleteFirst(struct dll **head)
{
    if(*head==NULL){
    printf("list is empty");
    }
    else{
        printf("%d",(*head)->id);
        *head=(*head)->rlink;
        (*head)->llink->rlink=NULL;
        (*head)->llink=NULL;
    }
}
//...................DELETE LAST NODE........................
void deleteLast(struct dll **head)
{
    struct dll *t=*head;
    if(*head==NULL)
    {
        printf("\nList is empty");
    }
    else{
         while(t->rlink!=NULL)
         {
             t=t->rlink;
         }
         t->llink->rlink=NULL;
         t->llink=NULL;
         printf("\nID = %d",t->id);
         free(t);
    }
}
//.........................DELETE MIDDLE NODE....................
void deleteMiddle(struct dll **head,int count)
{
    struct dll *t=*head;
    struct dll *p=NULL;
    int mid=count/2;
    mid=mid-1;
    if(*head==NULL)
    {
        printf("List is empty");
    }
    else{
       
        while(mid!=0)
        {
            p=t;
            t=t->rlink;
            mid--;
        }
        p->rlink=t->rlink;
        t->rlink->llink=p;
        t->rlink=NULL;
        t->llink=NULL;
        printf("\nID = %d",t->id);
        free(t);
    }
}
void deletePosition(struct dll ** head)
{
    struct dll *t=*head;
    struct dll *p=NULL;
    int n;
    printf("\nEnter node number to delete.");
    scanf("%d",&n);
    n=n-1;
    if(*head==NULL)
    {
        printf("List is empty");
    }
    
    else{
        while(n!=0)
        {
            p=t;
            t=t->rlink;
            n--;
        }
        p->rlink=t->rlink;
        t->rlink->llink=p;
        t->rlink=NULL;
        t->llink=NULL;
        printf("\nID = %d",t->id);
        free(t);
    }
}
