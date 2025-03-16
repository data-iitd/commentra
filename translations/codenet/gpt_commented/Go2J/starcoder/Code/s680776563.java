package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize a new Scanner to read input
		Scanner sc = new Scanner(System.in);
		// Read three integers A, B, and C from input
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		// Check if the difference between B and A is equal to the difference between C and B
		if (B - A == C - B) {
			// If the differences are equal, print "YES"
			System.out.println("YES");
		} else {
			// Otherwise, print "NO"
			System.out.println("NO");
		}
	}
}

