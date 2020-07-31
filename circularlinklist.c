#include<stdio.h>
#include<stdlib.h>
struct cll
{
    int id;
    struct cll *link;
};
void InsertBegin(struct cll **);
void InsertLast(struct cll **);
void InsertMiddle(struct cll **,int);
void InsertPosition(struct cll **);
int countNode(struct cll **);
void display(struct cll **);
void deleteFirst(struct cll **);
void deleteLast(struct cll **);
void deletePosition(struct cll **);
void deleteMiddle(struct cll **,int);
void reverse(struct cll **);
int main()
{
    struct cll *head= NULL;
    int choice;
    int countresult;
    while(1)
    {
        printf("\n...............................");
        printf("\n1.Insert node at begin");
        printf("\n2.Insert node at last");
        printf("\n3.Insert node at middle");
        printf("\n4.Insert node at any position");
        printf("\n5.count the nodes in list");
        printf("\n6.Display all nodes");
        printf("\n7.Delete first node");
        printf("\n8.Delete last node");
        printf("\n9.Delete node which you want to delete");
        printf("\n10.Delete middle node");
        printf("\n11.Reverse the List");
        printf("\n12.Exit from the list");
        printf("\n................................");

        printf("\nENTER CHOICE : ");
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
                countresult=countNode(&head);
                InsertMiddle(&head,countresult);
                break;
            case 4:
                InsertPosition(&head);
                break;
            case 5:
                countresult=countNode(&head);
                printf("count = %d",countresult);
                break;
            case 6:
                display(&head);
                break;
            case 7:
                deleteFirst(&head);
                break;
            case 8:
                deleteLast(&head);
                break;
            case 9:
                deletePosition(&head);
                break;
            case 10:
                countresult=countNode(&head);
                deleteMiddle(&head,countresult);
                break;
            case 11:
                reverse(&head);
                break;
            case 12:
                exit(0);
            default:
                printf("\nEntered invalid choice");

        }

    }
}
void InsertBegin(struct cll **head)
{
    struct cll *newNode = (struct cll *)malloc(sizeof(struct cll));
    printf("\nEnter ID : ");
    scanf("%d",&newNode->id);
    newNode->link=NULL;
    struct cll *t=*head;
    if(*head==NULL)
    {
        newNode->link=newNode;
        *head=newNode;
    }
    else{
        while(t->link!=*head)
        {
            t=t->link;
        }
            newNode->link=*head;
            t->link=newNode;
            *head=newNode;
    }
}
void InsertLast(struct cll **head)
{
    struct cll *newNode = (struct cll *)malloc(sizeof(struct cll));
    printf("\nEnter ID : ");
    scanf("%d",&newNode->id);
    newNode->link=NULL;

    struct cll *t=*head;

    if(*head==NULL)
    {
        newNode->link=*head;
        *head=newNode;
    }
    else{
        while(t->link!=*head)
        {
            t=t->link;
        }
        t->link=newNode;
        newNode->link=*head;
    }
}
//------------------------------------------------------------------
int countNode(struct cll **head)
{
    int cnt=0;
    struct cll *t=*head;
    if(*head == NULL) {
        return cnt;
    }else {
        cnt = cnt+1;
        while(t->link != *head) {
            cnt = cnt+1;
            t=t->link;
        }
        return cnt;
    }

}
//---------------------------------------------------------------------
void display(struct cll **head)
{
    struct cll *t = *head;
    if(*head==NULL)
    {
        printf("\nList is Empty!!");
    }
    else{
           do{
               printf("\n ID = %d",t->id);
               t=t->link;
           }while(t!=*head);
        }    
}
//----------------------------------------------------------------------
void InsertMiddle(struct cll **head,int n)
{
    struct cll *newNode = (struct cll *)malloc(sizeof(struct cll));
    printf("\nEnter ID : ");
    scanf("%d",&newNode->id);
    newNode->link=NULL;
    struct cll *t=*head;

    int mid=n/2;
    mid=mid-1;

    while(mid!=0)
    {
        t=t->link;
        mid--;
    }
        newNode->link=t->link;
        t->link=newNode;
}
//----------------------------------------------------------------------
void InsertPosition(struct cll **head)
{
    struct cll *newNode=(struct cll *)malloc(sizeof(struct cll));
    int n;
    printf("\nEnter position number: ");
    scanf("%d",&n);
    printf("\nEnter ID : ");
    scanf("%d",&newNode->id);
    newNode->link=NULL;
  
    int count = countNode(head);

    if(n < 1 || n > (count+1) ) {
        printf("\ninvalid node position");
    }
    

    if(*head == NULL) {
        printf("\nNo node in the list");
        (*head) = newNode;
        (*head)->link = *head;
    }
    else if(count == 1) {
        printf("\nOnly one node present in the list");
        (*head)->link = newNode;
        newNode->link = *head;
    }else if(n==1) {
        printf("\n we are inserting new node to first positon");
        newNode->link = *head;
        struct cll *t=*head; 
        while(t->link != *head) {
            t=t->link;
        }
        t->link=newNode;
        (*head) = newNode;
    }else {
        struct cll *t=*head;
        n = n-1;
        for(int i=1; i<n; i++) {
            t=t->link;
        } 
        newNode->link = t->link;
        t->link = newNode;
    }
}
//---------------------------------------------------------------------------
void deleteFirst(struct cll **head)
{
    struct cll *t=*head;
    struct cll *r=*head;
    if(*head==NULL)
    {
        printf("\nList is empty");
    }
    else{
    while(t->link!=*head)
    {
        t=t->link;
    }
    *head=(*head)->link;
    t->link=*head;
    r->link=NULL;
    printf("ID = %d",r->id);
    free(r);
    }
}
//--------------------------------------------------------------------------
void deleteLast(struct cll ** head)
{
    struct cll *t=*head;
    struct cll *p=NULL;
    if(*head==NULL)
    {
        printf("\nList is empty");
    }
    else{
    while(t->link!=*head)
    {
        p=t;
        t=t->link;
    }
    p->link=*head;
    t->link=NULL;
    printf("\nID = %d",t->id);
    free(t);
    }
}

//----------------------------------------------------------------------------
void deletePosition(struct cll **head)
{
    struct cll *t=*head;
    struct cll *p=NULL;
    int n;
    printf("\nEnter node position to delete : ");
    scanf("%d",&n);
    n=n-1;
    int count = countNode(head);
     if(count == 1){
        printf("..........");
        (*head)->link=NULL;
        printf("\nID = %d",t->id);
        free(t);
        *head=NULL;
    }
 
    else if(n == 0){
        while(t->link!=*head)
        {
            t=t->link;
        }

        p=*head;
        t->link=(*head)->link;
        *head=(*head)->link;
            
        p->link=NULL;
        printf("\nID = %d",p->id);
        free(p);
    }
       else{
    while(n!=0)
    {
        p=t;
        t=t->link;
        n--;
    }
    p->link=t->link;
    t->link=NULL;
    printf("\nID = %d",t->id);
    free(t);
    }
}
//---------------------------------------------------------------
void deleteMiddle(struct cll **head,int k)
{
    struct cll *t=*head;
    struct cll *p=NULL;
    int mid=k/2;
    mid=mid-1;
    if(*head==NULL)
    {
        printf("\nList is empty");
    }

    if(k==2)
    {
        while(t->link!=*head)
        {
            t=t->link;
        }
        p=*head;
        *head=(*head)->link;
        t->link=t;
        p->link=NULL;
        printf("\nID = %d",p->id);
        free(p);
    }
    else if(mid==0){
        while(t->link!=*head){
            
            p=t;
            t=t->link;
        }
               
            p->link=NULL;
            (*head)->link=t;
            printf("\nID = %d",p->id);
            free(p);

    }
    else{
    while(mid!=0)
    {
        p=t;
        t=t->link;
        mid--;
    }
    p->link=t->link;
    t->link=NULL;
    printf("\nID = %d",t->id);
    free(t);
    }
}
//--------------------REVERSE THE LIST---------------------------
void reverse(struct cll **head)
{
    struct cll *t1=NULL;
    struct cll *t2=*head;
    struct cll *p=*head;
    while(t2->link!=*head)
    {
        t2=t2->link;
        p->link=t1;
        t1=p;
        p=t2;
    }
    t2->link=t1;
    (*head)->link=t2;
    *head=t2;
}
