import java.util.*;

public class Main {

	public static void main(String[] args) {
		// Read the number of characters
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();

		// Read the sequence of characters as a byte slice
		Scanner sc = new Scanner(System.in);
		byte[] s = new byte[n];
		for (int i = 0; i < n; i++) {
			s[i] = sc.next().getBytes()[0];
		}
		sc.close();

		// Create an integer slice to hold the numeric representation of colors
		int[] ns = new int[n];
		// Convert characters to their respective numeric values
		for (int i = 0; i < n; i++) {
			switch (s[i]) {
			case 'R':
				ns[i] = 0; // 'R' is represented as 0
				break;
			case 'G':
				ns[i] = 1; // 'G' is represented as 1
				break;
			case 'B':
				ns[i] = 2; // 'B' is represented as 2
				break;
			}
		}

		// Create a 2D slice to hold cumulative counts of each color up to each index
		int[][] rgb = new int[n + 1][3];
		rgb[0] = new int[3]; // Initialize the first row with zero counts

		// Populate the cumulative counts for each color
		for (int i = 1; i <= n; i++) {
			rgb[i] = new int[3]; // Initialize the current row
			for (int j = 0; j < 3; j++) {
				rgb[i][j] = rgb[i - 1][j]; // Carry forward the previous counts
			}
			rgb[i][ns[i - 1]]++; // Increment the count for the current color
		}

		// Variable to hold the total count of valid triplets
		int sum = 0;

		// Iterate through all pairs of indices to find valid triplets
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				// Check if the colors at indices i and j are different
				if (ns[i]!= ns[j]) {
					// Determine the third color that completes the triplet
					int tn = 3 - ns[i] - ns[j];
					// Count how many times the third color appears after index j
					sum += rgb[n][tn] - rgb[j + 1][tn];
					// Check if the third color appears at the position k
					int k = 2 * j - i;
					if (k < n && ns[k] == tn) {
						sum--; // Adjust the count if the third color is at position k
					}
				}
			}
		}

		// Output the total count of valid triplets
		System.out.println(sum);
	}
}

