package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		// Read two integers from input
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();

		// Check if the sum of A and B is even
		if ((A + B) % 2 == 0) {
			// If even, print the average
			System.out.println((A + B) / 2);
			return;
		}
		// If odd, print "IMPOSSIBLE"
		System.out.println("IMPOSSIBLE");
	}
}

