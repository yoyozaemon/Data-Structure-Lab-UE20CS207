#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
char temp;
temp = *a;
*a = *b;
*b = temp;
}
void permutation(char *a, int n, int r)
{
int i;
if(n==r)
{
printf("%s\n",a);
}
else
{
for(i=n;i<=r;i++)
{
swap((a+n),(a+i));
permutation(a, n+1, r);
swap((a+n),(a+i));
}
}
}
int main()
{
char str[100];
printf("Enter string:");
scanf("%s",str);
printf("The permutations for the given string are:\n");
int n=strlen(str);
permutation(str,0,n-1);
return 0;
}
