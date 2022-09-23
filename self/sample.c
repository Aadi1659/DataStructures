#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 100
typedef struct stack{
  char st[MAX];
  int top;
}STACK;
void push(STACK *ptr, char ele) {
  ptr->top++;
  ptr->st[ptr->top]=ele;
}
char pop(STACK *ptr) {
  return ptr->st[ptr->top--];
}
int priority(char ele){
  switch(ele) {
    case '+':return 1;
    case '-':return 1;
    case '*':
    case '/':
    case '%': return 2;
    case '$':
    case '^': return 3;
    default: return 0;
  }
}
char reverse(char st[]) {
  for(int i=0; i<strlen(st); i++) {
    if(st[i]=='(') st[i]=')';
    else if(st[i]==')') st[i]='(';
   
  }
  short len=0,i,j;
  char temp; 
  len=strlen(st);
  for(i=len-1,j=0;j<(len/2); i--,j++){
        temp=st[j];
        st[j]=st[i];
        st[i]=temp;
    }    
  //strrev(st);
}
int compute(char symb, int op1, int op2) {
  switch(symb) {
    case '+':return op1+op2;
    case '-':return op1-op2;
    case '*':return op1*op2;
    case '/':return op1/op2;
    case '$':
    case '^':return pow(op1,op2);
    case '%':return op1%op2;
  }
}
int eval(char prefix[]) {
  
  int i,s[100],top=-1;
  int res,op1,op2; char symb;
  for(i=strlen(prefix)-1; i>=0; i--) {
    symb=prefix[i];
    if(isdigit(symb)) s[++top]=symb-'0';
    else {
      op1=s[top--];
      op2=s[top--];
      res=compute(symb,op1,op2);
      s[++top]=res;
    }
  }
  res=s[top--];
  return res;
}
int main() {
  char infix[MAX],prefix[MAX];
  int l;
  STACK *ptr,s;
  ptr=&s;
  s.top=-1;
  scanf("%d%s",&l,infix);
  reverse(infix);
  push(ptr,'(');
  strcat(infix,")");
  int i=0, k=0; char x;
  while(infix[i]!='\0'){
    if(infix[i]=='(') push(ptr,infix[i]);
    else if(isalnum(infix[i])) prefix[k++]=infix[i];
    else if(infix[i]==')'){
      while(s.st[s.top]!='(') prefix[k++]=pop(ptr);
      x=pop(ptr);
    }
    else{
    while((priority(s.st[s.top])>priority(infix[i]))) {
      prefix[k++]=pop(ptr);
    }
    push(ptr,infix[i]);
  }i++;
  }
  prefix[k]='\0';
  reverse(prefix);
  printf("%s %d",prefix,eval(prefix));
  return 0;
}



