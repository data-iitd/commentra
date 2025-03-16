
import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// Read the number of elements in the array
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();

		// Read the elements of the array
		long long a[] = new long long[n+1];
		for(int i = 1;i<=n;i++){
			a[i] = sc.nextLong();
		}

		// Initialize prefix and suffix arrays
		long long pre[] = new long long[n+1];
		long long last[] = new long long[n+1];

		// Initialize sum of prefix and suffix arrays to zero
		long long sumpre = 0, sumlast = 0;

		// Calculate prefix sum
		for(int i = 1;i<n;i++){
			sumpre += a[i];
			pre[i] = sumpre;
		}

		// Calculate suffix sum
		for(int i = n;i>0;i--){
			sumlast += a[i];
			last[i] = sumlast;
		}

		// Initialize difference as maximum long long value
		long long d = (1LL << 60);

		// Find the minimum difference between prefix and suffix sums
		for(int i = 1;i<n;i++){
			d = Math.min(d, Math.abs(pre[i] - last[i+1]));
		}

		// Print the minimum difference
		System.out.println(d);
	}
}

