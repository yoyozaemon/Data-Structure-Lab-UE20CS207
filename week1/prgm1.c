#include<stdio.h>
#include<string.h>
int c(char *a,char *p)
{
if(*a==*p)
{
return c(a+1,p+1);
}
else if(*p=='\0')
{
return 1;
}
return 0;
}
int check(char *a,char *p)
{
if(*a==*p)
{
if(c(a,p))
{
return 1;
}
}
if(*a=='\0' && *p!='\0')
{
return 0;
}
return check(a+1,p);
}
int main()
{
char str[50];
char sub[20];
printf("Enter the string: ");
scanf("%s",str);
printf("Enter the substring: ");
scanf("%s",sub);
int r=check(str,);
if(r==1)
{
printf("The substring exists in the string\n");
}
else if(r==0)
{
printf("The substring does not exist in the string\n");
}
return 0;
}
