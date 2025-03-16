// Go: //go:generate echo "https://atcoder.jp/contests/dp/tasks/dp_a"
import java.util.Scanner;

public class Main {
    
    // iabs returns the absolute value of an integer.
    private static int iabs(int x) {
        return x < 0 ? -x : x;
    }

    // solve calculates the minimum cost to reach the last stone using dynamic programming.
    private static int solve(int n, int[] heights) {
        // Initialize the minimum cost array with a large value.
        int[] t = new int[n + 1];
        for (int i = 0; i < t.length; i++) {
            t[i] = Integer.MAX_VALUE;
        }

        // The cost to reach the first stone is 0.
        t[0] = 0;

        // Calculate the minimum cost to reach each stone.
        for (int i = 1; i < n; i++) {
            // Cost to reach the current stone from the previous stone.
            t[i] = Math.min(t[i], t[i - 1] + iabs(heights[i] - heights[i - 1]));
            // Cost to reach the current stone from two stones back (if possible).
            if (i > 1) {
                t[i] = Math.min(t[i], t[i - 2] + iabs(heights[i] - heights[i - 2]));
            }
        }

        // Return the minimum cost to reach the last stone.
        return t[n - 1];
    }

    // main function reads input, calls the solve function, and prints the result.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = sc.nextInt();
        }
        int ans = solve(n, heights);
        System.out.println(ans);
        sc.close();
    }
}

// <END-OF-CODE>
