#include <stdio.h>
#define TREESIZE 7
int a[TREESIZE];
void insertTree(int element);
void display();
void inorder(int p);
void postorder(int p);
void preorder(int p);
int main(){
    int choice,element;
    for (int i = 0; i<TREESIZE; i++) {
        a[i] = -1;
    }
    
    do {
        printf("Enter 1:Insert()\n2.Display()\n3:Inorder()\n4:Preorder()\n5:Postorder()\n");

        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&element);
                insertTree(element);
                break;
            case 2:
                printf("The tree is as follows: \n");
                display();
                break;
            case 3:
                printf("Inorder traversal is :");
                inorder(0);
                break;
            case 4:
                printf("Preorder traversal is: ");
                preorder(0);
                break;
            case 5:
                printf("Postorder traversal is: ");
                postorder(0);
                break;
        }   
    }while (choice!=6);
    
}
void insertTree(int element){
    int p =0;
    if (a[0]==-1) {
        a[p] = element;
    }
    else {
        while (a[p]!=-1 && p<TREESIZE) {
            if (element<a[p]) {
                p = 2*p + 1;
            }
            else {
                p = 2*p + 2;
            }
        }
        if (p>=TREESIZE) {
            printf("Invalid insertion cannot insert!");
        }
        else {
            a[p] = element;
        }
    }
}

void display(){
    for (int i = 0 ;i<TREESIZE; i++) {
        printf("%d\n",a[i]);    
    }
}

void inorder(int p){
    
    if(a[p]!=-1 && p<TREESIZE){
        inorder(2*p+1);
        printf("%d\n",a[p]);
        inorder(2*p+2);
    }
}

void postorder(int p){
    if (a[p]!=-1 && p<TREESIZE) {
        postorder(2*p+1);
        postorder(2*p+2);
        printf("%d\n",a[p]);
    }
}

void preorder(int p){
    if (a[p]!=-1 && p<TREESIZE) {
        printf("%d\n",a[p]);
        preorder(2*p+1);
        preorder(2*p+2);        
    }
}