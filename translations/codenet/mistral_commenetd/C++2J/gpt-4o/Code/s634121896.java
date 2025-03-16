import java.util.*;

public class Main {
    static final long MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Run the solve function for each test case (if any) or the main input
        int q = 1;
        // q = scanner.nextInt(); // Uncomment if you want to read the number of test cases
        while (q-- > 0) {
            solve(scanner);
        }
        scanner.close();
    }

    static void solve(Scanner scanner) {
        // Input the number of elements
        int n = scanner.nextInt();
        // Initialize the list to store the numbers
        long[] nums = new long[n];
        // Initialize variables to keep track of the last number
        long last = 0;
        for (int i = 0; i < n; i++) {
            // Read the numbers from the input
            nums[i] = scanner.nextLong();
            // Update the last variable
            last = nums[i];
        }
        // Initialize an array to store the prefix sum of the number of ways to reach each index
        long[] dp = new long[n + 1];
        // Set the initial value of the prefix sum at index 0
        dp[0] = 1;
        // Initialize two maps to keep track of the previous index of each number and the number of ways to reach the previous index
        Map<Long, Long> kek = new HashMap<>();
        Map<Long, Integer> prev = new HashMap<>();
        // Iterate through the numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            // Calculate the prefix sum at the current index
            dp[i] = dp[i - 1] + (prev.getOrDefault(nums[i - 1], -1) != i - 1 ? kek.getOrDefault(nums[i - 1], 0L) : 0);
            dp[i] %= MOD;
            // Update the maps
            kek.put(nums[i - 1], dp[i]);
            prev.put(nums[i - 1], i);
        }
        // Output the result
        System.out.println(dp[n]);
    }
}

// <END-OF-CODE>
