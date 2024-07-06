#include <stdio.h>

void print(int* arr, int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int* arr, int p, int r){
    int pivot = arr[p];
    int i = p+1;
    int j = r;
    int temp;

    do{
        while (arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if (i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while(i<j);
        
    temp = arr[p];
    arr[p] = arr[j];
    arr[j] = temp;
    return j;
}

void sort(int* arr, int p, int r){
    if (p<r){
        int q = partition(arr, p, r);
        sort(arr, p, q-1);
        sort(arr, q+1, r);
    }
}

int main(){
    int arr[]= {3,6,9,2,4,8};
    print(arr, 6);
    sort(arr, 0, 5);
    print(arr,6);
}