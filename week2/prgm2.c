#include<stdio.h>
#include<stdlib.h>
typedef struct link {
int coeff;
int px;
int py;
struct link * next;
} my_poly;
void my_create_poly(my_poly **);
void my_show_poly(my_poly *);
void my_add_poly(my_poly **, my_poly *, my_poly *);
int main() {
int ch;
do {
my_poly * poly1, * poly2, * poly3;
printf("\nCreating 1st expression\n");
my_create_poly(&poly1);
printf("\nStoring the 1st expression");
my_show_poly(poly1);
printf("\nCreating 2nd expression\n");
my_create_poly(&poly2);
printf("\nStoring the 2nd expression");
my_show_poly(poly2);
my_add_poly(&poly3, poly1, poly2);
my_show_poly(poly3);
scanf("%d", &ch);
} while (ch);
return 0;
}
void my_create_poly(my_poly ** node) {
int num;
int coeff, px,py;
my_poly * tmp_node;
tmp_node = (my_poly *) malloc(sizeof(my_poly));
*node = tmp_node;
printf("Enter the no of terms:\n");
scanf("%d", &num);do {
printf("\nEnter Constant:");
scanf("%d", &coeff);
tmp_node->coeff = coeff;
printf("\nEnter x^:");
scanf("%d", &px);
tmp_node->px= px;
printf("\nEnter y^:");
scanf("%d", &py);
tmp_node->py= py;
tmp_node->next = NULL;
num=num-1;
if(num) {
tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
tmp_node = tmp_node->next;
tmp_node->next = NULL;
}
} while (num);
}
void my_show_poly(my_poly * node) {
printf("\nexpression is:\n\n");
while(node != NULL) {
printf("%dx^%dy^%d", node->coeff, node->px,node->py);
node = node->next;
if(node != NULL)
printf(" + ");
}
}
void my_add_poly(my_poly ** result, my_poly * poly1, my_poly * poly2) {
my_poly * tmp_node;
tmp_node = (my_poly *) malloc(sizeof(my_poly));
tmp_node->next = NULL;
*result = tmp_node;
while(poly1 && poly2) {
if (poly1->px > poly2->px || poly1->py >poly2->py ) {
tmp_node->px = poly1->px;
tmp_node->py = poly1->py;
tmp_node->coeff = poly1->coeff;
poly1 = poly1->next;
}
else if (poly1->px < poly2->px || poly1->py< poly2->py) {
tmp_node->px = poly2->px;
tmp_node->py = poly2->py;tmp_node->coeff = poly2->coeff;
poly2 = poly2->next;
}
else {
tmp_node->px= poly1->px;
tmp_node->py= poly1->py;
tmp_node->coeff = poly1->coeff + poly2->coeff;
poly1 = poly1->next;
poly2 = poly2->next;
}
if(poly1 && poly2) {
tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
tmp_node = tmp_node->next;
tmp_node->next = NULL;
}
}
while(poly1 || poly2) {
tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
tmp_node = tmp_node->next;
tmp_node->next = NULL;
if(poly1) {
tmp_node->px = poly1->px;
tmp_node->py = poly1->py;
tmp_node->coeff = poly1->coeff;
poly1 = poly1->next;
}
if(poly2) {
tmp_node->px = poly2->px;
tmp_node->py = poly2->py;
tmp_node->coeff = poly2->coeff;
poly2 = poly2->next;
}
}
}
