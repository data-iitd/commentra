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
    string op;
    cin >> op;
    int arg1, arg2;
    cin >> arg1 >> arg2;

    // Allocate memory if the operation type is 'alloc'
    if (op == "alloc") {
        int pos = 0;  // Initialize position counter
        for (int j = 0; j < m; j++) {
            // Check if the position is available for allocation
            if (alocuente[j] == 0) {
                // If the position is available, allocate the memory block of the given size
                pos++;
                if (pos == arg1) {
                    // Set the allocated memory blocks to the given index
                    for (int k = j - arg1 + 1; k <= j; k++) {
                        alocuente[k] = arg1;
                    }
                    // Print the allocated index
                    cout << arg1 << endl;
                    // Increment the index for the next allocation
                    arg1++;
                    // Break the loop since we found the suitable position
                    break;
                } else {
                    pos = 0;  // Reset the position counter for the next iteration
                }
            }
        }
        if (pos == 0) {
            // If no suitable position is found, print 'NULL'
            cout << "NULL" << endl;
        }
    }

    // Erase memory if the operation type is 'erase'
    else if (op == "erase") {
        int pos = 0;  // Initialize position counter
        // Check if the given index is valid and allocated
        if (arg1 >= 0 && arg1 < m && alocuente[arg1] == arg1) {
            // If the index is valid and allocated, free the memory block
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == arg1) {
                    // Set the memory block to 0 to indicate it is freed
                    alocuente[j] = 0;
                }
            }
        } else {
            // If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
            cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
        }
    }

    // Defragment memory if the operation type is 'defragment'
    else if (op == "defragment") {
        int cnt = 0;  // Initialize free block counter
        // Count the number of free blocks
        cnt = count(alocuente, alocuente + m, 0);
        // Create a new list with only allocated blocks
        vector<int> alocuente_new;
        for (int j = 0; j < m; j++) {
            if (alocuente[j]!= 0) {
                alocuente_new.push_back(alocuente[j]);
            }
        }
        // Add free blocks at the end of the list
        for (int j = 0; j < cnt; j++) {
            alocuente_new.push_back(0);
        }
        // Copy the new list to the original list
        for (int j = 0; j < m; j++) {
            alocuente[j] = alocuente_new[j];
        }
    }
}

