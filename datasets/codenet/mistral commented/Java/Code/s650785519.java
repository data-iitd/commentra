
import java.util.Scanner; // Importing the Scanner class

public class Main {
	public static void main(String[] args) throws Exception {
		// Creating a new Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);

		// Reading an integer value from the user
		int x = sc.nextInt();

		// Closing the Scanner object to free up system resources
		sc.close();

		// Calculating the answer
		int ans = (2199 - x) / 200;

		// Printing the answer to the console
		System.out.println(ans);
	}
}