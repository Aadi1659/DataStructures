#include <stdio.h>
void tower(int n,char src,char tmp,char dst);
int main()
{
    tower(3,'A','B','C');
    return 0;
}
void tower(int n,char src,char tmp,char dst){
    if (n==1) {
        printf("move disk %d from %c to %c\n",n,src,dst);
        return;
    }
    else {
        tower(n-1, src,dst,tmp);
        printf("move disk %d from %c to %c\n",n,src,dst);
        tower(n-1,tmp,src,dst);
        return;
    }
};