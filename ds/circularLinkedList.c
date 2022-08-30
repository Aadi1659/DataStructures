#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

typedef struct node {
  int data;
  struct node *tail;
} NODE;

typedef struct listlink {
  NODE *head;
} CLINK;

void init(CLINK *ptr) { ptr->head = NULL; }

void display(CLINK *ptr) {
  if (ptr->head == NULL) {
    printf("Empty list\n");
  } else {
  NODE *aux = ptr->head->tail;

    if (ptr->head == ptr->head->tail) {
      printf("%d\n", ptr->head->data);
    return;
    } else {
      while (aux->tail != ptr->head->tail) {
        printf("%d\n", aux->data);
        aux = aux->tail;
      }
      printf("%d\n", aux->data);
    }
  }
}

NODE *getNode(int element) {
  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  temp->data = element;
  temp->tail = NULL;
  return temp;
}

void insertFront(CLINK *ptr, int element) {
  NODE *newnode;
  newnode = getNode(element);
  if (ptr->head == NULL) {
    newnode->tail = newnode;
    ptr->head = newnode;
  } else {
    newnode->tail = ptr->head->tail->tail;
    ptr->head->tail->tail = newnode;
    ptr->head = newnode;
  }
}

void insertRear(CLINK *ptr, int element) {
  NODE *newnode = getNode(element);
  if (ptr->head == NULL) {
    newnode->tail = newnode;
    ptr->head = newnode;
  } else {
    newnode->tail = ptr->head->tail->tail;
    ptr->head->tail->tail = newnode;
    ptr->head = newnode;
  }
}

void deleteFront(CLINK *ptr) {
  NODE *temp = ptr->head;
  if (ptr->head == NULL) {
    printf("Cannot delete list empty\n");
  } else {
    if (ptr->head->tail == ptr->head) {
      printf("Deleted node is %d\n", temp->data);
      ptr->head = NULL;
      free(temp);
    } else {
      temp = ptr->head->tail;
      printf("Deleted node is %d\n", temp->data);
      ptr->head->tail = temp->tail;
      free(temp);
    }
  }
}

void deleteRear(CLINK *ptr){
    NODE *prev=ptr->head->tail->tail,*temp = ptr->head->tail,*temp1 = ptr->head;
    if (ptr->head==NULL) {
        printf("Empty list\n");
    }
    else {
        if (ptr->head->tail==ptr->head) {
            printf("Deleted node is %d\n",ptr->head->data);
            ptr->head = NULL;
            free(temp1);
        }
        else {
             while (prev->tail!=ptr->head->tail) {
            prev = prev->tail;
        }
        prev->tail = ptr->head->tail->tail;
        ptr->head = prev;
        printf("Deleted node is %d\n",temp->data);
        
        free(temp);
        }
       
    }
}

int main() {
  CLINK c1;
  init(&c1);
  insertFront(&c1, 10);
  insertFront(&c1, 20);
  insertRear(&c1, 30);
    deleteRear(&c1);
    deleteRear(&c1);

    deleteRear(&c1);


  display(&c1);
}