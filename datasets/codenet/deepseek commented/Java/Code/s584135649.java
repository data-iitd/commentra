import java.util.Scanner; // Importing the Scanner class for input operations

public class Main {

	public static void main(String[] args) { // Main method, entry point of the program
		Scanner sc = new Scanner(System.in); // Initialize Scanner object to read input from the user
		
		int i=0; // Initialize a counter to keep track of the number of inputs
		
		for(i=1;i<=5;i++) { // Loop to read 5 inputs from the user
			int n = sc.nextInt(); // Read an integer input from the user
			if(n==0) { // Check if the input is 0
				break; // Break the loop if the input is 0
			}
		}
		
		System.out.println(i); // Print the number of inputs read before encountering a 0
	}
}
