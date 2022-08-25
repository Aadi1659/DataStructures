#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coefficient;
    int exponent;
    
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

NODE *getnode(int coefficient,int exponent){
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->coefficient = coefficient;
    temp->exponent = exponent;
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
      
        if (current->coefficient>0) {
          printf(" + ");
        }
        else {
          printf("");
        }
        if (current->coefficient!=0) {
        printf("%dx^%d ",current->coefficient,current->exponent);
          
        }
        current = current->link;
    }
}

void insertEnd(LLINK *ptr,int coefficient,int exponent){
    NODE *newnode,*aux=ptr->head;
    newnode = getnode(coefficient,exponent);
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

void getVariablesFirst(LLINK *ptr){
  int variables,coefficient,exponent;
  printf("Enter the number of variables for the first list\n");
  scanf("%d",&variables);
  while (variables>0) {
    printf("Enter the variable number %d with coefficient first and exponent later: ",variables);
    scanf("%d %d",&coefficient,&exponent);
    insertEnd(ptr,coefficient,exponent);
    variables--;
  }
  printf("The polynomial you entered is :");
  display(ptr);
  printf("\nEnded now enter the second polynomial\n");

}

void getVariablesSecond(LLINK *ptr){
  int variables,coefficient,exponent;
  printf("Enter the number of variables for the second list\n");
  scanf("%d",&variables);
  while (variables>0) {
    printf("Enter the variable number %d with coefficient first and exponent later: ",variables);
    scanf("%d %d",&coefficient,&exponent);
    insertEnd(ptr,coefficient,exponent);
    variables--;
  }
  printf("The polynomial you entered is :");
  display(ptr);

  printf("\nOperation ended\n");

}

void add(LLINK *ptr1,LLINK *ptr2,LLINK *ptr3){
  NODE *temp = ptr3->head;
  while (ptr1->head!= NULL && ptr2->head!=NULL) {
    if (ptr1->head->exponent==ptr2->head->exponent) {
      temp->exponent = ptr1->head->exponent;
      temp->coefficient = ptr1->head->coefficient + ptr2->head->coefficient;
      ptr1->head = ptr1->head->link;
      ptr2->head = ptr2->head->link;
    }
    else if (ptr1->head->exponent>ptr2->head->exponent) {
      temp->exponent = ptr1->head->exponent;
      temp->coefficient = ptr1->head->coefficient;
      ptr1->head = ptr1->head->link;
    }
    else {
      temp->exponent = ptr2->head->exponent;
      temp->coefficient = ptr2->head->coefficient;
      ptr2->head = ptr2->head->link;
    }
    
    if (ptr1->head==NULL && ptr2->head==NULL) {
      return;
    }
    temp->link = getnode(0,0);
    temp = temp->link;
  }

  while (ptr1->head!=NULL || ptr2->head!=NULL) {
    if (ptr1->head) {
      temp->exponent = ptr1->head->exponent;
      temp->coefficient = ptr1->head->coefficient;
      ptr1->head = ptr1->head->link;
    }
    if (ptr2->head) {
      temp->exponent = ptr2->head->exponent;
      temp->coefficient = ptr2->head->coefficient;
      ptr2->head = ptr2->head->link;
    }
    if (ptr1->head==NULL && ptr2->head==NULL) {
      return;
    }
    temp->link = getnode(0,0);
    temp = temp->link;
    temp->link = NULL;
  }
  printf("Wohoo the added polynomial is :");
  
}

int main(){
  LLINK poly1,poly2,poly3;
  init(&poly1);
  init(&poly2);
  init(&poly3);
  getVariablesFirst(&poly1);
  getVariablesSecond(&poly2);
  poly3.head = getnode(0,0); 
  
  add(&poly1, &poly2,&poly3);
  display(&poly3); 
  printf("\nCode written by Aaditya Dev Sharma\n");
  

}