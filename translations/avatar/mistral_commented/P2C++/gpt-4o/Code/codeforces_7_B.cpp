#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read input number of tests and memory size
    int t, m;
    cin >> t >> m;

    // Initialize a vector to represent the memory allocation status
    vector<int> alocuente(m, 0);
    int ind = 1; // Initialize index for allocated blocks

    // Loop through each test case
    for (int i = 0; i < t; i++) {
        // Read the operation type and arguments
        string op;
        cin >> op;

        // Allocate memory if the operation type is 'alloc'
        if (op == "alloc") {
            int size;
            cin >> size;
            int pos = 0; // Initialize position counter
            for (int j = 0; j < m; j++) {
                // Check if the position is available for allocation
                if (alocuente[j] == 0) {
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
                    }
                } else {
                    pos = 0; // Reset the position counter for the next iteration
                }
            }
            if (pos < size) {
                // If no suitable position is found, print 'NULL'
                cout << "NULL" << endl;
            }
        }

        // Erase memory if the operation type is 'erase'
        else if (op == "erase") {
            int index;
            cin >> index;
            // Check if the given index is valid and allocated
            if (index <= 0 || find(alocuente.begin(), alocuente.end(), index) == alocuente.end()) {
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
        }

        // Defragment memory if the operation type is 'defragment'
        else if (op == "defragment") {
            int cnt = 0; // Initialize free block counter
            // Count the number of free blocks
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }
            // Create a new vector with only allocated blocks
            vector<int> new_alocuente;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    new_alocuente.push_back(alocuente[j]);
                }
            }
            // Add free blocks at the end of the vector
            for (int j = 0; j < cnt; j++) {
                new_alocuente.push_back(0);
            }
            alocuente = new_alocuente; // Update the original vector
        }
    }

    return 0;
}

// <END-OF-CODE>
