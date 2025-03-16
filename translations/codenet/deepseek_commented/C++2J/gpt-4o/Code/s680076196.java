import java.util.Scanner; // Step 1: Import the Scanner class for input operations

public class RectangleArea { // Step 2: Define the class
    public static void main(String[] args) { // Step 3: Main method to read input values
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b, c, d; // Declare variables to store the input values
        a = scanner.nextInt(); // Read the first integer value
        b = scanner.nextInt(); // Read the second integer value
        c = scanner.nextInt(); // Read the third integer value
        d = scanner.nextInt(); // Read the fourth integer value

        // Step 4: Perform calculations
        int area = (a - c) * (b - d); // Calculate the area of the rectangle using the given coordinates

        // Step 5: Output the result
        System.out.println(area); // Print the calculated area to the console
        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
