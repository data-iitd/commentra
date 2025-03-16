
#####
# Code
#####

# Read input number of tests and memory size
int t, m;
cin >> t >> m;

// Initialize an array to represent the memory allocation status
int alocuente[m];
for (int i = 0; i < m; i++) {
    alocuente[i] = 0;
}

// Loop through each test case
for (int i = 0; i < t; i++) {
    // Read the operation type and arguments
    string op;
    cin >> op;
    if (op == "alloc") {
        int size;
        cin >> size;
        int pos = 0;  // Initialize position counter
        for (int j = 0; j < m; j++) {
            // Check if the position is available for allocation
            if (alocuente[j] == 0) {
                // If the position is available, allocate the memory block of the given size
                pos++;
                if (pos == size) {
                    // Set the allocated memory blocks to the given index
                    for (int k = j - size + 1; k <= j; k++) {
                        alocuente[k] = ind;
                    }
                    // Print the allocated index
                    cout << ind << endl;
                    // Increment the index for the next allocation
                    ind++;
                    // Break the loop since we found the suitable position
                    break;
                } else {
                    pos = 0;  // Reset the position counter for the next iteration
                }
            }
        }
        if (pos!= size) {
            // If no suitable position is found, print 'NULL'
            cout << "NULL" << endl;
        }
    } else if (op == "erase") {
        int index;
        cin >> index;
        int pos = 0;  // Initialize position counter
        // Check if the given index is valid and allocated
        if (index <= 0 || index > m || alocuente[index - 1] == 0) {
            // If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
            cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
        } else {
            // If the index is valid and allocated, free the memory block
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == index) {
                    // Set the memory block to 0 to indicate it is freed
                    alocuente[j] = 0;
                }
            }
        }
    } else if (op == "defragment") {
        int cnt = 0;  // Initialize free block counter
        // Count the number of free blocks
        for (int j = 0; j < m; j++) {
            if (alocuente[j] == 0) {
                cnt++;
            }
        }
        // Create a new list with only allocated blocks
        vector<int> new_alocuente;
        for (int j = 0; j < m; j++) {
            if (alocuente[j]!= 0) {
                new_alocuente.push_back(alocuente[j]);
            }
        }
        // Add free blocks at the end of the list
        for (int j = 0; j < cnt; j++) {
            new_alocuente.push_back(0);
        }
        // Copy the new list back to the original array
        for (int j = 0; j < m; j++) {
            alocuente[j] = new_alocuente[j];
        }
    }
}

