package main;

import java.util.*;

public class Main {

	// Constants for buffer sizes and modulo value
	public static final int initialBufSize = 10000;
	public static final int maxBufSize = 1000000;
	public static final int mod = 1e9 + 7;

	// Scanner for reading input
	public static Scanner sc = new Scanner(System.in);

	// Main function
	public static void main(String[] args) {
		// Read an integer N from input
		int N = getInt();
		// Calculate the integer square root of N
		int sqrtN = (int) Math.sqrt(N);

		// Initialize min to N, which will hold the minimum value found
		int min = N;
		// Iterate through all possible divisors of N
		for (int i = 1; i <= sqrtN; i++) {
			// If i is not a divisor of N, skip to the next iteration
			if (N % i!= 0) {
				continue;
			}

			// Calculate the value based on the divisor and its complement
			int num = i + (N / i) - 2;
			// Update min if the new value is smaller
			if (num < min) {
				min = num;
			}
		}

		// Print the minimum value found
		System.out.println(min);
	}

	// Helper function to read an integer from input
	public static int getInt() {
		sc.next();
		return Integer.parseInt(sc.nextLine());
	}

	// Helper function to read a string from input
	public static String getString() {
		return sc.next();
	}

	// Function to return the absolute value of an integer
	public static int abs(int a) {
		return Math.abs(a);
	}

	// Function to compute p raised to the power of q
	public static int pow(int p, int q) {
		return (int) Math.pow(p, q);
	}

	// Function to compute (n^p) % mod using exponentiation by squaring
	public static int powMod(int n, int p) {
		if (p == 0) {
			return 1;
		} else if (p % 2 == 0) {
			int t = powMod(n, p / 2);
			return calcMod(t * t);
		} else {
			return calcMod(n * powMod(n, p - 1));
		}
	}

	// Function to find the minimum value among a variable number of integers
	public static int min(int... nums) {
		if (nums.length == 0) {
			throw new IllegalArgumentException("function min() requires at least one argument.");
		}
		int res = nums[0];
		for (int i = 0; i < nums.length; i++) {
			res = Math.min(res, nums[i]);
		}
		return res;
	}

	// Function to find the maximum value among a variable number of integers
	public static int max(int... nums) {
		if (nums.length == 0) {
			throw new IllegalArgumentException("function max() requires at least one argument.");
		}
		int res = nums[0];
		for (int i = 0; i < nums.length; i++) {
			res = Math.max(res, nums[i]);
		}
		return res;
	}

	// Function to check if a string exists in a slice of strings
	public static boolean strSearch(String[] a, String b) {
		for (int i = 0; i < a.length; i++) {
			if (a[i].equals(b)) {
				return true;
			}
		}
		return false;
	}

	// Function to print an integer array in a formatted way
	public static void printIntArray(int[] array) {
		String strArray = Arrays.toString(array);
		System.out.println(strArray.substring(1, strArray.length() - 1));
	}

	// Function to calculate x % mod
	public static int calcMod(int x) {
		return x % mod;
	}

	// Function to reverse a string
	public static String reverse(String s) {
		char[] runes = s.toCharArray();
		for (int i = 0, j = runes.length - 1; i < j; i++, j--) {
			char tmp = runes[i];
			runes[i] = runes[j];
			runes[j] = tmp;
		}
		return new String(runes);
	}

	// Function to check if a number is prime
	public static boolean isPrime(int n) {
		if (n < 2) {
			return false;
		} else if (n == 2) {
			return true;
		} else if (n % 2 == 0) {
			return false;
		}

		// Check for factors from 3 to the square root of n
		int sqrtN = (int) Math.sqrt(n);
		for (int i = 3; i <= sqrtN; i += 2) {
			if (n % i == 0) {
				return false;
			}
		}

		return true;
	}

}

