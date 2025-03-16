#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000 // Define a maximum length for the input string

// Function to solve the problem
void solve() {
    char x[MAX_LENGTH]; // Array to store the input string
    char stack[MAX_LENGTH]; // Stack to store characters
    int top = -1; // Stack pointer
    int c = 0; // Counter to store the number of pairs

    // Reading the input string
    scanf("%s", x);

    // Iterating through each character in the input string
    for (int i = 0; i < strlen(x); i++) {
        stack[++top] = x[i]; // Pushing the character onto the stack

        // Popping two characters from the stack and checking for a pair
        while (top > 0) {
            char p = stack[top--]; // Popping the top character
            char q = stack[top--]; // Popping the second top character

            // If the popped characters form a pair, increment the counter and continue
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++;
                continue;
            }

            // If the characters don't form a pair, push them back onto the stack and break
            stack[++top] = q;
            stack[++top] = p;
            break;
        }
    }

    // Writing the output
    printf("%d\n", c * 2);
}

// Main function that starts the program
int main() {
    solve(); // Calling the solve function
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
