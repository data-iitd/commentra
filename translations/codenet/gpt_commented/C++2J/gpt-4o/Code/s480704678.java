import java.util.Scanner;

public class Main {
    // Define constants for large values and mathematical constants
    static final long INF = 1001001001001001L;
    static final int inf = 1000000007;
    static final long MOD = 1000000007L;
    static final double PI = 3.1415926535897932;

    public static void main(String[] args) {
        // Read the number of elements
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize an array to store the input values and an array for prefix sums
        long[] a = new long[n];
        long[] acc = new long[n + 1];

        // Read input values and compute prefix sums modulo MOD
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
            acc[i + 1] = (acc[i] + a[i]) % MOD; // Update prefix sum and ensure it's within MOD
        }

        // Initialize the answer variable
        long ans = 0;

        // Calculate the final answer using the prefix sums
        for (int i = 0; i < n; i++) {
            ans = (ans + (a[i] % MOD) * ((MOD + acc[n] - acc[i + 1]) % MOD)) % MOD) % MOD; // Update answer
        }

        // Output the final result
        System.out.println(ans);
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
