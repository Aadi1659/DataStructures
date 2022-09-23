#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    
  } else {
    int x = ptr->arr[ptr->top];
    ptr->top--;
   
    return x;
  }
}

int peep(STACK *ptr) {
  if (ptr->top == -1) {
  } else {
    int x = ptr->arr[ptr->top];
    return x;
  }
}

int inputPrec(char ch) {
  if (ch == '+' || ch == '-') {
    return 1;
  } else if (ch == '*' || ch == '/') {
    return 3;
  } else if (ch == '^') {
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
  } else if (ch == '^') {
    return 5;
  } else if (ch == '#') {
    return -1;
  } else if (ch == '(') {
    return 0;
  } else if (isalpha(ch) || isdigit(ch)) {
    return 8;
  }
}

char infixToPrefix(char *infix, char *postfix, STACK *ptr) {

  int i = 0, j = 0;
  char ch;
  push(ptr, '#');
  while (infix[i] != '\0') {
    ch = infix[i];
    while (stackPrec(peep(ptr)) > inputPrec(ch)) {
      postfix[j] = pop(ptr);
      j++;
    }
    if (inputPrec(ch) != stackPrec(peep(ptr))) {
      push(ptr, ch);
    } else {
      pop(ptr);
    }
    i++;
    
  }
  while (peep(ptr) != '#') {
    postfix[j++] = pop(ptr);
    postfix[j] = '\0';
  }     
  
  return *postfix;
}

int lengthS(char infix[]) {
  int i = 0;
  while (infix[i] != '\0') {
    i++;
  }
  return i;
}
char reverse(char infix[]){
    
    int length = lengthS(infix);
    for (int i =0;i<length;i++) {
      if (infix[i]=='(') infix[i]=')'; 
      else if (infix[i]==')') infix[i] = '(';
    }
      
    short i,j;
    char temp;   
    for (i = length-1,j = 0 ;j<length/2;i--,j++) {
        temp = infix[j];
        infix[j] = infix[i];
        infix[i] = temp; 
    }
    
    
}

float evaluate(char x, int op1, float op2) {
  switch (x) {
  case '+':
    return op1 + op2;
  case '-':
    return op1 - op2;
  case '*':
    return op1 * op2;
  case '/':
    return op1 / op2;
    
  }
}

int main() {
  STACK s;
  init(&s);
  STACK sprefix;
  init(&sprefix);

  char infix[20];
  
 
  char prefix[20];
  char i;
  float op1, op2;
  int result;
  int lengthOfInfix;

  scanf("%d %s", &lengthOfInfix, infix);
  reverse(infix);
  printf("%s\n",infix);
  infixToPrefix(infix, prefix, &s);
  reverse(prefix);

  int lengthOfPrefix = lengthS(prefix);

  for (int i = lengthOfPrefix; i >= 0; i--) {
    if (isdigit(prefix[i])) {
      push(&sprefix, prefix[i] - 48);
    } else {
      op1 = pop(&sprefix);
      op2 = pop(&sprefix);
      result = evaluate(prefix[i], op1, op2);
      push(&sprefix, result);
    }
  }
  printf("%s %d\n", prefix, result);

}
