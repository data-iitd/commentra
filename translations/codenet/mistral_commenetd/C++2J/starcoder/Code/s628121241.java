
import java.util.*;

public class Main {
	public static void main(String[] args) {
		// Declare and read the value of 'R' from the standard input
		Scanner sc = new Scanner(System.in);
		int R = sc.nextInt();

		// Check the value of 'R' and print the corresponding output
		if (R < 1200) {
			System.out.println("ABC"); // Output: "ABC" if 'R' is less than 1200
		}
		else if (R >= 2800) {
			System.out.println("AGC"); // Output: "AGC" if 'R' is greater than or equal to 2800
		}
		else {
			System.out.println("ARC"); // Output: "ARC" if 'R' is between 1200 and 2800 (inclusive)
		}
	}
}

