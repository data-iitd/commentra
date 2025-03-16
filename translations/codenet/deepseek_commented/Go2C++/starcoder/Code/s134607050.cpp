#include <iostream>
#include <string>

using namespace std;

// S....M....E
// R...RL...LR
int searchRange(string text, int start, int limit) {
	int middle = -1; // Initialize the middle position to -1

	// Find the first 'R' from the start position
	for (int i = start; i < limit; i++) {
		if (text[i]!= 'R') {
			middle = i; // Set middle to the current position if 'R' is found
			break;      // Break the loop as we found the first 'R'
		}
	}

	int end = limit; // Initialize the end position to the limit

	// Find the first 'L' after the middle position
	for (int i = middle; i < limit; i++) {
		if (text[i]!= 'L') {
			end = i; // Set end to the current position if 'L' is found
			break;  // Break the loop as we found the first 'L'
		}
	}

	return start, middle, end; // Return the start, middle, and end positions
}

void answer() {
	string text; // Declare a string variable to hold the input
	cin >> text; // Read the input string
	int limit = text.length(); // Get the length of the input string

	int start = 0; // Initialize the start position
	int middle = 0; // Initialize the middle position
	int end = 0; // Initialize the end position
	bool firstPrinted = false; // Initialize a flag to check if it's the first printed

	// Loop to find and print the counts of 'R' and 'L' in the specified ranges
	for (end = 0; end < limit; end++) {
		start, middle, end = searchRange(text, start, limit); // Update the start, middle, and end positions
		int len1 = middle - start; // Calculate the length of the first segment
		int len2 = end - middle; // Calculate the length of the second segment

		// Print '0's for the first segment
		for (int i = start; i < middle-1; i++) {
			if (firstPrinted) {
				cout << " "; // Print a space if not the first printed
			}
			cout << "0"; // Print '0'
			firstPrinted = true; // Set the flag to true
		}

		// Calculate the counts of 'R' and 'L'
		int count1 = (len1+1)/2 + len2/2;
		int count2 = len1/2 + (len2+1)/2;

		if (firstPrinted) {
			cout << " "; // Print a space if not the first printed
		}
		cout << count1 << " " << count2; // Print the counts
		firstPrinted = true; // Set the flag to true

		// Print '0's for the second segment
		for (int i = middle + 1; i < end; i++) {
			if (firstPrinted) {
				cout << " "; // Print a space if not the first printed
			}
			cout << "0"; // Print '0'
			firstPrinted = true; // Set the flag to true
		}
		start = end; // Update the start position
		firstPrinted = true; // Set the flag to true
	}
	cout << endl; // Print a newline at the end
}

int main() {
	answer(); // Call the answer function
}

