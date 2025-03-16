import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Include the Scanner class for input operations
        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input from the standard input
        int x;
        // Declare an integer variable 'x' to store the input value
        x = scanner.nextInt();
        // Read an integer value from the standard input and store it in 'x'
        if (x >= 1200) 
            // Check if 'x' is greater than or equal to 1200
            System.out.println("ARC");
            // If the condition is true, print "ARC" to the standard output
        else 
            System.out.println("ABC");
            // Otherwise, print "ABC" to the standard output
        scanner.close();
        // Close the scanner to prevent resource leaks
    }
}
// Return 0 is implicit in Java's main method
// <END-OF-CODE>
