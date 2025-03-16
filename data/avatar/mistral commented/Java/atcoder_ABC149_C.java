// Importing necessary libraries
import java.util.Scanner ; 
import java.lang.Math ;

// Main method is the entry point of the Java application
public class Main {
    // Declaring the main method that takes String array as an argument
    public static void main ( String [ ] args ) {
        // Creating a Scanner object to read input from the standard input
        Scanner stdIn = new Scanner ( System.in ) ;

        // Reading an integer input from the user
        int x = Integer.parseInt ( stdIn.next ( ) ) ;

        // Checking if the number is even and not equal to 2
        if ( x != 2 && x % 2 == 0 )
            x ++ ;  // Increment the number if it's even and not 2

        // Starting an infinite loop
        while ( true ) {
            int i ;  // Declaring an integer variable 'i'
            double sqrtNum = Math.sqrt ( x ) ; // Calculating the square root of the number 'x'

            // Checking for prime numbers using trial division method
            for ( i = 3 ; i <= sqrtNum ; i += 2 ) {
                if ( x % i == 0 ) // Checking if the number 'x' is divisible by 'i'
                    break ; // If it's divisible, then 'i' is a factor and the loop is broken
            }

            // If 'i' is greater than the square root, then the number 'x' is prime
            if ( i > sqrtNum )
                break ; // Exiting the loop

            // If the loop didn't break, then the number 'x' is not prime, so we need to find the next prime number
            x += 2 ; // Incrementing the number by 2 to check the next odd number
        }

        // Printing the prime number found
        System.out.println ( x ) ;
    }
}
