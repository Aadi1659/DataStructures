#include <stdio.h>
int sum(int *a,int n);
int main()
{
    int a[5] = {1,2,3,4,5};
    int answer = sum(a,5);
    printf("%d\n",answer);
    return 0;
}
int sum(int *a,int n){
    if (n==0) {
        return a[0];
    }
    else {
        return sum(a,n-1) + a[n];
    }
        
}