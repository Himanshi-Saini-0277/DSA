#include <stdio.h>
#include <stdlib.h>

struct array{
    int total_len;
    int used_len;
    int *ptr;
};

void create(struct array *a, int tlen, int ulen){
    (*a).total_len = tlen;
    (*a).used_len = ulen;
    (*a).ptr = (int *)malloc(tlen * sizeof(int));
}

void set(struct array *a){
    int n;
    for (int i=0; i< ((*a).used_len); i++){
        printf("Enter element %d: ",i);
        scanf("%d", &n);
        ((*a).ptr)[i] = n;
    }
}

void show(struct array *a){
    for (int i=0; i<((*a).used_len); i++){
        printf("%d ", (*a).ptr[i]);
    }
}

int main(){
    struct array marks;
    create(&marks, 10, 5);
    set (&marks);
    show(&marks);
}