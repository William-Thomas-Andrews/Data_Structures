#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000


// Define the Stack struct - fixed capacity
typedef struct {
    int *data;
    int *top;
    int capacity;
    int size;
} Stack;

void init(Stack *stack, int capacity);
int push(Stack *stack, int item);
int pop(Stack *stack);
void look(Stack *stack);


int main () {
    Stack stack;
    init(&stack, MAXSIZE);
    push(&stack, 42);
    return 0;
}

void init(Stack *stack, int capacity) {
    stack->data = (int *)malloc(capacity * sizeof(int));
    stack->top = stack->data;
}

int push(Stack *stack, int item) {
    if (stack->size == MAXSIZE) {
        printf("Error, stack overflow");
        return 0;
    }
    *stack->top = item;
    stack->top++;
    stack->size++;
    return 0;
}

int pop(Stack *stack) {
    if (stack->size == 0) {
        printf("Error, cannot remove item from empty stack");
        return 0;
    }
    int to_return = *stack->top;
    stack->top--;
    stack->size--;
    return to_return;
}

void look(Stack *stack) {
    
}


