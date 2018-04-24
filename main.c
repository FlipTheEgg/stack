#include <stdio.h>
#include "stack.h"

int main() {

    stack_T * myStack = newStack();

    push(myStack, 123);
    push(myStack, 99);
    push(myStack, 4444);
    push(myStack, 5555);
    push(myStack, 6666);
    printf("Size: %d\nCapacity: %d\n", myStack->size, myStack->capacity);
    printf("Top: %d\n", top(myStack));

    printf("popped: %d\n", pop(myStack));
    printf("popped: %d\n", pop(myStack));
    printf("Size: %d\nCapacity: %d\n", myStack->size, myStack->capacity);
    printf("Top: %d\n", top(myStack));

    push(myStack, 4321);

    while (!empty(myStack)) {
        int value;
        value = pop(myStack);
        printf("popped: %d\n", value);
    }
    printf("Size: %d\nCapacity: %d\n", myStack->size, myStack->capacity);

    //Testing top for empty stack. Returns NULL, but is expressed as the value 0.
    printf("Top: %d\n", top(myStack));

    return 0;
}

