import java.util.Scanner;

public class Main {
    // Define constants for infinity and long long integer type
    static final long INF = 1 << 29;
    static final long MOD = 1000000007;

    public static void main(String[] args) {
        // Optimize input/output operations
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements and the constant c
        long n = scanner.nextLong();
        long c = scanner.nextLong();

        // Initialize arrays to store positions and velocities
        long[] x = new long[(int) n + 1];
        long[] v = new long[(int) n + 1];

        // Read the positions and velocities of the elements
        for (int i = 1; i <= n; i++) {
            x[i] = scanner.nextLong();
            v[i] = scanner.nextLong();
        }

        // Initialize arrays to store cumulative velocities from the left
        long[] lefttotal = new long[(int) n + 1];
        long[] maxlefttotal = new long[(int) n + 1];

        // Calculate cumulative velocities from the left
        for (int i = 1; i <= n; i++) {
            lefttotal[i] = lefttotal[i - 1] + v[i];
        }

        // Calculate the maximum value of lefttotal adjusted by position
        for (int i = 1; i <= n; i++) {
            maxlefttotal[i] = Math.max(maxlefttotal[i - 1], lefttotal[i] - x[i]);
        }

        // Initialize arrays to store cumulative velocities from the right
        long[] righttotal = new long[(int) n + 1];
        long[] maxrighttotal = new long[(int) n + 1];

        // Calculate cumulative velocities from the right
        for (int i = 1; i <= n; i++) {
            righttotal[i] = righttotal[i - 1] + v[(int) (n - i + 1)];
        }

        // Calculate the maximum value of righttotal adjusted by position
        for (int i = 1; i <= n; i++) {
            maxrighttotal[i] = Math.max(maxrighttotal[i - 1], righttotal[i] - (c - x[(int) (n + 1 - i)]));
        }

        // Initialize the answer variable to store the maximum result
        long ans = 0;

        // Evaluate the maximum possible value based on different scenarios
        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, lefttotal[i] - x[i]); // Scenario 1
            ans = Math.max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[(int) (n - i)]); // Scenario 2
            ans = Math.max(ans, righttotal[i] - (c - x[(int) (n + 1 - i)])); // Scenario 3
            ans = Math.max(ans, righttotal[i] - 2 * (c - x[(int) (n + 1 - i)]) + maxlefttotal[(int) (n - i)]); // Scenario 4
        }

        // Output the final result
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
