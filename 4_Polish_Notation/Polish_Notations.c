#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

char isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

char isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push (struct stack *ptr, char num){
    ptr->top ++;
    ptr->arr[ptr->top] = num;
}

char pop (struct stack *ptr) {
    if (!isEmpty(ptr)) {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    return '\0';
}

char prec(char a){
    if (a == '*' || a =='/'){
        return 3;
    }
    else if (a == '+' || a =='-'){
        return 2;
    }
    return 0;
}

char isOperator(char ch){
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-'){
        return 1;
    }
    return 0;
}

char StackTop(struct stack *s){
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

char * postfix(char *infix){
    struct stack *s = (struct stack *)malloc (sizeof(struct stack));
    (*s).size = 20;
    s->top = -1;
    s->arr = (char *) malloc(s->size * sizeof(char));

    char *post = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int j = 0;
    int i = 0;

    while(infix[i] != '\0'){
        if(! isOperator(infix[i])){
            post[j] = infix[i];
            j++; i++;
        }
        else {
            if (prec(infix[i]) > prec(StackTop(s))){
                push (s, infix[i]);
                i++;
            }
            else{
                post[j] = pop(s);
                j++;
            }
        }
    }
    while(! isEmpty(s)){
        post[j] = pop(s);
        j++;
    }
    post[j] = '\0';
    return post;
}

int main(){
    char * exp = "x-y/z-k*d";
    printf("Postfix is %s", postfix(exp));
}