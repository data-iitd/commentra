package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Read two integers A and B from standard input
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();

		// Check if the sum of A and B is even
		if ((A + B) % 2 == 0) {
			// If even, print the average of A and B
			System.out.println((A + B) / 2);
			return;
		}
		// If not even, print "IMPOSSIBLE"
		System.out.println("IMPOSSIBLE");
	}
}

