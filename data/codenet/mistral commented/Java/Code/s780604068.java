
import java.util.*;

public class Main {
	public static void main(String[] args){
		// Create a new Scanner object to read input from the standard input stream
		Scanner sc = new Scanner(System.in);

		// Read the first integer `N` from the input
		int N = sc.nextInt();

		// Allocate an integer array `map` of size `N * 2` to store the input elements
		int[] map = new int[N * 2];

		// Use a for loop to read `N * 2` integers from the input and store them in the `map` array
		for (int i = 0; i < N * 2; i++) {
			map[i] = sc.nextInt(); // Read the next integer from the input and store it in the current index of the map array
		}

		// Use the Arrays.sort method to sort the elements of the map array in ascending order
		Arrays.sort(map);

		// Initialize the variable max to 0
		int max = 0;

		// Use a for loop to iterate through the elements of the map array with a step of 2
		for (int i = 0; i < N * 2; i+=2) {
			// In each iteration, add the minimum of the current and next elements to the max variable
			max += Math.min(map[i], map[i + 1]);
		}

		// Finally, print the value of max to the standard output stream
		System.out.println(max);
	}
}