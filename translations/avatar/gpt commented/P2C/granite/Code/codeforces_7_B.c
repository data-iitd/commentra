
#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, m, i, j, pos, ind, op;
    int *alocuente;

    // Read the number of operations (t) and the size of the array (m)
    scanf("%d %d", &t, &m);

    // Allocate memory for the array of allocated memory blocks
    alocuente = (int*)malloc(m * sizeof(int));

    // Initialize the array to keep track of allocated memory blocks, initially all set to 0
    for (i = 0; i < m; i++) {
        alocuente[i] = 0;
    }

    // Initialize the index to keep track of the next allocation identifier
    ind = 1;

    // Process each operation
    for (i = 0; i < t; i++) {
        // Read the operation and its parameters
        scanf("%d", &op);

        // Handle the 'alloc' operation
        if (op == 1) {
            pos = 0;  // Position counter to find free blocks
            for (j = 0; j < m; j++) {
                // Check if the current block is free (0)
                if (alocuente[j] == 0) {
                    pos++;  // Increment the position counter
                    // If we have found enough consecutive free blocks
                    if (pos == scanf("%d", &op)) {
                        // Allocate the blocks and set them to the current identifier
                        for (int k = j - op + 1; k <= j; k++) {
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
            // If no sufficient space was found, output NULL
            if (pos < op) {
                printf("NULL\n");
            }
        }

        // Handle the 'erase' operation
        if (op == 2) {
            pos = 0;  // Position counter for finding the block to erase
            scanf("%d", &op);
            // Check if the identifier to erase is valid
            if (op <= 0 || op > m) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");  // Output error for illegal erase
            } else {
                // Iterate through the array to find and erase the specified block
                for (j = 0; j < m; j++) {
                    if (alocuente[j] == op) {
                        alocuente[j] = 0;  // Set the block to 0 to indicate it is free
                    }
                }
            }
        }

        // Handle the 'defragment' operation
        if (op == 3) {
            int cnt = 0;  // Counter for the number of free blocks
            cnt = 0;  // Count how many blocks are free
            for (j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;  // Increment the counter for the number of free blocks
                }
            }
            // Create a new list with only the allocated blocks (non-zero)
            int *alocuente2 = (int*)malloc((m - cnt) * sizeof(int));
            int k = 0;
            for (j = 0; j < m; j++) {
                if (alocuente[j]!= 0) {
                    alocuente2[k] = alocuente[j];
                    k++;
                }
            }
            // Append the free blocks (0) back to the end of the list
            for (j = 0; j < cnt; j++) {
                alocuente2[k] = 0;
                k++;
            }
            // Copy the new list back to the original array
            for (j = 0; j < m; j++) {
                alocuente[j] = alocuente2[j];
            }
            free(alocuente2);  // Free the memory allocated for the new list
        }
    }

    // Free the memory allocated for the array of allocated memory blocks
    free(alocuente);

    return 0;
}
