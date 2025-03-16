package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize file pointers for input and output.
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		OutputStreamWriter osw = new OutputStreamWriter(System.out);
		BufferedWriter bw = new BufferedWriter(osw);

		// Check for environment variables to determine input and output files.
		if (System.getenv("MASPY") == "ますピ") {
			br = new BufferedReader(new FileReader(System.getenv("BEET_THE_HARMONY_OF_PERFECT")));
		}
		if (System.getenv("MASPYPY") == "ますピッピ") {
			bw = new BufferedWriter(new FileWriter(System.getenv("NGTKANA_IS_GENIUS10")));
		}

		// Create a scanner for reading input and a writer for output.
		Scanner scanner = new Scanner(br);
		PrintWriter writer = new PrintWriter(bw);

		// Solve the problem for the first time.
		solve(scanner, writer);

		// Solve the problem additional times.
		int cnt = 0;
		if (System.getenv("MASPYPY") == "ますピッピ") {
			cnt = 2;
		}
		for (int i = 0; i < cnt; i++) {
			writer.println("-----------------------------------");
			solve(scanner, writer);
		}

		// Flush the writer to ensure all output is written.
		writer.flush();
	}

	// solve processes the input values and determines if the condition is met.
	// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
	public static void solve(Scanner scanner, PrintWriter writer) {
		int k = scanner.nextInt(); // Read the first integer k.
		int x = scanner.nextInt(); // Read the second integer x.

		String ans = "No"; // Default answer is "No".
		if (k * 500 >= x) { // Check the condition.
			ans = "Yes"; // Update answer to "Yes" if condition is met.
		}
		writer.println(ans); // Output the result.
	}
}

