#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    int data;
    struct node *link;
}NODE;

typedef struct stack{
    NODE *head;
}STACK;

void init(STACK *ptr){
    ptr->head = NULL;
}

NODE * getnode(int element){
    NODE *temp;
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = element;
    temp->link = NULL;
    return temp;
}

void push(STACK *ptr,int element){
    NODE *newnode = getnode(element);
    if(ptr->head==NULL){
        
        ptr->head = newnode;
    }
    else{
        newnode->link = ptr->head;
        ptr->head = newnode;
    }
}

float pop(STACK *ptr){
    if(ptr->head==NULL){
        printf("Stack empty\n");
    }
    else{
        NODE *temp = ptr->head;

        printf("Deleted element is %d\n",temp->data);
        ptr->head = temp->link;
        return temp->data;
        free(temp);
    }
}

void display(STACK *ptr) {
  NODE *aux;
  if (ptr->head == NULL) {
    printf("Empty stack...\n");
  } else {
    aux = ptr->head;
    while (aux != NULL) {
      printf("%d\n", aux->data);
      aux = aux->link;
    }
  }
}

float evaluate(char x,int op1,float op2){
    switch (x)
    {
    case '+':
        return op1+op2;
    case '-':
        return op1-op2;
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    default:
        printf("unknown operator!\n");
    }

}

int main(){
    STACK s1;
    init(&s1);
    char x;
    float op1,op2,result;
    while ((x=getchar())!='\n')
    {
        
        if (isdigit(x))
        {
            push(&s1,x-48);
        }
        else{
            op2 = pop(&s1);
            op1 = pop(&s1);
            result = evaluate(x,op1,op2);
            push(&s1,result);
        }
        
    }
    result = pop(&s1);
    printf("Value is %f\n",result);
    printf("Code written by Aaditya Dev Sharma\n");
}
