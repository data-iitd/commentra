import java.util.Random;
import java.util.Scanner;
public final class Main {
    private Main() {
    }
    // Main method to run the program
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        // Read the long integer n from the user
        long n = scanner.nextLong();
        // Read the integer k from the user
        int k = scanner.nextInt();
        // Use the Miller-Rabin probabilistic test to check if n is probably prime with k iterations
        boolean isProbablyPrime = millerRabin(n, k);
        // Print the result of the Miller-Rabin test
        System.out.println("Using Miller-Rabin Probabilistic Test: " + (isProbablyPrime ? "Probably Prime" : "Composite"));
        // Use the deterministic Miller-Rabin test to check if n is prime
        boolean isPrime = deterministicMillerRabin(n);
        // Print the result of the deterministic Miller-Rabin test
        System.out.println("Using Deterministic Miller-Rabin Test: " + (isPrime ? "Prime" : "Composite"));
    }
    // Miller-Rabin probabilistic test to check primality
    public static boolean millerRabin(long n, int k) {
        // Handle small numbers directly
        if (n < 4) {
            return n == 2 || n == 3;
        }
        // Decompose n-1 into d and s where d is odd and s is the number of times d can be divided by 2
        int s = 0;
        long d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            s++;
        }
        // Create a Random object for random base selection
        Random rnd = new Random();
        // Perform k iterations
        for (int i = 0; i < k; i++) {
            // Select a random base a between 2 and n-3
            long a = 2 + Math.abs(rnd.nextLong()) % (n - 3); 
            // Check if a is a witness for the compositeness of n
            if (checkComposite(n, a, d, s)) {
                return false;
            }
        }
        return true;
    }
    // Deterministic Miller-Rabin test to check primality
    public static boolean deterministicMillerRabin(long n) {
        // Handle small numbers
        if (n < 2) {
            return false;
        }
        // Decompose n-1 into d and r where d is odd and r is the number of times d can be divided by 2
        int r = 0;
        long d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }
        // Check n against a set of known prime numbers
        for (int a : new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (n == a) {
                return true;
            }
            if (checkComposite(n, a, d, r)) {
                return false;
            }
        }
        return true;
    }
    // Helper method to check if n is composite given base a, d, and s
    private static boolean checkComposite(long n, long a, long d, int s) {
        // Compute a^d mod n
        long x = powerModP(a, d, n);
        // If x is 1 or n-1, n is probably prime
        if (x == 1 || x == n - 1) {
            return false;
        }
        // Iterate r times to check if x becomes n-1
        for (int r = 1; r < s; r++) {
            x = powerModP(x, 2, n);
            if (x == n - 1) {
                return false;
            }
        }
        return true;
    }
    // Helper method to compute x^y mod p using modular exponentiation
    private static long powerModP(long x, long y, long p) {
        long res = 1;
        x %= p;
        if (x == 0) {
            return 0;
        }
        while (y > 0) {
            if ((y & 1) == 1) {
                res = multiplyModP(res, x, p);
            }
            y >>= 1;
            x = multiplyModP(x, x, p);
        }
        return res;
    }
    // Helper method to compute a * b mod p using loop for large numbers
    private static long multiplyModP(long a, long b, long p) {
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
