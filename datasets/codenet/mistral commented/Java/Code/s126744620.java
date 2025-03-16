import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	// Initialize the main method and create a Scanner object to read input
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// Read the number of elements 'n' and the sum 'k' from the standard input
		int n = sc.nextInt();
		int k = sc.nextInt();
		// Create an integer array 'a' of size 'n' to store the input elements
		int[] a = new int[n];
		// Use a for loop to read each element of the array 'a' from the standard input
		for(int i = 0 ; i < n ; i++) {
			a[i] = sc.nextInt();
		}
		// Create an Integer array 'x' of size 200010 and initialize all its elements to zero
		Integer[] x = new Integer[200010];
		Arrays.fill(x, 0);
		// Use another for loop to count the occurrences of each element in the array 'a' and store it in the corresponding index of array 'x'
		for(int i = 0 ; i < n ; i++) {
			// Increment the count of the index 'a[i] - 1' in array 'x'
			x[a[i] - 1]++;
		}
		// Sort the array 'x' in ascending order using a custom Comparator
		Arrays.sort(x, new Comparator<Integer>() {
			// Define an anonymous inner class implementing the Comparator interface to provide the custom comparison logic
			public int compare(Integer p1, Integer p2) {
				// Return the negative of the difference between the two integers to sort them in ascending order
				return p1 - p2;
			}
		});
		// Initialize a variable 'ans' to store the sum of the first 'k' elements in array 'x'
		int ans = 0;
		// Use a for loop to calculate the sum of the first 'k' elements in array 'x'
		for(int i = 0 ; i <= 200010 - k - 1 ; i++) {
			// Add the current count to the variable 'ans'
			ans += x[i];
		}
		// Print the final answer to the standard output
		System.out.println(ans);
	}
}
