#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list *next;
    struct list *pre;
};

void print_f (struct list *ptr){
    while (ptr != NULL){
        printf("%d ", (*ptr).data);
        ptr = (*ptr).next;
    }
    printf("\n");
}

void print_b (struct list *head){
    struct list *tail = head;
    while (tail->next != NULL) { 
        tail = tail->next; 
    }
    while (tail != head){
        printf("%d ", (*tail).data);
        tail = (*tail).pre;
    }
    printf("%d ", (*tail).data);
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

    head->pre = NULL;
    head->data = 10;
    head->next = second;

    second->pre = head;
    second->data = 20;
    second->next = third;

    third->pre = second;
    third->data = 30;
    third->next = fourth;

    fourth->pre = third;
    fourth->data = 40;
    fourth->next = NULL;

    print_f(head);
    print_b(head);
}