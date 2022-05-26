#include <stdio.h>
#include <stdlib.h>
typedef struct node{
int info;
struct node* next;
}NODE;
typedef struct ll{
NODE* head;
}LL;
void init(LL* pl){
pl->head = NULL;
}
void add_ele(LL* pl, int e){
NODE* temp;
temp = (NODE*)malloc(sizeof(NODE));
temp->info = e;
temp->next = pl->head;
pl->head = temp;
}
void disp(LL* pl){
NODE* p = pl->head;
printf("Elements: \n");
while(p){
printf("%d\t", p->info);
p = p->next;
}
printf("\n");
}
int swap_node(LL* ll, int x, int y){
if(x == y) return 0;
NODE *px, *py, *cx, *cy;
px = NULL;
py = NULL;
cx = ll->head;
  cy = ll->head;
while(cx && cx->info !=x){
px = cx;
cx = cx->next;
}
while(cy && cy->info !=y){
py = cy;
cy = cy->next;
}
if(cx==NULL || cy==NULL) return 0;
if(px) px->next = cy;
else ll->head = cy;
if(py) py->next = cx;
else ll->head = cx;
NODE* temp = cx->next;
cx->next = cy->next;
cy->next = temp;
return 1;
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
swap_node(&ll, 1, 5);
disp(&ll);
return 0;
}
