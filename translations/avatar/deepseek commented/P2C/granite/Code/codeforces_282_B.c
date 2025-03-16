

#include <stdio.h>

int main() {
    int firstline;
    scanf("%d", &firstline);  // Read the first line of input, which determines the number of iterations
    int total = 0;  // Initialize a variable to keep track of the total sum
    char memory[firstline];  // Initialize an array of characters to store the decisions

    // Loop through the range of firstline
    for (int x = 0; x < firstline; x++) {
        int A, G;
        scanf("%d %d", &A, &G);  // Read two integers from a single line of input
        if (total + A <= 500) {  // Check if adding A to total would not exceed 500
            total += A;  // Add A to total
            memory[x] = 'A';  // Assign 'A' to the current index of memory
        } else {
            total -= G;  // Subtract G from total
            memory[x] = 'G';  // Assign 'G' to the current index of memory
        }
    }

    // Print the elements of memory as a string
    for (int x = 0; x < firstline; x++) {
        printf("%c", memory[x]);  // Print the character at the current index of memory
    }

    return 0;
}
