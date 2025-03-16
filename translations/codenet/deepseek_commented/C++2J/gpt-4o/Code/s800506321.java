import java.util.Scanner; // Import the Scanner class for input operations.

public class Main { // Define the Main class.
    public static void main(String[] args) { // Define the main method, the entry point of the program.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input.
        
        int n, k, x, y, z; // Declare five integer variables to store values.
        n = scanner.nextInt(); // Read an integer value for n from the standard input.
        k = scanner.nextInt(); // Read an integer value for k from the standard input.
        
        x = n / k; // Calculate the integer division of n by k and store the result in x.
        y = n % k; // Calculate the remainder of the integer division of n by k and store the result in y.
        
        if (y != 0) { // Check if the remainder y is not equal to 0.
            z = x + 1 - x; // If y is not equal to 0, calculate z as x + 1 - x.
        } else { // If y is equal to 0.
            z = x - x; // Calculate z as x - x.
        }
        
        System.out.println(z); // Print the value of z to the standard output.
        
        scanner.close(); // Close the scanner to free resources.
    } // End of the main method.
} // End of the Main class.
