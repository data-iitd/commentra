// Import necessary Java classes for input/output operations and utility functions.
import java.io.*;
import java.util.*;

// Define the public class Main which contains the main logic of the program.
public class Main {

    // Declare static variables to store the number of elements and the array of elements.
    static int n, a[];
    // Declare a 3D array used for dynamic programming to store intermediate results.
    static double dp[][][];
}

// Reads the input number of elements n and the array a[].
static void solve() {
    n = ni();
    a = na(n);
    // Initialize the dp array with -1 to indicate uncomputed states.
    dp = new double[n+1][n+1][n+1];
    for(int i=0;i<n+1;i++) fill(dp[i], -1);
    // Set the base case for the dynamic programming.
    dp[0][0][0] = 0;
    // Count the occurrences of each element in the array a[].
    int cnt[] = new int[3];
    for(int i=0;i<n;i++) {
        cnt[a[i]-1]++;
    }
    // Call the rec() function to compute the result and print it.
    double ans = rec(cnt[0], cnt[1], cnt[2]);
    out.println(ans);
}

// Implements the recursive function for dynamic programming.
static double rec(int i, int j, int k) {
    // Check if the result for the current state (i, j, k) is already computed.
    if(dp[i][j][k] != -1) return dp[i][j][k];
    // Initialize the return value.
    double ret = 0;
    // Compute the probability of each type of element.
    double p = ((double)i+j+k)/n;
    double pi = (double)i/n;
    double pj = (double)j/n;
    double pk = (double)k/n;
    // Compute the expected value.
    ret += 1/p;
    if(i>0) ret += pi/p * rec(i-1, j, k);
    if(j>0) ret += pj/p * rec(i+1, j-1, k);
    if(k>0) ret += pk/p * rec(i, j+1, k-1);
    // Store the result in dp[i][j][k].
    return dp[i][j][k] = ret;
}

// Reads input from INPUT or standard input.
public static void main(String[] args) throws Exception {
    is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
    out = new PrintWriter(System.out);
    solve();
    out.flush();
}