
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		// Read the number of arms, n
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		// Initialize a slice of arm structures, as
		type arm struct{ l, r int }
		as := new arm[n];

		// Read and initialize each arm structure in the slice
		for (int i = 0; i < n; i++) {
			// Read the position and length of the arm
			int x = sc.nextInt();
			int l = sc.nextInt();

			// Initialize the left and right fields of the arm structure
			as[i].l = x - l;
			as[i].r = x + l;
		}

		// Sort the slice based on the right field of the arm structures
		Arrays.sort(as, new Comparator<arm>() {
			public int compare(arm a, arm b) {
				return a.r - b.r;
			}
		});

		// Initialize answer variable, ans, and right variable, r
		int ans = 1;
		int r = as[0].r;

		// Iterate through the slice and update the answer and right variable accordingly
		for (int i = 1; i < n; i++) {
			if (as[i].l >= r) { // Check if the left end of the current arm is greater than or equal to the right end of the previous arm
				ans++; // Increment the answer if it is
				r = as[i].r; // Update the right variable with the right end of the current arm
			}
		}

		// Print the answer
		System.out.println(ans);

		// End of code

	}

}

