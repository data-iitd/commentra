#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	// Declare a string variable to hold the input
	char s[100];
	// Read the input string from standard input
	scanf("%s", s);
	// Get the length of the input string
	int l = strlen(s);
	// Initialize the answer as "AC" (Accepted)
	char ans[3] = "AC";
	
	// Check if the first character is 'A'
	if (s[0] != 'A') {
		// If not, set the answer to "WA" (Wrong Answer)
		strcpy(ans, "WA");
	}
	
	// Initialize a counter for uppercase letters
	int cnt = 0;
	// Loop through the string starting from the second character
	for (int i = 1; i < l; i++) {
		// Check if the current character is an uppercase letter
		if (isupper(s[i])) {
			// Check if the uppercase letter is not at the second or last position
			// or if it is not 'C'
			if (i == 1 || i == l-1 || s[i] != 'C') {
				// If any of the conditions are met, set the answer to "WA"
				strcpy(ans, "WA");
			}
			// Increment the uppercase letter counter
			cnt++;
		}
	}
	
	// Check if there is exactly one uppercase letter (which should be 'C')
	if (cnt != 1) {
		// If not, set the answer to "WA"
		strcpy(ans, "WA");
	}
	
	// Print the final result
	printf("%s\n", ans);
	
	// End of code
	return 0;
}