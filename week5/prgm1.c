#include <stdio.h>
#include <stdlib.h>
#define max 5
void insert();
void delete();
void display();
int front=-1,rear=-1;
int queue[max];
void main()
{
int choice;
while(choice!=4)
{
printf("\nMAIN MEANU\n1.INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT");
printf("\nENTER YOUR CHOICE: ");
scanf("%d",&choice);
switch(choice)
{
case 1:insert(); break;
case 2:delete(); break;
case 3:display(); break;
case 4:exit(0); break;
default: printf("\n Enter valid choice");
}
}
}
void insert()
{
int item;
printf("\nEnter ELEMENT\n");
scanf("\n%d",&item);
if(rear==max-1)
{
printf("\nOVERFLOW\n");
return;
}
if(front==-1&&rear==-1)
{
front=0;
rear=0;
}
else
{rear=rear+1;
}
queue[rear]=item;
printf("\nVALUE INSERTED");
}
void delete()
{
int item;
if(front==-1||front>rear)
{
printf("\nUNDERFLOW\n");
return;
}
else
{
item=queue[front];
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
front=front+1;
}
printf("\nVALUE DELETED");
}
}
void display()
{
int i;
if(rear==-1)
{
printf("\nEMPTY QUEUE\n");
}
else
{
printf("\nThe elements of the queue are:\n");
for(i=front;i<=rear;i++)
{
printf("\n%d\n",queue[i]);
}
}
}
