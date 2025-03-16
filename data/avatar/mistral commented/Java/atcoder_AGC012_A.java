
import java.util.* ;  // Importing the utility class Scanner and static imports from Math package
import static java.lang.Math.* ; // Importing static methods from Math package

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;  // Creating a new Scanner object to read input from the standard input
        int n = sc.nextInt ( ) ;  // Reading the number of elements in the array from the standard input
        int [ ] array = new int [ 3 * n ] ;  // Creating an integer array of size 3 times the number of elements

        // Initializing the array with input values
        for ( int i = 0 ; i < array.length ; i ++ )
            array [ i ] = sc.nextInt ( ) ;

        // Sorting the array in ascending order
        Arrays.sort ( array ) ;

        int head = array.length - 2 ;  // Index of the last element to be considered in the current iteration
        long res = 0 ;  // Result variable to store the sum of the last two elements in each subarray

        // Calculating the sum of the last two elements in each subarray of size n and adding it to the result
        for ( int i = 0 ; i < n ; i ++ ) {
            res += array [ head ] ;  // Adding the last element of the current subarray to the result
            head -= 2 ;  // Decreasing the index of the last element by 2 to consider the next subarray
        }

        // Printing the result
        System.out.println ( res ) ;
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!