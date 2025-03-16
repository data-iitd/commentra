
package main;

import java.util.Scanner;

public class Main {

	public static void out(Object... x) {
		System.out.println(x);
	}

	public static int getInt() {
		Scanner sc = new Scanner(System.in);
		return sc.nextInt();
	}

	public static String getString() {
		Scanner sc = new Scanner(System.in);
		return sc.next();
	}

	// min, max, asub, absなど基本関数
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

	public static int asub(int a, int b) {
		if (a > b) {
			return a - b;
		}
		return b - a;
	}

	public static int abs(int a) {
		if (a >= 0) {
			return a;
		}
		return -a;
	}

	public static void main(String[] args) {
		// Read input values
		int N = getInt(); // Number of passengers
		int C = getInt(); // Bus capacity
		int K = getInt(); // Time window

		// Array to store arrival times
		int[] t = new int[N];
		for (int i = 0; i < N; i++) {
			t[i] = getInt();
		}

		// Sort the arrival times
		sort(t);

		// Initialize variables for the number of buses and passengers in the current bus
		int ans = 1;
		int cnt = 1;
		int end = t[0] + K; // Time when the bus will be full or the time window expires

		// Iterate through the sorted arrival times
		for (int i = 1; i < N; i++) {
			if (cnt < C && t[i] <= end) {
				// The current passenger can fit in the bus
				cnt++;
			} else {
				// The current bus is full or the time window has expired
				// Increment the bus count, reset the count, and update the end time
				cnt = 1;
				end = t[i] + K;
				ans++;
			}
		}

		// Output the number of buses required
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

