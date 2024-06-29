#include <stdio.h>
#include <stdlib.h>

struct queue{
    struct queue *next;
    int data;
};

int isEmpty(struct queue *f, struct queue *r){
    return (f == NULL && r == NULL);
}

void enqueue(struct queue **f, struct queue **r, int val){
    struct queue *n = (struct queue*)malloc(sizeof (struct queue));
    if(n == NULL){
        printf("Queue Overflow");
    }
    else{
        n->data = val;
        n->next = NULL;

        if (isEmpty(*f,*r)){
            *f=*r=n;
        }
        else{
            (*r)->next = n;
            *r=n;
        }
    }
}

void dequeue(struct queue **f, struct queue **r){
    int a = -1;
    struct queue *n = *f;
    if(isEmpty(*f,*r)){
        printf("Queue Underflow\n");
    }
    else{
        *f = (*f)->next;
         if (*f == NULL) {
            *r = NULL;
        }
        a = n->data;
        free (n);
    }
    printf("Dequeued %d\n", a);
}

void print(struct queue *n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main(){
    struct queue *f = NULL;
    struct queue *r = NULL;

    enqueue(&f,&r, 1);
    enqueue(&f,&r, 2);
    enqueue(&f,&r, 3);
    enqueue(&f,&r, 4);
    print(f);

    dequeue(&f,&r);
    print(f);

    if (isEmpty(f, r)){
        printf("Queue is empty");
    }
}