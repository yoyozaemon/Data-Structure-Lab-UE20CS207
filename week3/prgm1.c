#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
char name[20];
int phone_number;
char address[150];
char area[100];
struct Node *next, *prev;
} Node;
typedef struct CustomerDetails
{
Node *head;
} CustomerDetails;
void init(CustomerDetails* pdl)
{
pdl->head=NULL;
}
void insert(CustomerDetails* pdl, char* n,int* ph,char* ad, char*ar)
{
Node* temp=(Node*)malloc(sizeof(Node));
strcpy(temp->name,n);
temp->phone_number=*ph;
strcpy(temp->address,ad);
strcpy(temp->area,ar);
temp->next=NULL;
temp->prev=NULL;
if(pdl->head==NULL)
{
pdl->head=temp;
return;
}
Node* present=pdl->head,* previous=NULL;
while(present!=NULL && strcmp(present->name,n)<0)
{
previous=present;
present=present->next;
  }
if(present==NULL)
{
previous->next=temp;
temp->prev=previous;
}
else if(previous==NULL)
{
temp->next=pdl->head;
pdl->head->prev=temp;
pdl->head=temp;
}
else
{
previous->next=temp;
temp->prev=previous;
temp->next=present;
present->prev=temp;
}
}
void display(CustomerDetails* pdl)
{
Node* p=pdl->head;
if(p==NULL)
printf("Empty List");
else
{
while(p!=NULL)
{
printf("Name: %s Phone:%d Address:%s Area:%s\n",p->name,p->phone_number,p->address,p->area);
p=p->next;
}
}
}
void main()
{
CustomerDetails dol;
init(&dol);
int choice;
char n[20], ad[150], ar[100];
int ph;
do
{
fflush(stdin);
printf("Enter Name: ");
scanf("%s",n);
printf("Enter Phone Number: ");scanf("%d",&ph);
fflush(stdin);
printf("Enter Address: ");
scanf("%s",ad);
fflush(stdin);
printf("Enter Area: ");
scanf("%s",ar);
fflush(stdin);
insert(&dol,n,&ph,ad,ar);
printf("Do you want to insert another entry?\n1.Yes\t0.No\nEnter your choice :");
scanf("%d",&choice);
printf("\n");
}while(choice);
printf("\n");
printf("Ordered list :\n");
display(&dol);
}
