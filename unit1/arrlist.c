#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct arrlist{
	int *a;
	int size;
	int used_size;
};

void init(struct arrlist* p);
void alloc_mem(struct arrlist* pal);
int append(struct arrlist* pal, int ele);
void display(struct arrlist* pal);

int main(){
	struct arrlist arlist;
	init(&arlist);
	alloc_mem(&arlist);
	int ele;
	printf("Enter element:");
	scanf("%d", &ele);
	append(&arlist, ele);
	printf("\n%d#", arlist.size);
	printf("\n%d#", arlist.used_size);	
	display(&arlist);
	return 0;
}

void init(struct arrlist* p){
	p->size = 0;
	p->used_size = 1;
}

void alloc_mem(struct arrlist *pal){
	if(pal->size == 0){
		pal->a = (int*)malloc(sizeof(int)*SIZE);
		pal->size = SIZE;
	}
}

int append(struct arrlist *pal, int ele){
	pal->a[pal->used_size++] = ele;
	return 1;
}
	
void display(struct arrlist *pal){
	for(int i = 0; i <= pal->used_size; i++){
		printf("\n*%d", pal->a[i]);
	}
}



