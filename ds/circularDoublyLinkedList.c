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
    NODE *aux=ptr->head;
    if (ptr->head==NULL) {
        printf("Empty list cannot display anything\n");
    }
    else {
        while (aux->rlink!=ptr->head) {
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
        NODE *first=ptr->head;
        NODE *last = ptr->head->llink;
        newnode->rlink = ptr->head;
        newnode->llink = ptr->head->llink;
        last->rlink = newnode;
        first->llink = newnode;
        ptr->head = newnode;
    }
}

void insertRear(CDLINK *ptr,int element){
    NODE *newnode = getnode(element);
    if (ptr->head==NULL)
    {
        newnode->llink = newnode;
        newnode->rlink=newnode;
        ptr->head = newnode;
    }
    else{
        NODE *last = ptr->head->llink;
        newnode->llink = last;
        newnode->rlink = ptr->head;
        last->rlink = newnode;
        ptr->head->llink = newnode;

    }
}

void deleteFront(CDLINK *ptr){
    NODE *aux=ptr->head;
    if (ptr->head==NULL)
    {
        printf("The list is empty cannot delete\n");
    }
    else if (aux->rlink==ptr->head && aux->llink==ptr->head)
    {
        printf("Deleted node is %d\n",aux->data);
        ptr->head = NULL;
        free(aux);
    }
    
    else{
        NODE *temp=ptr->head;
        NODE *second = ptr->head->rlink;
        NODE *last = ptr->head->llink;
        last->rlink=second;
        second->llink = last;
        ptr->head = second;
        printf("The deleted node is %d\n",temp->data);
        free(temp);
    }
}

void deleteRear(CDLINK *ptr){
    NODE *aux=ptr->head;
    if (ptr->head==NULL)
    {
        printf("The list is empty cannot delete\n");
    }
    else if (aux->rlink==ptr->head && aux->llink==ptr->head)
    {
        printf("Deleted node is %d\n",aux->data);
        ptr->head = NULL;
        free(aux);
    }
    else{
        NODE *last = ptr->head->llink;
        NODE *secondLast = last->llink;
        secondLast->rlink = ptr->head;
        ptr->head->llink = secondLast;
        printf("The deleted node is %d\n",last->data);
        free(last);
    }
}
    
    

int main(){
    CDLINK cd1;
    init(&cd1);
    insertFront(&cd1,10);
    insertFront(&cd1,20);
    insertFront(&cd1,30);
    insertRear(&cd1,40);
    deleteFront(&cd1);
    deleteRear(&cd1);

    display(&cd1);
    

}
