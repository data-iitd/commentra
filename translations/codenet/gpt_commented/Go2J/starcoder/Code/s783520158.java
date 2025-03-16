import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare three integer variables to hold the input values
		int a, b, c;
		
		// Read three integers from standard input
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		
		// Check if the difference between the first two numbers is equal to the difference between the last two numbers
		if (b-a == c-b) {
			// If the differences are equal, print "YES"
			System.out.println("YES");
		} else {
			// If the differences are not equal, print "NO"
			System.out.println("NO");
		}
	}
}
