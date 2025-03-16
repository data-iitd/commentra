
// Package main contains the entry point of the program.
package main

// Scanner class represents the input reader.
class Scanner {
	// bufio.Reader field r is used for reading from the standard input.
	private java.io.BufferedReader r;
	// buf byte slice buffer is used for storing the input line.
	private byte[] buf;
	// p integer p keeps track of the current position in the buffer.
	private int p;

	// NewScanner function initializes a new Scanner object with the standard input os.Stdin as the reader.
	public Scanner() {
		// Initialize a new bufio.Reader object named rdr with the standard input as the I/O source.
		r = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		// Initialize a new Scanner object named s with the rdr as the reader field.
		s = new Scanner(rdr);
		// Return the initialized Scanner object.
		return s;
	}

	// Next method reads the next token from the input, which can be a single word, number, or symbol.
	// It skips leading whitespaces and returns the result as a string.
	public String next() {
		// Set the current position p to the beginning of the buffer if it's at the end.
		pre();
		// Start index of the token in the buffer.
		int start = p;
		// Read the input until a non-whitespace character is found.
		for (; p < buf.length; p++) {
			// If the current character is a whitespace, break the loop.
			if (buf[p] == ' ') {
				break;
			}
		}
		// Read the token, including the whitespace character if any.
		String result = new String(buf, start, p - start);
		// Increment the current position p.
		p++;
		// Return the result.
		return result;
	}

	// NextLine method reads the next line from the input and returns it as a string.
	public String nextLine() {
		// Set the current position p to the beginning of the buffer if it's at the end.
		pre();
		// Start index of the line in the buffer.
		int start = p;
		// Read the input until the end of the line is reached.
		for (; p < buf.length; p++) {
			// If the current character is a newline character, break the loop.
			if (buf[p] == '\n') {
				break;
			}
		}
		// Read the line, including the newline character if any.
		String result = new String(buf, start, p - start);
		// Increment the current position p.
		p++;
		// Return the result.
		return result;
	}

	// NextInt method reads an integer from the input and returns it.
	public int nextInt() {
		// Read the next token as a string.
		String token = next();
		// Parse the token as an integer and return the result.
		int v = Integer.parseInt(token);
		// Return the result.
		return v;
	}

	// NextInt64 method reads a 64-bit integer from the input and returns it.
	public long nextInt64() {
		// Read the next token as a string.
		String token = next();
		// Parse the token as a 64-bit integer and return the result.
		long v = Long.parseLong(token);
		// Return the result.
		return v;
	}

	// NextFloat method reads a floating-point number from the input and returns it.
	public double nextFloat() {
		// Read the next token as a string.
		String token = next();
		// Parse the token as a floating-point number and return the result.
		double v = Double.parseDouble(token);
		// Return the result.
		return v;
	}

	// NextIntArray method reads an array of integers from the input and returns it.
	public int[] nextIntArray() {
		// Read the next line as a string.
		String line = nextLine();
		// Split the line into tokens using spaces as delimiters.
		String[] tokens = line.split(" ");
		// Parse each token as an integer and append it to the result slice.
		int[] result = new int[tokens.length];
		for (int i = 0; i < tokens.length; i++) {
			int v = Integer.parseInt(tokens[i]);
			result[i] = v;
		}
		// Return the result.
		return result;
	}

	// NextInt64Array method reads an array of 64-bit integers from the input and returns it.
	public long[] nextInt64Array() {
		// Read the next line as a string.
		String line = nextLine();
		// Split the line into tokens using spaces as delimiters.
		String[] tokens = line.split(" ");
		// Parse each token as a 64-bit integer and append it to the result slice.
		long[] result = new long[tokens.length];
		for (int i = 0; i < tokens.length; i++) {
			long v = Long.parseLong(tokens[i]);
			result[i] = v;
		}
		// Return the result.
		return result;
	}

	// NextMap method reads a map from the input and returns it.
	public Map<Integer, Boolean> nextMap() {
		// Read the next line as a string.
		String line = nextLine();
		// Split the line into tokens using spaces as delimiters.
		String[] tokens = line.split(" ");
		// Parse each token as an integer and create a key-value pair.
		Map<Integer, Boolean> mp = new HashMap<>();
		for (String token : tokens) {
			int key = Integer.parseInt(token.split(":")[0]);
			mp.put(key, true);
		}
		// Return the result.
		return mp;
	}

	// pre method sets the current position p to the beginning of the buffer if it's at the end.
	private void pre() {
		// If the current position p is at the end of the buffer, read the next line.
		if (p >= buf.length) {
			readLine();
			p = 0;
		}
	}

	// readLine method reads a line from the input and appends it to the buffer.
	private void readLine() {
		// Read a line from the input using the bufio.Reader.
		String line = r.readLine();
		// Remove the newline character from the line.
		line = line.trim();
		// Append the line to the buffer.
		buf = line.getBytes();
	}
}

// main function is the entry point of the program.
public class Main {
	// main function is the entry point of the program.
	public static void main(String[] args) {
		// Initialize a new Scanner object named sc.
		Scanner sc = new Scanner();
		// Read the height H, width W, and number of obstacles N from the standard input.
		int H = sc.nextInt();
		int W = sc.nextInt();
		int N = sc.nextInt();
		// Calculate the maximum dimension A between H and W.
		int A = Math.max(H, W);
		// Print the result, which is the number of rows or columns needed to place all obstacles without overlapping.
		System.out.println((N + A - 1) / A);
	}
}

