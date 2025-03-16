import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		// Initialize Scanner to read input from the user
		Scanner sc = new Scanner(System.in);

		// Read the number of steps and the number of bad steps
		int n = sc.nextInt();
		int m = sc.nextInt();

		// Initialize an array to store bad steps and another array to store the number of ways to reach each step
		int[] a = new int[m + 1];
		int[] cnt = new int[n + 1];

		// Set the initial number of ways to reach step 0 to 1
		cnt[0] = 1;

		// Define the modulo value
		final int MOD = 1000000007;

		// Read the bad steps into the array 'a'
		for (int i = 1; i < a.length; i++) {
			a[i] = sc.nextInt();
		}

		// Initialize a variable to keep track of the current bad step index
		int num = 1;

		// Set the initial conditions for the first step
		if (m > 0) {
			if (a[1] == 1) {
				cnt[1] = 0;
				if (num < m) {
					num++;
				}
			} else {
				cnt[1] = 1;
			}
		} else {
			cnt[1] = 1;
		}

		// Use a loop to fill in the 'cnt' array using dynamic programming
		for (int i = 2; i < cnt.length; i++) {

			// Calculate the number of ways to reach the current step by adding the ways to reach the previous two steps
			cnt[i] = cnt[i - 2] + cnt[i - 1];
			cnt[i] %= MOD;

			// If the current step is a bad step, set the number of ways to reach that step to 0
			if (m > 0) {
				if (i == a[num]) {
					cnt[i] = 0;
					if (num < m) {
						num++;
					}
				}
			}

		}

		// Print the number of ways to reach the n-th step
		System.out.println(cnt[n]);

		// Close the Scanner object
		sc.close();
	}
}
