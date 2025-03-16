
import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws java.lang.Exception{
		// Read input values
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long m = sc.nextLong();
		long mod = sc.nextLong();

		// Initialize C array with base cases
		long[][] C = new long[310][310];
		C[0][0] = 1;
		for(int i=1;i<=n;i++){
			// Initialize i-th row with base cases
			C[i][0] = C[i][i] = 1;

			// Calculate C[i][j] using previous rows
			for(int j=1;j<i;j++)
				C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}

		// Initialize f and pre arrays for base case
		long[][] f = new long[310][310];
		long[][] pre = new long[310][310];
		for(int i=0;i<=m;i++)
			f[1][i] = 1, pre[1][i] = m-i+1;

		// Calculate f and pre arrays for all other rows
		for(int i=2;i<=n+1;i++){
			for(int j=0;j<=m;j++){
				// Calculate f[i][j] using previous rows and pre arrays
				for(int k=1;k<i;k++)
					(f[i][j] += f[i-k][j] * pre[k][j+1] % mod * C[i-2][k-1]) %= mod;
			}

			// Calculate pre[i][j] using previous rows and f arrays
			for(int j=m;j>=0;j--)
				pre[i][j] = (pre[i][j+1] + f[i][j]) % mod;
		}

		// Print the result
		System.out.println(f[n+1][0]);
	}
}

