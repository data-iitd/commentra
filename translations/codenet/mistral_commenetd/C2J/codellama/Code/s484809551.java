
// Define constants
public static final int N_MAX = 100;
public static final int P_MAX = 100;
public static final int DP_ARRAY_SIZE = N_MAX * P_MAX / 32 + 1;

// Define helper functions
public static int min(int a, int b) {
	return a < b ? a : b;
}

public static int max(int a, int b) {
	return a > b ? a : b;
}

public static int abs(int a) {
	return a < 0 ? -a : a;
}

public static int abss(int a, int b) {
	return a > b ? a - b : b - a;
}

// Function to find the last occurrence of a substring in a string
public static String strrstr(String string, String pattern) {
	int offset = 0;
	String lastP = null;

	String searchResult = null;
	while ((searchResult = string.substring(offset).indexOf(pattern)) != -1 && string.charAt(offset) != '\0') {
		lastP = searchResult;
		offset++;
	}

	return lastP;
}

// Function to compare two integers for qsort
public static int compare_f(int a, int b) {
	return a < b ? -1 : 1;
}

// Function to calculate the number of combinations of n items taken r at a time
public static int comb(int n, int r) {
	int result = 1;

	for (int i = 0; i < r; i++) {
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

// Function to find the greatest common divisor of two numbers
public static long gcd(long m, long n)
{
	long temp;

	while (m%n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}

	return n;
}

public static void main(String[] args) {
	// Define pattern base string
	String patternBase = "keyence";
	String top = new String();
	String bottom = new String();
	String S = new String();

	// Read input string from standard input
	Scanner sc = new Scanner(System.in);
	S = sc.nextLine();

	// Calculate length of input string
	int len = S.length();
	boolean found = false;

	// Loop through each character in pattern base string
	for (int offset = 0; offset < patternBase.length(); offset++) {
		// Copy substring up to current character to top variable
		top = patternBase.substring(0, offset);

		// Copy substring from current character to end of pattern base string to bottom variable
		bottom = patternBase.substring(offset);

		// Search for top substring in input string
		int topSearch = S.indexOf(top);

		// If top substring is found
		if (topSearch != -1) {
			// Search for bottom substring after top substring in input string
			int bottomSearch = S.indexOf(bottom, topSearch + offset);

			// If bottom substring is found
			if (bottomSearch != -1) {
				// Calculate number of separators between top and bottom substrings
				int sepCount = 0;

				// If topSearch is not the first occurrence of top substring in input string
				if (topSearch != 0) {
					sepCount++;
				}

				// If topSearch is not the same as bottomSearch
				if (topSearch + offset != bottomSearch) {
					sepCount++;
				}

				// If bottomSearch is not the last character in input string
				if (bottomSearch + bottom.length() != S.length()) {
					sepCount++;
				}

				// If number of separators is less than or equal to 1
				if (sepCount <= 1) {
					found = true;
					break;
				}
			}
		}
	}

	// Print output based on whether pattern is found or not
	System.out.println((found ? "YES" : "NO"));

	// Close scanner
	sc.close();
}

