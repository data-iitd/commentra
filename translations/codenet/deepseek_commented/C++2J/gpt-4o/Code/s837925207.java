import java.util.Scanner; // Import the Scanner class for input operations.

public class Main { // Define the Main class.
    public static void main(String[] args) { // The main method is the entry point of the program.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input.
        
        int x; // Declare an integer variable x.
        int ans = 0; // Initialize ans to 0.

        x = scanner.nextInt(); // Read an integer from the standard input and store it in x.

        ans = x + x * x + x * x * x; // Calculate the result by adding x, x*x, and x*x*x.

        System.out.println(ans); // Print the result to the standard output.

        scanner.close(); // Close the scanner to prevent resource leaks.
    } // End of the main method.
} // End of the Main class.
// <END-OF-CODE>
