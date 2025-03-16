import java.util.*;

public class Main {
    // Constants for mathematical operations and limits
    static final long INF = 1e9 + 228; // Infinity constant
    static final long INFLL = 1e18; // Long long infinity constant
    static final long MOD = 1e9 + 7; // Modulus for operations
    static final double eps = 1e-6; // Epsilon for floating point comparisons
    static final double eps2 = 1e-9; // Another epsilon for precision
    static final long MOD2 = 998244353; // Another modulus constant
    static final long dosz = 5e5; // Size constant
    static final long SZ = (1 << 18); // Size constant for bit manipulation
    static final double PI = Math.atan2(0, -1); // Pi constant

    // Function to optimize input/output
    static void fast_io() {
        // In Java, we typically don't need to optimize input/output like in C++
    }

    // Main logic to solve the problem
    static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Input number of elements
        long[] nums = new long[n]; // Array to store the elements
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextLong(); // Input each element
        }

        // Dynamic programming array to store results
        long[] dp = new long[n + 1];
        dp[0] = 1; // Base case: one way to select zero elements
        Map<Long, Long> kek = new HashMap<>(); // Map to store the last occurrence of each number
        Map<Long, Integer> prev = new HashMap<>(); // Map to store the previous index of each number

        // Fill the dynamic programming array
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + (prev.getOrDefault(nums[i - 1], -1) != i - 1 ? kek.getOrDefault(nums[i - 1], 0) : 0);
            dp[i] %= MOD; // Apply modulus to avoid overflow
            kek.put(nums[i - 1], dp[i]); // Update the last occurrence
            prev.put(nums[i - 1], i); // Update the previous index
        }

        System.out.println(dp[n]); // Output the result
    }

    // Main function
    public static void main(String[] args) {
        fast_io(); // Optimize input/output
        Random rand = new Random(); // Seed the random number generator
        System.out.printf("%.12f\n", 0.0); // Set output precision
        int q = 1; // Number of queries
        // Uncomment the following line to read the number of queries
        // q = scanner.nextInt();
        while (q-- > 0) {
            solve(); // Solve the problem for each query
        }
    }
}

// <END-OF-CODE>
