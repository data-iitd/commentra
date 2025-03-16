// Importing required packages
import java.util.*;
import java.io.*;

// Define a custom class 'Block'
class Block {
	String value;
	int len;

	// Constructor
	Block(String value, int len) {
		this.value = value;
		this.len = len;
	}
}

// Main class
public class Main {
	// Main function starts the execution
	public static void main(String[] args) {
		// Initialize variables
		int N, K, ans = 0;

		// Read input values for N and K from the standard input
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();

		// Initialize a buffer scanner for reading input from the standard input
		Scanner s = new Scanner(System.in);
		s.useDelimiter("");

		// Allocate a byte slice of size 1,000,000 for reading input
		byte[] b = new byte[1000000];

		// Set the buffer size for the buffer scanner
		s.next(b);

		// Read the input string S from the standard input
		String S = s.next();

		// Call the RunLength function to get the run-length encoded blocks
		Block[] blocks = RunLength(S);

		// Initialize variables sum, zero and length l
		int sum = 0, zero = 0, l = 0;

		// Loop through all the blocks in the blocks slice
		for (int r = 0; r < blocks.length; r++) {
			// Increment the sum by the length of the current block
			sum += blocks[r].len;

			// If the current block's value is '0', increment the zero counter
			if (blocks[r].value.equals("0")) {
				zero++;
			}

			// While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
			while (K < zero) {
				sum -= blocks[l].len;
				if (blocks[l].value.equals("0")) {
					zero--;
				}
				l++;
			}

			// Update the answer with the maximum of the current answer and the sum
			ans = Math.max(ans, sum);
		}

		// Print the final answer
		System.out.println(ans);
	}

	// RunLength function to get the run-length encoded blocks
	public static Block[] RunLength(String s) {
		// If the length of the input string is zero, return an empty slice
		if (s.length() == 0) {
			return new Block[0];
		}

		// Initialize the first block with the first character and length one
		Block t = new Block(s.substring(0, 1), 1);

		// Initialize an empty slice to store the blocks
		Block[] r = new Block[0];

		// Loop through all the characters in the input string starting from the second character
		for (int i = 1; i < s.length(); i++) {
			// If the current character is the same as the previous character, increment the length of the current block
			if (t.value.equals(s.substring(i, i + 1))) {
				t.len++;
			} else {
				// Add the previous block to the result slice
				r = Arrays.copyOf(r, r.length + 1);
				r[r.length - 1] = t;

				// Initialize a new block with the current character and length one
				t = new Block(s.substring(i, i + 1), 1);
			}
		}

		// Add the last block to the result slice
		r = Arrays.copyOf(r, r.length + 1);
		r[r.length - 1] = t;

		// Return the result slice
		return r;
	}
}

// End of the code

