#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read the number of operations (t) and the size of the array (m)
    int t, m;
    cin >> t >> m;

    // Initialize a vector to keep track of allocated memory blocks, initially all set to 0
    vector<int> alocuente(m, 0);
    // Initialize an index to keep track of the next allocation identifier
    int ind = 1;

    // Process each operation
    for (int i = 0; i < t; i++) {
        string op;
        cin >> op;

        // Handle the 'alloc' operation
        if (op == "alloc") {
            int size;
            cin >> size;
            int pos = 0;  // Position counter to find free blocks
            for (int j = 0; j < m; j++) {
                // Check if the current block is free (0)
                if (alocuente[j] == 0) {
                    pos++;  // Increment the position counter
                    // If we have found enough consecutive free blocks
                    if (pos == size) {
                        // Allocate the blocks and set them to the current identifier
                        for (int k = j - size + 1; k <= j; k++) {
                            alocuente[k] = ind;
                        }
                        cout << ind << endl;  // Output the identifier of the allocated blocks
                        ind++;  // Increment the identifier for the next allocation
                        break;
                    }
                } else {
                    pos = 0;  // Reset position counter if a block is occupied
                }
            }
            if (pos < size) {
                // If no sufficient space was found, output NULL
                cout << "NULL" << endl;
            }
        }

        // Handle the 'erase' operation
        if (op == "erase") {
            int id;
            cin >> id;
            // Check if the identifier to erase is valid
            if (find(alocuente.begin(), alocuente.end(), id) == alocuente.end() || id == 0) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;  // Output error for illegal erase
            } else {
                // Iterate through the array to find and erase the specified block
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == id) {
                        alocuente[j] = 0;  // Set the block to 0 to indicate it is free
                    }
                }
            }
        }

        // Handle the 'defragment' operation
        if (op == "defragment") {
            int cnt = count(alocuente.begin(), alocuente.end(), 0);  // Count how many blocks are free
            // Create a new vector with only the allocated blocks (non-zero)
            vector<int> new_alocuente;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    new_alocuente.push_back(alocuente[j]);
                }
            }
            // Append the free blocks (0) back to the end of the vector
            new_alocuente.insert(new_alocuente.end(), cnt, 0);
            alocuente = new_alocuente;  // Update the original vector
        }
    }

    return 0;
}

// <END-OF-CODE>
