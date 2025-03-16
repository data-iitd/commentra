
// main function is the entry point of our program
public static void main(String[] args) {
	// Initialize a new FastScanner object called fsc
	FastScanner fsc = new FastScanner();

	// Read the first three integers A, B, and C from the standard input
	int A = fsc.nextInt();
	int B = fsc.nextInt();
	int C = fsc.nextInt();

	// Check if the difference between B and A is equal to the difference between C and B
	if (B - A == C - B) {
		// If it is, print "YES"
		System.out.println("YES");
	} else {
		// Otherwise, print "NO"
		System.out.println("NO");
	}
}

// FastScanner class and methods for reading input efficiently
class FastScanner {
	// Initialize a new BufferedReader object called r
	BufferedReader r;
	// Initialize a new String object called buf
	String buf;
	// Initialize an integer variable called p
	int p;

	// Constructor for the FastScanner class
	public FastScanner() {
		// Initialize a new BufferedReader with a buffer size of 1024 bytes
		r = new BufferedReader(new InputStreamReader(System.in), 1024);
	}

	// Method for reading the next string token
	public String next() {
		// Preprocess the input buffer if necessary
		pre();

		// Find the start index of the next token
		int start = p;
		// Find the end index of the next token (space or newline character)
		while (p < buf.length()) {
			if (buf.charAt(p) == ' ') {
				break;
			}
			p++;
		}

		// Return the substring of the input buffer from the start index to the current position
		String result = buf.substring(start, p);
		// Move the position index to the next character
		p++;

		// Return the result
		return result;
	}

	// Method for reading the next line
	public String nextLine() {
		// Preprocess the input buffer if necessary
		pre();

		// Find the start index of the next line
		int start = p;
		// Read the rest of the line into the buffer
		p = buf.length();

		// Return the substring of the input buffer from the start index to the end of the line
		return buf.substring(start);
	}

	// Method for reading the next integer
	public int nextInt() {
		// Read a string token as an integer
		String token = next();
		// Convert the string token to an integer and return it
		return Integer.parseInt(token);
	}

	// Method for preprocessing the input buffer
	public void pre() {
		// If the position index is at the end of the buffer, read a new line
		if (p >= buf.length()) {
			readLine();
			p = 0;
		}
	}

	// Method for reading a new line into the buffer
	public void readLine() {
		// Read a line from the input buffer into a temporary string
		String line = "";
		try {
			line = r.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		// Copy the temporary string to the FastScanner's buffer
		buf = line;
	}
}

// Helper functions for finding the maximum and minimum values
public static int intMax(int a, int b) {
	// Return the larger of the two integers
	if (a < b) {
		return b;
	}
	return a;
}

public static long int64Max(long a, long b) {
	// Return the larger of the two integers
	if (a < b) {
		return b;
	}
	return a;
}

public static double float64Max(double a, double b) {
	// Return the larger of the two floating-point numbers
	if (a < b) {
		return b;
	}
	return a;
}

public static int intMin(int a, int b) {
	// Return the smaller of the two integers
	if (a > b) {
		return b;
	}
	return a;
}

public static long int64Min(long a, long b) {
	// Return the smaller of the two integers
	if (a > b) {
		return b;
	}
	return a;
}

public static double float64Min(double a, double b) {
	// Return the smaller of the two floating-point numbers
	if (a > b) {
		return b;
	}
	return a;
}

// Helper function for finding the greatest common divisor of two integers
public static int intGcd(int a, int b) {
	// If b is 0, return a as the GCD
	if (b == 0) {
		return a;
	}

	// Recursively call intGcd with b and the remainder of a divided by b
	return intGcd(b, a % b);
}

public static long int64Gcd(long a, long b) {
	// If b is 0, return a as the GCD
	if (b == 0) {
		return a;
	}

	// Recursively call int64Gcd with b and the remainder of a divided by b
	return int64Gcd(b, a % b);
}

// Helper function for finding the absolute value of an integer
public static int intAbs(int a) {
	// If a is negative, return the negative of a
	if (a < 0) {
		return -a;
	}
	// Otherwise, return a as is
	return a;
}

public static long int64Abs(long a) {
	// If a is negative, return the negative of a
	if (a < 0) {
		return -a;
	}
	// Otherwise, return a as is
	return a;
}

