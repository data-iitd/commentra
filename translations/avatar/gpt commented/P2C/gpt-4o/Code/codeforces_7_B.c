#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of operations (t) and the size of the array (m)
    int t, m;
    scanf("%d %d", &t, &m);
    
    // Initialize an array to keep track of allocated memory blocks, initially all set to 0
    int *alocuente = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        alocuente[i] = 0;
    }
    
    // Initialize an index to keep track of the next allocation identifier
    int ind = 1;

    // Process each operation
    for (int i = 0; i < t; i++) {
        char op[20];
        scanf("%s", op);
        
        // Handle the 'alloc' operation
        if (strcmp(op, "alloc") == 0) {
            int size;
            scanf("%d", &size);
            int pos = 0;  // Position counter to find free blocks
            
            for (int j = 0; j < m; j++) {
                // Check if the current block is free (0)
                if (alocuente[j] == 0) {
                    pos++;  // Increment the position counter
                    // If we have found enough consecutive free blocks
                    if (pos == size) {
                        // Allocate the blocks and set them to the current identifier
                        for (int k = j - size + 1; k <= j; k++) {
                            alocuente[k] = ind;
                        }
                        printf("%d\n", ind);  // Output the identifier of the allocated blocks
                        ind++;  // Increment the identifier for the next allocation
                        break;
                    }
                } else {
                    pos = 0;  // Reset position counter if a block is occupied
                }
            }
            if (pos < size) {
                // If no sufficient space was found, output NULL
                printf("NULL\n");
            }
        }
        
        // Handle the 'erase' operation
        if (strcmp(op, "erase") == 0) {
            int id;
            scanf("%d", &id);
            int found = 0;  // Flag to check if the identifier is found
            
            // Check if the identifier to erase is valid
            if (id <= 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");  // Output error for illegal erase
            } else {
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == id) {
                        alocuente[j] = 0;  // Set the block to 0 to indicate it is free
                        found = 1;  // Mark that we found the identifier
                    }
                }
                if (!found) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");  // Output error if identifier not found
                }
            }
        }
        
        // Handle the 'defragment' operation
        if (strcmp(op, "defragment") == 0) {
            int cnt = 0;  // Counter for the number of free blocks
            
            // Count how many blocks are free
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }
            
            // Create a new array to hold the defragmented blocks
            int *new_alocuente = (int *)malloc((m) * sizeof(int));
            int index = 0;
            
            // Copy only the allocated blocks (non-zero)
            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    new_alocuente[index++] = alocuente[j];
                }
            }
            
            // Append the free blocks (0) back to the end of the list
            for (int j = 0; j < cnt; j++) {
                new_alocuente[index++] = 0;
            }
            
            // Free the old array and point to the new one
            free(alocuente);
            alocuente = new_alocuente;
        }
    }
    
    // Free the allocated memory
    free(alocuente);
    return 0;
}

// <END-OF-CODE>
