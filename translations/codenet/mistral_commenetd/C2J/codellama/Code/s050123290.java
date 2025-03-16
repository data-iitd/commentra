#include<stdio.h>
#define N 1000  // Define a constant N with the value 1000

public class Main {
	public static void main(String[] args) {
		char[] su = new char[N]; // Declare a character array 'su' of size N
		int susum = 0; // Initialize an integer variable 'susum' to zero
		int j = 0; // Initialize an integer variable 'j' to zero

		while (true) { // Start an infinite loop
			for (j = 0; j <= N; j++) { // Iterate through each index of the array 'su'
				su[j] = (char) System.in.read(); // Read a character from the standard input and store it in the array 'su' at the current index
				if (su[j] == '\n')
					break; // If the character read is a newline character, break out of the loop
				susum = susum + (su[j] - '0'); // Add the ASCII value of the character (after subtracting '0') to the variable 'susum'
			}
			if (su[0] == '0')
				break; // If the first character of the array 'su' is '0', break out of the loop
			System.out.println(susum); // Print the sum of the digits read from the standard input
			susum = 0; // Reset the variable 'susum' to zero for the next iteration
		}
	}
}

