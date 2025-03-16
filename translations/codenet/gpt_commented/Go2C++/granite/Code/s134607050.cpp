
#include <iostream>
#include <string>

// searchRange finds the range of indices in the text where 'R' and 'L' are located.
// It returns the start index, the middle index (first non-'R' character), and the end index (first non-'L' character).
void searchRange(const std::string& text, int start, int limit, int& start_out, int& middle_out, int& end_out) {
	int middle = -1;

	// Find the first index where the character is not 'R'
	for (int i = start; i < limit; i++) {
		if (text[i]!= 'R') {
			middle = i;
			break;
		}
	}

	end_out = limit;

	// Find the first index after'middle' where the character is not 'L'
	for (int i = middle; i < limit; i++) {
		if (text[i]!= 'L') {
			end_out = i;
			break;
		}
	}

	// Return the start, middle, and end indices
	start_out = start;
	middle_out = middle;
}

// answer processes the input text and prints the results based on the 'R' and 'L' characters.
void answer() {
	std::string text;
	// Read input text from standard input
	std::cin >> text;
	int limit = text.length();

	int start = 0;
	int middle = 0;
	int end = 0;
	bool firstPrinted = false;

	// Loop until the end of the text is reached
	while (end < limit) {
		// Get the range of indices for the current segment of 'R's and 'L's
		searchRange(text, start, limit, start, middle, end);
		int len1 = middle - start;
		int len2 = end - middle;

		// Print '0's for the 'R' segment
		for (int i = start; i < middle - 1; i++) {
			if (firstPrinted) {
				std::cout << " ";
			}
			std::cout << "0";
			firstPrinted = true;
		}

		// Calculate counts based on the lengths of the segments
		int count1 = (len1 + 1) / 2 + len2 / 2;
		int count2 = len1 / 2 + (len2 + 1) / 2;

		// Print the counts for the current segment
		if (firstPrinted) {
			std::cout << " ";
		}
		std::cout << count1 << " " << count2;
		firstPrinted = true;

		// Print '0's for the 'L' segment
		for (int i = middle + 1; i < end; i++) {
			if (firstPrinted) {
				std::cout << " ";
			}
			std::cout << "0";
			firstPrinted = true;
		}
		// Move to the next segment
		start = end;
		firstPrinted = true;
	}
	// Print a newline at the end of the output
	std::cout << std::endl;
}

// main function serves as the entry point of the program
int main() {
	answer();
	return 0;
}

