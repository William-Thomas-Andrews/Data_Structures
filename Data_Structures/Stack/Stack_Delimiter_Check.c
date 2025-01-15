#include <stdio.h>
#include <stdlib.h>
#include "Char_Stack.h"

#define MAXSIZE 1000


int main () {

    Stack stack;
    init(&stack, MAXSIZE);

    FILE *file;
    char ch;

    // Open the file in read mode
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    char mem = ' ';
    int flag = 0;

    // Read and print each character until EOF
    while ((ch = fgetc(file)) != EOF) {
        int item;
        switch(ch) {
            case '(':
                push(&stack, '(');
                break;
            case ')':
                if (pop(&stack) != '(') {
                    printf("Delimiter error\n");
                    return 0;
                }
                break;
            case '[':
                push(&stack, '[');
                break;
            case ']':
                if (pop(&stack) != '[') {
                    printf("Delimiter error\n");
                    return 0;
                }
                break;
            case '{':
                push(&stack, '{');
                break;
            case '}':
                if (pop(&stack) != '{') {
                    printf("Delimiter error\n");
                    return 0;
                }
                break;
            // case '\"':
            //     push(&stack, '\"');
            //     break;
            // case '\'':
            //     push(&stack, '\'');
            //     break;
            case '/':
                if (fgetc(file) == '*') {
                    push(&stack, '/');
                    push(&stack, '*');
                }
                break;
            case '*':
                if (fgetc(file) == '/') {
                    push(&stack, '*');
                    push(&stack, '/');
                }
                break;
            default:
                break;
        }
        putchar(ch);  // Print the character
    }
    // while (stack.size != 0) {
    //     pop(&stack);
    // }
    // if

    // Close the file
    fclose(file);

    return 0;
}