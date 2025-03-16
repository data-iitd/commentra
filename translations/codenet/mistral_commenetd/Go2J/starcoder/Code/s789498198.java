package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize scanner and read the first line
		Scanner sc = new Scanner(System.in);
		sc.useDelimiter(" ");
		int A = sc.nextInt();
		int B = sc.nextInt();

		// Check if the sum of A and B is even
		if ((A + B) % 2 == 0) {
			// If it is, print the result (the average)
			System.out.println((A + B) / 2);
			return;
		}
		// If the sum is odd, print "IMPOSSIBLE"
		System.out.println("IMPOSSIBLE");
	}
}

