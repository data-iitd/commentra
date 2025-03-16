
import java.util.Scanner;

public class s097779718{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		sc.close();

		long tmp;

		if (A < B) {
			tmp = A;
			A = B;
			B = tmp;
		}

		if (!(A%B)) System.out.println(B);
		else System.out.println(Euclid(B, A%B));
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
