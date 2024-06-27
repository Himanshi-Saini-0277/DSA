#include <stdio.h>
#include <stdlib.h>

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

char push (struct stack *ptr, char num){
    ptr->top ++;
    ptr->arr[ptr->top] = num;
}

char pop (struct stack *ptr){
    char val = ptr->arr[ptr->top];
    ptr->top --;
    return val;
}

int match(char a, char b){
    if (a == '(' && b ==')'){
        return 1;
    }
    if (a == '{' && b =='}'){
        return 1;
    }
    if (a == '[' && b ==']'){
        return 1;
    }
    return 0;
}

int parenthesis(char *exp){
    struct stack *s;
    (*s).size = 20;
    s->top = -1;
    s->arr = (char *)malloc((s->size)*sizeof(char));
    char popped;

    for (int i=0; exp[i] != '\0'; i++){
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if (isEmpty(s)){
                return 0;
            }
            popped = pop(s);
            if (! match(popped, exp[i])){
                return 0;
            }
        }
    }
    if (isEmpty(s)){
        return 1;
    }
    return 0;
}

int main(){
    char * exp = "{8*(9)+[8-6]+9}";
    if (parenthesis(exp)){
        printf("Parenthesis are balanced");
    }
    else {
        printf("Parenthesis are not balanced");
    }
}