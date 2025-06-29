#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if(a > b)return a;
    else return b;
}
void lcs(char x[100], char y[100], int m, int n) {
    int l[100][100],i,j,len;
    char lc[100];
    for(i=0;i<=m;i++)
        for(j=0;j<=n;j++){
            if(i==0||j==0) 
                l[i][j]=0;
            else if (x[i-1]==y[j-1]) 
                l[i][j]=l[i-1][j-1]+1;
            else 
            l[i][j]=max(l[i-1][j],l[i][j-1]);                // 7 Longest Common Subsequence
        }
    len=l[m][n];
    printf("the lcs length is %d\n",len);
    lc[len]='\0';
    i=m;
    j=n;
    while(i>0 && j>0){
        if(x[i - 1] == y[j - 1]) {
            lc[len-1]=x[i-1];
            len--;
            i--;
            j--;
        }
        else{
            if(l[i-1][j]>l[i][j-1]) i--;
            else j--;
        }
    }
    printf("The LCS is %s\n", lc);    
}

int main() {
    char x[100], y[100];
    int m, n;
    printf("Enter the first string:\n");
    scanf("%s",x);
    printf("Enter the second string:\n");
    scanf("%s",y);
    m = strlen(x);
    n = strlen(y);
    lcs(x, y, m, n);
}
