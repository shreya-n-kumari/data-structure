#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push( int*, int*,int*);
void pop(int*, int*);
void display(int* ,int*);
void merge_array(int *, int *, int *);
int main()
{
    int size=5; 
    int s[size];
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
void push( int *s,  int *top, int* size)
{
    int element;
    if(*top==*size)
    {
        printf("\noverflow");
        printf("\nDo you want to increase the size of array? (Y/N) : ");
        char ans[1];
        scanf("%s",ans);

        if(ans[0]=='y'){
            int k=(*size)*2;
            *size = k;
            int res[k];
            merge_array(s, res, top);
            s = res;
        }
        else {
            printf("\nstack is full, please pop or exit");
        }
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
        printf("\t%d",(s[temp]));
        printf("\n");
    }
}

void merge_array(int *s, int *res, int *top)
{
    int i = 0;
    while(i == *top) {
         res[i] = s[i]; 
         i++;  
    }
}
