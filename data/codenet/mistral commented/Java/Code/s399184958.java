
import java.util.*; // We import the java.util.Scanner class to read input from the standard input stream.

class Main{
    public static void main( String[] args ) { // This is the entry point of the program.
	Scanner sc = new Scanner(System.in); // We create a new Scanner object to read input from the standard input stream.
	int A = sc.nextInt(); // We read the first integer from the standard input stream.
	int B = sc.nextInt(); // We read the second integer from the standard input stream.
	int C = sc.nextInt(); // We read the third integer from the standard input stream.

	if ( A == B && B == C && C == A ) { // We check if all three integers are equal to each other.
	    System.out.println("Yes"); // If all three integers are equal, we print the message "Yes" to the standard output stream.
	} else {
	    System.out.println("No"); // If the condition in the if statement is not met, we print the message "No" to the standard output stream.
	}
    }
}