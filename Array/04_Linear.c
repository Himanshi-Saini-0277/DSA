#include <stdio.h>

void search(int arr[], int size, int element){
    for (int i=0; i< size; i++){
        if (arr[i] == element){
            printf("Found at index %d", i);
        }
    }
}

int main(){
    int arr[] = {2,6,9,4,7};
    int size = 5;
    search(arr, size, 9);
}