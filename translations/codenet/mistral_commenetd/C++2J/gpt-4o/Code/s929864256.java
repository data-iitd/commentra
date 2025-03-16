import java.util.Scanner;

public class Main {
    // Constants definition
    private static final long INF = 1L << 60; // Infinite value for long long int
    private static final long MOD = 1000000007; // Modulus value for modular arithmetic

    public static void main(String[] args) {
        // Initialize variables
        long a, b;

        // Read input values from standard input
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextLong();
        b = scanner.nextLong();
        scanner.close();

        // Calculate the maximum value among a+b, a-b, and a*b
        long result = Math.max(a + b, Math.max(a - b, a * b));

        // Output the result to standard output
        System.out.println(result);
    }
}

// <END-OF-CODE>
