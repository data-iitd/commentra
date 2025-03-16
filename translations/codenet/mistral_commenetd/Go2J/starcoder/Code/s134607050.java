
import java.util.*;

public class Main {

	// Function to search the range of 'R' and 'L' in the given text
	// S....M....E
	// R...RL...LR
	public static int[] searchRange(String text, int start, int limit) {
		int middle = -1; // Initialize middle to -1

		for (int i = start; i < limit; i++) {
			if (text.charAt(i)!= 'R') { // Check if current character is not 'R'
				middle = i; // If not, then set middle to current index
				break; // and break the loop
			}
		}

		int end = limit; // Initialize end to limit

		for (int i = middle; i < limit; i++) {
			if (text.charAt(i)!= 'L') { // Check if current character is not 'L'
				end = i; // If not, then set end to current index
				break; // and break the loop
			}
		}

		return new int[] {start, middle, end}; // Return start, middle and end indices
	}

	// Function to print the answer
	public static void answer() {
		Scanner sc = new Scanner(System.in);
		String text = sc.next(); // Read text from standard input
		int limit = text.length(); // Get length of text

		int start = 0; // Initialize start index to 0
		int middle = 0; // Initialize middle index to 0
		int end = 0; // Initialize end index to 0
		boolean firstPrinted = false; // Initialize firstPrinted to false

		for (end = 0; end < limit; end++) { // Loop until end is less than limit
			int[] indices = searchRange(text, start, limit); // Call searchRange function to find the range of 'R' and 'L'

			int len1 = indices[1] - indices[0]; // Calculate length of first substring
			int len2 = indices[2] - indices[1]; // Calculate length of second substring

			// Print the first substring
			for (int i = indices[0]; i < indices[1] - 1; i++) {
				if (firstPrinted) { // Check if firstPrinted is true
					System.out.print(" "); // Print a space if true
				}
				System.out.print("0"); // Print '0' for each character in the first substring
				firstPrinted = true; // Set firstPrinted to true
			}

			// Print the count of 'R' and 'L' in the first and second substrings
			if (firstPrinted) { // Check if firstPrinted is true
				System.out.print(" "); // Print a space if true
			}
			System.out.printf("%v %v", len1 / 2 + len2 / 2, len1 / 2 + (len2 + 1) / 2); // Print the count of 'R' and 'L' in the first and second substrings
			firstPrinted = true; // Set firstPrinted to true

			// Print the second substring
			for (int i = indices[1] + 1; i < indices[2]; i++) {
				if (firstPrinted) { // Check if firstPrinted is true
					System.out.print(" "); // Print a space if true
				}
				System.out.print("0"); // Print '0' for each character in the second substring
				firstPrinted = true; // Set firstPrinted to true
			}
			start = end; // Set start to end
			firstPrinted = true; // Set firstPrinted to true
		}
		System.out.println(); // Print newline at the end
	}

	// Main function to call answer function
	public static void main(String[] args) {
		answer(); // Call answer function
	}

}

