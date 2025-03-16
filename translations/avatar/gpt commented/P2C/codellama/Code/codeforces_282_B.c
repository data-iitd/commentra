#include <stdio.h>

int main() {
    // Read the first line of input which indicates the number of iterations
    int firstline;
    scanf("%d", &firstline);

    // Initialize total to keep track of the accumulated value
    int total = 0;

    // Create an empty list to store the memory of actions taken
    char memory[firstline];

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
            memory[x] = 'A';
        } else {
            // If limit exceeded, subtract G from total
            total -= G;
            // Record the action "G" in memory
            memory[x] = 'G';
        }
    }

    // Print the sequence of actions taken as a single string
    for (int x = 0; x < firstline; x++) {
        printf("%c", memory[x]);
    }

    // End with comment "