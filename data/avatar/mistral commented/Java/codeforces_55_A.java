
import java.util.* ;  // Importing necessary Java utility packages
import java.lang.* ;  // Importing necessary Java language packages
import java.io.* ;   // Importing necessary Java I/O packages

public class Main {

    public static void main ( String [ ] args ) {
        Scanner scan = new Scanner ( System.in ) ;  // Creating a Scanner object to read input from the standard input stream

        int n , i = 1 , k = 0 , p = 1 ;  // Declaring and initializing variables
        boolean flag = true ;
        int [ ] a = new int [ 1000 ] ;  // Declaring and initializing an integer array of size 1000

        n = scan.nextInt ( ) ;  // Reading the first integer from the standard input stream and assigning it to the variable 'n'

        i = 1 ;  // Initializing the variable 'i' to 1
        k = 0 ;  // Initializing the variable 'k' to 0
        p = 1 ;  // Initializing the variable 'p' to 1
        flag = true ;  // Initializing the boolean variable 'flag' to true

        while ( k <= n ) {  // Starting a while loop that runs as long as 'k' is less than or equal to 'n'
            i += k ;  // Incrementing the variable 'i' by the value of 'k'

            if ( i >= n ) {  // Checking if the value of 'i' is greater than or equal to 'n'
                while ( i >= n ) i = i - n ;  // If yes, then decrement 'i' by 'n' until it becomes less than 'n'
            }

            ++ a [ i ] ;  // Incrementing the value of the 'i'-th element of the array 'a' by 1
            ++ k ;  // Incrementing the variable 'k' by 1
        }

        for ( i=0 ; i<n ; ++i ) {  // Starting a for loop that runs from 0 to 'n'-1
            if ( a [ i ] == 0 ) {  // Checking if the 'i'-th element of the array 'a' is equal to 0
                flag = false ;  // If yes, then set the boolean variable 'flag' to false
                break ;  // Exiting the for loop
            }
        }

        if ( flag ) System.out.println ( "YES" ) ;  // If the boolean variable 'flag' is still true after the for loop, then print "YES" to the standard output stream
        else System.out.println ( "NO" ) ;  // Otherwise, print "NO" to the standard output stream

        scan.close ( ) ;  // Closing the Scanner object to free up system resources
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further clarification.