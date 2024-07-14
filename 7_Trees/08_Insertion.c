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

void insert(struct node* root, int key){
    struct node* prev = NULL;
    while(root != NULL){
        prev = root;
        if(root->data == key){
            printf("Cannot Insert\n");
            return;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = create(key);
    if(prev->data < key){
        prev->right = new;
    }
    else{
        prev->left = new;
    }
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node *p = create(5);
    struct node *p1 = create(3);
    struct node *p2 = create(6);
    struct node *p3 = create(2);
    struct node *p4 = create(4);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    printf("\n");
    insert(p, 1);
    inorder(p);

    return 0;
}