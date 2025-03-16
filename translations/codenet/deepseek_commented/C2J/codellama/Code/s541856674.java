
import java.util.Scanner; // Step 1: Include necessary headers

public class Main { // Step 2: Define the main class
	public static void main(String[] args) { // Step 3: Define the main function
		Scanner sc = new Scanner(System.in); // Step 4: Create a Scanner object
		int N = sc.nextInt(); // Step 5: Read input values
		int R = sc.nextInt();

		if(N >= 10) { // Step 6: Implement conditional logic
			System.out.println(R); // If true, print the value of R
		} else {
			System.out.println(R + 100*(10-N)); // Otherwise, calculate and print the adjusted value of R
		}
	}
}

