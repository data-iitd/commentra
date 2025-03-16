
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

// Global variables
static int N, ss, ans, A, B, C;

public class s617271364{
    public static void main(String[] args) throws Exception {
        // Initialize the global variables
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] X = br.readLine().split(" ");
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
            String[] Y = br.readLine().split(" ");
            arr[i] = Integer.parseInt(Y[0]);
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
            // Update the variables based on the current value in dp
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
        cost += Math.abs(A - AA) + Math.abs(B - BB) + Math.abs(C - CC);

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
}

// Helper functions
static String nextLine() throws IOException {
    return br.readLine();
}

static int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

static int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

static int com(int a, int b) {
    if (a > b) {
        return 0;
    }
    return 0; //Math.abs(a - b);
}

static int abs(int a) {
    if (a < 0) {
        return a * -1;
    }
    return a;
}

static int sum(int[] a) {
    int sum = 0;
    for (int num : a) {
        sum += num;
    }
    return sum;
}

