
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare an integer variable 'a'
		int a;
		
		// Read an integer value from the standard input and assign it to 'a'
		Scanner scanner = new Scanner(System.in);
		a = scanner.nextInt();
		
		// Print the result of the expression 3 * a * a
		System.out.println(3 * a * a);
	}

}

