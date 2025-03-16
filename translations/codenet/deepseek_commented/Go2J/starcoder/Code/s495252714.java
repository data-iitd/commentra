package main;

import java.util.*;
import java.io.*;

public class Main {

	// Function to scan an integer from input.
	public static int scanInt() {
		Scanner sc = new Scanner(System.in);
		return sc.nextInt();
	}

	// Function to scan a 64-bit integer from input.
	public static long scanInt64() {
		Scanner sc = new Scanner(System.in);
		return sc.nextLong();
	}

	// Function to scan a list of integers from input.
	public static int[] scanInts(int n) {
		Scanner sc = new Scanner(System.in);
		int[] res = new int[n];
		for (int i = 0; i < n; i++) { res[i] = sc.nextInt(); }
		return res;
	}

	// Function to scan a single line of text from input.
	public static String scanText() {
		Scanner sc = new Scanner(System.in);
		return sc.nextLine();
	}

	// Function to print a list of integers, separated by spaces.
	public static void printInts(int... a) {
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i]);
			if (i!= a.length-1) { System.out.print(" "); }
		}
		System.out.println();
	}

	// The main function of the program.
	public static void main(String[] args) {
		// Set the split function for the scanner to scan words.
		Scanner sc = new Scanner(System.in);
		sc.useDelimiter("\\s");

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
	public static final int mod = 1000000007;

	// Function to perform modular exponentiation.
	public static int modpow(int a,int n) {
		int res = 1;
		for ( ; n>0; n>>=1) {
			if ((n&1) == 1) {
				res = res*a%mod;
			}
			a = a*a%mod;
		}
		return res;
	}

}

