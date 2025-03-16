// I/O
import java.io.*;
import java.util.*;

public class Main {
	// Scanner
	static Scanner sc = new Scanner(System.in);

	// Helper functions for reading different data types from the scanner
	static String nextStr() {
		return sc.next();
	}

	static int nextInt() {
		return Integer.parseInt(nextStr());
	}

	static float nextFloat() {
		return Float.parseFloat(nextStr());
	}

	static double nextDouble() {
		return Double.parseDouble(nextStr());
	}

	static long nextLong() {
		return Long.parseLong(nextStr());
	}

	static int[] nextIntArr(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}

	static long[] nextLongArr(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLong();
		}
		return arr;
	}

	static String[] nextStrArr(int n) {
		String[] arr = new String[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextStr();
		}
		return arr;
	}

	static int[][] nextIntArrArr(int n, int m) {
		int[][] arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			arr[i] = nextIntArr(m);
		}
		return arr;
	}

	static long[][] nextLongArrArr(int n, int m) {
		long[][] arr = new long[n][m];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLongArr(m);
		}
		return arr;
	}

	static String[][] nextStrArrArr(int n, int m) {
		String[][] arr = new String[n][m];
		for (int i = 0; i < n; i++) {
			arr[i] = nextStrArr(m);
		}
		return arr;
	}

	// Arithmetic
	static int max(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m < i) {
				m = i;
			}
		}
		return m;
	}

	static int min(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m > i) {
				m = i;
			}
		}
		return m;
	}

	static int abs(int x) {
		return x < 0? -x : x;
	}

	static int pow(int x, int y) {
		int res = 1;
		for (int i = 0; i < y; i++) {
			res *= x;
		}
		return res;
	}

	static int ceil(int a, int b) {
		if (a % b == 0) {
			return a / b;
		} else {
			return a / b + 1;
		}
	}

	// Sort
	static class RuneSlice {
		private char[] arr;

		RuneSlice(char[] arr) {
			this.arr = arr;
		}

		public int length() {
			return arr.length;
		}

		public int compare(int i, int j) {
			return arr[i] - arr[j];
		}

		public void swap(int i, int j) {
			char tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	// Main
	public static void main(String[] args) {
		// Read input values N, D, and A from the scanner
		int N = nextInt();
		int D = nextInt();
		int A = nextInt();

		// Initialize a slice of Mon structures called M
		Mon[] M = new Mon[N];

		// Read x and h values for each Mon and store them in the M slice
		for (int i = 0; i < N; i++) {
			M[i] = new Mon(nextInt(), nextInt());
		}

		// Sort the M slice based on x-coordinates
		Arrays.sort(M, new Comparator<Mon>() {
			public int compare(Mon a, Mon b) {
				return a.x - b.x;
			}
		});

		// Initialize an empty priority queue called q
		Queue q = new Queue();

		// Initialize answer variable ans to 0 and total variable total to 0
		int ans = 0;
		int total = 0;

		// Iterate through each Mon in the sorted M slice
		for (int i = 0; i < N; i++) {
			// Current Mon
			Mon m = M[i];

			// While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
			while (!q.isEmpty() && q.first().x < m.x) {
				// Pop the first Node from the priority queue
				total -= q.pop().h;
			}

			// If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
			if (total < m.h) {
				int damage = m.h - total;
				ans += damage;
				q.push(new Node(m.x + 2 * D, damage));
				total += damage;
			}
		}

		// Print the answer
		System.out.println(ans);
	}

	// Data structures
	static class Mon {
		int x, h;

		Mon(int x, int h) {
			this.x = x;
			this.h = h;
		}
	}

	static class Node {
		int x, h;

		Node(int x, int h) {
			this.x = x;
			this.h = h;
		}
	}

	static class Queue {
		Node[] arr;

		Queue() {
			arr = new Node[0];
		}

		void push(Node v) {
			arr = Arrays.copyOf(arr, arr.length + 1);
			arr[arr.length - 1] = v;
		}

		Node first() {
			return arr[0];
		}

		Node pop() {
			Node res = arr[0];
			arr = Arrays.copyOf(arr, arr.length - 1);
			return res;
		}

		boolean isEmpty() {
			return arr.length == 0;
		}
	}
}

