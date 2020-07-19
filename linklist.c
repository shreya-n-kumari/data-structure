#include<stdio.h>
#include<stdlib.h>
struct linklist
{
   int id;
   char name[10];
   struct linklist *link;
};

void InsertBegin(struct linklist **);
void InsertLast(struct linklist **);
int countnode(struct linklist **);
void InsertMiddle(struct linklist **,int);
void InsertAtPosition(struct linklist **);
void display(struct linklist **);
void deleteFirst(struct linklist **);
void deleteLast(struct linklist **);
void deletePosition(struct linklist **);
int main()
{
    struct linklist *head=NULL;
    int countresult;
    int choice;
    //int count;
    while(1)
    {
    printf("\n.............*****................");
    printf("\n1.Insert node at begin");
    printf("\n2.Insert node at last");
    printf("\n3.count total node in list");
    printf("\n4.Insert node in the middle");
    printf("\n5.Insert node at the desired location");
    printf("\n6.Display all inserted node");
    printf("\n7.exit from the programe");
    printf("\n8.Delete the first node of list.");
    printf("\n9.Delete the last node");
    printf("\n10.Delete node at gieven postion");
    printf("\n...............*****................");
    
    printf("\nENTER CHOICE:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            InsertBegin(&head);
            break;
        case 2:
            InsertLast(&head);
            break;
        case 3:
            countresult=countnode(&head);
            printf("count = %d", countresult);
            break;
        case 4:
            countresult= countnode(&head);
            InsertMiddle(&head,countresult);
            break;
        case 5:
            InsertAtPosition(&head);
            break;
        case 6:
            display(&head);
            break;
        case 7:
            exit(0);
            break;
        case 8:
            deleteFirst(&head);
            break;
        case 9:
            deleteLast(&head);
            break;
        case 10:
            deletePosition(&head);
            break;
        default:
        printf("entered invalid choice");
    }
 }
}
//.................INSERT NODE AT BEGIN...................
void InsertBegin(struct linklist **head)
{
    struct linklist *newNode=(struct linklist *)malloc(sizeof(struct linklist));
    printf("Enter ID:");
    scanf("%d",&newNode->id);
    printf("Enter name:");
    scanf("%s",newNode->name);
    newNode->link = NULL;
    if(*head==NULL) {
        *head=newNode;
    }
    else{
            newNode->link=*head;
            *head=newNode;
        }
}
//....................INSERT NODE AT LAST.....................
void InsertLast(struct linklist **head)
{
    struct linklist *newNode=(struct linklist *)malloc(sizeof(struct linklist));
    printf("\nEnter ID: ");
    scanf("%d",&newNode->id);
    printf("Enter name: ");
    scanf("%s",newNode->name);
    newNode->link = NULL;
    struct linklist *t=*head;

    if(*head==NULL)
    {
        *head=newNode;
    }
    else{
        //printf("----- before while---");
      while(t->link!=NULL)
      {
          //printf("----- inside while---");
          t=t->link;
      }
      //printf("----- after while---");
        t->link=newNode;
    }
}
//....................COUNT TOTAL NODES IN LIST.................
int countnode(struct linklist **head)
{
    struct linklist *t=*head;
    int cnt=0;
    while(t!=NULL)
    {
        cnt=cnt+1;
        t=t->link;
    }
    return cnt;
}
//....................INSERT NODE AT MIDDLE......................
void InsertMiddle(struct linklist **head,int count)
{
    struct linklist *newNode=(struct linklist *)malloc(sizeof(struct linklist));
    printf("Enter ID:");
    scanf("%d",&newNode->id);
    printf("Enter name:");
    scanf("%s",newNode->name);
    newNode->link=NULL;    

    struct linklist *t=*head;
    int mid=count/2;
    mid=mid-1;

    if (*head==NULL)
    {
        *head=newNode;
    }
    else{
        while(mid!=0)
        {
            t=t->link;
            mid--;
        }
        newNode->link=t->link;
        t->link=newNode;
    }
    
}
//................INSERT NODE AT GIVEN POSTION..............
void InsertAtPosition(struct linklist **head)
{
       int n;
    printf("enter position number: ");
    scanf("%d",&n);
    n=n-1;
    struct linklist *newNode=(struct linklist *)malloc(sizeof(struct linklist));
    printf("\nEnter ID:");
    scanf("%d",&newNode->id);
    printf("\nEnter name:");
    scanf("%s",newNode->name);
    newNode->link=NULL;
    struct linklist *t=*head;
    
    while(n!=0)
    {
        t=t->link;
        n--;
    }
    newNode->link=t->link;
    t->link=newNode;
}
//...................DISPLAY ALL NODES OF LIST.............
void display(struct linklist **head) {

    struct linklist * temp = *head;
    if(*head==NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
    while(temp!=NULL)
    {
        printf("\n%d",temp->id);
        printf("\n%s",temp->name);
        printf("\n--------------------------------");
        temp=temp->link;
    }
  }
}
//......................DELETE FIRST NODE.................
void deleteFirst(struct linklist **head)
{
    struct linklist *r= *head;
    if(*head==NULL)
    {
        printf("\nlist is empty");
    }
    else{
        *head=(*head)->link;
        r->link=NULL;
        printf("\nID = %d",r->id);
        printf("\nname = %s",r->name);
        free(r);
    }
}
//..................DELETE LAST NODE...................
void deleteLast(struct linklist **head)
{
    struct linklist *r=*head;
    struct linklist *p=NULL;
    if(*head==NULL)
    {
        printf("\nlist is empty");
    }
    else{
        while(r->link!=NULL)
        {
            p=r;
            r=r->link;
        }
            p->link=NULL;
            printf("\nID = %d",r->id);
            printf("\nname = %s",r->name);
            free(r);
    }
}
//..................DELETE NODE AT GIVEN POSITION..........
void deletePosition(struct linklist **head)
{
    struct linklist *r=*head;
    struct linklist *p=NULL;
    int n;
    printf("\nEnter node number to be delete : ");
    scanf("%d",&n);
    n=n-1;
    if(head==NULL)
    {
        printf("\nlist is empty ");
    }
    else{
        while(n!=0)
        {
            p=r;
            r=r->link;
            n--;
        }
        p->link=r->link;
        r->link=NULL;
        printf("\nID = %d",r->id);
        printf("\nname = %s",r->name);
        free(r);
    }
}
