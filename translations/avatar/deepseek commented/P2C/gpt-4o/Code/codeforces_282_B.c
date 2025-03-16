#include <stdio.h>

int main() {
    int firstline;  // Variable to store the number of iterations
    scanf("%d", &firstline);  // Read the first line of input
    int total = 0;  // Initialize a variable to keep track of the total sum
    char memory[100];  // Initialize an array to store the decisions
    int index = 0;  // Index for the memory array

    // Loop through the range of firstline
    for (int x = 0; x < firstline; x++) {
        int A, G;  // Variables to store the two integers
        scanf("%d %d", &A, &G);  // Read two integers from a single line of input
        if (total + A <= 500) {  // Check if adding A to total would not exceed 500
            total += A;  // Add A to total
            memory[index++] = 'A';  // Append 'A' to memory
        } else {
            total -= G;  // Subtract G from total
            memory[index++] = 'G';  // Append 'G' to memory
        }
    }

    memory[index] = '\0';  // Null-terminate the string
    printf("%s\n", memory);  // Print the memory array as a string

    return 0;  // Return success
}

// <END-OF-CODE>
