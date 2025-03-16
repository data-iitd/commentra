
import java.util.*;

public class Main {
	public static void main(String[] args) {
		// Read input values of n and p from the user
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int p = sc.nextInt();
		// Initialize b and c to count the number of even and odd elements in the array a
		int b = 0, c = 0;
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			if (a[i] % 2 == 0) {
				b++;
			}
			else {
				c++;
			}
			// Add comment explaining what is being done
			// Read an element from the array a and check if it is even or odd
			// Increment the corresponding counter (b for even and c for odd)
		}

		// Calculate the sum of 2^b and c
		int bsum = 1, csum = 0;
		bsum = (int) Math.pow(2, b);

		// Calculate the sum of nCr(c, i) for i from 0 to c
		if (p == 0) {
			for (int i = 0; i <= c; i++) {
				if (i % 2 == 0) {
					csum += nCr(c, i);
				}
				// Add comment explaining what is being done
				// If i is even, add nCr(c, i) to csum
			}
		}
		else {
			for (int i = 0; i <= c; i++) {
				if (i % 2 == 1) {
					csum += nCr(c, i);
				}
				// Add comment explaining what is being done
				// If i is odd, add nCr(c, i) to csum
			}
		}

		// Multiply bsum and csum and store the result in ans
		int ans = bsum * csum;
		// Add comment explaining what is being done
		// Multiply bsum and csum to get the final answer

		// Print the final answer
		System.out.println(ans);
	}

	// Function to calculate nPr (n choose r)
	public static int nPr(int n, int r) {
		// Initialize result to 1
		int res = 1;
		// Iterate from 0 to r and multiply result with (n-i)
		for (int i = 0; i < r; i++) {
			res *= (n - i);
			// Add comment explaining what is being done
			// Multiply result with factorial of (n-i)
			// to get the value of nPr(n, r)
			//System.out.println("Calculating nPr(" + n + ", " + r + ") = " + res);
		}

		// Return the result
		return res;
	}

	// Function to calculate nCr (n choose r)
	public static int nCr(int n, int r) {
		// Initialize result to 1
		double res = 1;
		// Iterate from 0 to r and multiply result with (n-i) and divide by (i+1)
		for (int i = 0; i < r; i++) {
			res *= (n - i);
			res /= (i+1);
			// Add comment explaining what is being done
			// Multiply result with factorial of (n-i) and divide by (i+1)
			// to get the value of nCr(n, r)
			//System.out.println("Calculating nCr(" + n + ", " + r + ") = " + res);
		}
		// Convert the double result to int and return it
		return (int)res;
	}
}

