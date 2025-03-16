#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create variables for number of operations (t) and size of memory (m)
    int t, m;
    scanf("%d %d", &t, &m);
    
    // Initialize the memory array to keep track of allocated memory
    int *memory = (int *)calloc(m, sizeof(int));
    
    // Initialize the allocation index to track the allocation IDs
    int allocIdx = 0;
    
    // Process each operation based on the number of operations (t)
    for (int j = 0; j < t; j++) {
        char operation[20];
        scanf("%s", operation);
        
        if (strcmp(operation, "alloc") == 0) {
            // Read the size of memory to allocate
            int n;
            scanf("%d", &n);
            int len = 0;
            int canAlloc = 0;
            int startIdx = 0;
            
            // Check for a contiguous block of free memory of size n
            for (int i = 0; i < m; i++) {
                if (memory[i] == 0) {
                    len++; // Increase length if the current memory is free
                } else {
                    len = 0; // Reset length if the current memory is allocated
                }
                
                // If a sufficient block is found, mark it as allocatable
                if (len == n) {
                    canAlloc = 1;
                    startIdx = i - n + 1; // Calculate the starting index for allocation
                    break;
                }
            }
            
            // If allocation is possible, allocate memory and print the allocation ID
            if (canAlloc) {
                allocIdx++;
                for (int i = startIdx; i < startIdx + n; i++) {
                    memory[i] = allocIdx; // Mark the allocated memory with the allocation ID
                }
                printf("%d\n", allocIdx); // Output the allocation ID
            } else {
                printf("NULL\n"); // Output NULL if allocation failed
            }
        } else if (strcmp(operation, "erase") == 0) {
            // Read the allocation ID to erase
            int x;
            scanf("%d", &x);
            
            // Check for illegal erase argument
            if (x <= 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                continue;
            }
            
            int hasErased = 0;
            
            // Erase the memory corresponding to the given allocation ID
            for (int i = 0; i < m; i++) {
                if (memory[i] == x) {
                    memory[i] = 0; // Free the allocated memory
                    hasErased = 1;
                }
            }
            
            // If no memory was erased, print an error message
            if (!hasErased) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            }
        } else if (strcmp(operation, "defragment") == 0) {
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
    
    // Free the allocated memory
    free(memory);
    
    return 0;
}

// <END-OF-CODE>
