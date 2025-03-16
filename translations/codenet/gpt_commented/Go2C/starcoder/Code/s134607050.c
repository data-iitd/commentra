

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// searchRange finds the range of indices in the text where 'R' and 'L' are located.
// It returns the start index, the middle index (first non-'R' character), and the end index (first non-'L' character).
int searchRange(char *text, int start, int limit) {
	int middle = -1;

	// Find the first index where the character is not 'R'
	for (int i = start; i < limit; i++) {
		if (text[i]!= 'R') {
			middle = i;
			break;
		}
	}

	int end = limit;

	// Find the first index after'middle' where the character is not 'L'
	for (int i = middle; i < limit; i++) {
		if (text[i]!= 'L') {
			end = i;
			break;
		}
	}

	// Return the start, middle, and end indices
	return start, middle, end;
}

// answer processes the input text and prints the results based on the 'R' and 'L' characters.
void answer() {
	char *text;
	// Read input text from standard input
	scanf("%s", &text);
	int limit = strlen(text);

	int start = 0;
	int middle = 0;
	int end = 0;
	int firstPrinted = 0;

	// Loop until the end of the text is reached
	while (end < limit) {
		// Get the range of indices for the current segment of 'R's and 'L's
		start, middle, end = searchRange(text, start, limit);
		int len1 = middle - start;
		int len2 = end - middle;

		// Print '0's for the 'R' segment
		for (int i = start; i < middle-1; i++) {
			if (firstPrinted) {
				printf(" ");
			}
			printf("0");
			firstPrinted = 1;
		}

		// Calculate counts based on the lengths of the segments
		int count1 = (len1+1)/2 + len2/2;
		int count2 = len1/2 + (len2+1)/2;

		// Print the counts for the current segment
		if (firstPrinted) {
			printf(" ");
		}
		printf("%d %d", count1, count2);
		firstPrinted = 1;

		// Print '0's for the 'L' segment
		for (int i = middle + 1; i < end; i++) {
			if (firstPrinted) {
				printf(" ");
			}
			printf("0");
			firstPrinted = 1;
		}
		// Move to the next segment
		start = end;
		firstPrinted = 1;
	}
	// Print a newline at the end of the output
	printf("\n");
}

// main function serves as the entry point of the program
int main() {
	answer();
}

