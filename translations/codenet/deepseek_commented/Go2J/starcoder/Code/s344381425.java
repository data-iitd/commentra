
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare three integer variables to store input values
		int a, b, c;
		
		// Read three integers from standard input and assign them to a, b, and c
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		
		// Check if a is less than b and b is less than c
		if (a < b && b < c) {
			// If the condition is true, print "Yes"
			System.out.println("Yes");
		} else {
			// Otherwise, print "No"
			System.out.println("No");
		}
		
		// Return from the function
		return;
	}

}

