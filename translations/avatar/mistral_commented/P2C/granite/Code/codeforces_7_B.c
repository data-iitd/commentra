
###
# Code
###

# Read input number of tests and memory size
scanf("%d %d", &t, &m);

// Initialize an array to represent the memory allocation status
int alocuente[m];
for (int i = 0; i < m; i++) {
    alocuente[i] = 0;
}

// Loop through each test case
for (int i = 0; i < t; i++) {
    // Read the operation type and arguments
    char op[10];
    int arg;
    scanf("%s %d", op, &arg);

    // Allocate memory if the operation type is 'alloc'
    if (strcmp(op, "alloc") == 0) {
        int pos = 0;  // Initialize position counter
        for (int j = 0; j < m; j++) {
            // Check if the position is available for allocation
            if (alocuente[j] == 0) {
                // If the position is available, allocate the memory block of the given size
                pos++;
                if (pos == arg) {
                    // Set the allocated memory blocks to the given index
                    for (int k = j - arg + 1; k <= j; k++) {
                        alocuente[k] = ind;
                    }
                    // Print the allocated index
                    printf("%d\n", ind);
                    // Increment the index for the next allocation
                    ind++;
                    // Break the loop since we found the suitable position
                    break;
                } else {
                    pos = 0;  // Reset the position counter for the next iteration
                }
            }
        }
        if (pos!= arg) {
            // If no suitable position is found, print 'NULL'
            printf("NULL\n");
        }
    }

    // Erase memory if the operation type is 'erase'
    else if (strcmp(op, "erase") == 0) {
        int pos = 0;  // Initialize position counter
        // Check if the given index is valid and allocated
        if (arg <= 0 || arg > m || alocuente[arg - 1] == 0) {
            // If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
            printf("ILLEGAL_ERASE_ARGUMENT\n");
        } else {
            // If the index is valid and allocated, free the memory block
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == arg) {
                    // Set the memory block to 0 to indicate it is freed
                    alocuente[j] = 0;
                }
            }
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
        int new_alocuente[m];
        int k = 0;
        for (int j = 0; j < m; j++) {
            if (alocuente[j]!= 0) {
                new_alocuente[k] = alocuente[j];
                k++;
            }
        }
        // Add free blocks at the end of the list
        for (int j = 0; j < cnt; j++) {
            new_alocuente[k] = 0;
            k++;
        }
        // Copy the new list back to the original array
        for (int j = 0; j < m; j++) {
            alocuente[j] = new_alocuente[j];
        }
    }
}
