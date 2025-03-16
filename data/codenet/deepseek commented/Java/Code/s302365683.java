import java.util.*;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws IOException 
	{ 
		// Create BufferedReader to read from standard input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// Create PrintWriter to write to standard output
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		
		// Read the number of elements
		StringTokenizer s = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(s.nextToken());
		
		// Initialize a HashMap to store the frequency of each integer
		HashMap<Integer, Integer> hm = new HashMap<>();
		
		// Read the values and update the frequency in the HashMap
		s = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			int val = Integer.parseInt(s.nextToken());
			hm.put(val, hm.getOrDefault(val, 0) + 1);
		}
		
		// Initialize the answer variable
		int ans = 0;
		
		// Iterate over the keys of the HashMap
		for (int val : hm.keySet()) {
			int num = hm.get(val);
			// Calculate the difference and add it to the answer
			if (num > val)
				ans += num - val;
			else if (num < val)
				ans += num;
		}
		
		// Print the answer and close the PrintWriter
		pw.println(ans);
		pw.close();
	}
}
