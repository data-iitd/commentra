
import java.util.Scanner; // Importing Scanner class for user input

public class Main {
	public static void main(String args[]) { // Main method to start the program
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object for user input
		int n; // Declaring an integer variable 'n' to store the number of elements in the array

		// Reading the number of elements from the user
		n = sc.nextInt();

		int[] h = new int[n]; // Declaring and initializing an integer array 'h' of size 'n'

		// Reading the elements of the array from the user
		for(int i = 0; i < n; i++) {
			h[i] = sc.nextInt(); // Reading each element of the array
		}

		int ans = 0; // Declaring and initializing an integer variable 'ans' to store the answer
		int out = 0; // Declaring and initializing an integer variable 'out' to store the current highest height

		// Calculating the answer by iterating through the array
		for( int i = 0; i < h.length; i++ ) { // Iterating through each element of the array
			if( out < h[i] ) { // Checking if the current height is greater than the previous highest height
				ans += h[i] - out; // Adding the difference between the current height and the previous highest height to the answer
				out = h[i]; // Updating the previous highest height to the current height
			}else { // If the current height is not greater than the previous highest height
				out = h[i]; // Updating the previous highest height to the current height
			}
		}

		// Printing the answer
		System.out.println(ans);
	}
}

