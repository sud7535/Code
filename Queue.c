#include<stdio.h>
#include<stdlib.h>
#define size 100
int front=0, rear=-1,item=0;
int isempty(){
  if (front<0||front>rear)
    return 1;
  else
    return 0;
}

int isfull(){
  if (rear==size-1)
    return 1;
  else
    return 0;
}

int a[size];

void enqueue(int item){
  rear=rear+1;
  a[rear]=item;
}

int dequeue(){
  int item=a[front];
  front=front+1;
  return item;
}

void display(){
  for (int i=front;i<=rear;i++){
    printf("%d\t",a[i]);
  }
  printf("\n");
}

void main(){
  int x=0,choice,item;
  while(x==0){
    printf("Enter choice to perform queue operations:");
    printf("\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
    scanf("%d",&choice);
    switch (choice){
    case 1:if (isfull()==1){
	printf("Queue Overflow");
      }
      else{
	printf("Enter element to be added:\n");
	scanf("%d",&item);
	enqueue(item);
      }
      break;
    case 2:if (isempty()==1)
	printf("Queue Underflow");
      else{
	int z=dequeue();
	printf("%d is the element removed\n",z);
      }
      break;
    case 3:display();
      break;
    case 4:exit(0);
      break;
    default:printf("Invalid Operation");
      break;
    }
  }
}
    

  
