
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare three integer variables to hold the input values
		int a, b, c;
		
		// Read three integers from the standard input and assign them to a, b, and c
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		
		// Check if c is between a and b (inclusive)
		if (c >= a && c <= b) {
			// If true, print "Yes"
			System.out.println("Yes");
		} else {
			// If false, print "No"
			System.out.println("No");
		}
	}
}

