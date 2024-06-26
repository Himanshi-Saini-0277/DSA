#include <stdio.h>

void array(int arr[], int size){
    int sum = 0;
    int product = 1;
    for(int i=0; i< size; i++){
        sum+= arr[i];
        product *= arr[i];
    } 
    printf("Sum is %d\n", sum);
    printf("Product is %d", product);
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    array(arr, 6);
}