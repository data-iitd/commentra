import java.util.*;

public class Main {
    // Constants for mathematical operations and limits
    static final long INF = 1e9 + 228; // Infinity constant
    static final long INFLL = 1e18; // Long long infinity constant
    static final long MOD = 1_000_000_007; // Modulus for operations
    static final double EPS = 1e-6; // Epsilon for floating point comparisons
    static final double EPS2 = 1e-9; // Another epsilon for precision
    static final long MOD2 = 998244353; // Another modulus constant

    // Function to solve the problem
    static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Input number of elements
        int[] nums = new int[n]; // Array to store the elements
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt(); // Input each element
        }

        // Dynamic programming array to store results
        long[] dp = new long[n + 1];
        dp[0] = 1; // Base case: one way to select zero elements
        Map<Integer, Long> kek = new HashMap<>(); // Map to store the last occurrence of each number
        Map<Integer, Integer> prev = new HashMap<>(); // Map to store the previous index of each number

        // Fill the dynamic programming array
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + (prev.getOrDefault(nums[i - 1], -1) != i - 1 ? kek.getOrDefault(nums[i - 1], 0L) : 0);
            dp[i] %= MOD; // Apply modulus to avoid overflow
            kek.put(nums[i - 1], dp[i]); // Update the last occurrence
            prev.put(nums[i - 1], i); // Update the previous index
        }

        System.out.println(dp[n]); // Output the result
    }

    // Main function
    public static void main(String[] args) {
        // Optimize input/output
        Scanner scanner = new Scanner(System.in);
        int q = 1; // Number of queries
        // Uncomment the following line to read the number of queries
        // q = scanner.nextInt();
        while (q-- > 0) {
            solve(); // Solve the problem for each query
        }
    }
}

// <END-OF-CODE>
