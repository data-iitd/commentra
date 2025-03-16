


#include <stdio.h>
#include <string.h>

int main() {
	// Declare a variable to hold the input string
	char s[1000];
	
	// Read a string input from the user
	scanf("%s", s);
	
	// Initialize the answer variable with "No"
	char ans[] = "No";
	
	// Check if the first occurrence of 'C' is before the last occurrence of 'F'
	if (strstr(s, "C") < strstr(s, "F")) {
		// If true, set the answer to "Yes"
		ans = "Yes";
	}
	
	// Check if 'C' does not exist in the string
	if (strstr(s, "C") == NULL) {
		// If true, set the answer to "No"
		ans = "No";
	}
	
	// Print the final answer
	printf("%s\n", ans);
}

