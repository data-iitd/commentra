
import java.util.Scanner;
class Main {
	static final int MAX = 200000; // Define a constant MAX for array size
	public static void main(String[] args) {
		int[] R = new int[MAX]; // Declare an array R with size MAX
		Scanner in = new Scanner(System.in); // Create a Scanner object to read input
		int n = in.nextInt(); // Read the number of elements
		for(int i = 0; i < n; i++) R[i] = in.nextInt(); // Read the elements of the array R
		
		int maxv = R[1] - R[0]; // Initialize maxv to the difference between the first two elements
		int minv = R[0]; // Initialize minv to the first element
		
		// Loop to find the maximum profit
		for(int i = 1; i < n; i++) {
			maxv = Math.max(maxv, R[i] - minv); // Update maxv if a larger profit is found
			minv = Math.min(minv, R[i]); // Update minv if a smaller value is found
		}
		
		System.out.println(maxv); // Output the maximum profit
	}
}

