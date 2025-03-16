import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
	public static void main(String[] args) { // Main method to start the program
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read user input
		int a, b, t; // Declaring three integer variables a, b, and t

		// Reading user input for variables a, b, and t
		a = sc.nextInt();
		b = sc.nextInt();
		t = sc.nextInt();

		double time = 0; // Declaring and initializing a double variable time to 0
		int count = 0; // Declaring and initializing an integer variable count to 0

		// Main loop to simulate the process
		while (time < t + 0.5) {
			// Incrementing the count variable by b each time through the loop
			count += b;
			// Adding the value of variable a to the time variable
			time += a;

			// Checking if the time variable exceeds the given time limit (t) with a tolerance of 0.5
			if (time > t + 0.5) {
				// If the condition is true, decrement the count variable by b and break out of the loop
				count -= b;
				break;
			}
		}

		// Printing the final count value to the console
		System.out.println(count);
	}
}
