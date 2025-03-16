
import java.util.Arrays ;  // Importing Arrays and Scanner classes
import java.util.Scanner ;

public class Main {
    // Creating a Scanner object for reading input from the console
    public static Scanner input = new Scanner ( System.in ) ;

    public static void main ( String [ ] args ) {
        // Reading the first two integers from the input
        int n = input.nextInt ( ) ;
        int m = input.nextInt ( ) ;

        // Creating an integer array 'a' of size 'm'
        int a [ ] = new int [ m ] ;

        // Checking if 'n' is divisible by 'm'
        if ( n % m == 0 ) {
            // If 'n' is divisible by 'm', then 'n' can be divided evenly by 'm'
            // So, all elements of 'a' will be equal to the quotient of 'n' and 'm'
            for ( int i = 0 ; i < a.length ; i ++ ) {
                a [ i ] = n / m ; // Assigning the quotient to each element of 'a'
            }
        } else {
            // If 'n' is not divisible by 'm', then 'n' can't be divided evenly by 'm'
            // So, we need to calculate the quotient 'sub' and the remainder 'test' of 'n' by 'm'
            int sub = n / m ;

            // All elements of 'a' will be equal to 'sub', except for some elements at the end
            for ( int i = 0 ; i < a.length ; i ++ ) {
                a [ i ] = sub ; // Assigning 'sub' to each element of 'a'
            }

            // Calculating the number of extra elements needed at the end of 'a'
            int test = n - ( sub * m ) ;

            // Adding '1' to each extra element of 'a'
            int count = 0 ;
            for ( int i = 0 ; i < test ; i ++ ) {
                a [ count ] = a [ count ] + 1 ; // Incrementing the value of each extra element by '1'
                count ++ ;

                // If we reach the end of 'a', then we reset the index to '0'
                if ( count > a.length ) count = 0 ;
            }
        }

        // Printing the elements of 'a' in reverse order
        for ( int i = a.length - 1 ; i >= 0 ; i -- ) {
            System.out.print ( a [ i ] + " " ) ;
        }
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further clarification!