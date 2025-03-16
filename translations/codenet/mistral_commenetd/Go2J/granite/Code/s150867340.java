
// Import the "java.util.Scanner" class for reading input values
import java.util.Scanner;

public class s150867340{
    public static void main(String[] args) {
        // Create a new instance of the "Scanner" class to read input values from the standard input
        Scanner scanner = new Scanner(System.in);

        // Declare and initialize two integer variables "a" and "b"
        // by reading input values from the standard input using the "scanner.nextInt()" method
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Calculate the product of "a" and "b" and store it in a new variable "product"
        int product = a * b;

        // Check if the product is even or odd using an if statement
        if (product % 2 == 0) {
            // If the product is even, print the message "Even" to the standard output
            System.out.println("Even");
        } else {
            // If the product is odd, print the message "Odd" to the standard output
            System.out.println("Odd");
        }

        // Close the "Scanner" object to release system resources
        scanner.close();
    }
}

// End of code