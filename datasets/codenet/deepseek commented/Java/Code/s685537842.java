import java.util.Scanner; // Import the Scanner class to read input from the user

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the user
		int a = sc.nextInt(); // Read the first integer input, representing the time increment
		int b = sc.nextInt(); // Read the second integer input, representing the number of items produced per time increment
		int t = sc.nextInt(); // Read the third integer input, representing the total time limit
		double time = 0; // Initialize the elapsed time to 0
		int count = 0; // Initialize the count of items produced to 0
		
		// Loop to produce items until the elapsed time exceeds the total time limit by 0.5 units
		while (time < t + 0.5) {
			count += b; // Increment the count by the number of items produced per time increment
			time += a; // Increment the elapsed time by the time increment
			if (time > t + 0.5) { // Check if the elapsed time exceeds the total time limit by 0.5 units
				count -= b; // Correct for the overproduction by decrementing the count
				break; // Exit the loop
			}
		}
		System.out.println(count); // Print the total count of items produced
	}
}
