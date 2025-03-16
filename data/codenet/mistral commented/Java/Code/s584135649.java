import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the main class named Main

	public static void main(String[] args) { // Defining the main method
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read user input

		int i = 0; // Initializing an integer variable 'i' with a value of 0

		for (i = 1; i <= 5; i++) { // Starting a for loop that runs 5 times with 'i' as the counter
			int n = sc.nextInt(); // Reading an integer value from the user input

			if (n == 0) { // Checking if the user input is equal to 0
				break; // If true, breaking out of the loop
			}
		}

		System.out.println(i); // Printing the value of 'i' after the loop has finished
	}
}