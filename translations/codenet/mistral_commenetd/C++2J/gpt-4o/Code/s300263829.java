import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Declare the Main class
    public static void main(String[] args) { // Declare the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a = scanner.nextInt(); // Read the first integer from input
        int b = scanner.nextInt(); // Read the second integer from input
        System.out.println(a * b); // Multiply the values of a and b and print the result
        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of main method
} // End of Main class
// <END-OF-CODE>
