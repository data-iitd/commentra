import java.util.Scanner;

public class GCD {
    // Function to calculate the greatest common divisor (GCD) of two numbers
    public static int you(int x, int y) {
        int z; // Variable to store the remainder

        // Repeat the following steps until y becomes zero
        while (y != 0) {
            // Calculate the remainder of x divided by y and store it in z
            z = x % y;

            // Update the values of x and y
            x = y;
            y = z;
        }

        // Return the final value of x, which is the greatest common divisor
        return x;
    }

    public static void main(String[] args) {
        // Declare variables x, y, and z
        int x, y, z;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read two integers from the user
        System.out.print("Enter two integers: ");
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Determine which number is greater and call the you() function with the appropriate arguments
        if (x >= y) {
            z = you(x, y); // Call the you() function with x and y as arguments
        } else {
            z = you(y, x); // Call the you() function with y and x as arguments
        }

        // Print the result (the greatest common divisor) to the console
        System.out.printf("The greatest common divisor of %d and %d is: %d\n", x, y, z);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
