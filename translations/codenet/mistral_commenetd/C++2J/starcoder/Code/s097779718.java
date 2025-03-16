import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long A = in.nextLong();
		long B = in.nextLong();
		System.out.println((A*B) / Euclid(A, B));
	}

	// Function to find the greatest common divisor (GCD) of two numbers using Euclid's algorithm
	public static long Euclid(long x, long y) {
		long tmp; // Variable to store the temporary value

		// Swap x and y if x is smaller than y
		if (x < y) {
			tmp = x;
			x = y;
			y = tmp;
		}

		// If x is divisible by y, return y as the GCD
		if (!(x%y)) return y;

		// Recursively call Euclid function with y and the remainder of x divided by y
		return Euclid(y, x%y);
	}
}
