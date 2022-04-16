#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
int info;
struct node* next;
}NODE;
typedef struct ll
{
NODE* head;
}LL;
void init(LL* pl)
{
pl->head = NULL;
}
void add_ele(LL* pl, int e)
{
NODE* temp;
temp = (NODE*)malloc(sizeof(NODE));
temp->info = e;
temp->next = pl->head;
pl->head = temp;
}
void disp(LL* pl)
{
NODE* p = pl->head;
printf("Elements: \n");
while(p){
  printf("%d\t", p->info);
p = p->next;
}
printf("\n");
}
void alt_node(LL* pl){
NODE* p = pl->head;
printf("Alternate elements: \n");
while(p){
printf("%d\t", p->info);
if(p->next) p = p->next->next;
else break;
}
printf("\n");
}
int main(){
LL ll;
init(&ll);
add_ele(&ll, 5);
add_ele(&ll, 4);
add_ele(&ll, 3);
add_ele(&ll, 2);
add_ele(&ll, 1);
disp(&ll);
alt_node(&ll);
return 0;
}
