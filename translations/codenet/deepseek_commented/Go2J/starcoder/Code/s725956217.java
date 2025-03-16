package main;

import java.util.*;
import java.io.*;

public class Main {

	// Helper function to print output.
	public static void out(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

	// Scanner to read input from standard input.
	static Scanner sc = new Scanner(System.in);

	// Function to read an integer from input.
	public static int getInt() {
		return Integer.parseInt(sc.next());
	}

	// Function to read a string from input.
	public static String getString() {
		return sc.next();
	}

	// Function to return the maximum of two integers.
	public static int max(int a, int b) {
		if (a > b) {
			return a;
		}
		return b;
	}

	// Function to return the minimum of two integers.
	public static int min(int a, int b) {
		if (a < b) {
			return a;
		}
		return b;
	}

	// Function to return the absolute difference between two integers.
	public static int asub(int a, int b) {
		if (a > b) {
			return a - b;
		}
		return b - a;
	}

	// Function to return the absolute value of an integer.
	public static int abs(int a) {
		if (a >= 0) {
			return a;
		}
		return -a;
	}

	// Function to find the lower bound index of a value in a sorted array.
	public static int lowerBound(int[] a, int x) {
		int idx = Arrays.binarySearch(a, x);
		if (idx < 0) {
			idx = -idx - 1;
		}
		return idx;
	}

	// Function to find the upper bound index of a value in a sorted array.
	public static int upperBound(int[] a, int x) {
		int idx = Arrays.binarySearch(a, x);
		if (idx < 0) {
			idx = -idx - 1;
		}
		if (idx < a.length && a[idx] == x) {
			idx++;
		}
		return idx;
	}

	// Struct to represent a shop with its price and stock.
	static class shop {
		int a, b;
		shop(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}

	// Main function to execute the program logic.
	public static void main(String[] args) {
		// Read the number of shops and the amount of items to buy.
		int N = getInt(), M = getInt();

		// Create a slice of shops and read each shop's price and stock.
		shop[] s = new shop[N];
		for (int i = 0; i < N; i++) {
			int a = getInt(), b = getInt();
			s[i] = new shop(a, b);
		}

		// Sort the shops by price.
		Arrays.sort(s, new Comparator<shop>() {
			public int compare(shop a, shop b) {
				return a.a - b.a;
			}
		});

		// Calculate the total cost of buying the required number of items.
		int total = 0;
		for (shop e : s) {
			// Determine the number of items to buy from the current shop.
			int n = min(e.b, M);
			// Update the total cost and the remaining items to buy.
			total += n * e.a;
			M -= n;
			// Break if all items are bought.
			if (M == 0) {
				break;
			}
		}

		// Print the total cost.
		out(total);
	}

}

