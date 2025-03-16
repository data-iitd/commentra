
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize a Scanner object to read input from the standard input stream
		Scanner sc = new Scanner(System.in);

		// Declare and initialize four integer variables by reading their values from the standard input stream
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();

		// Check if the product of a and b is greater than or equal to the product of c and d
		if(a*b >= c*d) {
			// If the condition is true, print the product of a and b
			System.out.println(a*b);
		}else if(a*b <= c*d) { // If the condition is false, check the next condition
			// If the second condition is true, print the product of c and d
			System.out.println(c*d);
		}
	}
}