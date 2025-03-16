
// Package main is the entry point of the program
package main

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

// scan function is used to read one line at a time
class Scanner {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer("");

    String next() {
        while (!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }
}

// Global variables
class Global {
    int N, ss, ans, A, B, C;
}

// sort function is used to sort an array in ascending order
class IntSlice implements Comparable<IntSlice> {
    int[] arr;

    IntSlice(int[] arr) {
        this.arr = arr;
    }

    @Override
    public int compareTo(IntSlice o) {
        return Integer.compare(arr[0], o.arr[0]);
    }
}

public class Main {
    // Global variables
    static Global g = new Global();

    // scan function is used to read one line at a time
    static Scanner sc = new Scanner();
    static PrintWriter wtr = new PrintWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) {
        // Read the first line which contains the number of tests and the number of elements in the array
        String[] X = sc.next().split(" ");

        // Initialize the global variables
        g.N = sc.nextInt();
        g.A = sc.nextInt();
        g.B = sc.nextInt();
        g.C = sc.nextInt();
        g.ss = g.A + g.B + g.C;

        // Initialize the array and the dp array
        int[] arr = new int[g.N];
        int[] dp = new int[g.N];

        // Initialize the answer variable
        g.ans = 10000;

        // Read the next N lines which contain the elements of the array
        for (int i = 0; i < g.N; i++) {
            arr[i] = sc.nextInt();
        }

        // Call the dfs function to find the minimum cost
        dfs(dp, 0, arr);

        // Print the answer
        wtr.println(g.ans);

        // Flush the buffer
        wtr.flush();
    }

    // dfs function is used for depth-first search
    static void dfs(int[] dp, int times, int[] arr) {
        // Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
        if (times >= g.N) {
            g.ans = min(g.ans, calc(dp, arr));
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
        cost += Math.abs(g.A - AA) + Math.abs(g.B - BB) + Math.abs(g.C - CC);

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
        return 0; //abs(a - b)
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
}

