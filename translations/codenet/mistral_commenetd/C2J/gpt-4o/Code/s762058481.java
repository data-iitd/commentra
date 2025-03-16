import java.util.Scanner;

public class Main {
    // Function to return the minimum of two integers
    public static int chmin(int a, int b) {
        // If 'a' is greater than 'b', return 'b'
        if (a > b)
            return b;
        // Otherwise, return 'a'
        else
            return a;
    }

    // Main function
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements 'n' from the standard input
        int n = scanner.nextInt();

        // Allocate memory for two arrays 'dp' and 'h' of size 'n'
        int[] dp = new int[n];
        int[] h = new int[n];

        // Initialize all elements of 'dp' to a large value
        for (int i = 0; i < n; ++i)
            dp[i] = 10000;

        // Read the height of each element from the standard input
        for (int i = 0; i < n; ++i)
            h[i] = scanner.nextInt();

        // Initialize the first element of 'dp' to 0
        dp[0] = 0;

        // Iterate through the array 'dp' from the second element to the last
        for (int i = 1; i < n; ++i) {
            // Calculate the cost to reach the current index 'i' from the previous index 'i - 1'
            if (i == 1)
                dp[1] = Math.abs(h[1] - h[0]);
            // Calculate the minimum cost to reach the current index 'i' from the previous index 'i - 1' or the previous previous index 'i - 2'
            else
                dp[i] = chmin(dp[i - 1] + Math.abs(h[i] - h[i - 1]), dp[i - 2] + Math.abs(h[i] - h[i - 2]));
        }

        // Print the minimum cost to reach the last index 'n - 1'
        System.out.println(dp[n - 1]);

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
