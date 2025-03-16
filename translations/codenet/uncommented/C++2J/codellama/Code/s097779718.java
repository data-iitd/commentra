import java.util.Scanner;

public class Euclid {
	public static long gcd(long x, long y) {
		long tmp;

		if (x < y) {
			tmp = x;
			x = y;
			y = tmp;
		}

		if (x % y == 0) return y;
		return gcd(y, x % y);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();

		System.out.println((A*B) / gcd(A, B));
	}
}

