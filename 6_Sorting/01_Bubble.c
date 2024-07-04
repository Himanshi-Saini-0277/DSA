#include <stdio.h>

void print(int* arr, int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int* arr, int n){
    int temp;
    int isSorted = 0;
    for (int i=0; i<n-1; i++){
        isSorted = 1;
        for(int j=0; j<n-1-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted){
            return;
        }
        printf("Iteration: %d\n", i);
        print(arr, 6);
    }
}

int main(){
    int arr[]= {3,6,9,2,4,8};
    print(arr, 6);
    sort(arr, 6);
}