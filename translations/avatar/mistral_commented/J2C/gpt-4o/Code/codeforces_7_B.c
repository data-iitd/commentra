#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation

int main() { // Starting the main function
    int t, m; // Variables for number of test cases and size of memory
    scanf("%d %d", &t, &m); // Reading the number of test cases and size of memory
    int *memory = (int *)calloc(m, sizeof(int)); // Allocating memory for the memory array and initializing to 0
    int allocIdx = 0; // Initializing a counter for allocated memory blocks

    for (int j = 0; j < t; j++) { // Loop through each test case
        char command[20]; // Buffer to hold the command
        scanf("%s", command); // Reading the command

        if (strcmp(command, "alloc") == 0) { // Allocate command
            int n; // Size of the block to be allocated
            scanf("%d", &n); // Reading the size of the block to be allocated
            int len = 0; // Initializing a counter for free memory blocks
            int canAlloc = 0; // Flag to check if allocation is possible
            int startIdx = -1; // Start index of the block to be allocated

            for (int i = 0; i < m; i++) { // Loop through the memory array
                if (memory[i] == 0) { // If the current block is free
                    len++; // Increment the counter
                } else { // If the current block is allocated
                    len = 0; // Reset the counter
                }
                if (len == n) { // If the free memory blocks form a block of size n
                    canAlloc = 1; // Set the flag
                    startIdx = i - n + 1; // Calculate the start index of the block
                    break; // Exit the loop
                }
            }
            if (canAlloc) { // If allocation is possible
                allocIdx++; // Increment the counter for allocated blocks
                for (int i = startIdx; i < startIdx + n; i++) // Allocate the block in the memory
                    memory[i] = allocIdx;
                printf("%d\n", allocIdx); // Print the allocated block number
            } else { // If allocation is not possible
                printf("NULL\n"); // Print NULL
            }
        } else if (strcmp(command, "erase") == 0) { // Erase command
            int x; // Block number to be erased
            scanf("%d", &x); // Reading the block number to be erased
            if (x <= 0) { // If the block number is invalid
                printf("ILLEGAL_ERASE_ARGUMENT\n"); // Print an error message
                continue; // Skip to the next iteration
            }
            int hasErased = 0; // Flag to check if the block has been erased
            for (int i = 0; i < m; i++) { // Loop through the memory array
                if (memory[i] == x) { // If the current block matches the given block number
                    memory[i] = 0; // Erase the block
                    hasErased = 1; // Set the flag
                }
            }
            if (!hasErased) { // If the block was not found
                printf("ILLEGAL_ERASE_ARGUMENT\n"); // Print an error message
            }
        } else if (strcmp(command, "defragment") == 0) { // Defragment command
            int d = 0; // Initializing a counter for free memory blocks
            for (int i = 0; i < m; i++) { // Loop through the memory array
                if (memory[i] == 0) { // If the current block is free
                    d++; // Increment the counter
                }
            }
            int newSize = m - d; // Calculate the new size of the memory array
            int *newMemory = (int *)malloc(newSize * sizeof(int)); // Create a new memory array of the new size
            int k = 0; // Initialize a counter for copying elements to the new array
            for (int i = 0; i < m; i++) { // Loop through the old memory array
                if (memory[i] != 0) { // If the current block is allocated
                    newMemory[k] = memory[i]; // Copy the block to the new array
                    k++; // Increment the counter
                }
            }
            free(memory); // Free the old memory array
            memory = newMemory; // Update the memory array with the new one
        } else { // Invalid command
            printf("h\n"); // Print an error message
        }
    }
    free(memory); // Free the memory array
    return 0; // Return success
}

// <END-OF-CODE>
