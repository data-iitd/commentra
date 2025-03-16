
import java.util.Scanner; // Import the Scanner class from the java.util package

public class Main { // The entry point of the program
	public static void main(String[] args) { // The main method
		Scanner sc = new Scanner(System.in); // Create a new Scanner object to read from the standard input
		int h = sc.nextInt(); // Read an integer from the standard input and store it in the variable h
		int r = sc.nextInt(); // Read an integer from the standard input and store it in the variable r
		if(r > -h){ // Check if r is greater than the negative value of h
			System.out.println("1"); // If the condition is true, print the number 1 followed by a newline character
		}
		else if (r == -h){ // Check if r is equal to the negative value of h
			System.out.println("0"); // If the condition is true, print the number 0 followed by a newline character
		}
		else{ // If the previous conditions are false
			System.out.println("-1"); // Print the number -1 followed by a newline character
		}
	}
}

