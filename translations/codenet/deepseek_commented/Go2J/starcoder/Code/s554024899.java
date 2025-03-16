package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// Read two integers from the input
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		// Define an array containing three slices, each representing a group of months with the same number of days
		int xt, yt;
		int[][] a = new int[][] {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
		
		// Iterate over the array to determine which group each of the integers belongs to
		for (int i = 0; i < a.length; i++) {
			for (int n : a[i]) {
				// System.out.println(n); // Uncomment to log each number in the array
				if (x == n) {
					xt = i;
				}
				if (y == n) {
					yt = i;
				}
			}
		}
		
		// Compare the groups of x and y to determine if they belong to the same group
		if (xt == yt) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}

