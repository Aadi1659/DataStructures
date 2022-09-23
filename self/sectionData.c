#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int srn;
    char name[100];
    struct node *link;
}NODE;

typedef struct listlink{
    NODE *head;
}LLINK;

void init(LLINK *ptr){
    ptr->head = NULL;
}

NODE *getnode(int srn,char name[]){
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    strcpy(name,temp->name);  
    temp->srn = srn;
    return temp;
}
    
void insertEnd(LLINK *ptr,int element){
    NODE *newnode;
    newnode = ptr->head;
}

