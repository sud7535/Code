#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};

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


void enqueue(){
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


void dequeue(){
  struct node *rem,*trav,*temp;
  int i=1,x,length;
  rem=start;
  start=rem->link;
  free(rem);
 }

void dis(){
  struct node *root;
  root=start;
  printf("START--->");
  while (root!=NULL){
    printf("%d--->",root->data);
    root=root->link;
  }
  printf("NULL\n");
  printf("%d\n",len());
}
  
void main(){
  int y=0;
  int n,x;
  start=NULL;
  while (y==0){
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Operation to perform:");
    scanf("%d",&x);
    switch (x){
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      dis();
      break;
    case 4:
      exit(0);
      break;
    }
  }
} 
