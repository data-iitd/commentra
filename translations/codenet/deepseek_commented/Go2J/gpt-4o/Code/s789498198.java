import java.util.Scanner;

public class Main {
    // Main function of the program
    public static void main(String[] args) {
        // Initialize the scanner for reading input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers A and B from standard input
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        // Check if the sum of A and B is even
        if ((A + B) % 2 == 0) {
            // If even, print the average of A and B
            System.out.println((A + B) / 2);
        } else {
            // If not even, print "IMPOSSIBLE"
            System.out.println("IMPOSSIBLE");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// Utility functions and classes can be added here if needed

// <END-OF-CODE>
