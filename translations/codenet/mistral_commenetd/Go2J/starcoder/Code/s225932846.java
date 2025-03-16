
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Read a string input from the user using sc.next() function and store it in the variable S
		String S = sc.next();

		// Initialize a variable i with value 2
		int i = 2;

		// Start a for loop that runs as long as i is less than or equal to the length of the string S
		for (i <= S.length()) {

			// Check if the first half of the string S (from index 0 to (S.length()-i)/2) is equal to the second half of the string S (from index (S.length()-i)/2 to S.length()-i)
			if (S.substring(0, (S.length()-i)/2).equals(S.substring((S.length()-i)/2, S.length()-i))) {

				// If the condition is true, print the length of the substring (S.length() - i) and break out of the loop
				System.out.println(S.length() - i);
				break;
			}

			// Increment the value of i by 2
			i += 2;
		}
	}
}

