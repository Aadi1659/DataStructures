#include <stdio.h>

int top = -1;
int stk[10];

int isnum(int num) {
  if (num >= 0 && num <= 9) {
    return 1;
  }
  return 0;
}

int getresult(char op, int op1, int op2) {
  switch (op) {
  case '+':
    return (op1 + op2);

  case '-':
    return (op1 - op2);

  case '*':
    return (op1 * op2);

  case '/':
    return (op1 / op2);
  }
}

int evaluate(char postfix[]) {
  char symbol;
  int i = 0, op1, op2, result;
  while (postfix[i] != '\0') {
    symbol = postfix[i];
    if (isnum(symbol - '0')) {
      stk[++top] = symbol - '0';
    } else {
      op2 = stk[top--];
      op1 = stk[top--];
      result = getresult(symbol, op1, op2);
      stk[++top] = result;
    }
    i++;
  }
  return stk[top];
}

int main() {
  char postfix[20];
  int result;
  printf("enter the postfix expression: ");
  scanf("%s", postfix);
  result = evaluate(postfix);
  printf("the value of postfix expression is : %d\n", result);
  return 0;
}