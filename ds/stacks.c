#include <stdio.h>
#define STACKSIZE 5
typedef struct stack{
    int top;
    int items[STACKSIZE];
}STACK;

void init(STACK *ptr){
    ptr->top = -1;
}

void push(STACK *ptr,int element){
    if (ptr->top==STACKSIZE-1) {
        printf("Stack is full cannot push!\n");
    }
    else {
        ptr->top ++;
        ptr->items[ptr->top]=element;
    }
}

int pop(STACK *ptr){
    if (ptr->top==-1) {
        printf("Empty stack cannot delete\n");

    }
    else {
        int x = ptr->items[ptr->top];
        ptr->top -- ;
        printf("Deleted element %d\n",x);
        return x;
    }
}

void display(STACK *ptr){
    if (ptr->top==-1) {
        printf("Empty stack nothing to show..\n");
    }
    else {
        for (int i = ptr->top;i>=0; i--) {
            printf("%d\n",ptr->items[i]);
        }
    }
}

int peep(STACK *ptr){
    if (ptr->top==-1) {
        printf("Empty stack...\n");
    }
    else {
        int x = ptr->items[ptr->top];
        printf("The top most element is %d\n",x);
        return x;

    }
}

int empty(STACK *ptr){
    if (ptr->top==-1) {
        printf("Empty list...\n");
        return 0;
    }
    return 1;
    
}

int overflow(STACK *ptr){
    if (ptr->top==STACKSIZE-1) {
        printf("Stack overflow...\n");
        return 1;
    }
    return 0;
}


int main(){
    STACK *s1;
    init(s1);
    push(s1,10);
    push(s1,20);
    display(s1);
    pop(s1);
    display(s1);
    peep(s1);
    int x = empty(s1);
    printf("%d\n",x);
    int y =overflow(s1);
    printf("%d\n",y);

    

}


