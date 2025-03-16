
import java.util.*;
import java.io.*;

/**
 * Main class for the problem
 */
public class Main {
	
	/**
	 * Entry point of the program
	 * @param args command line arguments
	 * @throws IOException for reading and writing files
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		// Read input
		StringTokenizer s = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(s.nextToken()); // Number of integers to be read

		// Initialize HashMap to store the frequency of each integer
		HashMap<Integer, Integer> hm = new HashMap<>();

		// Read integers and store their frequency in the HashMap
		s = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			int val = Integer.parseInt(s.nextToken());
			hm.put(val, hm.getOrDefault(val, 0) + 1);
		}

		// Calculate answer
		int ans = 0;
		for (int val : hm.keySet()) {
			int num = hm.get(val);
			if (num > val) { // If the frequency is greater than the value
				ans += num - val; // Add the difference to the answer
			} else if (num < val) { // If the frequency is less than the value
				ans += num; // Add the frequency to the answer
			}
		}

		// Print the answer
		pw.println(ans);
		pw.close();
	}
}