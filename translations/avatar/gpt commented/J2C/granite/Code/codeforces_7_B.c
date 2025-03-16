
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int t, m;
    scanf("%d %d", &t, &m);

    // Initialize the memory array to keep track of allocated memory
    int memory[m];
    for (int i = 0; i < m; i++) {
        memory[i] = 0;
    }

    // Initialize the allocation index to track the allocation IDs
    int allocIdx = 0;

    // Process each operation based on the number of operations (t)
    for (int j = 0; j < t; j++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "alloc") == 0) {
            int n;
            scanf("%d", &n);
            int len = 0;
            bool canAlloc = false;

            // Check for a contiguous block of free memory of size n
            for (int i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    len++; // Increase length if the current memory is free
                } else {
                    len = 0; // Reset length if the current memory is allocated
                }

                // If a sufficient block is found, mark it as allocatable
                if (len == n) {
                    canAlloc = true;
                    len = i - n + 1; // Calculate the starting index for allocation
                    break;
                }
            }

            // If allocation is possible, allocate memory and print the allocation ID
            if (canAlloc) {
                allocIdx++;
                for (int i = len; i < len + n; i++) {
                    memory[i] = allocIdx; // Mark the allocated memory with the allocation ID
                }
                printf("%d\n", allocIdx); // Output the allocation ID
            } else {
                printf("NULL\n"); // Output NULL if allocation failed
            }
        } else if (strcmp(op, "erase") == 0) {
            int x;
            scanf("%d", &x);

            // Check for illegal erase argument
            if (x <= 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            } else {
                bool hasErased = false;

                // Erase the memory corresponding to the given allocation ID
                for (int i = 0; i < m; i++) {
                    if (memory[i] == x) {
                        memory[i] = 0; // Free the allocated memory
                        hasErased = true;
                    }
                }

                // If no memory was erased, print an error message
                if (!hasErased) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
            }
        } else if (strcmp(op, "defragment") == 0) {
            // Initialize a counter for the number of free blocks
            int d = 0;

            // Move allocated memory to the front of the array
            for (int i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    d++; // Count free blocks
                } else {
                    memory[i - d] = memory[i]; // Shift allocated memory left
                }
            }

            // Clear the remaining memory at the end of the array
            for (int i = m - d; i < m; i++) {
                memory[i] = 0;
            }
        } else {
            // Handle any unrecognized command
            printf("h\n");
        }
    }

    return 0;
}
