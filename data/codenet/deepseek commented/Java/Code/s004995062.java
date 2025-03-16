import java.util.*; // Importing the utility library for general utilities
import java.math.*; // Importing the math library for mathematical operations

public class Main {
	public static void main(String args[]) { // Main method, the entry point of the program
		Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
		String sa = sc.next(); // Reading the first input string
		String sb = sc.next(); // Reading the second input string
		BigDecimal A = new BigDecimal(sa); // Converting the first string to a BigDecimal
		BigDecimal B = new BigDecimal(sb); // Converting the second string to a BigDecimal
		System.out.println(A.multiply(B).setScale(0, BigDecimal.ROUND_DOWN)); // Multiplying A and B, setting scale to 0, and rounding down
	}
}
