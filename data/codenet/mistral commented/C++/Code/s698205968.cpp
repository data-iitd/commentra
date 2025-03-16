#include <iostream> // Include the iostream library for input/output operations

using namespace std; // Use the standard namespace for easier access to iostream functions

int main() { // Beginning of the main function
	int m, f, r; // Declare variables m, f, and r to store user input

	while (cin >> m >> f >> r) { // Start of the while loop
		// The loop continues as long as the user inputs valid integers (m, f, and r)
		// and at least one of them is not -1

		if (m == -1 || f == -1) { // Check if m or f is -1
			cout << "F"; // If so, print "F" and move on to the next input
			continue;
		}

		if (m + f >= 80) { // Check if the sum of m and f is greater than or equal to 80
			cout << "A"; // If so, print "A" and move on to the next input
			continue;
		}

		if (m + f >= 65) { // Check if the sum of m and f is greater than or equal to 65
			cout << "B"; // If so, print "B" and move on to the next input
			continue;
		}

		if (m + f >= 50 || r >= 50) { // Check if the sum of m and f is greater than or equal to 50
									 // or if r is greater than or equal to 50
			cout << "C"; // If so, print "C" and move on to the next input
			continue;
		}

		if (m + f >= 30) { // Check if the sum of m and f is greater than or equal to 30
			cout << "D"; // If so, print "D" and move on to the next input
			continue;
		}

		cout << "F"; // If none of the above conditions are met, print "F" and move on to the next input
		cout << endl; // Print a newline character to start the next input on a new line
	}

	return 0; // End of the main function, return 0 to indicate successful execution
}
