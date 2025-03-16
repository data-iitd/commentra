
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for a stack
struct Stack {
    int top;
    int capacity;
    char *array;
};

// Function to create a stack
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char element) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = element;
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to check if two characters form a pair
bool isPair(char p, char q) {
    if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
        return true;
    }
    return false;
}

// Function to solve the problem
void solve(char *x) {
    struct Stack *s = createStack(strlen(x)); // Creating a stack
    int c = 0; // Counter to store the number of pairs

    // Iterating through each character in the input string
    for (int i = 0; i < strlen(x); i++) {
        push(s, x[i]); // Pushing the character onto the stack

        // Popping two characters from the stack and checking for a pair
        while (!isEmpty(s) && s->top > 0) {
            char p = pop(s); // Popping the top character
            char q = pop(s); // Popping the second top character

            // If the popped characters form a pair, increment the counter and continue
            if (isPair(p, q)) {
                c++;
                continue;
            }

            // If the characters don't form a pair, push them back onto the stack and break
            push(s, q);
            push(s, p);
            break;
        }
    }

    // Writing the output to the console
    printf("%d\n", c * 2);
}

// Main function
int main() {
    char x[1000]; // String to store the input string
    scanf("%s", x); // Reading the input string
    solve(x); // Calling the solve function
    return 0;
}

