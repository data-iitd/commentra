import java.util.Random;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read a long integer n from user input
        long n = scanner.nextLong();
        
        // Read an integer k from user input, which determines the accuracy of the Miller-Rabin test
        int k = scanner.nextInt();
        
        // Perform the Miller-Rabin probabilistic primality test
        boolean isProbablyPrime = millerRabin(n, k);
        // Output the result of the probabilistic test
        System.out.println("Using Miller-Rabin Probabilistic Test: " + (isProbablyPrime ? "Probably Prime" : "Composite"));
        
        // Perform the deterministic Miller-Rabin primality test
        boolean isPrime = deterministicMillerRabin(n);
        // Output the result of the deterministic test
        System.out.println("Using Deterministic Miller-Rabin Test: " + (isPrime ? "Prime" : "Composite"));
    }

    // Miller-Rabin probabilistic primality test
    public static boolean millerRabin(long n, int k) {
        // Handle small values of n
        if (n < 4) {
            return n == 2 || n == 3; // 2 and 3 are prime
        }
        
        // Initialize variables for the test
        int s = 0;
        long d = n - 1;
        
        // Factor n-1 into 2^s * d
        while ((d & 1) == 0) {
            d >>= 1;
            s++;
        }
        
        // Create a Random object for generating random bases
        Random rnd = new Random();
        
        // Perform k iterations of the test
        for (int i = 0; i < k; i++) {
            // Choose a random base a in the range [2, n-2]
            long a = 2 + Math.abs(rnd.nextLong()) % (n - 3); 
            // Check if n is composite with respect to base a
            if (checkComposite(n, a, d, s)) {
                return false; // n is composite
            }
        }
        return true; // n is probably prime
    }

    // Deterministic Miller-Rabin primality test for small values of n
    public static boolean deterministicMillerRabin(long n) {
        // Handle values of n less than 2
        if (n < 2) {
            return false; // 0 and 1 are not prime
        }
        
        // Initialize variables for the test
        int r = 0;
        long d = n - 1;
        
        // Factor n-1 into 2^r * d
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }
        
        // Test against a set of known small prime bases
        for (int a : new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            // If n is one of the small primes, return true
            if (n == a) {
                return true;
            }
            // Check if n is composite with respect to base a
            if (checkComposite(n, a, d, r)) {
                return false; // n is composite
            }
        }
        return true; // n is prime
    }

    // Check if n is composite given a base a, d, and s
    private static boolean checkComposite(long n, long a, long d, int s) {
        // Compute a^d mod n
        long x = powerModP(a, d, n);
        
        // Check if x is 1 or n-1
        if (x == 1 || x == n - 1) {
            return false; // n is not composite
        }
        
        // Square x s-1 times and check for n-1
        for (int r = 1; r < s; r++) {
            x = powerModP(x, 2, n);
            if (x == n - 1) {
                return false; // n is not composite
            }
        }
        return true; // n is composite
    }

    // Modular exponentiation: computes (x^y) mod p
    private static long powerModP(long x, long y, long p) {
        long res = 1; // Initialize result
        x %= p; // Update x if it is more than or equal to p
        
        // If x is 0, return 0
        if (x == 0) {
            return 0;
        }
        
        // Perform exponentiation by squaring
        while (y > 0) {
            // If y is odd, multiply x with result
            if ((y & 1) == 1) {
                res = multiplyModP(res, x, p);
            }
            y >>= 1; // Divide y by 2
            x = multiplyModP(x, x, p); // Square x
        }
        return res; // Return the result
    }

    // Modular multiplication: computes (a * b) mod p
    private static long multiplyModP(long a, long b, long p) {
        long res = 0; // Initialize result
        a %= p; // Update a if it is more than or equal to p
        
        // Perform multiplication using the method of doubling
        while (b > 0) {
            // If b is odd, add a to result
            if ((b & 1) == 1) {
                res = (res + a) % p;
            }
            a = (2 * a) % p; // Double a
            b >>= 1; // Divide b by 2
        }
        return res; // Return the result
    }
}
