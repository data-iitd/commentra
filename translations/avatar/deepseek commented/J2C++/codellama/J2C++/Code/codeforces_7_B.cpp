#include <iostream> 
#include <cstring> 

using namespace std ; 

int main ( ) { 
    int t , m ; // Step 1: Read the number of test cases (t) and the size of memory (m) from the input.
    cin >> t >> m ; 
    int memory [ m ] ; // Step 2: Initialize an array to keep track of memory allocation.
    int allocIdx = 0 ; // Initialize the allocation index.
    
    for ( int j = 0 ; j < t ; j ++ ) { // Step 3: Loop through each test case.
        string command ; // Step 4: Read the command from the input.
        cin >> command ; 
        
        switch ( command [ 0 ] ) { // Step 5: Perform the corresponding action based on the command.
            case 'a' : 
                int n ; // Step 6: Read the size of memory block to allocate.
                cin >> n ; 
                int len = 0 ; // Initialize the length counter.
                bool canAlloc = false ; // Flag to check if allocation is possible.
                
                for ( int i = 0 ; i < m ; i ++ ) { // Iterate through memory to find a suitable block.
                    if ( memory [ i ] == 0 ) len ++ ; // Increment length if current block is free.
                    else len = 0 ; // Reset length if current block is allocated.
                    
                    if ( len == n ) { // Check if a block of size n is found.
                        canAlloc = true ; // Set flag to true.
                        len = i - n + 1 ; // Set the starting index of the block.
                        break ; // Exit the loop as block is found.
                    }
                }
                
                if ( canAlloc ) { // Step 6: If allocation is possible.
                    allocIdx ++ ; // Increment the allocation index.
                    for ( int i = len ; i < len + n ; i ++ ) memory [ i ] = allocIdx ; // Allocate the block.
                    cout << allocIdx << endl ; // Print the allocation index.
                } else cout << "NULL" << endl ; // Step 6: If allocation is not possible, print "NULL".
                break ;
                
            case 'e' : 
                int x ; // Step 7: Read the index of the block to erase.
                cin >> x ; 
                if ( x <= 0 ) { // Check if the index is valid.
                    cout << "ILLEGAL_ERASE_ARGUMENT" << endl ; // Print error message if index is invalid.
                    break ;
                }
                bool hasErased = false ; // Flag to check if any block is erased.
                
                for ( int i = 0 ; i < m ; i ++ ) { // Iterate through memory to find the block to erase.
                    if ( memory [ i ] == x ) { // Check if the block matches the index.
                        memory [ i ] = 0 ; // Erase the block.
                        hasErased = true ; // Set flag to true.
                    }
                }
                
                if ( ! hasErased ) cout << "ILLEGAL_ERASE_ARGUMENT" << endl ; // Step 7: If no block is erased, print error message.
                break ;
                
            case 'd' : 
                int d = 0 ; // Initialize the defragmentation index.
                for ( int i = 0 ; i < m ; i ++ ) { // Iterate through memory to defragment.
                    if ( memory [ i ] == 0 ) d ++ ; // Increment defragmentation index if current block is free.
                    else memory [ i - d ] = memory [ i ] ; // Shift the block to the left.
                }
                for ( int i = m - d ; i < m ; i ++ ) memory [ i ] = 0 ; // Fill the remaining space with zeros.
                break ; // Step 8: Defragment the memory.
                
            default : 
                cout << "h" << endl ; // Step 9: If the command is unknown, print "h".
                break ;
        }
    }
    return 0 ; // Step 10: Return 0.
}

