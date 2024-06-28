#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push (struct stack *ptr, int num){
    if (isFull(ptr)){
        printf("Stack Overflow");
    }
    ptr->top ++;
    ptr->arr[ptr->top] = num;
}

void top(struct stack *ptr){
    printf("Top is %d\n", ptr->arr[ptr->top]);
}

void bottom(struct stack *ptr){
    printf("Bottom is %d", ptr->arr[0]);
}

void pop (struct stack *ptr){
    if (isEmpty(ptr)){
        printf("Stack Underflow");
    }
    int val = ptr->arr[ptr->top];
    ptr->top --;
    printf("Popped %d\n", val); 
}

void peek(struct stack *ptr, int i){
    if((ptr->top-i+1) == 0){
        printf("Invalid input");
    }
    printf("Element at %d is %d\n", i, ptr->arr[ptr->top -i +1]);
}

void print(struct stack *ptr){
    for (int i=0; i<= (ptr->top); i++){
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    (*s).size = 10;
    s->top = -1;
    s->arr = (int *)malloc((s->size)*sizeof(int));

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);

    print(s);
    pop(s);
    print(s);
    peek(s,2);
    top(s);
    bottom(s);
}