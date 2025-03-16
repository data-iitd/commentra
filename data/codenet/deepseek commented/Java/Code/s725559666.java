
import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		// Create a Scanner object to read input from the user
		Scanner scan = new Scanner(System.in);
		
		// Read three integers from the user
		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();
		
		// Close the Scanner object to free up resources
		scan.close();
		
		// Check if a is less than b and b is less than c and a is less than c
		if(a < b && b < c && a < c) {
			// If the condition is true, print "Yes"
			System.out.println("Yes");
		} else {
			// If the condition is false, print "No"
			System.out.println("No");
		}
		

	}

}

