
import java.util.*;

public class s788730767{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int p = sc.nextInt();
		int[] a = new int[n];
		int b = 0, c = 0;

		// Read input array and count the number of even and odd numbers
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			if (a[i] % 2 == 0) {
				b++;
			}
			else {
				c++;
			}
		}

		// Calculate the number of subsets with even and odd numbers
		long bsum = (long)Math.pow(2, b);
		long csum = 0;

		if (p == 0) {
			// Sum combinations where the number of elements is even
			for (int i = 0; i <= c; i++) {
				if (i % 2 == 0) {
					csum += nCr(c, i);
				}
			}
		}
		else {
			// Sum combinations where the number of elements is odd
			for (int i = 0; i <= c; i++) {
				if (i % 2 == 1) {
					csum += nCr(c, i);
				}
			}
		}

		// Calculate the final answer as the product of bsum and csum
		long ans = bsum * csum;
		System.out.println(ans);
	}

	// Function to calculate nCr
	public static long nCr(int n, int r) {
		double res = 1;
		for (int i = 0; i < r; i++) {
			res *= (n - i);
			res /= (i+1);
		}
		return (long)res;
	}
}

