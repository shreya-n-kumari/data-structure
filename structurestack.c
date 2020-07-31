#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct detail
{
    int id;
    char name[10];
};

void push(struct detail*, int*, int*);
void pop(struct detail*, int*);
void display(struct detail* ,int*);
void merge_array(struct detail*, struct detail*, int*);
int main()
{
    int size=2;
    struct detail s[size];
    int top=-1;
     
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
            push(s,&top,&size);
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
void push(struct detail *s,  int *top, int *size)
{
    //int element;
    if(*top==*size)
    {
        printf("\noverflow");
        printf("\nDo you want to increase the size of array? (Y/N) : ");
        char ans[1];
        scanf("%s",&ans);

        if(ans[0] == 'y' || ans[0] == 'Y'){
            int k=(*size)*2;
            *size = k;  
            printf("\nSize updated");                //update size..
            struct detail res[k];
            merge_array(s, res, top);
            s = res;
        }
        else {
            printf("\nstack is full, please pop or exit");
        }
    }
    else
    {
        *top = *top + 1;
        printf("\nEnter Details : ");
        printf("\nenter Id=");
        scanf("%d",&s[*top].id);
        printf("\nenter name= ");
        scanf("%s",&s[*top].name);
        
        
       // s[++(*top)]=element;
    }
}
void pop(struct detail *s, int *top)
{
    if(*top==-1)
    {
        printf("\nunderflow");
    }
    else
    {
        printf("\n----------- ** details ** ------------");
        printf("\nID = %d", s[*top].id);
        printf("\nName = %s", s[*top].name);
        (*top)--;

    }
}
void display(struct detail *s, int *top)
{
    int temp=*top;

    for(;temp>=0;temp--)
    {
        printf("\nID = %d", s[temp].id);
        printf("\nName = %s", s[temp].name);
        printf("\n");
    }
}

void merge_array(struct detail *s, struct detail *res, int *top)
{
    int i = 0;
    while(i == *top) {
         res[i].id = s[i].id;
         strcpy(res[i].name, s[i].name); 
         i++;  
    }
}
