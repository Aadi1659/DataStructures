#include <stdio.h>
#include <sys/types.h>

typedef struct queue {
  int data;
  int pty;
} QUEUE;

void pqinsert(QUEUE *p, int element, int pty, int *count) {
  QUEUE item;
  int j;
  item.data = element;
  item.pty = pty;
  j = *count - 1;
  while (j >= 0 && (p[j].pty > item.pty)) {
    p[j + 1] = p[j];
    j--;
  }
  p[j + 1] = item;
  (*count)++;
}

QUEUE delete (QUEUE *ptr, int *count) {
  QUEUE item;
  if (*count == 0) {
    item.data = 0;
    item.pty = -1;
    return item;
  } else {
    item = ptr[0];
    for (int i = 1; i <= (*count) - 1; i++) {
      ptr[i - 1] = ptr[i];
    }
    (*count)--;
  }
  return item;
}

void display(QUEUE *ptr, int *count) {

  for (int i = 0; i <= (*count) - 1; i++) {
    printf("%d %d\n", ptr[i].data, ptr[i].pty);
  }
}

int main() {
  QUEUE q[10];
  int count = 0;
  int choice, ele, pty;
  QUEUE deleted;
  do {
    printf("Enter 1:insert()\n2:delete()\n3:display()\n4.exit()\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter element to be inserted: ");
      scanf("%d", &ele);
      printf("Enter priority of that element: ");
      scanf("%d", &pty);

      pqinsert(q, ele, pty, &count);
      // printf("count is %d\n",count);
      break;
    case 2:
      deleted = delete (q, &count);
      if (deleted.pty == -1) {
        printf("Queue empty\n");
      } else {
        printf("Deleted element is %d\n with priority %d\n", deleted.data,
               deleted.pty);
        break;
      }
    case 3:
      display(q, &count);
      break;
    }
  } while (choice != 4);
}