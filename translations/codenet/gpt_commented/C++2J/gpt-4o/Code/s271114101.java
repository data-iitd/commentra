import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input

        int a, b, c; // Declare three integer variables to hold the input values

        // Read three integers from the user
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if any two of the three numbers sum up to the third number
        // If a + b equals c, or b + c equals a, or a + c equals b, print "Yes"
        // Otherwise, print "No"
        System.out.println((a + b == c || b + c == a || a + c == b) ? "Yes" : "No");

        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of main method
} // End of Main class
// <END-OF-CODE>
