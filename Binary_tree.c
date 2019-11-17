#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *llink;
  struct node *rlink
};
struct node *read(){
  int item;
  struct node *temp;
  temp=(struct node *)malloc(sizeof (struct node));
  printf("Enter data of node:\n");
  scanf("%d",&item);
  temp->data=item;
  temp->llink=NULL;
  temp->rlink=NULL;
  return temp;
}
struct node *head;
void create(struct node *temp){
  struct node *root;
  if (head==NULL){
    head=temp;
  }
  else{
    root=start;
    while (root->llink!=NULL){
      root=root->llink;
    }
    root->llink=temp;
  }
}
struct node create_binary_tree(struct node *root,int elem){
  if (root==NULL){
    root=(struct node *)malloc(sizeof(struct node));
    root->left=root->right=NULL;
    root->data=elem;
    return root;
  }
  else if (root->left==NULL)
    root->left=create_binary_tree(root->left,elem);
  else if (root->right==NULL)
    root->right=create(root->right,elem);
  else
    return root;
}
