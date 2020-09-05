#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10
void saveContact(struct phoneBook **);
void getContact(struct phoneBook **);
void deleteContact(struct phoneBook **);
struct phoneBook
{
    char name[100];
    int number;
    struct phoneBook *link;
};

int main()
{
    struct phoneBook* phone[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        phone[i] = NULL;
    }
    
    while(1)
    {
     printf("\n1.SaveContact");
     printf("\n2.GetContact");
     printf("\n3.Delete Contact");
     printf("\n4....EXIT.....");

     int choice;
     printf("\nEnter choice ");
     scanf("%d",&choice);
     switch (choice)
     {
        case 1:
            saveContact(phone);
            break;
        case 2:
            getContact(phone);
            break;
        case 3:
            deleteContact(phone);
            break;
        case 4:
            exit(0);
            break;  
        default:
            printf("\nEntered Invalid Choice :)");
            break;
     }
    }
}
int getkey(char* name)
{
    int length = strlen(name);
    int key = length % SIZE;
    return key;
}

/*int validateNumner(int number) {

    int isValid = 0;
    int count = 1;
    
    while ((number/10) !=0)
    {
        count = count +1;
        number = number%10;
    }
    printf("==== count %d=", count);
    if(count == 10)
    {
        isValid = 1;
    }
    
    return isValid;
}*/

void saveContact(struct phoneBook **s)
{
    struct phoneBook *newNode = (struct phoneBook *)malloc(sizeof(struct phoneBook));
    

    printf("\nEnter name => ");
    scanf("%s",newNode->name);

    printf("\nEnter number => ");
    scanf("%d", &(newNode->number));
    newNode->link=NULL;
    
    int index = getkey(newNode->name);
    s[index] = newNode;
    

}

void getContact(struct phoneBook **phone)
{
    char name[100];
    printf("\nEnter Name for search  ::");
    scanf("%s",name);
    int index = getkey(name);
   
    if(phone[index]->name==NULL)
    {
        printf("\nNO record found!");
    }else{

        if(strcmp((phone[index])->name, name))
        {
            printf("\nNO record found!");
        }
        else
        {
            struct phoneBook *temp= phone[index]; 
            printf("\nName is = %s",(phone[index])->name);
            printf("\nNumber is = %d", temp->number);

        }
    }
    
}
void deleteContact(struct phoneBook **phone)
{
    char name[15];
    printf("\nEnter name to delete::: ");
    scanf("%s",name);
    
    int index = getkey(name);

        struct phoneBook *temp= phone[index];
        printf("\nDeleted Details Are->->->->->");
        printf("\nName is = %s",(phone[index])->name);
        printf("\nNumber is = %d",(temp->number));

        phone[index] = NULL;
}

