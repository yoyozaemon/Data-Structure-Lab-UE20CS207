#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct element
{
int key;
char name[100];
int mark;
};
struct hash
{
struct node *head;
int count;
};void insert_To_hash(struct element *ht, int size,int key,char *name,int *count)
{
int index;
if(size==*count)
{
printf("\ntable full\n");
return;
}
index=key%size;
while(ht[index].mark!=0)
index=(index+1)%size;
ht[index].key=key;
strcpy(ht[index].name,name);
ht[index].mark=1;
(*count)++;
return;
}
void delete_hash(struct element *ht, int size,int key,int *count)
{
int i,index;
printf("\nCount=%d\n",*count);
if(count==0)
{
printf("\nTable empty\n");
return;
}
index=key%size;
i=0;
while(i<*count)
{
if(ht[index].mark==1)
{
if(ht[index].key==key)
{
ht[index].mark=0;
(*count)--;
return ;
}
i++;
}
index=(index+1)%size;
}
printf("\nPhone number not found\n");
return;
}
void display(struct element* ht, int size){
int i;
for(i=0;i<size;i++)
{
printf(" %d ",i);
if (ht[i].mark!=0)
printf("Phone number=%d,Name=%s",ht[i].key,ht[i].name);
printf("\n");
}
}
void search_hash(struct element *ht, int size,int key,int count)
{
int i,index;
if(count==0)
{
printf("\nTable empty\n");
return;
}
index=key%size;
i=0;
while(i<count)
{
if(ht[index].mark==1)
{
if(ht[index].key==key)
{
printf("\nThe number is found\n");
printf("\nnumber=%d name=%s\n\n\n",ht[index].key,ht[index].name);
return;
}
i++;
}
index=(index+1)%size;
}
printf("\nKey not found\n");
return;
}
int main()
{
struct element *hashtable;
int i,n,ch,key,no_elements;
char name[100];
int tablesz;
printf("\nEnter table size:");scanf("%d",&tablesz);
hashtable=(struct element*)(malloc(tablesz* sizeof(struct element)));
for(i=0;i<tablesz;i++)
{
hashtable[i].mark=0;
no_elements=0;
}
while(1)
{
printf("1 to Insert\n");
printf("2 to Delete\n");
printf("3 to Search\n");
printf("4 to Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter Phone number..\n");
scanf("%d",&key);
printf("Enter name..\n");
scanf("%s",name);
insert_To_hash(hashtable,tablesz,key,name,&no_elements);
break;
case 2:printf("Enter Phone number to be deleted\n");
scanf("%d",&key);
delete_hash(hashtable,tablesz,key,&no_elements);
break;
case 3:printf("Enter the phone number to be searched\n");
scanf("%d",&key);
search_hash(hashtable,tablesz,key,no_elements);
case 4:display(hashtable,tablesz);
break;
default:exit(0);
}
}
}
