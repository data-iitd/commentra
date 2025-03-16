import java.util.* ;  // Importing the utility package for collections and I/O operations
import java.io.* ;    // Importing the I/O package for file handling

public class Main {
    // Main method is the entry point of the program
    public static void main ( String args [ ] ) throws IOException {
        Scanner sc = new Scanner ( System.in ) ;  // Creating a Scanner object to read input from the console
        int n = sc.nextInt ( ) ;                // Reading the number of elements in the array from the input
        int arr [ ] = new int [ n ] ;             // Creating an integer array of size n
        arr [ 0 ] = sc.nextInt ( ) ;             // Reading the first element of the array from the input

        // Initializing a for loop to read and store the remaining elements of the array
        for ( int i = 1 ; i < n ; i ++ ) {
            int x = sc.nextInt ( ) ;            // Reading an element from the input
            arr [ i ] = x + arr [ i - 1 ] ;       // Assigning the current element the sum of the previous element and the current input
        }

        int m = sc.nextInt ( ) ;                // Reading the number of queries from the input
        int q [ ] = new int [ m ] ;              // Creating an integer array of size m to store the queries

        // Initializing a for loop to read and store the queries in the array q
        for ( int i = 0 ; i < m ; i ++ ) {
            q [ i ] = sc.nextInt ( ) ;          // Reading a query from the input
        }

        // Initializing a for loop to process each query and print the result
        for ( int k = 0 ; k < m ; k ++ ) {
            System.out.println ( fun ( arr , q [ k ] , n , m ) + 1 ) ; // Calling the fun function with the array, query, size of the array, and number of queries as arguments and printing the result with an offset of 1
        }
    }

    // fun function takes an array, a query, the size of the array, and the number of queries as arguments
    static int fun ( int arr [ ] , int q , int n , int m ) {
        int res = 0 ;                          // Initializing a variable to store the result
        int i = 0 , j = n ;                     // Initializing two variables to represent the left and right indices of the array

        // Using a while loop to perform a binary search on the array
        while ( i <= j ) {
            int md = i + ( j - i ) / 2 ;        // Calculating the middle index of the subarray
            if ( arr [ md ] == q ) {             // If the middle element is equal to the query, return the middle index
                return md ;
            } else if ( arr [ md ] > q ) {       // If the middle element is greater than the query, update the result and shift the right index towards the left
                res = md ;
                j = md - 1 ;
            } else {                           // If the middle element is less than the query, shift the left index towards the right
                i = md + 1 ;
            }
        }

        // If the query is not present in the array, return the index where it should be inserted
        return res ;
    }
}
