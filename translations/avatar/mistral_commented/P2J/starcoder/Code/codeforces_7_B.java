#######
# Code
#######

// Read input number of tests and memory size
int t, m;
t = Integer.parseInt(input());
m = Integer.parseInt(input());

// Initialize an array to represent the memory allocation status
int[] alocuente = new int[m];

// Loop through each test case
for (int i = 0; i < t; i++) {
    // Read the operation type and arguments
    String[] op = input().split();

    // Allocate memory if the operation type is 'alloc'
    if (op[0].equals("alloc")) {
        int pos = 0; // Initialize position counter
        for (int j = 0; j < m; j++) {
            // Check if the position is available for allocation
            if (alocuente[j] == 0) {
                // If the position is available, allocate the memory block of the given size
                pos++;
                if (pos == Integer.parseInt(op[1])) {
                    // Set the allocated memory blocks to the given index
                    for (int k = j - Integer.parseInt(op[1]) + 1; k <= j; k++) {
                        alocuente[k] = ind;
                    }
                    // Print the allocated index
                    System.out.println(ind);
                    // Increment the index for the next allocation
                    ind++;
                    // Break the loop since we found the suitable position
                    break;
                } else {
                    pos = 0; // Reset the position counter for the next iteration
                }
            }
        } else {
            // If no suitable position is found, print 'NULL'
            System.out.println("NULL");
        }

    // Erase memory if the operation type is 'erase'
    } else if (op[0].equals("erase")) {
        int pos = 0; // Initialize position counter
        // Check if the given index is valid and allocated
        if (Integer.parseInt(op[1]) < 0 || Integer.parseInt(op[1]) >= ind || alocuente[Integer.parseInt(op[1])] == 0) {
            // If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
            System.out.println("ILLEGAL_ERASE_ARGUMENT");
        } else {
            // If the index is valid and allocated, free the memory block
            for (int j = 0; j < m; j++) {
                if (Integer.parseInt(op[1]) > 0 && alocuente[j] == Integer.parseInt(op[1])) {
                    // Set the memory block to 0 to indicate it is freed
                    alocuente[j] = 0;
        }

    // Defragment memory if the operation type is 'defragment'
    } else if (op[0].equals("defragment")) {
        int cnt = 0; // Initialize free block counter
        // Count the number of free blocks
        cnt = 0;
        for (int j = 0; j < m; j++) {
            if (alocuente[j] == 0) {
                cnt++;
            }
        }
        // Create a new list with only allocated blocks
        int[] alocuente2 = new int[m - cnt];
        int k = 0;
        for (int j = 0; j < m; j++) {
            if (alocuente[j]!= 0) {
                alocuente2[k] = alocuente[j];
                k++;
            }
        }
        // Add free blocks at the end of the list
        for (int j = 0; j < cnt; j++) {
            alocuente2[k] = 0;
            k++;
        }
        // Copy the new list to the original list
        for (int j = 0; j < m; j++) {
            alocuente[j] = alocuente2[j];
        }
}

