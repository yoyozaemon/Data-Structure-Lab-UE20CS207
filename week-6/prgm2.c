#include<stdio.h>
#include<stdlib.h>
void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();
int stack1[100],stack2[100];
int top1=-1;
int top2 = -1;
int count = 0;
int main()
{int choice;
while(1)
{printf("1. Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
printf("Enter choice:");
scanf("%d",&choice);
switch(choice)
{case 1 : enqueue();
break;
case 2 : dequeue();
break;
case 3 : display();
break;
case 4 : exit(0);
}
}
}
void dequeue()
{
for(int i=0; i<=count; i++)
{push2(pop1());}
pop2();
count--;
for(int i=0;i<=count;i++)
{push1(pop2());
}
}
void push1(int element)
{stack1[++top1] = element;
}
void push2(int element){stack2[++top2] = element;}
int pop1()
{return stack1[top1--];}
int pop2()
{return stack2[top2--];}
void enqueue()
{int data, i;
printf("Enter element: ");
scanf("%d",&data);
push1(data);
count++;
}
void display()
{int i;
if(top1==-1)
{printf("Empty queue\n");}
else
{ printf("Queue elements: \n");
for(i=0; i<=top1; i++)
{ printf("%d\t", stack1[i]);
}
printf("\n");
}
}
