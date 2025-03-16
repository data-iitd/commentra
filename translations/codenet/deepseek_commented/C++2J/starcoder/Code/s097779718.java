import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long A = in.nextLong();
		long B = in.nextLong();
		System.out.println((A * B) / Euclid(A, B));
	}

	// Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
	public static long Euclid(long x, long y) {
		long tmp;

		// Ensure x is greater than y
		if (x < y) {
			tmp = x;
			x = y;
			y = tmp;
		}

		// Base case: if x is divisible by y, return y
		if (!(x % y)) return y;

		// Recursive case: apply the Euclidean algorithm
		return Euclid(y, x % y);
	}
}

