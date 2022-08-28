#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *rlink;
    struct node *llink;
}NODE;

typedef struct circularDoublyLinkedList{
    NODE *head;
}CDLINK;

void init(CDLINK *ptr){
    ptr->head =NULL;   
}

NODE * getnode(int element){
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = element;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

void display(CDLINK *ptr){
    NODE *aux;
    if (ptr->head==NULL) {
        printf("Empty list cannot display anything\n");
    }
    else {
        while (aux->rlink!=aux) {
            printf("%d\n",aux->data);
            aux = aux->rlink;
        }
        printf("%d\n",aux->data);
    }
}

void insertFront(CDLINK *ptr,int element){
    NODE *newnode;
    newnode = getnode(element);
    if (ptr->head==NULL) {
        newnode->rlink = newnode;
        newnode->llink = newnode;
        ptr->head = newnode;
    }
    else {
     
        newnode->rlink = ptr->head;
        newnode->llink = ptr->head->llink;
        ptr->head = newnode;
    }
}

int main(){
    CDLINK cd1;
    init(&cd1);
    insertFront(&cd1,10);
    insertFront(&cd1,20);
    insertFront(&cd1,30);


    display(&cd1);
}