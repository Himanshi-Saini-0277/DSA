#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

void isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        printf("Stack is empty");
    }
    printf("Stack is not empty");
}

void isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        printf("Stack is full");
    }
}

int main(){
    struct stack *s;
    (*s).size = 10;
    s->top = -1;
    s->arr = (int *)malloc((s->size)*sizeof(int));

    s->arr[0] = 1;
    s->top ++;
    s->arr[1] = 2;
    s->top ++;

    for (int i=0; i<= (s->top); i++){
        printf("%d ", s->arr[i]);
    }
    printf("\n");

    isEmpty(s);
    isFull(s);
}