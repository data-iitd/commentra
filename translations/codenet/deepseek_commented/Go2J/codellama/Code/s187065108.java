
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize scanner to read input
		Scanner sc = new Scanner(System.in);
		
		// Read initial values for r, D, and x
		int r = sc.nextInt();
		int D = sc.nextInt();
		int x = sc.nextInt();
		
		// Loop to calculate and print the values of x for 10 iterations
		for (int i = 1; i <= 10; i++) {
			x = r*x - D;
			System.out.println(x);
		}
		
		// Close scanner
		sc.close();
	}
}

