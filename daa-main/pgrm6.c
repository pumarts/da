#include <stdio.h>
#include <limits.h>
int mcm(int a[],int i,int j){
    int k, count;
    int min = INT_MAX;
    if(i == j)
        return 0;
    for(k = i; k < j; k++) {
            count=mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
            if(count<min) min=count;
    }
    return min;                                           // Matrix Chain Multiplication
}
int main() {
    int a[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Minimum number of multiplications is %d\n", mcm(a, 1, n - 1));
}
