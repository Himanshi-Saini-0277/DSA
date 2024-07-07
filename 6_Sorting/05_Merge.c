#include <stdio.h>

void print(int* arr, int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int* arr,int mid,int low,int high){
    int i, j, k, b[high-low+1];
    i = low;
    j = mid+1;
    k = low;

    while(i<=mid && j<=high){
        if (arr[j]< arr[i]){
            b[k] = arr[j];
            k++;
            j++;
        }
        else{
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    while(i<=mid){
        b[k] = arr[i];
        k++;
        i++;
    }
    while(j<=high){
        b[k] = arr[j];
        k++;
        j++;
    }
    for(i=low; i<=high; i++){
        arr[i] = b[i];
    }
}

void merge(int* arr, int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        merge(arr, low, mid);
        merge(arr, mid+1, high);
        sort(arr, mid, low, high);
    }
}

int main(){
    int arr[]= {3,6,9,2,4,8};
    print(arr, 6);
    merge(arr, 0, 6);
    print(arr,6);
}