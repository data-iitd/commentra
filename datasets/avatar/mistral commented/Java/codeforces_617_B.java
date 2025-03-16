import java.util.* ;  // Importing the Java Util Library for Scanner class

public class Main {   // Defining the Main class
    static Scanner input = new Scanner ( System.in ) ;  // Creating a new Scanner object to read input from the console

    public static void main ( String [ ] args ) {   // Defining the main method
        int n = input.nextInt ( ) ;  // Reading the first integer from the input as the size of the array

        List < Integer > arr = new ArrayList < > ( ) ;  // Creating an empty ArrayList to store the indices of the 1's in the input

        for ( int i = 0 ; i < n ; i ++ ) {   // Loop through the input to find the indices of the 1's
            if ( input.nextInt ( ) == 1 )
                arr.add ( i ) ;  // If the current input is 1, add its index to the ArrayList
        }

        if ( arr.isEmpty ( ) ) {   // Check if the ArrayList is empty
            System.out.println ( 0 ) ;  // If it is, print 0 as the output
        } else {
            long result = 1 ;  // Initialize the result variable to 1

            for ( int i = 1 ; i < arr.size ( ) ; i ++ ) {  // Loop through the ArrayList to calculate the result
                result *= arr.get ( i ) - arr.get ( i - 1 ) ;  // Multiply the difference between two consecutive indices to the result
            }

            System.out.println ( result ) ;  // Print the result as the output
        }
    }
}
