#include <bits/stdc++.h>

using namespace std;

// Define a type named "work" with two fields: "time" and "limit" of type int
struct work {
	int time, limit;
};

// Define a type named "works" as a vector of "work" structures
typedef vector<work> works;

// Implement the "works" type's comparison operators
bool operator<(const work& w1, const work& w2) {
	return w1.limit < w2.limit;
}

// Main function is the entry point of our program
int main() {
	// Declare variables and initialize them
	int n;
	cin >> n;

	// Create a vector of work structures with length "n"
	works ws(n);

	// Read input data for each work structure and store it in the corresponding index of the "ws" vector
	for (int i = 0; i < n; i++) {
		int a, n;
		cin >> a >> n;
		ws[i] = {a, n};
	}

	// Sort the "ws" vector based on the "limit" field of each work structure
	sort(ws.begin(), ws.end());

	// Initialize a variable named "sum" of type int and set its value to 0
	int sum = 0;

	// Iterate through the sorted "ws" vector and check if the total time spent on all works exceeds any work's limit
	for (const work& w : ws) {
		// Add the time of the current work structure to the "sum" variable
		sum += w.time;

		// Check if the sum is greater than the limit of the current work structure
		if (sum > w.limit) {
			// If it is, print "No" and return from the function
			cout << "No" << endl;
			return 0;
		}
	}

	// If the loop completes without finding a work structure whose time exceeds its limit, print "Yes"
	cout << "Yes" << endl;
}

