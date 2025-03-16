import java.util.Random;
import java.util.Scanner;

public final class Main {
    private final Random random;

    // Constructor that initializes the random number generator with a seed
    private Main(int seed) {
        random = new Random(seed);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            // Prompt user for a valid long number to check for primality
            while (!scanner.hasNextLong()) {
                System.out.println("Please enter a valid number.");
                System.out.print("Enter the number to check for primality: ");
                scanner.next();
            }
            long num = scanner.nextLong();

            // Prompt user for a valid integer for the number of iterations
            while (!scanner.hasNextInt()) {
                System.out.println("Please enter a valid integer for iterations.");
                System.out.print("Enter the number of iterations: ");
                scanner.next();
            }
            int iterations = scanner.nextInt();

            // Create an instance of Main with a fixed seed for randomness
            Main test = new Main(42); 
            // Perform the Solovay-Strassen primality test
            boolean isPrime = test.solovayStrassen(num, iterations);
            // Output the result of the primality test
            System.out.println(num + " is " + (isPrime ? "probably prime." : "composite."));
        } catch (Exception e) {
            // Handle any exceptions that occur during input or processing
            System.out.println("An error occurred: " + e.getMessage());
        } finally {
            // Ensure the scanner is closed to prevent resource leaks
            scanner.close();
        }
    }

    // Method to perform modular exponentiation using the method of exponentiation by squaring
    private static long calculateModularExponentiation(long base, long exponent, long mod) {
        long x = 1;
        long y = base;
        // Loop until the exponent is reduced to zero
        while (exponent > 0) {
            // If exponent is odd, multiply the current base with the result
            if (exponent % 2 == 1) {
                x = x * y % mod;
            }
            // Square the base and reduce the exponent
            y = y * y % mod;
            exponent /= 2;
        }
        return x % mod; // Return the final result
    }

    // Method to calculate the Jacobi symbol (a/n)
    public int calculateJacobi(long a, long num) {
        // Return 0 if num is not a positive odd integer
        if (num <= 0 || num % 2 == 0) {
            return 0;
        }
        a = a % num; // Reduce a modulo num
        int jacobi = 1; // Initialize the Jacobi symbol
        // Loop until a becomes zero
        while (a != 0) {
            // Reduce a by factors of 2 and adjust the Jacobi symbol accordingly
            while (a % 2 == 0) {
                a /= 2;
                long nMod8 = num % 8;
                if (nMod8 == 3 || nMod8 == 5) {
                    jacobi = -jacobi; // Adjust Jacobi symbol based on properties of num
                }
            }
            // Swap a and num, and adjust the Jacobi symbol if necessary
            long temp = a;
            a = num;
            num = temp;
            if (a % 4 == 3 && num % 4 == 3) {
                jacobi = -jacobi; // Adjust Jacobi symbol based on properties of a and num
            }
            a = a % num; // Reduce a modulo num
        }
        return (num == 1) ? jacobi : 0; // Return the Jacobi symbol or 0 if num is not 1
    }

    // Method to perform the Solovay-Strassen primality test
    public boolean solovayStrassen(long num, int iterations) {
        // Return false for numbers less than or equal to 1
        if (num <= 1) {
            return false;
        }
        // Return true for numbers 2 and 3
        if (num <= 3) {
            return true;
        }
        // Perform the test for the specified number of iterations
        for (int i = 0; i < iterations; i++) {
            long r = Math.abs(random.nextLong() % (num - 1)) + 2; // Random base in range [2, num-1]
            long a = r % (num - 1) + 1; // Ensure a is in the range [1, num-1]
            long jacobi = (num + calculateJacobi(a, num)) % num; // Calculate the Jacobi symbol
            long mod = calculateModularExponentiation(a, (num - 1) / 2, num); // Calculate modular exponentiation
            // If Jacobi symbol is 0 or does not match the modular result, num is composite
            if (jacobi == 0 || mod != jacobi) {
                return false;
            }
        }
        return true; // If all iterations pass, num is probably prime
    }
}
