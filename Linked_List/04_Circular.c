#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list *next;
};

void print (struct list *head){
    struct list *ptr = head;
    do{
        printf("%d ", (*ptr).data);
        ptr = (*ptr).next;
    }while (ptr != head);
    printf("\n");
}

struct list *first(struct list *head, int data){
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->data = data;
    ptr->next = head;

    struct list *p = head->next;
    while(p->next !=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
}

struct list *last(struct list *head, int data){
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->data = data;
    struct list *p = head;
    while (p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
}

struct list *ind(struct list *head, int data, int index){
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->data = data;
    struct list *p = head;
    int i =0;
    while (i != index){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}

struct list *after(struct list *head, struct list *prenode, int data){
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->data = data;

    ptr->next = prenode->next;
    prenode->next = ptr;
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
    fourth->next = head;

    print(head);
    head = first(head, 0);
    print(head);
    last(head, 50);
    print(head);
    ind(head, 15, 1);
    print(head);
    after(head, second, 25);
    print(head);
}