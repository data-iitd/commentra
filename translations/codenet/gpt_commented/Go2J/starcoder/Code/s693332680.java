package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare variables to hold input values
		int x, a, b;
		
		// Read three integer values from standard input
		Scanner sc = new Scanner(System.in);
		x = sc.nextInt();
		a = sc.nextInt();
		b = sc.nextInt();
		
		// Evaluate the difference between b and a to determine the output
		if (b-a <= 0) {
			System.out.println("delicious"); // Output "delicious" if b is less than or equal to a
		} else if (b-a <= x) {
			System.out.println("safe"); // Output "safe" if the difference is within the limit x
		} else {
			System.out.println("dangerous"); // Output "dangerous" if the difference exceeds x
		}
	}
}

