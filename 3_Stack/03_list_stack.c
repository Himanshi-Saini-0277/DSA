#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
struct stack *top = NULL;

int isEmpty(struct stack *top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

int isFull(){
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    if(ptr == NULL){
        return 1;
    }
    return 0;
}

struct stack * push (struct stack *top, int x){
    if (isFull(top)){
        printf("Stack overflow");
    }
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = x;
    ptr->next = top;
    top = ptr;
    return top;
}

void pop (struct stack *ptr){
    if (isEmpty(ptr)){
        printf("Stack underflow");
    }
    struct stack *p = ptr;
    top = ptr->next;
    int x = p->data;
    free(p);
}

void peek (int num){
    struct stack *ptr = top;
    for (int i =0; (i<num-1 && ptr->next != NULL); i++){
        ptr = ptr->next;
    }
    printf("Element at %d is %d\n", num, ptr->data);
}

void upper(){
    printf("Top is %d\n", top->data);
}

void bottom(){
    struct stack *ptr = top;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    printf("Bottom is %d", ptr->data);
}

void print (struct stack *ptr){
    while (ptr != NULL){
        printf("%d -> ", (*ptr).data);
        ptr = (*ptr).next;
    }
    printf("NULL");
    printf("\n");
}

int main(){
    top = push (top, 1);
    top = push (top, 2);
    top = push (top, 3);
    top = push (top, 4);
    top = push (top, 5);
    print(top);
    pop (top);
    print(top);
    peek(2);
    upper();
    bottom();
}