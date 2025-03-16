
package main;

import java.util.Scanner;

public class Main {

	public static void out(Object... x) {
		System.out.println(x);
	}

	public static int getInt() {
		Scanner sc = new Scanner(System.in);
		int i = sc.nextInt();
		return i;
	}

	public static String getString() {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		return s;
	}

	public static int max(int a, int b) {
		if (a > b) {
			return a;
		}
		return b;
	}

	public static int min(int a, int b) {
		if (a < b) {
			return a;
		}
		return b;
	}

	public static int abs(int a) {
		if (a >= 0) {
			return a;
		}
		return -a;
	}

	public static void main(String[] args) {
		// Initialize scanner and read input
		Scanner sc = new Scanner(System.in);

		// Read input: N, C, K
		int N = sc.nextInt();
		int C = sc.nextInt();
		int K = sc.nextInt();

		// Initialize array t of size N
		int[] t = new int[N];

		// Read input: t[i] for i from 0 to N-1
		for (int i = 0; i < N; i++) {
			t[i] = sc.nextInt();
		}

		// Sort array t in ascending order
		sort(t);

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
		out(ans);
	}

	public static void sort(int[] t) {
		for (int i = 0; i < t.length; i++) {
			for (int j = i + 1; j < t.length; j++) {
				if (t[i] > t[j]) {
					int temp = t[i];
					t[i] = t[j];
					t[j] = temp;
				}
			}
		}
	}
}

