import java.util.Scanner; // For standard input and output functions

public class Main {
    static final int MOD = 1000000007; // Define a large prime number for modulo operations
    static final int MOD9 = 998244353; // Another large prime number for modulo operations
    static final double EPS = 1e-7; // Define a small epsilon value for floating-point comparisons
    static final int INF = 0x3f3f3f3f; // Define a large integer value for infinity
    static final long INF_LONG = 0x3f3f3f3f3f3f3f3f; // Define a large long long value for infinity

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int tc = scanner.nextInt(); // Read the number of test cases
        int n = scanner.nextInt(); // Read the first integer
        int m = scanner.nextInt(); // Read the second integer
        int fl = 0; // Flag to indicate success

        // Ensure n is the smaller of the two integers
        if (n > m) {
            int temp = n;
            n = m;
            m = temp;
        }

        // Loop through the range from 1 to m
        for (int i = 1; i <= m; i++) {
            // Check if the current value multiplied by tc is within the range [n, m]
            if (i * tc >= n && i * tc <= m) {
                System.out.println("OK"); // Print "OK" if the condition is satisfied
                fl = 1; // Set the flag to indicate success
                break; // Exit the loop as we found a valid case
            }
        }

        // If no valid case was found, print "NG"
        if (fl == 0) {
            System.out.println("NG");
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
