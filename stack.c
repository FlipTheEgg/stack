// stack.c
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


stack_T *newStack(void){
    stack_T* s = malloc(sizeof(stack_T*));
    s->array = NULL;
    s->capacity = 0;
    s->size = 0;
    return s;
}

int pop(stack_T * stack_p) {
    if (empty(stack_p))
        return NULL;
    int r = top(stack_p);
    stack_p->size--;
    return r;
}

void increaseCapacity(stack_T * stack_p) {
    int oldCapacity = stack_p->capacity;
    int* oldArray = stack_p->array;

    if (stack_p->capacity == 0)
        stack_p->capacity++;
    else
        stack_p-> capacity *= 2;

    int * newArray = malloc(stack_p->capacity * sizeof(int));

    for (int i = 0; i < oldCapacity; i++)
        newArray[i] = oldArray[i];

    stack_p->array = newArray;

    free(oldArray);
}

void push(stack_T * stack_p, int value) {

    if(stack_p->size == stack_p->capacity) {
       increaseCapacity(stack_p);
    }

    stack_p->array[stack_p->size] = value;
    stack_p->size++;
}

int top(stack_T * stack_p) {
    if(empty(stack_p))
        return NULL;
    return(stack_p->array[stack_p->size - 1]);
}

int empty(stack_T * stack_p) {
    if(stack_p->size == 0) return 1;
    return 0;
}
