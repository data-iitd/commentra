import java.util.Scanner; // Import the Scanner class for input operations.
public class Main { // Define the Main class.
	public static void main(String[] args) { // Define the main function, the entry point of the program.
		Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input.
		int n = sc.nextInt(); // Read an integer value for n from the standard input.
		int k = sc.nextInt(); // Read an integer value for k from the standard input.
		int x = n/k; // Calculate the integer division of n by k and store the result in x.
		int y = n%k; // Calculate the remainder of the integer division of n by k and store the result in y.
		int z; // Declare an integer variable to store the value of z.
		if(y!=0) { // Check if the remainder y is not equal to 0.
			z=x+1-x; // If y is not equal to 0, calculate z as x+1-x.
		}
		else { // If y is equal to 0.
			z=x-x; // Calculate z as x-x.
		}
		System.out.println(z); // Print the value of z to the standard output.
		
		sc.close(); // Close the Scanner object.
	}
}
