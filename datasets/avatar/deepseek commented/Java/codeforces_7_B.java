import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner s = new Scanner ( System.in ) ; 
        int t = s.nextInt ( ) ; // Step 1: Read the number of test cases (t) from the input.
        int m = s.nextInt ( ) ; // Step 1: Read the size of memory (m) from the input.
        int [ ] memory = new int [ m ] ; // Step 2: Initialize an array to keep track of memory allocation.
        int allocIdx = 0 ; // Initialize the allocation index.
        
        for ( int j = 0 ; j < t ; j ++ ) { // Step 3: Loop through each test case.
            switch ( s.next ( ) ) { // Step 4: Read the command and perform the corresponding action.
                case "alloc" : 
                    int n = s.nextInt ( ) ; // Step 5: Read the size of memory block to allocate.
                    int len = 0 ; // Initialize the length counter.
                    boolean canAlloc = false ; // Flag to check if allocation is possible.
                    
                    for ( int i = 0 ; i < m ; i ++ ) { // Iterate through memory to find a suitable block.
                        if ( memory [ i ] == 0 ) len ++ ; // Increment length if current block is free.
                        else len = 0 ; // Reset length if current block is allocated.
                        
                        if ( len == n ) { // Check if a block of size n is found.
                            canAlloc = true ; // Set flag to true.
                            len = i - n + 1 ; // Set the starting index of the block.
                            break ; // Exit the loop as block is found.
                        }
                    }
                    
                    if ( canAlloc ) { // Step 5: If allocation is possible.
                        allocIdx ++ ; // Increment the allocation index.
                        for ( int i = len ; i < len + n ; i ++ ) memory [ i ] = allocIdx ; // Allocate the block.
                        System.out.println ( allocIdx ) ; // Print the allocation index.
                    } else System.out.println ( "NULL" ) ; // Step 5: If allocation is not possible, print "NULL".
                    break ;
                
                case "erase" : 
                    int x = s.nextInt ( ) ; // Step 6: Read the index of the block to erase.
                    if ( x <= 0 ) { // Check if the index is valid.
                        System.out.println ( "ILLEGAL_ERASE_ARGUMENT" ) ; // Print error message if index is invalid.
                        break ;
                    }
                    boolean hasErased = false ; // Flag to check if any block is erased.
                    
                    for ( int i = 0 ; i < m ; i ++ ) { // Iterate through memory to find the block to erase.
                        if ( memory [ i ] == x ) { // Check if the block matches the index.
                            memory [ i ] = 0 ; // Erase the block.
                            hasErased = true ; // Set flag to true.
                        }
                    }
                    
                    if ( ! hasErased ) System.out.println ( "ILLEGAL_ERASE_ARGUMENT" ) ; // Step 6: If no block is erased, print error message.
                    break ;
                
                case "defragment" : 
                    int d = 0 ; // Initialize the defragmentation index.
                    for ( int i = 0 ; i < m ; i ++ ) { // Iterate through memory to defragment.
                        if ( memory [ i ] == 0 ) d ++ ; // Increment defragmentation index if current block is free.
                        else memory [ i - d ] = memory [ i ] ; // Shift the block to the left.
                    }
                    for ( int i = m - d ; i < m ; i ++ ) memory [ i ] = 0 ; // Fill the remaining space with zeros.
                    break ; // Step 7: Defragment the memory.
                
                default : 
                    System.out.println ( "h" ) ; // Step 8: If the command is unknown, print "h".
                    break ;
            }
        }
        s.close ( ) ; // Step 9: Close the scanner.
    }
}
