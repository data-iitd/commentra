
import java.util.Scanner;

public class s097779718{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		long A = scanner.nextLong();
		long B = scanner.nextLong();
		scanner.close();

		// Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
		long Euclid(long x, long y) {
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

		// Calculate and output the least common multiple (LCM) of A and B
		System.out.println((A * B) / Euclid(A, B));
	}
}

