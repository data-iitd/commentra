
import java.math.*;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize variables for storing BigInteger numbers
		BigInteger a, b, c;

		// Create a Scanner object for reading input from the console
		Scanner cin = new Scanner(System.in);

		// Start an infinite loop to read input numbers until the console is empty
		while(cin.hasNext()) {
			// Read the first number from the console
			a = cin.nextBigInteger();
			// Add a comment explaining what this line does
			// Read the second number from the console
			b = cin.nextBigInteger();

			// Find the greater number between 'a' and 'b' and store it in 'c'
			c = a.max(b);

			// Determine the relationship between 'a' and 'b' based on the greater number 'c'
			if(a.equals(c)&&!b.equals(c)) {
				// If 'a' is equal to the greater number 'c' and 'b' is not, print "GREATER"
				System.out.println("GREATER");
			} else if(b.equals(c)&&!a.equals(c)) {
				// If 'b' is equal to the greater number 'c' and 'a' is not, print "LESS"
				System.out.println("LESS");
			} else {
				// If both 'a' and 'b' are equal to the greater number 'c', print "EQUAL"
				System.out.println("EQUAL");
			}
		}

		// Close the Scanner object to release the console resources
		cin.close();
	}

}

