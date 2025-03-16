#include <stdio.h>

int main() {
    // Read the first line of input which indicates the number of iterations
    int firstline;
    scanf("%d", &firstline);

    // Initialize total to keep track of the accumulated value
    int total = 0;

    // Create an array to store the memory of actions taken
    char memory[firstline + 1]; // +1 for null terminator
    int index = 0;

    // Loop through the range defined by firstline
    for (int x = 0; x < firstline; x++) {
        // Read two integers A and G from input, separated by space
        int A, G;
        scanf("%d %d", &A, &G);

        // Check if adding A to total does not exceed the limit of 500
        if (total + A <= 500) {
            // If within limit, add A to total
            total += A;
            // Record the action "A" in memory
            memory[index++] = 'A';
        } else {
            // If limit exceeded, subtract G from total
            total -= G;
            // Record the action "G" in memory
            memory[index++] = 'G';
        }
    }

    // Null-terminate the string
    memory[index] = '\0';

    // Print the sequence of actions taken as a single string
    printf("%s\n", memory);

    return 0;
}

// <END-OF-CODE>
