#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define MAXSIZE 1000


int main () {
    Stack stack;
    init(&stack, MAXSIZE);
    push(&stack, 42);
    // printf("%d\n", *stack.top);
    push(&stack, 10);
    // look(&stack);
    look(&stack);
    // for (int i = 0; i<3; i++) {
    //     // printf("%p", stack.top);
    //     printf("%d\n", *stack.top);
    //     stack.top++;
    // }
    printf("%d\n", pop(&stack));
    look(&stack);
    pop(&stack);
    look(&stack);
    pop(&stack);
    return 0;
}