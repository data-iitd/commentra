import java.util.Scanner;

public class Main {
    // Reads the next integer from the input
    static int nextInt() {
        return nextInt(); // Comment: Reads the next integer from the input
    }

    // Reads a slice of integers of length N
    static int[] nextInts(int N) {
        return nextInts(N); // Comment: Reads a slice of integers of length N
    }

    // Main function to solve the problem
    public static void main(String[] args) {
        // Reads the number of steps N
        int N = nextInt(); // Comment: Reads the number of steps N
        
        // Reads the list of heights h
        int[] h = nextInts(N); // Comment: Reads the list of heights h
        
        // Initializes the DP array with zeros
        int[] dp = new int[N]; // Comment: Initializes the DP array with zeros
        for (int i = 0; i < N; i++) {
            dp[i] = 0;
        }
        
        // Sets the cost to reach the second step
        dp[1] = Math.abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
        
        // Computes the minimum cost to reach each step using dynamic programming
        for (int i = 2; i < N; i++) {
            dp[i] = Math.min(dp[i - 1] + Math.abs(h[i] - h[i - 1]),
                             dp[i - 2] + Math.abs(h[i] - h[i - 2]));
        }
        
        // Prints the minimum cost to reach the last step
        System.out.println(dp[N-1]); // Comment: Prints the minimum cost to reach the last step
    }

    // Utility function to find the absolute value of an integer
    static int Abs(int a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    // Utility function to find the maximum value in a slice of integers
    static int Max(int[] a) {
        int r = a[0];
        for (int i = 0; i < a.length; i++) {
            if (r < a[i]) {
                r = a[i];
            }
        }
        return r;
    }

    // Utility function to find the minimum value in a slice of integers
    static int Min(int[] a) {
        int r = a[0];
        for (int i = 0; i < a.length; i++) {
            if (r > a[i]) {
                r = a[i];
            }
        }
        return r;
    }

    // Utility function to calculate the sum of a slice of integers
    static int Sum(int[] a) {
        int r = 0;
        for (int i : a) {
            r += i;
        }
        return r;
    }

    // Pair class to represent a pair of integers
    static class Pair {
        int a, b;
        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    // Pairs class to represent a slice of Pair
    static class Pairs extends java.util.ArrayList<Pair> {
        // Len method to get the length of the Pairs slice
        int Len() {
            return this.size();
        }

        // Swap method to swap two elements in the Pairs slice
        void Swap(int i, int j) {
            Pair temp = this.get(i);
            this.set(i, this.get(j));
            this.set(j, temp);
        }

        // Less method to compare two elements in the Pairs slice
        boolean Less(int i, int j) {
            return this.get(i).b < this.get(j).b;
        }
    }

    // Variable to hold the nextReader function
    static Scanner scanner = new Scanner(System.in);

    // Initializes the nextReader function
    static {
        scanner = new Scanner(System.in);
    }

    // nextString function to read the next string
    static String nextString() {
        return scanner.next();
    }

    // nextInt64 function to read the next 64-bit integer
    static long nextInt64() {
        return scanner.nextLong();
    }

    // nextInt function to read the next integer
    static int nextInt() {
        return scanner.nextInt();
    }

    // nextInts function to read a slice of integers of length N
    static int[] nextInts(int n) {
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = nextInt();
        }
        return r;
    }

    // nextStrings function to read a slice of strings of length N
    static String[] nextStrings(int n) {
        String[] r = new String[n];
        for (int i = 0; i < n; i++) {
            r[i] = nextString();
        }
        return r;
    }

    // nextFloat64 function to read the next float64
    static double nextFloat64() {
        return scanner.nextDouble();
    }
}
