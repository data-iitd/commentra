import java.util.Random;
import java.util.Scanner;
public final class Main {
    private final Random random; // Initializes the random number generator with a seed value.
    private Main(int seed) {
        random = new Random(seed);
    }
    public static void main(String[] args) { // Main method to run the program.
        Scanner scanner = new Scanner(System.in); // Scanner object to read user input.
        try {
            while (!scanner.hasNextLong()) { // Loop to ensure the user inputs a valid number.
                System.out.println("Please enter a valid number.");
                System.out.print("Enter the number to check for primality: ");
                scanner.next();
            }
            long num = scanner.nextLong(); // Reads the number to check for primality.
            while (!scanner.hasNextInt()) { // Loop to ensure the user inputs a valid integer for iterations.
                System.out.println("Please enter a valid integer for iterations.");
                System.out.print("Enter the number of iterations: ");
                scanner.next();
            }
            int iterations = scanner.nextInt(); // Reads the number of iterations.
            Main test = new Main(42); // Creates an instance of Main with a seed value of 42.
            boolean isPrime = test.solovayStrassen(num, iterations); // Uses the Solovay-Strassen method to check for primality.
            System.out.println(num + " is " + (isPrime ? "probably prime." : "composite.")); // Prints whether the number is probably prime or composite.
        } catch (Exception e) { // Catches any exceptions that occur during execution.
            System.out.println("An error occurred: " + e.getMessage());
        } finally {
            scanner.close(); // Closes the scanner object to free up resources.
        }
    }
    private static long calculateModularExponentiation(long base, long exponent, long mod) { // Method to compute modular exponentiation.
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
    public int calculateJacobi(long a, long num) { // Method to calculate the Jacobi symbol for two numbers.
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
    public boolean solovayStrassen(long num, int iterations) { // Method to implement the Solovay-Strassen primality test.
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
