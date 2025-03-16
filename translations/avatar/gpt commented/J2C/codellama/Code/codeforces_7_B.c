#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int t, m, n, len, i, j, x, d; 
    int allocIdx = 0; 
    int *memory = (int *)malloc(m * sizeof(int)); 
    char *operation = (char *)malloc(10 * sizeof(char)); 
    
    // Read the number of operations (t) and the size of memory (m)
    scanf("%d %d", &t, &m); 
    
    // Initialize the memory array to keep track of allocated memory
    for (i = 0; i < m; i++) 
        memory[i] = 0; 
    
    // Process each operation based on the number of operations (t)
    for (j = 0; j < t; j++) { 
        // Read the operation type (alloc, erase, defragment)
        scanf("%s", operation); 
        
        switch (operation[0]) { 
            case 'a': 
                // Read the size of memory to allocate
                scanf("%d", &n); 
                len = 0; 
                bool canAlloc = false; 
                
                // Check for a contiguous block of free memory of size n
                for (i = 0; i < m; i++) { 
                    if (memory[i] == 0) 
                        len++; // Increase length if the current memory is free
                    else 
                        len = 0; // Reset length if the current memory is allocated
                    
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
                    for (i = len; i < len + n; i++) 
                        memory[i] = allocIdx; // Mark the allocated memory with the allocation ID
                    printf("%d\n", allocIdx); // Output the allocation ID
                } else 
                    printf("NULL\n"); // Output NULL if allocation failed
                break; 
                
            case 'e': 
                // Read the allocation ID to erase
                scanf("%d", &x); 
                
                // Check for illegal erase argument
                if (x <= 0) { 
                    printf("ILLEGAL_ERASE_ARGUMENT\n"); 
                    break; 
                } 
                
                bool hasErased = false; 
                
                // Erase the memory corresponding to the given allocation ID
                for (i = 0; i < m; i++) { 
                    if (memory[i] == x) { 
                        memory[i] = 0; // Free the allocated memory
                        hasErased = true; 
                    } 
                } 
                
                // If no memory was erased, print an error message
                if (!hasErased) 
                    printf("ILLEGAL_ERASE_ARGUMENT\n"); 
                break; 
                
            case 'd': 
                // Initialize a counter for the number of free blocks
                d = 0; 
                
                // Move allocated memory to the front of the array
                for (i = 0; i < m; i++) { 
                    if (memory[i] == 0) 
                        d++; // Count free blocks
                    else 
                        memory[i - d] = memory[i]; // Shift allocated memory left
                } 
                
                // Clear the remaining memory at the end of the array
                for (i = m - d; i < m; i++) 
                    memory[i] = 0; 
                break; 
                
            default: 
                // Handle any unrecognized command
                printf("h\n"); 
                break; 
        } 
    } 
    
    // Close the scanner to free resources
    free(memory); 
    free(operation); 
    return 0; 
} 
