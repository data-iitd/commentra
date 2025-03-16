
#include <iostream>

using namespace std;

// Define constants W and N for the width and number of blocks respectively
int W, N;

// Define a 2D array input to store the dimensions of each block
int input[1024][2];

// Define a 2D array ans to store the maximum size of a rectangle that can be formed by placing a block of given size at each position
int ans[1024][2];

int main() {
	// Initialize variables i, j, t, and arrays ans and input
	int i, j, t;

	// Loop through all test cases
	for(t = 0; ; t++) {
		// Initialize all elements of arrays ans and input to zero
		for(i = 0; i < 1024; i++) {
			ans[i][0] = 0;
			ans[i][1] = 0;
			input[i][0] = 0;
			input[i][1] = 0;
		}

		// Read the width W and number of blocks N from the input
		cin >> W >> N;

		// If width W is zero, break out of the loop and move on to the next test case
		if(W == 0)
			break;

		// Read the dimensions of each block and store them in the input array
		for(i = 0; i < N; i++)
			cin >> input[i][0] >> input[i][1];

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
		cout << "Case " << t + 1 << ":\n" << ans[W - j][0] << "\n" << ans[W - j][1] << "\n";
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}

