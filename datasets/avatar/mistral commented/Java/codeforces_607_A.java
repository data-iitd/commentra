
import java.io.* ;  // Importing required Java classes for input and output
import java.util.* ;  // Importing required Java classes for Scanner and ArrayList

public class Main {

    public static void main ( String [ ] args ) {  // Main method starts the execution of Java program
        Scanner sc = new Scanner ( System.in ) ;  // Creating a new Scanner object for reading input from the console
        int max = 0 ;                            // Initializing max variable to store the maximum length of a subsequence
        int n = sc.nextInt ( ) ;                 // Reading the number of elements in the array from the console
        int [ ] beacon = new int [ 1000001 ] ;     // Creating an integer array of size 1000001 to store the indices of beacons
        int [ ] dp = new int [ 1000001 ] ;         // Creating an integer array of size 1000001 to store the length of the longest subsequence ending at each index

        for ( int i = 0 ; i < n ; i ++ ) {         // Loop to read the elements and their indices from the console
            int a = sc.nextInt ( ) ;             // Reading the element
            beacon [ a ] = sc.nextInt ( ) ;       // Storing the index of the beacon for the given element
        }

        if ( beacon [ 0 ] != 0 ) dp [ 0 ] = 1 ;     // If the first beacon exists, the length of the subsequence ending at index 0 is 1

        for ( int i = 1 ; i < 1000001 ; i ++ ) {  // Loop to calculate the length of the longest subsequence ending at each index
            if ( beacon [ i ] != 0 && beacon [ i ] < i ) {
                dp [ i ] = dp [ i - beacon [ i ] - 1 ] + 1 ;  // If the beacon exists and its index is less than the current index, update the length of the subsequence
            } else if ( beacon [ i ] != 0 ) {
                dp [ i ] = 1 ;                            // If the beacon exists but its index is greater than or equal to the current index, the length of the subsequence is 1
            } else {
                dp [ i ] = dp [ i - 1 ] ;                 // If there is no beacon, the length of the subsequence remains the same as the previous index
            }
            max = Math.max ( max , dp [ i ] ) ;          // Updating the maximum length of the subsequence
        }

        System.out.print ( n - max ) ;              // Printing the difference between the total number of elements and the maximum length of the subsequence
    }
}

These comments should provide a clear understanding of the logic behind each part of the code.