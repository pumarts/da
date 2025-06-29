#include <stdio.h>

void merge(int a[],int low,int mid,int high){
    int b[100],i=low,k=low,j=mid+1;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
        }else{
            b[k]=a[j];
            j++;
        }
        k++;
    }                                                  // MERGE SORT
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }
     while(j<=high){
        b[k]=a[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++)
    a[i]=b[i];
}
void mergesort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main() {
    int n, a[100], i;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);                   
    printf("Enter the %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);          
    mergesort(a, 0, n - 1);           
    printf("The sorted elements are:\n");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);        
}
