#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued %d\n", val);
    }
}

void dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    printf("Dequeued %d\n", a);
}

void print(struct queue *q){
    int i = (q->f+1)%q->size;
    printf("Queue is: ");
    while(i != (q->r+1)%q->size){
        printf("%d ",q->arr[i]);
        i = (i+1)%q->size;
    }
    printf("\n");
}

int main(){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 4;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size *sizeof(int));

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    print(q);

    dequeue(q);

    enqueue(q, 4);
    print(q);

    if (isFull(q)){
        printf("Queue is full");
    }
    if (isEmpty(q)){
        printf("Queue is empty");
    }
}