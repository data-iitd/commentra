#######
# Code
#######

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read input number of tests and memory size
    int t, m;
    cin >> t >> m;

    // Initialize an array to represent the memory allocation status
    vector<int> alocuente(m, 0);

    // Loop through each test case
    for (int i = 0; i < t; i++) {
        // Read the operation type and arguments
        string op;
        int arg;
        cin >> op >> arg;

        // Allocate memory if the operation type is 'alloc'
        if (op == "alloc") {
            int pos = 0;  // Initialize position counter
            for (int j = 0; j < m; j++) {
                // Check if the position is available for allocation
                if (alocuente[j] == 0) {
                    // If the position is available, allocate the memory block of the given size
                    pos += 1;
                    if (pos == arg) {
                        // Set the allocated memory blocks to the given index
                        for (int k = j - arg + 1; k <= j; k++) {
                            alocuente[k] = i + 1;
                        }
                        // Print the allocated index
                        cout << i + 1 << endl;
                        // Increment the index for the next allocation
                        i++;
                        // Break the loop since we found the suitable position
                        break;
                    } else {
                        pos = 0;  // Reset the position counter for the next iteration
                    }
                }
            }
            // If no suitable position is found, print 'NULL'
            if (pos == 0) {
                cout << "NULL" << endl;
            }
        }
        // Erase memory if the operation type is 'erase'
        else if (op == "erase") {
            int pos = 0;  // Initialize position counter
            // Check if the given index is valid and allocated
            if (arg > m || alocuente[arg - 1] == 0) {
                // If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            } else {
                // If the index is valid and allocated, free the memory block
                for (int j = 0; j < m; j++) {
                    if (arg > 0 && alocuente[j] == arg) {
                        // Set the memory block to 0 to indicate it is freed
                        alocuente[j] = 0;
                    }
                }
            }
        }
        // Defragment memory if the operation type is 'defragment'
        else if (op == "defragment") {
            int cnt = 0;  // Initialize free block counter
            // Count the number of free blocks
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }
            // Create a new list with only allocated blocks
            vector<int> alocuente_new;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    alocuente_new.push_back(alocuente[j]);
                }
            }
            // Add free blocks at the end of the list
            for (int j = 0; j < cnt; j++) {
                alocuente_new.push_back(0);
            }
            // Replace the old list with the new list
            alocuente = alocuente_new;
        }
    }

    return 0;
}

