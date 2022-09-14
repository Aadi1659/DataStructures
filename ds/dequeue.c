// A dequeue (double ended queue) is a queue that allows insertion and deletion
// at both ends doubly linked list implementation
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *llink;
  struct node *rlink;
} NODE;

typedef struct dequeue {
  NODE *front, *rear;
} QUEUE;

void init(QUEUE *ptr) { ptr->front = ptr->rear = NULL; }

NODE *getnode(int element) {
  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  temp->data = element;
  temp->llink = temp->rlink = NULL;
  return temp;
}

void insertFront(QUEUE *ptr, int element) {
  NODE *newnode = getnode(element);
  if (ptr->front == NULL) {
    ptr->front = ptr->rear = newnode;
  } else {
    newnode->rlink = ptr->front;
    ptr->front->llink = newnode;
    ptr->front = newnode;
  }
  printf("Added element is %d\n", newnode->data);
}

void insertRear(QUEUE *ptr, int element) {
  NODE *newnode = getnode(element);
  if (ptr->front == NULL) {
    ptr->front = ptr->rear = newnode;
  } else {
    ptr->rear->rlink = newnode;
    newnode->llink = ptr->rear;
    ptr->rear = newnode;
  }
  printf("Added element is %d\n", newnode->data);
}

int deleteFront(QUEUE *ptr) {
  if (ptr->front == NULL) {
    return -1;
  }
  NODE *temp = ptr->front;
  int x = ptr->front->data;
  if (ptr->rear == ptr->front) {
    ptr->front = ptr->rear = NULL;
  } else {
    ptr->front = ptr->front->rlink;
    ptr->front->llink = NULL;
  }
  free(temp);
  return x;
}

int deleteRear(QUEUE *ptr) {
  if (ptr->rear == NULL) {
    return -1;
  }
  NODE *temp = ptr->rear;
  int x = temp->data;
  if (ptr->rear == ptr->front) {
    ptr->front = ptr->rear = NULL;
  } else {
    ptr->rear = ptr->rear->llink;
    ptr->rear->rlink = NULL;
  }
  free(temp);
  return x;
}

void display(QUEUE *ptr) {
  NODE *aux = ptr->front;
  printf("The dequeue is :\n");
  while (aux != NULL) {
    printf("%d\n", aux->data);
    aux = aux->rlink;
  }
}

int main() {
  QUEUE q;
  init(&q);
  int choice, element, deletedFront, deletedRear;
  do {
    printf("Enter "
           "1:insertFront()\n\t2:insertRear()\n\t3:deleteFront()\n\t4:"
           "deleteRear()\n\t5:display()\n\t6:exit():\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("enter the element to be added in the front of the list: ");
      scanf("%d", &element);
      insertFront(&q, element);
      break;
    case 2:
      printf("enter the element to be added in the rear of the list: ");
      scanf("%d", &element);
      insertRear(&q, element);
      break;
    case 3:
      deletedFront = deleteFront(&q);
      if (deletedFront == -1) {
        printf("Dequeue empty cannot delete!\n");
      } else {
        printf("The deleted element is %d\n", deletedFront);
        break;
      }
    case 4:
      deletedRear = deleteRear(&q);
      if (deletedRear == -1) {
        printf("Dequeue empty cannot delete!\n");
      } else {
        printf("The deleted element is %d\n", deletedRear);
        break;
      }
    case 5:
      display(&q);
      break;
    }

  } while (choice != 6);
  printf("\n\tThanks for trying out my code!\t\n");
  printf("\n\tCode written by Aaditya Dev Sharma\t");
}