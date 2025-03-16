
// Import the "java.util.Scanner" class for input
import java.util.Scanner;

public class s824543330{
    public static void main(String[] args) {
        // Create a new instance of the Scanner class to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter two integer values and store them in variables a and b
        System.out.print("Enter the first integer: ");
        int a = scanner.nextInt();
        System.out.print("Enter the second integer: ");
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

        // Close the Scanner object to release system resources
        scanner.close();
    }
}

// End of code