import java.util.Scanner;  // Import the Scanner class for user input
import java.lang.Math;     // Import the Math class for mathematical functions

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input

        // Read an integer input from the user
        int n = scanner.nextInt();

        // Initialize a counter variable to track the number of iterations
        int x = 1;

        // Continue looping while n is not a power of 2
        while (Math.log(n) / Math.log(2) % 1 != 0) {
            x++;  // Increment the counter for each iteration
            // Subtract the largest power of 2 less than or equal to n from n
            n -= (int) Math.pow(2, (int) (Math.log(n) / Math.log(2)));
        }

        // Print the final count of iterations
        System.out.println(x);
        
        scanner.close();  // Close the scanner
    }
}
// <END-OF-CODE>
