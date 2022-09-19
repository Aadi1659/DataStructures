#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

void create_cirlist(struct node **tail,int element){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->link = NULL;
    if (*tail==NULL)
    {
            newnode->link = newnode;
            *tail = newnode;
    }
    else
    {
        newnode->link = (*tail)->link;
        (*tail)->link  = newnode;
        *tail = newnode;
    }
    
}

int survivor(struct node **tail,int n){
    struct node*cur=(*tail)->link,*prev=NULL;
    
    while ((cur)->link!=(cur))
    {
        for (int i = 0; i < n-1; i++)
        {
            prev = cur;
            cur = cur->link;
        }
        prev->link = cur->link;
        printf("the deleted node is %d\n",cur->data);
        free(cur);
        cur = prev->link;
        
    }
    (*tail) = cur;
    return (*tail)->data;
    
}
    
    
    

int main(){
    int x;
    struct node *tail = NULL;
    create_cirlist(&tail,1);
    create_cirlist(&tail,2);
    create_cirlist(&tail,3);
    create_cirlist(&tail,4);
    create_cirlist(&tail,5);
    x = survivor(&tail,3);
    printf("the survivor is %d\n",x);

}