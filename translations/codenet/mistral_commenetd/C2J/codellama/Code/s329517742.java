
import java.util.Scanner; // Importing the Scanner class

public class Main { // Declaring the Main class

	public static void main(String[] args) { // Declaring the main function

		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input

		int a = sc.nextInt(); // Reading an integer from the standard input and storing it in variable 'a'
		int b = sc.nextInt(); // Reading an integer from the standard input and storing it in variable 'b'

		if(500*a >= b) { // Logical block to check if 500 times the value of variable 'a' is greater than or equal to the value of variable 'b'
			System.out.println("Yes"); // If the condition is true, print 'Yes' to the standard output
		}
		else {
			System.out.println("No"); // If the condition is false, print 'No' to the standard output
		}

	}

}

