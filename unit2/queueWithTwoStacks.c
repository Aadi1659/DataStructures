#include <stdio.h>
#define MAXSIZE 100
typedef struct {
    int stack1[MAXSIZE];
    int stack2[MAXSIZE];
    int top1;
    int top2;
}QUEUE;

void init(QUEUE *ptr){
    ptr->top1 = ptr->top2 = -1;
}
    
//for push, just increment top and store the value.
//for pop, we retrieve the top position and simply post decrement it.

void enqueue(QUEUE *ptr,int element){
    ptr->stack1[++ptr->top1] = element;
    
}

int pop(QUEUE *ptr){
    int x;
    if(ptr->top1==-1)
        return -1;
    //if both stacks are empty return error
    //if stack 2 is empty, push all the elements from stack 1 to stack 2 to pop from stack 2.
    while(ptr->top1!=0){
        ptr->stack2[++ptr->top2] = ptr->stack1[ptr->top1--];
    }
    int element = ptr->stack1[ptr->top1--];
    while(ptr->top2!=-1){
        ptr->stack1[++ptr->top1] = ptr->stack2[ptr->top2--];
    }
    return element;

}

int topElement(QUEUE *ptr){
    if(ptr->top1==-1)
        return -1;
    return ptr->stack1[0];
}    

int topPosition(QUEUE *ptr){
    return ptr->top1;
}

//stack one is used for inserting elements only, stack two must be used only as an auxillary stack and remain empty at all times.

int validate(QUEUE *q, int pops){
    if(q->top2 != -1 || q->top1 < pops){
        return -1;
    }

    int x = pops, ele = -1;
    while(x > 0 && q->top1 != -1){
        q->stack2[++q->top2] = q->stack1[q->top1--];
        x--;
    }

    if(q->top1 != -1){
        ele = q->stack1[q->top1];
    }

    x = pops;
    while(x > 0 && q->top2 != -1){
        q->stack1[++q->top1] = q->stack2[q->top2--];
        x--;
    }

    return ele;
}

int main(){
    QUEUE ptr;
    init(&ptr);
    int n;
    scanf("%d",&n);
    char c;
    int ele;
    while(n--){
        scanf(" %c",&c);
        switch (c) {
            case 'E':
                scanf("%d",&ele);
                enqueue(&ptr,ele);
                printf("1 ");
                break;
            case 'V':
                scanf("%d",&ele);
                printf("%d ",validate(&ptr,ele));
                break;
            case 'D':
                int x = pop(&ptr);
                printf("%d",x);
                break;
            case 'P':
                ele = topElement(&ptr);
                printf("%d ",ele);
                break;
            
            
        }
        
    }
}