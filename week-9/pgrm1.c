#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
typedef long long int ll;
#define size 10000
struct head{
struct person* next;
};
struct person{
ll phone;
char name[30];
struct person* next; //this is for chaning
};
void InitHashTable(struct head* details){
for(int i=0;i<size;i++)
(details+i)->next=NULL;
}
int HashFunction(ll key){
int fn = key%10;key/=10;fn+=key%10;
int index = (fn*2)%7;
}
void HeapInsert(struct head* details , struct person* d){
ll ph = d->phone;
int index = HashFunction(ph);
if((details+index)->next == NULL){
(details+index)->next=d; //inserting first node!
printf("\n Inserted to Hash Table :) \n \n");
return;
}
else{
struct person* curr = (details+index)->next; //moving to chain!
while(curr->next!=NULL)curr=curr->next;
curr->next = d;
printf("\n Inserted to Hash Table UwU\n \n");
return;
}
}
void HashTableSearch(struct head* details ,ll ph){
int index = HashFunction(ph);
if((details+index)->next == NULL){
printf("\n This number was not found in table :( \n \n");
return;
}
else{
printf("\n All records with this number : \n \n");
struct person* curr = (details+index)->next;//moving to chain
while(curr!=NULL)
{
if(curr->phone == ph){
printf("\n Phone number : %lli",curr->phone);
printf("\n Name : %s" , curr->name);
printf("\n \n");
curr=curr->next;
}
else
curr=curr->next;
}
}
}
void HashTableDelete(struct head* details , ll ph){
int index = HashFunction(ph);
if((details+index)->next == NULL){
printf("\n This number was not found in table :( \n \n");
return;
}
else if((details+index)->next->phone == ph){
//if first node
(details+index)->next=(details+index)->next->next;
printf("\n First record with that number deleted! \n \n");
return;
}
else{
struct person* curr = (details+index)->next;//moving to chain
struct person* del = curr->next;
while(del!=NULL){
if(del->phone == ph){
curr->next = NULL;
printf("\n First record with that number deleted! \n \n");
return;}
else{
curr= del;
del=del->next;
}
}
printf("\n This number was not found in table :( \n \n"); //very specific cases
return;
}
}
void HastTableDisplay(struct head* details){
for(int i=0;i<size;i++){
if((details+i)->next != NULL)
{
struct person* curr = (details+i)->next;
printf("\n All record found in the table : \n \n");
while(curr!=NULL){
printf("\n Phone number : %lli",curr->phone);
printf("\n Name : %s" , curr->name);
printf("\n \n");
curr=curr->next;
}
}
}
}
int main(){
struct head details[size];
InitHashTable(details);
while(true){
printf("1.Insert to Hash Table \n");
printf("2.Search in Hash Table \n");
printf("3.Delete from Hash Table \n");
printf("4.Display full table \n");
int choice;
printf("Enter choice : ");
scanf("%d" , &choice);
if(choice == 1){
struct person* d = (struct person*)malloc(sizeof(struct person));
printf("Enter phone number : ");
scanf("%lli" , &(d->phone));
printf("Enter name : ");
scanf("\t%[^\n]%*c" ,d->name);
d->next=NULL;
// //testing
// printf("%lli" , d->phone);
// printf("%s",d->name);
HeapInsert(details , d);
}else if(choice == 2){
ll ph;
printf("Enter phone number to search : ");
scanf("%lli" , &ph);
HashTableSearch(details , ph);
}
else if(choice == 3){
ll ph;
printf("Enter phone number to delete : ");
scanf("%lli" , &ph);
HashTableDelete(details , ph);
}
else if(choice == 4){
HastTableDisplay(details);
}
}
}
