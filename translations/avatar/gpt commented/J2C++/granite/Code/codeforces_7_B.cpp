
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Create a vector to keep track of allocated memory
    vector<int> memory(100); // Assuming a maximum memory size of 100

    // Initialize the allocation index to track the allocation IDs
    int allocIdx = 0;

    // Read the number of operations (t) and the size of memory (m)
    int t, m;
    cin >> t >> m;

    // Process each operation based on the number of operations (t)
    for (int j = 0; j < t; j++) {
        string op;
        cin >> op;

        if (op == "alloc") {
            // Read the size of memory to allocate
            int n;
            cin >> n;

            int len = 0;
            bool canAlloc = false;

            // Check for a contiguous block of free memory of size n
            for (int i = 0; i < m; i++) {
                if (memory[i] == 0)
                    len++; // Increase length if the current memory is free
                else
                    len = 0; // Reset length if the current memory is allocated

                // If a sufficient block is found, mark it as allocatable
                if (len == n) {
                    canAlloc = true;
                    len = i - n + 1; // Calculate the starting index for allocation
                    break;
                }
            }

            // If allocation is possible, allocate memory and print the allocation ID
            if (canAlloc) {
                allocIdx++;
                for (int i = len; i < len + n; i++)
                    memory[i] = allocIdx; // Mark the allocated memory with the allocation ID
                cout << allocIdx << endl; // Output the allocation ID
            } else
                cout << "NULL" << endl; // Output NULL if allocation failed
        } else if (op == "erase") {
            // Read the allocation ID to erase
            int x;
            cin >> x;

            // Check for illegal erase argument
            if (x <= 0) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
                continue;
            }

            bool hasErased = false;

            // Erase the memory corresponding to the given allocation ID
            for (int i = 0; i < m; i++) {
                if (memory[i] == x) {
                    memory[i] = 0; // Free the allocated memory
                    hasErased = true;
                }
            }

            // If no memory was erased, print an error message
            if (!hasErased)
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
        } else if (op == "defragment") {
            // Initialize a counter for the number of free blocks
            int d = 0;

            // Move allocated memory to the front of the array
            for (int i = 0; i < m; i++) {
                if (memory[i] == 0)
                    d++; // Count free blocks
                else
                    memory[i - d] = memory[i]; // Shift allocated memory left
            }

            // Clear the remaining memory at the end of the array
            for (int i = m - d; i < m; i++)
                memory[i] = 0;
        } else {
            // Handle any unrecognized command
            cout << "h" << endl;
        }
    }

    return 0;
}
