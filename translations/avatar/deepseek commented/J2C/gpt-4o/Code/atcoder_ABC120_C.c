#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

// Function to solve the problem
void solve(char *x) {
    // Initialize a stack to keep track of characters
    char stack[MAX_LENGTH];
    int top = -1; // Stack pointer
    // Initialize a counter to count balanced pairs
    int c = 0;

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(x); i++) {
        // Push the current character onto the stack
        stack[++top] = x[i];

        // While the stack has more than one element, check for balanced pairs
        while (top > 0) {
            // Pop the top two elements from the stack
            char p = stack[top--];
            char q = stack[top--];

            // Check if they form a balanced pair
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                // Increment the counter if a balanced pair is found
                c++;
                continue;
            } else {
                // If not a balanced pair, push the popped elements back onto the stack
                stack[++top] = q;
                stack[++top] = p;
                break;
            }
        }
    }
    // Output the result, which is twice the counter value
    printf("%d\n", c * 2);
}

int main() {
    // Allocate memory for the input string
    char x[MAX_LENGTH];
    // Read the input string
    scanf("%s", x);
    // Call the solve function
    solve(x);
    return 0;
}

// <END-OF-CODE>
