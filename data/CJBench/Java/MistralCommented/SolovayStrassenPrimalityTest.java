
import java.util.Random;
import java.util.Scanner;

public final class Main {
    // Initialize random number generator with given seed
    private final Random random;
    private Main(int seed) {
        random = new Random(seed);
    }

    // Main method to start the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize scanner for user input
        try {
            // Ask user for valid number to check for primality
            while (!scanner.hasNextLong()) {
                System.out.println("Please enter a valid number.");
                System.out.print("Enter the number to check for primality: ");
                scanner.next();
            }
            long num = scanner.nextLong(); // Read the number from user input

            // Ask user for valid integer for iterations
            while (!scanner.hasNextInt()) {
                System.out.println("Please enter a valid integer for iterations.");
                System.out.print("Enter the number of iterations: ");
                scanner.next();
            }
            int iterations = scanner.nextInt(); // Read the number of iterations from user input

            // Initialize Main object with seed 42
            Main test = new Main(42);

            // Check if the number is prime using Solovay-Strassen algorithm
            boolean isPrime = test.solovayStrassen(num, iterations);

            // Print the result
            System.out.println(num + " is " + (isPrime ? "probably prime." : "composite."));
        } catch (Exception e) {
            // Handle exceptions
            System.out.println("An error occurred: " + e.getMessage());
        } finally {
            // Close scanner
            scanner.close();
        }
    }

    // Helper method to calculate modular exponentiation
    private static long calculateModularExponentiation(long base, long exponent, long mod) {
        long x = 1;
        long y = base;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                x = x * y % mod;
            }
            y = y * y % mod;
            exponent /= 2;
        }
        return x % mod;
    }

    // Helper method to calculate Jacobi symbol
    public int calculateJacobi(long a, long num) {
        if (num <= 0 || num % 2 == 0) {
            return 0;
        }
        a = a % num;
        int jacobi = 1;
        while (a != 0) {
            while (a % 2 == 0) {
                a /= 2;
                long nMod8 = num % 8;
                if (nMod8 == 3 || nMod8 == 5) {
                    jacobi = -jacobi;
                }
            }
            long temp = a;
            a = num;
            num = temp;
            if (a % 4 == 3 && num % 4 == 3) {
                jacobi = -jacobi;
            }
            a = a % num;
        }
        return (num == 1) ? jacobi : 0;
    }

    // Main method to check if a number is prime using Solovay-Strassen algorithm
    public boolean solovayStrassen(long num, int iterations) {
        if (num <= 1) {
            return false;
        }
        if (num <= 3) {
            return true;
        }
        for (int i = 0; i < iterations; i++) {
            long r = Math.abs(random.nextLong() % (num - 1)) + 2;
            long a = r % (num - 1) + 1;
            long jacobi = (num + calculateJacobi(a, num)) % num;
            long mod = calculateModularExponentiation(a, (num - 1) / 2, num);
            if (jacobi == 0 || mod != jacobi) {
                return false;
            }
        }
        return true;
    }
}