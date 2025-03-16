import java.util.Scanner ; // Importing Scanner class for user input

public class Main { // Defining the main class
    public static void main ( String [ ] args ) { // Starting the main method
        try { // Starting a try block for handling exceptions
            Scanner scanner = new Scanner ( System.in ) ; // Creating a new Scanner object for user input
            long n = scanner.nextLong ( ) ; // Reading a long integer value from user input

            // Calculating the square root of the given number
            int sqrt = ( int ) Math.sqrt ( n ) ;

            // Initializing the answer variable to 0
            int answer = 0 ;

            // Checking for prime factors of the given number
            for ( int i = 2 ; i <= sqrt ; i ++ ) { // Starting a for loop to check for prime factors
                int count = 0 ; // Initializing a counter variable to count the number of occurrences of a prime factor
                while ( 0 == ( n % i ) ) { // Checking if the given number is divisible by the current prime factor
                    n /= i ; // Dividing the given number by the current prime factor
                    count ++ ; // Incrementing the counter variable
                }

                // Calculating the contribution of the current prime factor to the answer
                for ( int j = 1 ; count - j >= 0 ; j ++ ) {
                    count -= j ;
                    answer ++ ;
                }
            }

            // Checking for the remaining prime factor (if any)
            if ( n > 1 ) {
                answer ++ ;
            }

            // Printing the result
            System.out.println ( answer ) ;

        } catch ( Exception e ) { // Catching any exceptions that might occur during the execution
            System.out.println ( "Error: " + e.getMessage ( ) ) ;
        } finally { // Closing the Scanner object to save system resources
            scanner.close ( ) ;
        }
    }
}
