import java.util.*;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws IOException 
	{ 
		// Initialize BufferedReader to read input from standard input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// Initialize PrintWriter to output results to standard output
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		
		// Read the first line of input and tokenize it to get the number of elements
		StringTokenizer s = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(s.nextToken());
		
		// Create a HashMap to store the frequency of each integer
		HashMap<Integer, Integer> hm = new HashMap<>();
		
		// Read the second line of input and populate the HashMap with frequencies
		s = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			int val = Integer.parseInt(s.nextToken());
			// Update the frequency count for the current value
			hm.put(val, hm.getOrDefault(val, 0) + 1);
		}
		
		// Initialize a variable to hold the final answer
		int ans = 0;
		
		// Iterate through the HashMap to calculate the result based on the frequency and value
		for (int val : hm.keySet()) {
			int num = hm.get(val);
			// If frequency is greater than the value, add the difference to the answer
			if (num > val)
				ans += num - val;
			// If frequency is less than the value, add the frequency to the answer
			else if (num < val)
				ans += num;
		}
		
		// Print the final answer
		pw.println(ans);
		// Close the PrintWriter to flush the output
		pw.close();
	}
}
