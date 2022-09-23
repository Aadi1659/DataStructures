// creating ordered doubly linked list and merging two of them into a third
// one...

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *rlink;
  struct node *llink;

} NODE;

typedef struct DoubleLinkedList {
  NODE *head;
} DLIST;

void init(DLIST *ptr) { ptr->head = NULL; }

NODE *getnode(int element) {
  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  temp->data = element;
  temp->llink = NULL;
  temp->rlink = NULL;
  return temp;
}

void display(DLIST *ptr) {
  NODE *current = ptr->head;
  if (ptr->head == NULL) {
    printf("EMPTY LIST CANNOT DISPLAY\n");
    return;
  }
  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->rlink;
  }
}

void insertRear(DLIST *ptr, int element) {
  NODE *newnode, *current = ptr->head;
  newnode = getnode(element);
  if (ptr->head == NULL) {
    ptr->head = newnode;
  } else {
    while (current->rlink != NULL) {
      current = current->rlink;
    }
    current->rlink = newnode;
    newnode->llink = current;
  }
}

void sort(DLIST *ptr) {
  NODE *prev = NULL;
  NODE *current = ptr->head;
  int temp;
  if (ptr->head == NULL) {
    printf("list empty cannot sort..\n");
  } else {
    for (current = ptr->head; current != NULL; current = current->rlink) {
      for (prev = current->rlink; prev != NULL; prev = prev->rlink) {
        if (current->data > prev->data) {
          temp = current->data;
          current->data = prev->data;
          prev->data = temp;
        }
      }
    }
  }
}
void takeInput(DLIST *ptr) {
  int input;
  while (input != -1) {
    printf("Enter the list element.Enter -1 to stop the loop..\n");
    scanf("%d", &input);
    if (input != -1) {
      insertRear(ptr, input);
      sort(ptr);
    }
  }
}
void merge(DLIST *ptr1, DLIST *ptr2, DLIST *ptr3) {
  NODE *temp1 = ptr1->head;
  NODE *temp2 = ptr2->head;
  NODE *answer = ptr3->head;
  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->data < temp2->data) {
      insertRear(ptr3, temp1->data);
      temp1 = temp1->rlink;

    } else {
      insertRear(ptr3, temp2->data);
      temp2 = temp2->rlink;
    }
  }
  while (temp1 != NULL) {
    insertRear(ptr3, temp1->data);
    temp1 = temp1->rlink;
  }
  while (temp2 != NULL) {
    insertRear(ptr3, temp2->data);
    temp2 = temp2->rlink;
  }
  printf("Merged list is ...\n");
}

int main() {
  DLIST l1;
  DLIST l2;
  DLIST l3;

  init(&l1);
  init(&l2);
  init(&l3);

  takeInput(&l1);
  printf("First list is \n");
  display(&l1);

  takeInput(&l2);
  printf("Second list is \n");
  display(&l2);

  merge(&l1, &l2, &l3);
  display(&l3);
  printf("Created by Aaditya Dev Sharma..");
}

