#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays
#include <string>   // Including the string library for string manipulation

using namespace std; // Using the standard namespace

int main() { // Starting the main function
    int t; // Variable to store the number of test cases
    cin >> t; // Reading the number of test cases
    int m; // Variable to store the size of the memory
    cin >> m; // Reading the size of the memory
    vector<int> memory(m, 0); // Initializing a vector of size m to represent the memory, filled with 0
    int allocIdx = 0; // Initializing a counter for allocated memory blocks

    for (int j = 0; j < t; j++) { // Loop through each test case
        string command; // Variable to store the command
        cin >> command; // Reading the command
        if (command == "alloc") { // Allocate command
            int n; // Variable to store the size of the block to be allocated
            cin >> n; // Reading the size of the block to be allocated
            int len = 0; // Initializing a counter for free memory blocks
            bool canAlloc = false; // Flag to check if allocation is possible
            for (int i = 0; i < m; i++) { // Loop through the memory vector
                if (memory[i] == 0) { // If the current block is free
                    len++; // Increment the counter
                } else { // If the current block is allocated
                    len = 0; // Reset the counter
                }
                if (len == n) { // If the free memory blocks form a block of size n
                    canAlloc = true; // Set the flag
                    len = i - n + 1; // Calculate the start index of the block
                    break; // Exit the loop
                }
            }
            if (canAlloc) { // If allocation is possible
                allocIdx++; // Increment the counter for allocated blocks
                for (int i = len; i < len + n; i++) // Allocate the block in the memory
                    memory[i] = allocIdx;
                cout << allocIdx << endl; // Print the allocated block number
            } else { // If allocation is not possible
                cout << "NULL" << endl; // Print NULL
            }
        } else if (command == "erase") { // Erase command
            int x; // Variable to store the block number to be erased
            cin >> x; // Reading the block number to be erased
            if (x <= 0) { // If the block number is invalid
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl; // Print an error message
                continue; // Skip to the next iteration
            }
            bool hasErased = false; // Flag to check if the block has been erased
            for (int i = 0; i < m; i++) { // Loop through the memory vector
                if (memory[i] == x) { // If the current block matches the given block number
                    memory[i] = 0; // Erase the block
                    hasErased = true; // Set the flag
                }
            }
            if (!hasErased) { // If the block was not found
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl; // Print an error message
            }
        } else if (command == "defragment") { // Defragment command
            int d = 0; // Initializing a counter for free memory blocks
            for (int i = 0; i < m; i++) { // Loop through the memory vector
                if (memory[i] == 0) { // If the current block is free
                    d++; // Increment the counter
                }
            }
            int newSize = m - d; // Calculate the new size of the memory vector
            vector<int> newMemory(newSize); // Create a new memory vector of the new size
            int k = 0; // Initialize a counter for copying elements to the new vector
            for (int i = 0; i < m; i++) { // Loop through the old memory vector
                if (memory[i] != 0) { // If the current block is allocated
                    newMemory[k] = memory[i]; // Copy the block to the new vector
                    k++; // Increment the counter
                }
            }
            memory = newMemory; // Update the memory vector with the new one
        } else { // Invalid command
            cout << "h" << endl; // Print an error message
        }
    }
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
