
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner scan = new Scanner ( System.in ) ; // Initialize Scanner object to read user input
        int a = scan.nextInt ( ) ; // Read the first integer input
        int b = scan.nextInt ( ) ; // Read the second integer input
        int res = a ; // Initialize result variable with the value of a

        // Enter a while loop that continues as long as a is greater than or equal to b
        while ( a >= b ) { 
            res += ( a / b ) ; // Update result by adding the integer division of a by b
            a = ( a / b ) + ( a % b ) ; // Update a to be the sum of the integer division and remainder
        } 

        System.out.println ( res ) ; // Print the final value of res
    } 
}

