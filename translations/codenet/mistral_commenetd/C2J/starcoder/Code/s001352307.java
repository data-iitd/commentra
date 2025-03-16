
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// Read input from stdin
		Scanner stdin = new Scanner(System.in);

		// Initialize variables
		int t, i, j, W, N;

		// Loop through all test cases
		for(t = 0; ; t++) {
			// Initialize all variables
			W = 0;
			N = 0;
			i = 0;
			j = 0;

			// Read the width W and number of blocks N from the input
			W = stdin.nextInt();
			N = stdin.nextInt();

			// If width W is zero, break out of the loop and move on to the next test case
			if(W == 0)
				break;

			// Initialize a 2D array input to store the dimensions of each block
			int[][] input = new int[1024][2];

			// Initialize a 2D array ans to store the maximum size of a rectangle that can be formed by placing a block of given size at each position
			int[][] ans = new int[1024][2];

			// Read the dimensions of each block and store them in the input array
			for(i = 0; i < N; i++) {
				input[i][0] = stdin.nextInt();
				input[i][1] = stdin.nextInt();
			}

			// For each position j from the width W down to 0, update the maximum size of a rectangle that can be formed by placing a block of given size at that position
			for(i = 0; i < N; i++) {
				for(j = W; j >= input[i][1]; j--) {
					// If the maximum size of a rectangle that can be formed by placing a block of size input[i] at position j - input[i][1] is less than the sum of the size of the current block and the maximum size of a rectangle at position j - input[i][1], update the maximum size of a rectangle at position j
					if(ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
						ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
						ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
					}
				}
			}

			// Find the position j such that the maximum size of a rectangle at position W - j is greater than the maximum size of a rectangle at position W - j - 1
			for(j = 0; j <= W; j++)
				if(ans[W - j][0] > ans[W - j - 1][0])
					break;

			// Print the result for the current test case
			System.out.printf("Case %d:\n%d\n%d\n", t + 1, ans[W - j][0], ans[W - j][1]);
		}
	}
}

