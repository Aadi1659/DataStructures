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

void insertFront(DLIST *ptr,int element){
    NODE *newnode;
    newnode = getnode(element);
    if (ptr->head==NULL) {
        ptr->head = newnode;
    }
    else {
        ptr->head->llink = newnode;
        newnode->rlink = ptr->head;
        ptr->head = newnode;
    }
}
void insertRear(DLIST *ptr,int element){
    NODE *newnode,*current=ptr->head;
    newnode = getnode(element);
    if (ptr->head==NULL) {
        ptr->head = newnode;
    }
    else {
        while (current->rlink!=NULL) {
            current = current->rlink;
        }
        current->rlink = newnode;
        newnode->llink = current;

    }
}
void deleteFront(DLIST *ptr){
    NODE *temp;
    if (ptr->head==NULL) {
        printf("NOTHING TO DELETE. LIST EMPTY\n");
        return;
    }
    temp = ptr->head;
    ptr->head->llink = NULL;
    ptr->head = ptr->head->rlink;
    printf("Freed node is %d\n",temp->data);
    free(temp);


}

void deleteEnd(DLIST *ptr){
    NODE *current=ptr->head,*previous;
    if (ptr->head==NULL) {
        printf("LIST IS EMPTY CANNOT DELETE\n");
        return;
    }
    else {
        while (current->rlink!=NULL) {
            current = current->rlink;
        }
        if (current->llink==NULL) {
            printf("The freed up node is %d\n",current->data);
            ptr->head=NULL;
            free(current);
        }
        else {
            previous = current->llink;
            previous->rlink=NULL;
            printf("The freed up node is %d\n",current->data);
            free(current);
        }
        

        
    }
    

}

int main(){
    DLIST l1;
    init(&l1);
    insertFront(&l1,20);
    insertFront(&l1,30);
    insertRear(&l1, 40);

    display(&l1);
    //deleteFront(&l1);
    deleteEnd(&l1);
    display(&l1);
}