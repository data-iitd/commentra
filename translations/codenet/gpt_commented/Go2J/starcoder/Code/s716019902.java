package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize a new scanner for reading input
		Scanner sc = new Scanner(System.in);
		// Read an integer N from input
		int N = sc.nextInt();
		int sum = 0;
		
		// Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
		for (int i = 1; i <= N; i++) {
			if (i % 3 == 0 || i % 5 == 0) {
				continue; // Skip numbers divisible by 3 or 5
			}
			sum += i; // Add the number to the sum
		}
		
		// Output the final sum
		System.out.println(sum);
	}
}

// 