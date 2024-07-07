#include <stdio.h>

void print(int* arr, int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int *arr, int n, int max){
    int c[n];
    int b[max+1];
    int i,j;

    for(i=0; i<= max; i++){
        b[i] = 0;
    }

    for(j=0; j<n; j++){
        b[arr[j]] = b[arr[j]] +1;
    }

    for (i=1; i<= max; i++){
        b[i] = b[i] +b[i-1];
    }

    for(j=n-1; j>=0; j--){
        c[b[arr[j]]-1] = arr[j];
        b[arr[j]] = b[arr[j]] -1;
    }

    for(i=0; i<n; i++){
        arr[i] = c[i];
    }
}

int main(){
    int arr[]= {3,6,9,2,4,8};
    int n = sizeof(arr)/ sizeof(arr[0]);

    print(arr, 6);
    sort(arr, n, 9);
    print(arr,6);
}