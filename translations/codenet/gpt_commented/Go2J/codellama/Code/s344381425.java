package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Declare three integer variables to hold the input values
		int a, b, c;
		
		// Read three integers from standard input
		Scanner scanner = new Scanner(System.in);
		a = scanner.nextInt();
		b = scanner.nextInt();
		c = scanner.nextInt();
		
		// Check if the integers are in strictly increasing order
		if (a < b && b < c) {
			// If they are in increasing order, print "Yes"
			System.out.println("Yes");
		} else {
			// If they are not in increasing order, print "No"
			System.out.println("No");
		}
		
		// End of the main function
		return;
	}
}

