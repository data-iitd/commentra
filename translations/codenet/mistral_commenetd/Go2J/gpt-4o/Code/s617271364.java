// Import necessary packages
import java.util.*;

public class Main {
    // Global variables
    static int N, ss, ans, A, B, C;

    public static void main(String[] args) {
        // Create a scanner for input
        Scanner sc = new Scanner(System.in);

        // Read the first line which contains the number of tests and the number of elements in the array
        String[] X = sc.nextLine().split(" ");
        N = Integer.parseInt(X[0]);
        A = Integer.parseInt(X[1]);
        B = Integer.parseInt(X[2]);
        C = Integer.parseInt(X[3]);
        ss = A + B + C;

        // Initialize the array and the dp array
        int[] arr = new int[N];
        int[] dp = new int[N];

        // Initialize the answer variable
        ans = 10000;

        // Read the next N lines which contain the elements of the array
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(sc.nextLine());
        }

        // Call the dfs function to find the minimum cost
        dfs(dp, 0, arr);

        // Print the answer
        System.out.println(ans);
    }

    // dfs function is used for depth-first search
    static void dfs(int[] dp, int times, int[] arr) {
        // Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
        if (times >= N) {
            ans = Math.min(ans, calc(dp, arr));
            return;
        }

        // Recursive case: try all possible values for the current element
        for (int i = 0; i < 4; i++) {
            dp[times] = i;
            dfs(dp, times + 1, arr);
        }
    }

    // calc function is used to calculate the cost
    static int calc(int[] dp, int[] arr) {
        // Initialize the cost and the variables to store the sum of elements with each value in dp
        int cost = 0, AA = 0, BB = 0, CC = 0;

        // Initialize the memo array to store the number of elements with each value in dp
        int[] memo = new int[4];

        // Iterate through the dp array and update the variables
        for (int i = 0; i < dp.length; i++) {
            int a = dp[i];
            memo[a]++;
            if (a == 1) {
                AA += arr[i];
            } else if (a == 2) {
                BB += arr[i];
            } else if (a == 3) {
                CC += arr[i];
            }
        }

        // Calculate the cost based on the variables
        cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

        // Update the cost based on the number of elements with each value in dp
        for (int i = 1; i < 4; i++) {
            int a = memo[i];
            if (a < 1) {
                cost += 10000;
            } else {
                cost += (a - 1) * 10;
            }
        }

        // Return the cost
        return cost;
    }

    // Helper functions
    static int abs(int a) {
        return a < 0 ? -a : a;
    }
}
