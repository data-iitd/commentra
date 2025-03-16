package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare three integer variables "a", "b", and "c"
		int a, b, c;

		// Read three integers from the standard input and assign them to the variables
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();

		// Check if the difference between "b" and "a" is equal to the difference between "c" and "b"
		if (b - a == c - b) {
			// If the condition is true, print "YES" to the standard output
			System.out.println("YES");
		} else {
			// If the condition is false, print "NO" to the standard output
			System.out.println("NO");
		}

		// End of the code
	}

}

