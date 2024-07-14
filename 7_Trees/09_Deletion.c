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

struct node* inOrderPredecessor(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node* delete(struct node* root, int key){
    struct node* pre;
    if(root == NULL){
        return NULL;
    }
    if(root->left ==NULL && root->right == NULL && root->data == key){
        free(root);
        return NULL;
    }
    if(key < root->data){
        root->left = delete(root->left, key);
    }
    else if(key> root->data){
        root->right = delete(root->right, key);
    }
    else{
        pre = inOrderPredecessor(root);
        root->data = pre->data;
        root->left = delete(root->left, pre->data);
    }
    return root;
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
    delete(p, 5);
    inorder(p);

    return 0;
}