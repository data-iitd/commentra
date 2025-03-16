import java.io.* ; // Import package for input/output
import java.util.* ; // Import package for collections

public class Main {

    // Define the main method, which is the entry point of the program
    public static void main ( String [ ] args ) {
        Scanner in = new Scanner ( System.in ) ; // Create a Scanner object to read input from the standard input
        PrintWriter pw = new PrintWriter ( System.out ) ; // Create a PrintWriter object to write output to the standard output

        int N = in.nextInt ( ) ; // Read the number of elements N from the standard input
        int [ ] A = new int [ N ] ; // Create an integer array A of size N to store the elements

        // Use a for loop to read each element from the standard input and store it in the corresponding index of the array A
        for ( int n = 0 ; n < N ; n ++ ) {
            A [ n ] = in.nextInt ( ) ;
        }

        // Use the Arrays.sort() method to sort the elements in the array A in ascending order
        Arrays.sort ( A ) ;

        // Initialize two variables, min and max, to store the minimum and maximum elements in the array A, respectively
        int min = A [ 0 ] ;
        int max = A [ N - 1 ] ;

        // Use a for-each loop to iterate through each element in the array A and perform some checks
        for ( int value : A ) {
            if ( value == min ) { // If the current element is equal to the minimum element min, increment the variable mins by 1
                mins ++ ;
            }
            if ( value == max ) { // If the current element is equal to the maximum element max, increment the variable maxs by 1
                maxs ++ ;
            }
        }

        // Check if the minimum and maximum elements are the same
        if ( min == max ) {
            long result = ( max - min ) + 1 ; // Calculate the difference between the minimum and maximum elements, plus 1
            result *= mins ; // Multiply the result by the number of occurrences of the minimum element
            result -= mins * ( mins - 1 ) / 2 ; // Subtract the number of combinations of pairs of minimum elements
            pw.println ( result ) ; // Print the output
        } else {
            long result = ( max - min ) ; // Calculate the difference between the minimum and maximum elements
            result *= mins ; // Multiply the result by the number of occurrences of the minimum element
            result *= maxs ; // Multiply the result by the number of occurrences of the maximum element
            pw.println ( result ) ; // Print the output
        }

        pw.close ( ) ; // Close the PrintWriter object to flush the output buffer and close the connection to the standard output
    }

    // Define a static debug method to print the contents of an array or other objects for debugging purposes
    static void debug ( Object...obj ) {
        System.err.println ( Arrays.deepToString ( obj ) ) ;
    }
}