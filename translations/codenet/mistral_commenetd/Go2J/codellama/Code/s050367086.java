
// Package main is the entry point of the program
package main

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// getScanner returns a new BufferedReader from the given file pointer
public static BufferedReader getScanner(InputStreamReader fp) {
	return new BufferedReader(fp);
}

// getNextString reads and returns the next string from the scanner
public static String getNextString(BufferedReader scanner) throws Exception {
	return scanner.readLine();
}

// getNextInt reads and converts the next integer from the scanner
public static int getNextInt(BufferedReader scanner) throws Exception {
	return Integer.parseInt(getNextString(scanner));
}

// getNextInt64 reads and converts the next int64 from the scanner
public static long getNextInt64(BufferedReader scanner) throws Exception {
	return Long.parseLong(getNextString(scanner));
}

// getNextUint64 reads and converts the next uint64 from the scanner
public static long getNextUint64(BufferedReader scanner) throws Exception {
	return Long.parseLong(getNextString(scanner));
}

// getNextFloat64 reads and converts the next float64 from the scanner
public static double getNextFloat64(BufferedReader scanner) throws Exception {
	return Double.parseDouble(getNextString(scanner));
}

// main function is the entry point of the program
public static void main(String[] args) throws Exception {
	// Open the standard input and output files
	InputStreamReader fp = new InputStreamReader(System.in);
	PrintWriter wfp = new PrintWriter(System.out);

	// If environment variables are set, open input and output files accordingly
	if (System.getenv("MASPY") != null && System.getenv("MASPY").equals("ますピ")) {
		fp = new InputStreamReader(new FileInputStream(System.getenv("BEET_THE_HARMONY_OF_PERFECT")));
	}
	if (System.getenv("MASPYPY") != null && System.getenv("MASPYPY").equals("ますピッピ")) {
		wfp = new PrintWriter(new FileOutputStream(System.getenv("NGTKANA_IS_GENIUS10")));
	}

	// Initialize scanner and writer
	BufferedReader scanner = getScanner(fp);
	PrintWriter writer = wfp;

	// Read the first two strings from the input
	String s = getNextString(scanner);
	String t = getNextString(scanner);

	// Initialize variables and structures
	int ns = s.length();
	int nt = t.length();
	List<String> ss = new ArrayList<String>();

	// Initialize ss with repeated string s
	for (int i = 0; i < (nt - 1) / ns + 1; i++) {
		ss.add(s);
	}

	// Combine all ss strings into one long string
	String sss = String.join("", ss) + String.join("", ss);

	// Initialize boolean array ok to keep track of unique characters
	boolean[] ok = new boolean[ns];

	// Initialize unordered map mp and array uni for suffix array calculation
	Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
	mp.put(0, -1);
	int m = 0;

	// Initialize uni array with indices from 0 to n-1
	int[] uni = new int[ns];
	for (int i = 0; i < ns; i++) {
		uni[i] = i;
	}

	// Initialize variable o for checking if current and next characters match
	boolean o = true;

	// Iterate through all characters in string s
	for (int i = 0; i < ns; i++) {
		// Initialize o to true
		o = true;

		// Iterate through all characters in string t
		for (m = 0; m < nt; m++) {
			// Check if current character in s matches the character at the same position in t
			if (t.charAt(m) != sss.charAt(i + m)) {
				// If not, set o to false and break the loop
				o = false;
				break;
			}
			// Increment m
			m++;
		}

		// If all characters match, set ok[i] to true and update variables r and m accordingly
		if (o) {
			i += nt - mp.get(m);
			m = mp.get(m);
		}

		// While characters in s and t do not match, update i and m accordingly
		for (m = 0; m >= 0 && t.charAt(m) != sss.charAt(i + m); m = mp.get(m)) {
			i += m - mp.get(m);
		}

		// Decrement i and increment m to move to the next pair of characters
		i--;
		m++;
	}

	// Initialize variable ans to store the answer
	int ans = 0;

	// Initialize variables r and rr for root calculation
	int r, rr;

	// Iterate through all characters in string s again
	for (int i = 0; i < ns; i++) {
		// If ok[i] is false, continue to the next iteration
		if (!ok[i]) {
			continue;
		}

		// If ok[(i+nt)%ns] is false, continue to the next iteration
		if (!ok[(i + nt) % ns]) {
			continue;
		}

		// Calculate roots r and rr of indices i and (i+nt)%ns respectively
		r = root(i, uni);
		rr = root((i + nt) % ns, uni);

		// If roots r and rr are equal, print -1 and exit the program
		if (rr == r) {
			writer.println(-1);
			return;
		}

		// Update uni array with root r
		uni[rr] = r;
	}

	// Initialize counter array to store the frequency of each root
	int[] counter = new int[ns];

	// Iterate through all roots and update their frequencies in counter array
	for (int i = 0; i < ns; i++) {
		r = root(i, uni);
		if (!ok[r]) {
			continue;
		}
		counter[r]++;
	}

	// Find the maximum frequency in counter array and store it in variable ans
	for (int i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i];
		}
	}

	// Print the answer
	writer.println(ans);

	// Flush the writer buffer
	writer.flush();
}

// root function returns the root of the given index in uni array
public static int root(int i, int[] uni) {
	// If index i is equal to its root, return i
	if (i == uni[i]) {
		return i;
	}

	// Recursively call root function with the root of index i
	uni[i] = root(uni[i], uni);
	return uni[i];
}

