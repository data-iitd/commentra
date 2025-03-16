import java.io.*;
import java.util.*;

public class Main {
	// Solve function processes the input and calculates the result.
	static void solve() {
		String tmp = ns(); // Read input string
		char s[] = tmp.toCharArray(); // Convert string to character array
		int n = s.length; // Get length of the array
		int ans = 0; // Initialize answer variable
		int cnt = 0; // Initialize count variable
		for(int i=0;i<n;i++) { // Iterate through the array
			if(s[i]=='S') { // If current character is 'S'
				cnt++; // Increment count
			} else { // If current character is 'X'
				if(cnt == 0) continue; // If count is 0, continue to next iteration
				ans++; // Increment answer
				cnt--; // Decrement count
			}
		}
		out.println(n - 2*ans); // Print the result
	}

	// Constant declarations and utility functions follow...
}
