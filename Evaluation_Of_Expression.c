#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define size 100
int top=-1;
char stack[size];
int isoperator(char symbol){
  if (symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-'){
    return 1;
  }
  return 0;
}
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
void eval(char exp[]){
  int i=0,x,y,z;
  int item=exp[i];
  while (item!='\0'){
    if (isdigit(item)){
      push(item-'0');
    }
    else if (isoperator(item)){
      int x=pop();
      int y=pop();
      switch (item){
	
      case '^':z=pow(y,x);
	break;
      case '/':z=y/x;
	break;
      case '*':z=y*x;
	break;
      case '+':z=y+x;
	break;
      case '-':z=y-x;
	break;
      }
      push(z);
    }
    i++;
    item=exp[i];
  }
  printf("Result:%d\n",stack[top]);
}
void main(){
  char exp[size];
  printf("Expression is:");
  gets(exp);
  eval(exp);
}
