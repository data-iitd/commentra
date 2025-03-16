
import java.util.Arrays ; // Importing the Arrays class for sorting arrays
import java.util.Scanner ; // Importing the Scanner class for reading input

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String [ ] args ) {
        Scanner in = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream
        int n = in.nextInt ( ) ; // Reading the number of elements in the array from the user input
        int [ ] a = new int [ n ] ; // Creating an integer array of size n

        // Initializing the array with user input
        for ( int i = 0 ; i < n ; i ++ ) {
            a [ i ] = in.nextInt ( ) ; // Reading an integer value from the user input and storing it in the array at the current index
        }

        Arrays.sort ( a ) ; // Sorting the array in ascending order using the Arrays.sort() method

        int min = a [ 0 ] ; // Assigning the minimum value in the array to the min variable

        // Checking if all the elements in the array are multiples of the minimum value
        for ( int value : a ) {
            if ( value % min != 0 ) { // Checking if the current element is not a multiple of the minimum value
                System.out.println ( - 1 ) ; // Printing -1 if any non-multiple of the minimum value is found
                return ; // Exiting the method if any non-multiple of the minimum value is found
            }
        }

        // Printing the minimum value if all elements are multiples of the minimum value
        System.out.println ( min ) ;
    }
}