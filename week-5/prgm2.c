#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
char name[50];
char date[20];
int n;//priority no
char time[20];
struct node* link;
}node;
typedef struct appoint_queue{
node* front;
node *rear;
int capacity;
int size;
}appq;
node* create_node()
{
node*new_node=malloc(sizeof(node));
printf("Enter the following details\n");
printf("Name:");scanf("%s",new_node->name);
printf("date:");scanf("%s",new_node->date);
printf("priority based on time and date:");scanf("%d",&new_node->n);
printf("time(24-hour):");scanf("%s",new_node->time);
return new_node;
}
void insert_q(appq* pq)
{
node* new_node=create_node();
if(pq->size==pq->capacity)
{
printf("no more entries\n\n");
return;
}
else if(pq->front==NULL)
{
pq->front=new_node;
pq->rear=new_node;}
else
{
node* temp;
temp=pq->front;
while(temp->link!=NULL)
{
temp=temp->link;
}
temp->link=new_node;
pq->rear=pq->rear->link;
}
}
void delete(appq *pq)
{
//deleting according to priority of appointment
if(pq->front==NULL)
printf("empty queue cannot be deleted\n");
else if(pq->front && pq->rear && pq->front==pq->rear)
{
free(pq->front);
pq->front=NULL;
pq->rear=NULL;
pq->size--;
}
else
{ node *temp=pq->front;
int i=temp->n;
node* pointer;//to hold the least priority node that is to be deleted
node* prev=NULL;
node* present=temp;
while(temp!=NULL)
{
if(i>temp->n)
{
i=temp->n;
pointer=temp;
}
temp=temp->link;
}
while(present!=pointer)
{ prev=present;
present=present->link;
}
if(present==pq->front)
{
pq->front=pq->front->link;free(present);
present=NULL;
}
else
{
prev=present->link;
free(present);
present=NULL;
}
pq->size --;
}
}
void display(appq *pq)
{
if(pq->front==NULL)
{
printf("Empty queue\n");
return;
}
else
{
node *temp=pq->front;
while(temp!=NULL)
{
printf("deleted details:\n");
printf("name:%s\ndate=%s\ntime=%s\n\n\n",temp->name,temp-
>date,temp->time);
temp=temp->link;
}
}
}
int main()
{
appq* pq;
pq=malloc(sizeof(appq));
pq->front=NULL;
pq->rear=NULL;
int s;
printf("ENter the number of patients the doctor see's in a day:\n");
scanf("%d",&pq->capacity);
int c=1;
while(c)
{ pq->size++;
insert_q(pq);printf("To book an appointment\npress1 to continue and 0 to stop\n");
scanf("%d",&c);
}
printf("the details of appoinemnt\n");
display(pq);
while(pq->front!=NULL)
{
delete(pq);
printf("AFter deleting the next one\n");
display(pq);
}
return 0;
}
