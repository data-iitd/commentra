
package main;

import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		// Read the input string from the standard input using Scanner class
		Scanner sc = new Scanner(System.in);
		String s = sc.next();

		// Initialize two integer variables max_tmp and max with zero values
		int max_tmp = 0;
		int max = 0;

		// Iterate through each character in the input string using a for loop
		for (int i = 0; i < s.length(); i++) {
			// Initialize a boolean variable flag with false value
			boolean flag = false;

			// Check the character type using switch statement
			switch (s.charAt(i)) {
			case 'A':
			case 'C':
			case 'T':
			case 'G':
				// Increment the max_tmp variable by 1 for each valid character encountered
				max_tmp++;
				break;
			default:
				// Set the flag variable to true if the character is not a valid nucleotide
				flag = true;
			}

			// Check if the current character is the last character in the input string
			if (i == s.length() - 1) {
				// Set the flag variable to true if the current character is the last character
				flag = true;
			}

			// If the flag variable is true, then the current character is not a valid nucleotide
			// So, we need to check if the max variable is less than the max_tmp value
			// If yes, then update the max variable with the max_tmp value
			if (flag == true) {
				if (max < max_tmp) {
					max = max_tmp;
				}
				// Reset the max_tmp variable to zero as we have processed the current sequence of valid nucleotides
				max_tmp = 0;
			}
		}

		// Print the maximum length of a valid sequence of nucleotides found in the input string
		System.out.println(max);

		// End of the code
	}
}

