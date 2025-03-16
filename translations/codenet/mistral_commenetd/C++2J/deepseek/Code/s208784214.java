import java.util.Scanner; // Import the Scanner class to read input

public class Main {
	// Define two integer variables: N and A
	static int N, A;

	public static void main(String[] args) {
		// Create a Scanner object to read input from the standard input stream
		Scanner scanner = new Scanner(System.in);

		// Read the values of N and A from the standard input
		N = scanner.nextInt();
		A = scanner.nextInt();

		// Use the conditional operator to check if the remainder of N divided by 500 is less than or equal to A
		System.out.println(N % 500 <= A ? "Yes" : "No");

		// Close the Scanner object to free up resources
		scanner.close();
	}
}
