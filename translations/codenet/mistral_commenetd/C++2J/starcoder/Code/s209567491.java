
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		// Read input
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int D = sc.nextInt();
		int X = sc.nextInt();

		// Initialize array A to store the number of chocolate pieces for each day
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt(); // Read the number of chocolate pieces for the i-th day
		}

		// Calculate the total number of chocolate pieces
		int num_of_chocolate = 0;
		for (int i = 0; i < N; i++) {
			// Initialize variables for inner loop
			int days = 0;
			int counter = 0;

			// Calculate the number of days this chocolate piece lasts
			for (int j = 0;; j++) {
				days = j * A[i] + 1; // Calculate the number of days
				if (days <= D) { // Check if the number of days is less than or equal to the maximum number of days
					counter++; // Increment the counter
				}
				else { // If the number of days is greater than the maximum number of days, break the loop
					break;
				}
			}

			// Add the number of chocolate pieces eaten in this day to the total number of chocolate pieces
			num_of_chocolate = num_of_chocolate + counter;
		}

		// Add the extra chocolate
		num_of_chocolate = num_of_chocolate + X;

		// Output the result
		System.out.println(num_of_chocolate);
	}
}

