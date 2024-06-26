#include <stdio.h>

void insert(int arr[], int element, int index, int size, int capacity){
    for (int i=size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
}

void delete(int arr[], int index, int size){
    for (int i=index; i<size; i++){
        arr[i]= arr[i+1];
    }
}

void print(int arr[], int size){
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[10] = {2,4,6,8,5};
    int size = 5;
    print(arr, size);
    printf("\n");
    size+=1;
    insert(arr, 3, 3, size, 10);
    print(arr, size);
    printf("\n");
    delete(arr, 1, size);
    size-=1;
    print(arr, size);
}