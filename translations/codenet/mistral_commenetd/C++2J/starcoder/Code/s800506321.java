
import java.util.*;
// Include the standard input/output library header file

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// Create a Scanner object to read input from the standard input stream

		int n, k, x, y, z;
		// Declare five integer variables: n, k, x, y, and z

		n = sc.nextInt();
		// Read the first integer (n) from the standard input stream and assign it to the variable n

		k = sc.nextInt();
		// Read the second integer (k) from the standard input stream and assign it to the variable k

		x = n/k;
		// Calculate the integer division of n by k and assign the result to the variable x

		y = n%k;
		// Calculate the remainder of n divided by k and assign the result to the variable y

		if(y!=0) {
			z = 1;
			// If the remainder y is non-zero, assign the value 1 to the variable z
		}
		else {
			z = 0;
			// If the remainder y is zero, assign the value 0 to the variable z
		}
		System.out.println(z);
		// Use the System.out.println() function to print the value of z to the standard output stream
	}
}
