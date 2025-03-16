
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		// Define pattern base string
		String patternBase = "keyence";
		String top = "", bottom = "";
		String S = in.next();

		// Calculate length of input string
		int len = S.length();
		boolean found = false;

		// Loop through each character in pattern base string
		for (int offset = 0; offset < patternBase.length(); offset++) {
			// Copy substring up to current character to top variable
			top = patternBase.substring(0, offset);

			// Copy substring from current character to end of pattern base string to bottom variable
			bottom = patternBase.substring(offset, patternBase.length());

			// Search for top substring in input string
			int topSearch = S.indexOf(top);

			// If top substring is found
			if (topSearch!= -1) {
				// Search for bottom substring after top substring in input string
				int bottomSearch = S.lastIndexOf(bottom);

				// If bottom substring is found
				if (bottomSearch!= -1) {
					// Calculate number of separators between top and bottom substrings
					int sepCount = 0;

					// If topSearch is not the first occurrence of top substring in input string
					if (topSearch!= 0) {
						sepCount++;
					}

					// If topSearch is not the same as bottomSearch
					if (topSearch!= bottomSearch) {
						sepCount++;
					}

					// If bottomSearch is not the last character in input string
					if (bottomSearch + bottom.length()!= len) {
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
		System.out.println((found? "YES" : "NO"));
	}
}

