package main;

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		// Reads the number of elements N.
		int N = scanner.nextInt();
		
		// Initializes slices X and Y to store N integers.
		int[] X = new int[N];
		int[] Y = new int[N];
		
		// Reads N integers into slice X and copies them to slice Y.
		for (int i = 0; i < N; i++) {
			X[i] = scanner.nextInt();
			Y[i] = X[i];
		}
		
		// Sorts slice Y in ascending order.
		Arrays.sort(Y);
		
		// Calculates the two middle values of the sorted slice Y.
		int m1 = Y[N / 2 - 1];
		int m2 = Y[N / 2];
		
		// For each element in slice X, prints the corresponding median value.
		for (int i = 0; i < N; i++) {
			if (X[i] <= m1) {
				System.out.println(m2);
			} else {
				System.out.println(m1);
			}
		}
		
	}

}

// Helper function to return the maximum of two integers.
public static int Max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Helper function to return the minimum of two integers.
public static int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Helper function to return the absolute value of an integer.
public static int Abs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

