import java.io.*;
import java.util.*;

public class Main {
    // Define a large prime number for modulo operations
    static final int MAGIC = 1000000007;

    // Command-line flags for CPU and memory profiling
    static String cpuprofile = "";
    static String memprofile = "";

    static int N;
    static int[] p = new int[200000];

    // Function to check if a number exists in the array p
    static int find(int n) {
        for (int i = 0; i < N; i++) {
            if (n == p[i]) {
                return 0; // Number found
            }
        }
        return 1; // Number not found
    }

    // Main solving function
    static void solve() {
        Io io = new Io(); // Create a new IO instance for input/output
        // PARSE HELPER SESSION
        // Read and log the input values
        int X = io.nextInt(); // Read an integer
        logf("%d\n", X); // Log the integer
        N = io.nextInt(); // Read the size of the array
        logf("%d\n", N); // Log the size
        for (int i = 0; i < N; i++) {
            p[i] = io.nextInt(); // Read integers into the array p
        }
        logf("p %s\n", Arrays.toString(Arrays.copyOfRange(p, 0, Math.min(N, 10)))); // Log the first 10 elements of p

        // Check for numbers around X that are not in the array p
        for (int i = 0; i <= 100; i++) {
            if (find(X - i) == 1) { // Check X - i
                System.out.printf("%d\n", X - i); // Print the result
                System.exit(0); // Exit the program
            }
            if (find(X + i) == 1) { // Check X + i
                System.out.printf("%d\n", X + i); // Print the result
                System.exit(0); // Exit the program
            }
        }
    }

    // Main function to execute the program
    public static void main(String[] args) {
        // Parse command-line flags (if any)
        // Note: Java does not have built-in flag parsing like Go, so this part is omitted

        solve(); // Call the solve function

        // Memory profiling code can be added here if needed
    }

    // Libraries

    // Io helps parsing inputs from standard input for programming contests.
    static class Io {
        BufferedReader reader;
        PrintWriter writer;
        StringTokenizer tokens;

        Io() {
            reader = new BufferedReader(new InputStreamReader(System.in)); // Initialize reader
            writer = new PrintWriter(System.out); // Initialize writer
        }

        // Flushes the output buffer
        void flush() {
            writer.flush(); // Flush the writer buffer
        }

        // Parses the next line as a string
        String nextLine() {
            try {
                return reader.readLine(); // Read a line
            } catch (IOException e) {
                throw new RuntimeException(e); // Handle exception
            }
        }

        // Parses the next token as a string
        String next() {
            if (tokens == null || !tokens.hasMoreTokens()) {
                tokens = new StringTokenizer(nextLine()); // Read the next line
            }
            return tokens.nextToken(); // Return the token
        }

        // Parses the next token as an integer
        int nextInt() {
            return Integer.parseInt(next()); // Convert the next token to int
        }

        // Parses the next token as a float
        double nextFloat() {
            return Double.parseDouble(next()); // Convert the next token to float
        }

        // Print a line with linefeed
        void printLn(Object... a) {
            for (Object obj : a) {
                writer.print(obj + " "); // Write to buffer
            }
            writer.println(); // Write linefeed
        }

        // Print formatted output
        void printf(String format, Object... a) {
            writer.printf(format, a); // Write formatted output to buffer
        }
    }

    // Log print formatted output to standard output
    static void logf(String format, Object... a) {
        System.err.printf(format, a); // Log formatted output to stderr
    }

    // Helper functions for mathematical operations

    // Returns the minimum of two integers
    static int intMin(int a, int b) {
        return Math.min(a, b);
    }

    // Returns the maximum of two integers
    static int intMax(int a, int b) {
        return Math.max(a, b);
    }

    // Direct calculation of combination
    // n, m should be "small"
    static int combination(int n, int m) {
        if (m > n) {
            return 0; // Not possible to choose more than available
        } else if (m == n || m == 0) {
            return 1; // Only one way to choose all or none
        } else {
            int res = 1;
            for (int i = 0; i < m; i++) {
                res *= (n - i); // Calculate numerator
            }
            for (int i = 1; i <= m; i++) {
                res /= i; // Calculate denominator
            }
            return res; // Return the combination result
        }
    }

    // Calculate combination modulo based on Lucas theorem
    static int lucas(int n, int m, int p) {
        int ntemp = n;
        int mtemp = m;
        int res = 1;
        for (int i = 0; i < 100; i++) {
            int nreminder = ntemp % p; // Remainder of n
            ntemp /= p; // Update n
            int mreminder = mtemp % p; // Remainder of m
            mtemp /= p; // Update m
            res = res * (combination(nreminder, mreminder) % p); // Combine results
            if (ntemp == 0) {
                break; // Break if n is exhausted
            }
        }
        return res % p; // Return the result modulo p
    }

    // Wrapper function for combination modulo
    static int combMod(int n, int m, int p) {
        return lucas(n, m, p); // Call lucas function
    }

    // Function to calculate the absolute value
    static int abs(int a) {
        return Math.abs(a); // Return absolute value
    }

    // Function to calculate the greatest common divisor (GCD)
    static int gcd(int a, int b) {
        while (a != 0) {
            int temp = b % a;
            b = a;
            a = temp; // Euclidean algorithm
        }
        return b; // Return the GCD
    }

    // Function to calculate power of 2 modulo a given number
    static int power2mod(int n, int mod) {
        int res = 1, x = 2;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * x % mod; // Update result if the current bit is set
            }
            x = x * x % mod; // Square the base
            n >>= 1; // Right shift n
        }
        return res; // Return the result
    }

    // Function to calculate power of 2 with modulo magic
    static int power2(int n) {
        return power2mod(n, MAGIC); // Call power2mod with magic
    }
}

// <END-OF-CODE>
