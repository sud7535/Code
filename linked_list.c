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

void bgn(){
  struct node *first; 
  first=read();
  if (start==NULL){
    start=first;
  }
  else {
    first->link=start;
    start=first;
  }
}

void end(){
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

void pos(){
  struct node *tra,*dest,*swap;
  int i=1,x,length;
  dest=read();
  tra=start;
  length=len();
  printf("Position to Insert at:");
  scanf("%d",&x);
  if (x==1){
    dest->link=start;
    start=dest;
  }
  else if (x<=length+1){
      while (i<=x-2){
	tra=tra->link;
	i++;
      }
      swap=tra->link;
      dest->link=swap;
      tra->link=dest;
  }
}

void del(){
  struct node *rem,*trav,*temp;
  int i=1,x,length;
  length=len();
  printf("Enter position to delete: ");
  scanf("%d",&x);
  trav=start;
  if (x==1){
    rem=start;
    start=rem->link;
    free(rem);
  }
  else if (x<=length+1){
    while (i<=x-2){
      trav=trav->link;
      i++;
    }
    rem=trav->link;
    temp=rem->link;
    trav->link=temp;
    free(rem);
  }
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
    printf("1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete\n5.Display\n6.Exit\n");
    printf("Operation to perform:");
    scanf("%d",&x);
    switch (x){
    case 1:
      bgn();
      break;
    case 2:
      end();
      break;
    case 3:
      pos();
      break;
    case 4:
      del();
      break;
    case 5:
      dis();
      break;
    case 6:
      exit(0);
      break;
    }
  }
} 
