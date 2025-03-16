
#include <stdio.h>
#include <string.h>

// Function to search the range of 'R' and 'L' in the given text
// S....M....E
// R...RL...LR
int searchRange(char *text, int start, int limit) {
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

	return start, middle, end; // Return start, middle and end indices
}

// Function to print the answer
void answer() {
	char text[100000]; // Initialize text as empty string
	scanf("%s", text); // Read text from standard input
	int limit = strlen(text); // Get length of text

	int start = 0; // Initialize start index to 0
	int middle = 0; // Initialize middle index to 0
	int end = 0; // Initialize end index to 0
	int firstPrinted = 0; // Initialize firstPrinted to false

	for (end = 0; end < limit; end++) { // Loop until end is less than limit
		start, middle, end = searchRange(text, start, limit); // Call searchRange function to find the range of 'R' and 'L'

		int len1 = middle - start; // Calculate length of first substring
		int len2 = end - middle; // Calculate length of second substring

		// Print the first substring
		for (int i = start; i < middle-1; i++) {
			if (firstPrinted) { // Check if firstPrinted is true
				printf(" "); // Print a space if true
			}
			printf("0"); // Print '0' for each character in the first substring
			firstPrinted = 1; // Set firstPrinted to true
		}

		// Print the count of 'R' and 'L' in the first and second substrings
		if (firstPrinted) { // Check if firstPrinted is true
			printf(" "); // Print a space if true
		}
		printf("%d %d", len1/2+len2/2, len1/2+(len2+1)/2); // Print the count of 'R' and 'L' in the first and second substrings
		firstPrinted = 1; // Set firstPrinted to true

		// Print the second substring
		for (int i = middle + 1; i < end; i++) {
			if (firstPrinted) { // Check if firstPrinted is true
				printf(" "); // Print a space if true
			}
			printf("0"); // Print '0' for each character in the second substring
			firstPrinted = 1; // Set firstPrinted to true
		}
		start = end; // Set start to end
		firstPrinted = 1; // Set firstPrinted to true
	}
	printf("\n"); // Print newline at the end
}

// Main function to call answer function
int main() {
	answer(); // Call answer function
}

