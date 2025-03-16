import java.util.Scanner;
// Import the necessary class Scanner from the java.util package.
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// Create a new Scanner object sc that takes input from the user.
		int x = sc.nextInt();
		// Use the nextInt() method of the Scanner class to take an integer input from the user and assign it to the variable x.
		System.out.println(x*x*x);
		// Use the println() method of the System class to display the result of the computation x*x*x on the console.
	}
}
