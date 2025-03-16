package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize scanner and writer for input and output
		Scanner sc = new Scanner(System.in);
		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

		// Set the scanner to split input by whitespace and configure buffer size
		sc.useDelimiter("\\s+");
		sc.tokens.nextElement();
		sc.tokens.nextElement();

		// Read the first string of runes (s)
		String s = sc.next();
		// Read the second string of runes (t)
		String t = sc.next();

		// Initialize a slice to hold possible answers
		List<String> ans = new ArrayList<String>();
		
		// Iterate through the first string to find occurrences of the second string
		for (int i = 0; i < s.length() - t.length() + 1; i++) {
			boolean f = true; // Flag to check if the current position is valid
			char[] ss = s.toCharArray(); // Create a copy of the original string

			// Check if the substring of s can match t
			for (int j = 0; j < t.length(); j++) {
				// If characters do not match and are not '?', set flag to false
				if (s.charAt(i+j)!= t.charAt(j) && s.charAt(i+j)!= '?') {
					f = false;
					break;
				} else {
					// Replace '?' with the corresponding character from t
					ss[i+j] = t.charAt(j);
				}
			}
			// If the substring matched, replace remaining '?' with 'a' and store the result
			if (f) {
				ans.add(new String(ss).replace("?", "a"));
			}
		}

		// Sort the possible answers
		Collections.sort(ans);

		// Output the result: either the first valid answer or "UNRESTORABLE"
		if (ans.size() == 0) {
			wr.write("UNRESTORABLE");
		} else {
			wr.write(ans.get(0));
		}
		wr.newLine();

		// Close scanner and writer
		sc.close();
		wr.close();
	}
}

