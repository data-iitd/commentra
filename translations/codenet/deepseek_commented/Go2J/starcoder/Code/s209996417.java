
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double n = sc.nextDouble();
		double k = sc.nextDouble();
		sc.close();

		// Read two floating-point numbers, n and k, from standard input.
		// These represent the number to be converted and the base of the number system, respectively.

		// Calculate the number of digits in the base k representation of n.
		// The logic involves finding the smallest integer x such that k^x is less than or equal to n and n is less than k^(x+1).
		// Output x + 1 as the number of digits in the base k representation of n.

		double x = 0.0;
		while (true) {
			double under = Math.pow(k, x);
			double upper = Math.pow(k, x + 1);

			if (under <= n && n < upper) {
				System.out.println(x + 1);
				return;
			}
			x++;
		}
	}
}

