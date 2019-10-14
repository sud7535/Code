#include<stdio.h>
#include<stdlib.h>
#define size 5
int top=-1,a[size];
#define clear() printf("\033[H\033[J")
int stfull();
void push(int item);
int pop();
int stempty();
void display();
void main()
{
	int c=1,choice,item,x;
	while(c==1)
	{
	printf("STACK OPERATIONS\n");
	printf(" 1.Push \n 2.Pop \n 3.Display \n 4.Exit\n");
	printf("Enter your choice:\n");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1: if (stfull()==1){
			printf("stack is overflow\n");
		}
			else{
			printf("Enter the element to push\n");
			scanf(" %d",&item);
			push(item);
		}
			break;
		case 2: if (stempty()==1){
			printf("Stack is underflow");
		}
			else{
			x=pop();
			printf("popped element is %d",x);
			}
			break;
		case 3: display();
		break;
		case 4: exit(0);
		break;
	}
	}}
int stfull()
{
	if (top==size-1)
		return 1;
	return 0;
}
void push(int item)
{
	top=top+1;
	a[top]=item;
}
int stempty()
{
	if (top==-1)
		return 1;
	return 0;
}
int pop()
{
	int item;
	item=a[top];
	top=top-1;
	return item;
}
void display()
{
	printf("Stack elements are\n");
	int i;
	for(i=top;i>=0;i--)
		printf("%d\n",a[i]);
}



