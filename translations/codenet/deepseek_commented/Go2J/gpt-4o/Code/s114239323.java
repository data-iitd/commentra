import java.util.Scanner;

public class Main {
    // Utility function to find the absolute value of an integer
    public static int abs(int a) {
        return a < 0 ? -a : a;
    }

    // Utility function to find the minimum value in an array of integers
    public static int min(int[] a) {
        int r = a[0];
        for (int i = 1; i < a.length; i++) {
            if (r > a[i]) {
                r = a[i];
            }
        }
        return r;
    }

    // Main function to solve the problem
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reads the number of steps N
        int N = scanner.nextInt(); // Comment: Reads the number of steps N
        
        // Reads the list of heights h
        int[] h = new int[N]; // Comment: Initializes the heights array
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt(); // Comment: Reads the list of heights h
        }
        
        // Initializes the DP array with zeros
        int[] dp = new int[N]; // Comment: Initializes the DP array with zeros
        for (int i = 0; i < N; i++) {
            dp[i] = 0;
        }
        
        // Sets the cost to reach the second step
        dp[1] = abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
        
        // Computes the minimum cost to reach each step using dynamic programming
        for (int i = 2; i < N; i++) {
            dp[i] = min(new int[]{
                dp[i - 1] + abs(h[i] - h[i - 1]),
                dp[i - 2] + abs(h[i] - h[i - 2])
            });
        }
        
        // Prints the minimum cost to reach the last step
        System.out.println(dp[N - 1]); // Comment: Prints the minimum cost to reach the last step
    }
}
