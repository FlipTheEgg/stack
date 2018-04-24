// stack.h
/*
Der må ikke ændres i denne header-fil.
*/
typedef struct {
    int capacity;
    int * array;
    int size;
} stack_T;
// HAD to be changed du to the following error:
// Typedef redefinition with different types.
// Googling revealed, that the name stack_t is part of my OS's header (?).

int pop(stack_T * stack_p);
void push(stack_T * stack_p, int value);
int top(stack_T * stack_p);
stack_T * newStack(void);
int empty(stack_T * stack_p);