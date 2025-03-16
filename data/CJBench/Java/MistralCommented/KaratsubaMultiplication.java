
import java.math.BigInteger;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }

    public static BigInteger karatsuba(BigInteger x, BigInteger y) {
        // Base case: if the bit length of either x or y is less than or equal to 4,
        // return the product of x and y using the built-in multiplication method
        if (x.bitLength() <= 4 || y.bitLength() <= 4) {
            return x.multiply(y);
        }

        // Calculate the maximum bit length of x and y and divide it by 2 to get m
        int n = Math.max(x.bitLength(), y.bitLength());
        int m = n / 2;

        // Shift right x by m bits to get the high part (the left half)
        BigInteger high1 = x.shiftRight(m);

        // Subtract the shifted high part from x and shift left m bits to get the low part (the right half)
        BigInteger low1 = x.subtract(high1.shiftLeft(m));

        // Perform the same operations on y
        BigInteger high2 = y.shiftRight(m);
        BigInteger low2 = y.subtract(high2.shiftLeft(m));

        // Recursively calculate the product of the low parts using the karatsuba method
        BigInteger z0 = karatsuba(low1, low2);

        // Calculate the product of the high parts and shift left 2m bits to get z2
        BigInteger z2 = karatsuba(high1, high2).shiftLeft(2 * m);

        // Calculate z1 as the sum of the products of the low parts and high parts,
        // then subtract z2 and shift left m bits to get the final result
        BigInteger z1 = karatsuba(low1.add(high1), low2.add(high2));
        BigInteger result = z2.add(z1.subtract(z0).subtract(z2)).add(z0);

        return result;
    }

    public static void main(String[] args) {
        // Create a new Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        try {
            // Read two large numbers as strings from the console and convert them to BigInteger objects
            BigInteger num1 = new BigInteger(scanner.nextLine().trim());
            BigInteger num2 = new BigInteger(scanner.nextLine().trim());

            // Call the karatsuba method to calculate the product of num1 and num2
            BigInteger result = karatsuba(num1, num2);

            // Print the result to the console
            System.out.println("The product of the two numbers is:");
            System.out.println(result);
        } catch (NumberFormatException e) {
            // Handle the NumberFormatException by printing an error message to the console
            System.err.println("Invalid input. Please enter valid large numbers.");
        } finally {
            // Close the Scanner object to free up system resources
            scanner.close();
        }
    }
}