
import java.util.Scanner; // Step 1: Import the Scanner class to read input from the user.

public class Main { // Step 2: Define a class named Main.
	public static void main(String[] args) { // Step 3: Define the main function where the execution of the program begins.
		Scanner sc = new Scanner(System.in); // Step 4: Create a Scanner object to read input from the user.
		int a = sc.nextInt(); // Step 5: Read an integer from the user and store it in variable a.
		int b = sc.nextInt(); // Step 6: Read an integer from the user and store it in variable b.
		int c = sc.nextInt(); // Step 7: Read an integer from the user and store it in variable c.
		int d = sc.nextInt(); // Step 8: Read an integer from the user and store it in variable d.

		if (a + b > c + d) // Step 9: Compare the sum of a and b with the sum of c and d.
			System.out.println("Left"); // Step 10: If the sum of a and b is greater than the sum of c and d, print "Left".
		else if (a + b < c + d) // Step 11: If the sum of a and b is less than the sum of c and d, print "Right".
			System.out.println("Right");
		else // Step 12: If the sums are equal, print "Balanced".
			System.out.println("Balanced");
	}
}

