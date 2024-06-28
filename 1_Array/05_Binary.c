#include <stdio.h>

void sort(int arr[], int size){
    for(int i=0; i< size; i++){
        for (int j=0; j< size; j++){
            if (arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            }
        }
    }
}

void print(int arr[], int size){
    for(int i=0; i< size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void search(int arr[], int size, int element){
    int min = 0;
    int max = size-1;
    if (element != arr[min] & element != arr[max]){
        int mid = (min + max)/2;
        if (element = arr[mid]){
            printf("Found at index %d", mid);
        }
        else if (element < arr[max]){
            max = mid;
            mid = (min + max)/2;
        }
        else if (element > arr[min]){
            min = mid;
            mid = (min + max)/2;
        }
    }
}

int main(){
    int arr[] = {1,3,5,7,9,2,4,6,8};
    int size = 9;
    sort (arr, size);
    print(arr, size);
    search(arr, size, 5);
}