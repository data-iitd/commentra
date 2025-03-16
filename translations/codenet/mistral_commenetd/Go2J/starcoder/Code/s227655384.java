// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

// ReadLongLines function reads long lines from standard input
public static String[] ReadLongLines(int times) throws IOException {
	// Initialize result slice with the given size
	String[] result = new String[times];
	// Initialize a new buffered reader
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	// Initialize a new bytes.Buffer
	StringBuffer buffer = new StringBuffer();
	// Initialize readBytes variable to keep track of the total number of bytes read
	long readBytes = 2;

	// For each iteration, read a line from the standard input
	for (int i = 0; i < times; i++) {
		// Read a line from the standard input
		for (boolean isPrefix = true; isPrefix; ) {
			// Read a line from the standard input
			String readBuf = reader.readLine();
			// Check if an error occurred during the read operation
			if (readBuf == null) {
				// If the error is of type io.EOF, it means that the end of the input has been reached
				if (readBytes == 0) {
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
			isPrefix = readBuf.endsWith("\n") == false;
			// Increment the total number of bytes read
			readBytes += readBuf.length();
		}
		// Seek back the standard input stream to the position before the last read operation
		reader.seek(reader.getFilePointer() - readBytes);
	}
	// Return the result
	return result;
}

// Console type is used to manage the standard output
public class Console {
	// Initialize a new buffered writer
	private BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	// Printf function prints formatted strings to the Console writer
	public void Printf(String format, Object... a) throws IOException {
		// Format and print the given arguments to the Console writer
		writer.write(String.format(format, a));
	}

	// Println function prints a newline character followed by the given string to the Console writer
	public void Println(String s) throws IOException {
		// Format and print the given string followed by a newline character to the Console writer
		writer.write(s + "\n");
	}

	// Close function flushes the Console writer and closes it
	public void Close() throws IOException {
		// Flush and close the Console writer
		Flush();
		writer.close();
	}

	// Flush function flushes the Console writer
	public void Flush() throws IOException {
		// Flush the Console writer
		writer.flush();
	}
}

// PrintList function prints an integer slice to the standard output
public static void PrintList(int[] list) throws IOException {
	// Initialize a new Console instance
	Console con = new Console();
	// Defer the Flush function to be called when the function returns
	try {
		// Iterate through the given integer slice and print each element to the standard output
		for (int i = 0; i < list.length; i++) {
			// If it's the first element, print it without a separator
			if (i == 0) {
				con.Printf("%d", list[i]);
			} else {
				// Otherwise, print it with a separator
				con.Printf(" %d", list[i]);
			}
		}
		// Print a newline character to the standard output
		con.Println("");
	} finally {
		// Flush and close the Console writer
		con.Close();
	}
}

// main function is the entry point of the program
public class Main {
	// main function is the entry point of the program
	public static void main(String[] args) throws IOException {
		// Initialize a new Console instance
		Console con = new Console();
		// Defer the Flush function to be called when the function returns
		try {
			// Initialize an empty map to store unique integers
			Map<Integer, Object> m = new HashMap<>();
			// Read long lines from the standard input
			String[] lines = ReadLongLines(4);
			// Split the second line into an integer slice
			String[] a = lines[1].split(" ");
			// Iterate through the integer slice and add each integer to the map
			for (int i = 0; i < a.length; i++) {
				// Parse the integer from the string and add it to the map
				int n = Integer.parseInt(a[i]);
				m.put(n, null);
			}

			// Read integers from the fourth line and add them to the map if they are not already present
			String[] b = lines[3].split(" ");
			for (int i = 0; i < b.length; i++) {
				// Parse the integer from the string and add it to the map if it's not already present
				int n = Integer.parseInt(b[i]);
				if (!m.containsKey(n)) {
					m.put(n, null);
				}
			}

			// Extract the unique integers from the map and store them in a slice
			int[] result = new int[m.size()];
			int j = 0;
			for (int k : m.keySet()) {
				// Append the integer to the result slice
				result[j++] = k;
			}

			// Sort the result slice in ascending order
			Arrays.sort(result);

			// Iterate through the sorted result slice and print each integer to the standard output
			for (int j = 0; j < result.length; j++) {
				// Print each integer to the standard output
				con.Printf("%d\n", result[j]);
			}
		} finally {
			// Flush and close the Console writer
			con.Close();
		}
	}
}

// 