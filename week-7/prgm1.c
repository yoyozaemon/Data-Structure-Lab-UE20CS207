#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trees
{
char a[20];
struct trees *lchild;
struct trees *rchild;
}trees;
trees *createnode(char *ele)
{
trees *temp;
temp=malloc(sizeof(trees));
strcpy(temp->a,ele);
temp->lchild=NULL;
temp->rchild=NULL;
return temp;
}
void insert(trees **root,char *ele)
{
trees *cur;
trees *prev;
trees *newnode;
newnode=createnode(ele);
if(*root==NULL)
{
*root=newnode;
return;
}
else
{
cur=*root;
prev=NULL;
while(cur!=NULL)
{
prev=cur;
if(strcmp(cur->a,ele)>0)cur=cur->lchild;
else
cur=cur->rchild;
}
if(strcmp(prev->a,ele)>0)
prev->lchild=newnode;
else
prev->rchild=newnode;
}
}
void search(trees *root,char *key)
{
if(root==NULL)
{
printf("Not found\n");
}
else if(strcmp(root->a,key)==0)
{
printf("SRN found\n");
}
else if(strcmp(root->a,key)>0)
{
search(root->lchild,key);
}
else
{
search(root->rchild,key);
}
}
void display(trees *root)
{
if(root==NULL)
return;
else
{
display(root->lchild);
printf("%s\n",root->a);
display(root->rchild);
}
}
int main()
{
trees *root;
int n,i=0,cap;
char m[50];
char b[20];root=NULL;
do
{
printf("1)Insert\n2)Display\n3)Search\n");
scanf("%d",&n);
switch(n)
{
case 1: printf("Enter number of SRN:");
scanf("%d",&cap);
i=0;
while(i<cap)
{
printf("\nInsert SRN: %d",i+1);
scanf("%s",m);
fflush(stdout);
insert(&root,m);
i++;
}
printf("Successfully inserted\n");
break;
case 2: printf("SRNs are:\n");
display(root);
break;
case 3: printf("Enter the SRN to search:");
scanf("%s",b);
search(root,b);
}
}while(1);
}
