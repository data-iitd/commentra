import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a; // Declare an integer variable 'a'
        int b; // Declare an integer variable 'b'
        
        a = scanner.nextInt(); // Read the value of 'a' from standard input
        b = scanner.nextInt(); // Read the value of 'b' from standard input
        int result; // Declare an integer variable 'result' to store the final result

        // Determine the value of 'result' based on the values of 'a' and 'b'
        if (a > b) {
            result = 2 * a - 1; // If 'a' is greater than 'b', calculate 'result' as 2 * 'a' - 1
        } else if (a == b) {
            result = 2 * a; // If 'a' is equal to 'b', calculate 'result' as 2 * 'a'
        } else {
            result = 2 * b - 1; // If 'a' is less than 'b', calculate 'result' as 2 * 'b' - 1
        }

        System.out.println(result); // Output the value of 'result' to standard output
        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of main method
} // End of Main class
// <END-OF-CODE>
