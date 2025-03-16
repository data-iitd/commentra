public class GCDCalculator {
    // Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
    public static int gcd(int x, int y) {
        int z;

        // Infinite loop to perform the Euclidean algorithm
        while (true) {
            z = x % y; // Calculate the remainder of x divided by y
            x = y;     // Update x to be y
            y = z;     // Update y to be the remainder

            // Break the loop if y becomes zero or negative
            if (y <= 0) break;
        }

        // Return the last non-zero value of x, which is the GCD
        return x;
    }

    public static void main(String[] args) {
        // Declare variables to hold input values and result
        int x, y, z;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from user input
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Call the 'gcd' function with the larger and smaller of the two integers
        if (x >= y) 
            z = gcd(x, y); // If x is greater than or equal to y, pass x and y to 'gcd'
        else 
            z = gcd(y, x); // Otherwise, pass y and x to 'gcd'

        // Print the result returned from the 'gcd' function
        System.out.println(z);

        // Close the scanner to free up resources
        scanner.close();
    }
}
