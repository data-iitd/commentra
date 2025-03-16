package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Read the first three integers as input
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int D = sc.nextInt();
		int x = sc.nextInt();

		// Iterate through a loop 10 times
		for (int i = 1; i <= 10; i++) {
			// Calculate the new value of x using the given formula
			x = r * x - D;

			// Print the value of x to the console
			System.out.println(x);
		}
	}
}

// The end of the code

Translate the above Java code to C++ and end with comment "