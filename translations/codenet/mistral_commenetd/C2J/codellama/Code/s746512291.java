// Include the standard input/output library
import java.util.Scanner;

public class Main {
	// Function main is the starting point of the program
	public static void main(String[] args) {
		// Declare an integer variable x
		int x;
		// Read an integer value from the standard input and store it in variable x
		Scanner sc = new Scanner(System.in);
		x = sc.nextInt();
		// Print the result of x cubed to the standard output
		System.out.println(x*x*x);
	}
}
