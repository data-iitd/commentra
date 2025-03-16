package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize input/output handling
		IO io = new IO();
		defer io.flush();

		// Read the number of elements
		int n = io.nextInt();

		// Create a slice to hold the input integers
		int[] aa = new int[n];

		// Read each integer and store it in the slice
		for (int i = 0; i < n; i++) {
			aa[i] = io.nextInt();
		}

		// Compute the cumulative sum of the input integers
		int[] cumsum = CumSum(aa);

		// Initialize the answer with a large value
		int ans = 2020202020;

		// Iterate through the cumulative sums to find the minimum difference
		for (int i = 1; i < cumsum.length-1; i++) {
			ans = Math.min(ans, Math.abs(cumsum[cumsum.length-1]-cumsum[i]-(cumsum[i]-cumsum[0])));
		}

		// Output the final answer
		io.println(ans);
	}

	// Io struct for handling input and output
	static class IO {
		private BufferedReader reader;
		private BufferedWriter writer;
		private StringTokenizer tokenizer;

		public IO() {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new BufferedWriter(new OutputStreamWriter(System.out));
			tokenizer = new StringTokenizer("");
		}

		public void flush() throws IOException {
			writer.flush();
		}

		public String next() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				tokenizer = new StringTokenizer(reader.readLine());
			}
			return tokenizer.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public String nextLine() throws IOException {
			return reader.readLine();
		}

		public void println(Object... objects) throws IOException {
			StringBuilder builder = new StringBuilder();
			for (int i = 0; i < objects.length; i++) {
				if (i!= 0) {
					builder.append(" ");
				}
				builder.append(objects[i]);
			}
			writer.write(builder.toString());
			writer.write("\n");
		}
	}

	// Abs returns the absolute value of an integer
	static int Abs(int a) {
		if (a >= 0) {
			return a;
		} else {
			return -a;
		}
	}

	// Pow calculates p raised to the power of q
	static int Pow(int p, int q) {
		return (int) Math.pow(p, q);
	}

	// Min returns the minimum value from a list of integers
	static int Min(int... nums) {
		if (nums.length == 0) {
			throw new IllegalArgumentException("function min() requires at least one argument.");
		}
		int res = nums[0];
		for (int i = 0; i < nums.length; i++) {
			res = Math.min(res, nums[i]);
		}
		return res;
	}

	// Max returns the maximum value from a list of integers
	static int Max(int... nums) {
		if (nums.length == 0) {
			throw new IllegalArgumentException("function max() requires at least one argument.");
		}
		int res = nums[0];
		for (int i = 0; i < nums.length; i++) {
			res = Math.max(res, nums[i]);
		}
		return res;
	}

	// SortAsc sorts a slice of integers in ascending order
	static int[] SortAsc(int[] a) {
		Arrays.sort(a);
		return a;
	}

	// SortDesc sorts a slice of integers in descending order
	static int[] SortDesc(int[] a) {
		Arrays.sort(a);
		Arrays.sort(a, Collections.reverseOrder());
		return a;
	}

	// GCD computes the greatest common divisor of two integers
	static int GCD(int a, int b) {
		if (b == 0) {
			return a;
		}
		return GCD(b, a%b);
	}

	// LCM computes the least common multiple of two integers
	static int LCM(int a, int b) {
		if (a == 0 && b == 0) {
			return 0;
		}
		return a * b / GCD(a, b);
	}

	// CumSum computes the cumulative sum of a slice of integers
	static int[] CumSum(int[] nums) {
		int[] sums = new int[nums.length+1];
		sums[0] = 0;
		for (int i = 0; i < nums.length; i++) {
			sums[i+1] = sums[i] + nums[i];
		}
		return sums;
	}

	// BisectLeft performs a binary search to find the leftmost index of a target in a sorted slice
	static int BisectLeft(int[] nums, int left, int right, int target) {
		if (left == right) {
			if (nums[left] == target) {
				return left;
			} else if (nums[left] < target) {
				return left + 1;
			} else {
				return left;
			}
		}

		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			return mid;
		}

		if (nums[mid] > target) {
			return BisectLeft(nums, left, mid, target);
		} else if (nums[mid] < target) {
			return BisectLeft(nums, mid+1, right, target);
		}
		return 0;
	}

	// Permutations generates all permutations of a slice of integers
	static int[][] Permutations(int[] nums) {
		int n = nums.length;
		if (n == 0) {
			return new int[0][0];
		}
		int[][] ans = new int[n][];

		for (int i = 0; i < n; i++) {
			int[] rest = remove(nums, nums[i]);
			int[][] lists = Permutations(rest);
			if (lists.length == 0) {
				lists = new int[1][0];
			}

			for (int j = 0; j < lists.length; j++) {
				int[] list = lists[j];
				int[] newList = new int[list.length+1];
				for (int k = 0; k < list.length; k++) {
					newList[k] = list[k];
				}
				newList[list.length] = nums[i];
				ans[j] = newList;
			}
		}
		return ans;
	}

	// remove removes a target integer from a slice
	static int[] remove(int[] nums, int target) {
		int[] result = new int[nums.length-1];
		int idx = 0;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i]!= target) {
				result[idx] = nums[i];
				idx++;
			}
		}
		return result;
	}

	// PowerSet generates the power set of a slice of integers
	static int[][] PowerSet(int[] nums) {
		int size = Pow(2, nums.length);
		int[][] result = new int[size][];

		int idx = 0;
		result[idx] = new int[0];
		idx++;

		for (int n : nums) {
			int max = idx;
			for (int i = 0; i < max; i++) {
				int[] newSet = copyAndAppend(result[i], n);
				result[idx] = newSet;
				idx++;
			}
		}

		return result;
	}

	// copyAndAppend creates a new slice by appending an integer to an existing slice
	static int[] copyAndAppend(int[] nums, int n) {
		int[] dst = new int[nums.length+1];
		for (int i = 0; i < nums.length; i++) {
			dst[i] = nums[i];
		}
		dst[nums.length] = n;
		return dst;
	}

	// Combination generates all combinations of k elements from a slice of integers
	static int[][] Combination(int[] nums, int k) {
		int size = nums.length;
		int[][] result = new int[CombinationCount(size, k, 10e10)][];
		int bi = (1 << uint(k)) - 1;
		int max = 1 << uint(size);
		int idx = 0;

		for (bi < max) {
			int flags = bi;
			int[] s = new int[k];
			for (int i = 0; i < size; i++) {
				if (flags%2!= 0) {
					s[i] = nums[i];
				}
				flags /= 2;
			}
			result[idx] = s;
			idx++;
			bi = Combination2NextIndex(bi);
		}
		return result;
	}

	// Combination2NextIndex computes the next combination index
	static int Combination2NextIndex(int n) {
		int smallest = n & -n;
		int ripple = n + smallest;
		int newSmallest = ripple & -ripple;
		int ones = ((newSmallest / smallest) >> 1) - 1;
		return ripple | ones;
	}

	// CombinationCount calculates nCm using memoization to reduce computation time
	static int CombinationCount(int n, int m, int maxInput) {
		Map<Integer, Map<Integer, Integer>> memo = new HashMap<Integer, Map<Integer, Integer>>();
		for (int i = 1; i <= maxInput*maxInput; i++) {
			memo.put(i, new HashMap<Integer, Integer>());
		}
		return combinationCount(n, m, memo);
	}

	// combinationCount is a helper function for calculating combinations with memoization
	static int combinationCount(int n, int m, Map<Integer, Map<Integer, Integer>> memo) {
		if (n == m || m == 0) {
			return 1;
		}

		Integer left = memo.get(n-1).get(m-1);
		Integer right = memo.get(n-1).get(m);

		if (left!= null && right!= null) {
			return left + right;
		}

		if (left!= null) {
			right = combinationCount(n-1, m, memo);
			memo.get(n-1).put(m, right);
			return left + right;
		}

		if (right!= null) {
			left = combinationCount(n-1, m-1, memo);
			memo.get(n-1).put(m-1, left);
			return left + right;
		}

		left = combinationCount(n-1, m-1, memo);
		right = combinationCount(n-1, m, memo);
		memo.get(n-1).put(m-1, left);
		memo.get(n-1).put(m, right);
		return left + right;
	}

	// Fact computes the factorial of a number
	static int Fact(int n) {
		if (n == 0) {
			return 1;
		} else {
			return n * Fact(n-1);
		}
	}

	// Divisors returns all divisors of a given integer
	static int[] Divisors(int n) {
		Map<Integer, Boolean> divisors = new HashMap<Integer, Boolean>();
		for (int i = 1; i < (int) Math.sqrt(n)+1; i++) {
			if (n%i == 0) {
				divisors.put(i, true);
				if (i!= n) {
					divisors.put(n/i, true);
				}
			}
		}
		int[] ans = new int[divisors.size()];
		int idx = 0;
		for (int k : divisors.keySet()) {
			ans[idx] = k;
			idx++;
		}
		return ans;
	}
}

