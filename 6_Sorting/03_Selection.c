#include <stdio.h>

void print(int* arr, int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int* arr, int n){
    for (int i=0; i<n; i++){
        int min = i;
        for (int j =i+1; j<n; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

    }
}

int main(){
    int arr[]= {3,6,9,2,4,8};
    print(arr, 6);
    sort(arr, 6);
    print(arr,6);
}