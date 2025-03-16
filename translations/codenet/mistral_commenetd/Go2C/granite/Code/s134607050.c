

#include <stdio.h>
#include <string.h>

// Function to search the range of 'R' and 'L' in the given text
// S....M....E
// R...RL...LR
void searchRange(char *text, int start, int limit, int *start_out, int *middle_out, int *end_out) {
	int middle = -1; // Initialize middle to -1

	for (int i = start; i < limit; i++) {
		if (text[i]!= 'R') { // Check if current character is not 'R'
			middle = i; // If not, then set middle to current index
			break; // and break the loop
		}
	}

	int end = limit; // Initialize end to limit

	for (int i = middle; i < limit; i++) {
		if (text[i]!= 'L') { // Check if current character is not 'L'
			end = i; // If not, then set end to current index
			break; // and break the loop
		}
	}

	*start_out = start; // Set start_out to start
	*middle_out = middle; // Set middle_out to middle
	*end_out = end; // Set end_out to end
}

// Function to print the answer
void answer() {
	char text[100000]; // Initialize text as an array of characters with a maximum length of 100000
	scanf("%s", text); // Read text from standard input

	int limit = strlen(text); // Get length of text

	int start = 0; // Initialize start index to 0
	int middle = 0; // Initialize middle index to 0
	int end = 0; // Initialize end index to 0
	int firstPrinted = 0; // Initialize firstPrinted to 0

	for (end = 0; end < limit; end = end + 1) { // Loop until end is less than limit
		searchRange(text, start, limit, &start, &middle, &end); // Call searchRange function to find the range of 'R' and 'L'

		int len1 = middle - start; // Calculate length of first substring
		int len2 = end - middle; // Calculate length of second substring

		// Print the first substring
		for (int i = start; i < middle - 1; i = i + 1) {
			if (firstPrinted!= 0) { // Check if firstPrinted is not 0
				printf(" "); // Print a space if true
			}
			printf("0"); // Print '0' for each character in the first substring
			firstPrinted = 1; // Set firstPrinted to 1
		}

		// Print the count of 'R' and 'L' in the first and second substrings
		if (firstPrinted!= 0) { // Check if firstPrinted is not 0
			printf(" "); // Print a space if true
		}
		printf("%d %d", len1 / 2 + len2 / 2, len1 / 2 + (len2 + 1) / 2); // Print the count of 'R' and 'L' in the first and second substrings
		firstPrinted = 1; // Set firstPrinted to 1

		// Print the second substring
		for (int i = middle + 1; i < end; i = i + 1) {
			if (firstPrinted!= 0) { // Check if firstPrinted is not 0
				printf(" "); // Print a space if true
			}
			printf("0"); // Print '0' for each character in the second substring
			firstPrinted = 1; // Set firstPrinted to 1
		}
		start = end; // Set start to end
		firstPrinted = 1; // Set firstPrinted to 1
	}
	printf("\n"); // Print newline at the end
}

// Main function to call answer function
int main() {
	answer(); // Call answer function
	return 0; // Return 0
}

