
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize an empty map to store the frequency of each number
		Map<Integer, Integer> m = new HashMap<Integer, Integer>();

		// Read the number of test cases N
		int N = ReadInt();
		// Read the N integers and store their frequencies in the map
		for (int i = 0; i < N; i++) {
			int num = ReadInt();
			if (m.containsKey(num)) {
				m.put(num, m.get(num) + 1);
			} else {
				m.put(num, 1);
			}
		}

		// Read the number of queries M
		int M = ReadInt();
		// For each query, read the number B and the index C, and update the frequency of the number at index C in the map
		for (int i = 0; i < M; i++) {
			int B = ReadInt();
			int C = ReadInt();
			if (m.containsKey(C)) {
				m.put(C, m.get(C) + B);
			} else {
				m.put(C, B);
			}
		}

		// Create a slice of integers from the map keys
		int[] ints = new int[m.size()];
		int i = 0;
		// Populate the slice with the map keys
		for (int k : m.keySet()) {
			ints[i] = k;
			i++;
		}

		// Sort the slice in descending order
		Arrays.sort(ints);
		Arrays.sort(ints, Collections.reverseOrder());

		// Initialize variables for calculating the sum
		int rest = N;
		int sum = 0;
		// Iterate through the sorted slice of integers
		for (int j : ints) {
			int num = m.get(j);
			// If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
			if (num >= rest) {
				sum += rest * j;
				break;
			}
			// Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
			sum += num * j;
			rest -= num;
		}

		// Print the result
		System.out.println(sum);
	}

	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

	static String next() throws IOException {
		while (true) {
			String w = reader.readLine();
			if (w.length() == 0)
				continue;
			return w;
		}
	}

	static int ReadInt() throws IOException {
		return Integer.parseInt(next());
	}
}

