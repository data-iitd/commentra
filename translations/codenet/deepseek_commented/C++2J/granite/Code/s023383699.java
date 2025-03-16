
import java.util.Scanner; // Import the Scanner class from the java.util package

public class s023383699{ // Define a class named s023383699
	public static void main(String[] args) { // Define the main method
		Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the user
		int x = sc.nextInt(); // Read an integer input from the user and store it in x
		System.out.println(x*x*x); // Output the cube of the input value x
		sc.close(); // Close the Scanner object to release system resources
	}
}
