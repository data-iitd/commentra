import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		// Read the number of arms
		int n = new Scanner(System.in).nextInt();
		
		// Define a struct to represent an arm with left and right bounds
		class arm {
			int l, r;
		}
		
		// Create a slice to hold the arms
		arm[] as = new arm[n];
		
		// Read the arm data from input
		for (int i = 0; i < n; i++) {
			int x = new Scanner(System.in).nextInt();
			int l = new Scanner(System.in).nextInt();
			as[i] = new arm();
			as[i].l = x - l;
			as[i].r = x + l;
		}
		
		// Sort the arms based on their right bounds
		Arrays.sort(as, new Comparator<arm>() {
			public int compare(arm a, arm b) {
				return a.r - b.r;
			}
		});
		
		// Initialize the count of non-overlapping arms and the rightmost bound
		int ans = 1; // Start with the first arm
		int r = as[0].r; // Set the rightmost bound to the right of the first arm
		
		// Iterate through the sorted arms to count non-overlapping arms
		for (int i = 1; i < n; i++) {
			// If the left bound of the current arm is greater than or equal to the rightmost bound
			if (as[i].l >= r) {
				ans++; // Increment the count of non-overlapping arms
				r = as[i].r; // Update the rightmost bound to the current arm's right bound
			}
		}
		
		// Print the total count of non-overlapping arms
		System.out.println(ans);
	}
}

