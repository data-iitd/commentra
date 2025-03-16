import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int r; // Declare an integer variable 'r' to store user input
        r = scanner.nextInt(); // Read an integer value from standard input and store it in 'r'
        
        // Calculate the square of 'r' and print the result
        System.out.println(r * r); // Output the square of 'r' followed by a newline
        
        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
