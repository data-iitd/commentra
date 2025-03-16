
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
	
		// Create a new Scanner object to read input from the standard input stream
		Scanner stdIn = new Scanner(System.in);
	
		// Read a short integer value from the input and store it in the variable r
		short r = stdIn.nextShort();
	
		// Check if the value of r is less than 1200. If true, print "ABC" and return from the main method.
		if (r < 1200) {
			System.out.println("ABC");
			return;
		}
	
		// If the condition in the previous if statement is false, check if the value of r is less than 2800.
		// If true, print "ARC" and return from the main method.
		if (r < 2800) {
			System.out.println("ARC");
			return;
		}
	
		// If both conditions in the previous if statements are false, print "AGC".
		System.out.println("AGC");
	
	}

}

