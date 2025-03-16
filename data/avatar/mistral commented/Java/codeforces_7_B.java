
import java.util.* ; // Importing the utility class Scanner

public class Main { // Defining the main class

    public static void main ( String [ ] args ) { // Starting the main method
        Scanner s = new Scanner ( System.in ) ; // Creating a new Scanner object to read input
        int t = s.nextInt ( ) ; // Reading the number of test cases
        int m = s.nextInt ( ) ; // Reading the size of the memory
        int [ ] memory = new int [ m ] ; // Initializing an integer array of size m to represent the memory
        int allocIdx = 0 ; // Initializing a counter for allocated memory blocks

        for ( int j = 0 ; j < t ; j ++ ) { // Loop through each test case
            switch ( s.next ( ) ) { // Reading the command
                case "alloc" : // Allocate command
                    int n = s.nextInt ( ) ; // Reading the size of the block to be allocated
                    int len = 0 ; // Initializing a counter for free memory blocks
                    boolean canAlloc = false ; // Flag to check if allocation is possible
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
                        System.out.println ( allocIdx ) ; // Print the allocated block number
                    } else { // If allocation is not possible
                        System.out.println ( "NULL" ) ; // Print NULL
                    }
                    break ;
                case "erase" : // Erase command
                    int x = s.nextInt ( ) ; // Reading the block number to be erased
                    if ( x <= 0 ) { // If the block number is invalid
                        System.out.println ( "ILLEGAL_ERASE_ARGUMENT" ) ; // Print an error message
                        break ;
                    }
                    boolean hasErased = false ; // Flag to check if the block has been erased
                    for ( int i = 0 ; i < m ; i ++ ) { // Loop through the memory array
                        if ( memory [ i ] == x ) { // If the current block matches the given block number
                            memory [ i ] = 0 ; // Erase the block
                            hasErased = true ; // Set the flag
                        }
                    }
                    if ( ! hasErased ) { // If the block was not found
                        System.out.println ( "ILLEGAL_ERASE_ARGUMENT" ) ; // Print an error message
                    }
                    break ;
                case "defragment" : // Defragment command
                    int d = 0 ; // Initializing a counter for free memory blocks
                    for ( int i = 0 ; i < m ; i ++ ) { // Loop through the memory array
                        if ( memory [ i ] == 0 ) { // If the current block is free
                            d ++ ; // Increment the counter
                        }
                    }
                    int newSize = m - d ; // Calculate the new size of the memory array
                    int [ ] newMemory = new int [ newSize ] ; // Create a new memory array of the new size
                    int k = 0 ; // Initialize a counter for copying elements to the new array
                    for ( int i = 0 ; i < m ; i ++ ) { // Loop through the old memory array
                        if ( memory [ i ] != 0 ) { // If the current block is allocated
                            newMemory [ k ] = memory [ i ] ; // Copy the block to the new array
                            k ++ ; // Increment the counter
                        }
                    }
                    memory = newMemory ; // Update the memory array with the new one
                    break ;
                default : // Invalid command
                    System.out.println ( "h" ) ; // Print an error message
                    break ;
            }
        }
        s.close ( ) ; // Closing the Scanner object
    }
}

This code now includes comments explaining the purpose and functionality of each logical block.