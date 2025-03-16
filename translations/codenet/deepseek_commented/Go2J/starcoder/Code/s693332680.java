package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare three integer variables x, a, and b to store input values.
		int x, a, b;
		
		// Read three integers from the standard input and assign them to x, a, and b.
		Scanner sc = new Scanner(System.in);
		x = sc.nextInt();
		a = sc.nextInt();
		b = sc.nextInt();
		
		// Use a switch statement to evaluate the condition b-a and execute the corresponding block of code.
		switch (b-a) {
			// If b-a is less than or equal to 0, print "delicious".
			case 0:
				System.out.println("delicious");
				break;
			// If b-a is greater than 0 but less than or equal to x, print "safe".
			case 1:
				System.out.println("safe");
				break;
			// If b-a is greater than x, print "dangerous".
			default:
				System.out.println("dangerous");
				break;
		}
	}
}

