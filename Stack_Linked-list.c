#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};

struct node *start;
int len(){
  int count=0;
  struct node *root;
  root=start;
  while(root!=NULL){
    count++;
    root=root->link;
  }
  return count;
}

struct node *read(){
  int item;
  struct node *temp;
  temp=(struct node *)malloc(sizeof (struct node));
  printf("Enter data of node:\n");
  scanf("%d",&item);
  temp->data=item;
  temp->link=NULL;
  return temp;
}

void push(){
  struct node *last,*trav;
  last=read();
  trav=start;
  if (trav==NULL){
    start=last;
  }
  else {
    while (trav->link!=NULL){
      trav=trav->link;
    }
    trav->link=last;
  }
}

void pop(){
  struct node *tra,*dest,*swap;
  int i=1,x,length;
  tra=start;
  length=len();
  while (i<=length-2){
    tra=tra->link;
    i++;
  }
  swap=tra->link;
  printf("Element Popped:%d\n",swap->data);
      tra->link=NULL;
      free(swap);
}

void display(){
  struct node *root;
  root=start;
  printf("START--->");
  while (root!=NULL){
    printf("%d--->",root->data);
    root=root->link;
  }
  printf("NULL\n");
}


void main(){
  int y=0;
  int n,x;
  start=NULL;
  while (y==0){
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    printf("Operation to perform:");
    scanf("%d",&x);
    switch (x){
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
      break;
    }
  }
} 
