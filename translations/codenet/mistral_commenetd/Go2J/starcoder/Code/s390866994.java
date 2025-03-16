
import java.util.*;
import java.io.*;

public class Main {

	// Function to read an integer from standard input
	public static int getInt() {
		Scanner sc = new Scanner(System.in);
		return sc.nextInt();
	}

	// Function to read a string from standard input
	public static String getString() {
		Scanner sc = new Scanner(System.in);
		return sc.next();
	}

	// Function to find the maximum of two integers
	public static int max(int a, int b) {
		if (a > b) {
			return a;
		}
		return b;
	}

	// Function to find the minimum of two integers
	public static int min(int a, int b) {
		if (a < b) {
			return a;
		}
		return b;
	}

	// Function to find the absolute value of an integer
	public static int abs(int a) {
		if (a >= 0) {
			return a;
		}
		return -a;
	}

	// Main function
	public static void main(String[] args) {
		// Initialize scanner and read input
		Scanner sc = new Scanner(System.in);

		// Read input: N, C, K
		int N = getInt();
		int C = getInt();
		int K = getInt();

		// Initialize array t of size N
		int[] t = new int[N];

		// Read input: t[i] for i from 0 to N-1
		for (int i = 0; i < N; i++) {
			t[i] = getInt();
		}

		// Sort array t in ascending order
		Arrays.sort(t);

		// Initialize variables: answer counter ans, counter cnt, and end index end
		int ans = 1;
		int cnt = 1;
		int end = t[0] + K;

		// Iterate through array t from index 1 to N-1
		for (int i = 1; i < N; i++) {
			// If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
			if (cnt < C && t[i] <= end) {
				cnt++;
			} else {
				// Reset counter cnt and update end index end to the current element t[i] plus K
				cnt = 1;
				end = t[i] + K;
				// Increment answer counter ans
				ans++;
			}
		}

		// Print the final answer
		System.out.println(ans);
	}
}

