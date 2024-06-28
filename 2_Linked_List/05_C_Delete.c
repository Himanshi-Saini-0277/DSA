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

struct list *first(struct list *head){
    struct list *ptr = (struct list *)malloc(sizeof(struct list));   
    struct list *p = head;
    while(p->next !=head){
        p = p->next;
    }
    p->next = head->next;
    head = head->next;
    free(ptr);
    return head;
}

struct list *last(struct list *head){
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    struct list *p = head->next;
    struct list *q = head;
    while (p->next != head){
        p = p->next;
        q = q->next;
    }
    q->next = head;
    free(p);
}

struct list *ind(struct list *head, int index){
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    struct list *p = head;
    int i =0;
    while (i != index){
        p = p->next;
        i++;
    }
    struct list *q = p->next;
    p->next = q->next;
    free(q);
}

struct list *after(struct list *head, struct list *prenode){
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    struct list *q = prenode->next;
    prenode->next = q->next;
    free(q);
}

int main(){
    struct list *head;
    struct list *second;
    struct list *third;
    struct list *fourth;
    struct list *fifth;

    head = (struct list *)malloc(sizeof(struct list));
    second = (struct list *)malloc(sizeof(struct list));
    third = (struct list *)malloc(sizeof(struct list));
    fourth = (struct list *)malloc(sizeof(struct list));
    fifth = (struct list *)malloc(sizeof(struct list));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = head;

    print(head);
    head = first(head);
    print(head);
    last(head);
    print(head);
    ind(head, 0);
    print(head);
    after(head, head);
    print(head);
}