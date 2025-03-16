import java.util.*; // Importing the utility classes for input/output operations

public class Main {
    public static void main(String[] args) {
        long mod = (long) 1e9 + 7; // Define the modulo constant
        Scanner sc = new Scanner(System.in); // Initialize the Scanner object to read input
        int n = sc.nextInt(); // Read the integer n from input
        int k = sc.nextInt(); // Read the integer k from input
        sc.close(); // Close the Scanner to free up resources

        ArrayList<Integer> len = new ArrayList<>(); // Create an ArrayList to store segment lengths
        int l = 1; // Initialize the starting point of the segment
        while (l <= n) {
            int r = n / (n / l); // Calculate the ending point of the segment
            len.add(r - l + 1); // Add the length of the segment to the ArrayList
            l = r + 1; // Move to the next segment
        }

        int q = len.size(); // Store the size of the len ArrayList in q
        long[] dp = new long[k * (q + 1)]; // Initialize the dp array with sufficient size

        // Calculate the prefix sums of the lengths and store them in the dp array
        for (int j = 1; j <= q; j++) {
            dp[j] = len.get(j - 1) + dp[j - 1];
        }

        // Main loop to calculate the dynamic programming values for k iterations
        for (int i = 1; i < k; i++) {
            for (int j = 1; j <= q; j++) {
                dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len.get(j - 1);
                dp[i * (q + 1) + j] %= mod; // Ensure the value does not exceed the modulo
            }
        }

        // Print the result stored in the dp array
        System.out.println(dp[k * (q + 1) - 1]);
    }
}
