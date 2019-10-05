#include<stdio.h>
#include<stdlib.h>
#define size 100
#include<ctype.h>
char stack[size];
int top=-1;
void push(char item){
  if (top>=size-1){
    printf("\n Stack Overflow");
  }
  else {
    top=top+1;
    stack[top]=item;
  }
}
char pop(){
  char item;
  if (top<0){
    printf("Stack Underflow");
    getchar();
  }
  else {
    item=stack[top];
    top--;
    return item;
  }
}
int isoperator(char symbol){
  if (symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-'){
    return 1;
  }
  return 0;
}
int precedence(char symbol){
  if (symbol=='^')
    return 3;
  else if (symbol=='/'||symbol=='*')
    return 2;
  else if (symbol=='+'||symbol=='-')
    return 1;
  return 0;
}
void infixtopostfix(char infixexp[],char postfixexp[]){
  int i=0,j=0;
  char x,item;
  push('(');
  strcat(infixexp,")");
  item=infixexp[i];
  while (item!='\0'){
    if (item=='('){
      push(item);
    }
    else if(isdigit(item)||isalpha(item)){
      postfixexp[j]=item;
      j++;
    }
    else if (isoperator(item)==1){
      x=pop();
      while (isoperator(x)=='1'&& precedence(x)>=precedence(item)){
	postfixexp[j]=x;
	j++;
	x=pop();
      }
      push(x);
      push(item);
    }
    else if (item==')'){
      x=pop();
      while (x!='('){
	postfixexp[j]=x;
	j++;
	x=pop();
      }}
    else {
      printf("Invalid Infix Expression");
      exit(1);
    }
    i++;
    item=infixexp[i];
  }
  postfixexp[j]='\0';
}

void main(){
  char infix[size],postfix[size];
  printf("Enter Infix Expression:");
  gets(infix);
  infixtopostfix(infix,postfix);
  printf("Postfix Expression:");
  puts(postfix);
}
  
