#include <stdio.h>

#define MAXSIZE 5

typedef struct queue{
    int items[MAXSIZE];
    int front,rear;
}QUEUE;

void init(QUEUE *ptr){
    ptr->front = -1; ptr->rear = -1;
}

void cqinsert(QUEUE *ptr,int element){
    if ((ptr->rear+1)%MAXSIZE==ptr->front) {
        printf("Queue is full!\n");
        return;
    }
    else {
        ptr->rear = (ptr->rear+1)%MAXSIZE;
        ptr->items[ptr->rear] = element;
        if (ptr->front==-1) {
            ptr->front ++;
        }
    }
}

void display(QUEUE *ptr){
    int i=ptr->front,j=ptr->rear;
    while (i!=j) {
        printf("%d\n",ptr->items[i]);
        i = (i+1)%MAXSIZE;
    }
    printf("%d\n",ptr->items[i]);
}

int delete(QUEUE *ptr){
    int x;
    if (ptr->front==-1) {
        return -1; 
    }
    else {
        x = ptr->items[ptr->front];
        if (ptr->front==ptr->rear) {
            ptr->front = -1;ptr->rear=-1;
        }
        else {
            ptr->front = (ptr->front+1)%MAXSIZE;
        }
        return x;
    }
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
                cqinsert(&q, ele);
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


