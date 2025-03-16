#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read input number of tests and memory size
    int t, m;
    scanf("%d %d", &t, &m);

    // Initialize an array to represent the memory allocation status
    int *alocuente = (int *)calloc(m, sizeof(int));
    int ind = 1; // Initialize index for allocated blocks

    // Loop through each test case
    for (int i = 0; i < t; i++) {
        char op[20];
        scanf("%s", op);

        // Allocate memory if the operation type is 'alloc'
        if (strcmp(op, "alloc") == 0) {
            int size;
            scanf("%d", &size);
            int pos = 0; // Initialize position counter
            for (int j = 0; j < m; j++) {
                // Check if the position is available for allocation
                if (alocuente[j] == 0) {
                    pos++;
                    if (pos == size) {
                        // Set the allocated memory blocks to the given index
                        for (int k = j - size + 1; k <= j; k++) {
                            alocuente[k] = ind;
                        }
                        // Print the allocated index
                        printf("%d\n", ind);
                        // Increment the index for the next allocation
                        ind++;
                        // Break the loop since we found the suitable position
                        break;
                    }
                } else {
                    pos = 0; // Reset the position counter for the next iteration
                }
            }
            if (pos < size) {
                // If no suitable position is found, print 'NULL'
                printf("NULL\n");
            }
        }

        // Erase memory if the operation type is 'erase'
        else if (strcmp(op, "erase") == 0) {
            int index;
            scanf("%d", &index);
            // Check if the given index is valid and allocated
            if (index <= 0 || index >= ind || !memchr(alocuente, index, m * sizeof(int))) {
                // If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            } else {
                // If the index is valid and allocated, free the memory block
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == index) {
                        // Set the memory block to 0 to indicate it is freed
                        alocuente[j] = 0;
                    }
                }
            }
        }

        // Defragment memory if the operation type is 'defragment'
        else if (strcmp(op, "defragment") == 0) {
            int cnt = 0; // Initialize free block counter
            // Count the number of free blocks
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }
            // Create a new list with only allocated blocks
            int *new_alocuente = (int *)calloc(m, sizeof(int));
            int index = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    new_alocuente[index++] = alocuente[j];
                }
            }
            // Add free blocks at the end of the list
            free(alocuente);
            alocuente = new_alocuente;
        }
    }

    // Free allocated memory
    free(alocuente);
    return 0;
}

// <END-OF-CODE>
