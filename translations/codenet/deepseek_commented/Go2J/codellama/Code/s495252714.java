
package main;

import java.util.Scanner;
import java.io.PrintWriter;
import java.util.Arrays;

//=====I/O=====

// Initialize buffered reader and writer for efficient I/O operations.
Scanner sc = new Scanner(System.in);
PrintWriter wr = new PrintWriter(System.out);

// Function to scan an integer from input.
int scanInt() {
	sc.next();
	return Integer.parseInt(sc.next());
}

// Function to scan a 64-bit integer from input.
long scanInt64() {
	sc.next();
	return Long.parseLong(sc.next());
}

// Function to scan a list of integers from input.
int[] scanInts(int n) {
	int[] res = new int[n];
	for (int i = 0; i < n; i++) { res[i] = scanInt(); }
	return res;
}

// Function to scan a single line of text from input.
String scanText() {
	sc.next();
	return sc.next();
}

// Function to print a list of integers, separated by spaces.
void printInts(int... a) {
	for (int i = 0; i < a.length; i++) {
		wr.print(a[i]);
		if (i != a.length-1) { wr.print(" "); }
	}
	wr.println();
	wr.flush();
}

//=====main=====

// The main function of the program.
public static void main(String[] args) {
	// Set the split function for the scanner to scan words.
	sc.useDelimiter("\\s+");

	// Read the number of elements.
	int n = scanInt();

	// Read n integers into a slice.
	int[] c = scanInts(n);

	// Initialize the answer variable.
	int ans = 0;

	// Sort the slice of integers.
	Arrays.sort(c);

	// Calculate the answer based on the sorted slice.
	for (int i = 0; i < n; i++) {
		ans = (ans+(n+1-i)*c[i]%mod)%mod;
	}

	// Print the final answer, multiplied by 4^(n-1) modulo mod.
	System.out.println(ans*modpow(4,n-1)%mod);
}

// Define the constant for modular arithmetic.
final int mod = 1000000007;

// Function to perform modular exponentiation.
int modpow(int a, int n) {
	int res = 1;
	for (; n>0; n>>=1) {
		if (n%2 == 1) {
			res = res*a%mod;
		}
		a = a*a%mod;
	}
	return res;
}

