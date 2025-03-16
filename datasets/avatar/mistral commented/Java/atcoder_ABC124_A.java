import java.util.Scanner ;  // Import Scanner class for reading input

public class Main {
    public static void main ( String [ ] args ) {  // Entry point of the Java application
        Scanner sc = new Scanner ( System.in ) ;  // Create a new Scanner object to read input from standard input

        int a = Integer.parseInt ( sc.next ( ) ) ;  // Read the first integer from standard input and convert it to an integer
        int b = Integer.parseInt ( sc.next ( ) ) ;  // Read the second integer from standard input and convert it to an integer

        int sum = 0 ;  // Initialize sum variable to 0

        for ( int i = 0 ; i < 2 ; i ++ ) {  // Iterate through two iterations
            if ( a >= b ) {  // Check if a is greater than or equal to b
                sum += a ;  // Add a to sum and decrement a by 1
                a-- ;  // Decrement a by 1
            } else {
                sum += b ;  // Add b to sum and decrement b by 1
                b-- ;  // Decrement b by 1
            }
        }

        System.out.println ( sum ) ;  // Print the value of sum to standard output
    }
}
