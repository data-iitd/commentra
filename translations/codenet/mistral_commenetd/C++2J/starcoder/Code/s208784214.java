
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Read the values of N and A from the standard input
		int N = sc.nextInt();
		int A = sc.nextInt();

		// Use the conditional operator to check if the remainder of N divided by 500 is less than or equal to A
		System.out.println((N % 500 <= A? "Yes" : "No"));

		// End the main function and return 0 to indicate successful execution
		return 0;
	}
}

