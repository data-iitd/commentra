#######
# Code
#######

# Read input number of tests and memory size
t, m = map(int, input().split());

// Initialize an array to represent the memory allocation status
int alocuente[m];

// Loop through each test case
for (int i = 0; i < t; i++) {
    // Read the operation type and arguments
    char *op = input();

    // Allocate memory if the operation type is 'alloc'
    if (strcmp(op, "alloc") == 0) {
        int pos = 0;  // Initialize position counter
        for (int j = 0; j < m; j++) {
            // Check if the position is available for allocation
            if (alocuente[j] == 0) {
                // If the position is available, allocate the memory block of the given size
                pos += 1;
                if (pos == atoi(op + 5)) {
                    // Set the allocated memory blocks to the given index
                    for (int k = j - atoi(op + 5) + 1; k <= j; k++) {
                        alocuente[k] = atoi(op + 1);
                    }
                    // Print the allocated index
                    printf("%d\n", atoi(op + 1));
                    // Increment the index for the next allocation
                    break;
                } else {
                    pos = 0;  // Reset the position counter for the next iteration
                }
            }
        }
        if (pos == 0) {
            // If no suitable position is found, print 'NULL'
            printf("NULL\n");
        }
    }

    // Erase memory if the operation type is 'erase'
    else if (strcmp(op, "erase") == 0) {
        int pos = 0;  // Initialize position counter
        // Check if the given index is valid and allocated
        if (atoi(op + 5) >= 0 && atoi(op + 5) < m && alocuente[atoi(op + 5)] == atoi(op + 1)) {
            // If the index is valid and allocated, free the memory block
            for (int j = 0; j < m; j++) {
                if (atoi(op + 5) > 0 && alocuente[j] == atoi(op + 1)) {
                    // Set the memory block to 0 to indicate it is freed
                    alocuente[j] = 0;
                }
            }
        } else {
            // If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
            printf("ILLEGAL_ERASE_ARGUMENT\n");
        }
    }

    // Defragment memory if the operation type is 'defragment'
    else if (strcmp(op, "defragment") == 0) {
        int cnt = 0;  // Initialize free block counter
        // Count the number of free blocks
        for (int j = 0; j < m; j++) {
            if (alocuente[j] == 0) {
                cnt++;
            }
        }
        // Create a new list with only allocated blocks
        int *alocuente_new = (int *)malloc(sizeof(int) * cnt);
        int k = 0;
        for (int j = 0; j < m; j++) {
            if (alocuente[j]!= 0) {
                alocuente_new[k] = alocuente[j];
                k++;
            }
        }
        // Add free blocks at the end of the list
        for (int j = 0; j < cnt; j++) {
            alocuente_new[k] = 0;
            k++;
        }
        // Copy the new list to the original list
        for (int j = 0; j < m; j++) {
            alocuente[j] = alocuente_new[j];
        }
        // Free the new list
        free(alocuente_new);
    }
}

