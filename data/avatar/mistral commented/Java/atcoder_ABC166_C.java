
import java.util.* ; // Importing the utility class Scanner

public class Main { // Defining the main class

    public static void main ( String [ ] args ) { // Starting the main method
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input

        int N = sc.nextInt ( ) ; // Reading the number of elements in the array H
        long M = sc.nextLong ( ) ; // Reading the number of queries

        long [ ] H = new long [ N ] ; // Creating an array of size N to store the heights
        boolean [ ] ans = new boolean [ N ] ; // Creating a boolean array of size N to store the answer for each index

        for ( int i = 0 ; i < N ; i ++ ) { // Reading the elements of the array H
            H [ i ] = sc.nextLong ( ) ;
            ans [ i ] = true ; // Initially assuming that all elements are in the left half
        }

        for ( int query = 0 ; query < M ; query ++ ) { // Processing each query
            int temp1 = sc.nextInt ( ) ; // Reading the first index
            int temp2 = sc.nextInt ( ) ; // Reading the second index

            if ( H [ temp1 - 1 ] < H [ temp2 - 1 ] ) { // If the height of the first index is less than the second index
                ans [ temp1 - 1 ] = false ; // The first index cannot be in the left half
            } else if ( H [ temp1 - 1 ] > H [ temp2 - 1 ] ) { // If the height of the first index is greater than the second index
                ans [ temp2 - 1 ] = false ; // The second index cannot be in the left half
            } else { // If the heights are equal
                ans [ temp1 - 1 ] = false ; // Both the first and second indices cannot be in the left half
                ans [ temp2 - 1 ] = false ;
            }
        }

        int ans2 = 0 ; // Initializing a counter to store the number of elements in the left half
        for ( int i = 0 ; i < N ; i ++ ) { // Iterating through the array to find the number of elements in the left half
            if ( ans [ i ] ) { // If an element is still assumed to be in the left half
                ans2 ++ ; // Increment the counter
            }
        }

        System.out.println ( ans2 ) ; // Printing the final answer
    }
}

