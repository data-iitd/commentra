

#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, m, i, j, pos, ind, op[2];
    int *alocuente;

    scanf("%d %d", &t, &m);
    // Read the number of operations and the size of the memory

    alocuente = (int*)malloc(m * sizeof(int));
    // Initialize an array to keep track of memory allocation

    ind = 1;
    // Initialize the ID counter for allocated memory blocks

    for (i = 0; i < t; i++) {
        // Loop through each operation
        scanf("%s %d", op, &op[1]);
        // Read the operation and split it into parts
        if (strcmp(op, "alloc") == 0) {
            // If the operation is to allocate memory
            pos = 0;
            // Initialize a position counter
            for (j = 0; j < m; j++) {
                // Loop through each memory block
                if (alocuente[j] == 0) {
                    // Check if the memory block is free
                    pos++;
                    // Increment the position counter
                    if (pos == op[1]) {
                        // If a contiguous block of the required size is found
                        for (int k = j - op[1] + 1; k <= j; k++) {
                            // Allocate the memory block with the current ID
                            alocuente[k] = ind;
                        }
                        printf("%d\n", ind);
                        ind++;
                        break;
                    }
                } else {
                    pos = 0;
                    // Reset the position counter if a free block is interrupted
                }
            }
            if (pos < op[1]) {
                printf("NULL\n");
                // If no contiguous block is found, print "NULL"
            }
        }
        if (strcmp(op, "erase") == 0) {
            // If the operation is to erase a memory block
            pos = 0;
            if (op[1] <= 0 || op[1] > m || alocuente[op[1] - 1] == 0) {
                // Check if the specified memory block is allocated and not already free
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                // If not, print "ILLEGAL_ERASE_ARGUMENT"
            } else {
                for (j = 0; j < m; j++) {
                    if (op[1] > 0 && alocuente[j] == op[1]) {
                        alocuente[j] = 0;
                        // Free the specified memory block
                    }
                }
            }
        }
        if (strcmp(op, "defragment") == 0) {
            // If the operation is to defragment the memory
            int cnt = 0;
            cnt = 0;
            for (j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                    // Count the number of free memory blocks
                }
            }
            for (j = 0; j < m; j++) {
                if (alocuente[j]!= 0) {
                    alocuente[j - cnt] = alocuente[j];
                    // Remove free memory blocks from the array
                }
            }
            for (j = 0; j < cnt; j++) {
                alocuente[m - 1 - j] = 0;
                // Append the free memory blocks at the end of the array
            }
        }
    }

    free(alocuente);
    // Free the memory allocated for the array

    return 0;
}
