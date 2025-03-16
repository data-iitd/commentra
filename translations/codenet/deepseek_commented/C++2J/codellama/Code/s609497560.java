import java.util.Scanner; // Import the Scanner class for input operations

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a new Scanner object for input operations
		int a = sc.nextInt(); // Read an integer value from the user and store it in 'a'
		System.out.println(a + (a * a) + (a * a * a)); // Calculate and print the sum of 'a', 'a^2', and 'a^3'
	}
}

