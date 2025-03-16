import java.math.BigInteger;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Karatsuba multiplication algorithm
    public static BigInteger karatsuba(BigInteger x, BigInteger y) {
        // Base case: if the numbers are small enough, use simple multiplication
        if (x.bitLength() <= 4 || y.bitLength() <= 4) {
            return x.multiply(y);
        }

        // Determine the size of the numbers
        int n = Math.max(x.bitLength(), y.bitLength());
        int m = n / 2;

        // Split the numbers into high and low parts
        BigInteger high1 = x.shiftRight(m); 
        BigInteger low1 = x.subtract(high1.shiftLeft(m)); 
        BigInteger high2 = y.shiftRight(m); 
        BigInteger low2 = y.subtract(high2.shiftLeft(m)); 

        // Recursively compute the three multiplications
        BigInteger z0 = karatsuba(low1, low2); 
        BigInteger z1 = karatsuba(low1.add(high1), low2.add(high2)); 
        BigInteger z2 = karatsuba(high1, high2); 

        // Combine the results using the Karatsuba formula
        return z2.shiftLeft(2 * m) 
                .add(z1.subtract(z2).subtract(z0).shiftLeft(m)) 
                .add(z0); 
    }

    // Main function to read input and compute the product using Karatsuba algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            // Read two large integers from the user
            BigInteger num1 = new BigInteger(scanner.nextLine().trim());
            BigInteger num2 = new BigInteger(scanner.nextLine().trim());

            // Compute the product using the Karatsuba algorithm
            BigInteger result = karatsuba(num1, num2);

            // Print the result
            System.out.println("The product of the two numbers is:");
            System.out.println(result);
        } catch (NumberFormatException e) {
            // Handle invalid input
            System.err.println("Invalid input. Please enter valid large numbers.");
        } finally {
            // Close the scanner
            scanner.close();
        }
    }
}
