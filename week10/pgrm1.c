#include <stdio.h>
int visit[100];
void creategraph(int(*)[]);
void dfs(int(*)[],int);
int n;
int strong_connect(int(*)[]);
int weak_connect(int(*)[]);
void remove_edge_direction(int(*)[],int(*)[]);
int component(int (*a)[100], int n, int source);
void main()
{
int result,source;
int a[100][100],b[100][100];
printf("Enter the number of vertices: ");
scanf("%d",&n);
creategraph(a);
result = strong_connect(a);
if(result)
{
printf("Strongly Connected Graph.");
}
else {
remove_edge_direction(a,b);
result=weak_connect(b);
if(result)printf("Weakly Connected Graph.");
else printf("Graph is not connected.");
printf("Enter source\n");
scanf("%d",&source);
int res= component(a,n,source);
printf("number of components: %d\n",res);
}
}
void creategraph(int(*a)[100])
{
int i,j;
while(1)
{
printf("Enter the source and destination vertices..");scanf("%d%d",&i,&j);
if((i==0)&&(j==0))break;
a[i][j]=1;
}
}
void dfs(int(*a)[100],int v)
{
int i;
visit[v]=1;
for(i=1;i<=n;i++)
{
if((a[v][i]==1)&& (visit[i]==0))
dfs(a,i);
}
}
int strong_connect(int(*a)[100])
{
int i,j;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
visit[j]=0;
dfs(a,i);
for(j=1;j<=n;j++)
if(visit[j]==0) return 0;
}
return 1;
}
int weak_connect(int (*b)[100])
{int j,count=1;
for(j=1;j<=n;j++)
visit[j]=0;
dfs(b,1);
for(j=1;j<=n;j++)
{
if(visit[j]==0)
//count++;
return 0;
}
return 1;
}
void remove_edge_direction(int(*a)[100],int(*b)[100])
{int i,j;for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(a[i][j]==1)
b[i][j]=b[j][i]=1;
}
}
}
int component(int (*a)[100], int n, int source)
{
int count = 1;
dfs(a,source);
for(int i=1;i<=n;i++)
{
if(!visit[i])
{
count++;
dfs(a,i);
}
}
return count;
}
