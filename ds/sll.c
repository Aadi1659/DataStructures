#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    
    struct node *link;
}NODE;

typedef struct listlink{
    NODE *head;
    int count;
}LLINK;

void init(LLINK *ptr){
    ptr->head = NULL;
    ptr->count = 0;
}

NODE *getnode(int element){
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = element;
    temp->link = NULL;
    return temp;
}

void display(LLINK *ptr){
    NODE *current=ptr->head;
    if (ptr->head==NULL) {
        printf("List empty cannot display anything\n");
        return;
    }
    while (current!=NULL) {
        printf("%d\n",current->data);
        current = current->link;
    }
}

void insertFront(LLINK *ptr,int element){
    NODE *newnode;
    newnode = getnode(element);
    if (ptr->head == NULL) {
        ptr->head = newnode;
    }
    else {
        newnode->link = ptr->head;
        ptr->head = newnode;
    }
    ptr->count++;
}

void insertEnd(LLINK *ptr,int element){
    NODE *newnode,*aux=ptr->head;
    newnode = getnode(element);
    if (ptr->head==NULL) {
        ptr->head = newnode;
    }
    else {
        while (aux->link!=NULL) {
            aux = aux->link;
        }
        aux->link = newnode;
    }
    ptr->count++;
}

void deleteFront(LLINK *ptr){
    NODE *temp;
    if (ptr->head==NULL) {
        printf("NOTHING TO DELETE LIST EMPTY\n");
    }
    else {
        temp = ptr->head;
        ptr->head = ptr->head->link;
        printf("The deleted node is %d\n",temp->data);
        free(temp);
    }
}

void deleteEnd(LLINK *ptr){
    NODE *temp,*previous=NULL;
    if (ptr->head==NULL) {
        printf("List empty cannot delete\n");

    }
    else {
        temp = ptr->head;
        while (temp->link!=NULL) {
            previous = temp;
            temp = temp->link;
        }
        if (previous==NULL) {
           printf("The deleted node is %d\n",temp->data);
            free(temp); 
            ptr->head = NULL;
        }
        else {
            previous->link = NULL;
            printf("The deleted node is %d\n",temp->data);
            free(temp);
        }
        
    }
}

void alternateDelete(LLINK *ptr){
    NODE *current,*previous,*temp;
    if (ptr->head==NULL) {
        printf("Nothing to delete list empty\n");
    }
    
    previous = ptr->head;
    current = ptr->head->link;
    while (previous!=NULL && current!=NULL) {
        previous->link = current->link;
        printf("deleted node is %d\n",current->data);
        previous = previous->link;
        free(current);
        if (previous!=NULL) {
            current = previous->link;
        }
    }

}

void destroy(LLINK *ptr){
    NODE *temp;
    if (ptr->head==NULL) {
        printf("Nothing to delete\n");
    }
    else {
        while (ptr->head!=NULL) {
            temp = ptr->head;
            printf("Deleted node is %d\n",temp->data);
            ptr->head = ptr->head->link;
            free(temp);
        }
    }
}

void insertSpecified(LLINK *ptr,int position,int element){
    NODE *newnode,*current = ptr->head,*previous = NULL;
    int count = 1;
    newnode = getnode(element);
    if (position>ptr->count+1) {
        printf("Invalid position...");
    }
    else {
        if (position==1) {
            insertFront(ptr,element);
        }
        else if(position==ptr->count+1) {
            insertEnd(ptr,element);
        }
        else {
            while (count!=position && current->link!=NULL) {
                previous = current;
                current = current->link;
                count ++;
            }
            newnode->link = current;
            previous->link = newnode;
        }
        ptr->count++;
    }

    }


int search(LLINK *ptr,int element){
    NODE *current = ptr->head;
    int position = 1;
    int found = 0;
    if (current==NULL) {
        printf("List is empty and cannot be searched\n");
    }
    else {
        while (current!=NULL) {
            if (current->data==element) {
                found = 1;
                break;
            }
            else {
                found = 0;
                current = current->link;
                position ++;
            }
        }
        if (found==1) {
            return position;
        }
        else {
            return false;
        }
    }
}
int main(){
    LLINK l1;
    init(&l1);
    insertEnd(&l1, 10);
    insertEnd(&l1, 20);
    insertSpecified(&l1,2, 30);
    
    // deleteEnd(&l1);
    
    // destroy(&l1);
    int answer = search(&l1,30);
    if (answer==false) {
        printf("could not find element. please enter valid element.\n");
    }
    else {
        printf("The element is at postition %d\n",answer);
    }
    display(&l1);


}
