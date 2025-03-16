// Constants and package imports
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Reading the first two integers h and n
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int n = sc.nextInt();

		// Initializing variable a to 0
		int a = 0;

		// Iterating through the array of size n and adding each integer to variable a
		for (int i = 0; i < n; i++) {
			a += sc.nextInt();
		}

		// Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
		if (h > a) {
			System.out.println("No");
		} else {
			System.out.println("Yes");
		}
	}
}

