import java.util.Scanner;  // Import the Scanner class for input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Main method is the entry point of the program
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int x, y, z;  // Declare three integer variables
        x = scanner.nextInt();  // Read the first integer
        y = scanner.nextInt();  // Read the second integer
        if (x >= y)  // Check if x is greater than or equal to y
            z = you(x, y);  // Call the you function with x and y as arguments
        else  // Otherwise
            z = you(y, x);  // Call the you function with y and x as arguments
        System.out.println(z);  // Print the result to standard output
        scanner.close();  // Close the scanner
    }

    public static int you(int x, int y) {  // Define the you function
        int z;  // Declare an integer variable to store intermediate results
        while (true) {  // Infinite loop to apply the Euclidean algorithm
            z = x % y;  // Compute the remainder of x divided by y
            x = y;  // Update x to be the previous value of y
            y = z;  // Update y to be the remainder
            if (y <= 0)  // Check if y is zero or negative
                break;  // Exit the loop if y is zero or negative
        }
        return x;  // Return the GCD of the original two numbers
    }
}  // End of Main class
// <END-OF-CODE>
