import java.util.Scanner; // Import the Scanner class for input and output operations

public class Main { // The Main class is the entry point of the program
	public static void main(String[] args) { // The main function is the entry point of the program
		Scanner sc = new Scanner(System.in); // Create a Scanner object for input operations
		int a, b; // Declare two integer variables 'a' and 'b'
		char S;   // Declare a character variable 'S'

		// A while loop that runs indefinitely until the user enters '?' to exit
		while (true) {
			a = sc.nextInt(); // Read an integer 'a' from the standard input
			S = sc.next().charAt(0); // Read a character 'S' from the standard input
			b = sc.nextInt(); // Read an integer 'b' from the standard input

			// Perform arithmetic operations based on the operator 'S'
			if (S == '+') System.out.println(a + b); // If 'S' is '+', print the sum of 'a' and 'b'
			if (S == '-') System.out.println(a - b); // If 'S' is '-', print the difference of 'a' and 'b'
			if (S == '*') System.out.println(a * b); // If 'S' is '*', print the product of 'a' and 'b'
			if (S == '/') System.out.println(a / b); // If 'S' is '/', print the quotient of 'a' and 'b'
			if (S == '?') break; // If 'S' is '?', break out of the loop
		}
	}
}

