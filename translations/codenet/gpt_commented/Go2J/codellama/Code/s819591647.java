
// problem_b.java

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

// Define a constant for modulus operation
final int constMod = 1000000007;

// Initialize scanner and writer for input and output
Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

// -----------------------------------------

// getInt reads a single integer from input
int getInt() {
	return sc.nextInt();
}

// getIntSlice reads n integers from input and returns them as a slice
int[] getIntSlice(int n) {
	int[] ns = new int[n];
	for (int i = 0; i < n; i++) {
		ns[i] = getInt();
	}
	return ns;
}

// getIntDoubleSlice reads m slices of n integers from input and returns them as a 2D slice
int[][] getIntDoubleSlice(int m, int n) {
	int[][] nds = new int[m][n];
	for (int i = 0; i < m; i++) {
		nds[i] = getIntSlice(n);
	}

	return nds;
}

// getString reads a single string from input
String getString() {
	return sc.next();
}

// getStringSlice reads n strings from input and returns them as a slice
String[] getStringSlice(int n) {
	String[] ss = new String[n];
	for (int i = 0; i < n; i++) {
		ss[i] = getString();
	}
	return ss;
}

// getStringDoubleSlice reads m slices of n strings from input and returns them as a 2D slice
String[][] getStringDoubleSlice(int m, int n) {
	String[][] sds = new String[m][n];
	for (int i = 0; i < m; i++) {
		sds[i] = getStringSlice(n);
	}

	return sds;
}

// -----------------------------------------

// Sort Functions

// sortIntSlice sorts a slice of integers in ascending order
int[] sortIntSlice(int[] ns) {
	java.util.Arrays.sort(ns);
	return ns;
}

// sortIntReverseSlice sorts a slice of integers in descending order
int[] sortIntReverseSlice(int[] ns) {
	java.util.Arrays.sort(ns);
	java.util.Collections.reverse(java.util.Arrays.asList(ns));
	return ns;
}

// -----------------------------------------

// Number Functions

// numAbs returns the absolute value of an integer x
int numAbs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// numModPow computes a^n % m using modular exponentiation
int numModPow(int a, int n, int m) {
	int result = 1;

	for (int i = n; i > 0; i >>= 1) {
		if (i % 2 == 1) {
			result = (result * a) % m;
		}
		a = (a * a) % m;
	}

	return result;
}

// numGcd computes the greatest common divisor of a and b
int numGcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return numGcd(b, a % b);
}

// numLcm computes the least common multiple of a and b
int numLcm(int a, int b) {
	return a * b / numGcd(a, b);
}

// numModInv computes the modular inverse of a under modulo p
int numModInv(int a, int p) {
	if (a == 1) {
		return 1;
	}
	return p - numModInv(p % a, p) * (p / a) % p;
}

// numModFrac computes factorials modulo constMod up to n
int[] numModFrac(int n) {
	int[] frac = new int[n + 1];

	frac[0] = 1;
	for (int i = 1; i <= n; i++) {
		frac[i] = i * frac[i - 1] % constMod;
	}

	return frac;
}

// numModConb computes nCr % constMod using precomputed factorials
int numModConb(int n, int r) {
	int[] frac = numModFrac(n);
	return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod;
}

// -----------------------------------------

// solve function implements the main logic of the problem
void solve() {
	// Read n and m from input
	int n = getInt();
	int m = getInt();
	// Read n integers into slice a
	int[] a = getIntSlice(n);

	// Calculate the sum of all elements in a
	int sum = 0;
	for (int v : a) {
		sum += v;
	}

	// Count how many elements in a meet the required rate
	int count = 0;
	for (int v : a) {
		double rate = (double) sum / (4 * m);
		if (v >= rate) {
			count++;
		}
	}

	// Output "Yes" if count is greater than or equal to m, otherwise "No"
	if (count >= m) {
		wr.write("Yes\n");
	} else {
		wr.write("No\n");
	}
}

// -----------------------------------------

// main function initializes the program and calls solve
public static void main(String[] args) {
	// Set a maximum buffer size for input
	int maxBufSize = 10000000;
	sc.useDelimiter("\\A");
	// Call the solve function to execute the main logic
	solve();
	// Flush the writer to output results
	wr.flush();
}

