#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STACKSIZE 50

typedef struct stack {
  int top;
  int arr[STACKSIZE];
} STACK;

void init(STACK *ptr) { ptr->top = -1; }

void push(STACK *ptr, float element) {
  if (ptr->top == STACKSIZE - 1) {
    printf("Stack is full!\n");
  } else {
    ptr->top++;
    ptr->arr[ptr->top] = element;
  }
}

int pop(STACK *ptr) {
  if (ptr->top == -1) {
    printf("Stack is empty cannot delete..\n");
  } else {
    char x = ptr->arr[ptr->top];
    ptr->top--;
    printf("Deleted element is %c\n", x);
    return x;
  }
}

int peep(STACK *ptr) {
  if (ptr->top == -1) {
    printf("Stack is empty cannot delete..\n");
  } else {
    char x = ptr->arr[ptr->top];
    
    printf("The element at the top of the stack is %c\n", x);
    return x;
  }
}

int inputPrec(char ch) {
  if (ch == '+' || ch == '-') {
    return 1;
  } else if (ch == '*' || ch == '/') {
    return 3;
  } else if (ch == '$') {
    return 6;
  } else if (ch == ')') {
    return 0;
  } else if (ch == '(') {
    return 9;
  } else if (isalpha(ch) || isdigit(ch)) {
    return 7;
  }
}

int stackPrec(char ch) {
  if (ch == '+' || ch == '-') {
    return 2;
  } else if (ch == '*' || ch == '/') {
    return 4;
  } else if (ch == '$') {
    return 5;
  } else if (ch == '#') {
    return -1;
  } else if (ch == '(') {
    return 0;
  } else if (isalpha(ch) || isdigit(ch)) {
    return 8;
  }
}

char infixToPostfix(char *infix, char *postfix,STACK *ptr) {
  
  int i = 0, j = 0;
  char ch;
  push(ptr, '#');
  while (infix[i] != '\0') {
    ch = infix[i];
    if (isalpha(ch) || isdigit(ch)) {
      postfix[j] = ch;
      printf("added %c\n",ch);
      j++;

    }
    else {
      while (stackPrec(peep(ptr)) > inputPrec(ch) && ch!=peep(ptr)) {
        postfix[j] = pop(ptr);
        printf("popped %c\n",postfix[j]);
        printf("added %c\n",postfix[j]);
        j++;


      }
      if (inputPrec(ch) != stackPrec(peep(ptr))) {
      printf("pushed %c\n",ch);
      push(ptr, ch);
      } 
      else {
        printf("popped 1 %c\n",ch);
        pop(ptr);
      }
    }
    
    i++;
  }
  while (peep(ptr) != '#') {
    postfix[j++] = pop(ptr);
    postfix[j] = '\0';
  }
  return *postfix;
}

int lengthS(char infix[]){
    int i = 0;
    while (infix[i]!='\0') {
        i++;
    }
    return i;
}
char reverse(char infix[],char reverse[]){
    
    int length = lengthS(infix);
    for (int i = length-1;i>=0; i--) {
        if (infix[i]=='(') {
          
          reverse[length-i-1] = ')';
        }
        else if(infix[i]==')'){
          
          reverse[length-i-1] = '(';
        }
        
        else {
          
          reverse[length-i-1] = infix[i];
          
        }
    }
    reverse[length] = '\0';
    
}
    
    

float evaluate(char x,int op1,float op2){
    switch (x)
    {
    case '+':
        return op1+op2;
    case '-':
        return op1-op2;
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    case '$':
      return pow(op1,op2);
    // default:
    //     printf("unknown operator!\n");
    }

}


int main() {
  STACK s;
  init(&s);
  STACK sprefix;
  init(&sprefix);
  
  char infix[20];
  char postfix[20];
  char reversedInfix[20];
  char prefix[20];
  char i;
  float op1,op2,result;

  scanf("%s", infix);
  reverse(infix,reversedInfix);
  printf("\n%s\n",reversedInfix);
  infixToPostfix(reversedInfix,postfix,&s);
  printf("\n%s\n",postfix);
  reverse(postfix,prefix);
  printf("\n%s\n",prefix);
  
  int lengthOfPrefix = lengthS(prefix);
  

  for (int i = lengthOfPrefix;i>=0; i--) {
    if (isdigit(prefix[i])) {
      push(&sprefix,prefix[i]-48);
      // printf("pushed element is %d",i);
    }
    else {
      op1 = pop(&sprefix);
      op2 = pop(&sprefix);
      result = evaluate(prefix[i],op1,op2);
      push(&sprefix,result);
    }
  }
  printf("Prefix evaluation is %f\n",result);
  


  
  
  
  
  printf("Code written by Aaditya Dev Sharma.\n");

}
