#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list *next;
};

void print (struct list *ptr){
    while (ptr != NULL){
        printf("%d ", (*ptr).data);
        ptr = (*ptr).next;
    }
}

int main(){
    struct list *head;
    struct list *second;
    struct list *third;
    struct list *fourth;

    head = (struct list *)malloc(sizeof(struct list));
    second = (struct list *)malloc(sizeof(struct list));
    third = (struct list *)malloc(sizeof(struct list));
    fourth = (struct list *)malloc(sizeof(struct list));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    print(head);
}