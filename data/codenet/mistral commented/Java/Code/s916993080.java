
import java.util.*;
import java.io.*;
import java.lang.*;


public class Main {
	public static void main(String[] args) throws IOException{
		// Initialize scanner object
		Scanner sc = new Scanner(System.in);

		// Read the number of rows from the standard input
		int n = sc.nextInt();

		// Allocate memory for the input array and the dynamic programming table
		int[][] arr = new int[n][3];
		int[][] dp = new int[n][3];

		// Read the input array elements
		for(int i=0;i<n;++i)
			for(int j=0;j<=2;++j) arr[i][j] = sc.nextInt();

		// Initialize the first row of the dynamic programming table
		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][2];

		// Perform dynamic programming for the remaining rows
		for(int i=1;i<n;++i){
			for(int j=0;j<3;++j){
				// Calculate the maximum value for the current cell based on the previous cells
				if (j==0)
					dp[i][j] = Math.max(arr[i][0] + dp[i-1][1],arr[i][0] + dp[i-1][2]);
				if (j==1)
					dp[i][j] = Math.max(arr[i][1] + dp[i-1][0],arr[i][1] + dp[i-1][2]);
				if (j==2)
					dp[i][j] = Math.max(arr[i][2] + dp[i-1][1],arr[i][2] + dp[i-1][0]);
			}
		}

		// Find the maximum value in the last row
		int max = -1;
		for(int i=0;i<3;++i)
			if (dp[n-1][i] > max) max = dp[n-1][i];

		// Print the maximum value
		System.out.println(max);

		// Close the scanner object
		sc.close();
	}

	static class Scanner {
		static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		static StringTokenizer tokenizer = new StringTokenizer("");

		static String next() throws IOException {
			while (!tokenizer.hasMoreTokens())
				tokenizer = new StringTokenizer(reader.readLine());
			return tokenizer.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		static double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		static long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		static float nextFloat() throws IOException {
			return Float.parseFloat(next());
		}
	}
}