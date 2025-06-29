#include <stdio.h>
#include <string.h>

int horspool(char T[100],char P[100],int n,int m){
    int ST[256];
    int i,j;

    for(i=0;i<256;i++)
    ST[i]=m;

    for(i=0;i<m-1;i++)
    ST[P[i]]=m-1-i;

    i=m-1;
    while(i<n){
        j=0;
        while(j<m && (P[m-1-j]==T[i-j]))
        j++;
        if(j==m)
            return (i-m+1);                     // 5 Horspool Algorithm
        else 
            i+=ST[T[i]];       
    }
    return -1;
}

int main() {
    char T[100], P[100];
    int i, j, n, m, flag;
    printf("Enter the text string:\n");
    scanf("%s",T);
    printf("Enter the pattern string:\n");
    scanf("%s",P);

    n = strlen(T);
    m = strlen(P);

    flag = horspool(T, P, n, m);
    if(flag == -1)
        printf("String not found!\n");
    else
        printf("String found from index %d.", flag);
}
