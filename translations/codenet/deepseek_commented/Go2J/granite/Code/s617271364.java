
import java.util.*;
import java.io.*;

public class s617271364{
    public static void main(String[] args) throws IOException {
        // Read the input values for N, A, B, and C
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int A = Integer.parseInt(input[1]);
        int B = Integer.parseInt(input[2]);
        int C = Integer.parseInt(input[3]);

        // Initialize the array to store the values and a dp array for choices
        int[] arr = new int[N];
        int[] dp = new int[N];
        int ans = 100000;
        int ss = A + B + C;

        // Read the array values from input
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            arr[i] = Integer.parseInt(input[0]);
        }

        // Start the depth-first search to find the minimum cost
        dfs(dp, 0, arr);

        // Print the minimum cost found
        System.out.println(ans);
    }

    // Depth-first search function to explore different combinations of choices
    public static void dfs(int[] dp, int times, int[] arr) {
        if (times >= N) {
            ans = Math.min(ans, calc(dp, arr));
            return;
        }

        for (int i = 0; i < 4; i++) {
            dp[times] = i;
            dfs(dp, times + 1, arr);
        }
    }

    // Function to calculate the cost based on the chosen combinations
    public static int calc(int[] dp, int[] arr) {
        int cost = 0;
        int[] memo = new int[4];

        // Create a memoization array to count the occurrences of each choice
        for (int i = 0; i < dp.length; i++) {
            memo[dp[i]]++;
            if (dp[i] == 1) {
                cost += arr[i];
            } else if (dp[i] == 2) {
                cost += arr[i];
            } else if (dp[i] == 3) {
                cost += arr[i];
            }
        }
        cost += Math.abs(A - cost) + Math.abs(B - cost) + Math.abs(C - cost);

        // Add additional cost for each choice that appears more than once
        for (int i = 1; i < 4; i++) {
            int a = memo[i];
            if (a < 1) {
                cost += 10000;
            } else {
                cost += (a - 1) * 10;
            }
        }

        return cost;
    }
}

