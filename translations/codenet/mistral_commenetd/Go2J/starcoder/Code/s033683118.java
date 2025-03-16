package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize the scanner and writer
		Scanner scanner = new Scanner(System.in);
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

		// Solve the problem for the given test cases
		solve(scanner, writer);
		writer.close();
	}

	// Function to solve the problem for a single test case
	public static void solve(Scanner scanner, BufferedWriter writer) throws IOException {
		// Read the input values
		int k = scanner.nextInt();
		int x = scanner.nextInt();

		// Initialize the answer
		String ans = "No";

		// Check if the condition is satisfied
		if (k * 500 >= x) {
			ans = "Yes";
		}

		// Print the answer
		writer.write(ans);
		writer.newLine();
	}
}

