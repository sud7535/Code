#include<stdio.h>
	void add(int m,int n,int p,int q,int a[m][n],int b[m][n]);
	void sub(int m,int n,int p,int q,int a[m][n],int b[m][n]);
	void mlt(int m,int n,int p,int q,int a[m][n],int b[p][q]);
	void main()
	{
	int i,j,m,n,p,q;
	char op;
	printf("Number of rows of Matrix A:");
	scanf("%d",&m);
	printf("Number of columns of Matrix A:");
	scanf("%d",&n);
	printf("Number of rows of Matrix B:");
	scanf("%d",&p);
	printf("Number of columns of Matrix B:");
	scanf("%d",&q);
	printf("Operation to perform(a,s,m):");
	scanf("\n%c",&op);
	int a[m][n],b[p][q];
	printf("Enter Elements of Matrix A:\n");
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	printf("Enter Elements of Matrix B:\n");
	for (i=0;i<p;i++)
	for (j=0;j<q;j++)
	scanf("%d",&b[i][j]);

	switch(op)

	{
	case 'a':if (m!=p&&n!=q){
	printf("Operation not possible");
	}
	else
	{
	add(m,n,p,q,a,b);
	}
	break;
	case 's':if (m!=p&&n!=q){
	printf("Operation not possible");
	}
	else
	{
	sub(m,n,p,q,a,b);
	}
	break;
	case 'm':if (m!=q){
	printf("Operation not possible");
	}
	else
	{
	mlt(m,n,p,q,a,b);
	}
	break;
	}
	}
	void add(int m,int n,int p,int q,int a[m][n],int b[m][n])
	{
	int c[m][n],i,j;
	printf("Result is:\n");
	for (i=0;i<m;i++){
	for (j=0;j<n;j++){
	printf("%d\t",a[i][j]+b[i][j]);
	}
	printf("\n");
	}}
	void sub(int m,int n,int p,int q,int a[m][n],int b[m][n])
	{
	int c[m][n],i,j;
	printf("Result is:");
	for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	printf("%d\t",a[i][j]-b[i][j]);
	}	
	printf("\n");
	}
	}
	void mlt(int m,int n,int p,int q,int a[m][n],int b[m][n]){
	int i,j,sum=0,c[m][n];
	for (int i=0;i<m;i++)
	{
	for (int j=0;j<q;j++)
	{
	for (int k=0;k<p;k++)
	{
	printf("%d\t",a[i][k]+b[k][j]);
	}}printf("\n");}
	}
