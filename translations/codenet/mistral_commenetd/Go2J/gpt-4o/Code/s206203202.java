// Importing the Scanner class for input
import java.util.Scanner;

public class Main {
    
    // Method to return the absolute value of an integer
    public static int abs(int x) {
        if (x < 0) {
            // If the input integer is negative, return its negation
            return -x;
        }
        // Otherwise, return the input integer as it is
        return x;
    }

    // Method to return the minimum of two integers
    public static int min(int a, int b) {
        if (a > b) {
            // If the first integer is greater than the second, return the second
            return b;
        }
        // Otherwise, return the first integer
        return a;
    }

    // Main method is the entry point of the program
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Declare and initialize two integer variables, N and K, using scanner
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Declare and initialize an integer variable, x, with the value of N modulo K
        int x = N % K;
        
        // Call the abs method to get the absolute value of x if it's negative
        x = abs(x);
        
        // Call the min method to find the minimum between x and abs(x-K)
        x = min(abs(x - K), x);
        
        // Print the result
        System.out.println(x);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
