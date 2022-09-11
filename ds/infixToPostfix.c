#include <ctype.h>
#include <stdio.h>
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
    int x = ptr->arr[ptr->top];
    ptr->top--;
    printf("Deleted element is %d\n", x);
    return x;
  }
}

int peep(STACK *ptr) {
  if (ptr->top == -1) {
    printf("Stack is empty cannot delete..\n");
  } else {
    int x = ptr->arr[ptr->top];
    printf("The element at the top of the stack is %d\n", x);
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
  } else if (isalpha(ch)) {
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
  } else if (isalpha(ch)) {
    return 8;
  }
}

void infixToPostfix(char *infix, char *postfix, STACK *ptr) {
  int i = 0, j = 0;
  char ch;
  push(ptr, '#');
  while (infix[i] != '\0') {
    ch = infix[i];
    while (stackPrec(peep(ptr)) > inputPrec(ch)) {
      postfix[j++] = pop(ptr);
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
}

int main() {
  STACK s;
  init(&s);
  char infix[20];
  char postfix[20];
  scanf("%s", infix);
  infixToPostfix(infix, postfix, &s);
  printf("Postfix is %s", postfix);
  printf("Code written by Aaditya Dev Sharma.\n");
}
