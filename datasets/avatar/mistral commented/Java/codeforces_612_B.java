// Importing the Scanner class for reading input from the console
import java.util.Scanner ;

// Defining the main method as the entry point of the program
public class Main {
    // Declaring the main method that takes an array of strings as arguments
    public static void main ( String args [ ] ) {
        // Creating a new Scanner object to read input from the console
        Scanner s = new Scanner ( System.in ) ;

        // Reading the number of test cases
        int n = s.nextInt ( ) ;

        // Declaring an integer array dp of size 200001 to store the position of each number in the sequence
        int dp [ ] = new int [ 200001 ] ;

        // Initializing a long variable ans to store the answer
        long ans = 0 ;

        // Iterating through each test case
        for ( int i = 0 ; i < n ; i ++ ) {
            // Reading the next number to be added to the sequence
            int num = s.nextInt ( ) ;

            // Storing the position of the number in the dp array
            dp [ num ] = i ;
        }

        // Calculating the answer by iterating through the dp array and finding the absolute difference between the positions of consecutive numbers
        for ( int i = 2 ; i <= n ; i ++ ) {
            // Adding the absolute difference to the answer
            ans += Math.abs ( dp [ i ] - dp [ i - 1 ] ) ;
        }

        // Printing the answer to the console
        System.out.println ( ans ) ;
    }
}