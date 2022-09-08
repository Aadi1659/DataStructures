


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACKSIZE 30
typedef struct stack{
    int top;
    int arr[STACKSIZE];
}STACK;

void init(STACK *ptr){
    ptr->top = -1;
}

void push(STACK *ptr,int element){
    if (ptr->top==STACKSIZE-1)
    {
        printf("Stack is full!\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
    
}

int pop(STACK *ptr){
    if(ptr->top==-1){
        printf("Stack is empty cannot delete..\n");
    }
    else{
        int x = ptr->arr[ptr->top];
        ptr->top --;
        printf("Deleted element is %d\n",x);
        return x;
    }
}

int empty(STACK *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}

int full(STACK *ptr){
    if(ptr->top==STACKSIZE-1){
        return 1;
    }
    return 0;
}

float evaluate(char x,int op1,int op2){
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
    STACK s;
    char x;
    int op1,op2,result;
    init(&s);
    while ((x=getchar())!='\n')
    {
        
        if (isdigit(x))
        {
            push(&s,x-48);
        }
        else{
            op2 = pop(&s);
            op1 = pop(&s);
            result = evaluate(x,op1,op2);
            push(&s,result);
        }
        
    }
    //result = pop(&s);
    printf("Value is %d\n",result);
}


        
    

