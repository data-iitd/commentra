import java.util.Scanner;

public class Main {
    // Function to solve the problem
    public static void solve() {
        // Initialize answer to 0
        long ans = 0;

        // Read input for number of nodes n
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Calculate contribution of each node to the answer
        for (int i = 1; i <= n; i++) {
            // Contribution of i-th node is i * (n - i + 1)
            ans += i * (long) (n - i + 1);
        }

        // Subtract contribution of edges
        for (int i = 1; i < n; i++) {
            // Read input for two nodes u and v
            int u = scanner.nextInt();
            int v = scanner.nextInt();

            // Find maximum and minimum of u and v
            int a = Math.max(u, v);
            int b = Math.min(u, v);

            // Subtract contribution of edge (u, v) from the answer
            ans -= b * (long) (n - a + 1);
        }

        // Print the answer
        System.out.println(ans);
    }

    public static void main(String[] args) {
        // Set number of test cases to 1 for simplicity
        int t = 1;

        // Solve the problem for each test case
        while (t-- > 0) {
            solve();
        }
    }
}

// <END-OF-CODE>
