
import java.util.Arrays ; // Importing the Arrays class for sorting the array
import java.util.Scanner ; // Importing the Scanner class for reading input

public class Main {

    public static void main ( String [ ] args ) { // Main method to start the program
        Scanner in = new Scanner ( System.in ) ; // Creating a new Scanner object to read input
        int n = in.nextInt ( ) ; // Reading the number of elements in the array from the user

        // Allocating memory for the array and initializing it with user input
        Long [ ] ans = new Long [ n ] ;
        for ( int i = 0 ; i < n ; i ++ ) {
            ans [ i ] = in.nextLong ( ) ; // Reading each element of the array one by one
        }

        // Sorting the array in ascending order
        Arrays.sort ( ans ) ;

        // Initializing a variable to keep track of the count
        Long count = ans [ n - 1 ] ; // The last element of the sorted array is the maximum element

        // Iterating through the array from the second last element to the first
        for ( int i = n - 2 ; i >= 0 ; i -- ) {
            // If the current element is less than the next element, add it to the count
            if ( ans [ i ] < ans [ i + 1 ] ) {
                count += ans [ i ] ;
            } else { // If the current element is greater than or equal to the next element
                // Decrement the current element until it becomes less than the next element
                while ( ans [ i ] >= ans [ i + 1 ] ) {
                    ans [ i ] -- ;
                }

                // If the current element is still greater than or equal to the next element, add it to the count
                if ( ans [ i ] > 0 ) {
                    count += ans [ i ] ;
                }
            }
        }

        // Printing the final count
        System.out.println ( count ) ;
    }
}