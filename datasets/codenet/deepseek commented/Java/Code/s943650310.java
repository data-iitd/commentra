
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Initialize Scanner to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read the amount of money (X) and the amount already spent (t)
		int X = sc.nextInt();
		int t = sc.nextInt();
		
		// Check if there is any remaining money
		if(X - t >= 0) {
			// Print the remaining money
			System.out.println(X - t);
		} else {
			// Print 0 if there is no remaining money
			System.out.println(0);
		}
	}
}

