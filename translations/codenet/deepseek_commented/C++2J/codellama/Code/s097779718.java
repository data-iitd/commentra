import java.util.Scanner;

public class Euclid {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long long A = sc.nextLong();
		long long B = sc.nextLong();
		long long tmp;

		// Ensure x is greater than y
		if (A < B) {
			tmp = A;
			A = B;
			B = tmp;
		}

		// Base case: if x is divisible by y, return y
		if (A % B == 0) return B;

		// Recursive case: apply the Euclidean algorithm
		return Euclid(B, A % B);
	}
}

