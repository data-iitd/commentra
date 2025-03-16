import java.util.Scanner ; // Import the Scanner class for reading input

public class Main {
    public static void main ( String [ ] args ) { // Entry point of the program
        Scanner sc = new Scanner ( System.in ) ; // Create a new Scanner object to read input
        int t ; // Read the number of test cases from the standard input

        // Initialize a counter variable to keep track of the number of valid cases
        int count = 0 ;

        // Read the number of test cases and process each one in the while loop
        while ( t -- > 0 ) {
            int a = sc.nextInt ( ) ; // Read the first integer from the standard input
            int b = sc.nextInt ( ) ; // Read the second integer from the standard input
            int c = sc.nextInt ( ) ; // Read the third integer from the standard input

            // Check if any of the given integers are equal to 1. If so, increment the counter.
            if ( ( a == 1 && b == 1 ) || ( a == 1 && c == 1 ) || ( b == 1 && c == 1 ) || ( a == 1 && b == 1 && c == 1 ) ) {
                count ++ ; // Increment the counter if any of the given integers are equal to 1
            }
        }

        // Print the value of the counter to the standard output
        System.out.println ( count ) ;
    }
}