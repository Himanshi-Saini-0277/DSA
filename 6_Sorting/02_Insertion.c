#include <stdio.h>

void print(int* arr, int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int* arr, int n){
    for (int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >=0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[]= {3,6,9,2,4,8};
    print(arr, 6);
    sort(arr, 6);
    print(arr,6);
}