#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int size;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->size = 0;
    stack->data = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(Stack* stack, char item) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->data = (char*)realloc(stack->data, stack->capacity * sizeof(char));
    }
    stack->data[stack->size++] = item;
}

char pop(Stack* stack) {
    if (stack->size == 0) {
        return '\0';
    }
    return stack->data[--stack->size];
}

int main() {
    // Set up input and output streams
    char x[100001];
    scanf("%s", x);
    Stack* s = createStack(strlen(x));
    int c = 0; // Counter for pairs of '0' and '1'

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(x); i++) {
        // Push the current character onto the stack
        push(s, x[i]);

        // Process the stack while there are at least two characters
        while (s->size > 1) {
            char p = pop(s); // Pop the top character
            char q = pop(s); // Pop the next character

            // Check if the characters form a pair of '0' and '1'
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++; // Increment the counter for valid pairs
                continue; // Continue to check for more pairs
            } else {
                // If not a valid pair, push the characters back onto the stack
                push(s, q);
                push(s, p);
                break; // Exit the while loop
            }
        }
    }
    // Output the result, which is twice the count of pairs found
    printf("%d\n", c * 2);

    // Free the allocated memory
    free(s->data);
    free(s);

    return 0;
}
