#ifndef STACK_H
#define STACK_H

// Define the Stack struct - fixed capacity
typedef struct {
    char *data;
    char *top;
    int capacity;
    int size;
} Stack;

void init(Stack *stack, int capacity);
int push(Stack *stack, int item);
char pop(Stack *stack);
void look(Stack *stack);

#endif  // STACK_H