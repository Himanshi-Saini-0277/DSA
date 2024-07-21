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

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        return 0;
    }
    else{
        q->f ++;
        a = q->arr[q->f];
    }
}

void print(struct queue *q){
    for (int i= q->f+1; i<= q->r; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main(){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size *sizeof(int));

    int node;
    int i = 4;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    printf("%d ", i);
    visited[i] = 1;
    enqueue(q, i);

    while(!isEmpty(q)){
        node = dequeue(q);
        for(int j=0; j<7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
}