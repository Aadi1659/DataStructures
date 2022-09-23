#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int item;
  struct node *link;
} NODE;

typedef struct stack {
  NODE *top;

} STACK;

void init(STACK *ptr) { ptr->top = NULL; }

NODE *getnode(int element) {
  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  temp->item = element;
  temp->link = NULL;
  return temp;
}

void push(STACK *ptr, int element) {
  NODE *newnode = getnode(element);
  if (ptr->top == NULL) {
    ptr->top = newnode;
  } else {
    newnode->link = ptr->top;
    ptr->top = newnode;
  }
}

int pop(STACK *ptr) {
  NODE *temp;

  int x;

  if (ptr->top == NULL) {
    printf("Empty stack cannot delete...\n");
    return -1;
  } else {
    temp = ptr->top;
    x = temp->item;
    printf("Deleted item is %d\n", temp->item);
    ptr->top = temp->link;

    free(temp);
    return x;
  }
}

void display(STACK *ptr) {
  NODE *aux;
  if (ptr->top == NULL) {
    printf("Empty stack...\n");
  } else {
    aux = ptr->top;
    while (aux != NULL) {
      printf("%d\n", aux->item);
      aux = aux->link;
    }
  }
}

int peep(STACK *ptr) {
  NODE *temp;
  int x;
  if (ptr->top == NULL) {
    printf("Empty stack cannot return peep value...\n");
    return -1;
  } else {
    temp = ptr->top;
    x = temp->item;
    printf("Topmost item is %d\n", temp->item);
    return x;
  }
}

int main() {
  STACK s1;
  init(&s1);
  int choice, element;
  do {
    printf("Press 1:push()\n2:pop()\n3:peep()\n4:display()\n5:exit()\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the element to insert:\n");
      scanf("%d", &element);
      push(&s1, element);
      break;

    case 2:
      element = pop(&s1);

      break;
    case 3:
      element = peep(&s1);

      break;
    case 4:
      display(&s1);
      break;
    }
  } while (choice != 5);
}