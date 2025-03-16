import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b; // Declare two integer variables to store user input
        a = scanner.nextInt(); // Read an integer value from the user and store it in variable a
        b = scanner.nextInt(); // Read another integer value from the user and store it in variable b
        if ((a * b) % 2 == 0) { // Check if the product of a and b is even or odd
            System.out.println("Even"); // Print "Even" if the product is even
        } else {
            System.out.println("Odd"); // Print "Odd" if the product is odd
        }
        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of main method
} // End of Main class
// <END-OF-CODE>
