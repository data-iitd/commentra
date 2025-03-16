package main;

import java.util.*;

public class Main {

	public static void main(String[] args) {
		// Reading the string input using 'Scanner' class
		Scanner sc = new Scanner(System.in);

		// Declaring a variable's' of type 'String' to store the input string
		String s = sc.next();

		// Declaring a variable 'ans' of type 'int' to store the answer
		int ans = 0;

		// Looping through each character 'c' in the string's'
		for (int i = 0; i < s.length(); i++) {
			// Checking if the current character 'c' is equal to '1'
			if (s.charAt(i) == '1') {
				// Incrementing the answer if the character is '1'
				ans++;
			}
		}

		// Printing the answer
		System.out.println(ans);

		// Closing the scanner
		sc.close();
	}
}

