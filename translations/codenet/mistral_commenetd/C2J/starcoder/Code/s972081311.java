import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, sum;

		n = sc.nextInt();
		// Read an integer value from the user and store it in the variable n

		sum = (n*(n+1))/2;
		// Calculate the sum of the first n natural numbers
		// The formula for the sum of the first n natural numbers is n*(n+1)/2

		System.out.println(sum);
		// Print the calculated sum to the standard output
	}
}
