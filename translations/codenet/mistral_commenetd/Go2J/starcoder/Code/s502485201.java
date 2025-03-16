
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize variables r, d, and x with given values
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int d = sc.nextInt();
		int x = sc.nextInt();

		// Loop through 10 iterations
		for (int i = 0; i < 10; i++) {
			// Calculate new value of x using given formula
			x = r * x - d;

			// Print the current value of x
			System.out.println(x);
		}
	}
}

