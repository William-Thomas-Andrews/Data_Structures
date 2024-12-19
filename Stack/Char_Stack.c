#include <stdio.h>
#include <stdlib.h>
#include "Char_Stack.h"

#define MAXSIZE 1000

// // Define the Stack struct - fixed capacity
// typedef struct {
//     int *data;
//     int *top;
//     int capacity;
//     int size;
// } Stack;

// void init(Stack *stack, int capacity);
// int push(Stack *stack, int item);
// int pop(Stack *stack);
// void look(Stack *stack);



void init(Stack *stack, int capacity) {
    stack->data = (char *)malloc(capacity * sizeof(char));
    stack->top = stack->data;
    stack->size = 0;
}

int push(Stack *stack, int item) {
    if (stack->size == MAXSIZE) {
        printf("Error, stack overflow\n");
        return 0;
    }
    if (stack->size == 0) {
        *stack->top = item;
        stack->size++;
        return 0;
    }
    else {
        stack->top++;
        *stack->top = item;
        stack->size++;
        return 0;
    }
}

char pop(Stack *stack) {
    if (stack->size == 0) {
        printf("Error, cannot remove item from empty stack\n");
        return ' ';
    }
    char to_return = *stack->top;
    stack->top--;
    stack->size--;
    return to_return;
}

void look(Stack *stack) {
    printf("%c\n", *stack->top);
}