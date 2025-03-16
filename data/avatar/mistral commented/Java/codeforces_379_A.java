
import java.util.Scanner ; // Import the Scanner class for reading input

public class Main {
    public static void main ( String [ ] args ) { // Entry point of the program
        Scanner scan = new Scanner ( System.in ) ; // Create a new Scanner object to read input
        
        int a = scan.nextInt ( ) ; // Read the first integer value from user input
        int b = scan.nextInt ( ) ; // Read the second integer value from user input
        
        int res = a ; // Initialize the result variable with the value of 'a'
        
        while ( a >= b ) { // Start a while loop that continues as long as 'a' is greater than or equal to 'b'
            res += ( a / b ) ; // Increment the result variable by the result of dividing 'a' by 'b'
            
            a = ( a / b ) + ( a % b ) ; // Update the value of 'a' with the result of the division and the remainder
        }
        
        System.out.println ( res ) ; // Print the value of the result variable to the standard output stream