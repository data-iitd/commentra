import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare variables K and X to hold input values
		int K, X;
		
		// Read two integers from standard input
		Scanner sc = new Scanner(System.in);
		K = sc.nextInt();
		X = sc.nextInt();
		
		// Check if 500 times K is greater than or equal to X
		if (500*K >= X) {
			// If the condition is true, print "Yes"
			System.out.println("Yes");
		} else {
			// If the condition is false, print "No"
			System.out.println("No");
		}
	}
}
