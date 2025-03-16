import java.util.Scanner; // Importing the Scanner class from the java.util package

public class Main {
	public static void main(String args[]) { // Main method declaration with String[] arguments and void return type

		// Creating a new Scanner object to read input from the standard input stream (System.in)
		Scanner sc = new Scanner(System.in);
		int intA; // Declaring an integer variable named intA

		// Reading an integer value from the user input using the Scanner object
		intA = sc.nextInt();

		// Calculating the cube of the integer value read from the user input using the Math.pow() method
		double dbAncer = Math.pow(intA, 3);

		// Casting the double value obtained from the cube calculation to an integer value
		int intAncer = (int)dbAncer;

		// Printing the integer value obtained from the cube calculation to the standard output stream (System.out)
		System.out.println(intAncer);
	}
}
