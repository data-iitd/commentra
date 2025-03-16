#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    // Read the number of operations and the size of the memory

    int *alocuente = (int *)calloc(m, sizeof(int));
    // Initialize an array to keep track of memory allocation, all elements set to 0

    int ind = 1;
    // Initialize the ID counter for allocated memory blocks

    for (int i = 0; i < t; i++) {
        // Loop through each operation
        char op[20];
        scanf("%s", op);
        // Read the operation

        if (strcmp(op, "alloc") == 0) {
            // If the operation is to allocate memory
            int size;
            scanf("%d", &size);
            // Read the size to allocate
            int pos = 0;
            // Initialize a position counter

            for (int j = 0; j < m; j++) {
                // Loop through each memory block
                if (alocuente[j] == 0) {
                    // Check if the memory block is free
                    pos++;
                    // Increment the position counter
                    if (pos == size) {
                        // If a contiguous block of the required size is found
                        for (int k = j - size + 1; k <= j; k++) {
                            alocuente[k] = ind;
                        }
                        // Allocate the memory block with the current ID
                        printf("%d\n", ind);
                        ind++;
                        break;
                    }
                } else {
                    pos = 0;
                    // Reset the position counter if a free block is interrupted
                }
            }
            if (pos < size) {
                printf("NULL\n");
                // If no contiguous block is found, print "NULL"
            }
        }

        if (strcmp(op, "erase") == 0) {
            // If the operation is to erase a memory block
            int id;
            scanf("%d", &id);
            // Read the ID to erase
            int found = 0;

            if (id <= 0) {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                // If not valid, print "ILLEGAL_ERASE_ARGUMENT"
            } else {
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == id) {
                        alocuente[j] = 0;
                        found = 1;
                        // Free the specified memory block
                    }
                }
                if (!found) {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
            }
        }

        if (strcmp(op, "defragment") == 0) {
            // If the operation is to defragment the memory
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }
            // Count the number of free memory blocks

            int *new_alocuente = (int *)malloc((m - cnt) * sizeof(int));
            // Create a new array without free blocks
            int index = 0;

            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    new_alocuente[index++] = alocuente[j];
                }
            }

            for (int j = 0; j < cnt; j++) {
                new_alocuente[index++] = 0;
                // Append the free memory blocks at the end of the array
            }

            free(alocuente);
            alocuente = new_alocuente;
            m -= cnt; // Update the size of the memory
        }
    }

    free(alocuente);
    return 0;
}
