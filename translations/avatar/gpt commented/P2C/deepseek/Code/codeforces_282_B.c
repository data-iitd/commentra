#include <stdio.h>
#include <stdlib.h>

int main() {
    int firstline, total = 0;
    char memory[500]; // Assuming the maximum length of memory is 500
    int x;
    int A, G;

    // Read the first line which indicates the number of iterations
    scanf("%d", &firstline);

    // Loop through the range defined by firstline
    for (x = 0; x < firstline; x++) {
        // Read two integers A and G from input, separated by space
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
    for (x = 0; x < firstline; x++) {
        printf("%c", memory[x]);
    }
    printf("\n");

    return 0;
}
