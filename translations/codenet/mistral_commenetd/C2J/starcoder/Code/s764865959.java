import java.util.Scanner; // Importing the Scanner class from the Java util package

public class Main{ // Defining the main class
	public static void main(String[] args){ // Defining the main method
		Scanner sc = new Scanner(System.in); // Creating a Scanner object named sc and initialising it to read from the standard input

		int x = sc.nextInt(); // Reading an integer value from the user and storing it in variable x

		// The following block of code calculates x raised to the power of 3
		x = x * x * x;

		// Printing the result to the console
		System.out.println(x);
	}
}
