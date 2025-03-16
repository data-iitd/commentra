/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/

// Import necessary packages
import java.util.Scanner;

// Define the main class
public class Main {
    
    // Function to solve the problem
    private static void solve(Scanner scanner) {
        long n = scanner.nextLong(); // Read input value for n
        System.out.println(n == 0 ? 1 : 0); // Output the negation of n (0 if n is non-zero, 1 if n is zero)
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        long n = 1; // Initialize n to 1 (can be modified to read input)
        while (n-- > 0) solve(scanner); // Call the solve function n times
        scanner.close(); // Close the scanner
    }
}

/*<END-OF-CODE>*/
