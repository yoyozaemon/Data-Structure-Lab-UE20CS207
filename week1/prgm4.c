#include<stdio.h>
void main()
{
void toh(int, char, char, char);
int n;
printf("\nEnter the no of disks..");
scanf("%d",&n);
toh(n,'A','B','C');
printf("\n");
}
void toh(int n, char s, char t, char d)
{
if(n==1)
{
printf("Move disk % d form %c to %c\n", n,s,d);
return;
}
toh(n-1,s,d,t);
printf("Move disk %d from %c to %c \n",n,s,d);
toh(n-1,t,s,d);
}
