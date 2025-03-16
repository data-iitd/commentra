
import java.util.* ; // Importing the utility class Scanner

public class Main { // Defining the main class

    public static void main ( String [ ] args ) { // Starting the main method
        Scanner stdIn = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input
        int N = stdIn.nextInt ( ) ; // Reading the number of elements in the array from the standard input
        int [ ] A = new int [ N ] ; // Creating an integer array of size N

        // Reading the elements of the array from the standard input
        for ( int i = 0 ; i < N ; i ++ ) {
            A [ i ] = stdIn.nextInt ( ) ;
            // Comment: Reading the i-th element of the array from the standard input
        }

        int count = 0 ; // Initializing the count variable to zero

        // Iterating through the array to find the number of increasing and decreasing sequences
        for ( int i = 0 ; i < N - 1 ; i ++ ) { // Iterating up to the second last index of the array
            if ( i == N - 1 ) count ++ ; // If we have reached the last index, increment the count
            else if ( A [ i ] == A [ i + 1 ] ) ; // If the current and next elements are equal, do nothing
            else if ( A [ i ] < A [ i + 1 ] ) { // If the current element is less than the next element
                while ( A [ i ] <= A [ i + 1 ] ) { // Finding the length of the increasing sequence
                    i ++ ;
                    if ( i == N - 1 ) break ; // If we have reached the last index, break the loop
                }
                count ++ ; // Increment the count after finding the length of the increasing sequence
            } else { // If the current element is greater than the next element
                while ( A [ i ] >= A [ i + 1 ] ) { // Finding the length of the decreasing sequence
                    i ++ ;
                    if ( i == N - 1 ) break ; // If we have reached the last index, break the loop
                }
                count ++ ; // Increment the count after finding the length of the decreasing sequence
            }
        }

        System.out.println ( count ) ; // Printing the final count
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!