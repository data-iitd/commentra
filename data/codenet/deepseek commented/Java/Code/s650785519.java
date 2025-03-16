
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		// Create a Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read an integer input from the user and store it in the variable x
		int x = sc.nextInt();
		
		// Close the Scanner object to release resources
		sc.close();

		// Perform a calculation to determine the value of ans
		int ans = (2199 - x) / 200;
		
		// Print the result of the calculation to the console
		System.out.println(ans);
	}
}

