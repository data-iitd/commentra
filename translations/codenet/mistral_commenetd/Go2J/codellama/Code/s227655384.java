
// Package main is the entry point of the program
package main

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// ReadLongLines function reads long lines from standard input
public static String[] ReadLongLines(int times) throws IOException {
	// Initialize result array with the given size
	String[] result = new String[times];
	// Initialize a new BufferedReader
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	// Initialize a new StringBuilder
	StringBuilder buffer = new StringBuilder();
	// Initialize readBytes variable to keep track of the total number of bytes read
	int readBytes = 2;

	// For each iteration, read a line from the standard input
	for (int i = 0; i < times; i++) {
		// Read a line from the standard input
		for (;;) {
			// Read a line from the standard input
			String readBuf = reader.readLine();
			// Check if an error occurred during the read operation
			if (readBuf == null) {
				// If the error is of type io.EOF, it means that the end of the input has been reached
				if (readBuf == null) {
					System.out.println("EOF");
					// Break the loop if the end of the input has been reached
					break;
				} else {
					// Return an error if an error other than io.EOF occurred
					return result;
				}
			}
			// Write the read line to the buffer
			buffer.append(readBuf);
			// Check if the line read is the last line of the input
			if (!reader.ready()) {
				// Store the content of the line in the result array
				result[i] = buffer.toString();
				// Reset the buffer for the next iteration
				buffer.setLength(0);
				// Break the inner loop if the line read is the last line of the input
				break;
			}
		}
		// Seek back the standard input stream to the position before the last read operation
		System.in.skip(-readBytes);
	}
	// Return the result and nil error
	return result;
}

// Console type is used to manage the standard output
class Console {
	// Initialize a new BufferedWriter
	private BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	// Printf function prints formatted strings to the Console writer
	public void Printf(String format, Object... a) {
		// Format and print the given arguments to the Console writer
		try {
			writer.write(String.format(format, a));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// Println function prints a newline character followed by the given string to the Console writer
	public void Println(String s) {
		// Format and print the given string followed by a newline character to the Console writer
		try {
			writer.write(s + "\n");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// Close function flushes the Console writer and closes it
	public void Close() {
		// Flush and close the Console writer
		try {
			writer.flush();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

// PrintList function prints an integer slice to the standard output
public static void PrintList(List<Integer> list) {
	// Initialize a new Console instance
	Console con = new Console();
	// Defer the Close function to be called when the function returns
	try {
		con.Close();
	} catch (IOException e) {
		e.printStackTrace();
	}
	// Iterate through the given integer slice and print each element to the standard output
	for (int i = 0; i < list.size(); i++) {
		// If it's the first element, print it without a separator
		if (i == 0) {
			con.Printf("%d", list.get(i));
		} else {
			// Otherwise, print it with a separator
			con.Printf(" %d", list.get(i));
		}
	}
	// Print a newline character to the standard output
	con.Println("");
}

// main function is the entry point of the program
public static void main(String[] args) throws IOException {
	// Initialize a new Console instance
	Console con = new Console();
	// Defer the Close function to be called when the function returns
	try {
		con.Close();
	} catch (IOException e) {
		e.printStackTrace();
	}

	// Initialize an empty map to store unique integers
	Map<Integer, Integer> m = new HashMap<>();
	// Read long lines from the standard input
	String[] lines = ReadLongLines(4);
	// Split the second line into an integer slice
	String[] a = lines[1].split(" ");
	// Iterate through the integer slice and add each integer to the map
	for (int i = 0; i < a.length; i++) {
		// Parse the integer from the string and add it to the map
		int n = Integer.parseInt(a[i]);
		m.put(n, 1);
	}

	// Read integers from the fourth line and add them to the map if they are not already present
	String[] b = lines[3].split(" ");
	for (int i = 0; i < b.length; i++) {
		// Parse the integer from the string and add it to the map if it's not already present
		int n = Integer.parseInt(b[i]);
		if (!m.containsKey(n)) {
			m.put(n, 1);
		}
	}

	// Extract the unique integers from the map and store them in a slice
	List<Integer> result = new ArrayList<>();
	for (int k : m.keySet()) {
		// Append the integer to the result slice
		result.add(k);
	}

	// Sort the result slice in ascending order
	result.sort((lhs, rhs) -> lhs - rhs);

	// Iterate through the sorted result slice and print each integer to the standard output
	for (int j = 0; j < result.size(); j++) {
		// Print each integer to the standard output
		con.Printf("%d\n", result.get(j));
	}
}

