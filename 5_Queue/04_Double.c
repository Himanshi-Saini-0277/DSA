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

void enqueue_f(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }
    else{
        for(int i=q->size-1; i>=q->f; i--){
            q->arr[i+1]= q->arr[i];
        }
        if (q->f == -1){
            q->f++;
            q->arr[q->f] = val;
            q->r++;
        }
        else {
            q->arr[q->f] = val;
            q->r++;
        }
    }
}

void enqueue_r(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }
    else{
        q->r++ ;
        q->arr[q->r] = val;
    }
}

void dequeue_f(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
    }
    else{
        a = q->arr[q->f];
        q->f ++;
    }
    printf("Dequeued %d\n", a);
}

void dequeue_r(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
    }
    else{
        a = q->arr[q->r];
        q->r --;
    }
    printf("Dequeued %d\n", a);
}

void print(struct queue *q){
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");

        for (int i=q->f; i<q->r+1; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size *sizeof(int));

    enqueue_r(q, 3);
    enqueue_r(q, 4);
    enqueue_f(q, 2);
    enqueue_f(q, 1);
    print(q);

    dequeue_f(q);
    dequeue_r(q);
    print(q);

    if (isFull(q)){
        printf("Queue is full");
    }
    if (isEmpty(q)){
        printf("Queue is empty");
    }
}