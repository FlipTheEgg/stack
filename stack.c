// stack.c
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define KRED  "\x1B[31m"
#define RESET "\033[0m"

stack_T *newStack(void){
    stack_T* s = malloc(sizeof(stack_T*));
    s->array = NULL;
    s->capacity = 0;
    s->size = 0;
    return s;
}

int pop(stack_T * stack_p) {
    if(empty(stack_p)) {
        printf("%sERROR: pop - stack empty%s\n", KRED, RESET);
        return NULL;
    } else {
        int r = top(stack_p);
        stack_p->size--;
        return r;
    }
}

void increaseCapacity(stack_T * stack_p) {
    if (stack_p->capacity == 0)
        stack_p->capacity++;
    else
        stack_p->capacity *= 2;
    stack_p->array = realloc(stack_p->array, stack_p->capacity * sizeof(int));
}

void push(stack_T * stack_p, int value) {
    if(stack_p->size >= stack_p->capacity)
       increaseCapacity(stack_p);
    stack_p->array[stack_p->size] = value;
    stack_p->size++;
}

int top(stack_T * stack_p) {
    if(empty(stack_p)) {
        printf("%sERROR: top - stack empty%s\n", KRED, RESET);
        return NULL;
    }
    return(stack_p->array[stack_p->size - 1]);
}

int empty(stack_T * stack_p) {
    if(stack_p->size <= 0) return 1;
    return 0;
}
