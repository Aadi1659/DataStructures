#include <stdio.h>
#define MAXSIZE 5
typedef struct queue{
    
    int items[MAXSIZE];
    int front,rear;
}QUEUE;

void init(QUEUE *p){
    p->front = -1;
    p->rear = -1;
};
    
void qinsert(QUEUE *p,int element){
    if (p->rear==MAXSIZE-1) {
        printf("Queue full condition\n");
        return;
    }
    else {
        p->rear++;
        p->items[p->rear] = element;
        if (p->front==-1) {
            p->front++;
        }
    }
}

void display(QUEUE *p){
    int i,j;
    i  = p->front; j = p->rear;
    while (i!=j) {
        printf("%d\n",p->items[i]);
        i++;
    }
    printf("%d\n",p->items[i]);
}

int delete(QUEUE *p){
    int x;
    if (p->front==-1) {
        return -1;
    }
    x = p->items[p->front];
    if (p->front==p->rear) {
        p->front = -1; p->rear = -1;
    }
    else {
        p->front ++;
    }
    return x;
}

int main(){
    QUEUE q;
    init(&q);
    int choice,ele,deleted;
    do {
        printf("Enter 1:insert()\n2:delete()\n3:display()\n4.exit()\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d",&ele);
                qinsert(&q, ele);
                break;
            case 2:
                deleted = delete(&q);
                if (deleted==-1) {
                    printf("Queue empty\n");
                }
                else {
                    printf("Deleted element is %d\n",deleted);
                    break;
                }
            case 3:
                display(&q);
                break;
        }
    }while (choice!=4);

}