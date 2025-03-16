import java.util.*;

public class Main {
	public static void main(String[] args) {
		// Declare variables
		int n;                      // Number of elements in the array
		int a[] = new int[100000];  // Array to store the elements
		int cnt = 1;                // Counter to store the number of increasing subsequences
		boolean isup;               // Flag to check if the subsequence is increasing or not
		boolean issame = false;     // Flag to check if all elements in a subsequence are the same

		// Read the number of elements from the user
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();

		// Read the elements of the array from the user
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		// Determine if the first two elements form an increasing subsequence
		if (a[0] < a[1])
			isup = true;
		else if (a[0] > a[1])
			isup = false;
		else
			issame = true;

		// Check for increasing subsequences in the array
		for (int i = 1; i < n - 1; i++) {
			// If the previous subsequence is made of same elements
			if (issame) {
				// If the current element is not the same as the next one
				if (a[i]!= a[i + 1]) {
					// Reset the flags and determine if the new subsequence is increasing or not
					issame = false;
					if (a[i] < a[i + 1])
						isup = true;
					else
						isup = false;
					cnt++;
				}
			} else {
				// If the subsequence is increasing
				if (isup && a[i] <= a[i + 1]) {
					// Continue the loop
					;
				} else if (!isup && a[i] >= a[i + 1]) {
					// The subsequence is decreasing, reset the flags and continue the loop
					isup = false;
					issame = false;
					cnt++;
				} else {
					// Check for the next element to determine if it starts a new increasing subsequence
					if (i + 2 < n) {
						if (a[i + 1] < a[i + 2])
							isup = true;
						else if (a[i + 1] > a[i + 2])
							isup = false;
						else
							issame = true;
						cnt++;
					} else {
						// Reach the end of the array, increment the counter and break the loop
						cnt++;
						break;
					}
				}
			}
		}

		// Print the number of increasing subsequences
		System.out.println(cnt);
	}
}
