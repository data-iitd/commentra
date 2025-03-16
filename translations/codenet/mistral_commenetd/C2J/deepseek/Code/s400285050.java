public class GCDCalculator {
    // Method to calculate the greatest common divisor (GCD) of two numbers
    public static int gcd(int x, int y) {
        int z; // Declare a variable z to store the remainder

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

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from the user
        System.out.print("Enter two integers: ");
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Determine which number is greater and call the gcd() method with the appropriate arguments
        if (x >= y) {
            z = gcd(x, y); // Call the gcd() method with x and y as arguments
        } else {
            z = gcd(y, x); // Call the gcd() method with y and x as arguments
        }

        // Print the result (the greatest common divisor) to the console
        System.out.printf("The greatest common divisor of %d and %d is: %d\n", x, y, z);
    }
}
