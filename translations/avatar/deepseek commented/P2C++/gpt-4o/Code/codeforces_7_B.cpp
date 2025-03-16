#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t, m;
    cin >> t >> m; // Read the number of operations and the size of the memory

    vector<int> alocuente(m, 0); // Initialize an array to keep track of memory allocation, all elements set to 0

    int ind = 1; // Initialize the ID counter for allocated memory blocks

    for (int i = 0; i < t; i++) {
        string op;
        cin >> op; // Read the operation

        if (op == "alloc") {
            int size;
            cin >> size; // Read the size to allocate
            int pos = 0; // Initialize a position counter

            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) { // Check if the memory block is free
                    pos++; // Increment the position counter
                    if (pos == size) { // If a contiguous block of the required size is found
                        for (int k = j - size + 1; k <= j; k++) {
                            alocuente[k] = ind; // Allocate the memory block with the current ID
                        }
                        cout << ind << endl; // Print the allocated ID
                        ind++; // Increment the ID counter
                        break;
                    }
                } else {
                    pos = 0; // Reset the position counter if a free block is interrupted
                }
            }
            if (pos < size) {
                cout << "NULL" << endl; // If no contiguous block is found, print "NULL"
            }
        }

        if (op == "erase") {
            int id;
            cin >> id; // Read the ID to erase
            if (find(alocuente.begin(), alocuente.end(), id) == alocuente.end() || id == 0) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl; // If not, print "ILLEGAL_ERASE_ARGUMENT"
            } else {
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == id) {
                        alocuente[j] = 0; // Free the specified memory block
                    }
                }
            }
        }

        if (op == "defragment") {
            int cnt = count(alocuente.begin(), alocuente.end(), 0); // Count the number of free memory blocks
            vector<int> new_alocuente; // Create a new vector for defragmented memory
            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    new_alocuente.push_back(alocuente[j]); // Keep allocated blocks
                }
            }
            new_alocuente.resize(m, 0); // Resize to original size and fill with 0s
            alocuente = new_alocuente; // Update the original vector
        }
    }

    return 0;
}

// <END-OF-CODE>
