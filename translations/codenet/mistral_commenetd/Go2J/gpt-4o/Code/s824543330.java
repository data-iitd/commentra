// Import the Scanner class for input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Declare and initialize two integer variables, a and b, using scanner.nextInt()
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Check if the product of a and b is even using the modulo operator (%).
        // If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
        if (a * b % 2 == 0) {
            // If the condition is true, print the message "Even"
            System.out.println("Even");
        } else {
            // If the condition is false, print the message "Odd"
            System.out.println("Odd");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
