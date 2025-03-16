
// Define constants for maximum sizes and array size for dynamic programming
final int N_MAX = 100;
final int P_MAX = 100;
final int DP_ARRAY_SIZE = (N_MAX * P_MAX / 32 + 1);

// Define macros for common operations
final int MIN(int a, int b) { return (a < b? a : b); }
final int MAX(int a, int b) { return (a > b? a : b); }
final int ABS(int a) { return (a < 0? -a : a); }
final int ABSS(int a, int b) { return (a > b? a - b : b - a); }

// Function to find the last occurrence of a substring within a string
static String strrstr(String string, String pattern) {
	int offset = 0;
	String lastP = null;

	String searchResult = null;
	// Loop to find the last occurrence of the pattern
	while ((searchResult = string.indexOf(pattern, offset))!= -1 && string.charAt(offset)!= '\0') {
		lastP = searchResult; // Update last found position
		offset++; // Move offset to search for further occurrences
	}

	return lastP; // Return the last found position
}

// Comparison function for qsort, comparing two size_t values
static int compare_f(final long a, final long b) {
	return (a < b? -1 : 1); // Return comparison result
}

// Function to calculate combinations C(n, r)
static long comb(final long n, final long r) {
	long result = 1;

	// Calculate the combination using the formula
	for (long i = 0; i < r; i++) {
		result *= n - i; // Multiply by decreasing values of n
		result /= i + 1; // Divide by increasing values of r
	}

	return result; // Return the result
}

// Function to compute the greatest common divisor (GCD) of two numbers
static long gcd(long m, long n) {
	long temp;

	// Euclidean algorithm to find GCD
	while (m % n!= 0) {
		temp = n;
		n = m % n; // Update n to the remainder
		m = temp; // Update m to the previous n
	}

	return n; // Return the GCD
}

// Main function to execute the program
public static void main(String[] args) {
	final String patternBase = "keyence"; // Define the pattern to search for
	String top = new String(new char[8]); // Buffers to hold split parts of the pattern
	String bottom = new String(new char[8]);
	String S = new String(new char[101]); // Buffer to hold the input string

	// Read the input string
	System.out.print("Enter the string: ");
	System.out.flush();
	System.in.read(S);

	final int len = S.length(); // Get the length of the input string
	boolean found = false; // Flag to indicate if the pattern is found

	// Loop through each possible split point in the pattern
	for (int offset = 0; offset < patternBase.length(); offset++) {
		// Split the pattern into top and bottom parts
		top.getChars(0, offset, patternBase, 0);
		top.setCharAt(offset, '\0'); // Null-terminate the top part
		bottom.getChars(0, patternBase.length() - offset, patternBase, offset);
		bottom.setCharAt(patternBase.length() - offset, '\0'); // Null-terminate the bottom part

		// Search for the top part in the input string
		final int topSearch = S.indexOf(top);
		if (topSearch!= -1) {
			// Search for the bottom part after the found top part
			final int bottomSearch = strrstr(S.substring(topSearch), bottom);
			if (bottomSearch!= -1) {
				int sepCount = 0; // Counter for separators

				// Count the number of separators between top and bottom parts
				if (topSearch!= 0) {
					sepCount++; // Increment if there's text before the top part
				}
				if (topSearch + offset!= bottomSearch) {
					sepCount++; // Increment if there's text between top and bottom parts
				}
				if (bottomSearch + bottom.length()!= S.length()) {
					sepCount++; // Increment if there's text after the bottom part
				}

				// Check if the number of separators is less than or equal to 1
				if (sepCount <= 1) {
					found = true; // Set found flag to true
					break; // Exit the loop as the pattern is found
				}
			}
		}
	}

	// Output the result based on whether the pattern was found
	System.out.println((found? "YES" : "NO"));
}

