#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int data){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){
    struct node *p = create(2);
    struct node *p1 = create(3);
    struct node *p2 = create(4);
    
    p->left = p1;
    p->right = p2;

    return 0;
}