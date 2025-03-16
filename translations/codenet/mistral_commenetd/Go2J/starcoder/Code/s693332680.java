// Importing necessary packages
import java.util.*;

// Declaring variables
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x, a, b;

		// Reading input values from standard input
		x = sc.nextInt();
		a = sc.nextInt();
		b = sc.nextInt();

		// Logic block to check if b is less than or equal to a
		if (b-a <= 0) {
			System.out.println("delicious");
		} else if (b-a <= x) {
			System.out.println("safe");
		} else {
			System.out.println("dangerous");
		}
	}
}

// End of code

