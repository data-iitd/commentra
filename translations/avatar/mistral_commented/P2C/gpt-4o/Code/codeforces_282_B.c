#include <stdio.h>

int main() {
    // Take the first line as an input
    int firstline;
    scanf("%d", &firstline);

    // Initialize total and memory array
    int total = 0;
    char memory[500]; // Assuming maximum length of memory will not exceed 500
    int index = 0;

    // Loop through the given number of lines
    for (int x = 0; x < firstline; x++) {
        // Take two integers as input, A and G
        int A, G;
        scanf("%d %d", &A, &G);
        
        // Check if adding A to the total memory usage is within the limit
        if (total + A <= 500) {
            // If yes, add A to the total and append 'A' to the memory array
            total += A;
            memory[index++] = 'A';
        } else {
            // If no, subtract G from the total and append 'G' to the memory array
            total -= G;
            memory[index++] = 'G';
        }
    }

    // Null-terminate the memory string
    memory[index] = '\0';

    // Print the final memory state
    printf("%s\n", memory);

    return 0;
}

// <END-OF-CODE>
