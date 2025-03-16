import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b; // Declare two integer variables 'a' and 'b'

        a = scanner.nextInt(); // Read the first integer from input
        b = scanner.nextInt(); // Read the second integer from input

        System.out.println(a * b + " " + (2 * (a + b))); // Print the product of 'a' and 'b' followed by the double of their sum

        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
