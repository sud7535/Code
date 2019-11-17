#include<stdio.h>
int binary(int a[10], int l, int h, int x);
int binary(int a[10], int l, int h, int x)
{
	int mid;
	if(l<=h)
	{
		mid=(l+h)/2;
	}
		if(a[mid]==x)
		{
			return mid;
		}
		else if(a[mid]>x)
		{
			return binary(a, l, mid-1, x);
		}
		else if(a[mid
 ]<x)
		{
			return binary(a, mid+1, h, x);
		}
		else
		{
			return -1;
		}
}  
int main()
{
	int a[20], i, x, n, result;
	printf("Enter the array size\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d", &a[i]);
	printf("Enter the element to be searched\n");
	scanf("%d", &x);
	result=binary(a, 0, n-1, x);
	if(result==-1)
	{
		printf("Element not found\n");
	}
	else
	{
		printf("Element %d is present at %d position", x, result+1);
	}
} 
