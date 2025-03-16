// Import the Scanner class for reading input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Declare and initialize two integer variables "a" and "b"
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Calculate the product of "a" and "b"
        int product = a * b;
        
        // Check if the product is even or odd using an if statement
        if (product % 2 == 0) {
            // If the product is even, print the message "Even" to the standard output
            System.out.println("Even");
        } else {
            // If the product is odd, print the message "Odd" to the standard output
            System.out.println("Odd");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
