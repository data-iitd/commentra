import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input
        int r; // Declare an integer variable named "r"

        // Read the value of "r" from the standard input using the Scanner
        r = scanner.nextInt();

        // Output the square of "r" to the standard output
        System.out.println(r * r);

        // Close the scanner to prevent resource leaks
        scanner.close();
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
