public class Main {
    // Function to return the smaller value between two integers
    public static int chmin(int a, int b) {
        if (a > b)
            return b;
        else
            return a;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of elements
        int[] dp = new int[n];      // Declare the dp array
        int[] h = new int[n];       // Declare the h array
        for (int i = 0; i < n; ++i)
            dp[i] = 10000;         // Initialize the dp array to a large value

        for (int i = 0; i < n; ++i)
            h[i] = scanner.nextInt(); // Read the heights into the h array

        dp[0] = 0; // Starting point with no cost
        for (int i = 1; i < n; ++i) {
            if (i == 1)
                dp[1] = Math.abs(h[1] - h[0]); // Cost to reach the first step
            else
                dp[i] = chmin(dp[i - 1] + Math.abs(h[i] - h[i - 1]), dp[i - 2] + Math.abs(h[i] - h[i - 2])); // Calculate the minimum cost to reach the current step
        }
        System.out.println(dp[n - 1]); // Print the minimum cost to reach the last step
    }
}
