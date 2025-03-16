package main;

import java.util.Scanner;

public class Main {

	// Function to read an integer from standard input
	public static int nextInt() {
		Scanner sc = new Scanner(System.in);
		return sc.nextInt();
	}

	// Function to read multiple integers from standard input
	public static int[] scanNums(int len) {
		int[] nums = new int[len];
		for (int i = 0; i < len; i++) {
			nums[i] = nextInt();
		}
		return nums;
	}

	// Function to calculate the first pattern
	public static int pattern1(int[] l) {
		// Calculate the value of n using the given formula
		int n = (l[0] * l[3]) + (l[1] * l[4]);

		// Return the value of n
		return n;
	}

	// Function to calculate the second pattern
	public static int pattern2(int[] l) {
		// Calculate the maximum of l[3] and l[4]
		int maxNum = Math.max(l[3], l[4]);

		// Calculate the value of n using the given formula
		int n = 2 * l[2] * maxNum;

		// Return the value of n
		return n;
	}

	// Function to calculate the third pattern
	public static int pattern3(int[] l) {
		// Calculate the minimum of l[3] and l[4]
		int minNum = Math.min(l[3], l[4]);

		// Calculate the value of n using the given formula
		int n = 2 * l[2] * minNum + doch(l);

		// Return the value of n
		return n;
	}

	// Helper function to calculate the difference between the larger and smaller of two numbers
	public static int doch(int[] l) {
		// If l[3] is greater than l[4], return the product of l[0] and the difference between l[3] and l[4]
		if (l[3] > l[4]) {
			return l[0] * (l[3] - l[4]);
		} else {
			// Otherwise, return the product of l[1] and the difference between l[4] and l[3]
			return l[1] * (l[4] - l[3]);
		}
	}

	// Main function to read input and call the pattern functions
	public static void main(String[] args) {
		// Read the length of the input list
		int len = 5;

		// Read the input list from standard input
		int[] l = scanNums(len);

		// Calculate and print the minimum of the three patterns
		System.out.println(Math.min(pattern1(l), pattern2(l), pattern3(l)));
	}
}

