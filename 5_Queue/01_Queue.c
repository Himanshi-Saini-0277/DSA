#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if(q->r == q->size-1){
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
        q->r++ ;
        q->arr[q->r] = val;
    }
}

void dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
    }
    else{
        q->f ++;
        a = q->arr[q->f];
    }
    printf("Dequeued %d\n", a);
}

void print(struct queue *q){
    for (int i= q->f+1; i<= q->r; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main(){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 20;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size *sizeof(int));

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    print(q);

    dequeue(q);
    print(q);
}