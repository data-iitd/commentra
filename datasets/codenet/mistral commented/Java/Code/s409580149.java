import java.io.*;
import java.util.*;

public class Main {
	// Declare static variables
	static int n, a[];
	static double dp[][][];

	// Declare static method to solve the problem
	static void solve() {
		// Read input: number of elements in the array 'a'
		n = ni();
		// Read input: array 'a'
		a = na(n);
		// Initialize 3-dimensional dp array with -1
		dp = new double[n+1][n+1][n+1];
		for(int i=0;i<n+1;i++)fill(dp[i], -1);
		// Base case: dp[0][0][0] = 0
		dp[0][0][0] = 0;
		// Initialize counter array 'cnt'
		int cnt[] = new int[3];
		// Count the occurrences of each element in the array 'a'
		for(int i=0;i<n;i++) {
			cnt[a[i]-1]++;
		}
		// Recursive call to calculate the answer
		double ans = rec(cnt[0], cnt[1], cnt[2]);
		// Print the answer
		out.println(ans);
	}

	// Recursive method to calculate the answer
	static double rec(int i, int j, int k) {
		// Base case: if dp[i][j][k] is already calculated, return the value
		if(dp[i][j][k]!= -1) return dp[i][j][k];
		// Calculate the probability p
		double p = ((double)i+j+k)/n;
		// Calculate the probability of the first element pi
		double pi = (double)i/n;
		// Calculate the probability of the second element pj
		double pj = (double)j/n;
		// Calculate the probability of the third element pk
		double pk = (double)k/n;
		// Calculate the answer: sum of probabilities and recursive calls
		double ret = 1/p;
		if(i>0)ret += pi/p * rec(i-1, j, k);
		if(j>0)ret += pj/p * rec(i+1, j-1, k);
		if(k>0)ret += pk/p * rec(i, j+1, k-1);
		// Store the calculated value in dp array
		return dp[i][j][k] = ret;
	}

	// Constant variables and libraries
	static final long mod = (long) 1e9 + 7;
	static final int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
	static final int[] dx8 = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy8 = { -1, 0, 1, -1, 1, -1, 0, 1 };
	static final int inf = Integer.MAX_VALUE / 2;
	static final long linf = Long.MAX_VALUE / 3;
	static final double dinf = Double.MAX_VALUE / 3;
	static final double eps = 1e-10;
	static final double pi = Math.PI;
	static StringBuilder sb = new StringBuilder();
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	// Helper methods
	// ... (the helper methods are not used in this code, so no need to comment them)
}
