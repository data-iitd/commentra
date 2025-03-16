
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize week array with 7 days of the week
		String[] week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

		// Read input string from scanner
		Scanner sc = new Scanner(System.in);
		String s = sc.next();

		// Find index of the given day in week array
		int index = -1;
		for (int i = 0; i < week.length; i++) {
			if (s.equals(week[i])) {
				index = i;
				break;
			}
		}

		// If the given day is not present in the week array, panic with error message
		if (index == -1) {
			System.out.println("Invalid day of the week");
		}

		// Calculate the number of days between the given day and Sunday
		// and print the result
		int daysUntilSunday = 7 - index;
		System.out.println("The number of days until Sunday is: " + daysUntilSunday);
	}
}

// 