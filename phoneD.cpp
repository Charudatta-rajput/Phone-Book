#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct node{
    long long int info;
    char name[30];
    struct node *next;
};

struct node *start=NULL;

void Display();
int Length();
void Insert();
void Delete();
void Search();

int main()
{
    int ch;
    do{
        system("cls");
        Display();
        printf("\n------------------------------------------");
        printf("\n\tMENU");
        printf("\n1 Insert the phone No:-\n2 Delete the Phone No:-\n3 Search the Phone No:-\n4 Display the Phone No:-\n5 Exit:-");
        printf("\nChoice ? ");
        scanf("%d",&ch);
        switch(ch){
            case 1: Insert(); break;
            case 2: Delete(); break;
            case 3: Search(); break;
            case 4: Display(); break;
            case 5: printf("\nGood Bye..!!\nPlease Press Enter Key"); break;
            default: printf("\noh oh Wrong Choice..!! ");
        }
      getch();
    }while(ch!=5);
     
}

void Display(){
    struct node *p;
    int i=1;
    if(start==NULL)
        printf("\n Phone Diary is empty");
    else{
        printf("\nPhone Diary is ....\n\n");
        p=start;
        while(p!=NULL){
            printf("%d. Phone No: %lld\n",i++,p->info);
            printf("   Name: %s\n\n",p->name);
            p=p->next;
        }
    }
}

int Length(){
    int c=0;
    struct node *p;
    p=start;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void Search(){
    long long int item;
    struct node *p;
    if(start==NULL)
        printf("\nPhone Diary is empty ");
    else{
        printf("\nEnter the Phone No :");
        scanf("%lld",&item);
        p=start;
        while(p!=NULL && p->info != item)
            p=p->next;

        if(p==NULL)
            printf("\n%lld is not found in the Phone Diary ",item);
        else
            printf("\n%lld is found in the list ",item);
    }
}

void Insert()
{
    struct node *n,*p;
    int i,pos;
    printf("\nEnter the position to Insert the Info:- ");
    scanf("%d",&pos);
    
    if(pos>=1 && pos<=Length()+1){
        n=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the Phone number: ");
        scanf("%lld",&n->info);
        printf("\nEnter the Name: ");
        scanf("%s",&n->name);
        if(pos==1){                     
            n->next=start;
            start=n;
        }
        else{                       
            p=start;
            for(i=1;i<pos-1;i++)
                p=p->next;

            n->next=p->next;
            p->next=n;
        }
        printf("\n%lld is inserted in Phone Diary at %d position ",n->info,pos);
    }
    else
        printf("\nInvalid Position ");
}

void Delete()
{
    struct node *p,*t;
    int pos,i;
    if(start==NULL)
        printf("\nThe Phone Diary Is Empty");
    else{
        printf("\nEnter the position ");
        scanf("%d",&pos);
        if(pos>=1&& pos<=Length()){
            if(pos==1){                          
                t=start;
                start=start->next;
            }
            else{
                p=start;
                for(i=1;i<pos-1;i++)
                    p=p->next;

                t=p->next;
                p->next=t->next;
            }
            printf("\n%lld is deleted from %d position",t->info,pos);
            free(t);
        }
        else
            printf("\nInvalid Position");
    }
}
