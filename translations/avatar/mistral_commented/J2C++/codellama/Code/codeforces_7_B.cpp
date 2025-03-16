
#include <iostream>
#include <string>

using namespace std ;

int main ( ) {
    int t ; // Number of test cases
    int m ; // Size of the memory
    int allocIdx = 0 ; // Counter for allocated memory blocks
    int len ; // Counter for free memory blocks
    bool canAlloc ; // Flag to check if allocation is possible
    int n ; // Size of the block to be allocated
    int x ; // Block number to be erased
    bool hasErased ; // Flag to check if the block has been erased
    int d ; // Counter for free memory blocks
    int newSize ; // New size of the memory array
    int k ; // Counter for copying elements to the new array
    string command ; // Command to be executed

    cin >> t >> m ; // Reading the number of test cases and the size of the memory
    int memory [ m ] ; // Initializing an integer array of size m to represent the memory

    for ( int j = 0 ; j < t ; j ++ ) { // Loop through each test case
        cin >> command ; // Reading the command
        switch ( command ) { // Reading the command
            case "alloc" : // Allocate command
                cin >> n ; // Reading the size of the block to be allocated
                len = 0 ; // Initializing a counter for free memory blocks
                canAlloc = false ; // Flag to check if allocation is possible
                for ( int i = 0 ; i < m ; i ++ ) { // Loop through the memory array
                    if ( memory [ i ] == 0 ) { // If the current block is free
                        len ++ ; // Increment the counter
                    } else { // If the current block is allocated
                        len = 0 ; // Reset the counter
                    }
                    if ( len == n ) { // If the free memory blocks form a block of size n
                        canAlloc = true ; // Set the flag
                        len = i - n + 1 ; // Calculate the start index of the block
                        break ; // Exit the loop
                    }
                }
                if ( canAlloc ) { // If allocation is possible
                    allocIdx ++ ; // Increment the counter for allocated blocks
                    for ( int i = len ; i < len + n ; i ++ ) // Allocate the block in the memory
                        memory [ i ] = allocIdx ;
                    cout << allocIdx << endl ; // Print the allocated block number
                } else { // If allocation is not possible
                    cout << "NULL" << endl ; // Print NULL
                }
                break ;
            case "erase" : // Erase command
                cin >> x ; // Reading the block number to be erased
                if ( x <= 0 ) { // If the block number is invalid
                    cout << "ILLEGAL_ERASE_ARGUMENT" << endl ; // Print an error message
                    break ;
                }
                hasErased = false ; // Flag to check if the block has been erased
                for ( int i = 0 ; i < m ; i ++ ) { // Loop through the memory array
                    if ( memory [ i ] == x ) { // If the current block matches the given block number
                        memory [ i ] = 0 ; // Erase the block
                        hasErased = true ; // Set the flag
                    }
                }
                if ( ! hasErased ) { // If the block was not found
                    cout << "ILLEGAL_ERASE_ARGUMENT" << endl ; // Print an error message
                }
                break ;
            case "defragment" : // Defragment command
                d = 0 ; // Initializing a counter for free memory blocks
                for ( int i = 0 ; i < m ; i ++ ) { // Loop through the memory array
                    if ( memory [ i ] == 0 ) { // If the current block is free
                        d ++ ; // Increment the counter
                    }
                }
                newSize = m - d ; // Calculate the new size of the memory array
                int newMemory [ newSize ] ; // Create a new memory array of the new size
                k = 0 ; // Initialize a counter for copying elements to the new array
                for ( int i = 0 ; i < m ; i ++ ) { // Loop through the old memory array
                    if ( memory [ i ] != 0 ) { // If the current block is allocated
                        newMemory [ k ] = memory [ i ] ; // Copy the block to the new array
                        k ++ ; // Increment the counter
                    }
                }
                memory = newMemory ; // Update the memory array with the new one
                break ;
            default : // Invalid command
                cout << "h" << endl ; // Print an error message
                break ;
        }
    }
    return 0 ;
}

