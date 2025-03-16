import java.util.*;

public class Main {
    // Global variables to store input values
    static int N, ss, ans, A, B, C;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the input values for N, A, B, and C
        String[] X = sc.nextLine().split(" ");
        N = Integer.parseInt(X[0]);
        A = Integer.parseInt(X[1]);
        B = Integer.parseInt(X[2]);
        C = Integer.parseInt(X[3]);

        // Initialize the array to store the values and a dp array for choices
        int[] arr = new int[N];
        int[] dp = new int[N];
        ans = 10000;
        ss = A + B + C;

        // Read the array values from input
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(sc.nextLine());
        }

        // Start the depth-first search to find the minimum cost
        dfs(dp, 0, arr);

        // Print the minimum cost found
        System.out.println(ans);
    }

    // Depth-first search function to explore different combinations of choices
    static void dfs(int[] dp, int times, int[] arr) {
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
    static int calc(int[] dp, int[] arr) {
        int cost = 0, AA = 0, BB = 0, CC = 0;

        // Create a memoization array to count the occurrences of each choice
        int[] memo = new int[4];
        for (int i = 0; i < dp.length; i++) {
            memo[dp[i]]++;
            if (dp[i] == 1) {
                AA += arr[i];
            } else if (dp[i] == 2) {
                BB += arr[i];
            } else if (dp[i] == 3) {
                CC += arr[i];
            }
        }
        cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

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

    // Helper functions to calculate absolute value
    static int abs(int a) {
        return a < 0 ? -a : a;
    }
}

// <END-OF-CODE>
