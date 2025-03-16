// I/O
import java.util.Scanner;

// NewScanner initializes a new Scanner struct with a Scanner and sets its properties
public class NewScanner {
	private Scanner sc;

	public NewScanner() {
		sc = new Scanner(System.in); // Create a new Scanner from System.in
		sc.useDelimiter("[^\\p{L}]+"); // Set the scanner to split input into words
	}

	// (s *Scanner) nextStr reads a single word as a string from the input
	public String nextStr() {
		return sc.next();
	}

	// (s *Scanner) nextInt reads a single integer from the input
	public int nextInt() {
		return Integer.parseInt(sc.next());
	}

	// (s *Scanner) nextFloat reads a single floating-point number from the input
	public float nextFloat() {
		return Float.parseFloat(sc.next());
	}

	// (s *Scanner) nextRuneSlice reads a slice of runes from the input
	public char[] nextRuneSlice() {
		return sc.next().toCharArray();
	}

	// (s *Scanner) nextIntSlice reads a slice of integers from the input with a given length
	public int[] nextIntSlice(int n) {
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = s.nextInt();
		}
		return res;
	}

	// (s *Scanner) nextFloatSlice reads a slice of floating-point numbers from the input with a given length
	public float[] nextFloatSlice(int n) {
		float[] res = new float[n];
		for (int i = 0; i < n; i++) {
			res[i] = s.nextFloat();
		}
		return res;
	}
}

// Arithmetic
public int max(int... nums) {
	int m = nums[0]; // Initialize the maximum value with the first number
	for (int i : nums) { // Iterate through the rest of the numbers
		if (m < i) { // If the current number is greater than the maximum value
			m = i; // Update the maximum value
		}
	}
	return m; // Return the maximum value
}

public int min(int... nums) {
	int m = nums[0]; // Initialize the minimum value with the first number
	for (int i : nums) { // Iterate through the rest of the numbers
		if (m > i) { // If the current number is smaller than the minimum value
			m = i; // Update the minimum value
		}
	}
	return m; // Return the minimum value
}

public int abs(int x) {
	if (x > 0) { // If the number is positive
		return x; // Return the number as is
	}
	return -x; // If the number is negative, return its negation
}

public int pow(int x, int y) {
	int res = 1; // Initialize the result to 1
	for (int i = 0; i < y; i++) { // Iterate y times
		res *= x; // Multiply the result by x
	}
	return res; // Return the result
}

// Sort
class Val {
	int id, num;
}

// ByNum is a type alias for a slice of Val structs, used for sorting
class ByNum implements Comparator<Val> {
	public int compare(Val a, Val b) {
		return a.num - b.num;
	}
}

// Main function
public class Main {
	public static void main(String[] args) {
		NewScanner sc = new NewScanner(); // Initialize a new Scanner
		BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out)); // Initialize a new BufferedWriter for output

		// Read input values
		int A = sc.nextInt(), B = sc.nextInt(), C = sc.nextInt(), K = sc.nextInt();

		// Find the maximum value among A, B, and C
		int ma = max(A, B, C);

		// Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
		int rest = 0;
		if (ma == A) {
			rest += B + C;
		} else if (ma == B) {
			rest += A + C;
		} else {
			rest += A + B;
		}

		// Calculate the final answer
		int answer = pow(ma, K) + rest;

		// Write the answer to the output
		try {
			wtr.write(Integer.toString(answer));
			wtr.newLine();
			wtr.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

// 