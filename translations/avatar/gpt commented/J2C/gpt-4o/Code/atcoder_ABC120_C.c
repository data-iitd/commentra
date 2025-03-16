#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

typedef struct {
    char *data;
    int top;
} Stack;

void initStack(Stack *s, int size) {
    s->data = (char *)malloc(size * sizeof(char));
    s->top = -1;
}

void push(Stack *s, char c) {
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    return s->data[(s->top)--];
}

int size(Stack *s) {
    return s->top + 1;
}

void freeStack(Stack *s) {
    free(s->data);
}

int main() {
    char x[MAX_LENGTH];
    // Read the input string
    scanf("%s", x);
    
    Stack s;
    initStack(&s, MAX_LENGTH);
    int c = 0; // Counter for pairs of '0' and '1'
    
    // Iterate through each character in the input string
    for (int i = 0; i < strlen(x); i++) {
        // Push the current character onto the stack
        push(&s, x[i]);
        
        // Process the stack while there are at least two characters
        while (size(&s) > 1) {
            char p = pop(&s); // Pop the top character
            char q = pop(&s); // Pop the next character
            
            // Check if the characters form a pair of '0' and '1'
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++; // Increment the counter for valid pairs
                continue; // Continue to check for more pairs
            } else {
                // If not a valid pair, push the characters back onto the stack
                push(&s, q);
                push(&s, p);
                break; // Exit the while loop
            }
        }
    }
    
    // Output the result, which is twice the count of pairs found
    printf("%d\n", c * 2);
    
    // Free the stack memory
    freeStack(&s);
    
    return 0;
}

// <END-OF-CODE>
