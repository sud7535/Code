#include<stdio.h>
#include<stdlib.h>
void bfs();
void dfs();
int a[10][10],v,i,j,n,ch,q[10],visited[10],f=0,r=-1;
void main()
{

printf("\n enter the no. of vertices");
scanf("%d",&n);
printf("\nenter graph data in the form of matrix");
for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
  }
}
printf("enter the starting vertex");
scanf("%d",&v);
for(i=1;i<=n;i++)
{
 q[i]=0;
 visited[i]=0;
}
printf("\n1.BFS\n2.DFS\n3.exit");
printf("\n enter your choice");
scanf("%d",&ch);
switch(ch)
{
 case 1: bfs(v);
         for(i=1;i<=n;i++)
         if(visited[i])
         {
    	   printf("%d \t",i);
         }
 	 else
  	 {
   	 printf("BFS is not possible");
 	 } 
         break;
 case 2: dfs(v);
         break;
 case 3: exit(0);
 default:printf("\n invalid choice");
}
}
void bfs(int v)
{
 for(i=1;i<=n;i++)
  if(a[v][i]&&!visited[i])
       q[++r]=i;
   if(f<= r)
   {
    visited[q[f]]=1;
    bfs(q[f++]);
   }
}
void dfs(int v)
{
 int i;
 visited[v]=1;
 for(i=1;i<=n;i++)
  if(a[v][i]&&!visited[i])
  {
   printf("\n%d->%d",v,i);
   dfs(i);
  }
} 




