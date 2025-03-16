
import java.util.Scanner; // Importing Scanner class for user input

public class Main { 
	public static void main(String[] args) { // Main method to start the program
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read user input
		int w = sc.nextInt(); // Reading the number of elements in the array from user input
		int n = sc.nextInt(); // Reading the number of swaps to be performed from user input
		int[] values = new int[w]; // Creating an integer array of size w

		// Initializing the array with values from 1 to w
		for (int i = 0; i < values.length; i++) {
			values[i] = i + 1; // Assigning the value i+1 to the ith index of the array
		}

		// Swapping elements based on user input
		for (int i = 0; i < n; i++) {
			String str = sc.next(); // Reading a string from user input containing two indices separated by a comma
			String[] ab = str.split(","); // Splitting the string into two parts using comma as delimiter
			int a = Integer.parseInt(ab[0]) - 1; // Converting the first index to an integer and subtracting 1 to get the actual index
			int b = Integer.parseInt(ab[1]) - 1; // Converting the second index to an integer and subtracting 1 to get the actual index
			int temp = values[a]; // Storing the value at index a in a temporary variable
			values[a] = values[b]; // Swapping the values at indices a and b
			values[b] = temp; // Assigning the value stored in the temporary variable to the index b
		}

		// Printing the updated array elements
		for(int i = 0; i<w;i++){
			System.out.println(values[i]); // Printing the value at the ith index of the array
		}
	}
}