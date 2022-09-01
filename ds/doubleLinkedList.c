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

void sort(DLIST *ptr){
    NODE *prev=NULL;
    NODE *current = ptr->head;
    int temp;
    if (ptr->head==NULL) {
        printf("list empty cannot sort..\n");
    }
    else {
        for (current=ptr->head; current!=NULL;current = current->rlink) {
            for (prev=current->rlink;prev!=NULL;prev=prev->rlink) {
                if (current->data>prev->data) {
                    temp = current->data;
                    current->data = prev->data;
                    prev->data = temp;
                }
            }
        }
    }
        
}

void merge(DLIST *ptr1,DLIST *ptr2){
    NODE *temp = ptr1->head;
    while (temp->rlink!=NULL) {
        temp = temp->rlink;
    }
    temp->rlink = ptr2->head;
    ptr2->head->llink = ptr1->head;
}
void takeInput(DLIST *ptr){
    int input;
    while (input!=-1) {
        printf("Enter the list element.Enter -1 to stop the loop..\n");
        scanf("%d",&input);
        if (input!=-1) {
            insertRear(ptr,input);
            
        }
        
    }
}

int main(){
    DLIST l1;
    init(&l1);
    insertFront(&l1,20);
    insertFront(&l1,30);
    insertRear(&l1, 40);

    // display(&l1);
    //deleteFront(&l1);
    // deleteEnd(&l1);
    display(&l1);
    sort(&l1);
    printf("sorted list is \n");
    display(&l1);
    printf("The second list is ...\n");
    DLIST l2;
    init(&l2);
    insertRear(&l2,40);
    insertRear(&l2,30);
    insertRear(&l2,20);
    insertRear(&l2,10);
    printf("unsorted list is \n");
    display(&l2);
    printf("sorted list is \n");
    sort(&l2);
    display(&l2);
    printf("merged list is ...");
    merge(&l1, &l2);
    sort(&l1);
    display(&l1);
}
