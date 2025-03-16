
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare a variable named day of type int
		int day;

		// Read an integer value from the standard input using fmt.Scan()
		Scanner in = new Scanner(System.in);
		day = in.nextInt();

		// Use a switch statement to determine the name of the day based on the given day number
		switch (day) {
		case 25:
			// If the day is 25, print "Christmas"
			System.out.println("Christmas");
			break;
		case 24:
			// If the day is 24, print "Christmas Eve"
			System.out.println("Christmas Eve");
			break;
		case 23:
			// If the day is 23, print "Christmas Eve Eve"
			System.out.println("Christmas Eve Eve");
			break;
		case 22:
			// If the day is 22, print "Christmas Eve Eve Eve"
			System.out.println("Christmas Eve Eve Eve");
			break;
		}
	}
}

