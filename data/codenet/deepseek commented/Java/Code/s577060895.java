import java.util.Scanner; // Importing Scanner class for input

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Initializing Scanner object to read input
		long n = Long.parseLong(sc.nextLine()); // Reading a long integer n from the user

		double sqrt = Math.sqrt(n); // Calculating the square root of n
		double nearNum = Math.floor(sqrt); // Finding the nearest integer to the square root

		long ans = (long) Math.pow(nearNum, 2); // Calculating the closest perfect square

		System.out.println(ans); // Printing the result

		sc.close(); // Closing the Scanner object to free up resources
	}
}
