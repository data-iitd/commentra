
import java.util.*; // Importing the Util package for using Scanner class
import java.math.*; // Importing the Math package for using BigDecimal class

public class Main {
	public static void main(String args[]) {
		// Creating a Scanner object to read input from the standard input stream
		Scanner sc = new Scanner(System.in);

		// Reading two strings `sa` and `sb` from the user input
		String sa = sc.next();
		String sb = sc.next();

		// Creating two BigDecimal objects `A` and `B` by converting the strings `sa` and `sb` to their decimal representation
		BigDecimal A = new BigDecimal(sa);
		BigDecimal B = new BigDecimal(sb);

		// Multiplying `A` and `B` and printing the product to the standard output stream after rounding it down to the nearest integer
		System.out.println(A.multiply(B).setScale(0, BigDecimal.ROUND_DOWN));
	}
}