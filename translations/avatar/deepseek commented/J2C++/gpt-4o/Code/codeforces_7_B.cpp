#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t, m;
    cin >> t; // Step 1: Read the number of test cases (t) from the input.
    cin >> m; // Step 1: Read the size of memory (m) from the input.
    vector<int> memory(m, 0); // Step 2: Initialize a vector to keep track of memory allocation.
    int allocIdx = 0; // Initialize the allocation index.

    for (int j = 0; j < t; j++) { // Step 3: Loop through each test case.
        string command;
        cin >> command; // Step 4: Read the command and perform the corresponding action.

        if (command == "alloc") {
            int n;
            cin >> n; // Step 5: Read the size of memory block to allocate.
            int len = 0; // Initialize the length counter.
            bool canAlloc = false; // Flag to check if allocation is possible.
            int startIdx = -1; // To store the starting index of the block.

            for (int i = 0; i < m; i++) { // Iterate through memory to find a suitable block.
                if (memory[i] == 0) len++; // Increment length if current block is free.
                else len = 0; // Reset length if current block is allocated.

                if (len == n) { // Check if a block of size n is found.
                    canAlloc = true; // Set flag to true.
                    startIdx = i - n + 1; // Set the starting index of the block.
                    break; // Exit the loop as block is found.
                }
            }

            if (canAlloc) { // Step 5: If allocation is possible.
                allocIdx++; // Increment the allocation index.
                for (int i = startIdx; i < startIdx + n; i++) memory[i] = allocIdx; // Allocate the block.
                cout << allocIdx << endl; // Print the allocation index.
            } else {
                cout << "NULL" << endl; // Step 5: If allocation is not possible, print "NULL".
            }
        } else if (command == "erase") {
            int x;
            cin >> x; // Step 6: Read the index of the block to erase.
            if (x <= 0) { // Check if the index is valid.
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl; // Print error message if index is invalid.
                continue;
            }
            bool hasErased = false; // Flag to check if any block is erased.

            for (int i = 0; i < m; i++) { // Iterate through memory to find the block to erase.
                if (memory[i] == x) { // Check if the block matches the index.
                    memory[i] = 0; // Erase the block.
                    hasErased = true; // Set flag to true.
                }
            }

            if (!hasErased) cout << "ILLEGAL_ERASE_ARGUMENT" << endl; // Step 6: If no block is erased, print error message.
        } else if (command == "defragment") {
            int d = 0; // Initialize the defragmentation index.
            for (int i = 0; i < m; i++) { // Iterate through memory to defragment.
                if (memory[i] == 0) d++; // Increment defragmentation index if current block is free.
                else memory[i - d] = memory[i]; // Shift the block to the left.
            }
            for (int i = m - d; i < m; i++) memory[i] = 0; // Fill the remaining space with zeros.
        } else {
            cout << "h" << endl; // Step 8: If the command is unknown, print "h".
        }
    }
    return 0; // Step 9: End of the program.
}

// <END-OF-CODE>
