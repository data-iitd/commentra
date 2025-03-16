package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize a map to count occurrences of integers
		Map<Integer, Integer> m = new HashMap<>();

		// Read the number of initial integers (N) and the number of operations (M)
		int N = ReadInt();
		int M = ReadInt();

		// Read N integers and count their occurrences in the map
		for (int i = 0; i < N; i++) {
			int x = ReadInt();
			m.put(x, m.getOrDefault(x, 0) + 1);
		}

		// Process M operations, where each operation adds B occurrences of integer C
		for (int i = 0; i < M; i++) {
			int B = ReadInt();
			int C = ReadInt();
			m.put(C, m.getOrDefault(C, 0) + B);
		}

		// Create a slice to hold the unique integers from the map
		List<Integer> ints = new ArrayList<>();
		for (int i : m.keySet()) {
			ints.add(i);
		}

		// Sort the integers in descending order
		Collections.sort(ints, Collections.reverseOrder());

		// Initialize variables to keep track of remaining integers and the total sum
		int rest = N;
		int sum = 0;

		// Calculate the maximum sum based on the sorted integers
		for (int i : ints) {
			int num = m.get(i);
			// If the number of occurrences is greater than or equal to the remaining count
			if (num >= rest) {
				sum += rest * i; // Add the product of remaining count and the integer
				break; // Exit the loop as we have used all remaining integers
			}
			sum += num * i; // Add the product of occurrences and the integer to the sum
			rest -= num; // Decrease the remaining count by the number of occurrences
		}

		// Output the final calculated sum
		System.out.println(sum);
	}

	// Initialize a buffered reader for input
	private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

	// Scan reads input and handles any errors
	private static void Scan(String format, Object... args) throws IOException {
		if (format == null || args == null)
			return;
		System.out.format(format, args);
		System.out.flush();
	}

	// ReadInt reads an integer from input and returns it
	private static int ReadInt() throws IOException {
		int x = Integer.parseInt(reader.readLine());
		return x;
	}
}

