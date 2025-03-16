import java.util.Scanner; // Importing the Scanner class for input

public class Main { 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Initialize Scanner object to read input
		int w = sc.nextInt(); // Read the size of the array
		int n = sc.nextInt(); // Read the number of swaps
		int[] values = new int[w]; // Initialize the array of size w
		
		// Initialize the array with values from 1 to w
		for (int i = 0; i < values.length; i++) {
			values[i] = i + 1; 
		} 
		
		// Perform n swaps based on the input pairs
		for (int i = 0; i < n; i++) {
			int x = 0;
			String str = sc.next(); // Read a string representing the pair of indices
			String[] ab = str.split(","); // Split the string into an array of two elements
			int a = Integer.parseInt(ab[0]) - 1; // Convert the first element to an integer and adjust for 0-based index
			int b = Integer.parseInt(ab[1]) - 1; // Convert the second element to an integer and adjust for 0-based index
			x = values[a]; // Store the value at index a in a temporary variable
			values[a] = values[b]; // Swap the values at indices a and b
			values[b] = x; // Assign the stored value to index b
		} 
		
		// Print the array after all swaps
		for(int i = 0; i < w; i++){
			System.out.println(values[i]);
		}
	}
}
