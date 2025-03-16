
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		// Create a map to store the counts of integers
		Map<Integer, Integer> m = new HashMap<Integer, Integer>();
		
		// Read the number of initial elements (N) and the number of operations (M)
		int N = ReadInt();
		int M = ReadInt();
		
		// Read N integers and store their counts in the map
		for (int i = 0; i < N; i++) {
			int x = ReadInt();
			if (m.containsKey(x)) {
				m.put(x, m.get(x) + 1);
			} else {
				m.put(x, 1);
			}
		}
		
		// Perform M operations to update the map with new integers and their counts
		for (int i = 0; i < M; i++) {
			int B = ReadInt();
			int C = ReadInt();
			if (m.containsKey(C)) {
				m.put(C, m.get(C) + B);
			} else {
				m.put(C, B);
			}
		}
		
		// Create a list of integers from the map keys
		List<Integer> ints = new ArrayList<Integer>(m.keySet());
		
		// Sort the list of integers in descending order
		Collections.sort(ints, Collections.reverseOrder());
		
		// Initialize variables to keep track of the remaining elements and the sum
		int rest = N;
		int sum = 0;
		
		// Iterate through the sorted integers and calculate the sum based on the conditions
		for (int i = 0; i < ints.size(); i++) {
			int x = ints.get(i);
			int num = m.get(x);
			if (num >= rest) {
				sum += rest * x;
				break;
			}
			sum += num * x;
			rest -= num;
		}
		
		// Print the calculated sum
		System.out.println(sum);
	}
	
	// Helper function to read an integer from stdin
	private static int ReadInt() {
		try {
			return Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
		} catch (IOException e) {
			return -1;
		}
	}
}

