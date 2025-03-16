
//problem_b.java
// This is the main file for problem B solution

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class problem_b {

	// Constants definition
	public static final int constMod = 1000000007;

	// Function definitions

	public static int getInt() { // Function to read an integer from standard input
		Scanner sc = new Scanner(System.in);
		return sc.nextInt();
	}

	public static int[] getIntSlice(int n) { // Function to read n integers and return a slice
		int[] ns = new int[n];
		for (int i = 0; i < n; i++) {
			ns[i] = getInt();
		}
		return ns;
	}

	public static String getString() { // Function to read a string from standard input
		Scanner sc = new Scanner(System.in);
		return sc.next();
	}

	public static String[] getStringSlice(int n) { // Function to read n strings and return a slice
		String[] ss = new String[n];
		for (int i = 0; i < n; i++) {
			ss[i] = getString();
		}
		return ss;
	}

	public static String[][] getStringDoubleSlice(int m, int n) { // Function to read m strings of length n and return a 2D slice
		String[][] sds = new String[m][n];
		for (int i = 0; i < m; i++) {
			sds[i] = getStringSlice(n);
		}

		return sds;

	}

	// Sorting functions

	public static int[] sortIntSlice(int[] ns) { // Function to sort an integer slice in ascending order
		Arrays.sort(ns);
		return ns;
	}

	public static int[] sortIntReverseSlice(int[] ns) { // Function to sort an integer slice in descending order
		Arrays.sort(ns);
		return ns;
	}

	// Mathematical functions

	//numAbs(x) = abs(s)
	public static int numAbs(int x) { // Function to get absolute value of an integer
		if (x < 0) {
			return -x;
		}

		return x;
	}

	//numModPow(a, n, m) = a^n % m
	public static int numModPow(int a, int n, int m) { // Function to calculate a^n % m
		int result = 1;

		for (int i = n; i > 0; i >>= 1) {
			if (i % 2 == 1) {
				result = (result * a) % m;
			}

			a = (a * a) % m;
		}

		return result;
	}

	// numGcd(a, b) = gcd(a, b)
	public static int numGcd(int a, int b) { // Function to calculate the greatest common divisor of a and b
		if (b == 0) {
			return a;
		}

		return numGcd(b, a % b);
	}

	// numLcm(a, b) = lcm(a, b)
	public static int numLcm(int a, int b) { // Function to calculate the least common multiple of a and b
		return a * b / numGcd(a, b);
	}

	// numModInv(a, p) = a^(-1) % p
	public static int numModInv(int a, int p) { // Function to calculate the modular inverse of a modulo p
		if (a == 1) {
			return 1;
		}

		return p - numModInv(p % a, p) * (p / a) % p;
	}

	// numModFrac(n) = n! % constMod
	public static int[] numModFrac(int n) { // Function to calculate n! modulo constMod
		int[] frac = new int[n + 1];
		frac[0] = 1;

		for (int i = 1; i <= n; i++) {
			frac[i] = i * frac[i - 1] % constMod;
		}

		return frac;
	}

	// numModConb(n, r) = nCr % constMod
	public static int numModConb(int n, int r) { // Function to calculate nCr modulo constMod
		int[] frac = numModFrac(n);

		return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod;
	}

	// -----------------------------------------

	// Main function

	public static void solve() { // Function to solve the problem

		int n = getInt();
		int m = getInt();
		int[] a = getIntSlice(n);

		int sum = 0;
		for (int v : a) {
			sum += v;
		}

		int count = 0;
		for (int v : a) {
			double rate = (double) sum / (4 * m);
			if (v >= rate) {
				count++;
			}
		}

		if (count >= m) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

	}

	// -----------------------------------------

	public static void main(String[] args) { // Main function
		solve();
	}

}

