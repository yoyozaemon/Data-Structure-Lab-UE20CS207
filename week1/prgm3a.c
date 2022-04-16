#include<stdio.h>
#include<string.h>
typedef struct student
{
char srn[15];
char name[50];
float chem,phy,math,bio,cs;
}stud_t;
void read(stud_t a[],int n);
void display(stud_t a[],int n);
void average(stud_t a[], int n);
void sort(stud_t a[], int n);
int main()
{
stud_t a[10];
int n,choice;
printf("Enter number of student: ");
scanf("%d",&n);
fflush(stdin);
read(a,n);
do
{
printf("1. display, 2. average, 3. sort\n4. exit\n Enter choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
display(a,n);
break;
}
case 2:
{
average(a,n);
break;
}
case 3:
{
printf("List of students sorted based on SRN: ");
sort(a,n);
break;
}
}
}while(choice!=4);
return 0;
}
void read(stud_t s[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("For student %d\n",i+1);
printf("Enter your srn: ");
scanf("%s",s[i].srn);
fflush(stdin);
printf("Enter name: ");
scanf("%s",s[i].name);
fflush(stdin);
fflush(stdin);
printf("Enter your maths marks: ");
scanf("%f",&s[i].math);
fflush(stdin);
printf("Enter your chem marks: ");
scanf("%f",&s[i].chem);
fflush(stdin);
printf("Enter your physics marks: ");
scanf("%f",&s[i].phy);
fflush(stdin);
printf("Enter your cs marks: ");
scanf("%f",&s[i].cs);
fflush(stdin);
printf("Enter your bio marks: ");
scanf("%f", &s[i].bio);
fflush(stdin);
}
}
void display(stud_t s[],int n)
{
for(int i=0;i<n;i++)
{
printf("For student %d\n",i+1);
  printf("\nSrn: ");
printf("%s",s[i].srn);
printf("\nName: ");
printf("%s",s[i].name);
printf("Maths marks: ");
printf("%f\n",s[i].math);
printf("Chem marks: ");
printf("%f\n",s[i].chem);
printf("Physics marks: ");
printf("%f\n",s[i].phy);
printf("CS marks: ");
printf("%f\n",s[i].cs);
printf("Bio marks: ");
printf("%f\n\n\n",s[i].bio);
}
}
void average(stud_t a[], int n)
{
int m,i;
int sum=0;
float avg;
printf("Enter subject number: \n1.chem \n2.math \n3.phy \n4.cs \n5.bio ");
scanf("%d",&m);
switch(m)
{
case 1:
{
sum=0;
for(i=0;i<n;i++)
{
sum+=a[i].chem;
}
avg = sum/n;
printf("average chem marks: %f\n",avg);
break;
}
case 2:
{
sum=0;
for(i=0;i<n;i++)
{
sum+=a[i].math;
}
avg = sum/n;
printf("average math marks: %f\n",avg);
break;
}
case 3:
{
  sum=0;
for(i=0;i<n;i++)
{
sum+=a[i].phy;
}
avg = sum/n;
printf("average phy marks: %f\n",avg);
break;
}
case 4:
{
sum=0;
for(i=0;i<n;i++)
{
sum+=a[i].cs;
}
avg = sum/n;
printf("average cs marks: %f\n",avg);
break;
}
case 5:
{
sum=0;
for(i=0;i<n;i++)
{
sum+=a[i].bio;
}
avg = sum/n;
printf("average bio marks: %f\n",avg);
break;
}
}
}
void sort(stud_t a[], int n)
{
int i,j,pos;
stud_t temp;
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(a[j].srn<a[j+1].srn)
{
pos=j;
}
}
if(pos!=i)
  {
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
printf("\n\nStructure after sorting: \n\n");
display(a,n);
return;
}
