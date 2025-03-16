
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter wtr = new PrintWriter(System.out);
		
		// Read input values
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int K = sc.nextInt();
		
		// Determine the maximum value among A, B, and C
		int ma = max(A, B, C);
		
		// Calculate the sum of the other two values
		int rest = 0;
		if (ma == A) {
			rest += B + C;
		} else if (ma == B) {
			rest += A + C;
		} else {
			rest += A + B;
		}
		
		// Double the maximum value K times
		for (int i = 1; i <= K; i++) {
			ma *= 2;
		}
		
		// Print the final result
		wtr.println(ma + rest);
		wtr.flush();
	}
	
	// Arithmetic
	public static int max(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m < i) {
				m = i;
			}
		}
		return m;
	}
	
	public static int min(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m > i) {
				m = i;
			}
		}
		return m;
	}
	
	public static int abs(int x) {
		if (x > 0) {
			return x;
		}
		return -x;
	}
	
	public static int pow(int x, int y) {
		int res = 1;
		for (int i = 0; i < y; i++) {
			res *= x;
		}
		return res;
	}
	
	// Sort
	public static class Val {
		public int id;
		public int num;
		
		public Val(int id, int num) {
			this.id = id;
			this.num = num;
		}
	}
	
	public static class ByNum implements Comparator<Val> {
		@Override
		public int compare(Val a, Val b) {
			return a.num - b.num;
		}
	}
	
	// I/O
	public static class Scanner {
		private BufferedReader sc;
		
		public Scanner() {
			sc = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String nextStr() {
			try {
				return sc.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		
		public int nextInt() {
			return Integer.parseInt(nextStr());
		}
		
		public long nextLong() {
			return Long.parseLong(nextStr());
		}
		
		public double nextDouble() {
			return Double.parseDouble(nextStr());
		}
		
		public int[] nextIntSlice(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}
		
		public long[] nextLongSlice(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}
		
		public double[] nextDoubleSlice(int n) {
			double[] res = new double[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}
	}
	
	// Util
	public static void shuffle(int[] arr) {
		Random rnd = new Random();
		for (int i = arr.length - 1; i >= 1; i--) {
			int j = rnd.nextInt(i + 1);
			int tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	
	public static void shuffle(long[] arr) {
		Random rnd = new Random();
		for (int i = arr.length - 1; i >= 1; i--) {
			int j = rnd.nextInt(i + 1);
			long tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	
	public static void shuffle(Object[] arr) {
		Random rnd = new Random();
		for (int i = arr.length - 1; i >= 1; i--) {
			int j = rnd.nextInt(i + 1);
			Object tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	
	public static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	
	public static void swap(long[] arr, int i, int j) {
		long tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	
	public static void swap(Object[] arr, int i, int j) {
		Object tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	
	public static int lowerBound(int[] arr, int l, int r, int x) {
		while (l < r) {
			int m = (l + r) / 2;
			if (arr[m] >= x) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int upperBound(int[] arr, int l, int r, int x) {
		while (l < r) {
			int m = (l + r) / 2;
			if (arr[m] > x) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int lowerBound(long[] arr, int l, int r, long x) {
		while (l < r) {
			int m = (l + r) / 2;
			if (arr[m] >= x) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int upperBound(long[] arr, int l, int r, long x) {
		while (l < r) {
			int m = (l + r) / 2;
			if (arr[m] > x) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int lowerBound(Object[] arr, int l, int r, Object x) {
		while (l < r) {
			int m = (l + r) / 2;
			if (((Comparable) arr[m]).compareTo(x) >= 0) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int upperBound(Object[] arr, int l, int r, Object x) {
		while (l < r) {
			int m = (l + r) / 2;
			if (((Comparable) arr[m]).compareTo(x) > 0) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int lowerBound(int[] arr, int x) {
		return lowerBound(arr, 0, arr.length, x);
	}
	
	public static int upperBound(int[] arr, int x) {
		return upperBound(arr, 0, arr.length, x);
	}
	
	public static int lowerBound(long[] arr, long x) {
		return lowerBound(arr, 0, arr.length, x);
	}
	
	public static int upperBound(long[] arr, long x) {
		return upperBound(arr, 0, arr.length, x);
	}
	
	public static int lowerBound(Object[] arr, Object x) {
		return lowerBound(arr, 0, arr.length, x);
	}
	
	public static int upperBound(Object[] arr, Object x) {
		return upperBound(arr, 0, arr.length, x);
	}
	
	public static int lowerBound(int[] arr, int l, int r, int x, Comparator<Integer> cmp) {
		while (l < r) {
			int m = (l + r) / 2;
			if (cmp.compare(arr[m], x) >= 0) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int upperBound(int[] arr, int l, int r, int x, Comparator<Integer> cmp) {
		while (l < r) {
			int m = (l + r) / 2;
			if (cmp.compare(arr[m], x) > 0) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int lowerBound(long[] arr, int l, int r, long x, Comparator<Long> cmp) {
		while (l < r) {
			int m = (l + r) / 2;
			if (cmp.compare(arr[m], x) >= 0) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int upperBound(long[] arr, int l, int r, long x, Comparator<Long> cmp) {
		while (l < r) {
			int m = (l + r) / 2;
			if (cmp.compare(arr[m], x) > 0) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int lowerBound(Object[] arr, int l, int r, Object x, Comparator<Object> cmp) {
		while (l < r) {
			int m = (l + r) / 2;
			if (cmp.compare(arr[m], x) >= 0) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int upperBound(Object[] arr, int l, int r, Object x, Comparator<Object> cmp) {
		while (l < r) {
			int m = (l + r) / 2;
			if (cmp.compare(arr[m], x) > 0) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	}
	
	public static int lowerBound(int[] arr, int x, Comparator<Integer> cmp) {
		return lowerBound(arr, 0, arr.length, x, cmp);
	}
	
	public static int upperBound(int[] arr, int x, Comparator<Integer> cmp) {
		return upperBound(arr, 0, arr.length, x, cmp);
	}
	
	public static int lowerBound(long[] arr, long x, Comparator<Long> cmp) {
		return lowerBound(arr, 0, arr.length, x, cmp);
	}
	
	public static int upperBound(long[] arr, long x, Comparator<Long> cmp) {
		return upperBound(arr, 0, arr.length, x, cmp);
	}
	
	public static int lowerBound(Object[] arr, Object x, Comparator<Object> cmp) {
		return lowerBound(arr, 0, arr.length, x, cmp);
	}
	
	public static int upperBound(Object[] arr, Object x, Comparator<Object> cmp) {
		return upperBound(arr, 0, arr.length, x, cmp);
	}
	
	public static int[][] pack(int[] arr, int n) {
		int[][] res = new int[n][];
		for (int i = 0; i < n; i++) {
			res[i] = new int[arr[i]];
		}
		for (int i = 0, idx = 0; i < n; i++) {
			for (int j = 0; j < arr[i]; j++) {
				res[i][j] = arr[idx++];
			}
		}
		return res;
	}
	
	public static int[][] pack(int[] arr, int n, int m) {
		int[][] res = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = arr[j];
			}
		}
		return res;
	}
	
	public static int[][][] pack(int[] arr, int n, int m, int l) {
		int[][][] res = new int[n][m][l];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < l; k++) {
					res[i][j][k] = arr[k];
				}
			}
		}
		return res;
	}
	
	public static int[][][][] pack(int[] arr, int n, int m, int l, int t) {
		int[][][][] res = new int[n][m][l][t];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < l; k++) {
					for (int u = 0; u < t; u++) {
						res[i][j][k][u] = arr[u];
					}
				}
			}
		}
		return res;
	}
	
	public static int[][][][][] pack(int[] arr, int n, int m, int l, int t, int v) {
		int[][][][][] res = new int[n][m][l][t][v];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < l; k++) {
					for (int u = 0; u < t; u++) {
						for (int w = 0; w < v; w++) {
							res[i][j][k][u][w] = arr[w];
						}
					}
				}
			}
		}
		return res;
	}
	
	public static int[][][][][][] pack(int[] arr, int n, int m, int l, int t, int v, int s) {
		int[][][][][][] res = new int[n][m][l][t][v][s];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < l; k++) {
					for (int u = 0; u < t; u++) {
						for (int w = 0; w < v; w++) {
							for (int x = 0; x < s; x++) {
								res[i][j][k][u][w][x] = arr[x];
							}
						}
					}
				}
			}
		}
		return res;
	}
	
	public static int[][][][][][][] pack(int[] arr, int n, int m, int l, int t, int v, int s, int p) {
		int[][][][][][][] res = new int[n][m][l][t][v][s][p];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < l; k++) {
					for (int u = 0; u < t; u++) {
						for (int w = 0; w < v; w++) {
							for (int x = 0; x < s; x++) {
								for (int y = 0; y < p; y++) {
									res[i][j][k][u][w][x][y] = arr[y];
								}
							}
						}
					}
				}
			}
		}
		