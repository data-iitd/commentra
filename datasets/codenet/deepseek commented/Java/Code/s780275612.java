
import java.util.Scanner;

public class Main {
	public static void main(String args[]){

		// Create a Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read an integer input from the user
		int intA = sc.nextInt();

		// Calculate the cube of the input integer
		double dbAncer = Math.pow(intA, 3);
		
		// Cast the result to an integer
		int intAncer = (int)dbAncer;
		
		// Print the result to the console
		System.out.println(intAncer);
	}
}

