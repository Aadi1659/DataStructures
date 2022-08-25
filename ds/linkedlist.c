#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *getnode(int ele){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->link = NULL;
	return temp;
}

void display(struct node *front){
	struct node* temp = front;
	while(temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}
	
int main(){
	struct node *node1, *node2, *node3;
	node1 = getnode(10);
	node2 = getnode(20);
	node1->link = node2;
	node3 = getnode(5);
	node3->link = node1;
	display(node3);
	return 0;
}
	