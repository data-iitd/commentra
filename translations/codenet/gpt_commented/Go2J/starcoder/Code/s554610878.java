package main;

import java.util.Scanner;

public class Main {

	// Constants for buffer sizes
	private static final int initialBufSize = 10000;
	private static final int maxBufSize = 1000000;

	// Global variables for scanner and modulus
	private static Scanner sc = new Scanner(System.in);
	private static int mod = 1000000007; // Modulus value for calculations

	public static void main(String[] args) {
		// Array representing the days of the week
		String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
		
		// Get the input day as a string
		String s = getString();
		int index = -1; // Initialize index to -1 to indicate not found

		// Search for the input day in the week array
		for (int i = 0; i < week.length; i++) {
			if (s.equals(week[i])) {
				index = i; // Update index if the day is found
				break;
			}
		}

		// Calculate and print the number of days until the next Sunday
		System.out.println(7 - index);
	}

	// Function to read an integer from input
	private static int getInt() {
		return Integer.parseInt(sc.next());
	}

	// Function to read a string from input
	private static String getString() {
		return sc.next();
	}

	// Function to compute the absolute value of an integer
	private static int abs(int a) {
		return Math.abs(a);
	}

	// Function to compute p raised to the power of q
	private static int pow(int p, int q) {
		return (int) Math.pow(p, q);
	}

	// Function to find the minimum value among given integers
	private static int min(int... nums) {
		if (nums.length == 0) {
			throw new IllegalArgumentException("function min() requires at least one argument.");
		}
		int res = nums[0];
		for (int i = 0; i < nums.length; i++) {
			res = Math.min(res, nums[i]);
		}
		return res;
	}

	// Function to find the maximum value among given integers
	private static int max(int... nums) {
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
	private static boolean strSearch(String[] a, String b) {
		for (int i = 0; i < a.length; i++) {
			if (a[i].equals(b)) {
				return true;
			}
		}
		return false;
	}

	// Function to print an array of integers
	private static void printIntArray(int[] array) {
		String strArray = Arrays.toString(array);
		System.out.println(strArray.substring(1, strArray.length() - 1));
	}

	// Function to calculate the modulus of x with respect to the defined mod
	private static int calcMod(int x) {
		return x % mod;
	}

}

