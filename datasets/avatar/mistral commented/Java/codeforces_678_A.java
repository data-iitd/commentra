
import java.util.Scanner ; // Import the Scanner class for reading input

public class Main {
    public static void main ( String [ ] args ) { // Entry point of the program
        Scanner scan = new Scanner ( System.in ) ; // Create a new Scanner object to read input
        int n = scan.nextInt ( ) ; // Read the first integer `n` from the standard input
        int k = scan.nextInt ( ) ; // Read the second integer `k` from the standard input
        n ++ ; // Increment the value of `n` by 1
        int z = 0 ; // Initialize an integer variable `z` to 0
        if ( n % k != 0 ) { // Check if the remainder of `n` divided by `k` is equal to 0
            z = k - n % k ; // If the remainder is not equal to 0, calculate the difference between `k` and the remainder and assign it to `z`
        }
        System.out.println ( n + z ) ; // Print the value of `n` plus the value of `z`
    }
}