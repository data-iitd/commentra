import java.math.BigInteger; // Importing BigInteger class for handling large integers
import java.util.Scanner; // Importing Scanner class for user input

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to perform Karatsuba multiplication
    public static BigInteger karatsuba(BigInteger x, BigInteger y) {
        // Base case: if either number is small (4 bits or less), use standard multiplication
        if (x.bitLength() <= 4 || y.bitLength() <= 4) {
            return x.multiply(y);
        }

        // Determine the maximum bit length of the two numbers
        int n = Math.max(x.bitLength(), y.bitLength());
        // Split the bit length in half
        int m = n / 2;

        // Split x into high and low parts
        BigInteger high1 = x.shiftRight(m); // High part of x
        BigInteger low1 = x.subtract(high1.shiftLeft(m)); // Low part of x

        // Split y into high and low parts
        BigInteger high2 = y.shiftRight(m); // High part of y
        BigInteger low2 = y.subtract(high2.shiftLeft(m)); // Low part of y

        // Recursively calculate the three products
        BigInteger z0 = karatsuba(low1, low2); // z0 = low1 * low2
        BigInteger z1 = karatsuba(low1.add(high1), low2.add(high2)); // z1 = (low1 + high1) * (low2 + high2)
        BigInteger z2 = karatsuba(high1, high2); // z2 = high1 * high2

        // Combine the three products to get the final result
        return z2.shiftLeft(2 * m) // Shift z2 left by 2m
                .add(z1.subtract(z2).subtract(z0).shiftLeft(m)) // Adjust z1 and z0, then shift left by m
                .add(z0); // Add z0
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        try {
            // Read two large numbers from user input
            BigInteger num1 = new BigInteger(scanner.nextLine().trim());
            BigInteger num2 = new BigInteger(scanner.nextLine().trim());

            // Calculate the product using the Karatsuba method
            BigInteger result = karatsuba(num1, num2);

            // Output the result
            System.out.println("The product of the two numbers is:");
            System.out.println(result);
        } catch (NumberFormatException e) {
            // Handle invalid input
            System.err.println("Invalid input. Please enter valid large numbers.");
        } finally {
            // Close the scanner to prevent resource leaks
            scanner.close();
        }
    }
}
