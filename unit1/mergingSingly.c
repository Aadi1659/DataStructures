#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *link;
} NODE;

typedef struct listlink {
  NODE *head;
} LLINK;

void init(LLINK *ptr) { ptr->head = NULL; }

NODE *getnode(int element) {
  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  temp->data = element;
  temp->link = NULL;
  return temp;
}
void sort(LLINK *ptr) {
  NODE *prev = NULL;
  NODE *current = ptr->head;
  int temp;
  if (ptr->head == NULL) {
    printf("list empty cannot sort..\n");
  } else {
    for (current = ptr->head; current != NULL; current = current->link) {
      for (prev = current->link; prev != NULL; prev = prev->link) {
        if (current->data > prev->data) {
          temp = current->data;
          current->data = prev->data;
          prev->data = temp;
        }
      }
    }
  }
}
void insertEnd(LLINK *ptr, int element) {
  NODE *newnode = getnode(element);
  if (ptr->head == NULL) {

    ptr->head = newnode;
  } else {
    NODE *aux = ptr->head;
    while (aux->link != NULL) {
      aux = aux->link;
    }
    aux->link = newnode;
  }
}
void display(LLINK *ptr) {
  NODE *aux = ptr->head;
  if (ptr->head == NULL) {
    printf("List empty...");
  } else {
    printf("List is...\n");
    while (aux != NULL) {
      printf("%d\n", aux->data);
      aux = aux->link;
    }
  }
}
void takeInput(LLINK *ptr) {
  int input;
  while (input != -1) {
    printf("Enter the elements of the linked list...press -1 to exit..\n");
    scanf("%d", &input);
    if (input != -1) {
      insertEnd(ptr, input);
      sort(ptr);
    }
  }
}

void merge(LLINK *ptr1, LLINK *ptr2, LLINK *ptr3) {
  NODE *temp2 = ptr2->head;

  NODE *temp1 = ptr1->head;
  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->data < temp2->data) {
      insertEnd(ptr3, temp1->data);
      temp1 = temp1->link;
    } else {
      insertEnd(ptr3, temp2->data);
      temp2 = temp2->link;
    }
  }
  while (temp1 != NULL) {
    insertEnd(ptr3, temp1->data);
    temp1 = temp1->link;
  }
  while (temp2 != NULL) {
    insertEnd(ptr3, temp2->data);
    temp2 = temp2->link;
  }
  printf("The merged list is ...\n");
}

int main() {
  LLINK l1;
  LLINK l2;
  LLINK l3;
  init(&l1);
  init(&l2);
  init(&l3);
  takeInput(&l1);
  display(&l1);
  takeInput(&l2);
  display(&l2);
  merge(&l1, &l2, &l3);
  display(&l3);
}