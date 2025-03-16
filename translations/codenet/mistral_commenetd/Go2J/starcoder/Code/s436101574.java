
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

		// Reading input strings s and t
		String s = sc.next();
		String t = sc.next();

		// Initializing an empty slice to store answers
		List<String> ans = new ArrayList<String>();

		// Iterating through all possible substrings of s that have the same length as t
		for (int i = 0; i < s.length() - t.length() + 1; i++) {
			// Initializing a slice to store the modified string s
			char[] ss = s.toCharArray();

			// Checking if the current substring matches the pattern t
			boolean f = true;
			for (int j = 0; j < t.length(); j++) {
				// If the current character of s does not match the current character of t or is not '?'
				if (ss[i + j]!= t.charAt(j) && ss[i + j]!= '?') {
					// Setting flag to false and breaking the loop
					f = false;
					break;
				} else {
					// Replacing the current character of s with the corresponding character of t
					ss[i + j] = t.charAt(j);
				}
			}
			// If the current substring matches the pattern t
			if (f) {
				// Appending the modified string to the answer slice
				ans.add(new String(ss).replace("?", "a"));
			}
		}
		// Sorting the answer slice in ascending order
		Collections.sort(ans);
		// Checking if the answer slice is empty
		if (ans.isEmpty()) {
			// Printing "UNRESTORABLE" if the answer slice is empty
			wr.write("UNRESTORABLE");
		} else {
			// Printing the first element of the answer slice
			wr.write(ans.get(0));
		}
		wr.close();
	}
}

