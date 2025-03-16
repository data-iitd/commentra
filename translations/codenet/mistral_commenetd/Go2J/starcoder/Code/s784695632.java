
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Define the function "main" as the entry point of our program.
		Scanner sc = new Scanner(System.in);
		int x, y;

		// Read the values of variables "x" and "y" from the standard input.
		x = sc.nextInt();
		y = sc.nextInt();

		// Print the result of the expression "x + y/2" to the standard output.
		System.out.println(x + y/2);

		// End of code.
	}
}

