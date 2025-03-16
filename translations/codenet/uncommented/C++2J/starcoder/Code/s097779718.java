import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long A = in.nextLong();
		long B = in.nextLong();

		System.out.println((A*B) / Euclid(A, B));
	}

	public static long Euclid(long x, long y) {
		long tmp;

		if (x < y) {
			tmp = x;
			x = y;
			y = tmp;
		}

		if (!(x%y)) return y;
		return Euclid(y, x%y);
	}
}

