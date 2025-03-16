#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char s[1000]; // Declare a string variable to hold the input
	scanf("%s", s); // Read input from the user
	int l = strlen(s); // Calculate the length of the string and store it in l
	char ans[3] = "AC"; // Initialize the answer variable with "AC"

	// Check if the first character is 'A'
	if (s[0] != 'A') {
		strcpy(ans, "WA"); // If the first character is not 'A', set ans to "WA"
	}

	int cnt = 0; // Initialize a counter to keep track of uppercase letters
	for (int i = 1; i < l; i++) { // Iterate over the string starting from the second character
		if (isupper(s[i])) { // Check if the character is an uppercase letter
			if (i == 1 || i == l-1 || s[i] != 'C') { // Check if the character is 'C' or not at the second or second-to-last position
				strcpy(ans, "WA"); // If any of the conditions are met, set ans to "WA"
			}
			cnt++; // Increment the counter if the conditions are met
		}
	}

	// Check if there is exactly one uppercase letter that is not the first or last character and is 'C'
	if (cnt != 1) {
		strcpy(ans, "WA"); // If cnt is not 1, set ans to "WA"
	}

	printf("%s\n", ans); // Print the final answer
	return 0;
}

