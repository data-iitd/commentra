
import java.util.Random;
import java.util.Scanner;

// Initialize scanner for user input
public final class Main {
    private Main() {
    }

    // Main method to start the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object for user input
        long n = scanner.nextLong(); // Read the first number 'n' from the user input
        int k = scanner.nextInt(); // Read the second number 'k' from the user input

        // Perform probabilistic Miller-Rabin test
        boolean isProbablyPrime = millerRabin(n, k);
        System.out.println("Using Miller-Rabin Probabilistic Test: " + (isProbablyPrime ? "Probably Prime" : "Composite"));

        // Perform deterministic Miller-Rabin test
        boolean isPrime = deterministicMillerRabin(n);
        System.out.println("Using Deterministic Miller-Rabin Test: " + (isPrime ? "Prime" : "Composite"));
    }

    // Probabilistic Miller-Rabin test
    public static boolean millerRabin(long n, int k) {
        // Check base cases
        if (n < 4) {
            return n == 2 || n == 3;
        }

        // Initialize variables
        int s = 0;
        long d = n - 1;

        // Find the largest power of 2 that divides 'd'
        while ((d & 1) == 0) {
            d >>= 1;
            s++;
        }

        // Generate random 'a' values and check for compositeness
        Random rnd = new Random();
        for (int i = 0; i < k; i++) {
            long a = 2 + Math.abs(rnd.nextLong()) % (n - 3); // Generate a random number 'a' between 2 and 'n-1'
            if (checkComposite(n, a, d, s)) { // If 'n' is composite, return false
                return false;
            }
        }

        // If all tests pass, 'n' is probably prime
        return true;
    }

    // Deterministic Miller-Rabin test
    public static boolean deterministicMillerRabin(long n) {
        // Check base cases
        if (n < 2) {
            return false;
        }

        // Initialize variables
        int r = 0;
        long d = n - 1;

        // Find the largest power of 2 that divides 'd'
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }

        // Check for small prime factors
        for (int a : new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (n == a) { // If 'n' is a small prime, return true
                return true;
            }
            if (checkComposite(n, a, d, r)) { // If 'n' is composite, return false
                return false;
            }
        }

        // If all tests pass, 'n' is prime
        return true;
    }

    // Check if 'n' is composite given 'a', 'd', and 's'
    private static boolean checkComposite(long n, long a, long d, int s) {
        // Calculate 'x' = a^d mod n
        long x = powerModP(a, d, n);

        // Check base cases
        if (x == 1 || x == n - 1) {
            return false;
        }

        // If 'x' is not a power of 2, 'n' is composite
        for (int r = 1; r < s; r++) {
            x = powerModP(x, 2, n);
            if (x == n - 1) {
                return false;
            }
        }

        // If all tests pass, 'n' is probably composite
        return true;
    }

    // Calculate 'x' = a^y mod p
    private static long powerModP(long a, long y, long p) {
        // Calculate 'x' as the product of 'a' raised to the power of each bit in 'y'
        long res = 1;
        a %= p;
        if (a == 0) {
            return 0;
        }
        while (y > 0) {
            if ((y & 1) == 1) {
                res = multiplyModP(res, a, p);
            }
            a = multiplyModP(a, a, p);
            y >>= 1;
        }
        return res;
    }

    // Multiply 'a' and 'b' modulo 'p'
    private static long multiplyModP(long a, long b, long p) {
        // Calculate the product of 'a' and 'b'
        long res = 0;
        a %= p;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = (res + a) % p;
            }
            a = (2 * a) % p;
            b >>= 1;
        }
        return res;
    }
}