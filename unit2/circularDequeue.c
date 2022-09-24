//  Functions to be implemented
//  1. create queue (allocate memory for queue array using DMA)
//  2. init queue( front rear set to -1)
//  3. insert from rear ( consider insertion in empty and non empty queue)
//  4.insert from front( consider insertion in empty and non empty queue)
//  5. delete from front(consider deletion from empty queue,with one element(reset queue), more than one)
//  6. delete from rear(consider deletion from empty queue,with one element(reset queue), more than one)
//  7. display queue
//  8.destroy queue(release dynamically allocated memory
//  Additional functions
//  9. isempty()//   return( check for front==-1)
//  10. isfull()//  return(check for( front+1)%size==rear))

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int front =-1; int rear = -1;
int *arr;
int size;
void insertFront(int element){
    if ((front==0 && rear == size - 1) || (front == rear+1)) {
        printf("queue full!");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        arr[front] = element;
    }
    else if (front==0) {
        front = size-1;
        arr[front] = element;
    }
    else {
        front --;
        arr[front] = element;
    }
        
}

void insertRear(int element){
    if ((front == 0 && rear == size - 1) || (front == rear+1)) {
        printf("queue full!");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        arr[rear] = element;
    }
    else if (rear == size-1) {
        rear = 0;
        arr[rear] = element;
    }
    else {
        rear++;
        arr[rear]= element;
    }
}

void deleteFront(){
    if (front==-1 && rear==-1) {
        printf("empty queue!\n");
    }
    else if(front==rear){
        printf("deleted element is %d\n",arr[front]);
        front = rear = -1;
    }
    else if(front==size - 1){
        printf("deleted element is %d\n",arr[front]);
        front = 0;
    }
    else {
        printf("deleted element is %d\n",arr[front]);
        front ++;
    }   
}

void deleteRear(){
    if (front==-1 && rear==-1) {
        printf("empty queue!\n");
    }
    else if(front==rear){
        printf("deleted element is %d\n",arr[rear]);
        rear = front = -1;
    }
    else if(rear == 0){
        printf("deleted element is %d\n",arr[rear]);
        rear = size-1;
    }
    else {
        printf("deleted element is %d\n",arr[rear]);
        rear --;
    }
}

        

void display(){
    int i = front;
    
    while (i!=rear) {
        printf("%d\n",arr[i]);
        i = (i+1)%size;
    }
    printf("%d\n",arr[i]);

}

void destroy(){
    free(arr);
    printf("deleted queue\n");
}
    
int main(){
    
    printf("enter the size of the array: ");
    scanf("%d",&size);
    arr = (int *)malloc(sizeof(size));
    insertFront(20);
    insertFront(10);
    insertRear(30);
    insertRear(40);
    deleteRear();
    deleteFront();
    display();
    destroy();
    
    
}