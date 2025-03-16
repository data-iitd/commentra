import java.util.Scanner;

public class Main {
    // Constants for limits and modulo
    static final int N = (int) (2e5 + 10);
    static final int K = (int) (2e6 + 10);
    static final int MOD = (int) (1e9 + 7);
    static final int INF = (int) (1e9 + 5);
    static final long INF64 = (long) 2e18;

    // Function to solve the problem
    static void solve(Scanner scanner) {
        long ans = 0; // Initialize the answer variable
        int n = scanner.nextInt(); // Read the number of nodes

        // Calculate the contribution of each node to the answer
        for (int i = 1; i <= n; i++) {
            ans += i * 1L * (n - i + 1); // Contribution of node i
        }

        // Adjust the answer based on the edges between nodes
        for (int i = 1; i < n; i++) {
            int u = scanner.nextInt(); // Read the edge connecting nodes u and v
            int v = scanner.nextInt();
            int a = Math.max(u, v); // Determine the maximum node
            int b = Math.min(u, v); // Determine the minimum node
            ans -= b * 1L * (n - a + 1); // Subtract the contribution of the edge
        }

        // Output the final answer
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Enable fast input/output

        int t = 1; // For now, we will just run one test case
        // t = scanner.nextInt(); // Uncomment to read the number of test cases
        while (t-- > 0) {
            solve(scanner); // Call the solve function for each test case
        }
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
