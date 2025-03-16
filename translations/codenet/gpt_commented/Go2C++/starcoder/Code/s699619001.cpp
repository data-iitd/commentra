#include <bits/stdc++.h>

using namespace std;

// Define a struct to represent a problem with its number of questions and bonus points
struct problem {
	int number, bonus;
};

// Function to return the minimum of two integers
int min(int a, int b) {
	if (a >= b) {
		return b;
	}
	return a;
}

int main() {
	// Read the number of problems (D) and the target score (G)
	int D, G;
	cin >> D >> G;

	// Create a vector to hold the problems
	vector<problem> problems(D);
	
	// Read the number of questions and bonus points for each problem
	for (int i = 0; i < D; i++) {
		cin >> problems[i].number;
		cin >> problems[i].bonus;
	}
	// Uncomment the following line to debug input values
	// cout << "D" << D << "G" << G << "problems" << problems << endl;

	// Initialize the answer to a large number (infinity equivalent)
	int ans = 10000;
	
	// Iterate over all possible combinations of problems using bit manipulation
	for (int bit = 0; bit < (1 << D); bit++) {
		int score = 0;        // Initialize the score for the current combination
		int solved = 0;       // Initialize the count of solved problems
		bool ok = false;      // Flag to check if the current combination meets the target score

		// Calculate the score and number of solved problems for the current combination
		for (int j = 0; j < D; j++) {
			if (bit & (1 << j)) { // Check if the j-th problem is included
				score += (j + 1) * 100 * problems[j].number + problems[j].bonus;
				solved += problems[j].number;
			}
		}

		// If the current score is less than the target score (G)
		if (score < G) {
			int j;
			// Find the rightmost problem that is not yet included
			for (j = D - 1; j >= 0; j--) {
				if (bit & (1 << j)) {
					break;
				}
			}
			// Attempt to solve additional questions from the rightmost problem
			for (int k = 0; k < problems[j].number; k++) {
				score += (j + 1) * 100; // Add score for solving one more question
				solved++;               // Increment the count of solved problems
				if (score >= G) {        // Check if the target score is reached
					ok = true;
					break;
				}
			}
			// If the target score is still not reached, add the bonus points
			if (!ok) {
				score += problems[j].bonus;
				if (score >= G) {
					ok = true; // Check again if the target score is reached
				}
			}
		} else {
			ok = true; // If the score is already greater than or equal to G
		}
		
		// If the current combination meets the target score, update the answer
		if (ok) {
			ans = min(ans, solved); // Update the minimum number of solved problems
		}
	}
	
	// Output the minimum number of problems that need to be solved to reach the target score
	cout << ans << endl;
}

