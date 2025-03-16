import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize a new FastScanner object called fsc
        FastScanner fsc = new FastScanner();

        // Read the first three integers A, B, and C from the standard input
        int A = fsc.nextInt();
        int B = fsc.nextInt();
        int C = fsc.nextInt();

        // Check if the difference between B and A is equal to the difference between C and B
        if (B - A == C - B) {
            // If it is, print "YES"
            System.out.println("YES");
        } else {
            // Otherwise, print "NO"
            System.out.println("NO");
        }
    }
}

// FastScanner class for reading input efficiently
class FastScanner {
    private BufferedReader reader;
    private String[] tokens;
    private int index;

    public FastScanner() {
        // Initialize a new BufferedReader with InputStreamReader
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokens = new String[0];
        index = 0;
    }

    public String next() throws IOException {
        // If there are no more tokens, read a new line
        if (index >= tokens.length) {
            tokens = reader.readLine().split(" ");
            index = 0;
        }
        return tokens[index++];
    }

    public int nextInt() throws IOException {
        // Read a string token as an integer
        return Integer.parseInt(next());
    }
}

// Helper functions for finding the maximum and minimum values
class MathUtils {
    public static int max(int a, int b) {
        return a < b ? b : a;
    }

    public static long max(long a, long b) {
        return a < b ? b : a;
    }

    public static double max(double a, double b) {
        return a < b ? b : a;
    }

    public static int min(int a, int b) {
        return a > b ? b : a;
    }

    public static long min(long a, long b) {
        return a > b ? b : a;
    }

    public static double min(double a, double b) {
        return a > b ? b : a;
    }

    // Helper function for finding the greatest common divisor of two integers
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // Helper function for finding the absolute value of an integer
    public static int abs(int a) {
        return a < 0 ? -a : a;
    }

    public static long abs(long a) {
        return a < 0 ? -a : a;
    }
}

// <END-OF-CODE>
