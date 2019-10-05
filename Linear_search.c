#include<stdio.h>
void search(int r, int c, int a[r][c],int item);

int main ()
{
int r,c,i,j,item;
printf("Number of rows:");
scanf("%d",&r);
printf("Number of columns:");
scanf("%d",&c);
int a[r][c];
printf("Elements of array\n");
for (i=0;i<r;i++)
for (j=0;j<c;j++)
scanf("%d",&a[i][j]);
printf("Element to be searched:");
scanf("%d",&item);
search(r,c,a,item);
}
void search(int r, int c,int a[r][c],int item)
{
int i,j,flag=2;
for (i=0;i<r;i++){
for (j=0;j<c;j++){
if (a[i][j]==item)
{
printf("Element found at {%d, %d}\n",i+1,j+1);
flag=1;
break;
}}}
if (flag!=1)
printf("not found");
}

