
import java.util.Scanner; // Importing the Scanner class for user input

public class Main {

	public static void main(String[] args) {
		// Creating a new Scanner object to read user input
		Scanner sc = new Scanner(System.in);

		// Reading the first line of user input as a long number
		long n = Long.parseLong(sc.nextLine());

		// Calculating the square root of the given number 'n'
		double sqrt = Math.sqrt(n);

		// Finding the nearest integer to the square root
		double nearNum = Math.floor(sqrt);

		// Calculating the square of the nearest integer
		long ans = (long) Math.pow(nearNum, 2);

		// Printing the result to the console
		System.out.println(ans);

		// Closing the Scanner object to free system resources
		sc.close();
	}
}