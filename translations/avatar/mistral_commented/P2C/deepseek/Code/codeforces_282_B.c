#include <stdio.h>

int main() {
    int firstline, A, G, total = 0;
    char memory[500]; // Assuming the maximum size of memory list is 500
    int memoryIndex = 0;

    // Take the first line as an input
    scanf("%d", &firstline);

    // Loop through the given number of lines
    for (int x = 0; x < firstline; x++) {
        // Take two integers as input, A and G
        scanf("%d %d", &A, &G);

        // Check if adding A to the total memory usage is within the limit
        if (total + A <= 500) {
            // If yes, add A to the total and append 'A' to the memory list
            total += A;
            memory[memoryIndex++] = 'A';
        } else {
            // If no, subtract G from the total and append 'G' to the memory list
            total -= G;
            memory[memoryIndex++] = 'G';
        }
    }

    // Print the final memory state
    memory[memoryIndex] = '\0'; // Null-terminate the string
    printf("%s\n", memory);

    return 0;
}
