import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input
        int r; // Declare an integer variable `r` to store the value read from the input

        // Read an integer `r` from the standard input
        r = scanner.nextInt();

        // Calculate and print the square of `r` to the standard output
        System.out.println(r * r);

        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
