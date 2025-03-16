import java.util.Scanner; // Import the Scanner class for input
import java.util.Arrays; // Import the Arrays class for sorting

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a Scanner object for input
		int n = sc.nextInt(); // Read the value of n from the input
		int k = sc.nextInt(); // Read the value of k from the input
		int[] l = new int[n]; // Declare an array of size n
		for (int i = 0; i < n; i++) {
			l[i] = sc.nextInt(); // Read the elements of the array l
		}

		Arrays.sort(l); // Sort the array l in ascending order

		int ans = 0; // Initialize ans to 0
		for (int i = 0; i < k; i++) {
			ans += l[n - 1 - i]; // Sum the last k elements of the sorted array
		}
		System.out.println(ans); // Print the result
	}
}
