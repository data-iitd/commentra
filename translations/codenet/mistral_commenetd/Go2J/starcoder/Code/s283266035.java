
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare a variable n of type int and initialize it to zero
		int n = 0;
		// Read an integer value from the standard input and store it in the variable n
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		// Declare a variable ans of type int and initialize it to zero
		int ans = 0;
		// Use a for loop to iterate through all possible factors of n
		for (int i = 1; i*i < n; i++) {
			// Check if i is a factor of n
			if (n % i == 0) {
				// Check if i is the last factor of n
				if (n % (n / i - 1) == i) {
					// If both conditions are true, add the last factor to the answer
					ans += n / i - 1;
				}
			}
		}
		// Print the answer to the standard output
		System.out.println(ans);
		// End of the code
	}

}

