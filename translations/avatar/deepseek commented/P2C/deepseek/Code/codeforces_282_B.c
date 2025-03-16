#include <stdio.h>
#include <stdlib.h>

int main() {
    int firstline, total = 0;
    char memory[500];
    int x;

    scanf("%d", &firstline);  // Read the first line of input, which determines the number of iterations

    for (x = 0; x < firstline; x++) {
        int A, G;
        scanf("%d %d", &A, &G);  // Read two integers from a single line of input
        if (total + A <= 500) {  // Check if adding A to total would not exceed 500
            total += A;  // Add A to total
            memory[x] = 'A';  // Append "A" to memory
        } else {
            total -= G;  // Subtract G from total
            memory[x] = 'G';  // Append "G" to memory
        }
    }

    memory[x] = '\0';  // Null-terminate the string

    printf("%s\n", memory);  // Print the memory array as a string

    return 0;
}
