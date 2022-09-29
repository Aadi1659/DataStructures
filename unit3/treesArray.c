// updated trees code with the search fxn and completed delete fxn
// code written by Aaditya Dev Sharma PES2UG21CS003

#include <stdio.h>
#define TREESIZE 100
int a[TREESIZE];
void insertTree(int element);
void display();
void inorder(int p);
int search(int p);
void delete (int p);
int main()
{
    int choice, element;
    for (int i = 0; i < TREESIZE; i++)
    {
        a[i] = -1;
    }

    do
    {
        printf("Enter 1:Insert()\n2.Search()\n3.Inorder()\n4.delete()\n5.display()\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            insertTree(element);
            break;
        case 2:
            printf("enter the element you want to search:");
            scanf("%d", &element);
            search(element);
            break;
        case 3:
            printf("Inorder traversal is :");
            inorder(0);
            break;
        case 4:
            printf("enter the element you want to delete\n");
            scanf("%d", &element);
            delete (element);
            break;
        case 5:
            display();
            break;
        }
    } while (choice != 6);
}
void insertTree(int element)
{
    int p = 0;
    if (a[0] == -1)
    {
        a[p] = element;
    }
    else
    {
        while (a[p] != -1 && p < TREESIZE)
        {
            if (element < a[p])
            {
                p = 2 * p + 1;
            }
            else
            {
                p = 2 * p + 2;
            }
        }
        if (p >= TREESIZE)
        {
            printf("Invalid insertion cannot insert!");
        }
        else
        {
            a[p] = element;
        }
    }
}

void display()
{
    for (int i = 0; i < TREESIZE; i++)
    {
        printf("%d\n", a[i]);
    }
}

void inorder(int p)
{

    if (a[p] != -1 && p < TREESIZE)
    {
        inorder(2 * p + 1);
        printf("%d\n", a[p]);
        inorder(2 * p + 2);
    }
}

int search(int p)
{
    int temp = 0;
    while (a[temp] != p && a[temp] != -1)
    {
        if (a[temp] < p)
        {
            temp = 2 * temp + 2;
        }
        else
        {
            temp = 2 * temp + 1;
        }
    }
    printf("found %d at %d position", p, temp);
    return temp;
}

void delete (int p)
{
    int temp = search(p);

    int hold, oneMoreHold;

    if ((a[2 * temp + 1] == -1) && (a[2 * temp + 2] == -1))
    {
        a[temp] = -1;
    }
    else if (a[2 * temp + 1] == -1)
    {
        hold = temp;
        temp = 2 * temp + 2;
        a[hold] = a[temp];
        a[temp] = -1;
    }
    else if (a[2 * temp + 2] == -1)
    {
        hold = temp;
        temp = 2 * temp + 1;
        a[hold] = a[temp];
        a[temp] = -1;
    }
    else
    {

        hold = temp;
        temp = 2 * temp + 2;

        while (a[2 * temp + 1] != -1)
        {
            temp = 2 * temp + 1;
        }

        oneMoreHold = a[temp];
        delete (a[temp]);
        a[hold] = oneMoreHold;
    }
}
