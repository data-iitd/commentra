import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input
        int a; // Declare an integer variable 'a'
        a = scanner.nextInt(); // Read a value from the user and store it in 'a'
        System.out.println(a + (a * a) + (a * a * a)); // Calculate and print the sum of 'a', 'a^2', and 'a^3'
        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of main method
} // End of Main class
// <END-OF-CODE>
