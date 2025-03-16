
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	// Define constants for modulo operation and factorial limit
	private static final int mod = 998244353;
	private static final int facNum = 300001;
	
	public static void main(String[] args) throws IOException {
		// Initialize a new scanner for reading input
		Scanner sc = new Scanner(System.in);
		// Read an integer N from input
		int N = sc.i();
		int sum = 0;
		
		// Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
		for (int i = 1; i <= N; i++) {
			if (i % 3 == 0 || i % 5 == 0) {
				continue; // Skip numbers divisible by 3 or 5
			}
			sum += i; // Add the number to the sum
		}
		
		// Output the final sum
		System.out.println(sum);
	}
	
	// Scanner class for handling input
	public static class Scanner {
		
		// Initialize a new scanner for reading input
		private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// s reads a string from the scanner
		public String s() throws IOException {
			return br.readLine();
		}
		
		// i reads an integer from the scanner
		public int i() throws IOException {
			return Integer.parseInt(s());
		}
		
		// f reads a float64 from the scanner
		public double f() throws IOException {
			return Double.parseDouble(s());
		}
		
		// bs reads a byte slice from the scanner
		public byte[] bs() throws IOException {
			return s().getBytes();
		}
		
		// is reads n integers from the scanner into a slice
		public int[] is(int n) throws IOException {
			int[] res = new int[n];
			StringTokenizer st = new StringTokenizer(s());
			for (int i = 0; i < n; i++) {
				res[i] = Integer.parseInt(st.nextToken());
			}
			return res;
		}
		
		// fs reads n float64 values from the scanner into a slice
		public double[] fs(int n) throws IOException {
			double[] res = new double[n];
			StringTokenizer st = new StringTokenizer(s());
			for (int i = 0; i < n; i++) {
				res[i] = Double.parseDouble(st.nextToken());
			}
			return res;
		}
		
		// Pow calculates a^n under modulo
		public static int Pow(int a, int n) {
			int ans = 1;
			for (int i = 0; i < n; i++) {
				ans = ans * a % mod;
			}
			return ans;
		}
		
		// Gcd calculates the greatest common divisor of a and b
		public static int Gcd(int a, int b) {
			if (a < b) {
				return Gcd(b, a);
			}
			while (b != 0) {
				a = a % b;
				b = b % a;
			}
			return a;
		}
		
		// min returns the minimum of two integers
		public static int min(int a, int b) {
			if (a < b) {
				return a;
			}
			return b;
		}
		
		// combination calculates n choose k using precomputed factorials
		public static int combination(int n, int k, int[] fac, int[] ifac) {
			if (n < k || n < 0) {
				return 0;
			}
			if (k == 0) {
				return 1;
			}
			// Calculate combination using factorials
			int ans = ifac[k] * ifac[n-k] % mod;
			return ans * fac[n] % mod;
		}
		
		// factorial precomputes factorials and their modular inverses
		public static int[] factorial() {
			int[] fac = new int[facNum];
			int[] ifac = new int[facNum];
			fac[0] = 1;
			ifac[0] = 1;
			for (int i = 1; i < facNum; i++) {
				fac[i] = fac[i-1] * i % mod;
				ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod;
			}
			return fac;
		}
		
		// lowerBound finds the index of the first element in a sorted slice that is not less than v
		public static int lowerBound(int[] vs, int v) {
			int n = vs.length / 2;
			int m = vs.length;
			while (m != n) {
				if (vs[n] < v) {
					n = (m-n+1)/2 + n;
				} else {
					m = n;
					n = n / 2;
				}
			}
			return n;
		}
		
		// IntSlice creates a slice of integers initialized to a specific value
		public static int[] IntSlice(int n, int init) {
			int[] r = new int[n];
			for (int i = 0; i < n; i++) {
				r[i] = init;
			}
			return r;
		}
	}
}

